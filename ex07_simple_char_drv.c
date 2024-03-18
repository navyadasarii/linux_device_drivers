#include<linux/kernel.h>
#include<linux/module.h>

#include<linux/fs.h> /* for the character driver support*/

ssize_t ex07_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO "inside the function %s\n",__FUNCTION__);

	return 0;
}

ssize_t ex07_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO "inside the function %s\n",__FUNCTION__);

	return length;
}

int ex07_open (struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO "inside the function %s\n",__FUNCTION__);

	return 0;
}

int ex07_close (struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO "inside the function %s\n",__FUNCTION__);

	return 0;
}


struct file_operations ex07_file_operations = {
	.owner = THIS_MODULE,
	.open = ex07_open,
	.read = ex07_read,
	.write = ex07_write,
	.release = ex07_close
};


__init int ex07_simple_module_init(void)
{
	printk(KERN_INFO "iNSIDE the %s function\n",__FUNCTION__);
	/* register a char device */
	register_chrdev(260/* major number*/,
			"Simple Char Drv"/* name of the driver*/,
			 &ex07_file_operations/* file operations*/);

	
	return 0;
	
}

void ex07_simple_module_exit(void)
{
	
	printk(KERN_INFO "inside the %s function\n",__FUNCTION__);

	/*unregister the char device driver*/
	unregister_chrdev(260,"Simple Char Drv");
	
}

module_init(ex07_simple_module_init);
module_exit(ex07_simple_module_exit);

MODULE_LICENSE("GPL");


