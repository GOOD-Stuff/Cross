/*
 * UdpClient.cpp
 *
 *  Created on: Oct 20, 2016
 *      Author: vldmr
 */

#include "UdpClient.h"

UdpClient::UdpClient() {
	peer_addr_len = sizeof(forward_ip);
	//peer_addr_len1 = sizeof(peer_addr);
	socket_desc   = 0;

}

int UdpClient::UdpSetConnect(const char *IP_addr, int port){
	unsigned long addr = 0;
	memset(&forward_ip, 0, sizeof(forward_ip));
	inet_pton(AF_INET, IP_addr, &addr);
	forward_ip.sin_addr.s_addr = addr;
	forward_ip.sin_port = htons(port);
	forward_ip.sin_family = AF_INET;

	socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if( socket_desc == -1 ){
		fprintf(stderr,"Could create socket, %s\n\r", strerror(errno));
		return 1;
	}
	return 0;
}

int UdpClient::UdpSend(char *buffer, int numb){
	if( sendto( socket_desc, buffer, numb, 0, ( sockaddr *) &forward_ip, peer_addr_len) != numb){
		fprintf(stderr, "Error sending response, %s\n\r", strerror(errno));
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

UdpClient::~UdpClient() {
	// TODO Auto-generated destructor stub
}

