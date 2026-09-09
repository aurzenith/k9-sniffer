#ifndef INET6_PACKET_H_
#define INET6_PACKET_H_

#include <cstdint>

#define INET6_ADDRESS_SIZE 16

struct inet6_packet_details {
  uint8_t *inet6_source_addr;
  uint8_t *inet6_destination_addr;
};

#endif
