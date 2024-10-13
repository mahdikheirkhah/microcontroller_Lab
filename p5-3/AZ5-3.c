/*
 * AZ5-3.c
 *
 * Created: 11/5/2022 9:10:03 PM
 * Author: Bashir Rayaneh
 */

#include <io.h>
#include <delay.h>
#include <stdio.h>
#include <MyApp.h>

char c;

interrupt [USART_RXC] void usart_rx_isr(void)
{
    c = (char)UDR;    
}

void main(void)
{
char digit[4];
float a;
int b,i;
ADCSRA = 0XC6;
ADMUX = 0XC5;
DDRD=0x00;
DDRC=0x00;
UCSRA=0x00;
UCSRB=0x98;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x33;
while (1)
    {
    // Please write your application code here
    ADCSRA |= (1<<ADSC);
    while((ADCSRA & (1<<ADIF)) == 0);
    ADCSRA |= (1<<ADIF);
    a = ADCW * (25600.0 / 1023.0);
    b = (int)a;
    digit[0]= b%10;
    digit[1]=(b/10)%10;
    digit[2]=(b/100)%10;
    digit[3]=(b/1000)%10;
    for(i = 0; i < 10; i++)
        sevensegdisplay_4digit(digit,1);
    if((c == 'T')|(c == 't')){
        printf("%5.1f", a);
        }    
    }
}
