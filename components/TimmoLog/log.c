#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "log.h"

static LogLevel g_log_level = LOG_INFO;

// ANSI颜色代码
#define ANSI_COLOR_RESET   "\033[0m"
#define ANSI_COLOR_RED     "\033[31m"
#define ANSI_COLOR_GREEN   "\033[32m"
#define ANSI_COLOR_YELLOW  "\033[33m"
#define ANSI_COLOR_BLUE    "\033[34m"
#define ANSI_COLOR_MAGENTA "\033[35m"
#define ANSI_COLOR_CYAN    "\033[36m"

static const char* log_level_strings[] = {
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"
};

static const char* log_level_colors[] = {
    ANSI_COLOR_BLUE,
    ANSI_COLOR_GREEN,
    ANSI_COLOR_YELLOW,
    ANSI_COLOR_RED,
    ANSI_COLOR_MAGENTA
};

void log_init(LogLevel level, const char* filename) {
    g_log_level = level;
}

void log_close(void) {
}

static void log_print(LogLevel level, const char *format, va_list args) {
    if (level < g_log_level) {
        return;
    }
    printf("%s[%s]:\t%s", log_level_colors[level], log_level_strings[level], ANSI_COLOR_RESET);
    vprintf(format, args);
    printf("\n");
    if (level == LOG_FATAL) {
        while(1);
    }
}

void log_debug(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_print(LOG_DEBUG, format, args);
    va_end(args);
}

void log_info(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_print(LOG_INFO, format, args);
    va_end(args);
}

void log_warn(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_print(LOG_WARN, format, args);
    va_end(args);
}

void log_error(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_print(LOG_ERROR, format, args);
    va_end(args);
}

void log_fatal(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log_print(LOG_FATAL, format, args);
    va_end(args);
}
