# Communications Application (comms_app)

This application manages all communication for the Sentinel Bio+ mission.

## Responsibilities
- Receive commands from Iridium SBD modem
- Transmit science data via S-band
- Provide fallback communication via Iridium
- Route data between payload and radios

## Interfaces
- UART (OBC ↔ radios)
- Payload data input
