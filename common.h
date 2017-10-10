#ifndef _COMMON_H_
#define _COMMON_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>

#define ERR_EXIT(e)\
    do\
    {\
        perror(e);\
        exit(EXIT_FAILURE);\
    } \
    while(0);

#endif