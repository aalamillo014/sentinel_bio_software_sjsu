# Build and Run Instructions

## Overview
This document describes how the Sentinel Bio+ flight software would be compiled and executed in a development or simulation environment.

---

## Compilation

### Requirements
- GCC compiler (or ARM cross-compiler for embedded systems)
- Standard C libraries

### Example Compile Command

```bash
gcc applications/comms_app/comms_app.c \
    applications/comms_app/packet_buffer.c \
    interfaces/uart_driver.c \
    -o comms_app
