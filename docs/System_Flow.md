# Sentinel Bio+ System Flow

## Overview
The Sentinel Bio+ flight software is organized into modular applications that interact through defined data paths to support science data collection, communication, and spacecraft health monitoring.

---

## High-Level Flow

Payload App → Comms App → UART Driver → Radios → Ground Station

Beacon App → UART Driver → Iridium (Health Telemetry)

Failsafe App → UART Driver → Iridium (Safe Mode Alert)

---

## Detailed Data Flow

### 1. Science Data Path
1. The payload_app collects science data from onboard sensors.
2. Data is formatted into a SciencePacket structure.
3. The comms_app receives or generates the packet.
4. The packet is stored in the onboard packet buffer.
5. During communication windows, packets are transmitted through the S-band radio.

---

### 2. Command Path (Uplink)
1. Ground station sends commands via Iridium.
2. The UART driver receives the command.
3. The comms_app processes the command.
4. Commands are routed to the appropriate subsystem (future implementation).

---

### 3. Health Telemetry Path
1. The beacon_app generates health messages.
2. Messages include:
   - Battery voltage
   - Current
   - Temperature
   - System mode
3. Data is transmitted via Iridium as low-rate telemetry.

---

### 4. Safe Mode Path
1. The failsafe_app continuously monitors:
   - Battery voltage
   - Temperature
   - Communication status
2. If a fault is detected:
   - System enters safe mode
   - A SAFE_MODE_ACTIVE message is transmitted via Iridium

---

## Software Architecture Summary

| Application     | Function |
|----------------|--------|
| payload_app    | Generates science data |
| comms_app      | Buffers and transmits data |
| beacon_app     | Sends health telemetry |
| failsafe_app   | Monitors system health and triggers safe mode |
| uart_driver    | Interfaces with radios |

---

## Future Improvements
- Direct integration between payload_app and comms_app
- Real command parsing and routing
- Ground station pass scheduling (AWS)
- Real-time operating system integration
- Hardware-in-the-loop testing
