/*
 * MultiPlayer.cpp
 *
 *  Created on: Aug 25, 2016
 *      Author: vldmr
 */

#include "MultiPlayer.h"

MultiPlayer::MultiPlayer() {
	memset(buff, 0, BUF_SIZE);

	cout << " ________________________________" << endl;
	cout << "|------ Please create your ------|" << endl;
	cout << "|----------- nickname -----------|" << endl;
	printf(": ");
	scanf("%s", &this->nickname);
	cout << "|________________________________|" << endl;

	cout << " ________________________________" << endl;
	cout << "|--------- Multiplayer ----------|" << endl;
	cout << "|------------ Menu --------------|" << endl;
	cout << "|------ 1) Connect to Host ------|" << endl;
	cout << "|------ 2) Create a game --------|" << endl;
	cout << "|------ 3) Hot seat (not yet) ---|" << endl;
	cout << "|---- anything) Return back -----|" << endl;
	cout << "|________________________________|" << endl;
	cout << "You choose: ";

	char menu = 0;
	cin >> menu;
	switch(menu){
	case '1':{
		Connect2Host();
		break;
	}
	case '2':{
		CreateGame();
		break;
	}
	default:
		break;
	}
}

void MultiPlayer::Connect2Host(){
	char IP_addr[15];
	printf("Please, enter IP address to connect: ");
	scanf("%s", &IP_addr);
	printf("U enter: %s\n", IP_addr);
	printf("Please, enter port: ");
	int port = 0;
	scanf("%d", &port);
	UdpClient Client;
	Client.UdpSetConnect(IP_addr, port);
	char buff[BUF_SIZE] = "start ";
	strcat(buff, this->nickname);
	Client.UdpSend(buff, strlen(buff));

}

void MultiPlayer::CreateGame(){
	const char *signall = "start";
	char tmp_buff[6];
	memset(tmp_buff, 0, sizeof(tmp_buff));
	UdpServ Server;
	int count = 0;
	while(1){
		count = Server.UdpRecvEcho(buff, BUF_SIZE);
		memcpy(tmp_buff, buff, 5);
		tmp_buff[5] = '\0';
		if( !( strcmp(tmp_buff, signall) ) ){
			char EnName[count - 6];
			printf("Connect is established with ");
			for(int i = 6; i < count - 1; i++){
				EnName[i-6] = buff[i];
				printf("%c", EnName[i]);
			}
			cout << endl;
//			break;
			printf("First turn from %s", this->nickname);
			Server.UdpSend(this->nickname, strlen(this->nickname));

		}
		else
			printf("%s not equal %s\n", tmp_buff, signall);
	}

}

MultiPlayer::~MultiPlayer() {
	// TODO Auto-generated destructor stub
}

