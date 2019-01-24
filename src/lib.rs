#![no_std]
#![feature(lang_items)]

// Calling C from Rust doesn't work. Getting the dmesg error "module: myhello: Unknown rela relocation: 9"
/*
extern "C" {
  #[no_mangle]
  fn _printk(message: &'static[u8]) -> ();
}

fn print(message: &'static[u8]) {
  unsafe { _printk(message); }
}
*/

#[no_mangle]
extern "C" fn get_output() -> &'static[u8] {
    return b"hello from rust\x00";
}

// Begin panic overhead code.
use core::panic::PanicInfo;
#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
  // if anything ever panics, the OS will freeze
//  print(b"Rust kernel panic\x00");
  loop {}
}
// We can ignore this, I think. panic!() will always halt right there and not return so this shouldn't be called.
// https://stackoverflow.com/questions/329059/what-is-gxx-personality-v0-for
#[lang = "eh_personality"]
#[no_mangle]
pub extern fn rust_eh_personality() {}
