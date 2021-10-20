#[cfg(test)]
mod tests {
    mod bindings;
    #[test]
    fn it_works() {
        unsafe 
        {
            let mut sequence = bindings::NatSequence::new(10);
            let vector = vec!(
                sequence.Next(),
                sequence.Next(),
                sequence.Next()
            );
            assert_eq!(vec![1,2,3], vector);
        }
    }
}
