#if !defined(_APICALLSH_)
#define _APICALLSH_

#include <stdint.h>

#include "../dri_gendef.h"
#include "serial.h"

typedef struct APICalls {
    void (*write)(uint32_t id, uint32_t size, const uint32_t* data);
    void (*get_resources)(Transmitter_t* transmitters, uint32_t* const size);
    void (*write_byte)(uint32_t id, const uint8_t data);
} APICalls_t;

PUBLIC APICalls_t apicalls;

#endif
