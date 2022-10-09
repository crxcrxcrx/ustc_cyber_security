# Explain the follow terms

## Segmentation fault

The memory in a process is separated into segments. 

When you visit a segment in an illegal way, then Segmentation Fault. 

## TLB

TLB is a memory cache that stores the **recent** translation of virtual memory to physical memory. 

## Page Fault

A page fault is an exception that the MMU raises when a process accesses a virtual memory page but have not been mapped in physical page.

## Demand Paging

In a system that uses demand paging, the operating system copies a disk page into physical memory only if an attempt is made to access it and that page is not already in memory

# Introduce the concept of thrashing, and explain under what circumstance thrashing will happen.

- Thrashing: A frequent page fault, that OS need to replace a page that will be needed again right away. 
- It occurs if a process does not have enough frames – number of frames required to support pages in active use. 

# Consider a paging system with the page table stored in memory.

## If a memory reference takes 50 nanoseconds, how long does a paged memory reference take?

100 ns: 50ns to access the page table and 50ns to access the word in memory. 

## If we add TLBs, and 75 percent of all page-table references are found in the TLBs, what is theeffective memory reference time? (Assume that finding a page-table entry in the TLBs takes 2 nanoseconds, if the entry is present.)

$$
0.75\times (50ns+2ns) + 0.25*(50ns+50ns+2ns)=64.5ns
$$

# Assume a program has just referenced an address in virtual memory. Describe a scenario how each of the following can occur: (If a scenario cannot occur, explain why.)

## TLB miss with no page fault

The page is not in TLB but in page table. 

## TLB miss and page fault

The page is neither in TLB nor in page table. 

## TLB hit and no page fault

The page is in TLB. 

## TLB hit and page fault

Never occurs: every page in TLB is also in page table, so TLB hit never leads page fault. 

# Assume we have a demand-paged memory. The page table is held in registers. It takes 8 milliseconds to service a page fault if an empty page is available or the replaced page is notmodified, and 20 milliseconds if the replaced page is modified. Memory access time is 100 nanoseconds. Assume that the page to be replaced is modified 70 percent of the time. What is the maximum acceptable page-fault rate for an effective access time of no more than 200 nanoseconds?

Let $p$ be the page fault rate. 

We have,
$$
(1-p)\times 100+0.7p\times 20000000+0.3p\times 8000000\leq 200
\\
p\geq 100/(14000000+2400000-100)=0.00061\%
$$

# Consider the following page reference string: 7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0, 1. Assuming demand paging with three frames, how many page faults would occur for the following replacement algorithms?

## LRU replacement

Bold the page which cause page fault:

**7**; 7 **2**;  7 2 **3**; **1** 2 3; 1 2 3; 1 2 **5**; **3** 2 5; 3 **4** 5; 3 4 **6**; **7** 4 6; 7 4 6; 7 **1** 6; 7 1 **0**; **5** 1 0; 5 **4** 0; 5 4 **6**; **2** 4 6; 2 **3** 6; 2 3 **0**; **1** 3 0

18 page faults

## FIFO replacement

**7**; 7 **2**;  7 2 **3**; **1** 2 3; 1 2 3; 1 **5** 3; 1 5 3; 1 5 **4**; **6** 5 4; 6 **7** 4; 6 7 4; 6 7 **1**; **0** 7 1; 0 **5** 1; 0 5 **4**; **6** 5 4; 6 **2** 4; 6 2 **3**; **0** 2 3; 0 **1** 3

17 page faults

## Optimal replacement

To replace the page that will not be used for the longest period of time.

**7**; 7 **2**;  7 2 **3**; **1** 2 3; 1 2 3; 1 **5** 3; 1 5 3; 1 5 **4**; 1 5 **6**; 1 5 **7**; 1 5 7; 1 5 7; 1 5 **0**; 1 5 0; 1 **4** 0; 1 **6** 0; 1 **2** 0; 1 **3** 0; 1 3 0; 1 3 0

13 page faults

# Explain what Belady’s anomaly is, and what is the feature of stack algorithms which never exhibit Belady’s anomaly?

- Belady’s anomaly is the name given to the phenomenon  where increasing the number of page frames results in an increase in the number of page faults for a given memory access pattern.
- Optimal replacement and LRU never exhibit Belady’s anomaly. 