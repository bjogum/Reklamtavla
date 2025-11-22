#ifndef TEXTEFFECTS_H
#define TEXTEFFECTS_H

#include "lcd.h"
#include "customer.h"

void scrollText(HD44780 *lcd, char *txt);
void blinkText(HD44780 *lcd, char *txt);
void createSpecChar(HD44780 *lcd);
void fixSpecChar(char *InStr);
const uint8_t* getBitmap(char inputChar); 
void fadeInString(HD44780 *lcd, char *txt);
void discoMan(HD44780 *lcd);
int cleanBreak(char *inputStr);

#endif