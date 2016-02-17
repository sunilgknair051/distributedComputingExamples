#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])  {
  int client;  struct sockaddr_in address;    char data;

  client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //Allocate client socket

  memset(&address, 0, sizeof(address));  //Clear socket address
  address.sin_family      = AF_INET;     //IPv4 address
  address.sin_addr.s_addr = inet_addr("127.0.0.1");//Create (loopback) IP address
  address.sin_port        = htons(9998); //Make port in network byte order

  data = 2;
  sendto(client, &data, 1, 0, (struct sockaddr *)&address, sizeof(address)); //(*@\clientBox{1+2)}@*)

  close(client);  //(*@\clientBox{4)}@*)
  return 0;
  }
