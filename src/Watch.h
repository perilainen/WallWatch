#ifndef Watch_h
#define Watch_h

#include <ESP8266React.h>
#include <AdminSettingsService.h>
#include <NTPStatus.h>
#include <time.h>
#include <FastLED.h> 
#define LED_PIN 2
#define NUM_LEDS 110

#define WATCH_SETTINGS_FILE "/config/watchSettings.json"
#define WATCH_SETTINGS_PATH "/rest/watchSettings"

class WatchSettings {
    public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    
};

class Watch : public AdminSettingsService<WatchSettings> {
    public: 
    Watch(AsyncWebServer* server, FS* fs, SecurityManager* securityManager);
    ~Watch();

    void loop();
    
    private:
      unsigned long _lastChange = 0;
      unsigned long _delay = 2500; 
      void lightBulbs(int low, int high);
      void lightMinutes(int minutes);
      void lightHour(int our);
      void closeBulbs(int low, int high);
      void lightClock();
      void testingBulbs();
      CRGB leds[NUM_LEDS];
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

    protected:
      void readFromJsonObject(JsonObject& root);
      void writeToJsonObject(JsonObject& root);
};



#endif