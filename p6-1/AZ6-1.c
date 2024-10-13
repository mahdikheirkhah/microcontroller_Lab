/*
 * AZ6-1.c
 *
 * Created: 11/9/2022 8:17:19 PM
 * Author: Bashir Rayaneh
 */

#include <io.h>
#include <MyApp.h>

void main(void)
{
int counter1 = 0, counter2 = 1000, flag1 = 0;
char b;
DDRD.5 = 1;
TCCR1A = 0X40;
TCCR1B = 0X0A;
while (1)
    {
    // Please write your application code here
    while(flag1 == 0){
        b =  getkeycode();
        if( b == 2  ){
            counter1 += 100 ;
            if(counter1 <= 1000)
            OCR1A = 500000/(counter1);
            else
                counter1 = 0;
            }
        else if( b == 3  ){
            counter1 -= 100 ;
            if(counter1 >= 100)
            OCR1A = 500000/(counter1);
            else
                counter1 = 1000;
            }
        else if (b == 1){
            flag1 = 1;
            break;
            }                  
        }
    while(flag1 == 1){
        b =  getkeycode();
        if( b == 2  ){
            counter2 += 1000 ;
            if(counter2 <= 10000)
            OCR1A = 500000/(counter2);
            else
                counter2 = 1000;
            }
        else if( b == 3  ){
            counter2 -= 1000 ;
            if(counter2 >= 1000)
            OCR1A = 500000/(counter2);
            else
                counter2 = 10000;
            }
        else if (b == 1){
            flag1 = 0;
            break;
            }           
        }    
    }
}
