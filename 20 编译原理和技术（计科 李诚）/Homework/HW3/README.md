# 第三次作业

## 3.8

### （a)

该文法中，$L\rightarrow L,S|S$ 存在左递归。

作出如下修改：

$S\rightarrow (L)|a$

$L\rightarrow SL'$​

$L'\rightarrow ,SL'|\epsilon$​

### （b)

$First(S)=\{( , a\}$

$First(L)=\{( , a\}$​

$First(L')=\{, , \epsilon\}$​​

$Folllow(S)=\{, , ),\$\}$

$Folllow(L)=\{),\$\}$

$Folllow(L')=\{),\$\}$

|          |                    |                      | 输入符号           |                          |                          |
| -------- | ------------------ | -------------------- | :----------------- | ------------------------ | ------------------------ |
| 非终结符 | a                  | ,                    | （                 | ）                       | $                        |
| S        | $S\rightarrow a$   |                      | $S\rightarrow (L)$ |                          |                          |
| L        | $L\rightarrow SL'$ |                      | $L\rightarrow SL'$ |                          |                          |
| L'       |                    | $L'\rightarrow ,SL'$ |                    | $L'\rightarrow \epsilon$ | $L'\rightarrow \epsilon$ |

## 3.10

$First(D)=First(T)=\{int,real\}$

$First(L)=\{id\}$

$First(R)=\{,,\epsilon\}$

$Follow(D)=Follow(L)=Follow(R)=\{\$\}$

$Follow(T)=id$

|          |                    |                     | 输入符号            |                      |                        |
| -------- | ------------------ | ------------------- | :------------------ | -------------------- | ---------------------- |
| 非终结符 | int                | real                | id                  | ,                    | $                      |
| D        | $D\rightarrow TL$  | $D\rightarrow TL$   |                     |                      |                        |
| T        | $T\rightarrow int$ | $T\rightarrow real$ |                     |                      |                        |
| L        |                    |                     | $L\rightarrow id R$ |                      |                        |
| R        |                    |                     |                     | $R\rightarrow ,id R$ | $R\rightarrow\epsilon$ |

## 3.12

$First(S)=\{x,d,a\}$

$First(A)=\{x\}$

$First(B)=\{b\}$

$First(P)=\{d,\epsilon\}$

$First(Q)=\{a,\epsilon\}$

对于两个产生式$S\rightarrow AB|PQx$

有

$First(AB)=\{x\}$​

$First(PQx)=\{x,d,a\}$

二者的交集不是空集，所以不是LL(1)文法。

## 3.16

### a

<img src="README.assets/image-20211001203033032.png" alt="image-20211001203033032" style="zoom: 25%;" />

### b

<img src="README.assets/image-20211001203054918.png" alt="image-20211001203054918" style="zoom:25%;" />

### c

<img src="README.assets/image-20211001203116044.png" alt="image-20211001203116044" style="zoom:25%;" />
