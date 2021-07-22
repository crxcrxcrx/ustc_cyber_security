Stack_Size	EQU 0x0000010
	AREA STACK, READWRITE
__stack_limit
Stack_Mem SPACE Stack_Size
__initial_sp

	AREA RESET,CODE,READONLY 
Vectors DCD __initial_sp												 
ENTRY
	LDR R0,= Vectors
	LDR R1,[R0]
	MOV R2, #0x11
	PUSH {R2}
LOOP 
	B LOOP
END
