#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>




ssize_t fops_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO "inside the function %s\n",__FUNCTION__);

	return 0;
}

ssize_t fops_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO "inside the function %s\n",__FUNCTION__);

	return length;
}

int fops_open (struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO "inside the function %s\n",__FUNCTION__);

	return 0;
}

int fops_close (struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO "inside the function %s\n",__FUNCTION__);

	return 0;
}

dev_t dev_num;
struct cdev chrdev;
struct file_operations fops = {
	.open = fops_open,
	.release = fops_close,
	.read = fops_read,
	.write = fops_write
};
static struct class *dev_class;

int __init ex10_fops_init(void)
{
	if(alloc_chrdev_region(&dev_num,0,1,"fops_cdev") < 0)
	{
		printk(KERN_INFO "cannot allocate device Number\n");
		return -1;
	}

	/* initialisation of cdev structure */

	cdev_init(&chrdev,&fops);
	chrdev.owner = THIS_MODULE;

	/*registration of a device */

	cdev_add(&chrdev,dev_num,1);

	/*creating a device file*/

	dev_class = class_create(THIS_MODULE,"fops_cdev");

	if(IS_ERR(dev_class))
	{
		printk(KERN_INFO "cannot create class for device\n");
		goto r_class;
	}

	if(IS_ERR(device_create(dev_class,NULL,dev_num,NULL,"fops_cdev")))
	{
		printk(KERN_INFO "cannot create device\n");

		goto r_device;
	}
	printk(KERN_INFO "Inside the function %s\n",__FUNCTION__);
	return 0;

r_device:
	class_destroy(dev_class);
r_class:
	unregister_chrdev_region(dev_num,1);
	return -1;

}

void __exit ex10_fops_exit(void)
{
	device_destroy(dev_class,dev_num);
	class_destroy(dev_class);
	unregister_chrdev_region(dev_num,1);
	printk(KERN_INFO "Inside the function %s\n",__FUNCTION__);
}

module_init(ex10_fops_init);
module_exit(ex10_fops_exit);

MODULE_LICENSE("GPL");

