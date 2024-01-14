# PRACTICAL KEY POINTS TO WORK WITH LINUX KERNEL DEVELOPMENT , DEBUGGING AND MANY MORE:

## NOTE:

---
This is the main documents I am creating and keep maitaining it in future whatever important knowledge I find. further more it is available and on git for easy access and daily modifications push to git
so in short It is the most important docs will be always be updated with any type of linux kernel related knowledge.

- [ ] 2024 Target: int the mid of 2024 it should have a big knowledge base and contain most of the kernel stuffs that make dealing with kernel easy

- [x] started on date: 27/12/2023
- [x] Author: Malkoot Khan
- [x] Description: The goal is to store and update here whatever new learning done. when all the important knowledge and pin-points are available in one place so it will be easier to get start where I left and memorize the things easily if there is a long break in any of the topic so after that much time I can easily pick where left.

---

**Getstarted to know the linux kernel:**

- [I got some good knowledge from the link](https://www.youtube.com/watch?v=QatE61Ynwrw)

**The key points:**

---

### linux test project(LTP):

This is a tool for testing the linux kernel it is open-source and its source code is available on github  
This is an important tool to use for testing after whatever changes made to the kernel but I think mostly used by the kernel maintainers
(It is somehow user level application but should be explored to confirm)

---

### Linux Kernel Selftests(kselftests):

It is another test suit and part of kernel

**static analysis:**

tools- >checkpatch: this needs to be explored it is used to check the patch I think it is available in the kernel source scripts dir; this scripts dir has a lot of important tools and should be explored in depth

**dynamic analysis:**

there are some tools that are used to check the memory and memory leaks : scuch as 
- kmemcheck
- kmemleak

**config flags:**

this file resides in the main kernel directory as ".config" and contains the various configurations flags. if we want to debug the kernel then first we have to enable debug flag in this file such as 
CONFIG_GDB_SCRIPTS=y

---

### ftrace(function trace):

this is another tool that gives you the function calling tree; should be explored in depth is very important

**dump_stack() prints stack trace:** it is something printing all function in time of crash that can be followed backwards to locate the exact function that caused the current crash but need to be explored

**useful commands:** (these commands/tools and many more are located within the toolchain)

- **objdump:** it is used to convert the vmlinux to assembly code and may be doing many more thing should be explored
- **addr2line:** his is an excellent tool to take the address or the function name with offset and jump to the exact corresponding line in souce code where you can analyze and see for the issue more easily
**Example**
`arm-linux-gnueabihf-addr2line -f -e vmlinux < address >`
address=the address of the problem
running the above command will give us the exact line in the source c code which we can explore more
it can also be done in the following way:
`scripts/faddr2line vmlinux < function name + offset >`
function+offset=function-name+0x34
-we can also target the in this way: run gdb ./vmlinux then in gdb "list *(functionName+offset or address)" it will take me to the line in source code that created the problem

### RandomTopicsImportant:

- (these topics should be explored in depth)
- wireshark?
- coredump?
- virtual memory?
- kdump?
- scripts dir in kernel source?

---

# QEMU RELATED STUFFS:

Follow the following steps to run qemu
`sudo qemu-system-arm -M virt -kernel "$zImage_path" -initrd ~/qemu/rootfs.cpio -append "root=/dev/ram rdinit=/sbin/init" -no-reboot -nographic`
> in the above command the machine is virtual .cpio is root filesystem required and currently located at that specific loc 
> The defconfig file for this is "vexpress_defconfig" located at "arch/arm/config/vexpress_defconfig" 
**GDB:** if we want to run gdb on kernel then run the following commands
> `sudo qemu-system-arm -M virt -kernel "$zImage_path" -initrd ~/qemu/rootfs.cpio -s -S -append "console=ttyS0 nokaslr" -append "root=/dev/ram rdinit=/sbin/init" -nographic`
but the debug flag should be enabled as explained earlier

---

running this gdb command in one terminal and in another terminal we have run `arm-linux-gnueabihf-gdb vmlinux` then `target remote :1234` and then some commands to boot in debug mode and explore
- [gdb debugging guide](https://www.youtube.com/watch?v=bxKMW9wtAH0)
- [qemu based gdb debugging guide](https://www.youtube.com/watch?v=FdNIiQxwJuk)
- [qemu based debug](https://www.youtube.com/watch?v=2VcA5Wj7IvU)

# Debugging steps:

- understand the problem
- reproduce the problem 
- identify the source of the problem
- fix the problem

---

## KGDB for real target:

kgdb is used when target is connected serially to host system; for doing kgdb debugging we have to prepare the following 

### target preparation:

- enable "CONFIG_KGDB=y" in .config file in main linux dir
- enable "CONFIG_KGDB_SERIAL_CONSOLE=y"
- boot the kernel with kgdb enabled; adjust the desired serial port. This typically involves adding something like kgdboc=ttyS0,115200 kgdbwait to your kernel command line. Adjust ttyS0 and 115200

### host preparation:

- install gdb (also confirm wether host and target are of same architecture or cross if cross: arm-linux-gnueabihf- etc but pi is arm and the target is also arm I think the same)
- connect to the target serially and confirm to see the kernel log
- "gdb path/to/vmlinux"
- "(gdb) target remote /dev/ttyS0"
- once connected then gdb cmmands can used to debug

---

# KGDB with qemu:

## prepare qemu target:

- compile the kernel with debug flag enabled:- > "CONFIG_DEBUG_INFO=y" it can be done either by menuconfig or directly in ".config" file
- run qemu with "-s -S" the working command in my case is `sudo qemu-system-arm -M virt -kernel "$zImage_path" -initrd ~/qemu/rootfs.cpio -s -S -append "console=ttyS0 nokaslr" -append "root=/dev/ram rdinit=/sbin/init" -nographic`. It is according to my current configuration and setup but can be veried for other setup as required
- after running the above command it will be waiting;

## Prepare Host:

- arm-linux-gnueabihf-gdb/gdb vmlinux depending on the architecture(cross compile or same)
- (gdb) target remote :1234

[guidance link](https://www.youtube.com/watch?v=2VcA5Wj7IvU)

you can explore various gdb commands to step in throguh source code layout or assembly and many more things



---

# CREATING PATCH FOR LINUX KERNEL:

here I am interested in contributing to linux kernel main repo but for that I must know how to find where to add modify the code then create a standard patch and standard way to add that patch to the kernel

you can watch the following tutorials for better understanding of creating patches

 [youtube](https://www.youtube.com/watch?v=LLBrBBImJt4)

 [youtube](https://www.youtube.com/watch?v=FZR9U98D_jY)


## Steps for creating patch:

- clone the kernel form `git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git`
- go into the git dir create your own branch and checkout to it
- run `./scripts/checkpatch.pl < dir >` it will check for any issue in specific area < dir > for exampel: `./scripts/checkpatch.pl net/ipv4/` so it will catch any error or warning in net/ipv4/
- go to that error or warning and correct it then again running `./script/checkpatch.pl net/ipv4/` to verify if it disappears
- Optional but you can also build using `make M= <  modifiedfile or dir  >` to see it it build successfully
- run `git add < modified file >`
- run `git commit -s -v` : running this command will open an editor write the title and the description according to other people done in the same file you can find that by running `git log < path to the same file >` or `git log --pretty=full` or `git log --pretty=online < pathTofile >` follow that same approach
- run `git format-patch master..< currentbranch >` or for one patch  `git format-patch -1`
- now check the patch `./scripts/checkpatch.pl < patch >` where patch=0001-tcp-fixed-whitespace-trailing-error.patch
- find the maintainer email by `./scripts/get_maintainer.pl < patch >` where patch=0001-tcp-fixed-whitespace-trailing-error.patch 
- before sending patch you have to do some more configurations first `~/.gitConfig` set username,user email, smtpuser, smtpserver,smtpencryption etc then go to gmail manageAccount- >security- >2steps auth- >create app passwordand keep it safe that is the password will be used when using 'git send-patch' command
- Just to follow the next steps we first send the patch to ourself if everything is ok then go for next steps `git send-email < patch >` press enter it will ask for email enter your own email then check
- send email `git send-email --to < personEmailAddr > --cc < maintainer_1_email > --cc < maintainer_2_email > --cc < and so on > < patch >` check and press enter if everything is ok it may be multiple times 
- the above command can also be executed as `git send-email --cc-cmd='./scripts/get_maintainer.pl --norolestats < patch >' --cc < your email address > < patch >`
- on successful submission, verify the patch at 
- [link](https://lore.kernel.org/)
- before sending patch you have to do some more configurations first "~/.gitConfig" set username,user email, smtpuser, smtpserver,smtpencryption etc then go to gmail manageAccount- >security- >2steps auth- >create app passwordand keep it safe that is the password will be used when using 'git send-patch' command
- git send-patch
-
**Note:** you can also locate the requirements of work to be done in kernel by `linux$ find . -iname "TODO"`

git blame dir" It will show who wrote each and who review everything we can check it for ours later


---

# CROSS COMPILATION OF LINUX KERNEL:

## cross tool-chain installation and settings for linux host

**STEP 1 :**
Download arm cross toolchain for your Host machine
**STEP 2 :**
```bash
export  path of the cross compilation toolchain. 
export PATH=$PATH:/home/$USER/BBB_Workspace/Downloads/gcc-linaro-6.3.1-2017.02-x86_64_arm-linux-gnueabihf/bin
```
---
## U-boot Compilation

**STEP 1:** 
distclean : deletes all the previously compiled/generated object files. 

`make CROSS_COMPILE=arm-linux-gnueabihf- distclean`

**STEP 2 :**
apply board default configuration for uboot

`make CROSS_COMPILE=arm-linux-gnueabihf- am335x_boneblack_defconfig`


**STEP 3 :**
run menuconfig, if you want to do any settings other than default configuration . 

`make CROSS_COMPILE=arm-linux-gnueabihf-  menuconfig`


**STEP 4 :**
compile 
```bash
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4  // -j4(4 core machine) will instruct the make tool to spawn 4 threads
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j8  // -j8(8 core machine) will instruct the make tool to spawn 8 threads
```

---
## linux compilation
```bash
#STEP 1:
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean

# STEP 2:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bb.org_defconfig (4.4)
for 4.11 use omap2plus_defconfig

# STEP 3:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig

 # STEP 4:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- uImage dtbs LOADADDR=0x80008000 -j4

 # STEP 5:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4 modules

 # STEP 6:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=< path of the RFS > modules_install
```
---

## Busy box compilation

**STEP 1:**
download busybox 

**STEP 2 :**
Apply default configuration
`make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- defconfig`

**STEP 3 :**
change default settings if you want 
`make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig`

**STEP 4 :**
generate the busy box binary and minimal file system 
`make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- CONFIG_PREFIX=< install_path > install`

---

## build-root compilation

1. download the build root package from 
- [buildroot](https://buildroot.org/)
2. configure the build root 


## Dropbear compilation

1. Download Dropbear 
2. Configure Dropbear
`./configure --host=arm-linux-gnueabihf --disable-zlib --prefix=/home/$USER/BBB_Workspace/dropbear CC=arm-linux-gnueabihf-gcc`

3. compile the Dropbear as static 

`make PROGRAMS="dropbear dropbearkey dbclient scp" STATIC=1`

4. install dropbear generated binaries 
`make PROGRAMS="dropbear dropbearkey dbclient scp" install`


5. generate RSA and DSS keys 
dropbearkey -t dss -f dropbear_dss_host_key
dropbearkey -t rsa -f dropbear_rsa_host_key

6. run the dropbear 
 **dropbear**

7. make a SSh connection from pc 
`ssh -l root 192.168.7.2`





use this command to install an openssh server on your ubuntu host 
`sudo apt-get install openssh-server`





