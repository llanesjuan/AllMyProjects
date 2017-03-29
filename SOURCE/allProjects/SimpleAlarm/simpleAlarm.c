/******* MS_Pot.c **************
*
* Use Fosc = 2 MHz for  Fcpu = 1 MHz.
* CPU never sleeps.
* Use Timer1 for a loop time of 10 ms.
* Blink LED on RB15 every two seconds.
* Display startup message on LCD.
* Display potentiometer output on LCD.
*******************************/

#include "p24HJ64GP502.h"

/*******************************
 * Configuration selections
 ******************************/
// FOSCSEL and FOSC default to FRC with divider and pin 10 = Fcpu
_FWDT(FWDTEN_OFF);               // Turn off watchdog timer
_FICD(JTAGEN_OFF & ICS_PGD1);    // JTAG is disabled; ICD on PGC1, PGD1

/*******************************
 * Global variables
 ******************************/
unsigned int DELAY;             // Counter for obtaining a delay
unsigned char ALIVECNT;         // Counter for BlinkAlive
unsigned int TEMP;              // Temporary variable
unsigned int BIGNUM;            // Parameter used by ASCII4

unsigned int codeP;          
unsigned int out; 
unsigned int timeLed; 
unsigned int transl;
unsigned int alarmOff;
unsigned int  lightA;
unsigned char LETTER;
unsigned char LETTERA;
unsigned int luz;
unsigned int mode;
unsigned int time20;
unsigned int timeLeft;
unsigned int lightOn;
unsigned int timeFin;
unsigned int time22;
unsigned int ini;
unsigned int ledB;
unsigned checkPass;
unsigned top;
unsigned bott;
unsigned track;
unsigned int aut;
unsigned int alar;

/*******************************
 * Strings
 ******************************/
//const char LCDstr[] = {063, 062, 050, 001, 014, 006, 000};  

const char LCDstr[] = {0x33,0x32,0x28,0x01,0x0C,0x06,0x00};
				// LCD controller initialization string

const char StrtStr[] = "\200Good Morning";
char PotStr[] = "\3060000";     // String to display pot output

const char TeamStrA[] = "\200   0000 00 00 0";
const char TeamStrB[]  ="\200   0001 01 01 1";
const char TeamStrC[] = "\200   0010 02 02 2";
const char TeamStrD[] = "\200   0011 03 03 3";
const char TeamStrE[] = "\200   0100 04 04 4";
const char TeamStrF[] = "\200   0101 05 05 5";
const char TeamStrG[] = "\200   0110 06 06 6";
const char TeamStrH[] = "\200   0111 07 07 7";
const char TeamStrI[] = "\200   1000 10 08 8";
const char TeamStrJ[]  ="\200   1001 11 09 9";
const char TeamStrK[] = "\200   1010 12 10 A";
const char TeamStrL[] = "\200   1011 13 11 B";
const char TeamStrM[] = "\200   1100 14 12 C";
const char TeamStrN[] = "\200   1101 15 13 D";
const char TeamStrO[] = "\200   1110 16 14 E";
const char TeamStrP[] = "\200   1111 17 15 F";
const char TeamStrLON[] = "\300 Alarm is ON                ";
const char TeamStrLOFF[] = "\300 Password Please            ";
const char TeamStrW[] = "\200        WARNING                     ";
const char TeamStrInt2[] = "\200int                      ";
const char TeamStrInt[] = "\200intruder inside";
const char TeamStrInt22[] = "\300Police is coming for you";
const char TeamStrTest4[] = "\200                                ";
const char TeamStr0[] = "\20010";
const char TeamStr1[] = "\200 9";
const char TeamStr2[] = "\200 8";
const char TeamStr3[] = "\200 7";
const char TeamStr4[] = "\200 6";
const char TeamStr5[] = "\200 5";
const char TeamStr6[] = "\200 4";
const char TeamStr7[] = "\200 3";
const char TeamStr8[] = "\200 2";
const char TeamStr9[] = "\200 1";
const char TeamStr10[] = "\200 0";
const char TeamStrECET[] = "\200     ECET-2000     ";
const char TeamStrECET2[] = "\300         THANKS            ";
const char TeamStrBlank[] = "200                              ";
const char TeamStrBlank2[] = "300                              ";
const char TeamStrtest[] = "\200 testtttttttttttttttttttttttttt";
/*******************************
 * Function prototypes
 ******************************/
