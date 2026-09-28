#include "socket.h"

int get_socket_all()
{
	int s = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if (s < 0) {
		perror("socket unable to be created");
		return 1;
	}

	return s;
}

void *create_socket_ring_buffer(int socket)
{
	int version = TPACKET_V3;
	if (setsockopt(socket, SOL_PACKET, PACKET_VERSION, &version,
		       sizeof(version)) < 0) {
		perror("failed to set socket version");
		return NULL;
	}

	struct tpacket_req3 req = { 0 };
	req.tp_block_size = 1 * 1024 * 1024;
	req.tp_block_nr = 64;
	req.tp_frame_size = 2048;
	req.tp_frame_nr =
		(req.tp_block_size * req.tp_block_nr) / req.tp_frame_size;
	req.tp_retire_blk_tov = 60;

	size_t ring_size = req.tp_block_size * req.tp_block_nr;
	void *ring_buf = mmap(NULL, ring_size, PROT_READ | PROT_WRITE,
			      MAP_SHARED, socket, 0);
	if (ring_buf == MAP_FAILED) {
		perror("ring buffer failed to map");
		return NULL;
	}

	return ring_buf;
}
