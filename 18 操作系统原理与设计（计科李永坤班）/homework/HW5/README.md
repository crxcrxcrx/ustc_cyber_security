# Consider a RAID organization comprising five disks in total, how many blocks are accessed in order to perform the following operations for RAID-5 and RAID-6?

## An update of one block of data

### RAID5

1. Read the parity block. 
2. Read the old data stored in the target block. 
3. Write the target block. 
4. Write the parity block. 

Read 2 blocks, write 2 blocks. 

### RAID6

​	One more parity block than RAID5. 

​	Read 3 blocks, write 3 blocks. 

## An update of seven continuous blocks of data. Assume that the seven contiguous blocks begin at a boundary of a stripe.

### RAID5

1. Read the first 4 blocks. 
2. Read the parity block of the first stripe. 
3. Write the first 4 blocks. 
4. Write the parity block of the first stripe. 
5. Read the next 4 blocks. 
6. Read the parity block of the next stripe. 
7. Write the first 3 blocks. 
8. Write the parity block of the next stripe. 

Read 10 blocks, write 9 blocks. 

### RAID6

​	One more parity block than RAID5. 

​	Read 11 blocks, write 10 blocks.

# Suppose that a disk drive has 5,000 cylinders, numbered 0 to 4999. The drive is currently serving a request at cylinder 2150, and the previous request was at cylinder 1805. The queue of pending requests, in FIFO order, is: 2069, 1212, 2296, 2800, 544, 1618, 356, 1523, 4965, 3681 Starting from the current head position, what is the total distance (in cylinders) that the disk armmoves to satisfy all the pending requests for each of the following disk-scheduling algorithms?

## FCFS

2150, 2069, 1212, 2296, 2800, 544, 1618, 356, 1523, 4965, 368

Distance = 13011

## SSTF

2150, 2069, 2296, 2800, 3681, 4965, 1618, 1523, 1212, 544, 356

Distance = 7586

## SCAN

2150, 2296, 2800, 3681, 4965, 2069, 1618, 1523, 1212, 544, 356

Distance = 7492

## LOOK

2150, 2296, 2800, 3681, 4965, 2069, 1618, 1523, 1212, 544, 356

Distance = 7424

## C-SCAN

2150, 2296, 2800, 3681, 4965, 356, 544, 1212, 1523, 1618, 2069

Distance = 9917

## C-LOOK

2150, 2296, 2800, 3681, 4965, 356, 544, 1212, 1523, 1618, 2069

Distance = 9137

# Explain what open-file table is and why we need it.

The Open File Table stores the information about all the files that are open while the OS is running. 

By keeping a central open-file table, the operating system can perform the following operation that would be infeasible otherwise.

# What does “755” mean for file permission?

7=4+2+1， read, write, execute for the owner. 

5=4+1, read, execute for the group. 

5=4+1, read, execute for the others.

# Explain the problems of using continuous allocation for file system layout and how to solve them.

Problems: 

1. May suffer from both internal and external fragmentation.
2. In this method, it is difficult to increase the size of the file due to the availability of the contiguous memory block.

How to solve:

​	 First-fit, best-fit or worse-fit of free list. 

# What are the advantages of the variation of linked allocation that uses a FAT to chain together the blocks of a file? What is the major problem of FAT?

Advantages:

1. No external fragmentation.
2. A directory entry only comprises of the starting block address.
3. We can quickly increase the size of the file. 

Problem:

​	Deleting Problem: Not really delete the data, just modify the directory entry. Need extra protection for deleted data. 

# Consider a file system similar to the one used by UNIX with indexed allocation, and assume that every file uses only one block. How many disk I/O operations might be required to read the contents of a small local file at /a/b/c in the following two cases? Should provide the detailed workflow.

## Assume that none of the disk blocks and inodes is currently being cached.

1. root directory
2. inode for /a
3. disk block for /a
4. inode for /a/b
5. disk block for /a/b
6. inode for /a/b/c
7. disk block for /a/b/c

## Assume that none of the disk blocks is currently being cached but all inodes are in memory.

1. root directory
2. disk block for /a
3. disk block for /a/b
4. disk block for /a/b/c

# Consider a file system that uses inodes to represent files. Disk blocks are 8-KB in size and a pointer to a disk block requires 4 bytes. This file system has 12 direct disk blocks, plus single, double, and triple indirect disk blocks. What is the maximum size of a file that can be stored in this file system?

$(12 * 8 KB) + (2048 * 8 KB) + (2048 * 2048 * 8 KB) + (2048 * 2048 * 2048 * 8 KB) \approx  64TB$

# What is the difference between hard link and symbolic link?

A hard link to a file will point to the place where the file is stored, or the inode of that file.  

A symbolic link will point to the actual file itself.

# What is the difference between data journaling and metadata journaling? Explain the operation sequence for each of the two journaling methods.

Data journaling logs data. 

Write sequence: Journal Write --> Journal Commit --> Checkpoint --> Free

Metadata journaling logs metadata only.

Write sequence: Data Write --> Journal Metadata Write --> Journal Commit --> Checkpoint --> Free

# What are the three I/O control methods?

1. Programmed I/O
2. Interrupt-Based I/O
3. DMA

# What services are provided by the kernel I/O subsystem?

1. I/O scheduling
2. Buffering
3. Caching
4. Spooling
5. Error handling and I/O protection
6. Power management