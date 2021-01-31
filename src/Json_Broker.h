#ifndef Json_Broker_H
#define Json_Broker_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WString.h>
#include <HTTPClient.h>

int* Send_Get_Request_To_Server_Get_Actions(int Componant_number, String Server_Name, int *Componant);
void Send_Data_To_Server(int Number, String *Component_name, int *Componant_value, String Server_name);

#endif
