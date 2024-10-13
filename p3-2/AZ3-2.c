/*
 * AZ3.2.c
 *
 * Created: 10/22/2022 5:27:56 PM
 * Author: Bashir Rayaneh
 */

#include <io.h>
#include <MyApp.h>
void main(void)
{
int i,a;
char digit[4]={0,0,0,0};
while (1)
    {
    // Please write your application code here
    a = getkeycode();
     for(i = 0 ;i<84;i++)
        sevensegdisplay_4digit(digit,0);
    if(a==13)  {
         digit[0]=digit[1];
         digit[1]=digit[2];
         digit[2]=digit[3];
         digit[3]++;
         if(digit[3] == 10)
            digit[3]=0;
         
    }
    else if(a==12){
        digit[3]=digit[2];
        digit[2]=digit[1];
        digit[1]=digit[0];
        digit[0]++;
        if(digit[0] == 10)
            digit[0]=0;
    }
    
    
    }
}