void Initial(void);
void BlinkAlive(void);
void LoopTime(void);
void InitLCD(void);
void Display(char DispStr[]);
void ReadPot(void);
void DisplayPot(void);
void ASCII4(char DispStr[]);
void BlinkLetter(void);
void light(int luz);
void alarm(void);
void waiting(void);
 /*******************************
 * Macros
 ******************************/
#define Delay(x) DELAY = x; while(--DELAY){ Nop(); Nop(); Nop();}

//////// Main program //////////////////////////////////////////

int main()
{
   Initial();                    // Initialize everything
   while (1)
   {   
      BlinkAlive();              // Blink LED1 for 16 ms every 4 seconds
      	
     
      alarm(); 

      BlinkLetter();               // Wait, while awake, on Timer1
      waiting();
	  LoopTime(); 
   }
}

/*******************************
 * Initial
 *
 * This function performs all initializations of variables and registers.
 ******************************/
void Initial()
{
   OSCCON = 0x0701;              // Use fast RCoscillator with Divide by 16
   CLKDIV = 0x0200;              // Divide by 4
   OSCTUN = 17;                  // Tune for Fcpu = 1 MHz
   AD1PCFGL = 0xFFFE;            // AN0 analog; other pins digital
   TRISB = 0x00CF;
   PORTB = 0x7CC0;
   TRISA = 0x01;
   PORTA = 0x00;
   TMR1 = 0;                     // Initialize Timer1 to zero
   PR1 = 10000 - 1;              // LoopTime = 10 ms
   T1CON = 0x8000;               // Count CPU clock cycles
   ALIVECNT = 197;               // Blink immediately
   InitLCD();                    // Initialize LCD
  _TRISB6 = 1; //next four switch for in  signal to convert
  _TRISB7 = 1;  
  _TRISB8 = 1;
  _TRISB9 = 1;
  _TRISB2 = 1;//mode from switch or automatic transl
  _TRISB3 = 1;//ok for password
  _TRISB4 = 0;//output to the led	
  _TRISB5 = 1;//signal from light
  _CN6PUE = 1;
  _CN7PUE = 1;
  _CN22PUE = 1;
  _CN23PUE = 1;
  _CN24PUE = 1;
  _CN21PUE = 1;
  codeP = 0x000F; 
  mode=1;
  luz = 0;
  timeLed = 0; 
  out = 0;
  timeLeft = 0;
  time22 = 0;
  transl=0;;
  alarmOff=0;
  lightA=0;
  LETTER=0;
  LETTERA=0;
  luz=0;
  mode=0;
  time20=0;
  lightOn=0;
  timeFin=0;
  ini=0;
  checkPass = 0;
 Display((char *) StrtStr);    // Display initial messa
 alar = 0;
}
/*******************************
 * BlinkAlive
 *
 * This function briefly blinks the Microstick's user LED every two seconds.
 * With a looptime of 10 ms, count 200 looptimes
 ******************************/
void BlinkAlive()
{
   _RB15 = 0;                    // Turn off
   if (++ALIVECNT >= 200)        // Increment counter and return if not 200
   {
      ALIVECNT = 0;              // Reset ALIVECNT
      _RB15 = 1;                 // Turn on LED for 10 ms every 2 secs
   }
}

/*******************************
 * LoopTime
 *
 * This function waits for Timer1 to roll over after 10000 counts.
 **************************8***/
void LoopTime()
{
   while (!_T1IF) ;
   _T1IF = 0;
}

/*******************************
 * InitLCD()
 *
 * Initialize the LCD for a four-bit interface, a two-line display. Then clear
 * display, turn off cursor, turn on display and increment cursor automatically.
 ******************************/
