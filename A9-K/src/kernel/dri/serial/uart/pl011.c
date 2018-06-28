#include "pl011.h"
//
#define DRIVER_WRAP_CALL PRIVATE

#define _UART0_ADDRESS ((volatile uint32_t*)0x10009000)

#define _UART_NUMBER 1

PRIVATE volatile uint32_t* const transmitters[_UART_NUMBER] = {
    _UART0_ADDRESS
};


void _serial_transfer_data(uint32_t id, uint32_t size, const uint32_t* data) {
    if (id >= _UART_NUMBER) {
        return;
    }

    for(; size > 0; size--) {
        *(transmitters[id]) = *(data++);
    }
}

void _serial_get_resources(Transmitter_t* dest, uint32_t* const size) {
    if (!dest) {
        *size = _UART_NUMBER;
        return;
    }

    for (uint32_t i = 0; i < *size; i++) {
        dest[i].id = i;
    }
}

void _serial_transfer_byte(uint32_t id, unsigned char byte) {
    if (id >= _UART_NUMBER) {
        return ;
    }

    *(transmitters[id]) = byte;
}

void pl011start() {
    apicalls.write = &_serial_transfer_data;
    apicalls.get_resources = &_serial_get_resources;
    apicalls.write_byte = &_serial_transfer_byte;
}
