#include<linux/kernel.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");

int init(void)
{
    printk("hello world\n");
    return(0);
}

void cleanup(void)
{
    printk("GoodBye!\n");
    return;
}


module_init(init);      // Registers the __init function for the module.
module_exit(cleanup);   // Registers the __exit function for the module. 
