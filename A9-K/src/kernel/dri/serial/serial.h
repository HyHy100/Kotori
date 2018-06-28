#if !defined(SERIALH_)
#define SERIALH_

#include <stdint.h>

#include "../dri_gendef.h"

typedef struct Transmitter {
    uint32_t id;
} Transmitter_t;

PUBLIC void serial_transfer_data(uint32_t id, uint32_t size, const uint32_t* data);

PUBLIC void serial_get_resources(Transmitter_t* transmitters, uint32_t* const size);

PUBLIC void serial_transfer_byte(uint32_t id, unsigned char data);

#endif
