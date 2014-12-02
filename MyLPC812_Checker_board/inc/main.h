#include <stdio.h>
#include <string.h>
#include <cr_section_macros.h>
#include "lpc8xx_clkconfig.h"
#include "lpc8xx_uart.h"
#include "lpc8xx_gpio.h"
#include "lpc8xx_i2c.h"
#include <LPS331.h>
#include "sct_fsm.h"
#include "sct_user.h"
//#define DEBUG_I2C
#define	DEBUG_UART0
#define UART0_BAUDRATE		115200
#define SYSTICK_DELAY		(SystemCoreClock/1000)
