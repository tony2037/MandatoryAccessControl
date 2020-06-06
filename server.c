#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

int write_source(char *path, char *source){
    FILE *f = fopen(path, "w");
    fprintf(f, "%s", source);
    fclose(f);
}

int compile(char *input, char *output){
    char command[256];
    memset(command, sizeof(command), 0);
    sprintf(command, "gcc -g %s -o %s", input, output);
    return system(command);
}

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0, n = 0;
    struct sockaddr_in serv_addr; 

    char sendBuff[1025];
    char source[4096];
    time_t ticks; 

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 
    memset(source, 0, sizeof(source));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 10); 

    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 

	if(connfd == -1){
            close(connfd);
            sleep(1);
            continue;
        }

        ticks = time(NULL);
        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
        send(connfd, sendBuff, strlen(sendBuff), 0);
        recv(connfd, source, sizeof(source), 0);
        printf("Recieve:\n %s\n", source);

	write_source("/var/X/ProgramY.c", source);
        compile("/var/X/ProgramY.c", "/var/Y/ProgramY");

        pid_t pid = fork();
        if (pid == 0){
            static char *argv[] = {};
            execv("/var/Y/ProgramY", argv);
            exit(127);
        }

        close(connfd);
        sleep(1);
     }
}
