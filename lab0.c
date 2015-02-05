// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         
// Authors:      
//
// Description:  Lab 0 assignment for ECE 372 Spring 2015.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "initLab0.h"
#include <stdio.h>

// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )



#define TWO_SECONDS 115198

typedef enum stateTypeEnum{
    //TODO: Define states by name
    D4_On, D5_On, D6_On, D7_On, Wait1, Wait2, Wait3, Wait4
} stateType;

volatile stateType state = D4_On;
volatile int second;

int main(void)
{

    //TODO: Finish these functions in the provided c files
    initLEDs();
    initTimer1();
    initSW1();

    second = 0;

    while(1)
    {
        //Use a switch statement to define the behavior based on the state
       
        switch(state){
            case D4_On:
                turnOnLED(4);
                break;
            case Wait1:
                break;
            case D5_On:
                turnOnLED(5);
                break;
            case Wait2:
                break;
            case D6_On:
                turnOnLED(6);        
                break;
            case Wait3:
                break;
            case D7_On:
                turnOnLED(7);
                break;
            case Wait4:
                break;

        }
    }
    return 0;
}

void _ISR _T1Interrupt(void){
    //TODO: Put down the timer 1 flag first!
    IFS0bits.T1IF = 0;

    //TODO: Change states if necessary.
    second = second + 1;
     if(PORTBbits.RB5 == 1){
        if(state == Wait1) {
            if(second < 20)
                       state = D5_On;
                   else
                       state = D7_On;
            second = 0;
        }
        else if(state == Wait2){
            if(second < 20)
                       state = D6_On;
                   else
                       state = D4_On;
            second = 0;
        }
        else if(state == Wait3){
            if(second < 20)
                        state = D7_On;
                   else
                        state = D5_On;
            second = 0;
        }
        else if(state == Wait4) {
            if(second < 20)
                        state = D4_On;
                   else
                        state = D6_On;
            second = 0;
        }
    }
    if(state == D4_On){
        if(PORTBbits.RB5 == 1){
            state = D4_On;
        }
        else
            state = Wait1;
    }
     if(state == D5_On){
        if(PORTBbits.RB5 == 1){
            state = D5_On;
        }
        else
            state = Wait2;
    }
     if(state == D6_On){
        if(PORTBbits.RB5 == 1){
            state = D6_On;
        }
        else
            state = Wait3;
    }
     if(state == D7_On){
        if(PORTBbits.RB5 == 1){
            state = D7_On;
        }
        else
            state = Wait4;
    }
   
    //Make sure if you use any variables that they are declared volatile!
}