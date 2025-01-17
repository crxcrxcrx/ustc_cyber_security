# 操作系统原理与设计

## 实验

一共四次实验：

### lab1

编译和调试Linux内核。不用写代码，会检查你编译和用gdb调试，会从题库中抽取Ubuntu终端的指令。

题库放在大礼包中，test.py为做题脚本。请检查实验之前先熟悉Ubuntu终端指令。

### lab2

完成一个Linux系统的shell（终端）和top（实时任务管理器）

需要用到进程、管道、系统调用等相关知识

top程序需要修改Linux内核源码，即，注册系统调用，需要修改的地方都放在了大礼包中。

### lab3

Linux系统的进程管理

1. 写一个进程的堆管理器，实现malloc, free, realloc等操作。
2. 注册一个内核模块，实现对一个进程内存占用的统计。分为五个部分，分别为统计VMA的个数，绘制页面活跃性统计图，在多级页表上查找虚拟地址对应的物理页号，保存内存中的数据段，保存内存中的代码段。为了节省仓库空间，大礼包中只放了需要修改的文件代码。

### lab4

FAT文件系统的操作

1. 实现遍历文件目录（即ls和tree指令的底层）
2. 实现读文件(即cat指令的底层)
3. 实现创建和删除文件(即touch和rm指令的底层)
4. 实现创建和删除目录(即mkdir和rmdir指令的底层)
5. 实现写文件(即echo >和echo >>指令的底层)

**由于大礼包的贡献者实在是又菜又懒，所以写文件并没有完成（但它其实并不难，只是很繁琐），然后两个FAT表也只改了一个（其实是作者忘了）。所以，代码仅供参考。**

## 作业

五次作业，不保证正确（而且可能有很多错误），仅供参考！