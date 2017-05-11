#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/delay.h>


int i=0;
int j=0;
int k=0;

static int *ptr=0;


module_param(i,int,S_IRUSR | S_IWUSR);
module_param(j,int,S_IRUSR | S_IWUSR);
module_param(k,int,S_IRUSR | S_IWUSR);



void Modify_Ram(void)
{
	

	//u1n2i3q4u5e6
	ptr = kmalloc(sizeof(int)*3, GFP_KERNEL);
	
	if(!ptr)
	{
		printk(KERN_ALERT "Error");
		return;
	}
	
	printk(KERN_ALERT " At Address : %X ",&ptr[0]);

		
	for(j=954641;j<954662;j++)
	{
		
		for(k=0;k<3;k++)
			ptr[k]=j;
		
		for(k=0;k<3;k++)
		{
			for(i=0;i<100;i++)
			{
				ptr[k]=(ptr[k] + 1);
			}
		}	
		
		
	        printk(KERN_ALERT " %d ",ptr[0]);
		
		msleep(1000);
	}
		
	kfree(ptr);
}

static int MemModifier_init(void)
{
	Modify_Ram();
	printk(KERN_ALERT "Hello inside Ram!!");
	return 0;
}


static void MemModifier_exit(void)
{
	printk(KERN_ALERT "Good Bye");
}





module_init(MemModifier_init);
module_exit(MemModifier_exit);




MODULE_AUTHOR("Raushan");
MODULE_DESCRIPTION("Kernel Module Demonstration");
MODULE_LICENSE("GPL");