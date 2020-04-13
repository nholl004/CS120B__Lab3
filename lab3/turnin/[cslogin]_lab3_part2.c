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
	unsigned char tmpa = 0x00;
	unsigned char tmpc = 0x00;
    while (1) {
	tmpa = PINA;
	if(tmpa < 0x03){
		tmpc = 0x60;
	}
	else if((tmpa > 0x02) && (tmpa < 0x05)){
		tmpc = 0x70;
	} 
	else if((tmpa > 0x04) && (tmpa < 0x07)){
                tmpc = 0x38;
        } 
	else if((tmpa > 0x06) && (tmpa < 0x0A)){
                tmpc = 0x3C;
        } 
	else if((tmpa > 0x09) && (tmpa < 0x0D)){
                tmpc = 0x3E;
        } 
	else if(tmpa > 0x0C){
                tmpc = 0x3F;
        }
	PORTC = tmpc;
    }
    return 1;
}
