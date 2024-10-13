/*
 * AZ3-4.c
 *
 * Created: 10/22/2022 8:45:19 PM
 * Author: Bashir Rayaneh
 */

#include <io.h>
#include <delay.h>
#include <MyApp.h>
#include <alcd.h>
#include <stdio.h>
void main(void)
{
char str[16];
int a, counter = 0;
lcd_init(16);
lcd_gotoxy(0,0);
lcd_putsf("COUNTER=");
while (1)
    {
    // Please write your application code here
    a = getkeycode();
    sprintf(str,"%d", counter);
    lcd_gotoxy(8,0);
    lcd_puts(str);
    if(a == 13){
        counter++;
        sprintf(str,"%d", counter);
        lcd_gotoxy(8,0);
        lcd_puts(str);
            
     }
    else if(a == 12){
        counter--;
        sprintf(str,"%d", counter);
        lcd_gotoxy(8,0);
        lcd_puts(str);
            
     }
     delay_ms(200);
    }
}
