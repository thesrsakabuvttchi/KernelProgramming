#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("thesrsakabuvttchi");

dev_t dev= 0;

int init(void)
{
    int sucess = alloc_chrdev_region(&dev,120,1,"Test_dev");
    if(sucess<0)
    {
        printk("Could not allocate, error code %d\n",sucess);
        return(-1);
    }
    else
    {
        printk("Sucess! Major=%d, Minor=%d\n",MAJOR(dev),MINOR(dev));
        return(0);
    }
}

void clean(void)
{
    unregister_chrdev_region(dev,1);
    printk("Cleaned! \n");
}


module_init(init);
module_exit(clean);