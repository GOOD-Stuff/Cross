/*
 * UdpServ.cpp
 *
 *  Created on: Aug 25, 2016
 *      Author: vldmr
 */

#include "UdpServ.h"

UdpServ::UdpServ() {
	peer_addr_len = sizeof(struct sockaddr_storage);
	socket_desc   = 0;
	int result = 0;
	int id = 0;
	UdpServInit();
	/*
	pthread_t ServerListen;
	result = pthread_create(&ServerListen, NULL, &UdpServ::helper, this);
	if( result != 0 ){
		perror("Creating the 1 thread");
		exit(EXIT_FAILURE);
	}
	result = pthread_join(ServerListen, NULL);
	if( result != 0 ){
		perror("Join the 1 thread");
		exit(EXIT_FAILURE);
	}
	*/
}

int UdpServ::UdpServInit(){
	unsigned long addr = 0;
	char IP_addr[15];
	memset(&forward_ip, 0, sizeof(forward_ip));
	printf("Please, enter your IP address: ");
	scanf("%s", &IP_addr);
	inet_pton(AF_INET, IP_addr, &addr);
	forward_ip.sin_family = AF_INET;
	forward_ip.sin_port = htons(GAME_PORT);
	forward_ip.sin_addr.s_addr = addr;

	socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if( socket_desc == -1 ){
		fprintf(stderr,"Could create socket, %s\n\r", strerror(errno));
		return EXIT_FAILURE;
	}
	const int optval = 1;
	setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

	// bind socket to port
	if( bind( socket_desc, (sockaddr*)&forward_ip, sizeof(forward_ip) ) != 0){
		fprintf(stderr,"Could not bind, %s\n",strerror(errno));
		return EXIT_FAILURE;
	}

	printf("Start listen on %d\r\n", GAME_PORT);
	return 0;
}

int UdpServ::UdpRecvEcho(char *buff, int buff_size){
	int count = 0;
	memset(buff, 0, buff_size);
	while(1){
		count = recvfrom( socket_desc, buff, buff_size, 0, (sockaddr*)&peer_addr, &peer_addr_len );
		printf("%s\r\n", buff);
		if( count == -1)
			continue;
		else
			break;
	}
	UdpSendEcho(buff, count);
	return count;
}

int UdpServ::UdpSendEcho(char *buff, int n_read){
	if( sendto( socket_desc, buff, n_read, 0, ( sockaddr *) &peer_addr, peer_addr_len) != n_read){
		fprintf(stderr, "Error sending response, %s\n\r", strerror(errno));
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int UdpServ::UdpSend(char *buffer, int numb){
	if( sendto( socket_desc, buffer, numb, 0, ( sockaddr *) &peer_addr, peer_addr_len) != numb){
		fprintf(stderr, "Error sending response, %s\n\r", strerror(errno));
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

UdpServ::~UdpServ() {
	// TODO Auto-generated destructor stub
}

