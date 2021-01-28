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
#define BTNStart PORTBbits.RB0 // botón Start


#define _XTAL_FREQ 8000000 //Para que funcione el delay -crystal-


/// variables globales
unsigned char bandera = 0;
unsigned char conta,contb; 
///////

void setup(void);
void semaforo(void);
void player1(void);
void player2(void);
void reset(void);

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
    __delay_ms(1500); // un rato más largo el verde jiji
    LEDv = 0; 
}
///////
void player1(void){
    switch(conta){
        case 0: PORTCbits.RC0 = 1 ; 
        break;
        case 1: PORTCbits.RC0 = 0 ; 
        PORTCbits.RC1 = 1 ; 
        break;
        case 2: PORTCbits.RC1 = 0 ; 
        PORTCbits.RC2 = 1 ;  
        break;
        case 3: PORTCbits.RC2 = 0 ; 
        PORTCbits.RC3 = 1 ; 
        break;
        case 4: PORTCbits.RC3 = 0 ; 
        PORTCbits.RC4 = 1 ; 
        break;
        case 5: PORTCbits.RC4 = 0 ; 
        PORTCbits.RC5 = 1 ; 
        break;
        case 6: PORTCbits.RC5 = 0 ;  
        PORTCbits.RC6 = 1 ; 
        break;  
        case 7: PORTCbits.RC7 = 0 ;  
        PORTAbits.RA0 = 1 ;
        PORTCbits.RC1 = 1 ;
        PORTCbits.RC2 = 1 ;
        PORTCbits.RC3 = 1 ;
        PORTCbits.RC4 = 1 ;
        PORTCbits.RC5 = 1 ;
        PORTCbits.RC6 = 1 ;
        PORTCbits.RC7 = 1 ;
        break;        
    }
}

void player2(void){
    switch(contb){
        case 0: PORTDbits.RD0 = 1 ; 
        break;
        case 1: PORTDbits.RD0 = 0 ; 
        PORTDbits.RD1 = 1 ; 
        break;
        case 2: PORTDbits.RD1 = 0 ; 
        PORTDbits.RD2 = 1 ;  
        break;
        case 3: PORTDbits.RD2 = 0 ; 
        PORTDbits.RD3 = 1 ; 
        break;
        case 4: PORTDbits.RD3 = 0 ; 
        PORTDbits.RD4 = 1 ; 
        break;
        case 5: PORTDbits.RD4 = 0 ; 
        PORTDbits.RD5 = 1 ; 
        break;
        case 6: PORTDbits.RD5 = 0 ;  
        PORTDbits.RD6 = 1 ; 
        break;  
        case 7: PORTDbits.RD7 = 0 ; 
        PORTAbits.RA1 = 1 ;
        PORTDbits.RD1 = 1 ;
        PORTDbits.RD2 = 1 ;
        PORTDbits.RD3 = 1 ;
        PORTDbits.RD4 = 1 ;
        PORTDbits.RD5 = 1 ;
        PORTDbits.RD6 = 1 ;
        PORTDbits.RD7 = 1 ; 
        break;        
    }
}

void reset(void){ //resetea el juego
    conta = contb = 0 ;
    
    PORTAbits.RA0 = 0 ;
    PORTAbits.RA1 = 0 ; 
    
    PORTCbits.RC1 = 0 ;
    PORTCbits.RC2 = 0 ;
    PORTCbits.RC3 = 0 ;
    PORTCbits.RC4 = 0 ;
    PORTCbits.RC5 = 0 ;
    PORTCbits.RC6 = 0 ;
    PORTCbits.RC7 = 0 ; 
    
    PORTDbits.RD1 = 0 ;
    PORTDbits.RD2 = 0 ;
    PORTDbits.RD3 = 0 ;
    PORTDbits.RD4 = 0 ;
    PORTDbits.RD5 = 0 ;
    PORTDbits.RD6 = 0 ;
    PORTDbits.RD7 = 0 ;
        
}


void carrera(void){ //suma al contador
    
    if (PORTBbits.RB1 == 0 || PORTBbits.RB2 == 0){
        if (PORTBbits.RB1 == 0 && PORTBbits.RB2 != 0) conta++;
        else if (PORTBbits.RB1 != 0 && PORTBbits.RB2 == 0) contb++;
        else { //por si hacen click a los botones en simultáneo
            conta++;
            contb++;
        }
    }
    if (conta == 7 || contb == 7) bandera = 0; //finaliza la carrera
}

/////
void main(void) {
   setup();
   
    while(1){
        if (BTNStart == 0){
            semaforo();
            reset();
            bandera = 1;
        } 
        while (bandera){
            carrera();
            player1(); //mantiene al tanto las luces leds
            player2();
        }
        
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
    //TRISBbits.TRISBO = 1; //entrada del boton 

}
