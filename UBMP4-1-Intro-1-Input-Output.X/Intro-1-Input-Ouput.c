/*==============================================================================
Project: Intro-1-Input-Output
Date:    March 1, 2022
This example UBMP4.1 input and output program demonstrates pushbutton input,
LED (bit) output, port latch (byte) output, time delay functions, and simple
'if' condition structures.
Additional program analysis and programming activities demonstrate byte output,
logical condition operators AND and OR, using delay functions to create sound,
and simulated start-stop button functionality.
==============================================================================*/
#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions
#include    "UBMP410.h"         // Include UBMP4.1 constant and function definitions
// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.
// The main function is required, and the program begins executing from here.
int main(void)
{
 // Configure oscillator and I/O ports. These functions run once at start-up.
 OSC_config();               // Configure internal oscillator for 48 MHz
 UBMP4_config();             // Configure on-board UBMP4 I/O devices
  
  // Code in this while loop runs repeatedly.
 while(1)
  {
    

     // If SW2 is pressed, make a flashy light pattern
 


     // Add code for your Program Analysis and Programming Activities here:
    
     // Activate bootloader if SW1 is pressed.
     if(SW1 == 0)
     {
         RESET();
     }
  }
 }


/* Learn More - Program Analysis Activities
*
* 1. How many times do the LEDs flash if SW2 is quickly pressed and released?
*    Do the LEDs keep flashing when SW2 is held? Look at the program and
*    explain why this happens when SW2 is held.
*
The LED's flash once in a clockwise pattern if SW2 is quickly pressed and released.
However, when SW2 is held the pattern continues to flow until the button is released because it is a loop.
The loop consists of each LED lighting up in a row with a delay between each LED, then turning off.
* 
2. Explain the difference between the statements: LED3 = 0; and LED3 = 1;
* 
The difference between the statements LED3 = 0 and LED3 = 1 is that when LED3 = 0, the LED does not flash/is off, but when LED3 = 1 it commands the LED to flash.
*
 3. What voltage do you expect the microcontroller to output to LED D3 when
*    the statement LED3 = 0; runs? What voltage do you expect the output to be
*    when the statement LED3 = 1; runs?
* 
When LED3 = 0, I expect the microcontroller to ouput 0 volts because it is assigning the LED to not flash,
but when LED3 = 1 I expect the microcontroller to output 1-2 volts.
*    You can confirm the output voltage with a voltmeter if you have access
*    to one. If you tried that, did the voltage match your prediction?
* 
The voltage did match my prediction of 1-2 volts, since the output voltage was approximately 2 volts.
* 
4. The statement 'if(SW2 == 0)' uses two equal signs, while the statement
*    'LED3 = 1;' uses a single equal sign. What operation is performed by one
*    equal sign? What operation is performed by two equal signs?
*
The operation performed by one equal sign is giving it a desired value, such as 0 or 1. In contrast, two equal signs is a conditional operation that will run only when SW2 is 0.
*
5. The following program code includes instructions that write to the PORTC
*    output latches directly. Try it by copying and pasting this code below
*    the existing SW2 'if' structure, at the location shown by the comment.
     if(SW3 == 0)
     {
         LATC = 0b00000000;
         __delay_ms(100);
         LATC = 0b11110000;
         __delay_ms(100);
     }
*    What happens when pushbutton SW3 is pressed? Identify at least one
*    advantage and one disadvantage of controlling the LEDs using 'LATC' writes
*    rather than through individual 'LEDn = x;' statements.
*
One disadvantage of controlling the LED's using LATC writes is that it is more difficult to read and understand when first viewed, rather than referring to assigning each LED strict values by using LEDx = ' '.
However, an advantage is that it provides better control over what commands it assigns, which allows better control over the states of the LED's. 
This is accomplished by actually having the ability to set LATC bits to specific values. 
* 
6. Next, compare the operation of 'if' and 'while' structures to simulate
*    momentary buttons. Replace the code you added in 5, above, with this code:
     // Momentary button using if structure
     if(SW3 == 0)
     {
         LED4 = 1;
     }
     else
     {
         LED4 = 0;
     }
     // Momentary button using while structure
     while(SW4 == 0)
     {
         LED5 = 1;
     }
     LED5 = 0;
*    First, try pressing and releasing SW3 and SW4 one at a time.
*
*    Next, press and hold SW3 while pressing and releasing SW4. Does it work
*    as expected?
* 
Yes, it does work as expected because both work one at a time without any other button being pressed. Additionally, holding SW3 while pressing SW4 also works because SW3 is an if statement,
so it allows SW4 to work.
*    
    Next, try press and holding SW4 while pressing and releasing SW3. Does it
*    work as expected? Explain the difference in operation between the 'if' and
*    'while' structures making up the momentary button code.
*
Yes, it also works as expected because SW3 will not flash since SW4 is a while loop which will run until it is released. It does not allow another code to be run simultaneously.
If statements are simply conditional operations that can run while also allowing another operation like SW4 to run, but SW4 is a continous running operation.
*
7. Let's explore logical conditions using 'if' statements. Replace the code
*    added in 6, above, with this nested if code to make a logical AND
*    condition that will light LED D4 only if both SW3 and SW4 are pressed:
     // Nested if 'AND' code
     if(SW3 == 0)
     {
         if(SW4 == 0)
         {
             LED4 = 1;
         }
         else
         {
             LED4 = 0;
         }
     }
     else
     {
         LED4 = 0;
     }
*    Test the code to ensure it works as expected. Does the order of the if
*    conditions matter? (eg. swap the conditional checks for SW3 and SW4)
* 
It does work as expected, but the order of the if conditions does matter because the first version is a nested code which only runs when SW3 == 0,
but if the "if" conditions are swapped, the first code will run first.
*
8. Next, replace the code from 7 with the following code which implements a
*    logical AND conditional operator composed of two ampersands '&&':
     // Conditional 'AND' code
     if(SW3 == 0 && SW4 == 0)
     {
         LED4 = 1;
     }
     else
     {
         LED4 = 0;
     }
*    Does '&&' work the same way as the nested if structures? Can you think of
*    at least one advantage of using a logical conditional operator instead of
*    nested if structures?
*
The '&&' does work as expected because both the nested if structure and logical operator only work when both SW3 and SW4 is pressed.
One advantage of using a logical conditional operator is that it is much simpler to write and read because it is only one condtion rather than multiple 'if' and 'else' operations.
Plus, we are able to create more complicated condtions with logical operations by implementing several parameters or implementing it with 'if' and 'else' statements.
 
* 9. Replace the double ampersand '&&' with double vertical bars '||)' to make
*    a logical OR conditional operator. Your code should look like this:
      // Conditional 'OR' code
     if(SW3 == 0 || SW4 == 0)
     {
         LED4 = 1;
     }
     else
     {
         LED4 = 0;
     }
*    Describe the conditions under which LED4 turns on.
*
The conditions in which LED4 turns on is when either SW3 or SW4 is pressed or when both are pressed at once. Thus, it can work in three ways.
*
* Programming Activities
*
* 1. The statement '__delay_ms(100);' creates a 100ms delay. Try changing one
*    or more of the delay values in the program to 500ms and see what happens.
*
*    Can the delay be made even longer? Try 1000 ms. How big can the delay be
*    before MPLAB-X produces an error message? (Hint: can you think of a fast
*    and efficient way of guessing an unknown number?)

Yes, the delay can be made even longer since it is supported up to a 4205ms(4.205s) delay.
*
The delay can be made longer because the maxium delay the board allows is
* 2. The '__delay_ms();' function only accepts integers as delay values. To
*    make delays shorter than 1ms, specify a delay in microseconds using the
*    '__delay_us();' function. You won't be able to see such short LED flashes
*    with your eyes, but you could measure them using an oscilloscope, or hear
*    them if they are used to turn the piezo beeper on and off. Try this code:
     // Make a tone while SW5 is held
     if(SW5 == 0)
     { 
         BEEPER = 1;
         __delay_us(567);
         BEEPER = 0;
         __delay_us(567);
     }
//test code
     if(SW4 == 0)
     {
         BEEPER = 1;
         __delay_us(169);
         BEEPER = 0;
         __delay_us(315);
     }
//test code
     if(SW3 == 0)
     {
         BEEPER = 1;
         __delay_us(890);
         BEEPER = 0;
         __delay_us(987);
     }
*    Try changing the delay values in both of the __delay_us(); functions.
*    Does the pitch of the tone increase or decrease if the delay value is
*    made smaller?
*
If the delay value is made smaller, the pitch increases and if the delay value is mader larger, the pitch decreases.

* 3. This code demonstrates a more compact way of toggling the beeper output
*    using a logical NOT operator '!'. Replace the code above, with this code:
     // Make a tone while SW5 is held
     if(SW5 == 0)
     {
         BEEPER = !BEEPER;
         __delay_us(567);
     }
*    One difference between this code and the code in 2, above, is the state
*    of the BEEPER pin when SW5 is released. What state will the BEEPER output
*    be in after this code runs? While one advantage of this method is smaller
*    code, can you think of one or more disadvantages based on its output when
*    the button is released?

One or more disadvantages based on its output is that it is difficult to control the value/status of the BEEPER. 
It is much simpler and easier to control the status of the BEEPER by setting it to = 0 or = 1, because it strictly sets the beeper to a desired value.
*
* 4. Using modified versions of the original SW2 'if' structure, create a
*    program that makes a unique LED flashing pattern for each pushbutton.
*
*    Test each of your flashing patterns. Describe what happens when more than
*    one button is held. Do all of the patterns try to flash the LEDs at the
*    same time, or sequentially? Explain why this is.
        
The LED's will flash in a way that matches the code sequentially because the code is read from top to bottom. It depends on which button is pressed first. 
For example, if held SW2, SW3, and SW4 at the same time but press SW3 first, it will complete the assignments of the button then run sequentially in the top to bottom order. 
LED4 first, then LED5, and LED3, then and sequentially from LED3 to LED4 to LED5.

if(SW2 == 0)
     {
         LED3 = 1;
         __delay_ms(3700);
         LED3 = 0;
         __delay_ms(2300);
         LED3 = 1;
         __delay_ms(2600);
         LED3 = 0;
         __delay_ms(2400);
         LED3 = 1;
         __delay_ms(1500);
         LED3 = 0;
         __delay_ms(2500);
         LED3 = 1;
         __delay_ms(400);
         LED3 = 0;
         __delay_ms(2600);
         LED3 = 1;
         __delay_ms(30);
         LED3 = 0;
         __delay_ms(2700);
     }
 
 if(SW3 == 0)
     {
         LED4 = 1;
         __delay_ms(100);
         LED4 = 0;
         __delay_ms(150);
         LED4 = 1;
         __delay_ms(150);
         LED4 = 0;
         __delay_ms(100);
         LED4 = 1;
         __delay_ms(150);
         LED4 = 0;
         __delay_ms(25);
         LED4 = 1;
         __delay_ms(200);
         LED4 = 0;
         __delay_ms(75);
         LED4 = 1;
         __delay_ms(75);
         LED4 = 0;
         __delay_ms(100);
          LED4 = 1;
         __delay_ms(100);
         LED4 = 0;
         __delay_ms(75);
          LED4 = 1;
         __delay_ms(150);
         LED4 = 0;
         __delay_ms(100);
          LED4 = 1;
         __delay_ms(125);
         LED4 = 0;
         __delay_ms(25);
     }
       if(SW4 == 0)
     {
         LED5 = 1;
         __delay_ms(50);
         LED5 = 0;
         __delay_ms(400);
         LED5 = 1;
         __delay_ms(100);
         LED5 = 0;
         __delay_ms(350);
         LED5 = 1;
         __delay_ms(150);
         LED5 = 0;
         __delay_ms(300);
         LED5 = 1;
         __delay_ms(200);
         LED5 = 0;
         __delay_ms(800);
     }

       if(SW5 == 0)
     {
         LED6 = 1;
         __delay_ms(50);
         LED6 = 0;
         __delay_ms(50);
         LED6 = 1;
         __delay_ms(75);
         LED6 = 0;
         __delay_ms(25);
         LED6 = 1;
         __delay_ms(200);
         LED6 = 0;
         __delay_ms(50);
         LED6 = 1;
         __delay_ms(150);
         LED6 = 0;
         __delay_ms(50);
         LED6 = 1;
         __delay_ms(125);
         LED6 = 0;
         __delay_ms(75);
         LED6 = 1;
         __delay_ms(175);
         LED6 = 0;
         __delay_ms(300);
     }
       
*
* 5. Create a program that makes a different tone for each pushbutton.
*    if(SW2 == 0)
     {
         BEEPER = 1;
         __delay_us(68);
         BEEPER = 0;
         __delay_us(886);
     }

     if(SW3 == 0)
     {
         BEEPER = !BEEPER;
         __delay_us(100);
     }

     if(SW4 == 0)
     {
         BEEPER = !BEEPER;
         __delay_us(260);
         BEEPER = !BEEPER;
         __delay_us(520);
     }

     if(SW5 == 0)
     {
         BEEPER = 1;
         __delay_us(768);
         BEEPER = 0;
         __delay_us(999);
     }
*    Test each tone by pressing each button individually. Next, press two or
*    more buttons at the same time. Describe what the tone waveform would look
*    like when more than one button is held.

When more than one button is held, the pitch decreases each time a new button is held. The waveform would like a small number of long and short waves within an image, 
rather than several short and tall waves by a high pitch.
*
* 6. Use individual 'if' structures to simulate 'Start' and 'Stop' buttons for
*    an industrial machine. LED D4 should turn on when SW3 is pressed, stay on
*    even after SW3 is released, and turn off when SW4 is pressed. Test your
*    program to make sure it works.
if(SW3 == 0)
     {
         LED4 = 1;
     }
if(SW4 == 0)
     {
         LED4 = 0;
     }
 
* 7. Running your program from 6, above, describe what happens when both SW3
*    and SW4 are pressed. Does LED D4 stay on? If so, how does the brightness
*    of LED D4 compare between its normal on state following SW3 being pressed
*    to this new state when both SW3 and SW4 are bing held? Can you explain
*    why it changes?

The brightness of the LED changes because the code is attempting to run two operations at once that are still functioning. 
However, the SW4 operation somewhat cancels out the SW3 operation because SW4 is to turn off the LED4. Thus, it dims the light.
*
* 8. As you can imagine, an industrial machine that is able to turn on even
*    while its 'Stop' button is pressed represents a significant safety hazard.
*    Using a logical conditional operator, modify the start-stop program from
*    activity 5 to make it safer. SW3 should only turn on LED D4 if SW4 is
*    released.

    if(SW3 == 0 && SW4 == 1)
     {
         LED4 = 1;
     }
    else{
        LED4 = 0;
    }
*
* 9. LED D1 is normally used to indicate that a program is running, but it can
*    be controlled by your program as well. If you take a look at the UBMP4
*    schematic, you will see that LED D1's cathode (or negative) pin is
*    connected to the microcontroller instead of the anode (positive) pin as
*    with the other LEDs. This means that you need to make D1's output a zero
*    to turn D1 on. Try it! Make a program that controls or flashes LED D1.


    if(SW2 == 0 && SW3 == 0 && SW4 == 0 && SW5 == 0){
        LED1 = 0;
         __delay_ms(100);
        LED1 = 1;
        __delay_ms(25);
        LED1 = 0;
        __delay_ms(100);
        LED1 = 1;
        __delay_ms(25);
        LED1 = 0;
        __delay_ms(400);
        LED1 = 1;
        __delay_ms(50);
        LED1 = 0;
        __delay_ms(100);
        LED1 = 1;
        __delay_ms(25);
        LED1 = 0;
        __delay_ms(50);
        LED1 = 1;
        __delay_ms(25);
        LED1 = 0;
        __delay_ms(50);
        LED1 = 1;
        __delay_ms(25);
        LED1 = 0;
        __delay_ms(800);
        LED1 = 1;
        __delay_ms(100);
     }
    }

*/