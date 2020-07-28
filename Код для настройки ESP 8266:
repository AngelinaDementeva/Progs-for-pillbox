#include <ESP8266WiFi.h>


const char* _ssid = "TP-Link_3CF3";
const char* _password = "37502720";

WiFiServer server(5000); 

char data[250], dcr[250];
int ind=0, icd=0;

WiFiClient client;

void setup() {

Serial.begin(9600);
delay(10);
WiFi.mode(WIFI_STA);
WiFi.begin(_ssid, _password);

while (WiFi.status() !=WL_CONNECTED)
{
  delay(500);
  }
server.begin();
Serial.print("connected");
Serial.print(WiFi.localIP());

}

void loop() {
if (!client.connected()){
  client = server.available();
  }
  else{
    if (Serial.available()>0){
      while(Serial.available()){
        dcr[icd] = Serial.read();
        icd ++;
        }
      for (int j=0; j<icd; j++){
        client.print(dcr[j]);
        }
      
      }
      if (client.available()>0){
        while(client.available()){
        data[ind] = client.read(); 
        ind ++;         
        }
        client.flush();
      for (int j=0; j<15; j++){        
         Serial.print(data[j]);
    }         
   }
  ind=0;
  icd=0;
  } 
     
 }
