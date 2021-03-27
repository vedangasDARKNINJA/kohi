#include "logger.h"

// HACK: This is temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "asserts.h"

void report_assertion_failure(const char* expression,const char* message, const char* file, i32 line)
{
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: %s, in file \'%s\', at line %d",expression,message,file,line);
}


b8 initialize_logging()
{
    // TODO: Create Log file
    return TRUE;
}

void shutdown_logging()
{
    // TODO: cleanup logging/write queued entries;
}

void log_output(log_level level,const char * format, ...)
{
    const char *level_strings[6] = {
        "[FATAL]: ",
        "[ERROR]: ",
        "[WARN]: ",
        "[INFO]: ",
        "[DEBUG]: ",
        "[TRACE]: ",
    };

    //b8 is_error = level < 2;

    // HACK: Stack allocated memory for messages.
    char out_message[32000];
    memset(out_message,0,sizeof(out_message));

    __builtin_va_list arg_ptr;
    va_start(arg_ptr,format);
    vsnprintf(out_message,32000,format,arg_ptr);
    va_end(arg_ptr);

    char out_message2[32000];
    sprintf(out_message2,"%s%s\n",level_strings[level],out_message);

    // TODO: Platform specific output
    printf("%s\n",out_message);
}
