	AREA RESET,CODE,READONLY  
ENTRY                      
	MOV R0, #0x11
	MOV R1, #0xab
	ADD R0, R1
	LSL R1, #2
LOOP
	B LOOP
END
