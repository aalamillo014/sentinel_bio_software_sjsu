#include "comms_app.h"
#include <stdio.h>
#include <string.h>

// Buffers
static char iridium_buffer[256];
static char sband_buffer[1024];

// Initialize communications system
void COMMS_Init(void) {
    // In real system: initialize UART drivers
}

// Receive command from Iridium
void COMMS_Receive_Iridium(void) {
    // Placeholder for UART read
    strcpy(iridium_buffer, "CMD:SET_BEACON:1800");
}

// Send data via S-band
void COMMS_Send_SBand(const char *data) {
    // Placeholder for radio transmit
}

// Send fallback via Iridium
void COMMS_Send_Iridium(const char *data) {
    // Placeholder for Iridium SBD transmit
}

// Main execution loop (called by OBC scheduler)
void COMMS_AppMain(void) {

    COMMS_Init();

    while (1) {

        // Step 1: Receive commands
        COMMS_Receive_Iridium();

        // Step 2: Check if science data exists
        if (strlen(sband_buffer) > 0) {
            COMMS_Send_SBand(sband_buffer);
        }
        else {
            COMMS_Send_Iridium("HEALTH_STATUS_OK");
        }

        // Step 3: Delay / wait (simulated scheduler)
        // In real system: OS sleep or tick-based execution
    }
}
