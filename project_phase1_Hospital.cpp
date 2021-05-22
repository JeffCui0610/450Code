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
#include<fstream>
#include<string>
using namespace std;
#define PORT 6268

int main(int argc, char const* argv[])
{
	int sock, valread;
	int gsn, numbyte;
	struct sockaddr_in serv_addr, client_addr;
	char buffer[1024] = { 0 };
	string d1,d2,d3;
	ifstream file;
	string s;
	socklen_t client_addr_len = sizeof(client_addr);
	//Initialize the socket discriptor
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	//Open file
	file.open("HospitalA.txt");

	getline(file,s);
	d1=s;
	getline(file,s);
	d2=s;
	getline(file,s);
	d3=s;
	
	string s_send="";
	s_send=s_send+d1;
	s_send=s_send+d2;
	s_send=s_send+d3;

	//cout<<s_send<<endl;
	file.close();

	

	//connect the hospital to healthcenter server
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	//Get the port number used for TCP
	if ((gsn=getsockname(sock, (struct sockaddr*)&client_addr, &client_addr_len))==-1){
		perror("getsockname fail");
		return -1;
	}
	cout<<"<Hospital A> has TCP port "<<ntohs(client_addr.sin_port)<<" and IP address "<<inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer))<<" for Phase1"<<endl;
	cout<<"<Hospital A> is now conncted to the health center"<<endl;
	
	//Send out the information to healthcenter
	strcpy(buffer, s_send.c_str());
	if ((numbyte=(send(sock, buffer, 1023, 0)))>0){
		//printf("<HospitalA> has sent %s to the admission office\n", s_send);
		cout<<"<HospitalA> has sent "<<"<all departments info>"<<" to the health center"<<endl;
	}

	cout<<"Updating the health center is done for <HospitalA>"<<endl;
	cout<<"End of Phase 1 for <HospitalA>"<<endl;

	
	//The part below has completely the same structure as above, so there is no further comment
	sleep(2);////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	


	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	ifstream file2;
	string s2;
	file2.open("HospitalB.txt");
	//assert(file.is_open());
	
	//int counter=0;
	getline(file2,s2);
	d1=s2;
	getline(file2,s2);
	d2=s2;
	getline(file2,s2);
	d3=s2;
	string s_send2;
	s_send2="";
	s_send2=s_send2+d1;
	s_send2=s_send2+d2;
	s_send2=s_send2+d3;
	file2.close();
	//cout<<s_send2<<endl;

	


	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	
	if ((gsn=getsockname(sock, (struct sockaddr*)&client_addr, &client_addr_len))==-1){
		perror("getsockname fail");
		return -1;
	}
	cout<<"<Hospital B> has TCP port "<<ntohs(client_addr.sin_port)<<" and IP address "<<inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer))<<" for Phase1"<<endl;
	cout<<"<Hospital B> is now conncted to the health center"<<endl;
	
	
	strcpy(buffer, s_send2.c_str());
	if ((numbyte=(send(sock, buffer, 1023, 0)))>0){
		//printf("<HospitalA> has sent %s to the admission office\n", s_send);
		cout<<"<HospitalB> has sent "<<"<all departments info>"<<" to the health center"<<endl;
	}

	cout<<"Updating the health center is done for <HospitalB>"<<endl;
	cout<<"End Phase 1 for <HospitalB>"<<endl;





	sleep(2);////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	


	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	ifstream file3;
	string s3;
	file3.open("HospitalC.txt");
	//assert(file.is_open());
	
	//int counter=0;
	getline(file3,s3);
	d1=s3;
	getline(file3,s3);
	d2=s3;
	getline(file3,s3);
	d3=s3;
	string s_send3;
	s_send3="";
	s_send3=s_send3+d1;
	s_send3=s_send3+d2;
	s_send3=s_send3+d3;
	file3.close();
	//cout<<s_send3<<endl;

	


	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	
	if ((gsn=getsockname(sock, (struct sockaddr*)&client_addr, &client_addr_len))==-1){
		perror("getsockname fail");
		return -1;
	}
	cout<<"<Hospital C> has TCP port "<<ntohs(client_addr.sin_port)<<" and IP address "<<inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer))<<" for Phase1"<<endl;
	cout<<"<Hospital C> is now conncted to the health center"<<endl;
	
	
	strcpy(buffer, s_send3.c_str());
	if ((numbyte=(send(sock, buffer, 1023, 0)))>0){
		//printf("<HospitalA> has sent %s to the admission office\n", s_send);
		cout<<"<HospitalC> has sent "<<"<all departments info>"<<" to the health center"<<endl;
	}

	cout<<"Updating the health center is done for <HospitalC>"<<endl;
	cout<<"End of Phase 1 for <HospitalC>"<<endl;

	
	return 0;
}
