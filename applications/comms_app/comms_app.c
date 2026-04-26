#include "comms_app.h"
#include <uart_driver.h>
#include <string.h>

// Buffers
static char iridium_buffer[256];
static char sband_buffer[1024];

// Initialize communications system
void COMMS_Init(void) {
    // Initialize UART ports

    // Example ports (you will change later based on hardware)
    UART_Init("/dev/ttyS0", 19200);   // Iridium
    UART_Init("/dev/ttyS1", 115200);  // S-band
}

// Receive command from Iridium
void COMMS_Receive_Iridium(void) {
    int bytes_read = UART_Read(iridium_buffer, sizeof(iridium_buffer));

    if (bytes_read > 0) {
        // Command received successfully
    }
}
// Send data via S-band
void COMMS_Send_SBand(const char *data) {
    UART_Write(data);
}

// Send fallback via Iridium
void COMMS_Send_Iridium(const char *data) {
    UART_Write(data);
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
