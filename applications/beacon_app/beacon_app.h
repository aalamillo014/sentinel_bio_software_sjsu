#ifndef BEACON_APP_H
#define BEACON_APP_H

void BEACON_Init(void);
void BEACON_CreateHealthMessage(char *buffer, int max_length);
void BEACON_SendHealthMessage(void);
void BEACON_AppMain(void);

#endif
