###PRACTICAL KEY POINTS TO WORK WITH LINUX KERNEL DEVELOPMENT , DEBUGGING AND MANY MORE
#NOTE:
This is the main documents I am creating and keep maitaining it in future whatever important knowledge I find. further more it is available and on git for easy access and daily modifications push to git
so in short It is the most important docs will be always be updated with any type of linux kernel related knowledge.

2024 Target: int the mid of 2024 it should have a big knowledge base and contain most of the kernel stuffs that make dealing with kernel easy

started on date: 27/12/2023
Author: Malkoot Khan
Description: The goal is to store and update here whatever new learning done. when all the important knowledge and pin-points are available in one place so it will be easier to get start where I left and memorize the things easily if there is a long break in any of the topic so after that much time I can easily pick where left.


Kernel to know the linux kernel:
================================
I got good knowledge from the link : https://www.youtube.com/watch?v=QatE61Ynwrw
The key points:
linux test project(LTP):
------------------------
This is a tool for testing the linux kernel it is open-source and its source code is available on github  
This is an important tool to use for testing after whatever changes made to the kernel but I think mostly used by the kernel maintainers
(It is somehow user level application but should be explored to confirm)

Linux Kernel Selftests(kselftests):
-----------------------------------
It is another test suit and part of kernel

static analysis:
----------------
tools->checkpatch: this needs to be explored it is used to check the patch I think it is available in the kernel source scripts dir; this scripts dir has a lot of important tools and should be explored in depth

dynamic analysis:
-----------------
there are some tools that are used to check the memory and memory leaks : scuch as 
-kmemcheck
-kmemleak

config flags:
-------------
this file resides in the main kernel directory as ".config" and contains the various configurations flags. if we want to debug the kernel then first we have to enable debug flag in this file such as 
CONFIG_GDB_SCRIPTS=y

ftrace(function trace):
-----------------------
this is another tool that gives you the function calling tree; should be explored in depth is very important

dump_stack() prints stack trace: it is something printing all function in time of crash that can be followed backwards to locate the exact function that caused the current crash but need to be explored

useful commands:(these commands/tools and many more are located within the toolchain)
----------------
-objdump: it is used to convert the vmlinux to assembly code and may be doing many more thing should be explored
-addr2line: this is an excellent tool to take the address or the function name with offset and jump to the exact corresponding line in souce code where you can analyze and see for the issue more easily

GDB(gnu debugger):
------------------
gdb debugger can be used to debug the kernel


wireshark?

coredump?

virtual memory?
kdump?
scripts dir in kernel source?



QEMU RELATED STUFFS:
--------------------
Follow the following steps to run qemu
"sudo qemu-system-arm -M virt -kernel "$zImage_path" -initrd ~/qemu/rootfs.cpio -append "root=/dev/ram rdinit=/sbin/init" -no-reboot -nographic"
<in the above command the machine is virtual .cpio is root filesystem required and currently located at that specific loc>
<The defconfig file for this is "vexpress_defconfig" located at "arch/arm/config/vexpress_defconfig">
GDB:if we want to run gdb on kernel then run the following commands
"sudo qemu-system-arm -M virt -kernel "$zImage_path" -initrd ~/qemu/rootfs.cpio -s -S -append "console=ttyS0 nokaslr" -append "root=/dev/ram rdinit=/sbin/init" -nographic"
but the debug flag should be enabled as explained earlier

running this gdb command in one terminal and in another terminal we have run "arm-linux-gnueabihf-gdb vmlinux" then "target remote :1234" and then some commands to boot in debug mode and explore
gdb debugging guide:-> "https://www.youtube.com/watch?v=bxKMW9wtAH0"
qemu based gdb debugging guide:-> "https://www.youtube.com/watch?v=FdNIiQxwJuk"
qemu based debug:-> "https://www.youtube.com/watch?v=2VcA5Wj7IvU"

Debugging steps:
----------------
- understand the problem
- reproduce the problem 
- identify the source of the problem
- fix the problem









