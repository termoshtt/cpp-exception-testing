/* C++ -> Rust -> C++ */

extern "C" {
    fn test_cxx_exception();
}

struct A {}
impl Drop for A {
    fn drop(&mut self) {
        println!("Drop A in Rust");
    }
}

#[no_mangle]
extern "C-unwind" fn rust_middle_func(callback: extern "C-unwind" fn()) {
    let _a = A {}; // test destructor
    callback(); // This raises C++ exception

    // Following will not be executed
    unreachable!("End of rust_middle_func");
}

fn main() {
    unsafe {
        test_cxx_exception();
    }
}
