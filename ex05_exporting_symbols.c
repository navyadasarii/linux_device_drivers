#include<linux/kernel.h>
#include<linux/module.h>

int ex05_simple_module(void)
{
	printk(KERN_INFO "iNSIDE the %s function\n",__FUNCTION__);
	
	return 0;
}

EXPORT_SYMBOL(ex05_simple_module);

__init int ex05_exporting_symbols_init(void)
{
	printk(KERN_INFO "iNSIDE the %s function\n",__FUNCTION__);
	
	return 0;
	
}

void ex05_exporting_symbols_exit(void)
{
	
	printk(KERN_INFO "inside the %s function\n",__FUNCTION__);
}

module_init(ex05_exporting_symbols_init);
module_exit(ex05_exporting_symbols_exit);

MODULE_LICENSE("GPL");


