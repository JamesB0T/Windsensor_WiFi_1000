#ifndef Definitions_h
#define Definitions_h           

// Passwort settings
String transactionID = String(random(0, 99999999));// Generate a random transaction ID by initialisation
String raw = "";                    // Uncrypted raw data
String crypt = "";                  // Crypted data

// EEPROM settings (max size is 4096 Byte)
int cfgStart = 1024;                // Start adress in EEPROM (Attention! The first 32 Byte are used beginning with adress 0)
int sizeEEPROM = 2048;              // Used size of EEPROM 2kB (limit for config file size)

// WLAN client settings
String hname;                       // Hostname
int maxccounter;                    // Maximum number for connection tests until aborted (maxcounter = 60; 60 * 500ms = 30s waiting time)
int ccounter;                       // Actual connection test counter

// Settings for NMEA server 
int SendPeriod = 1000;              // SendPeriod in [ms], Attention! Range is limited [500...2000]
int RedSendPeriod = 3000;           // Reduced send period [ms] when wind speed is zero, range [2000...10000]
volatile bool flag1 = false;        // Flag for data sending (normal speed)
volatile bool flag2 = false;        // Flag for data sending (reduced speed)
volatile bool flag3 = false;        // Flag for zero wind speed detection (true = zero)

// Definitions input pins for wind speed and wind direction
#define INT_PIN1 5                  // Wind speed D1, GPIO 5
#define INT_PIN2 4                  // Wind direction D2, GPIO 4

// Definition 1Wire
#define ONE_WIRE_BUS 15           // 1Wire bus on pin 15 (D8)

// Measuring data (used in intetrupt)
volatile int marker1 = 0;         // Wind speed
volatile int marker2 = 0;         // Wind direction
volatile int marker3 = 0;         // Marker for data saving in a array (sensor 1 and 2 binary switching data)
volatile int scounter = 0;        // Array counter for data saving (sensor1 and 2)
volatile int rpcounter = 0;       // Raw pulse counter for wind direction sensor (per revolution)
volatile int pcounter = 0;        // Pulse counter for wind direction sensor (per revolution)
volatile unsigned long icounter = 0;    // Interrupt counter for rotation detection
volatile unsigned long icounterold = 0; // Old interrupt counter for rotation detektion
volatile unsigned long counter1;  // Wind spped
volatile unsigned long counter2;  // Wind direction
volatile float time1;             // Wind speed (time in [ms] for one rotation)
volatile float time2;             // Wind direction (time in [ms] between wind speed sensor and wind direction sensor)
volatile int average;             // Number of values for average calculation [1...10]
volatile float timearray1[10];    // Array1 of time values (average building)
volatile float timearray2[10];    // Array2 of time values (average building)
volatile int mc = 0;              // Modulo counter
volatile float time1_avg;         // Average wind speed (time in [ms] for one rotation)
volatile float time2_avg;         // Average direction (time in [ms] between wind speed sensor and wind direction sensor)

static float radius = 0.06;       // Radius between center and middle of half hemisphere position
static float lamda = 0.3;         // Lambda is a constant for amemometer type with 3 hemisphere, lamda = 0,3
static float pi = 3.14159265358979;   // Pi constant

volatile float fieldstrength;     // WLAN field strength
volatile float quality;           // WLAN quality
volatile float temperature;       // Windsensor temperature
volatile float windspeed;         // Selected windspeed for Web interface
volatile float windspeed_hz;      // Wind speed in [Hz], [rps]
volatile float windspeed_mps;     // Wind speed in [m/s]
volatile float windspeed_kn;      // Wind speed in [kn]
volatile float windspeed_kph;     // Wind speed in [km/h]
volatile int windspeed_bft;       // Wind speed in [bft]
volatile float dwspeed;           // Down wind speed for Web interface
volatile float downwindspeed_kn;  // Down wind speed in [kn]
volatile float downwindspeed_mps; // Down wind speed in [m/s]
volatile float term3;             // 3te term
volatile float term2;             // 2te term
volatile float term1;             // 1te term
volatile float rawwinddirection;  // Wind direction 0...360[°] in relation to midle of ship line (midle = 0°) without offset
volatile float winddirection;     // Wind direction 0...360[°] in relation to midle of ship line (midle = 0°) with offset
volatile float winddirection2;    // Wind direction 0...180[°] in relation to midle of ship line (midle = 0°) for each boat side with offet
volatile float dirresolution;     // Resolution of wind direction [°]
volatile int sensor1;             // Output hallsensor signal for wind speed (Web interface)
volatile int sensor2;             // Output hallsensor signal for wind direction (Web interface)

volatile bool sensor1TimeArray[1000]; // Time array for Hall sensor 1 (Debug Mode)
volatile bool sensor2TimeArray[1000]; // Time array for Hall sensor 2 (Debug Mode)

// For calculating demo data
unsigned int demoSet = 0;         // number of DEMO set for timearrays


// Pin definitions for WIMO D1 mini
const int ledPin = D4;            // Pin GPIO 02 (D4), LED is low activ
const int ssPin = D8;             // Pin GPIO 15 (D8), SS or CS for SDCard

// Style parameter
int style = 1;                    // Toggle display between day (1) und night (0) illumination
int resetESP = 0;                 // Global marker for reset the ESP8266
int instrumentsize = 200;         // Instrument size in pixel
float scalefactor = 1.0;          // Scale factor for instrument
String icolor = "#FFFFFF";        // Instrument color day withe

// Selection arrays (list of arguments in HTTP get response for index calculation)
String usepassword[2] = {"0", "1"};
String itype[2] = {"simple", "complex"};
String isize[9] = {"200", "250", "300", "350", "400", "450", "500", "550", "600"};
String timeout[10] = {"30", "60", "90", "120", "150", "180", "210", "240", "270", "300"};
String apchannel[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13"};
String servermode[5] = {"0", "1", "2", "3", "4"};
String debugmode[4] = {"0", "1", "2", "3"};
String serspeed[10] = {"300", "1200", "2400", "4800", "9600", "19200", "38400", "57600", "74880", "115200"};
String sensorid[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
String sendwsdata[2] = {"0", "1"};
String windtype[2] = {"R", "T"};
String averages[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
String speedunits[4] = {"m/s", "km/h", "kn", "bft"};
String dwsensor[2] = {"0", "1"};
String dwrange[9] = {"20", "25", "30", "35", "40", "45", "50", "55", "60"};
String tstype[2] = {"Off", "DS18B20"};
String sendtsd[2] = {"0", "1"};
String tempunits[2] = {"C", "F"};
String mdnsservice[2] = {"0", "1"};

#endif
