/*
===============================================================================
 Name        : MyLPC812.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/
#ifdef __USE_CMSIS
#include "LPC8xx.h"
#endif

// TODO: insert other include files here
#include "main.h"


// TODO: insert other definitions and declarations here
#define	I2C_EXPANDER_SLAVE	0x77
#define	I2C_COLOR_SLAVE		0x2A
#define I2C_ACCEL_SLAVE		0x6A
#define I2C_ATMPRE			0x90

volatile uint8_t I2CMasterTXBuffer[I2C_BUFSIZE];
volatile uint8_t I2CMasterRXBuffer[I2C_BUFSIZE];
volatile uint8_t I2CSlaveTXBuffer[I2C_BUFSIZE];
volatile uint8_t I2CSlaveRXBuffer[I2C_BUFSIZE];
volatile uint32_t I2CMonBuffer[I2C_MONBUFSIZE];

int ticker=0;

void SwitchMatrix_Init()
{
    /* Enable SWM clock */
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);

    /* Pin Assign 8 bit Configuration */
    /* U0_TXD */
    /* U0_RXD */
    LPC_SWM->PINASSIGN0 = 0xffff0908UL;
    /* CTOUT_0 */
    LPC_SWM->PINASSIGN6 = 0x11ffffffUL;
    /* CTOUT_1 */
    /* I2C0_SDA */
    LPC_SWM->PINASSIGN7 = 0x0fffff0dUL;
    /* I2C0_SCL */
    LPC_SWM->PINASSIGN8 = 0xffffff01UL;

    /* Pin Assign 1 bit Configuration */
    /* SWCLK */
    /* SWDIO */
    /* RESET */
    LPC_SWM->PINENABLE0 = 0xffffffb3UL;
}

void Init_I2C(void)
{
	int i;

	/* Enable I2C clock */
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<5);
	/* Toggle peripheral reset control to I2C, a "1" bring it out of reset. */
	LPC_SYSCON->PRESETCTRL &= ~(0x1<<6);
	LPC_SYSCON->PRESETCTRL |= (0x1<<6);
	I2C_MstInit(LPC_I2C, I2C_FMODE_PRE_DIV, CFG_MSTENA, 0x00);

	for ( i = 0; i < I2C_BUFSIZE; i++ )
	{
		I2CMasterTXBuffer[i] = 0;
		I2CMasterRXBuffer[i] = 0;
		I2CSlaveTXBuffer[i] = 0;
		I2CSlaveRXBuffer[i] = 0;
	}

}

void Init_UART(void)
{
	UARTInit(LPC_USART0, UART0_BAUDRATE);
#ifdef DEBUG_UART0
	UARTSend(LPC_USART0, (uint8_t *)"Hello World!\r\n", 14);
#endif
}

void UARTSend_str (uint8_t *BufferPtr, int len){

	UARTSend(LPC_USART0, BufferPtr, len);
}

void Init_GPIO(void)
{
	/* Enable GPIO clock */
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);

	GPIOSetDir( 0, 0, 1 );	//motor_io2
//	GPIOSetDir( 0, 1, 1 );	//I2C_SCL
//	GPIOSetDir( 0, 2, 1 );	//SWDIO
//	GPIOSetDir( 0, 3, 1 );	//SWCLK
//	GPIOSetDir( 0, 4, 1 );	//RESET
//	GPIOSetDir( 0, 5, 0 );	//io2
	GPIOSetDir( 0, 6, 1 );	//motor_io3
	GPIOSetDir( 0, 7, 1 );	//motor_io1
//	GPIOSetDir( 0, 8, 1 );	//UART_TX
//	GPIOSetDir( 0, 9, 1 );	//UART_RX
//	GPIOSetDir( 0, 10, 1 );	//io4
//	GPIOSetDir( 0, 11, 1 );	//io3
//	GPIOSetDir( 0, 12, 1 );	//io1
//	GPIOSetDir( 0, 13, 1 );	//motor_pwm2	CTOUT_1
	GPIOSetDir( 0, 14, 1 );	//motor_io4
//	GPIOSetDir( 0, 15, 1 );	//I2C_SDA
	GPIOSetDir( 0, 16, 0 );	//board switch
//	GPIOSetDir( 0, 17, 1 );	//motor_pwm1 	CTOUT_0
}
void Init_SCT(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 8); /* enable the SCT clock   */

	/* set pre-scalar, SCT clock = 1 MHz, clear counter*/
	LPC_SCT->CTRL_L |= (((SystemCoreClock/1000000-1) << 5) | (1<<3));

	sct_fsm_init();                       /* Initialize SCT */

	LPC_SCT->CTRL_L &= ~(1<<2);
}

void SysTick_Handler(void)
{
	ticker++;
}

int main(void)
{
	uint8_t str[50];
	int strlen;

	SystemCoreClockUpdate();
	SysTick_Config( SYSTICK_DELAY );

	Init_GPIO();
	Init_UART();
//	Init_I2C();
	Init_SCT();

	while(1){

		if(ticker>100){

			ticker =  0;
			if(GPIOGetPinValue(0,16) == 0){
				sct_fsm_reload_Match1_a(300);
				sct_fsm_reload_Match2_a(700);
				strlen = sprintf(str,"hello!\n\r");
			}else{
				sct_fsm_reload_Match1_a(700);
				sct_fsm_reload_Match2_a(300);
				strlen = sprintf(str,"world!\n\r");
			}
			UARTSend_str(str, strlen);

		}//ticker>xxx

	}//while(1)

	return 0;

}//main

