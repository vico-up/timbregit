

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "Martinez-2.4G";
const char *password = "Guadalupe";

//Ajustar zona horaria a bolivia
const long utcOffsetInSeconds = -14400;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
 
String diasSemana[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
int diaInt;     //Guarda el dia en entero 0-6 respectivamente
String diaActual; //transforma dia en enteros en string

const int timbre = 5;   //pin de salida para activar el rele
int tiempoTimbre = 2500;
int tiempoTimbre1 = 5500;

int hora;
int minuto;
int segundo;


/////////////////////Horario////////////////////

int h1 = 8; int m1 = 00; int se1 = 00;
int h2 = 9; int m2 = 00; int se2 = 00;
int h3 = 9; int m3 = 20; int se3 = 00;
int h4 = 10; int m4 = 00; int se4 = 00;
int h5 = 10; int m5 = 30; int se5 = 00;
int h6 = 11; int m6 = 00; int se6 = 00;
int h7 = 12; int m7 = 00; int se7 = 00;
int h8 = 12; int m8 = 20; int se8 = 00;


void setup() 
{
  Serial.begin(9600);
  pinMode(timbre, OUTPUT);
  
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  timeClient.begin();

}

void loop() 
{
  timeClient.update();

  hora = timeClient.getHours();
  minuto = timeClient.getMinutes();
  segundo = timeClient.getSeconds();

  diaInt = timeClient.getDay();
  diaActual = diasSemana[diaInt];
  
  Serial.print(diaActual);
  Serial.print(", ");
  Serial.println(timeClient.getFormattedTime());

  // tocar 1

  if(timeClient.isTimeSet())
  {
    if(hora == h1 && minuto == m1)
    {
      if(diaInt == 1 || diaInt == 2 || diaInt == 3 || diaInt == 4 || diaInt == 5)
      {
        Serial.println("ok");
        tocar1();
      }
    }
  }

  //tocar 2

  if(timeClient.isTimeSet())
  {
    if(hora == h2 && minuto == m2)
    {
      if(diaInt == 1 || diaInt == 2 || diaInt == 3 || diaInt == 4 || diaInt == 5)
      {
        Serial.println("ok");
        tocar();
      }
    }
  }

   //tocar 3

  if(timeClient.isTimeSet())
  {
    if(hora == h3 && minuto == m3)
    {
      if(diaInt == 1 || diaInt == 2 || diaInt == 3 || diaInt == 4 || diaInt == 5)
      {
        Serial.println("ok");
        tocar();
      }
    }
  }

   //tocar 4

  if(timeClient.isTimeSet())
  {
    if(hora == h4 && minuto == m4)
    {
      if(diaInt == 1 || diaInt == 2 || diaInt == 3 || diaInt == 4 || diaInt == 5)
      {
        Serial.println("ok");
        tocar1();
      }
    }
  }

   //tocar 5

  if(timeClient.isTimeSet())
  {
    if(hora == h5 && minuto == m5)
    {
      if(diaInt == 1 || diaInt == 2 || diaInt == 3 || diaInt == 4 || diaInt == 5)
      {
        Serial.println("ok");
        tocar1();
      }
    }
  }

   //tocar 6

  if(timeClient.isTimeSet())
  {
    if(hora == h6 && minuto == m6)
    {
      if(diaInt == 1 || diaInt == 2 || diaInt == 3 || diaInt == 4 || diaInt == 5)
      {
        Serial.println("ok");
        tocar1();
      }
    }
  }

   //tocar 7

  if(timeClient.isTimeSet())
  {
    if(hora == h7 && minuto == m7)
    {
      if(diaInt == 1 || diaInt == 2 || diaInt == 3 || diaInt == 4 || diaInt == 5)
      {
        Serial.println("ok");
        tocar1();
      }
    }
  }

   //tocar 8

  if(timeClient.isTimeSet())
  {
    if(hora == h8 && minuto == m8)
    {
      if(diaInt == 1 || diaInt == 2 || diaInt == 3 || diaInt == 4 || diaInt == 5)
      {
        Serial.println("ok");
        tocar1();
      }
    }
  }

delay(1000);

}

void tocar()
{
 digitalWrite(timbre, HIGH);
 delay(tiempoTimbre);
 digitalWrite(timbre, LOW);
 delay(60000);
}

void tocar1()
{
 digitalWrite(timbre, HIGH);
 delay(tiempoTimbre1);
 digitalWrite(timbre, LOW);
 delay(60000);
}