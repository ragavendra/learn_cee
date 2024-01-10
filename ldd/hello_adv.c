#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
MODULE_LICENSE("Dual BSD/GPL");

static int device_major_number = 0;
static int hello_init(void)
{
	 printk(KERN_ALERT "Hello, world\n");

	 /*
	 dev_t *dev;

	 if (scull_major) {
		  dev = MKDEV(scull_major, scull_minor);
		  result = register_chrdev_region(dev, scull_nr_devs, "scull");
	 } else {
		  result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs,
				    "scull");
		  scull_major = MAJOR(dev);
	 }
	 if (result < 0) {
		  printk(KERN_WARNING "scull: can't get major %d\n", scull_major);
		  return result;
	 }*/

	 dev_t *device;
	 
	 // int res = alloc_chrdev_region(&device, 105, 2, "hello");
	 int res = alloc_chrdev_region(&device, device_major_number, 2, "hello");
	 checkResponse(res);

	 return 0;
}

static checkResponse(int re) {

	 if(re < 0)
		  printk(KERN_ALERT "Unable to assign DD major or minor no %d", res);
}
static void hello_exit(void)
{
	 int res = unregister_chrdev_region(device_major_number, 2);
	 checkResponse(res);
	 printk(KERN_ALERT "Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);
