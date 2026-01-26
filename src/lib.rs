#[unsafe(no_mangle)]
pub extern "C" fn sumar(a: i32, b: i32) -> i32 {
    
    println!("Hello, world!, from Rust! Code, your numbers are: {} and {}", a, b);
    return a + b;
}
#[unsafe(no_mangle)]
pub extern "C" fn loop_func() {
    for i in 1..10 {
        println!("Numero: [{}] Rust",i);
    }
}