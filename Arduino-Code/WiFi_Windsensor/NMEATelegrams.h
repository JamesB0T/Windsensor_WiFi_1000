// NMEA telegrams
// sendmode 0 = no serial, 1 = serial active

String sendMWV(int sendmode){
  
  String HexCheckSum;
  String NMEAWindSpeed;
  String SendWindSpeed;
  
  if (actconf.windSensor == 1){
  
    // Create NMEA string for wind speed $WIMWV,x.x,a,x.x,a,A*hh<CR><LF>
    NMEAWindSpeed = "WIMWV," + String(winddirection);
    if(String(actconf.windType) == "R"){
      NMEAWindSpeed +=  ",R,"; 
    }
    else{
      NMEAWindSpeed +=  ",T,";
    } 
    if(String(actconf.speedUnit) == "kn"){
      NMEAWindSpeed +=  String(windspeed_kn);
      NMEAWindSpeed +=  ",N,A";
    }  
    if(String(actconf.speedUnit) == "m/s"){
      NMEAWindSpeed +=  String(windspeed_mps);
      NMEAWindSpeed +=  ",M,A";
    }
    if(String(actconf.speedUnit) == "km/h"){
      NMEAWindSpeed +=  String(windspeed_kph);
      NMEAWindSpeed +=  ",K,A";
    }        
    // Build CheckSum
    HexCheckSum = String(CheckSum(NMEAWindSpeed), HEX);
    // Build complete NMEA string
    SendWindSpeed = "$" + NMEAWindSpeed;
    SendWindSpeed += "*";
    SendWindSpeed += HexCheckSum;
    if((int(actconf.serverMode) == 1 && sendmode == 1) || (int(actconf.debug) >= 3 && sendmode == 1)){
      Serial.println(SendWindSpeed);
    }
  }

  return SendWindSpeed;
}

String sendVWR(int sendmode){
  
  String HexCheckSum;
  String NMEAWindSpeed;
  String SendWindSpeed;
  
  if (actconf.windSensor == 1){
  
    // Create NMEA string for wind speed $WIVWR,x.x,a,x.x,N,x.x,M,x.x,K*hh<CR><LF>    
    NMEAWindSpeed = "WIVWR," + String(winddirection2);
    if(winddirection >= 0 && winddirection < 180){
      NMEAWindSpeed += ",R,";
    }
    else{
      NMEAWindSpeed += ",L,";
    }
    NMEAWindSpeed += String(windspeed_kn);
    NMEAWindSpeed += ",N,";
    NMEAWindSpeed += String(windspeed_mps);
    NMEAWindSpeed += ",M,";
    NMEAWindSpeed += String(windspeed_kph);
    NMEAWindSpeed += ",K";
    // Build CheckSum
    HexCheckSum = String(CheckSum(NMEAWindSpeed), HEX);
    // Build complete NMEA string
    SendWindSpeed = "$" + NMEAWindSpeed;
    SendWindSpeed += "*";
    SendWindSpeed += HexCheckSum;
    if((int(actconf.serverMode) == 1 && sendmode == 1) || (int(actconf.debug) >= 3 && sendmode == 1)){
      Serial.println(SendWindSpeed);
    }
  }

  return SendWindSpeed;
}
  
String sendVPW(int sendmode){
  
  String HexCheckSum;
  String NMEAWindSpeed;
  String SendWindSpeed;
  
  if (actconf.windSensor == 1){
     if (winddirection >= (180 - float(actconf.downWindRange)) && winddirection <= (180 + float(actconf.downWindRange))){
      downwindspeed_kn = windspeed_kn;
      downwindspeed_mps = windspeed_mps;
     }
     else{
      downwindspeed_kn = 0;
      downwindspeed_mps = 0;
     }
  
    // Create NMEA string for wind speed $WIVPW,x.x,N,x.x,M*hh<CR><LF>    
    NMEAWindSpeed = "WIVPW," + String(downwindspeed_kn);
    NMEAWindSpeed += ",N,";
    NMEAWindSpeed += String(downwindspeed_mps);
    NMEAWindSpeed += ",M";
    // Build CheckSum
    HexCheckSum = String(CheckSum(NMEAWindSpeed), HEX);
    // Build complete NMEA string
    SendWindSpeed = "$" + NMEAWindSpeed;
    SendWindSpeed += "*";
    SendWindSpeed += HexCheckSum;
    if((int(actconf.serverMode) == 1 && sendmode == 1) || (int(actconf.debug) >= 3 && sendmode == 1)){
      Serial.println(SendWindSpeed);
    }
  }

  return SendWindSpeed;
}
  
