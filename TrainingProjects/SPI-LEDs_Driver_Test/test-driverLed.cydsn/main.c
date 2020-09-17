/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Clock_1_Start();
    SPI_1_Start();
    //uint16_t dato=0;
    

    for(;;)
    {
        CyDelay(500);
        //dato=0x003F;
        
        /*SPI_1_SpiUartWriteTxData(0);
        CyDelay(1);
        SPI_1_SpiUartWriteTxData(0);
        CyDelay(1);
        SPI_1_SpiUartWriteTxData(1);
        CyDelay(1);
        SPI_1_SpiUartWriteTxData(1);
        CyDelay(1);
        SPI_1_SpiUartWriteTxData(1);
        CyDelay(1);
        SPI_1_SpiUartWriteTxData(1);
        CyDelay(1);
        SPI_1_SpiUartWriteTxData(1);
        CyDelay(1);
        SPI_1_SpiUartWriteTxData(1);
        CyDelay(1);*/
        SPI_1_SpiUartWriteTxData(0b0000000000111111); //'0' literal segun el otro codigo
        //SPI_1_SpiUartWriteTxData(0b1111110000000000); //lo volteo
        //SPI_1_SpiUartWriteTxData(0xFC00); // la vuelta, la paso a hex.
        //0b0000001100110111='A' -> 0b1110110011000000 -> ECC0
        //SPI_1_SpiUartWriteTxData(0xECC0);
        //SPI_1_SpiUartWriteTxData(0b0000001100110111);
        /*if(dato<65535)
            dato++;
        else
            dato=0;
        CyDelay(1);*/
        
        
        LE_Write(1);
        LE_Write(0);
        
        
        CyDelay(500);
        SPI_1_SpiUartWriteTxData(0b0000001100110111); //A
        /*if(dato<65535)
            dato++;
        else
            dato=0;
        CyDelay(1);*/
        
        
        LE_Write(1);
        LE_Write(0);
        
    }
}

/* [] END OF FILE */
