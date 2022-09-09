#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/skbuff.h>
#include <linux/socket.h>
#include <linux/hash.h>
#include <linux/in.h>
#include <linux/net.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <net/tcp.h>

#define OLD_KERNEL 1

static int init_detect(void)
{
        int off;

        off = offsetof(typeof(struct tcp_sock), copied_seq);
        printk("STRUCT_TCP_SOCK_COPIED_SEQ_OFFSET : 0x%x\n", off);

        off = offsetof(typeof(struct tcp_sock), write_seq);
        printk("STRUCT_TCP_SOCK_WRITE_SEQ_OFFSET : 0x%x\n", off);

        off = offsetof(typeof(struct task_struct), files);
        printk("STRUCT_TASK_FILES_OFFSET : 0x%x\n", off);

        off = offsetof(typeof(struct sock), __sk_flags_offset);
        printk("STRUCT_SOCK_FLAGS_OFFSET : 0x%x\n", off);
        return 0;
}

static void exit_detect(void)
{
        return;
}

module_init(init_detect);
module_exit(exit_detect);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("deepflow");
