---
课堂: 210037.01 数理逻辑与图论(刘斌)  
姓名: 赵奕  
学号: PB21000033  
id: 2

---
## 1.4
### 7
- a. 喜剧演员都很有趣
- b. 所有人都是有趣的喜剧演员
- c. 存在一个喜剧演员很有趣
- d. 存在一个有趣的喜剧演员

### 27
- a.  
  1. 论域：所有人  
     $p(x):$ $x$ 是学校里的学生  
     $q(x):$ $x$ 在越南居住过  
     $\exist x(p(x)\land q(x))$
  2. 论域：学校里的所有人  
     $p(x):$ $x$ 是学生  
     $q(x):$ $x$ 在越南居住过  
     $\exist x(p(x)\land q(x))$
  3. 论域：学校里的学生  
     $p(x,y):$ $x$ 在 $y$ 居住过  
     $\exist x\space p(x,\text{越南})$
- b.  
  1. 论域：所有人  
     $p(x):$ $x$ 是学校里的学生  
     $q(x):$ $x$ 会说印地语  
     $\exist x(p(x)\land\lnot q(x))$
  2. 论域：学校里的所有人  
     $p(x):$ $x$ 是学生  
     $q(x):$ $x$ 会说印地语  
     $\exist x(p(x)\land\lnot q(x))$
  3. 论域：学校里的学生  
     $p(x):$ $x$ 会说 $y$ 语言  
     $\exist x\lnot p(x,\text{印地})$
- c.  
  1. 论域：所有人  
     $p(x):$ $x$ 是学校里的学生  
     $q(x):$ $x$ 会 $Java,Prolog,C++$  
     $\exist x(p(x)\land q(x))$
  2. 论域：学校里的所有人  
     $p(x):$ $x$ 是学生  
     $q(x):$ $x$ 会 $Java,Prolog,C++$  
     $\exist x(p(x)\land q(x))$
  3. 论域：学校里的学生  
     $p(x,y):$ $x$ 会 $y$ 编程语言  
     $\exist x(p(x,Java)\land p(x,Prolog)\land p(x,C++))$
- d.  
  1. 论域：所有人  
     $p(x):$ $x$ 是班上的学生  
     $q(x):$ $x$ 喜欢泰国食物  
     $\forall x(p(x)\land q(x))$
  2. 论域：班上的所有人  
     $p(x):$ $x$ 是学生  
     $q(x):$ $x$ 喜欢泰国食物  
     $\forall x(p(x)\land q(x))$
  3. 论域：班上的学生  
     $p(x,y):$ $x$ 喜欢 $y$ 国食物  
     $\forall x(p(x,\text{泰国}))$
- e.  
  1. 论域：所有人  
     $p(x):$ $x$ 是班上的学生  
     $q(x):$ $x$ 玩曲棍球  
     $\exist x(p(x)\land\lnot q(x))$
  2. 论域：班上的所有人  
     $p(x):$ $x$ 是学生  
     $q(x):$ $x$ 玩曲棍球  
     $\exist x(p(x)\land\lnot q(x))$
  3. 班上的学生  
     $p(x,y):$ $x$ 玩 $y$  
     $\exist x\lnot p(x,\text{曲棍球})$

### 63
- a. $\forall x(P(x)\to\lnot Q(x))$
- b. $\forall x(R(x)\to\lnot S(x))$
- c. $\forall x(\lnot Q(x)\to S(x))$
- d. $\forall x(P(x)\to\lnot R(x))$
- e. 能; 首先由 b 易得 $\forall x(S(x)\to\lnot R(x))$  
  因此 $\forall x$ 我们有 $P(x)\to\lnot Q(x)\to S(x)\to\lnot R(x)$ 即 d

## 1.5
### 7
- a. Abdallah Hussein 不爱吃日本菜
- b. 学校中有爱吃韩国菜的人，并且学校里所有人都爱吃墨西哥菜
- c. 有至少一道菜，至少被 Monique Arsenault 或者 Jay Johnson 喜欢
- d. 没有一道菜，被多于一个学生喜欢
- e. 是永真式
- f. 对于任意的两个学生，至少存在一道菜，他们的看法相同
  
