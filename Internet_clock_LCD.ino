#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>               
#include <TimeLib.h>
#include <LiquidCrystal.h>

// lcd(rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(D1, D2, D3, D5, D6, D7);

char* ssid = "WIFI_SSID";
char* password = "WIFI_PSWD";

WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "asia.pool.ntp.org", 19800, 60000);

char Time[ ] = "TIME:00:00:00";
char Date[ ] = "DATE:00/00/2000";
byte last_second, second_, minute_, hour_, day_, month_;
int year_;

void setup() {

  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print(" Internet Clock");
  delay(1000);
  

  WiFi.begin(ssid, password);
  Serial.print("Connecting.");

  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("connected");
  lcd.setCursor(0,0);
  lcd.print(" WIFI connected");
  delay(1000);
  lcd.clear();
  timeClient.begin();
}
 

void loop() {

  timeClient.update();
  unsigned long unix_epoch = timeClient.getEpochTime();

  second_ = second(unix_epoch);
  if (last_second != second_) {
 

    minute_ = minute(unix_epoch);
    hour_   = hour(unix_epoch);
    day_    = day(unix_epoch);
    month_  = month(unix_epoch);
    year_   = year(unix_epoch);

 

    Time[12] = second_ % 10 + 48;
    Time[11] = second_ / 10 + 48;
    Time[9]  = minute_ % 10 + 48;
    Time[8]  = minute_ / 10 + 48;
    Time[6]  = hour_   % 10 + 48;
    Time[5]  = hour_   / 10 + 48;

 

    Date[5]  = day_   / 10 + 48;
    Date[6]  = day_   % 10 + 48;
    Date[8]  = month_  / 10 + 48;
    Date[9]  = month_  % 10 + 48;
    Date[13] = (year_   / 10) % 10 + 48;
    Date[14] = year_   % 10 % 10 + 48;

    Serial.println(Time);
    Serial.println(Date);
    lcd.setCursor(0,0);
    lcd.print(" ");
    lcd.print(Time);
    lcd.setCursor(0,1);
    lcd.print(Date);
  }
  delay(500);
}
