/*
 * AZ4-1.c
 *
 * Created: 10/27/2022 2:53:21 PM
 * Author: Bashir Rayaneh
 */

#include <io.h>
#include <delay.h>
#include <stdio.h>
#include <alcd.h>

void main(void)
{
float a;
char str[16];
lcd_init(16);
ADMUX = 0X42;
ADCSRA = 0XC6;
while (1)
    {
    // Please write your application code here
    ADCSRA |= (1<<ADSC);
    while((ADCSRA & (1<<ADIF)) == 0);
    ADCSRA |= (1<<ADIF);
    a = ADCW * (5.0 / 1023.0);  
    sprintf(str, "V2 = %3.1f volt",a);
    lcd_gotoxy(0,0);
    lcd_puts(str);
    delay_ms(500);
    }
}
