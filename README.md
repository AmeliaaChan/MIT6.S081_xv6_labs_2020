# MITS.S081_xv6_labs_2021
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
### 一个小插曲 由于本人前面做的是2021版本，发现从lab3开始与2020版本实验有差异，遂改做2020版本:)
