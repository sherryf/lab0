/*
* File:   initLab0.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"

#define FCY 14745600.0
#define TIME_DELAY 0.1

void initLEDs(){
    //TODO: Initialize the pin connected to the LEDs as outputs
    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB12 = 0;
    //TODO: Turn each LED OF
    LATBbits.LATB15 = 1;
    LATBbits.LATB14 = 1;
    LATBbits.LATB13 = 1;
    LATBbits.LATB12 = 1;

}

void initSW1(){
    //TODO: Initialize the pin connected to the switch as an input.
    TRISBbits.TRISB5 = 1;
}


void initTimer1(){
    //TODO: Initialize the timer
    unsigned int prVal = (FCY*TIME_DELAY)/256.0 - 1;
    PR1 = prVal;
    T1CONbits.TCKPS = 0b11; //prescalar 256
    IEC0bits.T1IE = 1; // Enable the interrupt
    IFS0bits.T1IF = 0; // Put the interrupt flag down
    T1CONbits.TON = 1; // Turn the timer 1 on
}

void turnOnLED(int led){
    if(led == 4){
        LATBbits.LATB15 = ON;
        LATBbits.LATB14 = OFF;
        LATBbits.LATB13 = OFF;
        LATBbits.LATB12 = OFF;
    }
    else if(led == 5){
        LATBbits.LATB15 = OFF;
        LATBbits.LATB14 = ON;
        LATBbits.LATB13 = OFF;
        LATBbits.LATB12 = OFF;
    }
    else if(led == 6){
        LATBbits.LATB15 = OFF;
        LATBbits.LATB14 = OFF;
        LATBbits.LATB13 = ON;
        LATBbits.LATB12 = OFF;
    }
    else if(led == 7){
        LATBbits.LATB15 = OFF;
        LATBbits.LATB14 = OFF;
        LATBbits.LATB13 = OFF;
        LATBbits.LATB12 = ON;
    }
}