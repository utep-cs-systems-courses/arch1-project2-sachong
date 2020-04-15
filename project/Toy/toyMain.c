#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h" /* for setPeriod */
#include "led.h" /* for led_control() */
#include "switches.h"

void main (void) {
  configureClocks(); 
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();	/* enable wd timer */
  or_sr(0x18);		/* CPU off, GIE on */
}
    
