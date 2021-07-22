	AREA RESET,CODE,READONLY
ENTRY
	GBLA flag
flag SETA 1
	MOV R0, #0
	WHILE flag<101
		MOV R1, #flag
		ADD R0, R1
flag SETA flag+1
	WEND
END