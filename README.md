# OTA Burner
- Over-The-Air Burner That's Used To Flash hex File On STM32 MCU.
- Booloader Is Developed Following UART Communication Protocol.
- Using NodeMCU ESP8266 And ReactJS Developed Website.
# Table Of Contents
- [General Info](#general-info)
- [Getting Started](#Getting-Started)
- [Technologies and Hardware](#Technologies-and-Hardware)
- [Configurations](#configurations)
# General Info
- This project Implements Over-The-Air Burner That's Used To Flash hex File On STM32 MCU, Following UART Communication Protocol, Using NodeMCU ESP8266.
- Website is developed and deployed to burn hex on MCU with help of FPEC peripheral.
- Website is hosted on heroku hosting service [Website](https://ota-flasher.herokuapp.com/).
- Peripherals and Drivers: FPEC, SYSYTICK, RCC, UART, GPIO.
- [View Demo](https://youtu.be/bJenN9XARbg).


![1](https://user-images.githubusercontent.com/74314248/176132841-ebe779c0-c267-441e-9e23-61b7b0ff0fe5.jpg)![2](https://user-images.githubusercontent.com/74314248/176132844-9efcd051-d292-4378-99d8-449369826c4b.jpg)


# Getting Started
- When Final Record In Hex File Is Reached ":00000001FF", The Application Jumps To The New Flashed Program Immediately.
- If 30 Seconds Passed Without Hex Files Received To Be Flashed, The Application Jumps To The Current Flashed Program.

# Technologies and Hardware
- C language
- STM32 MCU
- HTML, CSS, ReactJS
- NodeMCU ESP8266

# Configurations
- In Burner-NodeMCU-ESP8266 There's config file to Set WIFI SSID and Password (credentials_config.h).
