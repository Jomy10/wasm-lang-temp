//! S-Expressions (wat) formatter

use std::ffi::{CStr, CString};
use std::os::raw::c_char;

extern "Rust" {
    fn format(input: *const c_char, tab: *const c_char) -> *const c_char;
    fn free_format(inp: *const c_char);
}

/// Format s-expressions wat file
#[allow(temporary_cstring_as_ptr)]
pub fn format_wat(input: &str, tab: &str) -> String {
    let c_char = unsafe { format(
        CString::new(input).unwrap().as_ptr(),
        CString::new(tab).unwrap().as_ptr()
    ) };
    let c_str = unsafe { CStr::from_ptr(c_char) };
    let str = c_str.to_str().map(|s| s.to_owned()).unwrap();
    unsafe { free_format(c_char) };
    return str;
}
