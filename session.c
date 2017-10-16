#include "common.h"
#include "session.h"

void begin_session(session_t *psess)
{
    //一个session包括nobody父进程和ftp服务进程,需要把root用户改为nobody用户
    struct passwd *pwd = getpwnam("nobody");
    if (NULL == pwd)
    {
        return;
    }
   
    if (setegid(pwd->pw_gid) < 0) 
    { 
        ERR_EXIT("SETEGID");
    }
    
    if (seteuid(pwd->pw_uid) < 0) 
    { 
        ERR_EXIT("SETEUID");
    }
    

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
        ERR_EXIT("fork");
    }
    if (pid == 0)
    {
        //ftp service process as a child process of a session
        close(sockfds[0]);
        psess->child_fd=sockfds[1];
        handle_child(psess); 
    }
    else
    {
        //nobody process as a parent process of a session
        close(sockfds[1]);
        psess->parent_fd=sockfds[0];
        handle_parent(psess);
    }

}
