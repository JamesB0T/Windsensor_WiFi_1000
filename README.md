## The Windsensor WiFi 1000 is a OpenSource project to build windsensor for sailboats with 3D printer parts and a ESP8266

My windsensor was defect in the last winter time 2018 by a big storm in Netherlands. I needed a new windsensor for my small sailboat. It is a Dehlya 22. I seached a interesting and usefully project for my new 3D printer. At first I try to build the hemispheric parts and the rotor. After successfully 3D printing I was amazed about the good quality and mechanical precisition. My printer is a low cost Chinise model JGAurora in prusa design. At this point I started my project with the windsensor and I designed all parts in 3D for my printer.

The windsensor based on a [patent](Patents/US5231876.pdf) from PeetBros Inc. The patent has expired and everyone can use it. The function is very simple and use two reed magnet sensors for wind speed and wind direction. I modified the circuit and changed the sensors to two hall sensors. A ESP8266-E12 measure two time values from both sensors and calculate the wind speed and wind direction.The operating principle is very simple and tricky. It is a perfect solution of simplicity and function and a good base for the ESP8266.

![alt text](Pictures/Windsensor2.png)

I bublished the project in the german sail forum [www.segeln-forum.de](https://www.segeln-forum.de/board1-rund-ums-segeln/board35-bootstechnik-und-elektronik/67401-windsensor-diy/) and found a lot of interested poeple. Afte a half year was all mechanical components and elektrical shematics finished and I could try the first windsensor successfully on my sailboat.

These are my conditions for the new windsensor:

* Measuring from wind speed and wind direction
* Robust mechanics
* Weight <= 200g
* Small enought for a 22 feed sailboad
* Weatherproof and UV stable
* Visible by night
* No cabeling for sensor signals
* Only digital signal transmission with WiFi
* 12V power supplay from top light
* Using a ESP8266 for WiFi and data handling
* Update rate app. 1...2 samples per secounds
* No onboard instrument necessary
* Visualitation in OpenPlotter via laptop, mobile fone or tablett
* No software installation unnecessary (display is the browser)
* Supported protocol NMEA 0183
* Price <= 250 Euro

I use the windsensor in combination with OpenPlotter on a Rasiberry Pi 3. OpenPlotter is a access point for WiFi devices. The windsensor connects via WiFi with OpenPlotter and send the NMEA0183 data telegrams all one second.

![alt text](Pictures/Windsensor_Raspi_Handy_Laptop.png)

It is possible with each network device connect to OpenPlotter. A simple browser shows all data from the windsensor. I use a small 7" Android tablet as display for my windsensor.

