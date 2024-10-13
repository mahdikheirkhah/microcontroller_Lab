

#include <io.h>
#include <delay.h>
#include <MyApp.h>

void main(void)
{

int a = 0;
DDRB.0=0;
PORTB.0=1;
DDRB.1=0;
PORTB.1=1;

while (1)
    {
    char Digit[4] = {0, 0, 0, 0};
    Digit[0] = a % 10;
    Digit[1] = (a / 10) % 10;
    Digit[2] = (a / 100) % 10;
    Digit[3] = (a / 1000) % 10;

    sevensegdisplay_4digit(Digit, 0);
        if(!PINB.0){
            sevensegdisplay_4digit(Digit, 0);
            if(PINB.0) continue;

            a++;
            if(a > 9999){
                a = 0;
            }

            while(!PINB.0) sevensegdisplay_4digit(Digit, 0);;
        }



        if(!PINB.1){
            sevensegdisplay_4digit(Digit, 0);
            if(PINB.1) continue;

            a--;
            if(a < 0){
                a = 9999;
            }

            while(!PINB.1) sevensegdisplay_4digit(Digit, 0);;
        }


    }
}
