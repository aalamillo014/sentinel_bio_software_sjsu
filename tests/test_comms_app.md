# Communications App Test Procedure

## Purpose
Verify that the communications application can initialize, receive a simulated Iridium command, transmit science data through S-band, and fall back to Iridium when S-band data is unavailable.

## Test 1: Initialization
Expected output:
- Initializing Communications System...
- UART Initialized
- Iridium Modem Ready
- S-band Transceiver Ready

## Test 2: Iridium Command Receive
Expected output:
- Received Iridium Command: CMD:SET_BEACON:1800

## Test 3: S-band Transmission
Input:
- SCIENCE_DATA_PACKET

Expected output:
- Transmitting via S-band: SCIENCE_DATA_PACKET

## Test 4: Iridium Fallback
Condition:
- No S-band science packet is available

Expected output:
- Fallback transmission via Iridium: HEALTH_STATUS_OK
