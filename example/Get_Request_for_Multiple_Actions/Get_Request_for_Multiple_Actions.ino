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
#include <Json_Broker.h>

// Replace with your network credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

/*
   Use this Api for get Switch/Action value.
   Replace with your Token.
   If you don't understand this api. Read api documantation here for IoT Snacksbox:
*/
const char* Get_serverName = "https://api.iotsnacksbox.io/actions?snacksboxtoken=Replace_with_your_Token";

int Led1   = 2;
int Led2   = 4;
int Buzzer = 25;


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


  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Buzzer, LOW);


}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

     /*********************************************************/
    int Componant_number = 3;//number of switch/action in your project.
    int Componant[Componant_number];
    int* Componant_Value;
    /*
       Use this function to Get switch/action value from Server.
       Just Replace Server name, in this case my server name Get_serverName.
       Else don't need to change anything in this function.
       Send_Get_Request_To_Server_Get_Actions(Componant_number, Get_serverName, Componant)
    */
    Componant_Value = Send_Get_Request_To_Server_Get_Actions(Componant_number, Get_serverName, Componant);
   
    //use index number from 0 to get your switch/action value from server.
    Serial.println(Componant_Value[0]); //for 1 no switch/action
    Serial.println(Componant_Value[1]); //for 2 no switch/action
    Serial.println(Componant_Value[2]); //for 3 no switch/action
    /*********************************************************/



    // make condition/logic what you need
    if (Componant_Value[0] == 1) {
      digitalWrite(Led1, HIGH);
    }
    else if (Componant_Value[0] == 0) {
      digitalWrite(Led1, LOW);
    }
    
    if (Componant_Value[1] == 1) {
      digitalWrite(Led2, HIGH);
    }
    else if (Componant_Value[1] == 0) {
      digitalWrite(Led2, LOW);
    }
    
    if (Componant_Value[2] == 1) {
      digitalWrite(Buzzer, HIGH);
    }
    else if (Componant_Value[2] == 0) {
      digitalWrite(Buzzer, LOW);
    }



  }
  else {
    Serial.println("WiFi Disconnected");
  }

}
