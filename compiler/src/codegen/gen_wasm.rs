pub use wabt::wat2wasm;
use wabt::Wat2Wasm;

/// Config field meanings: https://docs.rs/wabt/latest/wabt/struct.Wat2Wasm.html#method.canonicalize_lebs
pub struct Config {
    pub canonilize_lebs: bool,
    pub relocatable: bool,
    pub write_debug_names: bool,
    pub validate: bool,
}

impl Default for Config {
    fn default() -> Self {
        Self {
            canonilize_lebs: true,
            relocatable: false,
            write_debug_names: false,
            validate: true,
        }
    }
}

impl Config {
    pub fn new_debug() -> Self {
        Self {
            canonilize_lebs: true,
            relocatable: false,
            write_debug_names: true,
            validate: true,
        }
    }
}

pub fn gen_wasm(wat: &str, config: &Config) -> Vec<u8> {
    Wat2Wasm::new()
        .canonicalize_lebs(config.canonilize_lebs)
        .relocatable(config.relocatable)
        
        .write_debug_names(config.write_debug_names)
        .validate(config.validate)
        .convert(wat)
        .unwrap()
        .as_ref()
        .to_vec()
}
