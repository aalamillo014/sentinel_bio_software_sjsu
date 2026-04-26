#ifndef FAILSAFE_APP_H
#define FAILSAFE_APP_H

void FAILSAFE_Init(void);
int FAILSAFE_CheckPower(float battery_voltage);
int FAILSAFE_CheckTemperature(float temperature);
int FAILSAFE_CheckComms(int comms_status);
void FAILSAFE_EnterSafeMode(void);
void FAILSAFE_AppMain(void);

#endif
