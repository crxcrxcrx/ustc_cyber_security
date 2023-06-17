---
课堂: 210037.01 数理逻辑与图论(刘斌)  
姓名: 赵奕  
学号: PB21000033  
id: 3

---
## 1.8
### 5
- 当 $x\ge y$ 时 $\max(x,y)=x,\min(x,y)=y$ 因此 $\max(x,y)+\min(x,y)=x+y$
- 当 $x<y$ 时 $\max(x,y)=y,\min(x,y)=x$ 因此 $\max(x,y)+\min(x,y)=x+y$

由上得证
### 13
因为只需要证明存在，因此找到一对满足题意的数 $(8,9)$ （其中 $8=2^3,9=3^2$） 即得证
### 27
注意到，$(j+k)-|j-k|=2\min(j,k)$ 因此一次操作后黑板上的数的和奇偶性不变，故最后一个整数与 $\sum\limits_{i=1}^{2n}$ 

因为 $\sum\limits_{i=1}^{2n}=n(2n+1)$ 为奇数，故最后一个整数为奇数
### 51
形状
```plain
@ @@ @@ @  @
@ @@ @  @@ @@
@    @  @   @
@
```
组成棋盘（前四种）
```plain
@ % # $   @ @ # #   @ @ # #   @ # # #
@ % # $   @ @ # #   @ % # $   @ @ # %
@ % # $   % % $ $   @ % # $   @ $ % %
@ % # $   % % $ $   % % $ $   $ $ $ %
# $ @ %   @ @ # #   @ @ # #   @ # # #
# $ @ %   @ @ # #   @ % # $   @ @ # %
# $ @ %   % % $ $   @ % # $   @ $ % %
# $ @ %   % % $ $   % % $ $   $ $ $ %
```
第五种不行，理由：  
由对称性，不妨设 $(1,1),(1,2),(2,2),(2,3)$ 有一个骨牌，因此不得不紧邻该骨牌在右侧放置 $(1,3),(1,4),(2,4),(2,5)$ 以及 $(1,5),(1,6),(2,6),(2,7)$ 这时以及不可能覆盖 $(1,7)$ 因此不可行
## 2.1
### 11
a)假; b)假; c)假; d)真; e)假; f)假; g)真; 
### 27
$\mathcal{P}(A)\subseteq \mathcal{P}(B)\rightarrow A\subseteq B$：对任意 $t\in A$ 如果有 $\{t\}\subseteq A$ 则 $\{t\}\in\mathcal{P}(A)$ 则 $\{t\}\in\mathcal{P}(B)$ 所以 $\{t\}\subseteq B$ 故 $t\in B$，因此 $A\subseteq B$  
$A\subseteq B\rightarrow\mathcal{P}(A)\subseteq \mathcal{P}(B)$：对任意 $c\in \mathcal{P}(A)$，有 $c\subseteq A$。又因为 $A\subseteq B$ 所以有 $c\subseteq B$ 则 $c\in\mathcal{P}(B)$ 故 $\mathcal{P}(A)\subseteq \mathcal{P}(B)$
### 41
对任意 $a\in A,b\in B,c\in C$ 我们有 $((a,b),c)\in (A\times B)\times C$ 但 $((a,b),c)\notin A\times B\times C$ 以及 $(a,b,c)\in A\times B\times C$ 但 $(a,b,c)\notin (A\times B)\times C$
### 43
不成立。若 $A=B=\varnothing$ 则 $\mathcal{P}(A)=\mathcal{P}(B)=\{\varnothing\}$ 和 $A\times B=\varnothing$  
然而 $\mathcal{P}(A)\times \mathcal{P}(B)=\{(\varnothing,\varnothing)\}$ 但 $\mathcal{P}(A\times B)=\varnothing$
### 49
$a=c\land b=d\rightarrow \{\{a\},\{a,b\}\}=\{\{c\},\{c,d\}\}$ 是显然的

下证 $\{\{a\},\{a,b\}\}=\{\{c\},\{c,d\}\}\rightarrow a=c\land b=d$：

若 $a\not= b$ 此时必有 $\{a\}=\{c\}$（因为仅有这两个集合是一个元素），所以 $a=c$ 继而 $\{a,b\}=\{c,d\}$ 继而 $b=d$  
若 $a=b$ 此时有 $$\{\{a\},\{a,b\}\}=\{\{a\}\}$ 只有一个元素，因此必有 $\{c\}=\{c,d\}$ 因此有 $c=d$，故 $\{\{c\},\{c,d\}\}=\{\{c\}\}$，所以 $\{\{a\}\}=\{\{c\}\}$ 因此 $a=c$ 易得 $b=d$

