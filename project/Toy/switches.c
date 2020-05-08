#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "led.h"

char switch1_state_down, switch2_state_down, switch3_state_down, switch4_state_down, switch_state_changed;/* effectively boolean */
char led_toggle_speed;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();	/* to initially read the switches */
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  
  


  switch1_state_down = (p2val & SW0) ? 0 : 1; /* 0 when SW1 is up */


  switch2_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW2 is up */


  switch3_state_down = (p2val & SW2) ? 0 : 1; /* 0 when SW3 is up */

      
  switch4_state_down = (p2val & SW3) ? 0 : 1; /* 0 when SW4 is up */
  
 
  if(switch1_state_down){
    switch_state_changed = switch1_state_down;
    led_toggle_speed = 10;
    led_update();
  }
  if(switch2_state_down){
    led_toggle_speed = 25;
    switch_state_changed = switch2_state_down;
    led_update();
  }
  if(switch3_state_down){
    led_toggle_speed = 70;
    switch_state_changed = switch3_state_down;
    led_update();
  }
  if(switch4_state_down){
    led_toggle_speed = 85;
    switch_state_changed = switch4_state_down;
    led_update();
  }

}
