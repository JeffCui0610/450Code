#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <errno.h>

#include <string.h>

#include <netdb.h>

#include <sys/types.h>

#include <netinet/in.h>

#include <sys/socket.h>

#include <arpa/inet.h>

#include <sys/wait.h>
#include<iostream>
#include<map>
#include<list>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>





struct hospital_info{
	char hospital_name;
	int d1[2];
	int d2[2];
	int d3[2];
};

struct arr{
	int range[2];
};
		
/*
int stoi1(string s){
	int result;
	switch(s){
		case "0": {result=0;break;}
		case "1": {result=1;break;}
		case "2": {result=2;break;}
		case "3": {result=3;break;}
		case "4": {result=4;break;}
		case "5": {result=5;break;}
		case "6": {result=6;break;}
		case "7": {result=7;break;}
		case "8": {result=8;break;}
		case "9": {result=9;break;}
		case "10": {result=10;break;}
	};
	return result;
	
}
*/




using namespace std;
#define PORT 6268
int main(int argc, char const* argv[])
{
	map<string, arr> A;
	int counter;
	struct hospital_info h1,h2,h3;	
	int server_fd, new_socket, valread, listen_sd;
	struct sockaddr_in address, servaddr, listen_addre,peer_addr, connect_addr;
	//struct sockaddr ;
	//int opt = 1;
	int addrlen = sizeof(address);
	string temp_str, temp_str2;
	int split,n;
	socklen_t listen_add_len, connected_add_len, peer_len;
	char buffer[1024];
	//Initialize the socket descriptor
	if ((listen_sd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	memset(&servaddr, 0, sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 
	if (bind(listen_sd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(listen_sd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	int counterrr=0;

	while (1) {
		counterrr=counterrr+1;
		if ((new_socket = accept(listen_sd, (struct sockaddr *)NULL, NULL)) < 0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
		//Initialize child precess to deal with multiple request
		int child;
		if (counterrr<=2)
			child=fork();
		if (child<0){
			perror("fork error");
			return -1;
		}
		if (child>0 and counterrr<=2){
			close(new_socket);
			continue;
		}
		

		connected_add_len = sizeof(connect_addr);
		
		int gsn, numbytes;
		//Get the port number 
		if ((gsn=getsockname(new_socket, (struct sockaddr*)&connect_addr, &connected_add_len))==-1){
			perror("getsockname fail");
			return -1;
		}
		cout<<"The health center has TCP port "<<ntohs(connect_addr.sin_port)<<" and IP address "<<inet_ntoa(connect_addr.sin_addr)<<endl;
		string rec_s;
		//receive the request and restore the message into a file temporarily
		if ((numbytes=(recv(new_socket, buffer, 1023, 0)))>0){
			rec_s=string(buffer);
			char cstr[rec_s.size()+1];
			strcpy(cstr, rec_s.c_str());
			cout<<"Received the department list from <Hospital"<<cstr[0]<<">"<<endl;
			ostringstream path, temp_path;
			path<<cstr[0]<<".txt";
			ofstream  out(path.str().c_str());
			out<<rec_s<<endl;
			out.close();
			
		
	}
		if (counterrr>2)
			cout<<"End of Phase 1 for the health center"<<endl;
		close(new_socket);
			
		exit(0);
}
		sleep(2);
		
		
		return 0;
	}
