# Applications

This folder contains all flight software applications for the Sentinel Bio+ mission.

Each application is designed following NASA Core Flight System (cFS) architecture principles and is responsible for a specific subsystem function.

## Planned Applications
- comms_app: Handles communication with Iridium and S-band radios
- payload_app: Manages science payload data collection and processing
- beacon_app: Sends periodic health and status telemetry
- failsafe_app: Monitors system health and triggers safe mode

## Notes
Applications communicate with the Onboard Computer (OBC) and interface with hardware through defined communication protocols such as UART.
