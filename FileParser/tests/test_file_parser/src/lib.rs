#![allow(non_upper_case_globals)]                                                                                  
#![allow(non_camel_case_types)]                                                                                    
#![allow(improper_ctypes)]                                                                                         
#![allow(non_snake_case)]                                                                                          
#![allow(unused)]



#[cfg(test)]
mod tests {
    mod bindings;

    use std::time::{Duration, Instant};
    #[test]
    fn it_works() {
        let start = Instant::now();
        unsafe
        {
            bindings::main_();
        };
        let duration = start.elapsed();
        println!("Time elapsed in expensive_function() is: {:?}", duration);
    }
}
