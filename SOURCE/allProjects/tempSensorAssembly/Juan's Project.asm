$NOMOD51
$NOSYMBOLS
;*****************************************************************************
;  Fall 2012 Project
;
;  FILE NAME   :  Project.ASM 
;  DATE        :  10/28/2012
;  TARGET MCU  :  C8051F340
;  DESCRIPTION :  Starter Code to measure the external temperature using the 
;                 LM35DZ temperature sensor connected to P1.1 of the
;                 C851F340.  It initializes the cross bar, I/O and ADC0.
;                 The ACALL to Measure_Temp returns a 10-bit right justified
;                 value in the DPTR representing the external temperature in Degree Celcius. 
;                 The internal Voltage Reference is utilized so that the temperature 
;                 can be determined from the following equation:
;
;                 Degree C= ((DPTR(base 10) * (2.44V/1024))/10mV/c) 
;
;                 Not all 1024 values are required so a small table can be
;                 used with an offset to determine values from 0 to 99 degrees F.
;                 Use a lookup table as it is far easier than trying to 
;                 implement the formula in code, convert to degrees F and then
;                 convert to LCD format encoding.
;
;
;  
;*****************************************************************************
$NOLIST                               ; stops listing of the include file
$INCLUDE (C8051F340.inc)
$LIST                                 ; restarts listing
;*****************************************************************************
; EQUATES TABLE
;*****************************************************************************


ENABLE           EQU  P1.4            ; Enable signal to LCD
RW               EQU  P1.2             ;R/W signal to LCD.
RS               EQU  P1.3            ; RS signal to LCD
LCD              EQU  P0              ; Output port to LCD.

keyport          equ P2               ; Keypad port connected here
row1             equ P2.0             ; Row 1 (pin 8)
row2             equ P2.1             ; Row 2 (pin 1) 
row3             equ P2.2             ; Row 3 (pin 2)
row4             equ P2.3             ; Row 4 (pin 4)

col1             equ P2.4             ; Column 1 (pin 3)
col2             equ P2.5             ; Column 2 (pin 5)
col3             equ P2.6             ; Column 3 (pin 6)
col4             equ P2.7             ; Column 4 (pin 7)

Green            equ P1.7             ; GREEN LED output.

Ambient          equ 40H              ; AMBIENT temp RAM address.
                                      
;*****************************************************************************
; RESET AND INTERRUPT VECTOR TABLE
;*****************************************************************************

            ORG  0000H                ; code starts at the reset vector address
              LJMP Main

;*****************************************************************************
; MAIN PROGRAM CODE
;*****************************************************************************

            ORG  0030H                 ; Main starts above the vector addresses
Main:       ANL  PCA0MD, #0BFH         ; disables watchdog timer
						MOV  OSCICN,#83H
            MOV  P1MDIN, #0DDH         ; P1.1 and P1.5 set to Analog I/O
            MOV  P1MDOUT, #0DDH        ; P1.1 & P1.5 Open-Drain; The rest are Push-Pull
            MOV  P1SKIP, #22H          ; Skips I/O P1.1 and P1.5 in crossbar
            mov  P0MDOUT, #0FFh        ; Makes all P0 push-pull outputs.
            mov  XBR1, #40h            ; Configures cross-bar for outputs.					  

						CALL Init				


            MOV   RSTSRC, #04H        ; Missing clock detector is enabled
            ACALL ADC0_Init           ; calls the ADC initalization routine
            SETB  AD0EN               ; enables AD0


						mov 30h,#01h
						mov 31h,#02h
						MOV 32H,#03H					
						mov 33H,#04H
						MOV 34H,#05H
						MOV 35H,#06H
						MOV 36H, #07H

						MOV 20H   ,#00H
						
						MOV 21H,#00H
						
						MOV 22H,#00H
					
						MOV 23H,#00H
						
						MOV 24H,#00H
						
						MOV 25H,#00H
						
						MOV 26H,#00H

						MOV 27H,#00H
						MOV R6,#01H
						MOV R7,#01H
						CLR 00H
						CLR 01H
						MOV 20H,#00H
						MOV R5,#01H
					  MOV R1, #20H                     
						MOV R4, #20H;                 INITIAL MEMORY ADDRESS TO STORE KEY ENTRY
						MOV R7,#03H


						jmp start


;******************************************************************************************************************



;********************************************************			

