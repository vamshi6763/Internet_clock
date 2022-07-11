# Internet_clock
Internet clock using nodemcu without RTC module


libraries to be installed:
1. LiquidCrystal
2. NTPClient
3. TimeLib


Components Required:
1. NodeMCU
2. LCD 16x2
3. Jumpwires


NOTE: First install Nodemcu Drivers in Arduino IDE.


Procedure:
1. Goto sketch -> include library -> manage libraries.
2. Now search for "LiquidCrystal" by arduino, then click on install.
3. Now search for "NTPClient" by Fabrice Weinberg, then click on install.
4. Now search for "TimeLib" by Paul stoffregen, then click on install.
5. In the code, replace "WIFI_SSID" with your wifi name and replace "WIFI_PSWD" with your password.
6. In line 16, replace 19800 with your respective UTC time zone
   For example, indian UTC zone is +5:30.... so, 5*60*60=18000,  30*60=1800,   18000+1800=19800 for india.
7. select your appropriate port and upload the code.



Connections:

![16X2-LCD-PINS](https://user-images.githubusercontent.com/101927825/178347131-5b42be32-39ab-4f82-95e7-66e365a16f50.png)

    LCD    -->     NodeMCU
1.  VSS    -->     GND
2.  VDD    --?     vin
3.  VO     -->     from pot
4.  RS     -->     D1
5.  RW     -->     GND
6.  E      -->     D2
7.  D0     -->     No connection
8.  D1     -->     No connection
9.  D2     -->     No connection
10. D3     -->     No connection
11. D4     -->     D3
12. D5     -->     D5
13. D6     -->     D6
14. D7     -->     D7
15. A      -->     3.3v
16. K      -->     GND


output:

https://user-images.githubusercontent.com/101927825/178349611-1c08ca26-6c4c-4e30-b385-cf03a2e21fdb.mp4

