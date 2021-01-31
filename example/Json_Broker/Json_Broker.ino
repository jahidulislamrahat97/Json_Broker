#include <WiFi.h>
#include <Json_Broker.h>

const char* ssid = "House of R&D";
const char* password = "12345HouseofR&D";

const char* serverName = "https://api.iotsnacksbox.io/actions?snacksboxtoken=ab4f6a52ba46a57d30052b671f31fed6de40cc732aee2523e1b42c5a070c47e4";

const char* Post_Server_Name = "https://api.iotsnacksbox.io/trigger/Smoke?snacksboxtoken=ab4f6a52ba46a57d30052b671f31fed6de40cc732aee2523e1b42c5a070c47e4";


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



  int Number = 3;
  String Name[] = {"AAA", "BBB", "CCC"};
  int Data[] = {23, 35, 95};
  Send_Data_To_Server(Number, Name, Data, Post_Server_Name);














  //  if (WiFi.status() == WL_CONNECTED) {
  //
  //    /*********************************************************/
  //    int Componant_number = 4;
  //    int Componant[Componant_number];
  //    int* Componant_Value;
  //    Componant_Value = Send_Get_Request_To_Server_Get_Actions(Componant_number, serverName, Componant);
  //    Serial.println(Componant_Value[0]);
  //    Serial.println(Componant_Value[1]);
  //    Serial.println(Componant_Value[2]);
  //    Serial.println(Componant_Value[3]);
  //
  //
  //    /*********************************************************/
  //  }
  //  else {
  //    Serial.println("WiFi Disconnected");
  //  }


}
