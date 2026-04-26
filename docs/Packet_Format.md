# Sentinel Bio+ Packet Format

## Purpose
This document defines the baseline packet structure used by the Sentinel Bio+ onboard software for science data and health telemetry.

## Science Packet
The science packet carries payload data from the bio/radiation experiment through the OBC and into the communications application for downlink.

## Science Packet Fields
- packet_id: Identifies the packet type
- timestamp: Records when the data was collected
- payload_data: Stores science payload data
- checksum: Used for basic data integrity verification

## Health Packet
The health packet carries spacecraft status information for low-rate telemetry through Iridium or S-band.

## Health Packet Fields
- packet_id: Identifies the packet type
- timestamp: Records packet creation time
- battery_voltage: EPS battery voltage
- battery_current: EPS current draw
- temperature: System temperature
- system_mode: Current spacecraft mode
- checksum: Used for basic data integrity verification

## Notes
Science data is prioritized for S-band downlink, while health telemetry can be transmitted through Iridium as a fallback or safe-mode communications path.
