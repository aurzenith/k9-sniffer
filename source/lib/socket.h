#ifndef SOCKET_H_
#define SOCKET_H_

#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/mman.h>

int get_socket_all();

void *create_socket_ring_buffer(int socket);

#endif
