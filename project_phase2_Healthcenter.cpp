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
#define h1udpport "21368"
#define h2udpport "21468"
#define h3udpport "21568"
#define s1udpport "21668"
#define s2udpport "21768"
#define s3udpport "21868"
#define s4udpport "21968"
#define s5udpport "22068"




using namespace std;


struct hospital_info {
	char hospital_name;
	int d1[2];
	int d2[2];
	int d3[2];
};

struct arr {
	int range[2];
};

//USEd to convet char into int
int ctoi(char c){
	int result;
	switch(c){
		case '0': {result=0;break;}
		case '1': {result=1;break;}
		case '2': {result=2;break;}
		case '3': {result=3;break;}
		case '4': {result=4;break;}
		case '5': {result=5;break;}
		case '6': {result=6;break;}
		case '7': {result=7;break;}
		case '8': {result=8;break;}
		case '9': {result=9;break;}
		//default: {result=10;break;}
	};
	return result;

}

//convert integer into string
string itos(int c){
	string result;
	switch(c){
		case 0: {result="0";break;}
		case 1: {result="1";break;}
		case 2: {result="2";break;}
		case 3: {result="3";break;}
		case 4: {result="4";break;}
		case 5: {result="5";break;}
		case 6: {result="6";break;}
		case 7: {result="7";break;}
		case 8: {result="8";break;}
		case 9: {result="9";break;}
		//default: {result=10;break;}
	};
	return result;

}


struct student{
	int symptom;
	string interest;
};





