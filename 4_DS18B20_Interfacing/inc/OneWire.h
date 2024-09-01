/*
 * File_Name       :   OneWire.h
 * Author          :   Mohamed Akram JABALLAH
*/


#ifndef ONEWIRE_H_
#define ONEWIRE_H_





#define OneWire_CMD_CONVERTTEMP           0x44
#define OneWire_CMD_RSCRATCHPAD           0xBE
#define OneWire_CMD_WSCRATCHPAD           0x4E
#define OneWire_CMD_CPYSCRATCHPAD         0x48
#define OneWire_CMD_RECEEPROM             0xB8
#define OneWire_CMD_RPWRSUPPLY            0xB4
#define OneWire_CMD_SEARCHROM             0xF0
#define OneWire_CMD_READROM               0x33
#define OneWire_CMD_MATCHROM              0x55
#define OneWire_CMD_SKIPROM               0xCC
#define OneWire_CMD_ALARMSEARCH           0xEC

#define OneWire_PORT                      PORTA
#define OneWire_DDR                       DDRA
#define OneWire_PIN                       PINA
#define OneWire_DQ                        PA0

#define OneWire_INPUT_MODE()              OneWire_DDR  &= ~(1 << OneWire_DQ)
#define OneWire_OUTPUT_MODE()             OneWire_DDR  |=  (1 << OneWire_DQ)
#define OneWire_LOW()                     OneWire_PORT &= ~(1 << OneWire_DQ)
#define OneWire_HIGH()                    OneWire_PORT |=  (1 << OneWire_DQ)


 
uint8_t OneWire_reset (void);
void OneWire_write_bit(uint8_t bit);
void OneWire_write_byte(uint8_t byte);
uint8_t OneWire_read_bit(void);
uint8_t OneWire_read_byte(void);




 
#endif 







