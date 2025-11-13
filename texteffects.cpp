#include <stdio.h> //sprintf()
#include <string.h> //strlen()
#include <util/delay.h> //_delay_ms()
#include "lcd.h"
#include "customer.h"

#define DISPLEN 16

void scrollText(HD44780 *lcd, Customer *user, int userToPresent, int textIndex){

    // SCROLL FUNCTION + delay
    int cnt = 0;

    // two 'complete scrolls'
    while (cnt < 2){
        cnt++;

        char txt_R[45];
        char *txt_L = user[userToPresent].message[textIndex].message;

        // scroll to txt ends (roll out of screen)
        for (int i = 0; i < (strlen(user[userToPresent].message[textIndex].message)+DISPLEN+1); i++){

            if (i <= DISPLEN){
                snprintf(txt_R,i+1,txt_L);
                lcd->GoTo(DISPLEN-i,0);
                lcd->WriteText((char *)txt_R);    
            } 
            else {
                lcd->Clear();
                lcd->WriteText((char *)txt_L+i-DISPLEN);
            }
            _delay_ms(130);
        }
    }
}