start:       JB F1, CONT 
				
		;*******************************************		
				CALL clear
				MOV DPTR, #00H
				ACALL Measure_Temp        ; Returns the temperature in the DPTR.  Now DPTR has the 10-bit right justified value for temperature.	
         	;	MOV DPTR, #79H		
					 JMP NH
   
EXTRA:	   MOV A,00H	;        IN USE W/WS FROM F3      	
				   MOV B,#64
				   DIV AB
			     MOV B,#29
			   	 MUL AB
				   ADD A, #49				 
				   JMP COMM

NH:				 MOV B,#0F4H;    244
					 MOV A,DPL;                  ???????
					 MUL AB;  mult  x 244
					 MOV A,B
					 RR A
					 RR A									 
					 ANL A,#3FH						 					      
					 mov B, #09h;     i have in A   temp in celsius		
					 MUL AB;                   temp  X9
					 XCH A,B
					 JZ MANOR            ; IF # USE JUST DPLOW GO TO MANOR
					 
           XCH A,B               ; DP hight has a value
					 DJNZ B,EXTRA       ; CHECKING IF B > 1 IF          
					 JMP M
MANOR:		 mov A,B;   
           ADD A,#3			
           MOV B,#5
					 DIV AB
					 ADD A,#20H
					 jmp MENOS2

M:         MOV B,#5H               ; WORKS W/ #s from 7D TO EF
					 DIV AB
					 ADD A,#55H
COMM:      MOV B,#100
           DIV AB					
					 JZ MENOS
					 
          					
					 ADD A,#30h
				   CALL clear
					 CALL display

MENOS:     MOV A,B  
					 		
MENOS2:		 MOV B,#10
					 DIV AB
					 add A,#30H 
					 				
					 CALL display

EX:			   MOV A,B					
				   ADD A,#30H
					 CALL display



           CALL clear

				
				
		;******************************************************************		
					

 CONT:           
 						     MOV R0, #0           ; clear R0 - the first key is key0

; scan row1
                 SETB row4            ; set row4
                 CLR row1             ; clear row1
                 CALL colScan         ; call column-scan subroutine
                 JB F0, finish        ; | if F0 is set, jump to end of program 
                                      ; | (because the pressed key was found
                                      ; | and its number is in R0)

; scan row2
                 SETB row1            ; set row1
                 CLR row2             ; clear row2
                 CALL colScan         ; call column-scan subroutine
                 JB F0, finish        ; | if F0 is set, jump to end of program 
                                      ; | (because the pressed key was found
                                      ; | and its number is in R0)

; scan row3
                 SETB row2            ; set row2
                 CLR row3             ; clear row3
                 CALL colScan         ; call column-scan subroutine
                 JB F0, finish        ; | if F0 is set, jump to end of program 
                                      ; | (because the pressed key was found
                                      ; | and its number is in R0)

; scan row4
                 SETB row3            ; set row3
                 CLR row4             ; clear row4
                 CALL colScan         ; call column-scan subroutine
                 JB F0, finish        ; | if F0 is set, jump to end of program 
                                      ; | (because the pressed key was found
                                      ; | and its number is in R0)

                 JMP start            ; | go back to scan row 1
                                      ; | (this is why row4 is set at the
                                      ; | start of the program - when the
                                      ; | program jumps back to start, row4
                                      ; | has just been scanned)

finish:         


TWO:	           MOV DPTR, #Table1    ; Initialize Data Pointer
							   mov A, R0			
                 MOVC A, @A + DPTR
					
							   MOV @R1, A
								inc R1
							;	CJNE R1,#27H,NEXT
								;JMP COMP
NEXT:					 ; MOV A,#2AH
							


start2:        	cjne R2, #16, next35
								mov R2,#0
							  mov R3, #0
								call clear


next35:         CALL display
                CLR F0               ; clear flag
								CJNE R1,#27H,NEXT
								JMP COMP

						
               JMP start            ; Continue looking for next key



COMP:		       JMP $					
								





;*****************************************************************************
;*****************************************************************************


colScan:         JB col1, nextcol     ; check if col1 key is pressed
                 JNB col1, $          ; If yes, then wait for key release
                 JMP gotkey           ; Have key, return
nextcol:         INC R0               ; Increment keyvalue
                 JB col2, nextcol2    ; check if col2 key is pressed
                 JNB col2, $          ; If yes, then wait for key release
                 JMP gotkey           ; Have key, return
