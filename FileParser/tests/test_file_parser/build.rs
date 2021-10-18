extern crate bindgen;

fn main() 
{
    println!("cargo:rerun-if-changed=src/wrapper.hpp");
    println!("cargo:rerun-if-changed=src/main_.cpp");
    let cpp_files = [
        "../../src/main_.cpp",
        "../../src/Utils/print_usage.cpp",
        "../../src/Pipeline/source_handler.cpp",
        "../../src/Pipeline/sink_handler.cpp",
        "../../src/Pipeline/replace_handler.cpp",
        "../../src/Pipeline/replace_builder.cpp",
        "../../src/Pipeline/pipeline.cpp",
        "../../src/Pipeline/pipeline_builder.cpp",
        "../../src/Pipeline/i_handler.cpp",
        "../../src/Pipeline/file_sink_handler.cpp",
        "../../src/Pipeline/counter_handler.cpp",
        "../../src/Pipeline/counter_builder.cpp",
        "../../src/Pipeline/abstract_handler.cpp"
    ];
    cc::Build::new()
        .cpp(true)
        .files(cpp_files.iter())
        .compile("cppprog");
    
    let bindings = bindgen::Builder::default()
        .header("src/wrapper.hpp")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");
    
    bindings.write_to_file("src/tests/bindings.rs")
        .expect("Unable to write to file");
}