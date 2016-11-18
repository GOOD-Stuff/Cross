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
	udp_ip_mac();
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


/*
 * @brief  Recognizes ip and mac address
 *
 * @param  none
 *
 * @return none
 */
void UdpServ::udp_ip_mac(void) {
	struct ifreq ifr;
	memset(&ifr, 0, sizeof(ifr));
	strcpy(ifr.ifr_name, "eth0");

	//********* IP Address ***************
	int s = socket(AF_INET, SOCK_DGRAM, 0);
	ioctl(s, SIOCGIFADDR, &ifr);

	struct sockaddr_in *sa = (struct sockaddr_in*)&ifr.ifr_addr;

	ip_address = inet_ntoa(sa->sin_addr);
	char tmp_data[3];
	int k = 0, l = 0;
	for( unsigned int i = 0; i < strlen(ip_address); i++ ){
		if( ip_address[i] != '.' ){
			tmp_data[l] = ip_address[i];
			l++;
		}
		else{
			board_ip_addr[k] = atoi(&tmp_data[0]);
			k++; l = 0;
			memset(tmp_data, 0, 3);
		}
	}
	board_ip_addr[k] = atoi(&tmp_data[0]);

	close(s);
}

int UdpServ::UdpServInit(){
	unsigned long addr = 0;
	int GAME_PORT = 0;
	memset(&forward_ip, 0, sizeof(forward_ip));
	printf("Please, enter port for establish of connect : ");
	scanf("%d", &GAME_PORT);
	inet_pton(AF_INET, ip_address, &addr);
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

