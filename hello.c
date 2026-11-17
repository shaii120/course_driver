#include <linux/module.h>
#include <linux/errno.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

static dev_t dev_num;

static int __init hello_init (void)
{
    int num;
    printk(KERN_INFO "Hello module initiallzing...\n");
    num = alloc_chrdev_region(&dev_num, 0, 1, "hw-module-test");
    printk(KERN_INFO "Hello module allocated %d\n", dev_num);
    return 0;
}

static void __exit hello_exit (void)
{
    unregister_chrdev_region(dev_num, 1);
    printk(KERN_INFO "Hello module ending...\n");
}

module_init(hello_init);
module_exit(hello_exit);