use std::env;
use std::process::Command;
use serde::Deserialize;

fn main() {
    let target = env::var("CARGO_CFG_TARGET_OS").unwrap();

    // s-expression formatter
    if target == "macos" {
        build_macos_formatter();
    } // TODO: other platforms
}  

/////////////////////////////////// s-expressions formatter //////////////////////////////////
const MACOS_TARGET_VERSION: &str = "10.15";

#[derive(Debug, Deserialize)]
#[serde(rename_all = "camelCase")]
struct SwiftPaths {
    runtime_library_paths: Vec<String>
}

#[derive(Debug, Deserialize)]
struct SwiftTarget {
    paths: SwiftPaths
}

fn build_macos_formatter() {
    let profile = env::var("PROFILE").unwrap(); // release / debug
    let arch = env::var("CARGO_CFG_TARGET_ARCH").unwrap();
    let target = format!("{}-apple-macosx{}", arch, MACOS_TARGET_VERSION);
    
    let swift_target_info_str = Command::new("swift")
        .args(&["-target", &target, "-print-target-info"])
        .output()
        .unwrap()
        .stdout;
    let swift_target_info: SwiftTarget = serde_json::from_slice(&swift_target_info_str).unwrap();
    swift_target_info.paths.runtime_library_paths.iter().for_each(|path| {
        // path = /usr/lib/swift
        println!("cargo:rustc-link-search=native={}", path);
    });
    
    if !Command::new("swift")
        .args(&["build", "-c", &profile])
        .current_dir("./s-expr-formatter")
        .status()
        .unwrap()
        .success() {
        panic!("Swift library s-expr-formatter compilation failed");
    }
    
    println!("cargo:rustc-link-search=./s-expr-formatter/.build/{}-apple-macosx/{}", arch, profile);
    println!("cargo:rustc-link-lib=static=s-expr-formatter");
    println!("cargo:rerun-if-changed=s-expr-formatter/src/*.swift");
}
