# 第五次作业

## 4.3

### (a)

| $S'\rightarrow S$    | print($S.num$)        |
| -------------------- | --------------------- |
| $S\rightarrow (L)$   | $S.num=L.num+1$       |
| $S\rightarrow a$     | $S.num= 0$​            |
| $L\rightarrow L_1,S$ | $L.num=L_1.num+S.num$ |
| $L\rightarrow S$     | $L.num=S.num$         |

### (b)

| $S'\rightarrow S$    | print($S.max$​)               |
| -------------------- | ---------------------------- |
| $S\rightarrow (L)$   | $S.max=L.max+1$​              |
| $S\rightarrow a$     | $S.max= 0$​​                   |
| $L\rightarrow L_1,S$ | $L.max=max\{L_1.max,S.max\}$​ |
| $L\rightarrow S$     | $L.max=S.max$​                |

## 4.5

| $S\rightarrow E$                              | print($E.max$)                   |
| --------------------------------------------- | -------------------------------- |
| $E\rightarrow \text{while }E_1\text{ do }E_2$ | $E.max=max\{E_1.max,E_2.max\}+1$ |
| $E\rightarrow id:=E_1$                        | $E.max=E_1.max$                  |
| $E\rightarrow E_1+E_2$                        | $E.max=max\{E_1.max,E_2.max\}$   |
| $E\rightarrow id$                             | $E.max=0$                        |
| $E\rightarrow (E_1)$​                          | $E.max=E_1.max$                  |

## 4.9

### (b)

inh：该文法符号在推导过程中相对于小数点的位置

syn：文法符号L推出的串的总贡献

| $S'\rightarrow S$      | print($S.val$)                                               |
| ---------------------- | ------------------------------------------------------------ |
| $S\rightarrow L_1.L_2$ | $S.val=L_1.syn+L_2.syn$​ ,  $L_1.inh=0$​  , $L_2.inh=-1$​       |
| $S\rightarrow L$       | $S.val=L.syn$​  , $L.inh=1$​                                   |
| $L\rightarrow L_1B$​    | $L.syn=L_1.syn+B.c$​​​  , $L_1.inh=\text{if (L.inh>0) } L.inh+1 \text{ else }L.inh-1$​​​ ,  $B.inh=L.inh$​​​​ |
| $L\rightarrow B$       | $L.syn=B.c$​​​ , $B.inh=L.inh$​​​                                  |
| $B\rightarrow 0$       | $B.c=0$                                                      |
| $B\rightarrow 1$       | $B.c=2^{B.inh}$                                              |

## 4.12

### (a)

$S'\rightarrow \{S.deep=0;\}S$​

$S\rightarrow (\{L.deep=S.deep+1;\}L)$​

$S\rightarrow a\quad \{print(S.deep);\}$​​​

$L\rightarrow \{L_1.deep=L.deep;\}L_1,\{S.deep=L.deep;\}S$​

$L\rightarrow \{S.deep=L.deep;\}S$​

### (b)

num：继承属性，本次推导后该文法符号前有几个字符

no：综合属性，该文法符号推出的序列的最后一个字符是第几个字符

$S'\rightarrow \{S.num=0;\}S$​

$S\rightarrow (\{L.num=S.num+1;\}L\{S.no=L.no+1;\})$​

$S\rightarrow a\{S.no=S.num+1;print(S.no);\}$​

$L\rightarrow \{L_1.num=L.num;\}L_1,\{S.num=L_1.no+1;\}S\{L.no=S.no;\}$

$L\rightarrow \{S.num=L.num;\}S\{L.no=S.no;\}$

## 4.14

### (b)

用继承属性deep表示嵌套深度

$P\rightarrow \{D.deep=1;\}D$

$D\rightarrow \{D_1.deep=D.deep;\}D_1;\{D_2.deep=D.deep;\}D_2$

$D\rightarrow id:T\{print(id.name, D.deep);\}$

$D\rightarrow proc\text{ }id;\{D_1.deep=D.deep+1;\}D_1;S$

## 4.15

| $E\rightarrow E_1+T$ | $stack[top-2].val=mknode('+',stack[top-2].val,stack[top].val)$ , $top=top-2$​ |
| -------------------- | ------------------------------------------------------------ |
| $E\rightarrow E_1-T$​ | $stack[top-2].val=mknode('-',stack[top-2].val,stack[top].val)$​ , $top=top-2$​ |
| $E\rightarrow T$     |                                                              |
| $T\rightarrow(E)$    | $stack[top-2].val=stack[top-1].val$ , $top=top-2$            |
| $T\rightarrow id$    | $stack[top].val=mkleaf(id, stack[top].val)$                  |
| $T\rightarrow num$   | $stack[top].val=mkleaf(num, stack[top].val)$                 |

