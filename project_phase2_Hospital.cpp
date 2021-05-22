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
#include<map>
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
#define h1udpport "21368"
#define h2udpport "21468"
#define h3udpport "21568"
#define s1udpport "21668"
#define s2udpport "21768"
#define s3udpport "21868"
#define s4udpport "21968"
#define s5udpport "22068"

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

	//Initialize the socket descriptor

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	//Read file from corresponding file


	file.open("HospitalA.txt");
	//assert(file.is_open());
	
	//int counter=0;
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

	

	//Connect to the remote server


	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}


	//obtain the port number and IP address 
	
	if ((gsn=getsockname(sock, (struct sockaddr*)&client_addr, &client_addr_len))==-1){
		perror("getsockname fail");
		return -1;
	}
	cout<<"<Hospital A> has TCP port "<<ntohs(client_addr.sin_port)<<" and IP address "<<inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer))<<" for Phase1"<<endl;
	cout<<"<Hospital A> is now conncted to the health center"<<endl;
	
	
	strcpy(buffer, s_send.c_str());
	if ((numbyte=(send(sock, buffer, 1023, 0)))>0){
		//printf("<HospitalA> has sent %s to the admission office\n", s_send);
		cout<<"<HospitalA> has sent <department> to the health center"<<endl;
	}

	cout<<"Updating the health center is done for <HospitalA>"<<endl;
	cout<<"End of Phase 1 for <HospitalA>"<<endl;


	sleep(2);////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
//The structure of this code is similar as above, so no further repeated comment


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
		cout<<"<HospitalB> has sent <department> to the health center"<<endl;
	}

	cout<<"Updating the health center is done for <HospitalB>"<<endl;

	cout<<"End of Phase 1 for <HospitalB>"<<endl;



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
		cout<<"<HospitalC> has sent <department> to the health center"<<endl;
	}

	cout<<"Updating the health center is done for <HospitalC>"<<endl;
	cout<<"End of Phase 1 for <HospitalC>"<<endl;

	



/*

Begin receiving allocation result from hospital

*/






	map<string, int> stoh;
	stoh["A"]=6;
	stoh["B"]=7;
	stoh["C"]=8;

	map<int, string> udp_port;
	udp_port[6]=h1udpport;
	udp_port[7]=h2udpport;
	udp_port[8]=h3udpport;


	map<int, string> indextoh;
	indextoh[6]="A";
	indextoh[7]="B";
	indextoh[8]="C";


	
	int index=5;

	while(1){

	index=index+1;
	int usockfd;
	struct addrinfo uhints, *uservinfo, *up;
	int urv;
	int unumbytes;
	struct sockaddr_storage utheir_addr;
	char buf[1024];
	socklen_t uaddr_len;
	char s[INET6_ADDRSTRLEN];
	memset(&uhints, 0, sizeof uhints);
	uhints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	uhints.ai_socktype = SOCK_DGRAM;
	uhints.ai_flags = AI_PASSIVE; // use my IP
	if ((urv = getaddrinfo(NULL, udp_port[index].c_str(), &uhints, &uservinfo)) != 0) {
	fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(urv));
	return 1;
	}

	//Start a new child process to  deal with multiple tasks at the same time


	int uchild;
	if (index<=7)
		uchild = fork();
	if (uchild < 0) {
		perror("fork error");
		return -1;
	}
	if (index>=9){
		break;
	}

	if (uchild > 0 && index<=7) {
		//close(new_socket);
		continue;
	}
	// loop through all the results and bind to the first we can
	for(up = uservinfo; up != NULL; up = up->ai_next) {
	if ((usockfd = socket(up->ai_family, up->ai_socktype,
	up->ai_protocol)) == -1) {
	perror("listener: socket");
	continue;
	}
	if (bind(usockfd, up->ai_addr, up->ai_addrlen) == -1) {
	close(usockfd);
	perror("listener: bind");
	continue;
	}
	break;
	}
	if (up == NULL) {
	fprintf(stderr, "listener: failed to bind socket\n");
	return 2;
	}
	freeaddrinfo(uservinfo);
	//printf("listener: waiting to recvfrom...\n");
	uaddr_len = sizeof utheir_addr;


	// Check whether the receive process has a valid process

	if ((unumbytes = recvfrom(usockfd, buf,1023 , 0,
	(struct sockaddr *)&utheir_addr, &uaddr_len)) == -1) {
	perror("recvfrom");
	exit(1);
	}
	string received=string(buf);
	string hospitalname=indextoh[index];
	/*if (buf[0]=='N'){
		cout<<"No student has been admitted to <Hospital"<<hospitalname<<">"<<endl;
	}
	else*/
		
	cout<<"<Hospital"<<hospitalname<<"> has UDP port "<<udp_port[index]<<" and IP address 127.0.0.1 for Phase 2"<<endl;
	//print the student  received
	int nums;
	for(int nums=0; nums<=received.length(); nums++)
	{
		if (buf[nums]=='#')
			cout<<"<Student"<<buf[nums+1]<<">"<<" has been admitted to <Hospital"<<hospitalname<<">"<<endl;
	}


	close(usockfd);
	exit(0);



	
}

sleep(5);
//wait(NULL);

	
	return 0;
}
