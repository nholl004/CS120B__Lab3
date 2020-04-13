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
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char tmpa1 = 0x00;
	unsigned char tmpa2 = 0x00;
	unsigned char tmpc = 0x00;
    while (1) {
	tmpa1 = PINA << 4;
	tmpa1 = tmpa1 >> 4;
	tmpa2 = PINA >> 4;
	if(tmpa1 < 0x03){
		tmpc = 0x60;
	}
	else if((tmpa1 > 0x02) && (tmpa1 < 0x05)){
		tmpc = 0x70;
	} 
	else if((tmpa1 > 0x04) && (tmpa1 < 0x07)){
                tmpc = 0x38;
        } 
	else if((tmpa1 > 0x06) && (tmpa1 < 0x0A)){
                tmpc = 0x3C;
        } 
	else if((tmpa1 > 0x09) && (tmpa1 < 0x0D)){
                tmpc = 0x3E;
        } 
	else if(tmpa1 > 0x0C){
                tmpc = 0x3F;
        }
	if(tmpa2 == 0x03){
		tmpc = tmpc + 0x80;
	}
	PORTC = tmpc;
    }
    return 1;
}
