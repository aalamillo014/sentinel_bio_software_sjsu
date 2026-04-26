# Sentinel Bio+ Flight Software Repository

## Overview
This repository contains the modular flight software architecture for the Sentinel Bio+ CubeSat mission concept. The software is organized around spacecraft applications responsible for science data collection, communications, health beaconing, and failsafe response.

The repository is structured to support a cFS-inspired modular design, where each subsystem application has a clear responsibility and defined interfaces.

---

## Mission Software Functions
The software supports the following major mission functions:

- Collect science data from the payload
- Format science data into structured packets
- Buffer packets onboard before downlink
- Downlink science data through S-band
- Receive low-rate commands through Iridium
- Send health telemetry beacons
- Detect faults and trigger safe-mode alerts

---

## Repository Structure

```text
sentinel_bio_software/
├── applications/
│   ├── comms_app/
│   ├── payload_app/
│   ├── beacon_app/
│   └── failsafe_app/
│
├── interfaces/
│   ├── uart_driver.c
│   ├── uart_driver.h
│   ├── packet_format.h
│   └── comms_interface.md
│
├── docs/
│   ├── Software_Architecture.md
│   ├── System_Flow.md
│   └── Packet_Format.md
│
├── tests/
│   └── test_comms_app.md
│
├── simulations/
├── scripts/
├── core_flight_system/
├── README.md
└── .gitignore
