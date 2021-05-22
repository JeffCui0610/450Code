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
#include<map>
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
	string d1, d2, d3;
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


	//Read  massage from corresponding file

	ifstream file3;
	string s3;
	file3.open("Student1.txt");

	string s_send3;
	s_send3 = "";

	while (getline(file3, s3))
	{
		s_send3 = s_send3 + s3;
	}
	file3.close();
	s_send3 = "1" + s_send3;



	//Get conneection from remote server


	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

	//Get the port number and IP address

	if ((gsn = getsockname(sock, (struct sockaddr*)&client_addr, &client_addr_len)) == -1) {
		perror("getsockname fail");
		return -1;
	}
	cout << "<Student1> has TCP port " << ntohs(client_addr.sin_port) << " and IP address " << inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer)) << endl;
	//cout << "<Student1> is now conncted to the admission office" << endl;
	strcpy(buffer, s_send3.c_str());
	if ((numbyte = (send(sock, buffer, 1023, 0))) > 0) {
		cout<<"Completed sending application for <Student1>"<<endl;
	}


	sleep(2);//////////////////////////////////////////////////////////////////////////////////////////////////////////

	//The code structure is similar as above, so no more further repeated comment

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	file3.open("Student2.txt");


	s_send3 = "";

	while (getline(file3, s3))
	{
		s_send3 = s_send3 + s3;
	}
	file3.close();
	s_send3 = "2" + s_send3;

	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	if ((gsn = getsockname(sock, (struct sockaddr*)&client_addr, &client_addr_len)) == -1) {
		perror("getsockname fail");
		return -1;
	}
	cout << "<Student2> has TCP port " << ntohs(client_addr.sin_port) << " and IP address " << inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer)) << endl;
	strcpy(buffer, s_send3.c_str());
	if ((numbyte = (send(sock, buffer, 1023, 0))) > 0) {
		cout<<"Completed sending application for <Student2>"<<endl;
	}
	sleep(2);//////////////////////////////////////////////////////////////////////////////////////////////////////////
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);


	file3.open("Student3.txt");

	s_send3 = "";

	while (getline(file3, s3))
	{
		s_send3 = s_send3 + s3;
	}
	file3.close();
	s_send3 = "3" + s_send3;

	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	if ((gsn = getsockname(sock, (struct sockaddr*)&client_addr, &client_addr_len)) == -1) {
		perror("getsockname fail");
		return -1;
	}
	cout << "<Student3> has TCP port " << ntohs(client_addr.sin_port) << " and IP address " << inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer)) << endl;
	strcpy(buffer, s_send3.c_str());
	if ((numbyte = (send(sock, buffer, 1023, 0))) > 0) {
		cout<<"Completed sending application for <Student3>"<<endl;
	}
	sleep(2);//////////////////////////////////////////////////////////////////////////////////////////////////////////
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);


	file3.open("Student4.txt");


	s_send3 = "";

	while (getline(file3, s3))
	{
		s_send3 = s_send3 + s3;
	}
	file3.close();
	s_send3 = "4" + s_send3;

	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	if ((gsn = getsockname(sock, (struct sockaddr*)&client_addr, &client_addr_len)) == -1) {
		perror("getsockname fail");
		return -1;
	}
	cout << "<Student4> has TCP port " << ntohs(client_addr.sin_port) << " and IP address " << inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer)) << endl;
	strcpy(buffer, s_send3.c_str());
	if ((numbyte = (send(sock, buffer, 1023, 0))) > 0) {
		cout<<"Completed sending application for <Student4>"<<endl;
	}
	sleep(2);//////////////////////////////////////////////////////////////////////////////////////////////////////////
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);


	file3.open("Student5.txt");


	s_send3 = "";

	while (getline(file3, s3))
	{
		s_send3 = s_send3 + s3;
	}
	file3.close();
	s_send3 = "5" + s_send3;

	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	if ((gsn = getsockname(sock, (struct sockaddr*)&client_addr, &client_addr_len)) == -1) {
		perror("getsockname fail");
		return -1;
	}
	cout << "<Student5> has TCP port " << ntohs(client_addr.sin_port) << " and IP address " << inet_ntop(AF_INET, &client_addr.sin_addr, buffer, sizeof(buffer)) << endl;
	strcpy(buffer, s_send3.c_str());
	if ((numbyte = (send(sock, buffer, 1023, 0))) > 0) {
		cout<<"Completed sending application for <Student5>"<<endl;
	}

	
	





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

	The below the receiving part waiting for UDP receive


*/

	map<int, string> udp_port;
	udp_port[1]=s1udpport;
	udp_port[2]=s2udpport;
	udp_port[3]=s3udpport;
	udp_port[4]=s4udpport;
	udp_port[5]=s5udpport;

	
	int index=0;

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


	//Start child process to desl with multiple task at the same time

	int uchild;
	if (index<=4)
		uchild = fork();
	if (uchild < 0) {
		perror("fork error");
		return -1;
	}
	if (index>=6){
		break;
	}

	if (uchild > 0 && index<=4) {
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
	//Check whether the received massage is valid
	uaddr_len = sizeof utheir_addr;
	if ((unumbytes = recvfrom(usockfd, buf,1023 , 0,
	(struct sockaddr *)&utheir_addr, &uaddr_len)) == -1) {
	perror("recvfrom");
	exit(1);
	}
	string received=string(buf);
	cout<<"<Student"<<index<<">"<<"has received the reply from the health center"<<endl;
	cout<<"<Student"<<index<<">"<<"has UDP port "<<udp_port[index]<<" and IP address 127.0.0.1 for Phase 2"<<endl;
	cout<<"<Student"<<index<<">"<<"has received the application result, the result is: "<<received<<endl;
	//cout<<"Received information: "<<received<<endl;
	//cout<<"<Student"<<index<<">"<<"end phase 2"<<endl;

	close(usockfd);
	exit(0);



	
}

sleep(8);
//wait(NULL);










	return 0;
}
