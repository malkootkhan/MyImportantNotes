# Main Linux topics to be studied each:

## Linux Kernel Overview
- Diagram of Linux subsystems
- Role of the kernel
- Code Contexts
- User Space and Kernel Space
- Introducing LXR
- System Call Interface

## Processes
- Process data structures
- The /proc File System
- Process creation
- User/Kernel Mode Stacks
- Linked Lists
## Loadable Kernel Modules
- What are they
- Module related commands
- Module functions
- Printk()
- Kernel Modules and the GPL
## Debugging Kernel Code
- More on Printk()
- creating /proc files
- The sys file system
 - [ ] debugfs
- cscope
- kernel crashes —the “oops” message
- KDB and KGDB
## Synchronization
- Need for Synchronization
- [ ] critical Section
- Mutexes
- semaphores
- Completions
- A tomic Operations
- [ ] Bits
- [ ] Integers
- Spin locks
- [ ] Read-write Spinlocks
- Alternative to Blocking

- [ ] Sequential Locks
- [ ] Read-Copy-Update
- [ ] Per-CPU Variables
## Memory Management
- Virtual Memory
- Paging
- kmalloc() and friends
- Slab Allocator
- get_free_page() and friends
- Buddy Algorithm
## Device Drivers
- What is a Device Driver?
- The /dev directory
- Device Registration
- [ ] The File Operations Table
- Unified Device Model
 

## Interrupt Context
- interrupt handlers
- [ ] Registering an Interrupt Handler
- Deferred work

- [ ] Tasklets
- [ ] Workqueues
- Timers
## Virtual Filesystem/Block Devices
- VFS data structures
- Adding a filesystem
- The Block Layer
- [ ] I/O Schedulers
- Block devices
## Configuring and Building the Kernel
- Why build the kernel?
- Where to get the Kernel
- [ ] Upstream and Downstream Kernels
- Kernel Source Tree
- Configuring the Kernel
- Building and Installing the Kernel
## The Scheduler
- What does the Scheduler Do?
- Completely Fair Scheduler
- [ ] Red/Black Trees
- High Resolution Timer
## The Linux Boot Process
- BIOS
- Bootloader
- [ ] Grub
- Initial RAM Disk
- Kernel Initialization
- init process
- Run Levels
