#include "client.h"
int main(int argc,char**argv)
{
    int server_fifo_fd;
    int client_fifo_fd;
    struct message msg;
    char client_fifo[256];
    
    server_fifo_fd = open(SERVER_FIFO_NAME,O_WRONLY);
	if(server_fifo_fd==-1)
	{
		fprintf(stderr,"sorry no server\n");
		return EXIT_FAILURE;
	}
	msg.client_pid=getpid();
	sprintf(client_fifo,CLIENT_FIFO_NAME,msg.client_pid);
	if(mkfifo(client_fifo,0777)==-1)
	{
		fprintf(stderr,"sorry ,can not make %s\n",client_fifo);
		return EXIT_FAILURE;
	}
	sprintf(msg.data,"hello world");
	printf("%d send %s\n",msg.client_pid,msg.data);
	write(server_fifo_fd,&msg,sizeof(msg));
	client_fifo_fd = open(client_fifo,O_RDONLY);
	if(client_fifo_fd!=-1)
	{
		if(read(client_fifo_fd,&msg,sizeof(msg))>0)
		{
			printf("receive :%d :%s\n",msg.client_pid,msg.data);
		}
		close(client_fifo_fd);
	}
	
	close(server_fifo_fd);
	unlink(client_fifo);
	return EXIT_SUCCESS;
}

