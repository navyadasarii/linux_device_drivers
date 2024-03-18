#include<linux/kernel.h>
#include<linux/module.h>

__init int ex01_simple_module_init(void)
{
	printk(KERN_INFO "iNSIDE the %s function\n",__FUNCTION__);
	
	return 0;
	
}

void ex01_simple_module_exit(void)
{
	
	printk(KERN_INFO "inside the %s function\n",__FUNCTION__);
}

module_init(ex01_simple_module_init);
module_exit(ex01_simple_module_exit);

MODULE_LICENSE("GPL");


