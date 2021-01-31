#include "Json_Broker.h"



int* Send_Get_Request_To_Server_Get_Actions(int Componant_number, String Server_Name, int *Componant) {
  Serial.println("*********************************************");
  Serial.print("Server Name: ");
  Serial.println(Server_Name);
  Serial.println("Request Type: Get Request");
  Serial.println("Sending Get Request to the Server.....");

  HTTPClient http;
  String serverPath = Server_Name;
  // Your Domain name with URL path or IP address with path
  http.begin(serverPath.c_str());
  // Send HTTP GET request
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.print("Payload/JSON from Server:");
    Serial.println(payload);

    static int deserializ_memory = 384 * Componant_number;
    DynamicJsonDocument doc(deserializ_memory);
    deserializeJson(doc, payload);
    const char* Componant_Name[Componant_number];
    Serial.println("Componant ID\tComponant Name\tValue");
    for (int i = 0; i < Componant_number; i++ ) {
      JsonObject action = doc[i];
      Componant_Name[i] = action["name"];//Componant value
      Componant[i] = action["value"];//Componant value
      Serial.print("Componant ");
      Serial.print(i);
      Serial.print("\t");
      Serial.print(Componant_Name[i]);
      Serial.print("\t\t");
      Serial.println(Componant[i]);
    }

  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();
  Serial.println("Sending Request End.");
  return Componant;//value

}

void Send_Data_To_Server(int Number, String *Component_name, int *Componant_value, String Server_name) {
 
  Serial.println("Sending Data To Server...");
  
  HTTPClient http;
  http.begin(Server_name);
  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.addHeader("Content-Type", "application/json");
  
  String DBQ = "\"";
  String DBQC = "\":";
  String Primary = "{\"data\":{\"";
  String Comma = ",";
  String Current = "{\"data\":{\"";

  for (int i = 0; i < Number; i++) {
    if (i > 0) {
      Current = Current + Comma + DBQ + Component_name[i] + DBQC + String(Componant_value[i]);
    }
    else {
      Current = Current + Component_name[i] + DBQC + String(Componant_value[i]);
    }
  }
  Current = Current + "}}";
  Serial.println(Current);
  
  String httpRequestData = Current;
  int httpResponseCode = http.POST(httpRequestData);
  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);
  http.end();

}
