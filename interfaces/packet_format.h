#ifndef PACKET_FORMAT_H
#define PACKET_FORMAT_H

#include <stdint.h>

#define SCIENCE_PACKET_SIZE 550
#define HEALTH_PACKET_SIZE 128

typedef struct {
    uint16_t packet_id;
    uint32_t timestamp;
    uint8_t payload_data[522];
    uint16_t checksum;
} SciencePacket_t;

typedef struct {
    uint16_t packet_id;
    uint32_t timestamp;
    float battery_voltage;
    float battery_current;
    float temperature;
    uint8_t system_mode;
    uint16_t checksum;
} HealthPacket_t;

#endif
