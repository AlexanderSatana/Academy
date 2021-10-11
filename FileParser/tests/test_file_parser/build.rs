extern crate bindgen;

fn main() 
{
    println!("cargo:rerun-if-changed=src/wrapper.hpp");
    let cpp_files = [
        "../../src/Utils/print_usage.cpp",
        "../../src/Pipeline/pipeline.cpp"
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