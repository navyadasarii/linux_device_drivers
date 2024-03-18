#include<linux/kernel.h>
#include<linux/module.h>

static int __init ex02_simple_module_init(void)
{
	printk(KERN_INFO "iNSIDE the %s function\n",__FUNCTION__);
	
	return 0;
	
}


module_init(ex02_simple_module_init);

MODULE_LICENSE("GPL");