nextcol2:        INC R0               ; Increment keyvalue
                 JB col3, nextcol3    ; check if col3 key is pressed
                 JNB col3, $          ; If yes, then wait for key release
                 JMP gotkey           ; Have key, return
nextcol3:        INC R0               ; Increment keyvalue
                 JB col4, nokey       ; check if col4 key is pressed
                 JNB col4, $          ; If yes, then wait for key release
                 JMP gotkey           ; Have key, return
nokey:           INC R0               ; Increment keyvalue
                 RET                  ; finished scan, no key pressed

gotKey:          SETB F0              ; key found - set F0
                 SETB 00H              ; DO NOT GET TEMP
								 SETB F1              ; this flag used to stop showing temperature
								 RET                  ; and return from subroutine


;*****************************************************************************

;********************************************************************************					
					;this is my personal delay
					mov R5,#5				
dem:      mov   R4,#15
myDelay:  mov   R6, #00h
myLoop:   mov   R5, #00h
          djnz  R5, $
          djnz  R6, myLoop
	      	djnz  R4,myDelay					
									
          ret

;*******************************************************************************************

;***************************************************************************** 

init:            CLR RS               ; Register Select ( 0 = Command )
                 CLR RW               ; Read/Write ( 1 = Read ; 0 = Write )
                 clr ENABLE           ; High to Low Transition Stores the data
                 call delay           ; Waits for LCD to stabilize
                 call reset           ; Sends reset bytes to LCD
								                      ; E X R R D D D D D D D D   
                                      ; | | S W 7 6 5 4 3 2 1 0 
                                      ; | | | | | | | | | | | |
                 mov LCD, #38H        ; 1 0 0 0 0 0 1 1 1 0 0 0 Function Set Word 
                                      ;
                 call Busy            ; Check Busy Flag
                 setb ENABLE          ; Latched the first byte.
                 call delay           ; Waits.
                 clr ENABLE           ; Then resets latch.
                 call busy            ; Check Busy Flag
                                      ; E X R R D D D D D D D D   
                                      ; | | S W 7 6 5 4 3 2 1 0 
                                      ; | | | | | | | | | | | |
                 mov LCD, #08H        ; 1 0 0 0 0 0 0 0 1 0 0 0 Display Off word
                 call Busy            ; Check Busy Flag
                 setb ENABLE          ; Latched the first byte.
                 call delay           ; Waits.
                 clr ENABLE           ; Then resets latch.
                 call Busy            ; Check Busy Flag
                                      ; E X R R D D D D D D D D   
                                      ; | | S W 7 6 5 4 3 2 1 0 
                                      ; | | | | | | | | | | | |
                 mov LCD, #0FH        ; 1 0 0 0 0 0 0 0 1 1 1 1 Display On word.
                 call Busy            ; Check Busy Flag
                 setb ENABLE          ; Latched the first byte.
                 call delay           ; Waits.
                 clr ENABLE           ; Then resets latch
                 call Busy            ; Check Busy Flag
                                      ; E X R R D D D D D D D D   
                                      ; | | S W 7 6 5 4 3 2 1 0 
                                      ; | | | | | | | | | | | |
                 mov LCD, #06H        ; 1 0 0 0 0 0 0 0 0 1 1 0 Entry Mode word
                 call Busy            ; Check Busy Flag
                 setb ENABLE          ; Latched the first byte.
                 call delay           ; Waits.
                 clr ENABLE           ; Then resets latch.
                 call Busy            ; Check Busy Flag
                                      ; E X R R D D D D D D D D   
                                      ; | | S W 7 6 5 4 3 2 1 0 
                                      ; | | | | | | | | | | | |
                 mov LCD, #02H        ; 1 0 0 0 0 0 0 0 0 0 1 0 Display Home word
                 call Busy            ; Check Busy Flag
                 setb ENABLE          ; Latched the first byte.
                 call delay           ; Waits.
                 clr ENABLE           ; Then resets latch.
                 call Busy            ; Check Busy Flag
                 ret

;*****************************************************************************
;*****************************************************************************
 

