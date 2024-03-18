#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int count = 1;

module_param(count,int,0644);

__init int ex06_simple_module_init(void)
{
	int index = 0;
	printk(KERN_INFO "iNSIDE the %s function\n",__FUNCTION__);

	for(index = 0; index < count; index++)
	{
		printk(KERN_INFO "hello world\n");
	}
	
	return 0;
	
}

void ex06_simple_module_exit(void)
{
	int index;
	printk(KERN_INFO "inside the %s function\n",__FUNCTION__);
	
	for(index = 0; index < count; index++)
	{
		printk(KERN_INFO "bye world\n");
	}
	

}

module_init(ex06_simple_module_init);
module_exit(ex06_simple_module_exit);

MODULE_LICENSE("GPL");


