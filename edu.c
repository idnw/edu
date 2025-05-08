#include<linux/module.h>
#include<linux/printk.h>

static int __init edu_init(void)
{
	printk("A driver for study linux :)\n");
	return 0;
}

static void __exit edu_exit(void)
{
	printk("Bye bye!\n");
}

module_init(edu_init);
module_exit(edu_exit);

MODULE_DESCRIPTION("A driver for study linux");
MODULE_AUTHOR("luhy");
MODULE_LICENSE("GPL");

