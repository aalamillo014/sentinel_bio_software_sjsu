#include "failsafe_app.h"
#include "uart_driver.h"

#define MIN_BATTERY_VOLTAGE 7.2
#define MAX_TEMPERATURE 50.0
#define COMMS_OK 1

static int safe_mode_active = 0;

void FAILSAFE_Init(void) {
    safe_mode_active = 0;
}

int FAILSAFE_CheckPower(float battery_voltage) {
    return battery_voltage < MIN_BATTERY_VOLTAGE;
}

int FAILSAFE_CheckTemperature(float temperature) {
    return temperature > MAX_TEMPERATURE;
}

int FAILSAFE_CheckComms(int comms_status) {
    return comms_status != COMMS_OK;
}

void FAILSAFE_EnterSafeMode(void) {
    safe_mode_active = 1;

    // Send low-rate safe-mode alert through Iridium fallback path
    UART_Write("SAFE_MODE_ACTIVE");
}

void FAILSAFE_AppMain(void) {
    FAILSAFE_Init();

    while (1) {
        // Placeholder telemetry values
        float battery_voltage = 8.2;
        float temperature = 24.5;
        int comms_status = COMMS_OK;

        if (
            FAILSAFE_CheckPower(battery_voltage) ||
            FAILSAFE_CheckTemperature(temperature) ||
            FAILSAFE_CheckComms(comms_status)
        ) {
            FAILSAFE_EnterSafeMode();
        }

        // Future work:
        // - Pull real EPS voltage/current/temp telemetry
        // - Pull real OBC temperature telemetry
        // - Monitor radio response status
        // - Command ADCS into power-positive/safe attitude
    }
}
