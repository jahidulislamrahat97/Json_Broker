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
   Use this Api for get Switch/Action value.
   Replace with your Token.
   If you don't understand this api. Read api documantation here for IoT Snacksbox:
*/
const char* Get_serverName = "https://api.iotsnacksbox.io/actions?snacksboxtoken=Replace_with_your_Token";

int Led = 4;

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


  pinMode(Led, OUTPUT);
  digitalWrite(Led, LOW);

}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    /*********************************************************/
    int Componant_number = 1;//number of switch/action in your project.
    int Componant[Componant_number];
    int* Componant_Value;
    /*
       Use this function to Get switch/action value from Server.
       Just Replace Server name, in this case my server name Get_serverName.
       Else don't need to change anything in this function.
       Send_Get_Request_To_Server_Get_Actions(Componant_number, Get_serverName, Componant)
    */
    Componant_Value = Send_Get_Request_To_Server_Get_Actions(Componant_number, Get_serverName, Componant);
   
    Serial.println(Componant_Value[0]);//use index number from 0 to get your switch/action value individually from server.
    /*********************************************************/



    // make condition/logic what you need
    if (Componant_Value[0] == 1) {
      digitalWrite(Led, HIGH);
    }
    else if (Componant_Value[0] == 0) {
      digitalWrite(Led, LOW);
    }



  }
  else {
    Serial.println("WiFi Disconnected");
  }

}
