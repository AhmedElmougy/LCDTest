/*
 * File        : main.c
 * Description : This file includes LCD test application for Atmega32
 * Author      : Ahmed Elmogy Embedded SW Engineer 
 * Date        : 5/2/2020
 * Git account : https://github.com/AhmedElmougy
 * mail        : ahmed.m.elmogy@gmil.com 
 */


#include "LSTD_Types.h"
#include "HLCD_Interface.h"
#include "LDELAY_Interface.h"

int main(void)
{
	/*initialize LCD*/
	HLCD_voidInitializeLCD();
	/*Number to display*/
	u32 num = 4556545;
	
	/*infinite loop*/
	while (1) 
    {
		/*clear LCD and return to first location*/
		HLCD_voidClearLCD();
		/*switch display off*/
		HLCD_voidScreenDisplayOnOff(HLCD_OFF);
		/*wait for 2 seconds*/
		LDelay_voidDelay_ms(2000);
		/*switch display on*/
		HLCD_voidScreenDisplayOnOff(HLCD_ON);
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*stop cursor blinking and hide cursor*/
		HLCD_voidCursorDisplayOnOff(HLCD_OFF);
		HLCD_voidCursorBlinkOnOff(HLCD_OFF);
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*Display a character on LCD*/
		HLCD_voidDisplayChar('a');
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*Display second custom character on LCD*/
		HLCD_voidDisplayCustomChar(HLCD_CUST_CHAR_2);
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*Display string*/
		HLCD_voidDisplayString("Test",HLCD_STRING);
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*move cursor to second line digit number 5*/
		HLCD_voidSetCursorPosition(HLCD_LINE2,5);
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*Display number 4556545 on LCD*/
		HLCD_voidDisplayString(&num,HLCD_NUMBER);
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*Move to second line first cell*/
		HLCD_voidSelectLine(HLCD_LINE2);
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*display c on LCD*/
		HLCD_voidDisplayChar('c');
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		
		/*shift right 16 times*/
		for (u8 i =0;i<16;i++)
		{
			HLCD_voidShiftRight();
			/*wait for 500 ms*/
			LDelay_voidDelay_ms(500);
			
		}/*end of shift right for loop*/
		
		/*shift left 16 times*/
		for (u8 i =0;i<16;i++)
		{
			HLCD_voidShiftLeft();
			/*wait for 500 ms*/
			LDelay_voidDelay_ms(500);
			
		}/*end of shift left for loop*/
		
		/*start cursor blinking and display*/
		HLCD_voidCursorDisplayOnOff(HLCD_ON);
		HLCD_voidCursorBlinkOnOff(HLCD_ON);
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*Move cursor 4 steps right*/
		HLCD_voidCursorShiftRight(3);
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*display b character*/
		HLCD_voidDisplayChar('b');
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*move cursor 2 steps left*/
		HLCD_voidCursorShiftLeft(2);
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		HLCD_voidDisplayChar('f');
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*return cursor to initial position without clearing display*/	
		HLCD_voidReturnHome();
		/*wait for 1 second*/
		LDelay_voidDelay_ms(1000);
		/*clear LCD*/
		HLCD_voidClearLCD();
		/*wait 1 second*/
		LDelay_voidDelay_ms(1000);
		/*loop custom character*/
		for (u8 i =0;i<8;i++)
		{
			/*display all custom made characters saved in CGRAM*/
			HLCD_voidDisplayCustomChar(i);
			/*wait for 500 ms*/
			LDelay_voidDelay_ms(500);
			
		}/*end of custom character loop*/
		
		/*wait for 3 second*/
		LDelay_voidDelay_ms(3000);
		
	}/*end of while loop*/
	
}/*end of main()*/

