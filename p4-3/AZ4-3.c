#include <io.h>
#include <MyApp.h>
#include <delay.h>


void main(void)
{
int res,i;
char digit[4] = {1, 2, 3, 4};
char sel = 0; // 0 -> tempeture | 1 -> voltage channel 2 | 2 -> voltage channel 3
DDRB.0=0;
PORTB.0=1;
ADCSRA= 0xc6;
while (1)
    {
        if(!PINB.0){
            delay_ms(20);
            if(PINB.0) continue;

            sel++;
            if(sel > 2) sel = 0;

            while(!PINB.0) continue;
        }

        if(sel == 0){
            ADMUX = 0xc5;
            delay_ms(1);
            ADCSRA |= (1<<ADSC);
            while(ADCSRA & (1<<ADIF) == 0);
            ADCSRA |= (1<<ADIF);
            res = ADCW*25600.0/1023;
            digit[0] = res%10;
            digit[1] = (res/10)%10;
            digit[2] = (res/100)%10;
            digit[3] = (res/1000)%10;
            for(i = 0; i < 10; i++)
                sevensegdisplay_4digit(digit, 2);
        } else if(sel == 1){
            ADMUX = 0x42;
             delay_ms(1);
            ADCSRA |= (1<<ADSC);
            while(ADCSRA & (1<<ADIF) == 0);
            ADCSRA |= (1<<ADIF);
            res = ADCW*50.0/1023;
            digit[0] = res%10;
            digit[1] = (res/10)%10;
            digit[2] = 0;
            digit[3] = 0;
            for(i = 0; i < 10; i++)
                sevensegdisplay_4digit(digit, 1);
        } else if(sel == 2){
            ADMUX = 0x43;
            delay_ms(1);
            ADCSRA |= (1<<ADSC);
            while(ADCSRA & (1<<ADIF) == 0);
            ADCSRA |= (1<<ADIF);
            res = ADCW*50.0/1023;
            digit[0] = res%10;
            digit[1] = (res/10)%10;
            digit[2] = 0;
            digit[3] = 0;
            for(i = 0; i < 10; i++)
                sevensegdisplay_4digit(digit, 1);
        }
    }
}