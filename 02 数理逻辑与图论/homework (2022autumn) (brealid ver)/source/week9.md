---
课堂: 210037.01 数理逻辑与图论(刘斌)  
姓名: 赵奕  
学号: PB21000033  
id: 9

---
## 6.5节
### 9
不能，新增这两条边没有改变 $A$ 的度，因此 $A$ 的度仍为 $5$，为奇数。

### 23
没有欧拉回路或欧拉通路，因为有多个度为奇数的顶点。

### 45
尝试链接哈密顿回路，$m$ 个顶点侧的顶点需要与两个 $n$ 侧顶点配对作为前驱和后继，而每个顶点同时可以且必须作为前驱和后继连入通路，可知 $m$ 个顶点需要 $m$ 个前驱和 $m$ 个后继，能作为 $m$ 个前驱和 $m$ 个后继，因此有 $m=n$. 注意到 $m=n=1$ 时无法连成回路，故 $m=n\geq 2$.

### 47
- a) i:否 ii:否 iii:是
- b) i:否 ii:否 iii:是
- c) i:是 ii:是 iii:是
- d) i:是 ii:是 iii:是
- 
### 67
假设含有哈密顿回路。
 
1. 该回路中不含$ch$，则含$hi$, $hj$, $cb$, $cd$. 若含$ai$, $ab$ 则无法包括全部；若含$ai$, $bf$, 则一定含$aj$, 无法包括全部；若含$bf$, $ie$, 则一定含$cf$, 无法包括$n$. 综上，不可能不包含$ch$，情况不成立。
 
2. 该回路中含$ch$，则由对称性含$ci$, $bf$. 若含$hi$, $bc$不含$ef$, 则无法包含$a$, 对$hi$, $bc$, $ef$包含两个的情况相同；若仅含$hi$, 则含$gf$, $de$, $cd$, $ab$, 无法连成单个回路；若$hi$, $bc$, $ef$都不包含，则无法包含$jkl$. 因此情况亦不成立。
 
 综上所述，假设恒不成立，因此不存在哈密顿回路。


## 6.6节
### 3
$a-c-d-e-g-z$  
$3+3+1+5+4=16$

### 27
洛杉矶 - 旧金山 - 丹佛 - 底特律 - 纽约

### 31
记该给走的有向非循环图拓扑排序为 $v_1,v_2,\dots,v_n$, $w_{i,j}$ 为 $v_i-v_j$ 的权值，$dp_i$ 为以 $i$ 为结束点的最长路径，在 $dp_i$ 中 $v_i$ 的上一个节点记作 $L_i$  
因为 $dp_i=\max\{dp_{L_i}+w_{L_i,v_i}\}$  
循环 $i$ 从 $1$ 到 $n$，$j$ 从 1 到 $i-1$，便 $dp_i$ 取到 $dp_i,w_{j,i}$ 最大（$i=1$ 时 $dp_i = 0$）

