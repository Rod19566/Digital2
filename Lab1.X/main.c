/*
 * File:   main.c
 * Author: Dina Rodríguez
 *
 * Created on January 21, 2021, 6:06 PM
 */


#include <xc.h>
/* ----
 Palabras de configuración
 ---*/

// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

/*---
 Variables
 ---*/
//se asignan variables de los puertos para las luces led
#define LEDr PORTEbits.RE0 
#define LEDa PORTEbits.RE1 
#define LEDv PORTEbits.RE2  //los leds
#define BTNStart PORTBbits.RB0 //


#define _XTAL_FREQ 8000000 //Para que funcione el delay


void setup(void);
void semaforo(void);

/*---
 * 1 Ciclo del semáforo
 ---*/
void semaforo(void){
    LEDv = 0;
    LEDr = 1;
    LEDa = 0;
    __delay_ms(500); 
    
    LEDr = 0;
    LEDa = 1;
    __delay_ms(500); 
    
    LEDa = 0;
    LEDv = 1;
    __delay_ms(500); 
}
///////

/// variables globales
unsigned char bandera = 0;

/////
void main(void) {
   setup();
   
    while(1){
        if (BTNStart == 0){
            semaforo();
           // bandera = 1;
        } 
      //  bandera = 0;
    }
}

/*---
 Ciclo Principal
 ---*/
void setup(void){
    
    ANSEL = 0;
    ANSELH = 0;
    
    TRISEbits.TRISE0 = 0;  //Led rojo
    TRISEbits.TRISE1 = 0;  //Led amarillo
    TRISEbits.TRISE2 = 0;  //Led verde
    
    PORTE = 0;
    

}