### 11
- a. $A(Lois, Michaels\text{教授})$
- b. $\forall x(S(x)\to A(x,Gross\text{教授}))$
- c. $\forall x(F(x)\to (A(x,Miller\text{教授})\lor A(x,Miller\text{)教授}))$
- d. $\exists x\forall y((S(x)\land F(y))\to\lnot A(x,y))$
- e. $\exists y\forall x((S(x)\land F(y))\to\lnot A(x,y))$
- f. $\exists x\forall y((S(x)\land F(y))\to A(x,y))$
- g. $\exists x\forall y((F(x)\land F(y)\land x\not= y)\to A(x,y))$
- h. $\exists x\forall y((S(x)\land F(y))\to\lnot A(y,x))$

### 21
论域是全体整数  
$\forall x\exists a\exists b\exists c\exists d((x>0)\to x=a^2+b^2+c^2+d^2)$

### 35
使得式为真：$\{1,2,3,4\}$  
使得式为假：$\{1,2,3\}$  

## 1.6
### 11
1. 当 $p_1,p_2,\dots,p_n$ 均为假的时候，显然原式成立
2. 当 $p_1,p_2,\dots,p_n$ 均为真，$q$ 为真时，显然有 $r$ 真以及 $q\to r$ 真
3. 当 $p_1,p_2,\dots,p_n$ 均为真，$q$ 为假时，显然有 $r$ 假以及 $q\to r$ 是否真假无意义

### 23
错误 - 第 6 步：3, 5 中 c 不一定相同

### 29
1. $\exists x\lnot P(x)$（前提引入）
2. $\lnot P(c)$（存在实例，由(1)）
3. $\forall x(P(x)\lor Q(x))$（前提引入）
4. $P(c)\lor Q(c)$（全称实例，由于(3)）
5. $Q(c)$（折取三段论，由(2),(4)）
6. $\forall x(\lnot Q(x)\lor S(x))$
7. $\lnot Q(c)\lor S(c)$（全称实例，由于(6)）
8. $S(c)$（折取三段论，由(5),(7)）
9. $\forall x(R(x)\to\lnot S(x))$
10. $R(c)\to\lnot S(c)$（全称实例，由于(9)）
11. $\lnot R(c)$（假言推理，由(8),(10)）
12. $\exists x\lnot R(x)$（存在引入，由(11)）

### 35
有效；

记：
- p: 超人能够防止邪恶
- q: 超人愿意防止邪恶
- r: 超人防止了邪恶
- s: 超人是无能的
- t: 超人是恶意的
- u: 超人存在

前提：$\begin{cases}p\land q\to r\\ \lnot p\to s\\ \lnot q\to t\\ \lnot r\\ u\to(\lnot s\land\lnot t)\end{cases}$

推理过程：由 $\lnot r$ 得出 $\lnot p\lor\lnot q$ 得出 $s\lor t$ 得出 $\lnot(\lnot s\land\lnot t)$ 得出 $\lnot u$ 即超人不存在

## 1.7
### 15
如果 $\sqrt{x}$ 是有理数，记 $\sqrt{x}=\frac{p}{q}(p,q\in Z^*)$ 则 $x=\frac{p^2}{q^2}$ 是有理数（因为 $p^2,q^2\in Z^*$）矛盾，因此 $\sqrt{x}$ 是无理数

### 19
- a. 如果 $n$ 是奇数，则 $n^3$ 是奇数进而 $n^3+5$ 是偶数，矛盾，因此 $n$ 是偶数
- b. 假设 $n,n^3+5$ 均为奇数，则 $n$ 是奇数 $\to$ $n^3$ 是奇数，推得 $(n^3+5)-n^3$ 是偶数即 $5$ 是偶数，矛盾，因此假设错误

### 41
反证法：若所有数均小于平均数，则有

$a_1+a_2+\cdots+a_n<n\cdot\overline{a}$

即 $a_1+a_2+\cdots+a_n<a_1+a_2+\cdots+a_n$ 矛盾

