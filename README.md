# Oximeter IoT Project

This project aims to develop an IoT-based system using an Oximeter device to monitor and analyze oxygen saturation levels remotely.

## Project Overview

The primary objective of this project is to leverage an oximeter device and IoT technologies to enable real-time monitoring and analysis of a patient's oxygen saturation and temperature levels. The system collects data from the oximeter device, processes it and transmits the information to a remote server or application for further analysis.

## Components

The project requires the following components:

- Oximeter device capable of measuring oxygen saturation levels (sensor max30102)
- Sensor capable of measuring temperatures (lm35)
- Microcontroller board (Arduino)
- Wi-Fi or Ethernet module for IoT connectivity (library)
- Jumper wires for connections
- Power source (e.g., battery or USB power bank)
- Remote server or application for data visualization and analysis. 
- Cloud platform ([ThingSpeak](https://thingspeak.com)).

## Circuit Diagram

Here is a simplified circuit diagram illustrating the connections:
<div style="display: inline-block; vertical-align: top;">
    <pre>
    +-----------------------+
    |                       |
    |    Microcontroller    |
    |                       |
    | +-------+ +---------+ |
    | | Oximeter |  LM35  | |
    | +-------+ +---------+ |
    |                       |
    +-----------------------+
    </pre>
</div>
<div style="display: inline-block; vertical-align: top;">
    <img src="/App_Doctor/Imagenes/image.png" alt="Your Image" width="300" height="300">
</div>

## Functionality

The system's main functionality includes:

1. Hardware: The sensors allows the acquisition of analog signals, such as temperature, oximetry and heart rate, which can then be analyzed.

2. Data Transmission: The microcontroller allows sending the signals taken by the sensor, and using Arduino through the serial port, these signals are sent to the thingspeak cloud, which are received on a computer through a specially designed application. 

3. Remote Monitoring: The remote server or application receives the transmitted data and visualizes it in real-time. This allows healthcare professionals or caregivers to remotely monitor the oxygen saturation levels and identify any abnormalities or trends.

4. Alerts and Notifications: The system can be configured to generate alerts or notifications when oxygen saturation levels fall below or exceed predefined thresholds. These alerts can be sent to designated individuals via application.


## Software Implementation

To implement this project, you will need to:

1. Set up the development environment for the chosen microcontroller board, such as Arduino IDE or a compatible platform.

2. Interface the microcontroller with the Oximeter/temperature device to extract oxygen saturation/temperature data.

3. Configure the device to establish an internet connection ([Click](https://github.com/caprivm/virtualization/wiki) to get all information!).

4. Implement the necessary code to transmit the acquired Oximeter data to the remote server or application using the chosen IoT communication protocol *(JSON)*.

5. Develop the remote server or application to receive, process, and visualize the data in real-time. This may involve web development, data analysis, and user interface design.

6. Optionally, incorporate alert mechanisms to notify relevant individuals when oxygen saturation levels deviate from normal ranges. 

