#include "comms_app.h"
#include "uart_driver.h"
#include "packet_format.h"
#include <string.h>

// Buffers / mission data
static char iridium_buffer[256];
static SciencePacket_t science_packet;

// Initialize communications system
void COMMS_Init(void) {
    // Initialize UART ports
    // These are placeholder Linux-style device paths and will be updated later for the actual OBC hardware.
    UART_Init("/dev/ttyS0", 19200);    // Iridium
    UART_Init("/dev/ttyS1", 115200);   // S-band
}

// Create a science packet using the Sentinel Bio+ packet format
void COMMS_Create_SciencePacket(void) {
    science_packet.packet_id = 1;
    science_packet.timestamp = 123456; // Placeholder timestamp

    // Fill payload with dummy science data for now
    for (int i = 0; i < 522; i++) {
        science_packet.payload_data[i] = i % 256;
    }

    // Placeholder checksum
    science_packet.checksum = 0xABCD;
}

// Receive command from Iridium
void COMMS_Receive_Iridium(void) {
    int bytes_read = UART_Read(iridium_buffer, sizeof(iridium_buffer));

    if (bytes_read > 0) {
        // Command received successfully
        // Future work: parse command and route to correct subsystem
    }
}

// Send science packet via S-band
void COMMS_Send_SBand(const SciencePacket_t *packet) {
    UART_Write((const char *)packet);
}

// Send fallback health message via Iridium
void COMMS_Send_Iridium(const char *data) {
    UART_Write(data);
}

// Main execution loop called by OBC scheduler
void COMMS_AppMain(void) {

    COMMS_Init();

    while (1) {

        // Step 1: Receive low-rate commands through Iridium
        COMMS_Receive_Iridium();

        // Step 2: Create science packet from payload data
        COMMS_Create_SciencePacket();

        // Step 3: Prioritize S-band for science data downlink
        COMMS_Send_SBand(&science_packet);

        // Step 4: Future work:
        // - Add pass scheduling
        // - Add packet buffering
        // - Add fallback logic if S-band is unavailable
    }
}
