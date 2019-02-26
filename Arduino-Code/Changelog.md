**20190220 firmware_V1.02.wsb {+ (stable) +}**

* Blinking text in demo mode fixed (red syle)
* Individual help text depends on firmware version

**20190220 firmware_V1.01.wsb {+ (old) +}**

* Problem with average setting solved (now updating directly)
* Average value 10 now usable
* Info message in Demo Mode for Instrument page and Device Info page
* Offset for wind direction inserted (new feature)
* Two step update not more necessary
* Any english messages changed

**20190217 firmware_V1.00.wsb {+ (old) +}**

* First actual firmware V1.00
* Critical WLAN settings solved (now checking all input values)
* Implement online update function via GitLab

**20190214 WiFi_Windsensor_12.bin V0.99 {- (critical faulty) -}**

* Jumping pointer in complex instrument is solved (using no average function)

**20190211 WiFi_Windsensor_11.bin V0.98 {- (faulty) -}**

* Sliding avarage disabled for complex instrument
* Relative link fixed in devinfo
* Values for sensor1 and sensor2 fixed in devinfo
* Back button in restart screen added

**20190205 WiFi_Windsensor_10.bin V0.97 {- (faulty) -}**

* Settings field width changed (to 15 characters)
* Limiting sensor values for time1 and time2 < 1000 (value spike reducing)
* WLAN quality value changed for unconnected WLAN (no connection = 0%)
* Using relative links in all web pages (solved reference problem by different IP adresses)
* Inserting a delay from 150ms in main loop (load reducing)
* Default value for Debug Mode is 0 (no debug messages)
* Server Modes changed

**20190201 WiFi_Windsensor_9.bin V0.96 {- (faulty) -}**

* Clear passwort setting
* Blocking all interrupts in interrupt routines
* Blocking all interrupts by saving in EEPROM (critical chrash problem solved)
* Atomic operation for wind value calculation
* All variables in interrupt routines declared as volatile
* All static variables declared as static

**20190125 WiFi_Windsensor_8.bin V0.95 {- (faulty critical) -}**

* Firmware version displaying fixed
* Missing values in JSON solved
* Changed the code for data sending (competitors problem)
* Firmware with EEPROM crash problem (interrupt overrun)

**20190125 WiFi_Windsensor_7.bin V0.95 {- (faulty) -}**

**20190115 WiFi_Windsensor_6.2.bin V0.94 {- (faulty) -}**

* First version with web interface
* Setting changes are reboot save

**20190115 WiFi_Windsensor_6.1.bin V0.94 {- (faulty) -}**

* First version with web interface
* Fix parameter settings by wind sensor start (is neccessary for new settings data structure)
* Settings changes are not reboot save

**{- !!! Danger !!! Do not change from a older version to a newer version without installing WiFi_Windsensor_6.1.bin. Otherwise hanging your wind sensor and need a firmware download via serial line. -}**

**20190105 NMEA_Windsensor_16_final_MyBoat.bin {+ (stable) +}**

* Version without web interface
* Only usable for NMEA data transmission to external clients
* AccessPoint login problem solved
* AccessPoint is allways on and connectable
* Only fix settings usable
* SSID: MyBoat
* Pass: S6587rr94P

**20180710 NMEA_Windsensor_11_final_MyBoat.bin {- (faulty) -}**

* Version without web interface
* Only usable for NMEA data transmission to external clients
* First version with fix settings (delivery state for all wind sensor assembly kits)
* SSID: MyBoat
* Pass: S6587rr94P
* Existing AccessPoint problem
