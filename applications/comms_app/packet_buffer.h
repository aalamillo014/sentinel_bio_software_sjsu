#ifndef PACKET_BUFFER_H
#define PACKET_BUFFER_H

#include "packet_format.h"

#define PACKET_BUFFER_CAPACITY 10

void PacketBuffer_Init(void);
int PacketBuffer_IsFull(void);
int PacketBuffer_IsEmpty(void);
int PacketBuffer_Add(const SciencePacket_t *packet);
int PacketBuffer_GetNext(SciencePacket_t *packet);

#endif
