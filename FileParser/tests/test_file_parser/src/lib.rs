#![allow(non_upper_case_globals)]                                                                                  
#![allow(non_camel_case_types)]                                                                                    
#![allow(improper_ctypes)]                                                                                         
#![allow(non_snake_case)]                                                                                          
#![allow(unused)]
#[cfg(test)]
mod tests {
    //include!("bindings.rs");
    mod bindings;
    #[test]
    fn it_works() {
        unsafe
        {
            //let pipeline: bindings::Pipeline = Pipeline
        };
        assert_eq!(2 + 2, 4);
    }
}
