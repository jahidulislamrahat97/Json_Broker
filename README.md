# Json Broker Library for Arduino, esp32, esp8266. # 

# Overview #

This library will only work in [iotsnackbox.io](https://iotsnacksbox.io/) environment. We recommend it for beginner level coders. If you are in advanced level you can also use it to skip huge lines of code. Otherwise you can use it. 

<br>

**What is iotsnacks box?**
<br>
<blockquote> IoT snacks box is an integrated hardware and software platform to deliver end-to-end IoT solutions. Using this device and platform, data can remotely monitor & control by automate processes through IoT.
</blockquote>
<br>

**What types of work can be done by iotsnacksbox?**
<br>
<blockquote>
Automate processes for  agriculture, industry automation, energy control, healthcare, datalogging and any other system that  can be solved using IoT. With the latest technology and user engaging user experience design with the  finest architecture our web platform allows users to deploy cloud IoT applications, control & monitor  dashboards with any IoT devices. 
</blockquote>
<br>

**iotsnacksbox for whom?**
<br>
<blockquote>
This development board provides a range of features that allow developers to build advanced application for smart home, education purpose, gardening, security system specially industrial automation and agricultural sectors.
</blockquote>
 
# Installation #

This library has some dependency with others library. If you don't have these library you can download it from here. 
1. [Arduino Json.](https://github.com/bblanchon/ArduinoJson)
2. [HTTP Client.](https://github.com/espressif/arduino-esp32/tree/master/libraries/HTTPClient)

***If you don't understand see the [Tutorial for Installation](). 


# Usage And Examples #

```
HTTP Request.
  ├── 1.0. HTTP Get Request.
  │   ├── 1.1. HTTP Get Request for Single Action.
  │   └── 1.2. HTTP Get Request for Multiple Actions.
  └── 2.0. HTTP Post Request.
      ├── 2.1.HTTP Post Request for Single Triger.
      └── 2.1.HTTP Post Request for Multiple Trigers.
```

```
widgets
  ├── 1.0. Action.
  │   ├── 1.1. On/Off Switch.
  │   ├── 1.2. Slider Switch.
  │   └── 1.3. Selection Switch.
  └── 2.0. Triger
      ├── 2.1. Field Value.
      ├── 2.2. pi Chart.
      ├── 2.3. Bar Chart.
      ├── 2.4. Line Chart.
      └── 2.5. Area Chart.
```

>>## 1.0.  Get Request : When you send a 'get request' to the server, it sends back to you it's update. In case, when you send a ‘get request’ to the IoT Snacks Box Server, it sends back to you it's  ([Switch]() / [Slider]() / [Selection switch]() / [Action]()) Position. Like is it on/off or its position.  ##


>>   ## 1.1. Get Request for Single Action/Switch: ##


``` cpp
/* Include Json_Broker library. */
#include <Json_Broker.h>
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

/*
   Use this Api for get Switch/Action value.
   Replace with your Token.
   If you don't understand this api. Read api documantation here for IoT Snacksbox:
*/
const char* Get_serverName = "https://api.iotsnacksbox.io/actions?snacksboxtoken=Replace_with_your_Token";


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

  }
  else {
    Serial.println("WiFi Disconnected");
  }

}
```
>>   ## 1.2. Get Request for Multiple Action/Switch: ##


``` cpp
/* Include Json_Broker library. */
#include <Json_Broker.h>
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

/*
   Use this Api for get Switch/Action value.
   Replace with your Token.
   If you don't understand this api. Read api documantation here for IoT Snacksbox:
*/
const char* Get_serverName = "https://api.iotsnacksbox.io/actions?snacksboxtoken=Replace_with_your_Token";


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


  }
  else {
    Serial.println("WiFi Disconnected");
  }

}
```
*** If you don't understand see the [Api documentation for GET Request](), [Tutorial for GET Request](). 



>> ## 2.0.  Post Request: If you want to see your data to IoT server in different widgets like [Field value]() / [pi chart]() / [Line chart]() / [Bar chart]() / [Area Chart](). you need to send a post request with your data. like (Temperature : 30°C, Light : 220lm).     ##

>> ## 2.1. Post Request for Single Triger/Sensor: ##


``` cpp
/* Include Json_Broker library. */
#include <Json_Broker.h>
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

/*
   Use this Api to post sensor value on server.
   Replace with your Token and Triger name.
   "https://api.iotsnacksbox.io/trigger/Triger_Name?snacksboxtoken=Replace_with_your_Token"
   In this case my api is look like this:"https://api.iotsnacksbox.io/trigger/Smoke?snacksboxtoken=ab4f6a52ba46a5"
   If you don't understand this api. Read api documantation here for IoT Snacksbox:
*/
const char* Post_Server_Name = "https://api.iotsnacksbox.io/trigger/Smoke?snacksboxtoken=Replace_with_your_Token";

int Smoke_sensor = 39;

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


}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    int Smoke_sensor_value = analogRead(Smoke_sensor);
    /*********************************************************/
    int Componant_number = 1;//number of sensor/triger in your project.
    String Name[] = {"Smoke"};
    int Data[] = {Smoke_sensor_value};
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


```
>> ## 2.1. Post Request for Multiple Triger/Sensors: ##



``` cpp
/* Include Json_Broker library. */
#include <Json_Broker.h>
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

/*
   Use this Api to post sensor value on server.
   Replace with your Token and Triger name.
   "https://api.iotsnacksbox.io/trigger/Triger_Name?snacksboxtoken=Replace_with_your_Token"
   In this case my api is look like this:"https://api.iotsnacksbox.io/trigger/Smoke?snacksboxtoken=ab4f6a52ba46a5"
   If you don't understand this api. Read api documantation here for IoT Snacksbox:
*/
const char* Post_Server_Name = "https://api.iotsnacksbox.io/trigger/Smoke?snacksboxtoken=Replace_with_your_Token";

int Smoke_sensor = 39;

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

}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    int Smoke_sensor_value = analogRead(Smoke_sensor);
    /*********************************************************/
    int Componant_number = 1;//number of sensor/triger in your project.
    String Name[] = {"Smoke"};
    int Data[] = {Smoke_sensor_value};
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


``` 
*** If you don't understand see the [Api documentation for POST Request ](), [Tutorial for POST Request](). 


# Contribution #

You cannot contribute to this repository. If you want to contribute, go to the [developer's repository]().



# Credit #
<p align="center">
  <a href="#">
    <img alt="Rahat" src="https://avatars.githubusercontent.com/u/41055866?s=460&u=52d15e31f977e41498fab3b4ba4128d1c27cdf0f&v=4" width="100"  />
  </a>
  <h1 align="center" style="margin-bottom: 0px;  border: 0;">Jahidul Islam Rahat
  </h1>
  <div  width: 500px; height: 50px; margin-top: 10px; vertical-align: middle; align="center">
    <img src="https://camo.githubusercontent.com/013ab4b8c0a14af1d626b6106c10a4ca83129f9b89d063db25612dcb88740bc5/68747470733a2f2f63646e2e6a7364656c6976722e6e65742f6e706d2f73696d706c652d69636f6e734076332f69636f6e732f66616365626f6f6b2e737667" style=" width: 50px; height: 50px; border-radius: 500px; float:left; margin-left: 11px;">    

  <img src="https://camo.githubusercontent.com/c80f9763ed06d4ab9fbcc1a74b8b74cd95e4c7f82d3f1f70233994f236a0faeb/68747470733a2f2f63646e2e6a7364656c6976722e6e65742f6e706d2f73696d706c652d69636f6e734076332f69636f6e732f696e7374616772616d2e737667" style=" width: 50px; height: 50px; border-radius: 500px; float:left; margin-left: 11px;">   

  <img src="https://camo.githubusercontent.com/d659d2bac00c01b42bffbae84bdc121e828b8fecd5b4949ffa2575f5d9e4a371/68747470733a2f2f63646e2e6a7364656c6976722e6e65742f6e706d2f73696d706c652d69636f6e734076332f69636f6e732f6c696e6b6564696e2e737667" style=" width: 50px; height: 50px; border-radius: 500px; float:left; margin-left: 11px;">   

  <img src="https://camo.githubusercontent.com/5f5cadad3e06f6dd96c64d4025e219856ae6f923799bc8ea4e628013de25724a/68747470733a2f2f63646e2e6a7364656c6976722e6e65742f6e706d2f73696d706c652d69636f6e734076332f69636f6e732f6769746875622e737667" style=" width: 50px; height: 50px; border-radius: 500px; float:left; margin-left: 11px;">  

 </div>
</p>

<br>
<br>
<br>
<br>

# Learn More #


