/*
 *  hello.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

MODULE_LICENSE("GPL");

const char* get_output(void);

// netlink.c
//void netlink_init(void);
//void netlink_exit(void);

/*void _printk(const char* message) {
  printk(message);
}*/

// device_control.c
int init_device_control(void);
void cleanup_device_control(void);

int init_module(void) {
	const char* out;
	printk(KERN_INFO "Hello, World!2\n");
	out = get_output();
	printk(out);

	//netlink_init();
	init_device_control();


    printk(KERN_INFO "Setup complete!\n");

	/*
	 * A non 0 return means init_module failed; module can't be loaded.
	 */
	return 0;
}

void cleanup_module(void) {
	//netlink_exit();
	cleanup_device_control();
	printk(KERN_INFO "Goodbye, World!\n");
}

