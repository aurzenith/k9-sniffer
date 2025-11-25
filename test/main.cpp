#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>


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
            // trick read() to load our uint8_t, since it demands a char*
            bin_file.read(reinterpret_cast<char*>(buffer.data()), length);
        } else {
            std::cerr << "No data found, closing.";
        }

    } else {
        std::cerr << "File not found, closing.";
    }
    return buffer;
}




int main(int argv, char** argc) 
{
    std::vector<uint8_t> packet;
    const char* file_name = "../output_raw.bin";

    packet = read_file(file_name);

    for (int i = 0; i < packet.size(); i++) {
        std::cout << packet[i] << std::endl;
    }



    return 0;
}