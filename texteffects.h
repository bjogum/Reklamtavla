#ifndef TEXTEFFECTS_H
#define TEXTEFFECTS_H

#include "lcd.h"
#include "customer.h"

void scrollText(HD44780 *lcd, char *txt);
void createSpecChar(HD44780 *lcd);
void FixSpecChar(char *InStr);

#endif