# Communications Interface Definition

## Purpose
This document defines the software and hardware interfaces for the Sentinel Bio+ communications subsystem.

## Hardware Interfaces
- OBC to Iridium modem: UART
- OBC to S-band transceiver: UART
- Radio to antenna: RF coaxial connection

## Software Interfaces
- Payload data is passed to comms_app for transmission.
- Iridium commands are received and routed to the OBC.
- S-band is prioritized for science data downlink.
- Iridium is used as a low-rate fallback and health telemetry path.

## Data Flow
Payload → OBC → comms_app → S-band radio → Ground Station

Fallback path:

OBC → comms_app → Iridium SBD modem → Ground
