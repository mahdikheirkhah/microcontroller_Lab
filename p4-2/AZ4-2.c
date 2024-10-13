#include <io.h>
#include <delay.h>
#include <stdio.h>
#include <alcd.h>

void main(void)
{
float a;
char str[2][16];
lcd_init(16);
ADCSRA = 0XC6;
while (1)
    {
    // Please write your application code here
    ADMUX = 0X42;
    delay_ms(20);
    ADCSRA |= (1<<ADSC);
    while((ADCSRA & (1<<ADIF)) == 0);
    ADCSRA |= (1<<ADIF);
    a = ADCW * (5.0 / 1023.0);  
    sprintf(str[1], "V2 = %3.1f volt",a);
    lcd_gotoxy(0,1);
    lcd_puts(str[1]);
    delay_ms(250); 
    ADMUX = 0Xc5;
    delay_ms(20);
    ADCSRA |= (1<<ADSC);
    while((ADCSRA & (1<<ADIF)) == 0);
    ADCSRA |= (1<<ADIF);
    a = ADCW * (256.0 / 1023.0);  
    sprintf(str[0], "T = %5.2f 'C",a);
    lcd_gotoxy(0,0);
    lcd_puts(str[0]);
    
    }
}