void InitLCD()
{
    static unsigned int i;
    Delay(5000);			// Delay 50 ms for LCD controller to power up
    _RB11 = 0;				// RS=0 for command
    while (LCDstr[i])		// Send char if the byte is not zero
    {
        _RB10 = 1;			// Drive E pin high
        PORTB = (((LCDstr[i] & 0xF0) << 8)|(PORTB & 0x0FFF)); // Send upper nibble
        _RB10 = 0;			// and low so LCD will accept nibble
        Delay(200);			// Wait for 2 ms
        _RB10 = 1;
        PORTB = (((LCDstr[i] & 0x0F) << 12)|(PORTB & 0x0FFF)); // Send lower nibble
        _RB10 = 0;			// and low so LCD will accept nibble
        Delay(200);			// Wait for 2 ms
        i++;				// Increment pointer to next character
    }
    PORTB &= 0x03FF;		// Drive all LCD pins low
}

/*******************************
 * Display()
 *
 * This subroutine is called using the name of a display string as an inline parameter. 
 * The format of the string is:
 *      Cursor-position code (CPC)
 *      Displayable characters
 *      A null character (0x00) to terminate the string
 * The cursor-position code identifies the location to be used by the
 * first displayable character.
 * For the top row of the 24x2 LCD, the CPC's are 0x80, 0x81,..., 0x97
 * For the second row of the 24x2 LCD, the CPC's are 0xC0, 0xC1,..., 0D7
 ******************************/
void Display(char DispStr[])
{
   static unsigned int i;
   i = 0;	
   _RB11 = 0;          		// RS=0 for command (CPC)
   while (DispStr[i])        	// Send char if the byte is not zero
   {
      _RB10 = 1;       		// Drive E pin high
      PORTB = (((DispStr[i] & 0xF0) << 8)|(PORTB & 0x0FFF)); // Send upper nibble
      _RB10 = 0;       		// Drive E pin low to trigger LCD read of nibble
      _RB10 = 1;       		// Drive E pin high
      PORTB = (((DispStr[i] & 0x0F) << 12)|(PORTB & 0x0FFF)); // Send lower nibble
      _RB10 = 0;       		// Drive E pin low to trigger LCD read of nibble
      Delay(1); 		// Wait 10 us for LCD to handle byte
      _RB11 = 1;       		// Drive RS pin high for displayable characters
      i++;                 	// Increment pointer to next character
   }
   PORTB &= 0x03FF;		// Drive all LCD pins low
}

/**************************************/
void BlinkLetter()
 { 	
			if (alarmOff == 0)
			{ //Display((char *) TeamStrtest);
				 if (++LETTER >= 100)        // Increment counter and return if not 200
				{	 alar = 1;
					LETTER = 0;

				if (_RB2 == 1)   //RB2 SWITCH TO SELECT BETWEEN WHOLE CODE OR JUST USING SWITCHES
					{				    	
							light(luz);//CALLING FUNCTION TO DISPLY LETTERS
							luz ++;
							if(luz == 16)
							luz = 0;
					}
				
					else
					{
						transl = (PORTB >> 6);//GETTING THE CODE WISHED FROM SWITCHES
						transl = (transl & 0x000F);
						light(transl);//CALLING FUNCTION TO DISPLAY WITH CODE FROM SWITCHES	    						
					}		
				}			
			} 		   
}	
/**********************************************/
void light(int luce)
{						
	switch (luce)
			{
		    case 0 : Display((char *) TeamStrA);
		          break;							
		     case 1 :Display((char *) TeamStrB);
		     break;					
			case 2 : Display((char *) TeamStrC);
		     break;			
			case 3 :  Display((char *) TeamStrD);
		     break;			
			case 4 :  Display((char *) TeamStrE);
		     break;
			case 5 :  Display((char *) TeamStrF);
			 break;				
			case 6 :  Display((char *) TeamStrG);
			break;			
			case 7 :  Display((char *) TeamStrH);
	        break;			
			case 8 :  Display((char *) TeamStrI);
     	    break;
			case 9 :  Display((char *) TeamStrJ);
    	     break;			
			case 10 :  Display((char *) TeamStrK);
		    break;			
			case 11 :  Display((char *) TeamStrL);
		    break;			
			case 12 :  Display((char *) TeamStrM);
		    break;			
			case 13 :  Display((char *) TeamStrN);
		    break;			
			case 14 :  Display((char *) TeamStrO);
	        break;			
			case 15 :  Display((char *) TeamStrP);
		    break;			
			}       
}
/************************************************/
void alarm()
{
		if (alarmOff == 0)//IF NOTHING CROSSED THE LIGHT
		 {if (alar == 1){
		    if (++lightA >= 0)//GETTING INFO FROM THE LIGHT SENSOR EVERY 1/200 SEC
		
			{
			  
		      if  (_RB5 == 1) 
				{  
					Display((char *) TeamStrLON);//DISPLAY THAT EVERY THING IS OK WITH ALARM (NOTHING CROSSING)
		            lightA = 0;//START A NEW CYCLE TO GET INFO FROM LIGHT SENSOR
					
		        }
				else
				{
					Display((char *) TeamStrLOFF);//ALARM TRIGUERED
		            Display((char *) TeamStrW);// DISPLAY EVENT ALARM GOING OFF warning
		            alarmOff = 1;// TO ACT IN ANY OTHER PART OF THE PROGRAM
				}
		    }  
		 }
}           
}
/**************************************************/

