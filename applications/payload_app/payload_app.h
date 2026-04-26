#ifndef PAYLOAD_APP_H
#define PAYLOAD_APP_H

#include "packet_format.h"

void PAYLOAD_Init(void);
void PAYLOAD_CollectScienceData(SciencePacket_t *packet);
void PAYLOAD_AppMain(void);

#endif
