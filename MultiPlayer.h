/*
 * MultiPlayer.h
 *
 *  Created on: Aug 25, 2016
 *      Author: vldmr
 */

#ifndef MULTIPLAYER_H_
#define MULTIPLAYER_H_
#include <iostream>
#include "UdpServ.h"
#define BUF_SIZE  1000

using namespace std;

class MultiPlayer {
public:
	MultiPlayer();
	virtual ~MultiPlayer();
private:
	char buff[BUF_SIZE];
	void Connect2Host();
	void CreateGame();
};

#endif /* MULTIPLAYER_H_ */
