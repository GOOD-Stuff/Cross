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
	cout << "|--------- Multiplayer ----------|" << endl;
	cout << "|------------ Menu --------------|" << endl;
	cout << "|------ 1) Connect to Host ------|" << endl;
	cout << "|------ 2) Create a game --------|" << endl;
	cout << "|------ 3) Return back   --------|" << endl;
	cout << "|________________________________|" << endl;
	cout << "You choose: ";

	int menu = 0;
	cin >> menu;
	switch(menu){
	case 1:{
		Connect2Host();
		break;
	}
	case 2:{
		CreateGame();
		break;
	}
	default:
		break;
	}
}

void MultiPlayer::Connect2Host(){

}

void MultiPlayer::CreateGame(){
	const char *signal = "start";
	char tmp_buff[5];
	UdpServ Server;
	int count = 0;
	while(1){
		count = Server.UdpRecvEcho(buff, BUF_SIZE);
		for(int i = 0; i < 5; i++)
			tmp_buff[i] = buff[i];
		if( !( strcmp(tmp_buff, signal) ) ){
			char ip[count - 6];
			printf("Connect is established with ");
			for(int i = 6; i < count - 1; i++){
				ip[i-6] = buff[i];
				printf("%c", ip[i]);
			}
			cout << endl;
			break;
		}
	}


}

MultiPlayer::~MultiPlayer() {
	// TODO Auto-generated destructor stub
}

