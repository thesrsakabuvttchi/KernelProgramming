#include<linux/kernel.h>
#include<linux/module.h>

char S[50] = "";
MODULE_LICENSE("GPL");

int init(void)
{
    printk("Hello %s\n",S);
    return(0);
}

void cleanup(void)
{
    printk("Bye %s\n",S);
    return;
}

module_param_string(name,S,50,0);

module_init(init);      // Registers the __init function for the module.
module_exit(cleanup);   // Registers the __exit function for the module. 
