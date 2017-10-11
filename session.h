#ifndef _SESSION_H_
#define _SESSION_H_

#include "common.h"

/*
 * 一个会话包括一个服务进程和nobody进程
 */
typedef struct session
{
    //control connection
    int ctrl_fd;
    //command
    char cmdline[MAX_COMMAND_LINE];
    //CMD
    char cmd[MAX_COMMAND];
    //cmd arg value
    char arg[MAX_ARG];
    //父子进程通信通道
    int parent_fd;
    int child_fd;
}session_t;


void begin_session(session_t *psess);

#endif
