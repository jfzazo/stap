#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/syscalls.h>
#include <linux/kallsyms.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm/unistd.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>
#include <linux/version.h>
#include <linux/syscalls.h>

MODULE_LICENSE("GPL");

#define PERIOD 1000 // 10 seconds = 10000 ms

int state = 0;

static struct timer_list my_timer;

void my_timer_callback( unsigned long data )
{
    state++;
    printk(KERN_INFO "Current: %d", state);
    mod_timer( &my_timer, jiffies + msecs_to_jiffies(PERIOD) );
}

int birria_init(void) {
    
      
  /* setup your timer to call my_timer_callback */
  setup_timer(&my_timer, my_timer_callback, 0);
  /* setup timer interval to 200 msecs */
  mod_timer(&my_timer, jiffies + msecs_to_jiffies(PERIOD));
  printk(KERN_ALERT "\nTimer start\n");
 
     
    return 0;
}
 
void birria_exit(void) {
    del_timer(&my_timer);
    printk(KERN_ALERT "\nTimer stop\n");
    return;
}
 
module_init(birria_init);
module_exit(birria_exit);
