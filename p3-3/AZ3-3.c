/*
 * AZ3-3.c
 *
 * Created: 10/22/2022 7:13:15 PM
 * Author: Bashir Rayaneh
 */

#include <io.h>
#include <alcd.h>
#include <stdio.h>
#include <delay.h>
#include <MyApp.h>

void main(void)
{
char str[2][16];
char temp[16];
int a;
lcd_init(16);
while (1)
    {
    // Please write your application code here
    a = getkeycode();
    if((a % 2 == 0)&(a < 16)){  
            sprintf(str[0],"%X", a);
            lcd_gotoxy(a,0);
            lcd_puts(str[0]);
    }
    else if((a%2 == 1)&(a<16)){
        sprintf(str[1],"%X", a);
            lcd_gotoxy(a,1);
            lcd_puts(str[1]);
    }
    }
}
