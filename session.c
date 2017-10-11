#include "common.h"
#include "session.h"

void begin_session(session_t *psess)
{
    //通信socks,也可用pipe
    int sockfds[2];
    if (socketpair(PF_UNIX, SOCK_STREAM, 0, sockfds) < 0)
    {
        ERR_EXIT("socketpair");
    }
    
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        //ftp service process
        close(sockfds[0]);
        psess->child_fd=sockfds[1];
        handle_child(psess); 
    }
    else
    {
        //nobody process
        close(sockfds[1]);
        psess->parent_fd=sockfds[0];
        handle_parent(psess);
    }
}
