#include <stdio.h>
<<<<<<< HEAD
=======
#include <string.h>
>>>>>>> f7210cdaad4cf59cb7644c1b387030886dec9465
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr

int main(int argc , char *argv[])
{
<<<<<<< HEAD
	int socket_desc , new_socket , c;
	struct sockaddr_in server , client;
=======
	int socket_desc;
	struct sockaddr_in server; 
              char *message, server_reply[2000];
>>>>>>> f7210cdaad4cf59cb7644c1b387030886dec9465
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
<<<<<<< HEAD
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );
	
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("bind failed");
	}
	puts("bind done");
	
	//Listen
	listen(socket_desc , 3);
	
	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (new_socket<0)
	{
		perror("accept failed");
	}
	
	puts("Connection accepted");
=======
		
	server.sin_addr.s_addr = inet_addr("192.168.56.104"); //Please enter the ip address of your Server VM
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );

	//Connect to remote server
	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	
	puts("Connected \n");

	//Send some data
	message = "connect";
	if( send(socket_desc , message , strlen(message) , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");
                    //Receive a reply from the server
	if( recv(socket_desc, server_reply , 2000 , 0) < 0)
	{
		puts("recv failed");
	}
	puts("Reply received\n");
	//puts(server_reply);
>>>>>>> f7210cdaad4cf59cb7644c1b387030886dec9465

	return 0;
}
