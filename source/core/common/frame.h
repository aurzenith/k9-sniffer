#ifndef FRAME_H_
#define FRAME_H_

#include <cstdint>

#define MAC_ADDRESS_SIZE 6

struct frame_details {
  uint8_t *mac_destination_addr;
  uint8_t *mac_source_addr;
  uint16_t type_field;
};

#endif
