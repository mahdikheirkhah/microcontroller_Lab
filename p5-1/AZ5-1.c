/*
 * AZ5-1.c
 *
 * Created: 11/5/2022 3:28:17 PM
 * Author: Bashir Rayaneh
 */
#include <io.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>
#include <MyApp.h>

interrupt [USART_RXC] void usart_rx_isr(void)
{
    lcd_gotoxy(0,0);
    lcd_putchar(UDR);
}

void main(void)
{
int a;
DDRC=0x00;
DDRD=0x00;
UCSRA=0x00;
UCSRB=0x98;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x33;
lcd_init(16);
#asm("sei")
while (1)
    {
    // Please write your application code here 
    a = (int)getkeycode();
    if(a != 16)
        printf("%d\n",a);
    delay_ms(100);
    }
}
