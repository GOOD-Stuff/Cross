/*
 * SinglePlayer.h
 *
 *  Created on: Aug 25, 2016
 *      Author: vldmr
 */

#ifndef SINGLEPLAYER_H_
#define SINGLEPLAYER_H_

#include <vector>
#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

class SinglePlayer {
public:
	SinglePlayer();
	void SingleGame();
	virtual ~SinglePlayer();
private:
	vector<int> history_x;
	vector<int> history_y;
	char field[3][3];
	char symbol;
	string username;
	int who;
	int x, y;
	int count;
	int win;
	int count_win_X;
	int count_win_O;
	void CleanField(char field[][3], vector<int> *x, vector<int> *y);
	int Check(char field[][3], vector<int> *x, vector<int> *y);
};

#endif /* SINGLEPLAYER_H_ */
