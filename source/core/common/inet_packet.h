#ifndef INET_PACKET_H_
#define INET_PACKET_H_

#include <cstdint>

#define INET_ADDRESS_SIZE 4

struct inet_packet_details {
  uint8_t header_length;
  uint16_t total_length;
  uint8_t time_to_live;
  uint8_t protocol;
  uint32_t inet_source_addr;
  uint32_t inet_destination_addr;
};

#endif
