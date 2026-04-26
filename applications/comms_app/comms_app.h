#ifndef COMMS_APP_H
#define COMMS_APP_H

#include "packet_format.h"

void COMMS_Init(void);
void COMMS_AppMain(void);
void COMMS_Create_SciencePacket(void);
void COMMS_Receive_Iridium(void);
void COMMS_Send_SBand(const SciencePacket_t *packet);
void COMMS_Send_Iridium(const char *data);

#endif
