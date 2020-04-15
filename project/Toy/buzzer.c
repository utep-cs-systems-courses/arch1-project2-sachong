#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

static unsigned int period = 1000;
static signed int rate = 500;	

#define MIN_PERIOD 100
#define MAX_PERIOD 6200

int counter =0;
int wait = 0;
void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */


  
}

  //Song played when Button 1 is pressed
  if(switch1_state_down){
    wait = 60; //wait time between notes
    switch(counter){
    case 0:
      buzzer_set_period(880);//A note
      counter++;
      break;
    case 1:
      buzzer_set_period(587);//D note
      counter++;
      break;
    case 2:
      buzzer_set_period(0);
      counter++;
      break;
    case 3:
      buzzer_set_period(587);
      counter++;
      break;
    case 4:
      buzzer_set_period(880);
      counter++;
      break;
    case 5:
      buzzer_set_period(587);
      counter++;
      break;
    case 6:
      buzzer_set_period(0);
      counter++;
      break;
    case 7:
      buzzer_set_period(587);
      counter++;
      break;
    case 8:
      buzzer_set_period(0);
      counter++;
      break;
    case 9:
      buzzer_set_period(587);
      counter++;
      break;
    case 10:
      buzzer_set_period(523);//C note
      counter++;
      break;
    case 11:
      buzzer_set_period(0);
      counter++;
      break;
    case 12:
      buzzer_set_period(523);
      counter=0;
      break;
      
      
    }

  }
  //Song played when Button 2 is pressed
  else if(switch2_state_down){
    wait = 30;//wait time between notes
    switch(counter){
    case 0:
      buzzer_set_period(523.25);//C note
      counter++;
      break;
	
    case 1:
      buzzer_set_period(698.46);//F note
      counter++;
      break;

    case 2:
      buzzer_set_period(0);
      counter++;
      break;
      
    case 3:
      buzzer_set_period(698.46);
      counter++;
      break;
    
    case 4:
      buzzer_set_period(783.99);//G note
      counter++;
      break;
    
    case 5:
      buzzer_set_period(698.46);
      counter++;
      break;
    
    case 6:
      buzzer_set_period(659.26);//E note
      counter++;
      break;
    
    case 7:
      buzzer_set_period(587.33);//D note
      counter++;
      break;
    
    case 8:
      buzzer_set_period(0);
      counter++;
      break;
    
    case 9:
      buzzer_set_period(587.33);
      counter = 0;
      break;
    }

  }
  //Song played when Button 3 is pressed
   else if(switch3_state_down){
     wait = 40;//wait time between notes
    switch(counter){   
    case 0:
      buzzer_set_period(523);//C note
      counter++;
      break;
    case 1:
      buzzer_set_period(0);
      counter++;
      break;
    case 2:
      buzzer_set_period(523);
      counter++;
      break;
    case 3:
      buzzer_set_period(784);//G note
      counter++;
      break;
    case 4:
      buzzer_set_period(0);
      counter++;
      break;
    case 5:
      buzzer_set_period(784);
      counter++;
      break;
    case 6:
      buzzer_set_period(831);//G# note
      counter++;
      break;
    case 7:
      buzzer_set_period(0);
      counter++;
      break;
    case 8:
      buzzer_set_period(831);
      counter++;
      break;
    case 9:
      buzzer_set_period(784);
      counter=0;
      break;

    }
  }
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}
