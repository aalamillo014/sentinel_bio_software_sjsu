#include "packet_buffer.h"

static SciencePacket_t packet_buffer[PACKET_BUFFER_CAPACITY];

static int head = 0;
static int tail = 0;
static int count = 0;

void PacketBuffer_Init(void) {
    head = 0;
    tail = 0;
    count = 0;
}

int PacketBuffer_IsFull(void) {
    return count == PACKET_BUFFER_CAPACITY;
}

int PacketBuffer_IsEmpty(void) {
    return count == 0;
}

int PacketBuffer_Add(const SciencePacket_t *packet) {
    if (PacketBuffer_IsFull()) {
        return -1;
    }

    packet_buffer[tail] = *packet;
    tail = (tail + 1) % PACKET_BUFFER_CAPACITY;
    count++;

    return 0;
}

int PacketBuffer_GetNext(SciencePacket_t *packet) {
    if (PacketBuffer_IsEmpty()) {
        return -1;
    }

    *packet = packet_buffer[head];
    head = (head + 1) % PACKET_BUFFER_CAPACITY;
    count--;

    return 0;
}
