![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Pressure6 Click

- **CIC Prefix**  : PRESSURE6
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : sep 2018.

---


### Software Support

We provide a library for the Pressure6 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2580/pressure-6-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register and read data from register.
The library includes function for read Temperature data and Pressure data.
The user also has the function for power ON and porew OFF procedure and function for reads Interrupt state.

Key functions :

- ``` uint16_t pressure6_getPressure() ``` - Functions for read Pressure data
- ``` uint8_t pressure6_getTemperatre() ``` - Functions for read Temperature data
- ``` void pressure6_powerON() ``` - Power ON procedure 

**Examples Description**

The application is composed of three sections :

- System Initialization - Inicializes I2C module and set INT pin as INPUT
- Application Initialization - Initialization driver init and start power ON procedure for wake up chip and sets  measurement mode.
- Application Task - (code snippet) - Read Pressure data and Temperature data and logs data to USBUART every 1 sec.


```.c
void applicationTask()
{
    pressure6_waitingForNewData();
    Pressure = pressure6_getPressure();
    Temperature = pressure6_getTemperatre();
    
    // Logs Pressure and Temperature data
    IntToStr(Pressure, demoText);
    mikrobus_logWrite(" Pressure : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    IntToStr(Temperature, demoText);
    mikrobus_logWrite(" Temperature : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    mikrobus_logWrite("  ", _LOG_LINE);
    Delay_ms( 1000 );
}
```


The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2580/pressure-6-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### Cloud

| Sensor | Actuator | Ref 1 | Ref 2 | Jedinica | Range - min  | Range - max |
|:------:|:--------:|:-----:|:-----:|:-----:|:------------:|:-----------:|
| YES | NO | PRESSURE6_T | PRESSURE6_P | [C] - [hPa] | 0C - 300hPa | 85C - 1300hPa | 

---
---
