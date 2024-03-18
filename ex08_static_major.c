#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

dev_t dev = MKDEV(260,0);
dev_t dev1 = MKDEV(260,1);

int __init ex08_static_major_init(void)
{
	/*register_chrdev(major num,
			 name of the driver visible in /proc/devices,
			 file operations );*/
	
	register_chrdev_region(dev/*dev_t dev*/,
				 2/* unsigned int count*/,
				 "static_major"/* char * name */);
	register_chrdev_region(dev1/*dev_t dev*/,
				 2/* unsigned int count*/,
				 "major"/* char * name */);

//	printk(KERN_INFO "major num = %u , minor num = %u\n ",MAJOR(dev),MINOR(dev));

	printk(KERN_INFO "inside %s function\n",__FUNCTION__);



	return 0;
}

void __exit ex08_static_major_exit(void)
{
	printk(KERN_INFO "inside %s function\n",__FUNCTION__);
	unregister_chrdev_region(dev,2);
	unregister_chrdev_region(dev1,2);


}

module_init(ex08_static_major_init);
module_exit(ex08_static_major_exit);

MODULE_LICENSE("GPL");


