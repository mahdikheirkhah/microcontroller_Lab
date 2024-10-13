#include <io.h>
#include <delay.h>
#include <MyApp.h>

//============================================================================================================
//            Hex seven segment code array
//----------------------------  0   1    2     3    4    5    6    7    8    9   A     b    C   d     E    F  blank  - --//
flash   char  SevenSegCode[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00,0x40}; 
//---------------------------
void    sevensegdisplay_1digit(char  digit){
    DDRC=0XFF;
    DDRD.4=1;
    PORTD.4=1;  //Enable 7segment
    PORTC=SevenSegCode[digit];
}
//----------------------------
void    sevensegdisplay_4digit(char  digit[4],char point){
    DDRC=0XFF;
    DDRD|=0xf0;
    PORTD.4=1;
    PORTC=SevenSegCode[digit[0]];
    delay_ms(3);
    PORTD.4=0;
    PORTD.5=1;
    PORTC=SevenSegCode[digit[1]] | (point==1 ? 0x80:0);
    delay_ms(3);
    PORTD.5=0;
    PORTD.6=1;
    PORTC=SevenSegCode[digit[2]] | (point==2 ? 0x80:0);
    delay_ms(3);
    PORTD.6=0;
    PORTD.7=1;
    PORTC=SevenSegCode[digit[3]] | (point==3 ? 0x80:0);
    delay_ms(3);
    PORTD.7=0;
}
//==========================================Key pad====================================
char    getkeycode(void){
char		row;
    DDRB=0XF0;
    PORTB=0X0F;
	delay_us(1000);
	row=PINB & 0X0F;
	if(row==0x0f)return 16;
	delay_ms(2);
	row=PINB & 0X0F;
	if(row==0x0f)return 16;
    DDRB=0Xf0;
    PORTB=0Xef;
	delay_us(100);
	row=PINB & 0X0f;
	if(row!=0x0f){
        if(row==0x0e)return 7;
        if(row==0x0d)return 8;
        if(row==0x0b)return 9;
        if(row==0x07)return 10;
        return 16;
    }
    PORTB=0Xdf;
	delay_us(100);
	row=PINB & 0X0f;
	if(row!=0x0f){
        if(row==0x0e)return 4;
        if(row==0x0d)return 5;
        if(row==0x0b)return 6;
        if(row==0x07)return 11;
        return 16;
    }
    PORTB=0Xbf;
	delay_us(100);
	row=PINB & 0X0f;
	if(row!=0x0f){
        if(row==0x0e)return 1;
        if(row==0x0d)return 2;
        if(row==0x0b)return 3;
        if(row==0x07)return 12;
        return 16;
    }
    PORTB=0X7f;
	delay_us(100);
	row=PINB & 0X0f;
	if(row!=0x0f){
        if(row==0x0e)return 15;
        if(row==0x0d)return 0;
        if(row==0x0b)return 14;
        if(row==0x07)return 13;
        return 16;
    }
	return 16;
}
//----------------------------------------
//flash char		KeyPadCode[16]={0xd7,0xee,0xde,0xbe,0xed,0xdd,0xbd,0xeb,0xdb,0xbb,0x7e,0x7d,0x7b,0x77,0xb7,0xe7};
//flash char		KeyPadCode[]={0xd7,0xeb,0xbb,0x7e,0xed,0xdd,0xbd,0xee,0xde,0xbe,0x7e,0x7d,0x7b,0x77,0xb7,0xe7};
//---------------------------------
//char    getkeycode(void){
//int     i=0;  
//char		row,clumn;
//    DDRB=0XF0;
//    PORTB=0X0F;
//	delay_us(1000);
//	row=PINB & 0X0F;
//	if(row==0x0f)return 16;
//	delay_ms(200);
//	row=PINB & 0X0F;
//	if(row==0x0f)return 16;
//    DDRB=0X0F;
//    PORTB=0XF0;
//	delay_us(1000);
//	clumn=PINB & 0XF0;
//	if(clumn==0xf0)return 16;
//	delay_ms(200);
//	clumn=PINB & 0XF0;
//	if(clumn==0xf0)return 16;
//	row=clumn + row;
//	for (i=0;i<16;i++)
//	{
//		if(row==KeyPadCode[i])return i;
//	}
//	return 16;
//}
//----------------------------------------
