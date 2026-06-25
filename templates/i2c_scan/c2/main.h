// System Headers
#include "string.h"
#include "stdio.h"
#include "libgcc.h"

// System Configuration
#include "generated/autoconf.h"

// Components headers
#include "hal_gpio.h"
#include "hal_i2c.h"
#include "hal_sys_uart.h"

#define PSRAM_SCKL_FREQ_MHZ (CONFIG_CPU_FREQ_MHZ / CONFIG_PSRAM_NUM)
