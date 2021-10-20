extern crate bindgen;

fn main() 
{
    println!("cargo:rerun-if-changed=src/wrapper.hpp");
	println!("cargo:rerun-if-changed=src/adapter_cpp/natural_sequence.cpp");
    let cpp_files = [
		"src/adapter_cpp/natural_sequence.cpp",
		"../../src/Sequence/natural_sequence.cpp"
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