#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"


char state = 0;
char toggle_red()		/* always toggle! */
{


  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on = 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  switch(state){
      
  case 1: //state 1
    buzzer_set_period(700);
    green_on = 1;
    red_on = 0;
    state = 1;
    led_update();
    break;

  case 2: // state 2
    buzzer_set_period(600);
    toggle_red();
    state = 2;
    led_update();
    break;
    
  case 3: //state 3
    buzzer_set_period(800);
    toggle_green();
    state = 3;
    led_update();
    break;
    
  case 4: //state 4
    buzzer_set_period(400);
    green_on = 1;
    red_on = 1;
    state = 4;
    led_update();
    break;
  }

}



