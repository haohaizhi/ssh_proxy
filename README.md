安装依赖库：yum install libssh-devel



修改用户或者密码：
```
char username[128] = "admin";
char password[128] = "comleader";
```

修改代理程序连接的伪终端（PTY）的进程：
```
//当用户ssh连接到代理服务器时，会使用Telnet中转到ripd监听的2602端口，根据自己的需要进行修改
static int exec_pty(const char *mode, const char *command,
                    struct channel_data_struct *cdata) {\
    printf("pty mode: %s, command: %s \n",mode ,command);
    switch(cdata->pid = fork()) {
        case -1:
            close(cdata->pty_master);
            close(cdata->pty_slave);
            fprintf(stderr, "Failed to fork\n");
            return SSH_ERROR;
        case 0:
            close(cdata->pty_master);
            if (login_tty(cdata->pty_slave) != 0) {
                exit(1);
            }
           // execl("/bin/sh", "sh", mode, command, NULL);
           //  sh mode command
            const char *telnet_path = "/usr/bin/telnet";
            const char *host = "127.0.0.1";
            const char *port = "2602";
            execl(telnet_path, "telnet", host, port, NULL);
            exit(0);
        default:
            close(cdata->pty_slave);
            /* pty fd is bi-directional */
            cdata->child_stdout = cdata->child_stdin = cdata->pty_master;
    }
    return SSH_OK;
}
```

编译：make -B

创建私钥文件：ssh-keygen -t rsa -f /home/sshproxy/rsa_admin_key

使用：
```
./ssh_server -p 8899 127.0.0.1

解释：在IP地址127.0.0.1的8899端口启动SSH代理服务
```

项目参考：[https://github.com/xbmc/libssh](https://github.com/xbmc/libssh)