
# SeatSense: Smart Bus Seat Monitoring System

**SeatSense** is a smart, real-time seat occupancy monitoring system designed to optimize public transportation by providing passengers and operators with real-time data on bus seat availability. This project integrates hardware and software solutions to improve operational efficiency and enhance the commuting experience for passengers.

## Key Features
- **Real-Time Seat Monitoring**: Monitors seat occupancy in real-time using infrared sensors, displaying updates on an onboard LCD display, a mobile app, and a web dashboard.
- **Data Collection and Processing**: Collects data from sensors and processes it through Arduino and ESP8266 Wi-Fi modules, transmitting data to a central server.
- **Optimized Operations**: Provides transportation operators with actionable insights, such as demand forecasting and route optimization.
- **User-Friendly App**: Passengers can check seat availability through the Android mobile app or the web platform before boarding.

## Technologies Used
### Hardware Components:
- **Arduino Uno**: The primary microcontroller for handling sensor data and controlling the system's functionality.
- **ESP8266 Wi-Fi Module**: Handles wireless transmission of seat occupancy data to the server in real-time.
- **IR Sensors**: Infrared sensors used to detect whether a seat is occupied or vacant.
- **16x2 LCD Display**: Displays real-time seat availability onboard the bus, ensuring passengers and operators have instant access to the data.
- **I2C Converter**: An I2C (Inter-Integrated Circuit) interface converter for the LCD display, which reduces wiring complexity and allows for easier communication between the Arduino and the display.
- **Breadboard and Jump Wires**: Used for building the circuit and connecting various components like the sensors, display, and Wi-Fi module.
- **9V Battery and Battery Holder**: Supplies power to the Arduino and other components, ensuring the system functions smoothly on the bus.
- **LED Indicator**: Provides visual feedback for different system statuses, such as seat availability or system errors.
- **Resistors and Capacitors**: Essential for circuit stability and preventing power surges or inconsistencies.


### Software Components:
- **Arduino IDE**: For writing and uploading the control code to the Arduino Uno.
- **PHP**: Backend scripting language for processing and managing real-time data.
- **MySQL Database**: Stores seat availability data for both real-time and historical analysis.
- **WAMP Server**: Hosts the PHP backend and manages communication between hardware and the database.
- **Android Studio**: Used for building the mobile application that displays real-time seat availability.
- **ESP8266WiFi Library**: Enables the ESP8266 module to communicate over Wi-Fi and send data to the server.

## Project Structure
- `/Arduino/`: Contains the Arduino code responsible for sensor data processing and communication with the server.
- `/php/`: PHP scripts that handle data received from the Arduino and ESP8266, process it, and update the database.
- `/app/`: The Android mobile app built using Android Studio, providing passengers with real-time seat occupancy data.
- `/server/`: WAMP server configuration and database management scripts.
- `/components/`: Information on hardware components used, such as wiring diagrams and part specifications.

## Installation and Setup
1. **Hardware Setup**: 
   - Connect the IR sensors to the Arduino Uno, ensuring proper wiring for power and signal transmission.
   - Attach the ESP8266 Wi-Fi module to the Arduino for data communication with the server.
   - Set up the LCD display to show seat availability in real-time on the bus.
   
2. **Software Setup**:
   - Upload the Arduino code to the Arduino Uno using the Arduino IDE.
   - Set up the WAMP server on your local machine to host the PHP scripts and MySQL database.
   - Clone the repository and deploy the PHP files to the WAMP server.
   - Import the provided SQL schema to set up the MySQL database.
   - Compile and run the Android app using Android Studio.

## Future Enhancements
- **Machine Learning Integration**: Implement predictive algorithms to forecast seat occupancy and optimize resource allocation.
- **Expansion**: Extend the system to other modes of public transportation such as trains and ferries.
- **Dynamic Pricing**: Utilize real-time seat availability data to implement dynamic fare pricing.
- **Smart City Integration**: Collaborate with smart city initiatives to provide holistic urban mobility solutions.

## Challenges Faced
- Transitioning from ESP01 to ESP8266 for better integration with the mobile app.
- Debugging infinite loop issues in the PHP and Arduino code for smooth data flow.
- Optimizing sensor accuracy by increasing the number of IR sensors.

## Contribution
Feel free to fork this repository, submit issues, and make pull requests if you want to contribute to the development of SeatSense.

