#include "serial.h"
#include "apicalls.h"

void serial_transfer_data(uint32_t id, uint32_t size, const uint32_t* data) {
    (*apicalls.write)(id, size, data);
}

void serial_get_resources(Transmitter_t* transmitters, uint32_t* const size) {
    (*apicalls.get_resources)(transmitters, size);
}

void serial_transfer_byte(uint32_t id, unsigned char data) {
    (*apicalls.write_byte)(id, data);
}
