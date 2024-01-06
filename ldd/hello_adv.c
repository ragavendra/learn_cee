#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
MODULE_LICENSE("Dual BSD/GPL");
static int hello_init(void)
{
	 printk(KERN_ALERT "Hello, world\n");

	 dev_t *device;
	 int res = alloc_chrdev_region(&device, 105, 2, "hello");
	 checkResponse(res);

	 return 0;
}

static checkResponse(int re) {

	 if(re < 0)
		  printk(KERN_ALERT "Unable to assign DD major or minor no %d", res);
}
static void hello_exit(void)
{
	 int res = unregister_chrdev_region(105, 2);
	 checkResponse(res);
	 printk(KERN_ALERT "Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);
