# MITS.S081_xv6_labs_2020
## 1. util
> Lec1_lab: Xv6 and Unix utilities
***
## 2. syscall
> Lec3_lab: Systerm calls
### 2.1 Systerm call tracing
***
### 2.2 Sysinfo
内容：收集正在运行系统的信息，包括可用内存字节数和状态不是`UNUSED`的进程数，返回给用户  

总体难度：根据`hints`逐步完成，问题不大  

在`kernel/kalloc.c`中参考`kalloc()`完成函数`col_freemem()`，功能是计算可用内存字节数  
> Attention：这里所求内存大小单位是“字节数”，`kalloc()`注释中的`4096-byte page`是关键信息

在`kernel/proc.c`中参考`allocproc()`完成函数`col_nproc`，功能是计算状态不是`UNUSED`的进程数  

在`kernel/sysproc.c`中完成`sysinfo()`  
> Attention：苯人未在`kernel/defs.h`中增加`col_freemem()`和`col_nproc()`导致编译时报错(#`O′)
***
## 一个小插曲 由于本人前面做的是2021版本，发现从lab3开始与2020版本实验有差异，遂改做2020版本:)
***
## 3. pgtbl
> Lec4_lab: Page tables
### 3.1 Print a page table
内容：打印页表内容  

总体难度：easy  

在`kernel/vm.c`中参考`freewalk()`完成函数`vmprint()`  

思路：已知页表有三级，也就是如果要完成逐级打印页表只需要写三级循环就可以(OK一如既往的糟糕的代码风格)，主要是偷懒为了避免多写一个helper函数来进行递归2333
>Attention: 这里检索pte时的条件如果照抄`freewalk()`中的`if((pte & PTE_V) && (pte & (PTE_R|PTE_W|PTE_X)) == 0)`，则在输出第三级pte时将出错，显然后半部分应删去
***
