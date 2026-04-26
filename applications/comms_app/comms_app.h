#ifndef COMMS_APP_H
#define COMMS_APP_H

void COMMS_Init(void);
void COMMS_Run(void);
void COMMS_Receive_Iridium(void);
void COMMS_Send_SBand(const char *data);
void COMMS_Send_Iridium(const char *data);

#endif
