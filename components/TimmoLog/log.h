#ifndef __LOG_H__
#define __LOG_H__

typedef enum {
  LOG_DEBUG,   // 调试信息，最详细
  LOG_INFO,    // 普通信息
  LOG_WARN,    // 警告信息
  LOG_ERROR,   // 错误信息
  LOG_FATAL    // 致命错误，最严重
} LogLevel;

void log_init(LogLevel level, const char* filename);
void log_debug(const char *format, ...);
void log_info(const char *format, ...);
void log_warn(const char *format, ...);
void log_error(const char *format, ...);
void log_fatal(const char *format, ...);
#endif