/*
 * AZ5-2.c
 *
 * Created: 11/5/2022 7:48:23 PM
 * Author: Bashir Rayaneh
 */
#include <io.h>
#include <delay.h>
#include <MyApp.h>

int a;
char b;
interrupt [USART_RXC] void usart_rx_isr(void)
{
    b = (char)UDR;
    a = (int) UDR;    
}

void main(void){
char digit[4];
int counter,i,flag1=0,flag2=0;
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
    while(flag1 == 0){
        counter = a;
        digit[0] = counter %10;
        digit[1] = (counter /10) %10;
        digit[2] = (counter /100) %10;
        digit[3] = (counter /1000) %10;
        for(i = 0; i < 10; i++)
         sevensegdisplay_4digit(digit,0);
        if((b == 'd')|(b == 'D')|(b == 's')|(b == 'S')|(b == 'u')|(b == 'U'))
            flag1 = 1;    
        }
        if(((b == 'd')|(b == 'D')) & (flag2 == 0)){
            counter --;
        } else if((b == 's')|(b == 'S')){
            flag2 = 1;       
        }else if(((b == 'u')|(b == 'U')) & (flag2 == 0)){   
             counter ++;
        }
        digit[0] = counter %10;
        digit[1] = (counter /10) %10;
        digit [2] = (counter /100) %10;
        digit [3] = (counter /1000) %10;
        for(i = 0; i < 43; i++)
            sevensegdisplay_4digit(digit,0); 
    }
}
