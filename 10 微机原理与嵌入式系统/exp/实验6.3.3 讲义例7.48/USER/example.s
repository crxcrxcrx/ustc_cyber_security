	AREA example,CODE,READONLY
	EXPORT strcopy
strcopy
LOOP
	LDRB R2,[R1],#1
	STRB R2,[R0],#1
	CMP R2,#0 
	BNE LOOP
	MOV PC,LR
 END
