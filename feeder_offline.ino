#include <ESP8266WiFi.h>
#include <time.h>
#include <Servo.h> 

const char* ssid     = "Trai Tim Ben Le";
const char* password = "hello125";     
const int timezone = 7;
const int dst = 0;
const int NUM_TANK = 4;
int wifiStatus;
Servo gServo1, gServo2, gServo3, gServo4;
Servo listServo[NUM_TANK] = {gServo1, gServo2, gServo3, gServo4};
const int FEED_TIMES[3] = {6, 13, 19};
const int PINS[NUM_TANK] = {D0, D2, D4, D5};
const int SWITCH = D7;
const int FISH[NUM_TANK] = {20, 20, 20, 20};

void setup()
{  
  Serial.begin(115200);
  configTime();
  pinMode(SWITCH, INPUT_PULLUP);
}

void configTime(){
  configTime(timezone * 3600, dst, "pool.ntp.org", "time.nist.gov");  
  while (!time(nullptr)) {
    Serial.print(".");
    delay(1000);
  }
}

//void connectWifi(){
//  Serial.println();
//  Serial.print("Your are connecting to;");
//  Serial.println(ssid);  
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(1000);
//    Serial.print(".");
//  }
//}
     
void loop() {
  time_t now = time(nullptr);  
  Serial.println(ctime(&now));
  struct tm *tmp = gmtime(&now);
  for(int s = 0; s < 60;  s++)
  {
    if(s==0)
    {
      for(int i = 0; i < 3; i++)
      {
        if(FEED_TIMES[i] == tmp->tm_hour)
        {
          if(tmp->tm_min == 0)
          {
            Serial.println("FEED");
            feedAll();
          }      
        }      
      }
    }
    if(digitalRead(SWITCH) == HIGH)
    {
      feedAll();
      break;
    }
    delay(1000);
  }
}

void feedAll()
{
   for(int i=0; i<3; i++)
   {
      for(int j=0; j<NUM_TANK; j++)
      { 
        listServo[j].attach(PINS[j]); 
        listServo[j].write(180);
        delay(100 * FISH[j]);
        listServo[j].detach();
        delay(5000);
      }
      delay(10000);
   }
}
