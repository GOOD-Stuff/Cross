/*
 * MultiPlayer.h
 *
 *  Created on: Aug 25, 2016
 *      Author: vldmr
 */

#ifndef MULTIPLAYER_H_
#define MULTIPLAYER_H_
#include <iostream>
#include <vector>
#include "UdpServ.h"
#include "UdpClient.h"
using namespace std;

#define BUF_SIZE  1000
#define NICK_SIZE 100

class MultiPlayer {
public:
	MultiPlayer();
	virtual ~MultiPlayer();
private:
	//***** Fields *****
	vector<int> history_x;
	vector<int> history_y;
	char field[3][3];
	char buff[BUF_SIZE];
	char nickname[NICK_SIZE];
	int x, y;
	int count;
	int win;
	int count_win_X;
	int count_win_O;
	//***** Prototypes *****
	void Connect2Host();
	void CreateGame();
};

#endif /* MULTIPLAYER_H_ */
