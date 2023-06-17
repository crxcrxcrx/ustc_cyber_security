---
课堂: 210037.01 数理逻辑与图论(刘斌)  
姓名: 赵奕  
学号: PB21000033  
id: 1

---
### 1.1
13. 用符号写命题
- a. $p\land q$
- b. $p\land \lnot q$
- c. $\lnot p\land \lnot q$
- d. $p\lor q$
- e. $p\to q$
- f. $(p\lor q)\land(p\to \lnot q)$
- g. $p\leftrightarrow q$  
---
19. 判断语句真假
- a. 错 (T->F)
- b. 对 (F->T)
- c. 对 (F->F)
- d. 对 (F->F)  
---
35. 构建真值表（T表示真，F表示假）
- a. 
  | $p$ | $q$ | $(p\lor q)\to(p\oplus q)$ |
  | :-: | :-: | :-----------------------: |
  |  T  |  T  | F |
  |  T  |  F  | T |
  |  F  |  T  | T |
  |  F  |  F  | T |
- b. 
  | $p$ | $q$ | $(p\oplus q)\to(p\land q)$ |
  | :-: | :-: | :-----------------------: |
  |  T  |  T  | T |
  |  T  |  F  | F |
  |  F  |  T  | F |
  |  F  |  F  | T |
- c. 
  | $p$ | $q$ | $(p\lor q)\oplus(p\land q)$ |
  | :-: | :-: | :-----------------------: |
  |  T  |  T  | F |
  |  T  |  F  | T |
  |  F  |  T  | T |
  |  F  |  F  | F |
  |  F  |  F  | T |
- d. 
  | $p$ | $q$ | $(p\leftrightarrow q)\oplus(\lnot p\leftrightarrow q)$ |
  | :-: | :-: | :-----------------------: |
  |  T  |  T  | T |
  |  T  |  F  | T |
  |  F  |  T  | T |
  |  F  |  F  | T |
- e. 
  | $p$ | $q$ | $r$ | $(p\leftrightarrow q)\oplus(\lnot p\leftrightarrow \lnot r)$ |
  | :-: | :-: | :-: | :-----------------------: |
  |  T  |  T  |  T  | F |
  |  T  |  T  |  F  | T |
  |  T  |  F  |  T  | T |
  |  T  |  F  |  F  | F |
  |  F  |  T  |  T  | F |
  |  F  |  T  |  F  | T |
  |  F  |  F  |  T  | T |
  |  F  |  F  |  F  | F |
- f. 
  | $p$ | $q$ | $(p\oplus q)\to(p\oplus \lnot q)$ |
  | :-: | :-: | :-----------------------: |
  |  T  |  T  | T |
  |  T  |  F  | F |
  |  F  |  T  | F |
  |  F  |  F  | T |  
---
43. 解释  
    我们知道，当 $p,q,r$ 中至少有一个为真时 $p\lor q\lor r$ 为真，当 $p,q,r$ 中至少有一个为假时 $\lnot p\lor \lnot q\lor \lnot r$ 为真（可以看做将 $\lnot p,\lnot q,\lnot r$ 带入第一个式子得到）  
    因此对两个表达式作逻辑与，得到：当 $p,q,r$ 中至少有一个为真并且至少有一个为假时，$(p\lor q\lor r)\land(\lnot p\lor \lnot q\lor \lnot r)$ 为真。由此易得，当三个变量具有相同真值时表达式为假
### 1.2
11. 记：
- p: 路由器能向边缘系统发送分组
- q: 路由器支持新的地址空间
- r: 路由器安装了最新版本的软件

则题述逻辑可以化为：$p\leftrightarrow q;r\rightarrow q;r\rightarrow p;\lnot q$ 均为真  
这是自洽的，如：$p=F;q=F;r=F$    

---
29. 首先有：  
- B 的言语表示 B 不是骑士，也不是无赖；  
- C 的言语表示 C 不是骑士； 
 
因此 A 是骑士。  
继而有 B 是间谍，C 是无赖

--- 
39. 记：
- p: 男管家的话是真话
- q: 厨师的话是真话
- r: 园丁的话是真话
- s: 杂役的话是真话

则题述逻辑可以化为：$p\rightarrow q;\lnot q\lor\lnot r;r\lor s;s\rightarrow\lnot q$ 均为真  
若 $q=T$，可依次推出 $r=F,s=T,q=F$，矛盾，因此 $q=F$  
若 $p=T$ 可推出 $q=T$，矛盾，因此 $p=T$  
若 $r=T$ 可推出 $s=T/F$  
若 $r=F$ 可推出 $s=T$

因此仅能得到 男管家说的是假话 以及 厨师说的是假话，其他人无法判断。
### 1.3
19. $\begin{aligned}
&(\lnot q\land(p\rightarrow q))\rightarrow\lnot p\\
=&(\lnot q\land(\lnot p\lor q))\rightarrow\lnot p\\
=&((\lnot q\land\lnot p)\lor(\lnot q\land q))\rightarrow\lnot p\\
=&((\lnot q\land\lnot p)\lor F)\rightarrow\lnot p\\
=&(\lnot q\land\lnot p)\rightarrow\lnot p\\
\equiv&T\\[-80pt]
\end{aligned}$  

---
29.  $\begin{aligned}
&(p\rightarrow r)\lor(q\rightarrow r)\\
=&(\lnot p\lor r)\lor(\lnot q\lor r)\\
=&(\lnot p\lor\lnot q)\lor r\\
=&\lnot(p\land q)\lor r\\
=&(p\land q)\rightarrow r\\[-62pt]
\end{aligned}$

---
33.  
| $p$ | $q$ | $r$ | $p\rightarrow q$ | $q\rightarrow r$ | $p\rightarrow r$ | $(p\rightarrow q)\land(q\rightarrow r)\rightarrow(p\rightarrow r)$ |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  T  |  T  |  T  |  T  |  T  |  T  |  T  |
|  T  |  T  |  F  |  T  |  F  |  F  |  T  |
|  T  |  F  |  T  |  F  |  T  |  T  |  T  |
|  T  |  F  |  F  |  F  |  F  |  F  |  T  |
|  F  |  T  |  T  |  T  |  T  |  T  |  T  |
|  F  |  T  |  F  |  T  |  F  |  T  |  T  |
|  F  |  F  |  T  |  T  |  T  |  T  |  T  |
|  F  |  F  |  F  |  T  |  F  |  T  |  T  |

---
45. $(p\land q\land \lnot r)\lor(p\land \lnot q\land r)\lor(\lnot p\land q\land r)$

---
55. 易知 $p\downarrow p=\lnot p,p\lor q=\lnot(p\downarrow q)$  
    因此 $\begin{aligned}
&p\rightarrow q\\
=&\lnot p\lor q\\
=&(p\downarrow p)\lor q\\
=&((p\downarrow p)\downarrow q)\downarrow(p\downarrow p)\downarrow q\\[-48pt]
\end{aligned}$