<p align="center">
  <a href="iotsnackbox.io" target="_blank" rel="noopener noreferrer"><img width="150" src="./assets/logo.png" alt="iotsnackbox.io">
  </a>
  <br>
  <a href="iotsnackbox.io"><img src="https://www.ardu-badge.com/badge/iotsnacksbox_server.svg?version=1.0.1" alt="Build Status">
  </a>
</p>

<h2 align="center">IoT Snacksbox Server Library for Arduino, Esp32, Esp8266.
</h2>


<p align="center">This library will help you to communicate with the IoT server. Will help control any component from the server. Will help to send any data from the device to the server. Basically it will be helpful for HTTP GET POST.
</p>

<br>
<br>



ℹ This library will only work in [iotsnackbox.io](https://iotsnacksbox.io/) environment. We recommend it for beginner level coders. If you are in advanced level you can also use it to skip huge lines of code. Otherwise you can use it.🙂 

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
 
<br>

## Installation ##

This library has some dependency with others library. If you don't have these library you can download it from here. 
1. [Arduino Json.](https://github.com/bblanchon/ArduinoJson)
2. [HTTP Client.](https://github.com/espressif/arduino-esp32/tree/master/libraries/HTTPClient)

[Tutorial for Installation](). 

<br>

## Usage And Examples ##

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

<br>

**1.0. GET Request**
<br>
<blockquote>
 GET is used to retrieve and request data from a specified resource in a server. GET is one of the most popular HTTP request techniques. In simple words, the GET method is used to retrieve whatever information is identified by the Request-URL. In case, when you send a GET Request() to the IoT Snacks Box Server, it sends back to you it's (Switch/Slider/Selection Switch/Action) position. Like it’s on/off or its position.
</blockquote>

<br>

**1.1. Get Request for Single Action/Switch :**
<br>


``` cpp
/* Include iotsnacksbox_server library. */
#include <iotsnacksbox_server.h>
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
<br>

**1.2. Get Request for Multiple Actions/Switch:**
<br>


``` cpp
/* Include iotsnacksbox_server library. */
#include <iotsnacksbox_server.h>
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

<br>
<br>

**2.0. POST Request**
<br>
<blockquote>
 POST Request: In web communication, POST requests are utilized to send data to a server to create or update a resource.  The information submitted to the server with POST request method is archived in the request body of the HTTP request. The HTTP POST method is often used to send user-generated data to a server. One example is when a user uploads a profile photo. If you want to see your data in IoT server in different widgets (Field value /Pi chart /Line chart/Bar chart/Area Chart), you need to send a POST Request() with your data like (Temperature : 30°C, Light : 220lm).
</blockquote>

<br>

**2.1. Post Request for Single Triger/Sensor:**
<br>

``` cpp
/* Include iotsnacksbox_server library. */
#include <iotsnacksbox_server.h>
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

<br>

**2.2. Post Request for Multiple Triger/Sensors:**
<br>

``` cpp
/* Include iotsnacksbox_server library. */
#include <iotsnacksbox_server.h>
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


## Contribution ##



## Credit ##



## Learn More ##


