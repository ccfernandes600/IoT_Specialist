/***********************************************************
*
* Projeto IOT  – Sensor de temperatura com alarme e motor
*
*************************************************************/
#include <math.h>
const int Sensor_temp = 0; // entrada sensor: A0 - Analógica
float temperatura = 0; // variável tipo float - inícia no 0
int ADClido = 0;
const int Buzzer = 8; // entrada buzzer: 8 - digital
const int Led = 7; // entrada led: 7 - digital
const int motor = 9; //entrada motor: 9 - digital 
float Tensao; 
//************************************************************
void setup(){
Serial.begin(9600); // taxa comunicação da placa com o computador
analogReference(INTERNAL); //No Mega, use INTERNAL1V1, no Leonardo remova essa linha
pinMode(Buzzer, OUTPUT);
pinMode(Led, OUTPUT);
pinMode(motor, OUTPUT);
}
 
//************************************************************

void loop(){
temperatura = analogRead(Sensor_temp);
temperatura = temperatura *1100 / (1024 *10); 
Serial.print("Temperatura = "); //mostra valor na tela
Serial.print(temperatura);
Serial.println(" *C");    
if(temperatura > 29 and temperatura <49.99 ){ // setado como 30ºC
digitalWrite(motor, HIGH); //aciona o motor
}
  
else if(temperatura > 50){ 
digitalWrite(Buzzer, HIGH); //aciona o Buzzer
digitalWrite(Led, HIGH); //aciona o Led
digitalWrite(motor, HIGH); //aciona o motor
}
  
else{

digitalWrite(Buzzer, LOW); //desliga o Buzzer
digitalWrite(Led, LOW); //Desliga o Led
digitalWrite(motor, LOW); //Desliga motor
}  
delay(1000);
}