#ifndef _EM_LOG_H_      // 多个文件引用时，不能重复定义
#define _EM_LOG_H_

#include <stdarg.h>
#include <stdio.h>
#include "locker.h"
#include "lst_timer.h"
#include "http_conn.h"

#define OPEN_LOG 1                  // 声明是否打开日志输出
#define LOG_LEVEL LOGLEVEL_INFO     // 声明当前程序的日志等级状态，只输出等级等于或高于该值的内容
#define LOG_SAVE 0                  // 可补充日志保存功能

typedef enum{                       // 日志等级，越往下等级越高
    LOGLEVEL_DEBUG = 0,
    LOGLEVEL_INFO,
    LOGLEVEL_WARN,
    LOGLEVEL_ERROR,
}E_LOGLEVEL;

void EM_log(const int level, const char* fun, const int line, const char *fmt, ...);

// __FUNCTION__ 为常见的宏，无需使用#define自己定义，表示当前的函数是哪个
// __LINE__  为常见的宏，表示当前处于哪一行
#define EMlog(level, fmt...) EM_log(level, __FUNCTION__, __LINE__, fmt) // 宏定义，隐藏形参

#endif