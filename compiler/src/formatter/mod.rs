use std::ffi::{CString, CStr};
use std::os::raw::c_char;

#[cfg(target_os = "macos")]
extern "Rust" {
    fn format(input: *const c_char, tab: *const c_char) -> *const c_char;
    fn free_format(inpp: *const c_char);
}

#[cfg(target_os = "macos")]
#[allow(temporary_cstring_as_ptr)]
/// Format s-expressions wat file
pub fn format_wat(input: &str, tab: &str) -> String {
    let c_char = unsafe {
        format(
            CString::new(input).unwrap().as_ptr(),
            CString::new(tab).unwrap().as_ptr()
        )
    };
    let c_str = unsafe { CStr::from_ptr(c_char) };
    let str = c_str.to_str().map(|s| s.to_owned()).unwrap();
    unsafe { free_format(c_char) };
    return str
}
