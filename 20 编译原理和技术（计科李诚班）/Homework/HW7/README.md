# 第七次作业

## 7.8

上次做过了

## 习题2

Global Symtab

| i     | var  | int  |
| ----- | ---- | ---- |
| j     | var  | int  |
| h     | var  | real |
| $P_1$ | PROC |      |
| $P_2$ | PROC |      |

PROC $P_1$ Symtab

| temp | var  | real |
| ---- | ---- | ---- |
| max  | var  | int  |

PROC $P_2$ Symtab

| k     | var  | real |
| ----- | ---- | ---- |
| f     | var  | real |
| $P_3$ | PROC |      |

PROC $P_3$ Symtab

| l    | var  | int  |
| ---- | ---- | ---- |

## 习题3

| 产生式                               | 翻译方案                                                     |
| ------------------------------------ | ------------------------------------------------------------ |
| $T\rightarrow \text{record L D end}$ | $T.type=record(top(tblptr));$​​​​<br />$T.width=top(offset);$​​​​<br />$pop(tblptr);$​​​<br />$pop(offset);$​​​ |
| $L\rightarrow \epsilon$              | $t=mkTable(nil);$<br />$push(t,tblptr);$<br />$push(0,offset);$ |
| $D\rightarrow D_1;D_2$               |                                                              |
| $D\rightarrow id:T$                  | $offset=T.type==\text{"char" ? offset : offset + 4  - offset \% 4;}$​​​​<br />$\text{enter(id.lexeme, T.type, offset);}$​<br />$\text{offset = offset + T.width;}$​​​​​​ |
| $T\rightarrow integer$               | $\text{T.type = "integer"}$​<br />$\text{T.width = 4}$​        |
| $T\rightarrow real$                  | $\text{T.type = "real"}$​​<br />$\text{T.width = 8}$​​           |
| $T\rightarrow long$                  | $\text{T.type = "long"}$​​<br />$\text{T.width = 8}$​​           |
| $T\rightarrow char$                  | $\text{T.type = "char"}$​<br />$\text{T.width = 1}$​           |

