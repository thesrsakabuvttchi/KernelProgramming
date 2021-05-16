#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("thesrsakabuvttchi");

const int Major=234,Minor=890;

//Major number is 12 bits at max and minor number is 20 bits at max also use macro MKDEV
dev_t dev = (const int)(Major<<20|(Minor%(1<<20)));

int init(void)
{
    int Sucess = register_chrdev_region(dev,1,"Test_dev");
    printk("Preparing to register with Major=%d and Minor=%d: ",Major,Minor);
    if(Sucess<0)
    {
        printk("Failed with code %d\n",Sucess);
        return(-1);
    }
    else
    {
        printk("Sucessful! %d %d\n",MAJOR(dev),MINOR(dev));
        return(0);
    }
}

void clean(void)
{
    unregister_chrdev_region(dev,1);
    printk("Cleaned!\n");
}

module_init(init);
module_exit(clean);