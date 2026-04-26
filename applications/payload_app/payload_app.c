#include "payload_app.h"

void PAYLOAD_Init(void) {
    // Placeholder initialization for payload sensors
}

void PAYLOAD_CollectScienceData(SciencePacket_t *packet) {
    packet->packet_id = 1;
    packet->timestamp = 123456;

    // Placeholder science payload data
    for (int i = 0; i < 522; i++) {
        packet->payload_data[i] = i % 256;
    }

    // Placeholder checksum
    packet->checksum = 0xABCD;
}

void PAYLOAD_AppMain(void) {
    SciencePacket_t science_packet;

    PAYLOAD_Init();

    while (1) {
        PAYLOAD_CollectScienceData(&science_packet);

        // Future work:
        // - Send packet to comms_app
        // - Add real payload UART input
        // - Add radiation/bio sensor data formatting
        // - Add timestamp from OBC clock
    }
}
