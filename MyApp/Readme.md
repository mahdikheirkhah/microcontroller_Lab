Purpose
The MyApp library provides functions for interacting with a 7-segment display and a keypad on an AVR microcontroller. It includes the following functions:

sevensegdisplay_1digit(char digit): Displays a single digit on the 7-segment display.
sevensegdisplay_4digit(char digit[4], char point): Displays four digits on the 7-segment display with an optional decimal point.
getkeycode(void): Reads the key pressed on the keypad and returns its corresponding code.
Usage
Include the header file:

C
#include <MyApp.h>
Use code with caution.

Initialize the hardware:

Configure the necessary pins for the 7-segment display and keypad.
Use the library functions:

Call sevensegdisplay_1digit() or sevensegdisplay_4digit() to display digits on the 7-segment display.
Call getkeycode() to read the pressed key from the keypad.

Example:

#include <io.h>
#include <delay.h>
#include <MyApp.h>

int main(void) {
    char digit[4] = {0, 1, 2, 3};
    char keycode;

    while (1) {
        keycode = getkeycode();
        if (keycode != 16) {
            digit[0] = keycode;
            sevensegdisplay_4digit(digit, 0); // Display 4 digits without a decimal point
        }
    }
}

Notes
The library assumes a specific hardware configuration for the 7-segment display and keypad. You may need to adjust the pin assignments in the library code if your setup is different.
The keypad scanning algorithm is a simple row-column scanning method. If you need more advanced keypad handling, consider using a different algorithm or a specialized keypad driver.
The library uses delay_ms() and delay_us() functions from the delay.h library. Ensure that these functions are implemented correctly for your microcontroller.