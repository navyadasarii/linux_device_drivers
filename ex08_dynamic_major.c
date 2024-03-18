#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

dev_t dev = 0;

int __init ex08_dynamic_major_init(void)
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

	printk(KERN_INFO "inside %s function\n",__FUNCTION__);



	return 0;
}

void __exit ex08_dynamic_major_exit(void)
{

	unregister_chrdev_region(dev,1);
	printk(KERN_INFO "inside %s function\n",__FUNCTION__);

}

module_init(ex08_dynamic_major_init);
module_exit(ex08_dynamic_major_exit);

MODULE_LICENSE("GPL");


