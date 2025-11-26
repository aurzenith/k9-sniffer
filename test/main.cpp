// example code for rest of project...
// Kris C 2025-11-23
//

#include <cstdint>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <vector>

#define MAC_ADDRESS_SIZE 6
#define INET_ADDRESS_SIZE 4
#define INET6_ADDRESS_SIZE 16


std::vector<uint8_t> read_file(const char* file_name)
{
    std::fstream bin_file;
    std::vector<uint8_t> buffer;
    uint32_t length = 0;
    if (file_name != nullptr) {
        bin_file.open(file_name, std::fstream::in | std::fstream::binary);
        bin_file.seekg(0, bin_file.end);
        length = bin_file.tellg();
        bin_file.seekg(0, bin_file.beg);

        if (length != 0) {
            buffer.resize(length);
            // trick read() to load our uint8_t, since it demands a char*
            bin_file.read(reinterpret_cast<char*>(buffer.data()), length);
            std::streamsize bytes_read = bin_file.gcount();
            std::cout << bytes_read << std::endl;
        } else {
            std::cerr << "No data found, closing.";
        }

    } else {
        std::cerr << "File not found, closing.";
    }
    return buffer;
}

// first test function
bool type_is_ipv4(std::vector<uint8_t> packet)
{
    bool is_ipv4 = false;
    uint8_t low = 0;
    uint8_t high = 0;

    uint16_t type_field = 0;

    uint32_t skip_to_type = MAC_ADDRESS_SIZE + MAC_ADDRESS_SIZE; 
    // 6 for dest and source to skip forwards starting at 0 - 5 - 11, then start at 12

    // for ipv4 in the ethernet header we should have a value of 0x0800
    high = packet[skip_to_type];
    low = packet[skip_to_type + sizeof(uint8_t)];

    type_field = (uint16_t(high) << 8) | low;

    std::cout << std::hex << type_field << std::endl;

    if (type_field == 0x0800) {
        is_ipv4 = true;
    }
    
    return is_ipv4;
}

uint8_t* get_destination_mac(std::vector<uint8_t> packet)
{
    // 6 bytes for mac address size
    uint8_t mac_address[MAC_ADDRESS_SIZE];




}

struct frame_details {
    uint8_t mac_destination_addr[MAC_ADDRESS_SIZE];
    uint8_t mac_source_addr[MAC_ADDRESS_SIZE];

    uint16_t type_field;
};

struct inet_packet_details {
    uint8_t header_length;
    uint16_t total_length;
    uint8_t time_to_live;
    uint8_t protocol;
    uint32_t inet_source_addr;
    uint32_t inet_destination_addr;
};

struct inet6_packet_details {
    uint8_t inet6_source_addr[INET6_ADDRESS_SIZE];
    uint8_t inet6_destination_addr[INET6_ADDRESS_SIZE];

};




int main(int argv, char** argc) 
{
    std::vector<uint8_t> packet;
    const char* file_name = "../output_raw.bin";

    packet = read_file(file_name);
    for (int i = 0; i < packet.size(); i++)
        std::cout << std::hex << packet[i] << std::endl;

    bool is_ipv4 = type_is_ipv4(packet);
    
    if (is_ipv4 == true){
        std::cout << "true";
    } else {
        std::cout << "false";
    }
    return 0;
}