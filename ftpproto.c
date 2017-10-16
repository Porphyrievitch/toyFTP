#include "ftpproto.h"
#include "sysutil.h"

void handle_child(session_t *psess)
{
    writen(psess->ctrl_fd, "220 toyFTPD 0.01\r\n", strlen("220 toyFTPD 0.01\r\n"));
    int ret;
    while (1)
    {
       	memset(psess->cmdline, 0, sizeof(psess->cmdline));
	memset(psess->cmd, 0, sizeof(psess->cmd));
	memset(psess->arg, 0, sizeof(psess->arg));
        
        //parse FTP command and arguments
        ret = readline(psess->ctrl_fd, psess->cmdline, MAX_COMMAND_LINE);
    }
}
