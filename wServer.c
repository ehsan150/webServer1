/***********************************************************************
 * Copyright (C) 2011 Seyed Ehsan Mohajerani
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *********************************************************************
 * @file wServer.c
 * @brief header file for the server file of the web server project
 * @author: Seyed Ehsan Mohajerani
 * @Released: July 15 2011
 * @Last Updated: August 15 2011
 * http://shoe.bocks.com/net/
 * http://www.pythonprasanna.com/Papers%20and%20Articles/Sockets/udpserver.c
 * Application Note C/C++ Coding Standard Quantum Leaps, LLC
 * 
 * Run with./se --syntax1 --syntax2 --syntax3 
 * @Application Note C/C++ Coding Standard Quantum Leaps, LLC
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <errno.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/types.h>/*For create socket*/
#include <sys/socket.h>/*For create socket and binding and connection*/
#include <netinet/in.h>/*For binding*/
#include <netdb.h>/*For converting a hostname into a network address*/
#include <unistd.h>/*For closing connections*/
#include "wServer.h"

#define BUF_SIZE 1024/*A 1k buffer*/
#define BACKLOG_QUEUE 5/*Number of pending connection*/
#define DEFAULT_PORT 80/* Defining default port*/

/* Global Variables*/
int my_socket;/*For starting a socket*/
int bind_chk;/*For binding a socket*/
int listen_chk;/*For listening socket*/
int reuse_chk;/*For reusing connection*/
int accept_chk;/*For accepting connection*/
int address_len;/*Argument to accept*/
int debug_indicator=0;/*Indicator for debug printing mode*/
int test_indicator=0;/*Indicator for test printing mode*/
int port_number=DEFAULT_PORT;/*Port and the default value for it*/
char received_data;/*Recieving variable*/
char blocked_IP_1[16];/*Blocked IP 1*/
char blocked_IP_2[16];/*Blocked IP 2*/
char root_dir[100];/*Root Dir*/
/*structs*/
struct sockaddr_in server_address;/*server*/
struct sockaddr_in client_address;/*client*/

/* Starting a socket*/
int socket_start(void){
	/* Creating an address family, TCP */
	my_socket= socket(AF_INET,SOCK_STREAM,0);
	/* test if the socket created successfully*/
	if (my_socket<0 ) {
		perror("Error creating socket");
		return -1;
	}
	printf (" Socket created \n");
	return 0;
}

/*Binding port Defined to the created socket*/
int socket_bind(){
	/* Type of created socket */
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	/* Set the PORT */
	server_address.sin_port = htons(port_number);
	/* Bind the PORT */
	bind_chk= bind(my_socket,(struct sockaddr *)
	&server_address,sizeof(struct sockaddr));
	/* Check if the binding were done successfully*/
	if (bind_chk<0 ){
		perror("Error binding socket");
		exit(EXIT_FAILURE);
	}
	printf (" %s %d %s", "Port", port_number, "is Bound to the socket  \n");
	return 0;
}

/*Listening for connections*/
int socket_listen(void){
	listen_chk= listen(my_socket, BACKLOG_QUEUE);
	/* Check if the listening were done successfully*/
	if (listen_chk<0 ){
		perror("Error listening socket");
		exit(EXIT_FAILURE);
	}
	printf (" %s ", "Listening for connection  \n");
	return 0;
}

/*Accept connection*/
int accept_connection(void){
	accept_chk= accept(my_socket, (struct sockaddr *)
	&client_address, &address_len);
	/* Check if the accept were done successfully*/
	if (accept_chk<0 ){
		perror("Error accepting socket");
		exit(EXIT_FAILURE);
		}
	printf (" %s ", "Connection accpeted  \n");
	return 0;
}

/*Recieving data ,Starting the Server*/
void communication(void){
	/*Buffer for recieving data*/
	char *buffer=malloc(BUF_SIZE);
	/*start receiving*/
	while(1){
		received_data = recv(accept_chk,buffer,BUF_SIZE,0);
		buffer[received_data]= '\0';
		/*Closing socket and free memory on quit command*/
		if (strstr(buffer,"quit") != NULL){
			close(my_socket);
			close(accept_chk);
			printf(" %s ", "Closing server\n");
			free (buffer);
			break;
		}

		else{
		    if (strstr(buffer,"stop") != NULL){
                    			close(my_socket);
                    			//close(accept_chk);
                    			printf(" %s ", "Closing connection\n");
                    			socket_start();
                    			//socket_bind();
                            	//socket_listen();
                            	//accept_connection();
                    		}

			/*Printing debug message*/
			if (debug_indicator==1){
			printf("Received message from client is %s\n", buffer);
			}
			/*Printing test message*/
			else if (test_indicator==1){
            			printf("Test received message from client is %s\n", buffer);
            			}
			/*Checking command and replace with reply*/
			command_control(buffer);
			send(accept_chk,buffer,strlen(buffer),0);
		}


	}
}
/*Control syntax receivnig from the command line*/
void syntax_control(int count,char** input_syntax){
	/*Loop for checking the syntax*/
	int i=0;
	for (i ; i < count;i++){
		if (strcmp(input_syntax[i], "--debug") == 0){
			debug_indicator=1;
			/*Printing debug message*/
			printf ("\n Debug indicator is on \n");
		}
		else if (strcmp(input_syntax[i], "--test") == 0){
        			test_indicator=1;
        			start_test();
        			/*Printing test message*/
        			printf ("\n Test indicator is on \n");
        		}
		else if (strcmp(input_syntax[i], "--port") == 0){
				port_number=atoi(input_syntax[i+1]);
		}
		else if (strcmp(input_syntax[i], "--block") == 0){
				strcpy(blocked_IP_1,input_syntax[i+1]);
				strcpy(blocked_IP_2,input_syntax[i+2]);
		}
		else if (strcmp(input_syntax[i], "--webroot") == 0){
				strcpy(root_dir,input_syntax[i+1]);
		}
	}
	/*Printing debug message*/
	if (debug_indicator==1){
		printf("Blocked IP 1 is %s\n", blocked_IP_1);
		printf("Blocked IP 2 is %s\n", blocked_IP_2);
	}
	/*Printing test message*/
    else if (test_indicator==1){
    		printf("Test blocked IP 1 is %s\n", blocked_IP_1);
    		printf("Test blocked IP 2 is %s\n", blocked_IP_2);
    	}
}

/*Control input receivnig from the client*/
void command_control(char* command){ 
	if (strcmp(command, "INFO") == 0){
		strcpy(command,"Version = 1");
	}
	else if (strcmp(command, "GET /") == 0){
			/*Printing debug message*/
			if (debug_indicator==1){
				printf("GET is received \n");
			}
			file_process(command,root_dir,"index.htm");
	}
}

void file_process(char* command,char* root_dir,char* file_name){
	FILE *file;
	int size_of_file;
		if ((file = fopen(file_name, "r"))==NULL){
		printf("Error Opening File.\n");
		exit(EXIT_FAILURE);
		}
		else {
			fseek(file, 0L, SEEK_END);
			size_of_file= ftell(file);
			fseek(file, 0L, SEEK_SET);
			char read_buffer[size_of_file];
			fread(read_buffer, 1, size_of_file-1, file);
			strcpy(command,read_buffer);
			/*Printing debug message*/
			if (debug_indicator==1){
				printf("File is %s", read_buffer);
			}
		}
	fclose(file);
}
