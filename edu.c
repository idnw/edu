#include<linux/module.h>
#include<linux/printk.h>
#include<linux/workqueue.h>

struct workqueue_struct *test_wq;
struct work_struct test_work;

void edu_test_work(struct work_struct *work)
{
	printk("A work from workqueue\n");
}

static int __init edu_init(void)
{
	printk("A driver for study linux :)\n");

	test_wq = alloc_workqueue("test_wq", WQ_CPU_INTENSIVE | WQ_UNBOUND, 1);
	if (!test_wq)
		return (-ENOMEM);

	INIT_WORK(&test_work, edu_test_work);
	queue_work(test_wq, &test_work);

	return 0;
}

static void __exit edu_exit(void)
{
	destroy_workqueue(test_wq);
	printk("Bye bye!\n");
}

module_init(edu_init);
module_exit(edu_exit);

MODULE_DESCRIPTION("A driver for study linux");
MODULE_AUTHOR("luhy");
MODULE_LICENSE("GPL");
