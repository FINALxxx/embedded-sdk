#include "log.h"
#include <stdio.h>

int main() {
    // Initialize the logger
    log_init(LOG_DEBUG, "./log/log.ans");

    // Log some messages
    log_debug("This is a debug message.");
    log_info("This is an info message.");
    log_warn("This is a warning message.");
    log_error("This is an error message.");
    log_fatal("This is a fatal error message.");
    // Finalize the logger


    return 0;
}