/*
 * UdpServ.h
 *
 *  Created on: Aug 25, 2016
 *      Author: vldmr
 */

#ifndef UDPSERV_H_
#define UDPSERV_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#define GAME_PORT 50001


class UdpServ {
public:
	UdpServ();

	int UdpSend(char *buffer, int numb);
	int UdpRecvEcho(char *buff, int buff_size);

	static void *helper(void *classRef){
		((UdpServ *)classRef)->UdpServInit();
		return NULL;
	}

	virtual ~UdpServ();
private:
	int UdpServInit();
	int UdpSendEcho(char *buff, int n_read);
	struct sockaddr_in forward_ip;
	struct sockaddr_storage peer_addr;
	socklen_t peer_addr_len;
	int socket_desc;

};

#endif /* UDPSERV_H_ */
