# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toyMain.elf 

#additional rules for files
toyMain.elf: ${COMMON_OBJECTS} stateMachines.o led.o switches.o buzzer.o p1_interrupt_handler.o wdInterruptHandler.o toyMain.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toyMain.elf
	msp430loader.sh toyMain.elf

clean:
	rm -f *.o *.elf

