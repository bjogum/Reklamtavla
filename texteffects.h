#ifndef TEXTEFFECTS_H
#define TEXTEFFECTS_H

#include "lcd.h"
#include "customer.h"

void scrollText(HD44780 *lcd, Customer *user, int userToPresent, int textIndex);
void createSpecChar(HD44780 *lcd);
void FixSpecChar(char *InStr);

#endif