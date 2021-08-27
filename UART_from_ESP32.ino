#include<WiFi.h>
#include<PubSubClient.h>
#include "UbidotsEsp32Mqtt.h"

using namespace std;

#define RX 0 
#define TX 1

const char* ssid = "";        //WiFi Name
const char* password = "";    //WiFi Password
const char* mqtt_server = "";
const char* token = "BBFF-ly2XaZuUeIARsriH4mPYzvjscjfEG7";

//char path[] = "";             //Path to be defined
char* host = "192.168.43.149";             //Host Name

WiFiClient espClient;
PubSubClient client(espClient);

String button_data = "";
String accelerometer_data = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400); //communicate with PC via usb
  Serial1.begin(9600, SERIAL_8N1, RX, TX);  //communicate with Vision
  
 
  WiFi.begin(ssid, password);                 //connect to WiFi
  while (WiFi.status() != WL_CONNECTED){
     delay(500);
     Serial.print(".");  
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  delay(500);

  client.setServer(mqtt_server,1883);
  //client.setCallback(callback); 
}

void loop(){
      delay(500);    
      button_data = String(Serial1.readStringUntil(' '));
      Serial.println("Button data recieved:" + button_data);
      accelerometer_data = String(Serial1.readStringUntil('\n')); 
      Serial.println("Accelerometer data recieved:" + accelerometer_data);
      //publish to mqtt broker

      
}
