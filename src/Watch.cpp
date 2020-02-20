#include <Watch.h>

int hour_low = 0;
    int hour_high = 54;
    int one_low = 44;
    int one_high = 46;
    int two_low = 52;
    int two_high = 54;
    int three_low = 41;
    int three_high = 43;
    int four_low = 33;
    int four_high = 36;
    int five_low = 22;
    int five_high = 24;
    int six_low = 30;
    int six_high = 32;
    int seven_low = 19;
    int seven_high = 21;
    int eight_low = 15;
    int eight_high = 18;
    int nine_low = 11;
    int nine_high = 13;
    int ten_low = 0;
    int ten_high = 2;
    int eleven_low = 3;
    int eleven_high = 6;
    int twelve_low = 7;
    int twelve_high = 10;


    int min_low = 55;
    int min_high = 98;
    int half_low = 55;
    int half_high = 58;
    int in_low = 74;
    int in_high = 74;
    int over_low = 62;
    int over_high = 65;
    int fivemin_low = 88;
    int fivemin_high = 90;
    int tenmin_low = 94;
    int tenmin_high = 96;
    int fifteenmin_low = 83;
    int fifteenmin_high = 87;
    int twentymin_low = 66;
    int twentymin_high = 70;

    int header_low = 99;
    int header_high = 109;
    int clock_low = 103;
    int clock_high = 109;
    int is_low = 100;
    int is_high = 101;

Watch::Watch(AsyncWebServer* server, FS* fs, SecurityManager* securityManager) :
    AdminSettingsService(server, fs, securityManager, WATCH_SETTINGS_PATH, WATCH_SETTINGS_FILE) {
    Serial.println("init");
}

Watch::~Watch(){

}

void getTime(){
    
}



String toReadString(tm* time, bool incOffset) {
  char time_string[25];
  strftime(time_string, 25, incOffset ? "%FT%T%z" : "%FT%TZ", time);
  return String(time_string);
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
    



