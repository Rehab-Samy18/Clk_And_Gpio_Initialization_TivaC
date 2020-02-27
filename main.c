/* First Code in ARM
 * BY : Rehab Samy
 * Date : 8/2/2019
 */

#define REG volatile unsigned long int *

REG RCC = 0x400FE060;
REG RCGCGPIO =  0x400FE608;
REG GPIODIRF =  0x4005D400;
REG GPIOHBCTL = 0x400FE06C;
REG GPIOAFSEL_F = 0x4005D420;
REG GPIODR8R_F = 0x4005D508;
REG GPIODEN_F =  0x4005D51C;
REG GPIODATA_F1 = 0x4005D008;
int main(void)
{
    //The steps required to successfully change the PLL-based system clock
    /* STEP 1 */
    *RCC |= (1<<11);  //SET BYPASS BIT(NO. 11)
    *RCC &= ~(1<<22); //CLEAR USESYS BIT(NO. 22)

    /* STEP 2 */

    *RCC |= (1<<4); //OSCRC BIT(4,5)  ACTIVATING INTERNAL CLOCK
    *RCC &=~(1<<5);

    *RCC &= ~(1<<13);  //CLEAR PWRDN BIT(NO. 13)
  /* ------------------------------------------------------------------------- */

    //The steps required to successfully initialize GPIO
    *GPIOHBCTL |= (1<<5);  //ENABLE AHP FOR PORTF

    *RCGCGPIO |= (1<<5);  //Enable and provide a clock to 16/32-bit general-purpose timer module 5 in Run mode

    *GPIODIRF |= (1<<1);  //PORTF = 1 (OUTPUT)

    *GPIOAFSEL_F &= ~(1<<1); //The associated pin functions as a GPIO and is controlled by the GPIO registers.

    *GPIODR8R_F |= (1<<1); //The corresponding GPIO pin has 8-mA drive

    *GPIODEN_F |= (1<<1);  //The digital functions for the corresponding pin are enabled

    *GPIODATA_F1 = (1<<1);
    return 0;
}

