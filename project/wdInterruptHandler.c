#include <msp430.h>
#include "buzzer.h"
#include "led.h"

int wait;



void decisecond() 
{
  static char cnt = 0;		/* # deciseconds/frequecy change */
  if (++cnt > 100) {		
    buzzer_advance_frequency();
    cnt = 0;
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char second_count = 0, decisecond_count = 0;
  if (++second_count == wait) { //leds will change back and forth at the tempo of the song selected
    led_toggle();
    second_count = 0;
  }
 
  if (++decisecond_count == wait){
    buzzer_advance_frequency();
    
    
    decisecond_count = 0;
    
  }
  led_update();
}
