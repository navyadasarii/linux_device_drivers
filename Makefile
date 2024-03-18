obj-m := sample.o

obj-m := sample2.o

obj-m += ex01_simple_module.o

obj-m += ex02_simple_module_init.o

obj-m += ex03_simple_module_exit.o

obj-m := ex0203_simple_module.o

ex0203_simple_module-objs := ex02_simple_module_init.o ex03_simple_module_exit.o

obj-m := ex01_simple_module.o
obj-m += ex04_simple_module.o

obj-m := ex05_exporting_symbols.o
obj-m += ex05_using_symbols.o

obj-m := ex06_module_param.o

obj-m := ex07_simple_char_drv.o
obj-m += ex07_copy.o

obj-m := ex08_static_major.o

#obj-m := ex08_dynamic_major.o

obj-m := ex09_udev.o

obj-m += ex10_fops.o




all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
