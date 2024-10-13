/*
 * AZ6-2.c
 *
 * Created: 11/9/2022 10:47:22 PM
 * Author: Bashir Rayaneh
 */

#include <io.h>
#include <MyApp.h>
#include <alcd.h>
#include <stdio.h> 
float timer=0;
char a;
int flag=0,flag2=0;
interrupt [TIM1_COMPA] void timer1_compa_isr(void){
    a = getkeycode();
    if (a==1){
      if(flag2==0 ){      
        flag =1;
        flag2=1;
        }
      else if(flag2 ==1){
        flag = 0 ;
        flag2 = 0;
      }   
    }
    if(flag == 1){
        timer+=0.01; 
        if(timer > 99.99)
            timer = 0.00;
    }
}
void main(void)
{
char str[16];
TCCR1A=0x00;
TCCR1B=0x0A;
TIMSK=0x10;
OCR1A = 9999;
#asm("sei")
lcd_init(16);
while (1)
    {
    // Please write your application code here
    sprintf(str,"%5.2f", timer);
    lcd_gotoxy(0,0);
    lcd_puts(str);
    }
}
