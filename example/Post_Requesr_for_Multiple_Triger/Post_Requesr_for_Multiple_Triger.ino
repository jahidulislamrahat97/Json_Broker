/*********************************************************************************
   If this code works, it was written by Jahidul Islam Rahat.
   If not, I don't know who wrote it.
   :) xD

   Author: Jahidul Islam Rahat.
   Date: 2 Feb 2021.
*********************************************************************************/
/*
   Example code for Json Broker Libray.()
   IoT Dashboard: https://iotsnacksbox.io/ - (IoT Snacksbox is an IoT server.
   where you can use it for factory monitoring, Appliances Control,
   Data Visualization, Smart Production Planning, Data Backup, Access Control,
   Security monitoring and Inter Machine Communication.)
   ***You can use it free for your school project.***
   School of IoT: https://www.anttrobotics.com/schoolofiot
*/


#include <WiFi.h>
#include <iotsnacksbox_server.h>

// Replace with your network credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

/*
   Use this Api to post sensor value on server.
   Replace with your Token and Triger name.
   "https://api.iotsnacksbox.io/trigger/Triger_Name?snacksboxtoken=Replace_with_your_Token"
   In this case my api is look like this:"https://api.iotsnacksbox.io/trigger/WeatherStation?snacksboxtoken=ab4f6a52ba46a5"
   If you don't understand this api. Read api documantation here for IoT Snacksbox:
*/
const char* Post_Server_Name = "https://api.iotsnacksbox.io/trigger/WeatherStation?snacksboxtoken=Replace_with_your_Token";

int Smoke_sensor       = 39;
int Temperature_sensor = 36;
int LDR_sensor         = 34;


void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());


  pinMode(Smoke_sensor, INPUT);
  pinMode(Temperature_sensor, INPUT);
  pinMode(LDR_sensor, INPUT);





}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    int Smoke_sensor_value = analogRead(Smoke_sensor);
    int Temperature_sensor_value = analogRead(Temperature_sensor);
    int LDR_sensor_value = analogRead(LDR_sensor);
    /*********************************************************/
    int Componant_number = 3;//number of sensor/triger in your project.
    String Name[] = {"Smoke", "Temperature", "Light"};
    int Data[] = {Smoke_sensor_value, Temperature_sensor_value, LDR_sensor_value};
    /*
       Use this function to Post Sensor/Triger  Data/Value to Server.
       Just Replace Server name, in this case my server name Post_serverName.
       Else don't need to change anything in this function.
       Send_Data_To_Server(Componant_number, Name, Data, Post_Server_Name)
    */
    Send_Data_To_Server(Componant_number, Name, Data, Post_Server_Name);
    /*********************************************************/






  }
  else {
    Serial.println("WiFi Disconnected");
  }

}
