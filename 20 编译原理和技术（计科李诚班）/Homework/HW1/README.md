# 第一次作业

薛佳龙 PB19061212 

## 2.3

### d

最开始由多个0，之后由多个10组成的字符串

### e

开始由多个00或11，之后由多个如下部分组成的字符串：

初始为01或10，之后为多个00或11，之后为一个01或10，之后为多个00或11

## 2.4

### c

other1→除了*以外的其它字符

other2→除了*和/以外的其它字符

answer→/(\*)(other)\*((\*)\*other1\*other2\*)\*(\*)\*\(\*)/

### d

number0→0

number1→(1|number0 1)(number0 1)*(number0|ε)||number0

number2→(2|number1 2)(number1 2)*(number1|ε)||number1

number3→(3|number2 3)(number2 3)*(number2|ε)||number2

number4→(4|number3 4)(number3 4)*(number3|ε)||number3

number5→(5|number4 5)(number4 5)*(number4|ε)||number4

number6→(6|number5 6)(number5 6)*(number5|ε)||number5

number7→(7|number6 7)(number6 7)*(number6|ε)||number6

number8→(8|number7 8)(number7 8)*(number7|ε)||number7

answer→(9|number8 9)(number8 9)*(number8|ε)||number8

### h

1*(0|10)*
