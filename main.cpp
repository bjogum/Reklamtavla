#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include "lcd.h"
#include "uart.h"

// https://wokwi.com/projects/416241646559459329

// PORTB B (digital pin 8 to 13)
// C (analog input pins)
// PORTD D (digital pins 0 to 7)
#define LED_PIN 2
#define BUTTON_PIN 1

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 


#define BUTTON_IS_CLICKED(PINB,BUTTON_PIN) !BIT_CHECK(PINB,BUTTON_PIN)

 

int main(void){
    init_serial();
    HD44780 lcd;

    lcd.Initialize(); // Initialize the LCD
    lcd.Clear();      // Clear the LCD

    lcd.WriteText((char *)"Hej hej");
    printf("Hej hej\n");
    int r = 12;
    printf("Hej 2 %d\n",r);
    // // //Sätt till INPUT_PULLUP
    // BIT_CLEAR(DDRB,BUTTON_PIN); // INPUT MODE
    // BIT_SET(PORTB,BUTTON_PIN); 

    // DATA DIRECTION = avgör mode
    // om output så skickar vi  1 eller 0 på motsvarande pinne på PORT
    // om input så läser vi  1 eller 0 på motsvarande pinne på PIN
    //bool blinking = false;
    while(1){
        /*

        1. En struct med kund: betalning, namn
        2. En struct med reklamtext (text mot rätt kund)
        3. Reklamtid = 20sek (FRÅGA: sleep är olika på olika os..?)
        4. Slumpa fram kund, beroende på betalning. rand().
        5. Om vi har tid: Skrolla/rulla texten.

Hederlige Harrys Bilar:
Betalat 5000. Vill slumpmässigt visa en av tre meddelanden
"Köp bil hos Harry"  (scroll)
"En god bilaffär (för Harry!)" text
"Hederlige Harrys Bilar" text (blinkande)
 
Farmor Ankas Pajer AB:
Betalat 3000. Vill slumpmässigt visa en av två
"Köp paj hos Farmor Anka"  (scroll)
"Skynda innan Mårten ätit alla pajer" text
 
Svarte Petters Svartbyggen:
Betalat 1500. Vill visa
"Låt Petter bygga åt dig"  (scroll) - på jämna minuter
"Bygga svart? Ring Petter" text - på ojämna minuter
 
Långbens detektivbyrå:
Betalat 4000. Vill visa
"Mysterier? Ring Långben"  text 
"Långben fixar biffen" text 
 
Ibland måste vi visa reklam för oss själva:
motsvarande för 1000 kr. 
Meddelande "Synas här? IOT:s Reklambyrå"

        */


    
    }

    return 0;
}