using namespace std;
#define PORT 6268
int main(int argc, char const* argv[])
{
	map<string, arr> hospital_info;
	int counter;
	struct hospital_info h1, h2, h3;
	int server_fd, new_socket, valread, listen_sd;
	struct sockaddr_in address, servaddr, listen_addre, peer_addr, connect_addr;
	//struct sockaddr ;
	//int opt = 1;
	int addrlen = sizeof(address);
	string temp_str, temp_str2;
	int split, n;
	ifstream file;
	socklen_t listen_add_len, connected_add_len, peer_len;
	char buffer[1024];
	string s;
	//Initialize socket descritor for listening part
	if ((listen_sd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
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
	int loop_counter=0;
	//Begin too receive information from hospital and student
	while (1) {
		loop_counter=loop_counter+1;
		if (loop_counter>=9){
			break;
		}
		//Initialize a new socket for communication
		if ((new_socket = accept(listen_sd, (struct sockaddr*)NULL, NULL)) < 0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}

		//start a new child process to deal with simutaneously task
		int child = fork();
		if (child < 0) {
			perror("fork error");
			return -1;
		}
		
		if (child > 0) {
			close(new_socket);
			continue;
		}


		connected_add_len = sizeof(connect_addr);

		int gsn, numbytes;
		//Get the port number and IP address
		if ((gsn = getsockname(new_socket, (struct sockaddr*)&connect_addr, &connected_add_len)) == -1) {
			perror("getsockname fail");
			return -1;
		}
		if (loop_counter==4 || loop_counter==1)
			cout << "The health center has TCP port " << ntohs(connect_addr.sin_port) << " and IP address " << inet_ntoa(connect_addr.sin_addr) << endl;
		string rec_s;
		//Test whether the data receive process is completed
		if ((numbytes = (recv(new_socket, buffer, 1023, 0))) > 0) {
			rec_s = string(buffer);
			char cstr[rec_s.size() + 1];
			strcpy(cstr, rec_s.c_str());
			char id=cstr[0];
			//distinguish between hospital or student infomation
			if ( id=='A' || id == 'B' || id == 'C') {
				cout << "Received the department list from <Hospital" << cstr[0] << ">" << endl;
				ostringstream path, temp_path;
				//temp_path=cstr[0]+".txt";
				path << cstr[0] << ".txt";
				ofstream  out(path.str().c_str());
				out << rec_s << endl;
				out.close();
				if (loop_counter==3)
					cout<<"End phase 1 for the health center"<<endl;
			}
			else
			{
				
				cout << "health center receive the application from <Student" << cstr[0] << ">" <<endl;
				ostringstream path, temp_path;
				path << "S" << cstr[0] << ".txt";
				ofstream  out(path.str().c_str());
				out << rec_s << endl;
				out.close();
			}

		}
		close(new_socket);
		exit(0);
	}
	sleep(3);
	//cout<<"break out"<<endl;
	


/*

Allocate student to hoospitals   based on their interest and sympotom

*/
	char h[3]={'A', 'B', 'C'};
	char sid[5]={'1','2','3','4','5'};
	int idx=0;
	for (idx=0;idx<3;idx++){
		ostringstream fname;
		fname<<h[idx]<<".txt";
		file.open(fname.str().c_str());
		getline(file, s);	
		char cstr[s.size() + 1];
		strcpy(cstr, s.c_str());
		for (int t=0; t<s.size() + 1;t++){
			if(cstr[t]=='#'){
				string key, s1(1, cstr[t-2]), s2(1, cstr[t-1]);
				key=s1+s2;
				hospital_info[key].range[0]=ctoi(cstr[t+1]);
				if (t+4<s.size()+1){
					if (cstr[t+4]=='0')
						hospital_info[key].range[1]=10;
					else
						hospital_info[key].range[1]=ctoi(cstr[t+3]);
									
				}
				else
				hospital_info[key].range[1]=ctoi(cstr[t+3]);
			}			
			}
		file.close();
	}
	map<int, student> student_info;
	for (idx=0; idx<5; idx++){
		ostringstream sfname;
		sfname<<"S"<<sid[idx]<<".txt";
		//cout<<sfname<<endl;
		file.open(sfname.str().c_str());
		getline(file, s);
		char cstr[s.size() + 1];
		strcpy(cstr, s.c_str());
		//for (int position=0; position<s.size();position++){ cout<<cstr[position]<<endl;}
		int skey;
		skey=idx+1;
		student_info[skey].interest="";
		if (cstr[10]=='I')
			student_info[skey].symptom=ctoi(cstr[9]);
		else
			student_info[skey].symptom=10;
		for (int position=10; position<s.size();position++){
			if (cstr[position]==':'){
				//cout<<"don"<<endl;
				string ts1(1, cstr[position+1]), ts2(1,cstr[position+2]);
				student_info[skey].interest=student_info[skey].interest+ts1+ts2;
				//student_info[skey].interest=student_info[skey].interest+"qqqqqqqq";
			}
		file.close();	
		}
	}
	





	/*

	health center sends back information Under UDP protocal		
			

	*/	
	//int usockfd;
	struct addrinfo hints, *uservinfo,*p;
	int rv;
	int unumbyte;
	struct sockaddr_in uconnect_addr;
	socklen_t uconnect_len;
	map<int, string> udp_port;
	udp_port[6]=h1udpport;
	udp_port[7]=h2udpport;
	udp_port[8]=h3udpport;
	udp_port[1]=s1udpport;
	udp_port[2]=s2udpport;
	udp_port[3]=s3udpport;
	udp_port[4]=s4udpport;
	udp_port[5]=s5udpport;

	map<int, string> udp_info;
	udp_info[1]="";
	udp_info[2]="";
	udp_info[3]="";
	udp_info[4]="";
	udp_info[5]="";
	udp_info[6]="";
	udp_info[7]="";
	udp_info[8]="";

	map<int, string> ntoh;
	ntoh[6]="A";
	ntoh[7]="B";
	ntoh[8]="C";

	map<string, int> stoh;
	stoh["A"]=6;
	stoh["B"]=7;
	stoh["C"]=8;

	




	//Prepare the information that is required to send back to hoospital and students
	for (int i=1; i<6;i++){
		string info=student_info[i].interest;
		int ssize=info.length();
		int bad_counter=0;
		for (int j=0; j<ssize/2;j++){
			string candi_depart=info.substr(j*2,2);
		
			if (hospital_info.count(candi_depart)<=0){
				bad_counter=bad_counter+1;
				if (bad_counter==ssize/2){
					udp_info[i]=udp_info[i]+"0";
					break;
		
				}
				continue;					
			}
			int low=hospital_info[candi_depart].range[0];
			int high=hospital_info[candi_depart].range[1];
			if ((student_info[i].symptom>=low) && (student_info[i].symptom<=high)){
				//cout<<i<<low<<high<<endl;
				udp_info[i]=udp_info[i]+candi_depart;
				string ihospital=candi_depart.substr(0,1), istring=itos(i), isymptom=itos(student_info[i].symptom);
				string idepart=candi_depart.substr(1,1);
				int hos_index=stoh[ihospital];
				//udp_info[hos_index+5]=udp_info[hos_index+5]+"Student"+istring+"#"+isymptom+"#"+idepart;
				udp_info[hos_index]=udp_info[hos_index]+ihospital+idepart+isymptom+"#"+istring;
				//udp_info[hos_index]=udp_info[hos_index]+"1234";
				break;		
			}
			
		}
		
	
	}
	
	




/*

Use UDP to send information back to hospital and student

*/


	memset(&hints, 0, sizeof hints);
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_DGRAM; 
	int usockfd;

	for (int order=1; order<9; order++){
		//Gett the port number and IP address for udp communicattion
		if ((rv = getaddrinfo("localhost", udp_port[order].c_str(), &hints, &uservinfo)) != 0) {
			fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
			return 1;
			}
// loop through all the results and make a socket
		for(p = uservinfo; p != NULL; p = p->ai_next) {
			if ((usockfd = socket(p->ai_family, p->ai_socktype,p->ai_protocol)) == -1) {
				perror("talker: socket");
				continue;
				}
				break;
				}
			if (p == NULL) {
			fprintf(stderr, "talker: failed to bind socket\n");
			return 2;
			}

		uconnect_len= sizeof(uconnect_addr);
		int gsn, numbytes;
		
		int info_size=udp_info[order].length();
		
		//Determine which information should be sent

		if (info_size==0 && order<=5){
			udp_info[order]=udp_info[order]+"Rejection";		
			}

		if (info_size==0 && order>5){
			string temp_string="No student to accept";
			if ((numbytes = sendto(usockfd, temp_string.c_str(), 1023, 0,
			p->ai_addr, p->ai_addrlen)) == -1) {
				perror("talker: sendto");
				exit(1);
			}
			continue;
		}
		

		//Check  whether the required informaation is sent successfully or not
		if ((numbytes = sendto(usockfd, udp_info[order].c_str(), 1023, 0,
			p->ai_addr, p->ai_addrlen)) == -1) {
				perror("talker: sendto");
				exit(1);
			}
		if (order<=5)
			{
								
			if ((gsn = getsockname(usockfd, (struct sockaddr*)&connect_addr, &uconnect_len)) == -1) {
				perror("getsockname fail");
				return -1;
			}

		cout << "The health center has UDP port " << ntohs(connect_addr.sin_port) << " and IP address " << "127.0.0.1 "<< "for Phase 2"<<endl;

				cout<<"The health center has send the application result to <Student"<<order<<">"<<endl;
				//If the hospital have no student to accept, the message below will not be accepted
				if (udp_info[order].length()<4)
					cout<<"The health center has send one admitted student to <Hospital"<<udp_info[order].substr(0,1)<<">"<<endl;
			}
		
		
		freeaddrinfo(uservinfo);
		//printf("talker: sent %d bytes to %s\n", numbytes, argv[1]);
		close(usockfd);


	

	

	}



	return 0;
}
