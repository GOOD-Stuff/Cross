/*
 * UdpClient.h
 *
 *  Created on: Oct 20, 2016
 *      Author: vldmr
 */

#ifndef UDPCLIENT_H_
#define UDPCLIENT_H_

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

class UdpClient {
public:
	UdpClient();
	int UdpSetConnect(const char *IP_addr, int port);
	int UdpSend(char *buffer, int numb);
	int UdpRecieve(char *buffer);
	int UdpCheck(char *buffer, int size);
	virtual ~UdpClient();
private:
	struct sockaddr_in forward_ip;
	struct sockaddr_storage peer_addr;
	socklen_t peer_addr_len;
	int socket_desc;

};

#endif /* UDPCLIENT_H_ */
