#include "log.h"

char *EM_logLevelGet(const int level){  // 得到当前输入等级level的字符串
    if(level == LOGLEVEL_DEBUG){
        return (char*)"DEBUG";
    }else if (level == LOGLEVEL_INFO ){
        return (char*)"INFO";
    }else if (level == LOGLEVEL_WARN ){
        return (char*)"WARN";
    }else if (level == LOGLEVEL_ERROR ){
        return (char*)"ERROR";
    }else{
        return (char*)"UNKNOWN";
    }
    
}

void EM_log(const int level, const char* fun, const int line, const char *fmt, ...){ // 日志输出函数
    //#ifdef OPEN_LOG   此处错误，应使用#if   // 判断开关
    #if OPEN_LOG
    va_list arg;
    va_start(arg, fmt); // 初始化args的函数，使其指向可变参数的第一个参数，fmt是可变参数的前一个参数
    char buf[vsnprintf(NULL, 0, fmt, arg) + 1];     // 创建缓存字符数组  vsnprintf(NULL, 0, fmt, arg)返回arg中字符的个数，不含'\0'
    vsnprintf(buf, sizeof(buf), fmt, arg);          // 赋值 ftm 格式的 arg 到 buf
    va_end(arg);
    if (level >= LOG_LEVEL) {                         // 判断当前日志等级，与程序日志等级状态对比
        printf("[%s]\t[%s %d]: %s \n", EM_logLevelGet(level), fun, line, buf);  // 这里的日志只是指输出到终端
    }
    #if LOG_SAVE
    // 将日志落入磁盘中

    #endif // 0

    #endif // OPEN_LOG
    
}