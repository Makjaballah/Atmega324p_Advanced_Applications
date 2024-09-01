PROJECT_NAME = SPI_Master
DEVICE = atmega324p
FRQ = 1000000
SRC = ./src/
LIB = ./inc/
TARGET = main
CC = avr-gcc
OBJCOPY = avr-objcopy
AVR_SIZE = avr-size --format=avr --mcu=$(DEVICE)
CFLAGS = -std=gnu99 -Wall -Os -DF_CPU=$(FRQ) -mmcu=$(DEVICE)


all : $(SRC)
	$(CC) $(CFLAGS) -I $(LIB)  -o $(TARGET).o $(SRC)*.c
	$(CC) $(CFLAGS) -I $(LIB) -o $(TARGET).elf $(SRC)*.c
	$(OBJCOPY) -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex
	$(AVR_SIZE) $(TARGET).elf
	@echo "Succes compiled"
        
clean :
	rm -f *.o *.elf *.hex
	@echo "done"
                   
