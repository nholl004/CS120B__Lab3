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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char tmpa = 0x00;
	unsigned char tmpb = 0x00;
	unsigned char tmpc = 0x00;
	unsigned char c1 = 0x00;
	unsigned char c2 = 0x00;
    while (1) {
	tmpa = PINA;
	tmpb = PINB;
	while(c1 < 8){
		c2 = tmpa & 0x01;
		if(c2 == 0x01){
			tmpc++;
		}
		c2 = tmpb & 0x01;
		if(c2 == 0x01){
			tmpc++;
		}
		tmpa = tmpa >>1;
		tmpb = tmpb >>1;
		c1++;
	}
	PORTC = tmpc;	
    }
    return 1;
}
