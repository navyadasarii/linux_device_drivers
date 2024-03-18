include<linux/kernel.h>
#include<linux/module.h>



void __exit ex03_simple_module_exit(void)
{
	
	printk(KERN_INFO "inside the %s function\n",__FUNCTION__);
}


module_exit(ex03_simple_module_exit);

MODULE_LICENSE("GPL");


