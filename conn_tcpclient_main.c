#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "conn_tcpclient.c"
#include "conn_tcpclient.h"

int main(int argc,char **argv){
  conn_socket_host(argv);
  conn_socket_create();
  conn_socket_binding(argv);
  conn_socket_connection(argv);
  conn_data_passing();
  return 0;
}
