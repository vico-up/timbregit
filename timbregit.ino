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
int tiempoTimbre = 5000;
int tiempoTimbre1 = 10000;

int hora;
int minuto;
int segundo;


/////////////////////Horario////////////////////

int h1 = 22; int m1 = 37; int se1 = 00;
int h2 = 22; int m2 = 38; int se2 = 00;
int h3 = 9; int m3 = 00; int se3 = 00;
int h4 = 9; int m4 = 20; int se4 = 00;
int h5 = 9; int m5 = 30; int se5 = 00;
int h6 = 10; int m6 = 00; int se6 = 00;
int h7 = 10; int m7 = 30; int se7 = 00;
int h8 = 11; int m8 = 00; int se8 = 00;
int h9 = 11; int m9 = 30; int se9 = 00;
int h10 = 11; int m10 = 40; int se10 = 00;
int h11 = 12; int m11 = 00; int se11 = 00;
int h12 = 12; int m12 = 20; int se12 = 00;


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

  if(timeClient.isTimeSet())
  {
    if(hora == h1 && minuto == m1 && segundo == se1)
    {
      if(diaInt == 1 || diaInt == 2 || diaInt == 3 || diaInt == 4 || diaInt == 5)
      {
        timbrar();
      }
    }
  }

  if(timeClient.isTimeSet())
  {
    if(hora == h2 && minuto == m2 && segundo == se2)
    {
      if(diaInt == 1 || diaInt == 2 || diaInt == 3 || diaInt == 4 || diaInt == 5)
      {
        timbrar1();
      }
    }
  }

  
 
  delay(1000);

  
  
  


}

void timbrar()
{
 digitalWrite(timbre, HIGH);
 delay(tiempoTimbre);
 digitalWrite(timbre, LOW);
}

void timbrar1()
{
 digitalWrite(timbre, HIGH);
 delay(tiempoTimbre1);
 digitalWrite(timbre, LOW);
}