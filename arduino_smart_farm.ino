#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
//software serial- SIM900A module
SoftwareSerial SIM900A (12, 13);// RX, TX
// or Software Serial on Uno, Nano...
SoftwareSerial EspSerial(3, 2); // RX, TX
#include <dht.h>
dht thSensor;
#define BLYNK_PRINT Serial
#define ESP8266_BAUD 9600
#define BLYNK_TEMPLATE_ID "TMPL6k0yhHvgc"
#define BLYNK_TEMPLATE_NAME "soil moisture monitor"
#define BLYNK_AUTH_TOKEN "xxxx xxxxxx xxxxxxxxx"
// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial1// Your ESP8266 baud rate:



//ldr module pins
#define ldr1 4
#define ldr2 5
#define ldr3 6
#define ldr4 7
//buzzer pins
#define buzzer 11

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Redmi Note 9";
char pass[] = "23456789";

ESP8266 wifi(&EspSerial);

 // slider value for water pump controller
int slider = 0; 
String msg;// msg variable

void setup()
{

// ldr sensors inputs
pinMode(ldr1, INPUT);
pinMode(ldr2,INPUT);
pinMode(ldr3, INPUT);
pinMode(ldr4,INPUT);


  // Debug console
  Serial.begin(9600);

 // gsm module
  SIM900A.begin(9600); // GSM Module Baud rate – communication speed
  
 delay(100);
 SIM900A.println("AT+CMGF=1"); //Text Mode initialisation
  delay(1000);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

 Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);

 pinMode(9,OUTPUT);// Water pump out

}

void loop()
{
  Blynk.run();
  soilMoisture();
  humidityAndTemp();

  //print recieved msg
if (SIM900A.available()>0){
Serial.write(SIM900A.read());
  }*/

  // test Switch cases
if (Serial.available()>0)
switch(Serial.read()){
    
 case 's':
    sendMessage();
    break;
 case 't':
    humidityAndTemp();
    break;
   } 

 ldrSensor1();
 ldrSensor2();
 ldrSensor3();
 ldrSensor4();*/

}
// ldr module function
void ldrSensor1(){
if(1==digitalRead(ldr1)>0){
msg="Warning sensor 1";
//Serial.println("warning p sensor1");
sendMessage();
buzzerTone();
delay(1000);
}
}
void ldrSensor2(){
if(1==digitalRead(ldr2)>0){
msg="Warning sensor 2";
//Serial.println("warning p sensor2");
sendMessage();
buzzerTone();
delay(1000);
}
}
void ldrSensor3(){
if(1==digitalRead(ldr3)>0){
msg="Warning sensor 3";  
//Serial.println("warning p sensor4");
sendMessage();
buzzerTone();
delay(1000);
}
}
void ldrSensor4(){
if(1==digitalRead(ldr4)>0){
msg="Warning sensor 4"; 
//Serial.println("warning p sensor4");
sendMessage();
buzzerTone();
delay(1000);
}
}





// msg function
void sendMessage()
{

  Serial.println("sending msg");
  SIM900A.println("AT+CMGS=\"+94784744706\"\r"); // Receiver’s Mobile Number
  delay(1000);
  
  SIM900A.println(msg);// Messsage content
  delay(100);
  
  SIM900A.println((char)26);
   delay(1000);
   
   }
// Secuirity alarm - laser system 
void buzzerTone()
{
for(int i=1;i<=10;i++){
tone (buzzer,450);
delay(500);
noTone(buzzer);
delay(500);
}
}








// Soil Moisture Sensor
void soilMoisture(){
const int dry = 622;
const int wet = 310;
  int soilSensVal = analogRead(A0);
  int percentageHum= map(soilSensVal, wet, dry, 100, 0);
 // Serial.print(percentageHum);
  //Serial.println("%");
  Blynk.virtualWrite(V0,percentageHum);
  delay(100);
// water pump on
if(percentageHum<=slider){
digitalWrite(9,LOW);
}
else
{
  digitalWrite(9,HIGH);
}


  }

// DHT 11 Temp And Humidity 

void humidityAndTemp()
{
  delay(1000);
int val = thSensor.read11(10);
//Serial.print("Temp is ");
//Serial.println(thSensor.temperature);
//Serial.print("Humidity is ");
//Serial.println(thSensor.humidity);
Blynk.virtualWrite(V1,thSensor.temperature);
Blynk.virtualWrite(V2,thSensor.humidity);
delay(1000);
}
//Slider for WaterPump
BLYNK_WRITE(V3){
slider= param.asInt();
}