## 2.2
### 19
方法①：  
$\begin{aligned}&x\in\overline{A\cap B\cap C}\\ \leftrightarrow&x\notin{A\cap B\cap C}\\ \leftrightarrow&x\notin A\lor x\notin B\lor x\notin C\\ \leftrightarrow&x\in \overline{A}\lor x\in \overline{B}\lor x\in \overline{C}\\ \leftrightarrow&x\in\overline{A}\cup\overline{B}\cup\overline{C}\end{aligned}$

方法②：  
|$x\in A$|$x\in B$|$x\in C$|$x\in\overline{A\cap B\cap C}$|$x\in\overline{A}\cup\overline{B}\cup\overline{C}$|
|:-:|:-:|:-:|:-:|:-:|
|T|T|T|F|F|
|T|T|F|T|T|
|T|F|T|T|T|
|T|F|F|T|T|
|F|T|T|T|T|
|F|T|F|T|T|
|F|F|T|T|T|
|F|F|F|T|T|
### 35
$\overline{A\cup B}\cap\overline{A\cup C}\cap\overline{B\cup C}=\overline{A}\cap\overline{B}\cap\overline{A}\cap\overline{C}\cap\overline{B}\cap\overline{C}=\overline{A}\cap\overline{B}\cap\overline{C}$
### 47
对于 $x\in A$ 若 $x\in C$ 则 $x\notin A\oplus C$ 故 $x\notin B\oplus C$ 故 $x\in B$  
若 $x\notin C$ 则 $x\in A\oplus C$ 故 $x\in B\oplus C$ 故 $x\in B$  
因此 $A\subseteq B$ 同理 $B\subseteq A$ 故 $A=B$

## 2.3
### 3
- a) 不是（多值）
- b) 是
- c) 是

### 21
- a) $f(x)=\begin{cases}2x+2&x\ge 0\\-2x+1&x<0\end{cases}$
- b) $f(x)=|x|+1$
- c) $f(x)=\begin{cases}2x+2&x\ge 0\\-2x-1&x<0\end{cases}$
- d) $f(x)=|x|+2$

### 37
不能；例如：  
当 $x\in R$，值域也是 $R$ 时设 $f(x)=\begin{cases}\ln(|x|)&x\not=0\\0&x=0\end{cases},g(x)=x^2$ 则 $f(g(x))$ 与 $f(x)$ 都映上，但 $g(x)$ 不映上
## 2.4
### 27
- 考虑到 $a_n-a_{n-1} = 1+\{\sqrt{n}\}-\{\sqrt{n-1}\}$，因此若 $a_n-a_{n-1}\not=1$ 必有 $a_n-a_{n-1}=2$ 且 $\{\sqrt{n}\}-\{\sqrt{n-1}\}=1$。因此必定存在 $x\in Z_+$ 使得 $\{\sqrt{n}\}>x+0.5>\{\sqrt{n-1}\}$ 故 $n>x^2+x+0.25>n-1$ 因此 $n=x^2+x+1$，故 $a_n=x^2+2x+2$ 以及 $a_{n-1}=x^2+2x$，可以发现 $(x+1)^2$ 被跳过了。因此有，所有 $a_n-a_{n-1}=2$ 的 $n$ 都满足 $a_n$ 与 $a_{n-1}$ 中有一个完全平方数。所有可以推得 $a_n$ 包括所有非完全平方数的正整数。又因为 $a_1=2$，是第 1 个非完全平方数的正整数，所以 $a_n$ 是第 n 个非完全平方数的正整数

## 2.5
### 11
- a) $A=[1,2],B=[2,3]$
- b) $A=[1,2]\cup N,B=[3,4]\cup N$
- c) $A=B=R$
### 17
一定。注意到 $A=(A-B)\cup(A\cap B)$，且 $A$ 不可数，$A\cap B$ 可数（因为 $B$ 可数），故 $A-B$ 一定不可数
### 31
映上：对于任意 $z=f(m,n)$，若 $(x-2)(x-1)/2 < z \le (x-1)x/2$，则取 $m=z-(x-2)(x-1)/2,n=x-m$，易知 $m,n>0$ 即有 $f(m,n)=z$。

一对一：上述 $m,n$ 是唯一的。这是因为，当 $m+n$ 固定时，一定只存在一个 $m$；  
下证不存在多个 $m+n$ 可以使式子成立。易知 $0\le m<x$，因此若 $m^\prime+n^\prime>x$ 则可算得 $m^\prime=z-(m^\prime+n^\prime-2)(m^\prime+n^\prime-1)/2\le 0$ 不符合题意；若有 $m^\prime+n^\prime<x$ 则可算得 $m^\prime=z-(m^\prime+n^\prime-2)(m^\prime+n^\prime-1)/2\ge x-1\ge m^\prime+n^\prime$ 得 $n^\prime\le 0$ 不符合题意。故不存在多个 $m+n$ 可以使式子成立。