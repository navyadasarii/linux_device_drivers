/* STEPS:
 * 1.INCLUDE LINUX/DEVICE.H  AND LINUX/KDEV_T.H
 * 2.CREATE STRUCT CLASS 
 * 3.CREATE DEVICE WITH CLASS CREATED ABOVE
 */



#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/kdev_t.h>

dev_t dev = 0;
static struct class *dev_class; 

int __init ex09_udev_init(void)
{
	/*register_chrdev(major num,
			 name of the driver visible in /proc/devices,
			 file operations );*/
	
	if(alloc_chrdev_region(&dev,0,1,"dynamic_major") < 0)
	{
		printk(KERN_INFO "cannot allocate major number\n");
		return -1;
	}
	
	printk(KERN_INFO "major num = %u , minor num = %u\n ",MAJOR(dev),MINOR(dev));
	/*STEP 2: struct class * class_create(struct module *owner,const char *name)*/

	dev_class = class_create(THIS_MODULE,"udev_chr_dev");

	/*checking error using IS_ERR()	macro*/

	if(IS_ERR(dev_class))
	{
		printk(KERN_INFO "cannot create the struct class for device\n");
		goto r_class;
	}

	/*STEP 3: struct device * device_create(struct class *, struct device *parent, dev_t dev, void * drvdata,const char *fmt,...)*/

	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"udev_chr_dev")))
	{
		printk(KERN_INFO "cannot cretae device\n");
		goto r_device;
	}

	printk(KERN_INFO "inside %s function\n",__FUNCTION__);
	return 0;

r_device:
	class_destroy(dev_class);
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}




void __exit ex09_udev_exit(void)
{
	device_destroy(dev_class/*struct class * */,
			dev/* dev_t dev*/);
	class_destroy(dev_class/*struct class * */);
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO "inside %s function\n",__FUNCTION__);

}

module_init(ex09_udev_init);
module_exit(ex09_udev_exit);

MODULE_LICENSE("GPL");


