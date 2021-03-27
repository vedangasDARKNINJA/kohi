#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED  1
#define LOG_INFO_ENABLED  1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

//Disable Debug and trace logging for release
#if KRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level
{
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5,
} log_level;


b8 initialize_logging();
void shutdown_logging();

KAPI void log_output(log_level level,const char * format, ...);

// Logs a fatal level message.
#define KFATAL(format, ...) log_output(LOG_LEVEL_FATAL,format,##__VA_ARGS__);

#ifndef KERROR
#define KERROR(format, ...) log_output(LOG_LEVEL_ERROR,format,##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
// if WARN Log level is enabled
#define KWARN(format, ...) log_output(LOG_LEVEL_WARN,format,##__VA_ARGS__);
#else 
// if WARN Log level is disabled
#define KWARN(format, ...)
#endif

#if LOG_INFO_ENABLED == 1
// if INFO Log level is enabled
#define KINFO(format, ...) log_output(LOG_LEVEL_INFO,format,##__VA_ARGS__);
#else 
// if INFO Log level is disabled
#define KINFO(format, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// if DEBUG Log level is enabled
#define KDEBUG(format, ...) log_output(LOG_LEVEL_DEBUG,format,##__VA_ARGS__);
#else 
// if DEBUG Log level is disabled
#define KDEBUG(format, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// if TRACE Log level is enabled
#define KTRACE(format, ...) log_output(LOG_LEVEL_TRACE,format,##__VA_ARGS__);
#else 
// if TRACE Log level is disabled
#define KTRACE(format, ...)
#endif