String sendINF(int sendmode){
  
  String HexCheckSum;
  String NMEAWindSpeed;
  String SendWindSpeed;
  
  if (actconf.windSensor == 1){
  
    // Create NMEA string for wind speed $PWINF,0,x.x,D,x.x,D,x.x,M,x.x,K,x.x,N,x.x,B,A*hh<CR><LF>
    NMEAWindSpeed = "PWINF," + String(actconf.sensorID);
    NMEAWindSpeed +=  ",";
    NMEAWindSpeed +=  String(winddirection);
    NMEAWindSpeed +=  ",D,";
    NMEAWindSpeed +=  String(dirresolution);
    NMEAWindSpeed +=  ",D,";
    NMEAWindSpeed +=  String(windspeed_mps);
    NMEAWindSpeed +=  ",M,";
    NMEAWindSpeed +=  String(windspeed_kph);
    NMEAWindSpeed +=  ",K,";
    NMEAWindSpeed +=  String(windspeed_kn);
    NMEAWindSpeed +=  ",N,";
    NMEAWindSpeed +=  String(windspeed_bft);
    NMEAWindSpeed +=  ",B,";
    // Build CheckSum
    HexCheckSum = String(CheckSum(NMEAWindSpeed), HEX);
    // Build complete NMEA string
    SendWindSpeed = "$" + NMEAWindSpeed;
    SendWindSpeed += "*";
    SendWindSpeed += HexCheckSum;
    if((int(actconf.serverMode) == 1 && sendmode == 1) || (int(actconf.debug) >= 3 && sendmode == 1)){
      Serial.println(SendWindSpeed);
    }
  }

  return SendWindSpeed;
}
  
String sendWST(int sendmode){
  
  String HexCheckSum;
  String NMEASensorTemp;
  String SendSensorTemp;
  
  if (actconf.tempSensor == 1){
    OneWire oneWire(ONE_WIRE_BUS);
    DallasTemperature DS18B20(&oneWire);
    DS18B20.requestTemperatures(); 
    String tempc;
    String tempf;
    tempc = String(DS18B20.getTempCByIndex(0));
    tempf = String(DS18B20.getTempFByIndex(0));
    
    // Create NMEA string for wind sensor temperature $PWWST,C,0,x.x,A*hh<CR><LF>
    if(String(actconf.tempUnit) == "C"){
      NMEASensorTemp = "PWWST,C," + String(actconf.sensorID);
      NMEASensorTemp += ",";
      NMEASensorTemp += String(tempc);
      DebugPrint(3, "Sensor Temp [°C]:");
      DebugPrintln(3, tempc);
    }
    else{
      NMEASensorTemp = "PWWST,F," + String(actconf.sensorID);
      NMEASensorTemp += ",";
      NMEASensorTemp += String(tempf);
      DebugPrint(3, "Sensor Temp [°F]:");
      DebugPrintln(3, tempf);
    }
    NMEASensorTemp += ",A";
    // Build CheckSum
    HexCheckSum = String(CheckSum(NMEASensorTemp), HEX);
    // Build complete NMEA string
    SendSensorTemp = "$" + NMEASensorTemp;
    SendSensorTemp += "*";
    SendSensorTemp += HexCheckSum;
    if((int(actconf.serverMode) == 1 && sendmode == 1) || (int(actconf.debug) >= 3 && sendmode == 1)){
      Serial.println(SendSensorTemp);
    }
  }

  return SendSensorTemp;
}