clear:                                ; E X R R D D D D D D D D   
                                      ; | | S W 7 6 5 4 3 2 1 0 
                                      ; | | | | | | | | | | | | 
                 mov LCD, #01H        ; 1 0 0 0 0 0 0 0 0 0 0 1 Clear Display word
                 call Busy            ; Check Busy Flag
                 setb ENABLE           ; Latched the first byte.
                 call delay           ; Waits.
                 clr ENABLE          ; Then resets latch
                 ret

;*****************************************************************************
;*****************************************************************************


display:                              ; The data to be sent is in A.
                 setb RS              ; Register Select ( 1 = Data )                     
                 mov LCD, A           ; Sends data to LCD
                 setb ENABLE          ; Latches the data.
                 call delay           ; Waits.
                 clr ENABLE           ; Then resets the latch.
                 inc R2
                 inc R3               ; R3 is used to keep track of LCD DDRAM.
                                      ; After an ASCII char is sent, R3 is
                                      ;  incremented.
                 cjne R3, #8, next2   ; If R3=8 then the second line is used. 
                 call secondline     
next2:           cjne R3, #16, next3  ; If R3=16 then the LCD will need to
                
								                    
                 mov R3, #0           ;  R3 is cleared.
                 call clear           ; This clears the LCD and resets the
                                      ;  DDRAM to 0.
next3:           ret

;*****************************************************************************
;*****************************************************************************
 

secondline:      push ACC             ; Saves ACC to stack.
                 push DPH             ; Saves
                 push DPL             ;       DPTR to stack.
                 clr RS
                 mov LCD, #0C0H        ; Moves Second Line word
                 setb ENABLE           ; Latched the first byte.
                 call delay           ; Waits.
                 clr ENABLE          ; Then resets latch.
                 call Delay
                 setb RS 
                 pop DPL              ; Restores
                 pop DPH              ;          DPTR.
                 pop ACC              ; Restores ACC.
                 ret
;*****************************************************************************


delay:           mov   R6, #00h
Loop0:           mov   R5, #00h
                 djnz  R5, $
                 djnz  R6, Loop0
                 ret



reset:           call delay
                 mov LCD, #30H        ; Writes Function Set.
                 setb ENABLE          ; Latches Instruction.
                 call delay           ; Waits.
                 clr ENABLE           ; Then resets latch.
                 call Busy            ; Check Busy Flag delay
                 mov LCD, #30H        ; Writes Function Set.
                 setb ENABLE          ; Latches Instruction.
                 call delay           ; Waits.
                 clr ENABLE           ; Then resets the latch.
                 call Busy            ; Check Busy Flagdelay
                 mov LCD, #30H        ; Writes Function Set.
                 setb ENABLE          ; Latches Instruction
                 call delay           ; Waits
                 clr Enable           ; Then resets the latch
                 call Busy            ; Check Busy Flag
                 ret 

;****************************************************************************
Busy:            clr RS
                 setb RW
                 jb P0.7, $
                 clr RW
                 ret
;
;*****************************************************************************




ADC0_Init:  MOV ADC0CN, #80H          ; conversion initiated on every
                                      ; write of "1" to AD0BUSY
            MOV AMX0P, #1EH           ; select Positive input on P1.1      VALUE = #13 FOR EXT TEMP  VALUE = #1E FOR INT
            MOV AMX0N, #1FH           ; select ground (single-ended mode)
            MOV ADC0CF, #00001000B    ; 00001000B
                                       ;    1>sets ADC conversioin clock (750kHz)
                                       ;     0> ADC0H:ADC0L is right justified
;					
            MOV REF0CN, #00000011B    ;	      00000011B
                                        ;         0>    Vref used as voltage ref
                                        ;          0>   internal temp sensor off
                                        ;           1>  internal bias gen on
                                        ;            1> internal reference buffer enabled
            ANL EIE1, #0F7H           ;	disable ADC0 conversion
                                      ; complete interrupt
            RET     

;*****************************************************************************


Measure_Temp:
            
            CLR AD0INT              ; clears conversion completion flag
            SETB AD0BUSY            ; initiates AD0 conversion
            JNB AD0INT,$            ; waits for conversion to complete
            MOV DPL,ADC0L           ; stores temperature (word) in
            MOV DPH,ADC0H           ;  DPTR
            RET

;*****************************************************************************
; CONSTANTS
;*****************************************************************************


Table:          DB  '*','*','*','*','*','*','*'

Table2:          DB  '*','*','*','*','*','*','*'
Table1:          DB  '1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'

;*****************************************************************************

; End of file.

END