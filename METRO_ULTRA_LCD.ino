     #define trigPin 2
     #define echoPin 3
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

// Constructor de la librería de LCD 16x2
// Aqui se configuran los pines asignados a la pantalla del PCF8574
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
     void setup()
        {   Serial.begin (9600);
            pinMode(trigPin, OUTPUT);
            pinMode(echoPin, INPUT); 
            lcd.begin(16, 2);
        }

     void loop()
        {   long duracion, distancia ;
            digitalWrite(trigPin, LOW);        // Nos aseguramos de que el trigger está desactivado
            delayMicroseconds(2);              // Para asegurarnos de que el trigger esta LOW
            digitalWrite(trigPin, HIGH);       // Activamos el pulso de salida
            delayMicroseconds(10);             // Esperamos 10µs. El pulso sigue active este tiempo
            digitalWrite(trigPin, LOW);        // Cortamos el pulso y a esperar el echo
            duracion = pulseIn(echoPin, HIGH) ;
            distancia = duracion / 2 / 29.1  ;
            lcd.setCursor ( 0, 0 );
            Serial.println(String(distancia) + " cm.") ;
            lcd.print("LA DISTANCIA ES: ") ;
            lcd.setCursor ( 4, 1 );
            lcd.println(String(distancia) + " cm.") ;
            delay (500) ;                  // Para limitar el número de mediciones
        }
