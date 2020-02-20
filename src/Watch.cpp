#include <Watch.h>


Watch::Watch(AsyncWebServer* server, FS* fs, SecurityManager* securityManager) :
    AdminSettingsService(server, fs, securityManager, WATCH_SETTINGS_PATH, WATCH_SETTINGS_FILE) {
    Serial.println("init");
}

Watch::~Watch(){
}

void Watch::closeBulbs(int low, int high){
  for (int i =low; i<= high; i++){
    leds[i] = CRGB (0,0,0);
  }
}

void Watch::lightBulbs(int low,int high){
  for (int i =low; i<= high; i++){
    leds[i] = CRGB (_settings.red,  _settings.green, _settings.blue);
  }
}

void Watch::lightMinutes(int minutes){
  //Serial.print(":");
  //Serial.println(minutes);
  closeBulbs(min_low,min_high);
  
  switch (minutes){
    case 5:
      lightBulbs(fivemin_low,fivemin_high);
      lightBulbs(over_low,over_high);
      break;
    case 10:
      lightBulbs(tenmin_low,tenmin_high);
      lightBulbs(over_low,over_high);
      break;
    case 15:
      lightBulbs(fifteenmin_low,fifteenmin_high);
      lightBulbs(over_low,over_high);
      break;
    case 20:
      lightBulbs(twentymin_low,twentymin_high);
      lightBulbs(over_low,over_high);
      break;
    case 25:
      lightBulbs(fivemin_low,fivemin_high);
      lightBulbs(in_low,in_high);
      lightBulbs(half_low,half_high);
      break;
    case 30:
      lightBulbs(half_low,half_high);
      break;
    case 35:
      lightBulbs(fivemin_low,fivemin_high);
      lightBulbs(over_low,over_high);
      lightBulbs(half_low,half_high);
      break;
    case 40:
      lightBulbs(twentymin_low,twentymin_high);
      lightBulbs(in_low,in_high);
      break;
    case 45:
      lightBulbs(fifteenmin_low,fifteenmin_high);
      lightBulbs(in_low,in_high);
      break;
    case 50:
      lightBulbs(tenmin_low,tenmin_high);
      lightBulbs(in_low,in_high);
      break;
    case 55:
      lightBulbs(fivemin_low,fivemin_high);
      lightBulbs(in_low,in_high);
  }
  
}
void Watch::lightHour(int our){
  //Serial.print("Lightning: ");
  //Serial.print(our);
  closeBulbs(hour_low,hour_high);
  
  switch (our){
    
    
    case 1:
      lightBulbs(one_low,one_high);
      break;
    case 2:
      lightBulbs(two_low,two_high);
      break;
    case 3:
      lightBulbs(three_low,three_high);
      break;
    case 4:
      lightBulbs(four_low,four_high);
      break;
    case 5:
      lightBulbs(five_low,five_high);
      break;
    case 6:
      lightBulbs(six_low,six_high);
      break;
    case 7:
      lightBulbs(seven_low,seven_high);
      break;
    case 8:
      lightBulbs(eight_low,eight_high);
      break;
    case 9:
      lightBulbs(nine_low,nine_high);
      break;
    case 10:
      lightBulbs(ten_low,ten_high);
      break;
    case 11:
      lightBulbs(eleven_low,eleven_high);
      break;
    case 12:
      lightBulbs(twelve_low,twelve_high);
      break;
  }
  
}
void Watch::lightClock(){
  Serial.println("lightning clock");
  closeBulbs(header_low,header_high);
  lightBulbs(clock_low,clock_high);
  lightBulbs(is_low,is_high);
  
  time_t now = time(nullptr);
  struct tm *ltime = localtime(&now);
  int hours = ltime->tm_hour;
  int minutes = ltime->tm_min;
  
  if (minutes>=25){
    lightHour(1+hours%12);
  }
  else{
    lightHour(hours%12);
  }
  lightMinutes(minutes/5 *5);
  
  FastLED.show();
  //Serial.println("Fastled Show");
}

void Watch::testingBulbs(){
  lightBulbs(0,109); 
  FastLED.show();
}
void Watch::loop(){
    
    unsigned long currentTime = millis();
    if ((unsigned long)(currentTime - _lastChange)> _delay){
        _lastChange =currentTime;
        Serial.println("HEJ");
        time_t now = time(nullptr);
        struct tm *ltime = localtime(&now);
        int hours = ltime->tm_hour;
        int minutes = ltime->tm_min;
        lightClock();
// struct tm *theTime;
// 	time_t tim = time(nullptr);
	
// 	theTime = localtime(&tim);
// 	int hours = theTime->tm_hour;
//     int minutes = theTime->tm_min;
    
    Serial.print(hours);
    Serial.print(":");
    Serial.println(minutes);
    Serial.println(_settings.red);
    
    
        
    }
}
void Watch::readFromJsonObject(JsonObject& root) {
    _settings.red = root["red"] | 100;
    _settings.green = root["green"] | 100;
    _settings.blue = root["blue"] | 100;

}

void Watch::writeToJsonObject(JsonObject& root){
    root["red"] = _settings.red;
    root["green"]  = _settings.green;
    root["blue"] = _settings.blue;
}
    



