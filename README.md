# webServer1
Web Server/Client

The program should be compiled by 

$ gcc wServer.c wServer_main.c -o se 

or

$ gcc wServer.c wServer_main.c test_wServer.c -o se

on the server part and

$ gcc conn_tcpClient_main.c -o cl

on the client part


Then the program can be run by entering (sudo maybe needed)

$ ./se 

or

$ ./se --syntax1

or

$ ./se --syntax1 --syntax2

or

$ ./se --syntax1 --syntax2 --syntax3

on the server and 

$ ./cl server-IP-address port-number 

on the client side.


Server syntax can be 

debug 

test

block ip1 ip2

port p

webroot rootdirectory



and the commands which can be send from client to server are:

INFO 

GET /

quit

stop


Example:

Open 2 shells, 1 for the server and 1 for the client.

On the server shell:

$ gcc wServer.c wServer_main.c -o se

$ sudo ./se --debug

or

$ sudo ./se --debug --port 80

or

$ sudo ./se --test --port 80

or

$ sudo ./se --debug --port 80 --block 127.0.0.1 127.0.0.1

or

$ sudo ./se --debug --port 80 --block 192.168.0.2 192.168.0.2

On the client shell:

$ gcc conn_tcpClient_main.c -o cl

$ ./cl 127.0.0.1 80

or

$ ./cl 192.168.0.100 80

The app gets a string from user on the client side. 

It sends the string to the server. 

The server prints the string on the shell and responses back to the client with the same string.

The client prints the received string on the shell.


Entering "quit" on the client side closes the app.
Entering "stop" on the client side closes the connection with that client.