---
课堂: 210037.01 数理逻辑与图论(刘斌)  
姓名: 赵奕  
学号: PB21000033  
id: 6

---
## 5.3
### 15
- a) $M_{R^2}=M_R^{[2]}=\left[\begin{matrix}0&0&1\\1&1&0\\0&1&1\end{matrix}\right]$
- b) $M_{R^3}=M_R^{[2]}\odot M_R=\left[\begin{matrix}1&1&0\\0&1&1\\1&1&1\end{matrix}\right]$
- b) $M_{R^4}=M_R^{[3]}\odot M_R=\left[\begin{matrix}0&1&1\\1&1&1\\1&1&1\end{matrix}\right]$

### 31
23. 反自反的
24. 自反的 反对称的 传递的
25. 反自反的 反对称的

## 5.4
### 13
$R\cup R^{-1}$ 为 $R$ 的对称闭包

### 23
$M_{(R\cup R^{-1})}=M_R\lor M_{R^{-1}}=M_R\lor M_{R}^{T}$

### 29
- a) $\{(1,1),(1,2),(1,4),(2,2),(3,3),(4,1),(4,2),(4,4)\}$
- b) $\{(1,2),(1,4),(3,3),(4,1),(2,1),(4,2),(2,4),(1,1),(4,4),(2,2)\}$
- c) $\{(1,2),(1,4),(3,3),(4,1),(2,1),(4,2),(2,4),(1,1),(4,4),(2,2)\}$

## 5.5
### 7
p 和 p 具有相同的真值，故逻辑等价关系具有自反性  
p 与 q 若逻辑等价，则 p 与 q 逻辑等价，即具有对称性  
p 与 q 逻辑等价，q 与 r 逻辑等价，则 p 与 r 逻辑等价，具有传递性  
T 的等价类为所有永真式构成的集合  
F 的等价类为所有矛盾式构成的集合

### 21
不是，不符合传递性

### 47
- a) {(0,0),(1,2),(2,1),(1,1),(2,2,),(3,3),(4,4),(5,5),(3,4),(3,5),(4,3),(4,5),(5,3),(5,4)}
- b) {(0,0),(0,1),(1,0),(1,1),(2,2),(3,3),(2,3),(3,2),(4,4),(4,5),(5,4),(5,5)}
- c) {(0,0),(1,2),(2,1),(0,1),(0,2),(1,1),(2,2),(1,0),(2,0),(3,3),(3,4),(3,5),(4,3),(4,4),(4,5)}
- d) {(0,0),(1,1),(2,2),(3,3),(4,4),(5,5)}

### 59
a) 
- 自反性 $(c_1,c_1)$ 在 $R$ 中，因为 $c_1$ 可以旋转 $360^\circ\cdot n$ 得到 $c_1$；  
- 对称性 当 $(c_1,c_2)\in R$ 时 $(c_2,c_1)\in R$：若 $c_1$ 经过某个特定次序的旋转和翻转能得到 $c_2$，可以颠倒次序将 $c_2$ 还原为 $c_1$
- 传递性 $(c_1,c_2),(c_2,c_3)\in R$ 时将 $c_1$ 经过变为 $c_2$ 的步骤，再将其变为 $c_3$，即 $(c_1,c_3)$ 也在 $R$ 中
  
### 63
是的，该闭包中的关系均满足自反性，对称性，传递性