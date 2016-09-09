/*
 * SinglePlayer.cpp
 *
 *  Created on: Aug 25, 2016
 *      Author: vldmr
 */

#include "SinglePlayer.h"

SinglePlayer::SinglePlayer() {
	x = 0, y = 0;
	CleanField(field, &history_x, &history_y);
	srand(time(NULL));
	who = rand() % 2;
	if (who)
		username = "player";
	else
		username = "computer";

	count = 0; // count steps of game
	win = 0;
	count_win_X = 0;
	count_win_O = 0;

}

void SinglePlayer::CleanField(char field[][3], vector<int> *x, vector<int> *y){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = ' ';
		}
	}
	x->clear();
	y->clear();
}

void SinglePlayer::SingleGame(){
	cout << "\nAnd the game starts the " << username << endl;
	cout << "Ready, stady, GO!\n" << endl;

		while (1) {
			if (who > 0) {
				cout << "Your turn ";
				cin >> symbol;
				if ((symbol == 'E') || (symbol == 'e'))
					break;
				else if (symbol == 'R') {
					CleanField(field, &history_x, &history_y);
					symbol = 'X';
					count = 0;
				}
				cin >> x >> y;
			} else {
				x = rand() % 3;
				y = rand() % 3;
				symbol = 'O';
			}
			if (!(history_x.empty()) && !(history_y.empty())) {
				vector<int>::iterator it_x = history_x.begin();
				vector<int>::iterator it_y = history_y.begin();
				while (it_x != history_x.end() && it_y != history_y.end()) {
					while ((*it_x == x) && (*it_y == y)) {
						if (who) {
							cout << "It was, please insert other ";
							cin >> x >> y;
						} else {
							x = rand() % 3;
							y = rand() % 3;
						}
						it_x = history_x.begin();
						it_y = history_y.begin();
					}
					it_x++;
					it_y++;
				}
			}
			history_x.push_back(x);
			history_y.push_back(y);
			field[x][y] = symbol;
			cout << " 0" << "\t" << "1#" << "\t" << "2#" << endl;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cout << i << field[i][j] << "\t";
				}
				cout << endl;
			}

			count++;

			if (count >= 5) {
				win = Check(field, &history_x, &history_y);
				if (win == 1) {
					cout << "*** WIN X! ***" << endl;
					CleanField(field, &history_x, &history_y);
					count = 0;
					count_win_X++;
				} else if (win == 2) {
					cout << "*** WIN O! ***" << endl;
					CleanField(field, &history_x, &history_y);
					count = 0;
					count_win_O++;
				}
			}
			if( count == 9 ){
				cout << "*** DRAW! ***" << endl;
				CleanField(field, &history_x, &history_y);
				count = 0;
			}
			win = 0;
			cout << "\nWins: X = " << count_win_X << " | " << "O = " << count_win_O << endl;
			who = who == 0 ? 1 : 0;
			username = who == 0 ? "computer" : "player";
			cout << "\n**** the " << username << " ****" << endl;
		}
		cout << "I was glad to see you. Goodbye!" << endl;
}

int SinglePlayer::Check(char field[][3], vector<int> *x, vector<int> *y) {
	int start_x = 0;
	int start_o = 0;
	int countX = 0;
	int countO = 0;
	int vert_X = 0;
	int vert_O = 0;
	int zX, zO;
	int yX, yO;
	zX = zO = 0;
	yX = yO = 0;

	for (int i = start_x; i <= 2; i++) {
		for (int j = start_o; j <= 2; j++) {
			if ((field[i][j] == 'X') || (field[i][j] == 'x')) {
				countX++;
				if (i == j)
					zX++;
			} else if ((field[i][j] == 'O') || (field[i][j] == 'o')) {
				countO++;
				if (i == j)
					zO++;
			}

			if (((i == 0) && (j == 2)) || ((i == 1) && (j == 1))
					|| ((i == 2) && (j == 0))) {
				if ((field[i][j] == 'X') || (field[i][j] == 'x'))
					yX++;
				else if ((field[i][j] == 'O') || (field[i][j] == 'o'))
					yO++;
			}

			if( ( field[j][i] == 'X' ) || ( field[j][i] == 'x' ) ) {
				vert_X++;
			} else if ( ( field[j][i] == 'O' ) || ( field[j][i] == 'o' ) ) {
				vert_O++;
			}
		}

		if (countX == 3)
			return 1;
		else if (countO == 3)
			return 2;
		else {
			countX = 0;
			countO = 0;
		}

		if( vert_X == 3 )
			return 1;
		else if( vert_O == 3 )
			return 2;
		else {
			vert_X = 0;
			vert_O = 0;
		}

		if (((zX == 2) || (zO == 2)) && (i == 0)) {
			zX--;
			zO--;
		}

		if (zX == 3)
			return 1;
		else if (zO == 3)
			return 2;

		if (yX == 3)
			return 1;
		else if (yO == 3)
			return 2;

	} // end for(i);

	return 0;
}

SinglePlayer::~SinglePlayer() {
	// TODO Auto-generated destructor stub
}

