	AREA Buf,DATA,READWRITE;
Num1 DCD 0x11;
Nums DCD 0x22;
	AREA BUF,CODE,READONLY
	EXPORT TestAsm
ENTRY
TestAsm
	LDR R0,=Num1
	LDR R1,[R0]
	ADD R1,#0x9A
	STR R1,[R0]  
	LDR R0,=Nums  
	LDR R2,[R0]
	ADD R2,#0xAB
	STR R2,[R0] 
LOOP
	B LOOP
NOP
END
