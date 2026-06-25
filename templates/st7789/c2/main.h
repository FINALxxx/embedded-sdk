// System Headers
#include "string.h"
#include "stdio.h"
#include "libgcc.h"

// System Configuration
#include "generated/autoconf.h"

// Components headers
#include "hal_gpio_type.h"
#include "hal_qspi.h"
#include "hal_sys_uart.h"

// Device headers
#include "st7789.h"

#define PSRAM_SCKL_FREQ_MHZ (CONFIG_CPU_FREQ_MHZ / CONFIG_PSRAM_NUM)
