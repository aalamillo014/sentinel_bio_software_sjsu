#include "beacon_app.h"
#include "uart_driver.h"
#include <stdio.h>

static char health_message[128];

void BEACON_Init(void) {
    // Placeholder initialization for health beaconing
}

void BEACON_CreateHealthMessage(char *buffer, int max_length) {
    // Placeholder spacecraft health values
    float battery_voltage = 8.2;
    float battery_current = 0.45;
    float temperature = 24.5;
    int system_mode = 1;

    snprintf(
        buffer,
        max_length,
        "HEALTH:VBAT=%.2f,IBAT=%.2f,TEMP=%.2f,MODE=%d",
        battery_voltage,
        battery_current,
        temperature,
        system_mode
    );
}

void BEACON_SendHealthMessage(void) {
    BEACON_CreateHealthMessage(health_message, sizeof(health_message));

    // Iridium is used as the low-rate fallback/health telemetry path
    UART_Write(health_message);
}

void BEACON_AppMain(void) {
    BEACON_Init();

    while (1) {
        BEACON_SendHealthMessage();

        // Future work:
        // - Add timed interval, such as every 30 minutes
        // - Pull real EPS telemetry over I2C
        // - Add safe-mode beacon behavior
    }
}
