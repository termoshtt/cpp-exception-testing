fn main() {
    cc::Build::new()
        .cpp(true)
        .file("foo.cpp")
        .cpp_link_stdlib("stdc++") // use libstdc++
        .compile("libfoo.a");
}
