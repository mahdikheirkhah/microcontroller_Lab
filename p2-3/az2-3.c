/*
 * AZ2-3.c
 *
 * Created: 10/16/2022 1:38:47 AM
 * Author: Bashir Rayaneh
 */

#include <io.h>
#include <MyApp.h>

char digit[4]={0,0,9,9};

interrupt[EXT_INT1]void ext_int1_isr(void){
     digit[2]--;
     if(digit[2]== 0){
        digit[2]=9;
        digit[3]--;
     }
     if(digit[3]==0){
        digit[3]=9;
     }
}

interrupt[EXT_INT0]void ext_int0_isr(void){
     digit[0]++;
     if(digit[0]>9){
        digit[0]=0;
        digit[1]++;
     }
     if(digit[1]>9){
        digit[0]=0;
        digit[1]=0;
     }

}

void main(void)
{
int i;
DDRD.2 = 0;
PORTD.2 = 1;
DDRD.3 = 0;
PORTD.3 = 1;
GICR |=(1<<INT1)|(1<<INT0)|(0<<INT2);
MCUCR = (1<<ISC11)|(1<<ISC10)|(1<<ISC01)|(1<<ISC00);
GIFR = (1<<INTF1)|(1<<INTF0)|(0<<INTF2);
#asm("sei")
while (1)
   {
    // Please write your application code here
      sevensegdisplay_4digit(digit, 0);
   }
}

