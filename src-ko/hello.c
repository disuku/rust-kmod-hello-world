/*
 *  hello.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

const char* get_output(void);

/*void _printk(const char* message) {
  printk(message);
}*/

int init_module(void) {
	const char* out;
	printk(KERN_INFO "Hello, World!\n");
	out = get_output();
	printk(out);

	/*
	 * A non 0 return means init_module failed; module can't be loaded.
	 */
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "Goodbye, World!\n");
}

