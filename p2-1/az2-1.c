/*
 * az2-1.c
 *
 * Created: 1/1/2003 12:28:11 AM
 * Author: Admin
 */

#include <io.h>
#include <delay.h>
#include <MyApp.h>
void main(void)
{
char a = 0;
char b = 0;
char c = 0;
char d = 0;
char zero = 0;
while (1)
    {
    // Please write your application code here
    char digit[4] =  {0,0,0,0};
    char j = 0;
    d = c;
    c = b;
    b = a;
    a = zero;

    digit[0] = a;
    digit[1] = b;
    digit[2] = c;
    digit[3] = d;

    for (j = 0 ; j < 99 ; j++)
    { sevensegdisplay_4digit(digit,0);}

    zero++;
    if (zero > 15){
    zero = 0;
    }
    }
}
