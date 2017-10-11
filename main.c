#include "common.h"
#include "session.h"

int main()
{
    //必须以root用户启动
    if (0 != getuid())
    {
        fprintf(stderr, "toyFTP:must be started as root\n");
        exit(EXIT_FAILURE);
    }

    session_t sess = {-1, "", "", "", -1, -1};
    int listenfd = tcp_server(NULL, 5188);
    int conn;
    pid_t pid;

    while(1)
    {
        conn = accept_timeout(listenfd, NULL, 0);
        if (-1 == conn)
        {
            ERR_EXIT("accept timeout");
        }

        pid = fork();
        if (-1 == pid)
        {
            ERR_EXIT("fork failed");
        }
        
        if (0 == pid)
        {
            //子进程关闭监听套接字
            close(listenfd);
            sess.ctrl_fd = conn;
            begin_session(&sess); 
        }
        else
        {
            //父进程关闭连接套接字
            close(conn); 
        }
    }
    
    return 0;
}
