#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "lcd.h"
#include "uart.h"

// https://wokwi.com/projects/416241646559459329

// PORTB B (digital pin 8 to 13)
// C (analog input pins)
// PORTD D (digital pins 0 to 7)
#define LED_PIN 2
#define BUTTON_PIN 1
#define REKLAMTID 20000

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

#define BUTTON_IS_CLICKED(PINB,BUTTON_PIN) !BIT_CHECK(PINB,BUTTON_PIN)


int main(void){

    init_serial();
    HD44780 lcd;
    lcd.Initialize(); // Initialize the LCD

    typedef struct
    {
    char message[40];
    }Message;

    typedef struct
    {   
        Message message[3];
        int messagesCount;
        int paid;
    }Customer;
    
    // create all (5) customers.
    Customer user[5];

    //Hedelige Harry
    user[0].paid = 5000;
    user[0].messagesCount = 3;
    strcpy(user[0].message[0].message, "K\xEFp bil hos Harry");
    strcpy(user[0].message[1].message, "En god bilaff\xE1r (f\xEFr Harry!)");
    strcpy(user[0].message[2].message, "Hederlige Harrys Bilar");

    //Farmor Anka
    user[1].paid = 3000;
    user[1].messagesCount = 2;
    strcpy(user[1].message[0].message, "K\xEFp paj hos Farmor Anka");
    strcpy(user[1].message[1].message, "Skynda innan Marten \xE1tit alla pajer");

    //Svarte Petter
    user[2].paid = 1500;
    user[2].messagesCount = 2;
    strcpy(user[2].message[0].message, "Lat Petter bygga at dig");
    strcpy(user[2].message[1].message, "Bygga svart? Ring Petter");

    //Långbens detektivbyrå
    user[3].paid = 4000;
    user[3].messagesCount = 2;
    strcpy(user[3].message[0].message, "Mysterier? Ring Langben");
    strcpy(user[3].message[1].message, "Langben fixar biffen");
    
    //IoTs reklambyrå
    user[4].paid = 1000;
    user[4].messagesCount = 1;
    strcpy(user[4].message[0].message, "Synas h\xE1r? IOT:s Reklambyra");

    // get the SUM of the payments
    int sum = 0;
    for (int i = 0; i < 5; i++){
        sum += user[i].paid;
    }
    
    int userToPresent = -1; 

    while(1){

        int lastPresented = userToPresent;
        
        // get a NEW random customer
        while (userToPresent == lastPresented){

            int randCustomer = rand() % (sum+1); 

            if (randCustomer >= 0 && randCustomer <= 4999){
                userToPresent = 0;
            } else if (randCustomer >= 5000 && randCustomer <= 8000){
                userToPresent = 1;
            } else if (randCustomer >= 8001 && randCustomer <= 9501){
                userToPresent = 2;
            } else if (randCustomer >= 9502 && randCustomer <= 13502){
                userToPresent = 3;
            } else if (randCustomer >= 13503 && randCustomer <= sum){
                userToPresent = 4;
            }
        }

        // get a random text (index)
        int textIndex = rand() % user[userToPresent].messagesCount;

        printf("Now presenting; %d | Text id: %d\n", userToPresent, textIndex);

        // Clear the LCD
        lcd.Clear();      

        // write LCD text
        lcd.WriteText((char *)user[userToPresent].message[textIndex].message);

        _delay_ms(REKLAMTID);

    }
    return 0;
}
