#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"

#define I2C_SLAVE_ADDR                  0x50
#define SLAVE_REG_ADDR                  0x00
#define PINS_DIGITAL_OUTPUT             0x00
#define SLAVE_DATA                      0x0F
void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable(); //INTCONbits.GIE = 1 = Enables all active interrupts
    INTERRUPT_PeripheralInterruptEnable(); //INTCONbits.PEIE = 1 = Enables all active peripheral interrupts
    
    uint8_t data = SLAVE_DATA;
    while (1)
    {
//        I2C1_Write1ByteRegister(I2C_SLAVE_ADDR, SLAVE_REG_ADDR, data); //¦b0x00 ¼g 0x0F
        
        if(data == I2C1_Read1ByteRegister(I2C_SLAVE_ADDR, SLAVE_REG_ADDR)){
            RA1=1;
            __delay_ms(5000);
            RA1=0;
            __delay_ms(5000);
        }
        else{
            RA1=1;
            __delay_ms(1000);
            RA1=0;
            __delay_ms(1000);
        }
    }
}