void waiting()// WAITING THE TIME TO PUT THE PASSWORD
{
	if ( alarmOff == 1)//if alarm is active
    { 	
      
		if (ledB == 0)
        {
			 if (lightOn == 1)
			{	
					_RB4 = 1;// LIGHTING THE LED FOR ALARM NOT CANCELLED
			}
			else
				_RB4 = 0;

			if (++timeFin >= 50)//this loop for Blinking the lED every .5 sec
			{
					timeFin = 0;
				{
					if (lightOn == 0)
					{				
						lightOn  = 1;
					}
					else
					{
						lightOn  = 0;				
					}			
				}
			}		
		}
     
   	   if (++timeLed >= 100)
		{
			timeLed = 0;
        


				switch (timeLeft)
			{
		    case 0 : Display((char *) TeamStr0);
		    break;							
		     case 1 :Display((char *) TeamStr1);
		     break;					
			case 2 : Display((char *) TeamStr2);
		     break;			
			case 3 :  Display((char *) TeamStr3);
		     break;			
			case 4 :  Display((char *) TeamStr4);
		     break;
			case 5 :  Display((char *) TeamStr5);
		     break;			
			case 6 :  Display((char *) TeamStr6);
		    break;			
			case 7 :  Display((char *) TeamStr7);
		    break;			
			case 8 :  Display((char *) TeamStr8);
		   break;
			case 9 :  Display((char *) TeamStr9);
					     break;
			
			case 10 :  Display((char *) TeamStr10);
					     break;
			
			}	
			timeLeft++;				
	
		}

		
	     if ((++time20 >= 1101) && (++time20 <= 1400)) //WAIT 10 SECONDS to go off alarm
          {
	           
		      // lightOn  = 0;
               Display((char *) TeamStrInt);//DISPLAYING THE MESSAGE FOR INTRUDER  
				Display((char *) TeamStrInt22);//police coming
				out = 1; //to kill the process out of time to put pasword
				ledB=1;
				_RB4 = 1;// LIGHTING THE LED FOR ALARM NOT CANCELLED 
	       }


		 if (++time22 >= 1401)
		{
			
				Display((char *) TeamStrECET);
				Display((char *) TeamStrECET2);
				lightOn  = 0;
		    	_RB4 = 0;
			//	time20 = 0;
			//	time22 = 0;
			
		}
   
	             
		 if(out == 0)//still on time to put password
			{	
	    		if (_RB3 == 1)//put RB3 ON after putting password					
               
			 	{	
					time20 = 0;		
	                transl = (PORTB >> 6);//GETTING THE CODE WISHED FROM SWITCHES
					transl = (transl & 0x000F);
			    	transl =(transl & codeP);
				
	                if(transl == 0x000F)// right passw
                    {
					    luz = 0;// to star decoding in zero
                        Display((char *) TeamStrTest4);//space					
		            	alarmOff =0;
						time20 = 0;
						_RB4 = 0;// LIGHTING THE LED off FOR ALARM  CANCELLED
						timeLeft = 0;
						time22 = 0;
				    }			
					
		    	}
			}
						
			
   	}			
          
}   
   

/************************************************/
