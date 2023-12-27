###PRACTICAL KEY POINTS TO WORK WITH LINUX KERNEL DEVELOPMENT , DEBUGGING AND MANY MORE
#NOTE:
This is the main documents I am creating and keep maitaining it in future whatever important knowledge I find. further more it is available and on git for easy access and daily modifications push to git
so in short It is the most important docs will be always be updated with any type of linux kernel related knowledge.

2024 Target: int the mid of 2024 it should have a big knowledge base and contain most of the kernel stuffs that make dealing with kernel easy

started on date: 27/12/2023
Author: Malkoot Khan
Description: The goal is to store and update here whatever new learning done. when all the important knowledge and pin-points are available in one place so it will be easier to get start where I left and memorize the things easily if there is a long break in any of the topic so after that much time I can easily pick where left.


Kernel to know the linux kernel:
--------------------------------
I got good knowledge from the link : https://www.youtube.com/watch?v=QatE61Ynwrw
The key points:
linux test project(LTP): use to test the kernel (code is available on github)

Linux Kernel Selftests(kselftests): part of kernel
static analysis tools->checkpatch: to be studied
dynamic analysis tool->kmemcheck,kmemleak

config flags:
config_debug

function trace (ftrace)

dump_stack() prints stack trace

useful commands
-objdump
-addr2line (a tool within toolchain that is used to convert the crash address to a source code exact line )
GDB(gnu debugger)


wireshark?
coredump?

virtual memory
kdump
scripts dir in kernel source



QEMU RELATED STUFFS:
--------------------






