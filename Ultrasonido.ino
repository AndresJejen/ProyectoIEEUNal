#include "DHT.h"
DHT dht(7, DHT11);
const unsigned int TRIG_PIN=8;
const unsigned int ECHO_PIN=9;
const unsigned int BAUD_RATE=9600;

const unsigned int RefT=25;
const unsigned int RefNivel=5;
const unsigned int RefH=80;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(BAUD_RATE);

  // PREPARAR LA LIBRERIA PARA COMUNICARSE CON EL SENSOR
  dht.begin();
}

void loop() {

// ESPERAR ENTRE MEDICIONES, NECESARIO PARA EL BUEN FUNCIONAMIENTO
  delay(2000);
  // LEER LA HUMEDAD USANDO EL METRODO READHUMIDITY
  float h = dht.readHumidity();
  // LEER LA TEMPERATURA USANDO EL METRODO READTEMPERATURE
  float t = dht.readTemperature();
  // REVISAR QUE LOS RESULTADOS SEAN VALORES NUMERICOS VALIDOS, INDICANDO QUE LA COMUNICACION ES CORRECTA
  if (isnan(h) || isnan(t)) {
    Serial.println("Falla al leer el sensor DHT11!");
    return;
  }
  //Leer Sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  

 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration/29/2;
 if(duration==0){
   Serial.println("Warning: no pulse from sensor");
   } 
  else{
      Serial.print("distance to nearest object:");
      Serial.println(distance);
      Serial.println(" cm");
        // IMPRIMIR RESULTADO AL MONITOR SERIAL
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");
  }
 delay(100);


  if((distance>RefNivel)||(t>RefT)||(h>RefH))
  {
   if(distance>RefNivel)
   {
    Serial.println("Recargar Agua");
    }
    else{}

    if(t>RefT)
   {
    Serial.println("Activar Ventilador");
    }
    else{}

    if(h>RefH)
   {
    Serial.println("Regar Planta");
    }
    else{}
  }
  else
  {
    Serial.println("Todo Ok");
  }

 
}
