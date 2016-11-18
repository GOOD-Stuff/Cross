/*
 * main.cpp
 *
 *  Created on: Aug 24, 2016
 *      Author: vldmr
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "MultiPlayer.h"
#include "SinglePlayer.h"

using namespace std;

void CleanField(char field[][3], vector<int> *x, vector<int> *y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = ' ';
		}
	}
	x->clear();
	y->clear();
}



int main(int argc, char *argv[]) {
	while(1){
		cout << " ________________________________" << endl;
		cout << "|---------- Cross 0.6v ----------|" << endl;
		cout << "|------------ Menu --------------|" << endl;
		cout << "|------- 1) Singleplayer --------|" << endl;
		cout << "|------- 2) Multiplayer  --------|" << endl;
		cout << "|------- 3) How to play? --------|" << endl;
		cout << "|---  anything) Exit outside  ---|" << endl;
		cout << "|________________________________|" << endl;
		cout << "You choose: ";

		/*
		 * TODO: game for 2 players
		 */

		char menu = 0;
		cin >> menu;
		switch(menu){
		case '1':{
			SinglePlayer SinPlay;
			SinPlay.SingleGame();
			break;
		}
		case '2':{
			MultiPlayer MulPlay;
			break;
		}
		case '3':{
			cout << " ________________________________" << endl;
			cout << "|---------- Cross 0.6v ----------|" << endl;
			cout << "|---------- How to play ---------|" << endl;
			cout << "| First of all insert   \"X\" and  |" << endl;
			cout <<	"| after position (x, y) in range |" << endl;
			cout <<	"| of 0 to 2.                     |" << endl;
			cout << "| For example: X 0 2             |" << endl;
			cout << "| For exit from game, insert:    |" << endl;
			cout <<	"|   \"E\" or                       |" << endl;
			cout <<	"|   \"R\" for restart              |" << endl;
			cout << "|________________________________|" << endl;
			break;
		}
		default:
			return 0;
		}
	}

	return 0;
}

