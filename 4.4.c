<<<<<<< HEAD
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>	
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>	

=======
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>	
#include <unistd.h>
>>>>>>> f7210cdaad4cf59cb7644c1b387030886dec9465

void func(int socket_desc)
{
	char buff[80];
	int n;
<<<<<<< HEAD


	for (;;) 
	{
		bzero(buff,80);
		read(socket_desc, buff, sizeof(buff));
		printf("From client %s\t To client : ", buff);
		bzero(buff, 80);
		n=0;

		while ((buff[n++] = getchar()) != '\n');
		write(socket_desc, buff, sizeof(buff));
		
		if (strncmp("exit", buff, 4) == 0)
		{
			printf("Server exit...\n");
			break;
=======
	for (;;)
	{
		bzero(buff, sizeof(buff));
		printf("Enter message: ");
		n = 0;
		while ((buff[n++] = getchar()) != '\n');

		write(socket_desc, buff, sizeof(buff));
		bzero(buff, sizeof(buff));
		read(socket_desc, buff, sizeof(buff));
		printf("From Server : %s", buff);
		if ((strncmp(buff, "exit", 4)) == 0)
		{
			printf("Client exit...\n");
		break;
>>>>>>> f7210cdaad4cf59cb7644c1b387030886dec9465
		}
	}
}

<<<<<<< HEAD
int main(int argc, char *argv[])
{
	int socket_desc;

	struct sockaddr_in server, client;
	int conn;
	int len;


	socket_desc = socket (AF_INET , SOCK_STREAM , 0);
	if (socket_desc  == -1)
	{
		printf("Could not create socket...\n");
	}

=======
int main()
{
	int socket_desc, conn;
	struct sockaddr_in server, client; 

	
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket...\n");
		exit(0);
	}
>>>>>>> f7210cdaad4cf59cb7644c1b387030886dec9465
	else
		printf("Socket successfully created...\n");
	bzero(&server, sizeof(server));

	server.sin_family = AF_INET;
	server.sin_port = htons(8888);
<<<<<<< HEAD
	server.sin_addr.s_addr = htonl(INADDR_ANY);


	

	if(( bind(socket_desc, (struct sockaddr *)&server, sizeof(server))) != 0)
	{
		printf("Socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded...\n");
		

	if((listen(socket_desc,5)) != 0)
	{
		printf("Listen failed...\n");
		exit(0);
	} 
	else
		printf("Server listening...\n");
	len = sizeof(client);


	conn = accept(socket_desc, (struct sockaddr *)&client, &len);
	if(conn < 0)
	{
		printf("Server accept failed...\n");
		exit(0);
	}
	else
		printf("Server accept the client...\n");

	func(conn); 

	close(socket_desc);
=======
	server.sin_addr.s_addr = inet_addr("192.168.56.104");

	
	if (connect(socket_desc , (struct sockaddr *)&server, sizeof(server)) !=0)
	{
		printf("Connection with server failed...\n");
		exit(0);
	}

	else
		printf("Connected to the server...\n");

	func(socket_desc);

	
	close(socket_desc);

>>>>>>> f7210cdaad4cf59cb7644c1b387030886dec9465
}
