/*
 * az3.1.c
 *
 * Created: 10/22/2022 4:06:57 PM
 * Author: Bashir Rayaneh
 */

#include <io.h>
#include <MyApp.h>

void main(void)
{
int i, a;
char digit[4]={0,0,0,0};
while (1)
    {
    // Please write your application code here
     for(i=0;i<84;i++)
            sevensegdisplay_4digit(digit,0);
     a = getkeycode(); 
     if((0 <= a) & (a <= 15))
     {
        digit[3] = digit[2];
        digit[2] = digit[1];
        digit[1] = digit[0];
        digit[0] = a;
        }
    }
}
