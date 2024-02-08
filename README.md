# fastLOGIC! open source industrial controller
## A cost-effective Arduino-based board designed for simple (industrial) logic control used for small-scale automation and process control applications.

The Arduino [library](https://github.com/Neumi/fastLOGIC/tree/main/software/library/fastLOGIC) can be used to get started. A few example sketches show what fastLOGIC! is capable of and how to read sensor data and how to write outputs to the LEDs and relays.

If you want to write or read directly from or to the pins:
```cpp
// fastLOGIC! pin mapping
DIGITAL_IN_A = D2;
DIGITAL_IN_B = D3;
RELAY_A_OUT = D5;
RELAY_B_OUT = D4;
TM1637_SCK = D6;
TM1637_DIO = D7;
DS18B20_DATA = D9;
LED_B_OUT = D10;
LED_A_OUT = D13;
VOLTAGE_SENS_IN = A0;
BUTTONS_IN = A1;
ANALOG_IN_A = A2;
ANALOG_IN_B = A3;
```

If you want to use the **7-segment display**, use this [library](https://github.com/avishorp/TM1637).

The part numbers in the KiCAD files are LCSC part numbers. This means you can order directly at JLCPCB using the manufacturing files in the [production folder](https://github.com/Neumi/fastLOGIC/tree/main/hardware/version001/fastLOGIC/production).
I usually only order SMT parts because THT assembly costs extra (and they don't have all parts in stock).

###  The only parts you need:
- [relais 5V](https://de.aliexpress.com/item/1005006065653383.html)
- [4-bit Common Anode Display](https://de.aliexpress.com/item/1005006101748128.html)
- [JST connectors 3pin + 4pin](https://de.aliexpress.com/item/4000120545240.html)
- [Screw terminals 2pin + 3pin](https://de.aliexpress.com/item/1005005194957825.html)
- [USB connector Type A](https://de.aliexpress.com/item/1005004679855929.html)
- [Case](https://de.aliexpress.com/item/32760647473.html)
- some m3 screws
  
### Optional:
- [XGZP6847a pressure sensor](https://de.aliexpress.com/item/1005003768236942.html)
- [High pressure sensor](https://de.aliexpress.com/item/1005005510454084.html)
- [DS18B20 temperature sensor](https://de.aliexpress.com/item/1005005973956237.html)

### Have fun but:
* **The project is still in development and is only in the prototype stage! Stay tuned!**
* **this also means that not everything works 100% and is safe**
* **Do not use in a production environment unsupervised. Use at your own risk**
* **Input voltage should be between 12...25V. (NO reverse polarity protection currently)**
* **Do not switch mains voltage with the relais! Only low voltage and currents <5A**
    
  
<img alt="linear axis" src="/img/perspective_photo.jpg">
<img alt="linear axis" src="/img/description.jpg">
<img alt="linear axis" src="/img/assembly.png">
<img alt="linear axis" src="/img/layout001.png">
