# Sentinel Bio+ Software Architecture

## Purpose
The Sentinel Bio+ software architecture organizes the mission software into modular applications that support science data collection, communications, health monitoring, and safe-mode response.

## Software Stack

Payload App → Comms App → UART Driver → Radios → Ground Segment

Beacon App → UART Driver → Iridium/S-band

Failsafe App → UART Driver → Iridium Safe-Mode Alert

## Applications

### payload_app
Collects and formats science data into structured science packets.

### comms_app
Buffers science packets and transmits them through the S-band radio. Iridium is used for low-rate fallback messages.

### beacon_app
Creates periodic health messages containing battery voltage, current, temperature, and spacecraft mode.

### failsafe_app
Monitors power, temperature, and communications status. If a fault is detected, the spacecraft enters safe mode and sends an alert.

## Interfaces

### UART Driver
The UART driver provides the software interface between the OBC and communication radios.

### Packet Format
Science and health telemetry are organized using defined packet structures to support consistency, traceability, and future testing.

## Current Development Status
- Repository structure created
- Communications application created
- UART interface layer added
- Packet format defined
- Packet buffer added
- Beacon application added
- Failsafe application added
- Payload application added

## Future Work
- Add real UART device mapping for OBC hardware
- Add actual payload sensor input
- Add real checksum calculation
- Add AWS Ground Station pass scheduling logic
- Add unit tests and integration tests
- Add cFS-style task scheduling
