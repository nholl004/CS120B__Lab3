/*	Author: nholl004
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTC = 0x01;
    /* Insert your solution below */
	unsigned char tmpd = 0x00;
	unsigned char tmpb = 0x00;
    while (1) {
	tmpd = PIND;
	tmpb = PINB;

	tmpd = tmpd <<1;
	tmpd = tmpd + tmpb;
	if(tmpd >= 0x46){
		tmpb = 0x02;
	}	
	else if((tmpd > 0x05) && (tmpd < 0x46)){
		tmpb = 0x04;
	}
	else if(tmpd < 0x05){
		tmpb = 0x00;
	}

	PORTB = tmpb;
    }
    return 1;
}
