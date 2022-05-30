# Wildhorn Sensor Simulator
This repo aims to make a hardware-in-the-loop simulation of the sensor to test the hostboard. 
The goal is to gather sensor data from a ROS simulation, send it through serial (USB) to a Nucleo Board. 
The Nucleo board will then simulate the behaviour of the sensors and communicate with hostboards using SPI and I2C protocol. Each hostboard should have 3 sensors that work with I2C protocol and 3 with SPI protocol. The Nucleo board used is the one containing an STM32F446RE MCU.

ST default HAL (Hardware abstraction layer) library is used to transmit/receive data. Using the "Interrupt" set of function will be better to avoid crazy polling and a good synchronisation.

Note that the dual addressing of the SMT32 I2C bus must be used in order to have enough sensor addresses available. For I2C, two I2C buses can be initialized with one configured with double addressing making (1 + 2 = 3 addresses to acknowledge to). The two buses can then be connected together with hardware to form one unique I2C bus.

The HAL library must be <b> modified </b> in order to analyse which address has been acknowledged. For this the flag DUALF (check reference manual for STM32F446RE) can be analysed.
