

# Saino - Aircraft Engine Monitoring System

A Qt-based application for real-time monitoring and analysis of aircraft engine sensor data received from FPGA units. This system provides comprehensive visualization and logging of engine health parameters during pre-flight testing and operation.

## 📋 Project Overview

Saino is the main monitoring application that receives, processes, and displays real-time sensor data from aircraft engines via FPGA units. It implements robust data handling with corruption tolerance while providing intuitive graphical interfaces for engine health assessment.

## 🚀 Features

- **Real-time Data Acquisition**: Receives engine sensor data via serial communication
- **Robust Protocol Handling**: Tolerates and recovers from data corruption as specified in the protocol
- **Comprehensive Visualization**:
  - Circular gauges for critical parameters with configurable ranges
  - Real-time warning lights for sensor errors
  - Dual-table display for organized data presentation
- **Excel Data Logging**: Continuous storage of all received data in Excel-compatible format
- **Configurable Serial Interface**: Flexible serial port configuration for various hardware setups
- **Corruption-Resistant**: Designed to handle real-world data corruption scenarios from jet engine environments

## 📸 Application Interface
<img width="1003" height="790" alt="Screenshot (291)" src="https://github.com/user-attachments/assets/b97e91f6-7813-4ff9-881e-6c4f69d4d92f" />
*program environment, containing configurable setting for Serial Communication, Gauges, etc.*

## 🔗 Related Projects

This application works in conjunction with:
- **[JetMotor FPGA Simulator](https://github.com/slotfi909/JetMotor/)** - Generates synthetic FPGA data for testing and development

## 🛠️ Protocol Implementation

### Data Reception & Validation
- **Header Validation**: Strict `0xA5 0xA5 0xA5 0xA5` validation
- **Checksum Verification**: UINT16 checksum from MSG COUNTER to last FACTOR
- **Footer Confirmation**: `0x55` footer validation
- **Duplicate Detection**: MSG COUNTER tracking to prevent duplicate processing
- **Corruption Handling**: Graceful recovery from partial or corrupted messages

### Supported Sensor Parameters

| Parameter | Gauge Range | Units | Critical Thresholds |
|-----------|-------------|-------|---------------------|
| Oil Pressure | 0-1000 | psi | Warning: 800-900, Critical: >900 |
| Oil Temperature | 0-400 | °C | Warning: 300-350, Critical: >350 |
| Fuel Flow | 0-800 | kg/h | Warning: 700-750, Critical: >750 |
| EGT | 0-400 | °C | Warning: 300-350, Critical: >350 |
| Torque | 0-400 | N·m | Warning: 300-350, Critical: >350 |
| Motor Speed | 0-1000 | RPM | Warning: 800-900, Critical: >900 |

