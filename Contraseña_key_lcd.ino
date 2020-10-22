#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
 /* Funcion de configuracion de pines del modulo LCD/I2C 
    (Direccion,en,rw,rs,d4,d5,d6,d7,backlight,polaridad)*/
 LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const byte Filas = 4;  
const byte Cols = 4;   
byte Pins_Filas[] = {9,8,7,6};
Pins_Cols[] = {5,4,3,2}; 
//no utilizar los pines 1 y 0 para no interferir en Rx y Tx
char Teclas [ Filas ][ Cols ] =
 {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
 };
char codigoSecreto[4] = {'2','2','5','5'};
// Para cambiar el tamaño de la clave, solo hay que cambiar el tamaño del array
Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);

int posicion=0;    
int cursor=5;      
int clave=0;       
int luz=0;         
int tiempo=0;      
int ledVerde=11;   
int ledRojo=12;    
int buzzer=10;    

Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);
void setup()
   {
      Serial.begin(9600) ;
      lcd.begin(16,2);       
      lcd.noBacklight();     
      pinMode (ledVerde,OUTPUT);
      pinMode (ledRojo, OUTPUT);
      pinMode (buzzer, OUTPUT);
      digitalWrite(ledRojo,HIGH); 
      digitalWrite(ledVerde, LOW); 

      lcd.setCursor(0,0);     
      lcd.print("Introduzca clave"); 
      lcd.setCursor(cursor,1);
    }
    void loop()
   {
      char pulsacion = Teclado1.getKey() ;
      if (pulsacion != 0) 
        { 
          if (pulsacion != '#' && pulsacion != '*' && clave==0)
           { lcd.print(pulsacion); 
             cursor++;             
             tone(buzzer,350);    
             delay(200);
             noTone(buzzer);

      if (pulsacion == codigoSecreto[posicion])
          posicion ++;

      if (posicion == 4)
       { 
         digitalWrite (13,HIGH);  
         lcd.setCursor(0,0);      
         lcd.print("Clave correcta ");         
         delay(200);                           
         tone(buzzer,500);
         delay(100);
         noTone(buzzer);
         tone(buzzer,600);
         delay(100);
         noTone(buzzer);
         tone(buzzer,800);
         delay(100);
         noTone(buzzer);

         lcd.setCursor(5,1); 
         clave=1; 
         digitalWrite(ledRojo,LOW); 
         digitalWrite(ledVerde, HIGH); 
     }

     if(cursor>8)        
       {   cursor=5;     
           posicion=0;           
           lcd.setCursor(5,1);
           lcd.print(" ");       
           lcd.setCursor(5,1);
           if(clave==0)        
              { tone(buzzer,70,500); 
                delay(250); 
                noTone(buzzer);
              }
        }
     }
   } 
    if (pulsacion == '*')
     { 
       posicion = 0;
       cursor = 5;
       clave=0;
       posicion=0;
       lcd.setCursor(0,0); 
       lcd.print("Introduzca clave"); 
       lcd.setCursor(5,1);
       lcd.print(" "); 
       lcd.setCursor(5,1);
    
       digitalWrite(ledRojo,HIGH); 
       digitalWrite(ledVerde, LOW); 
    }
 }
//YO ♡ ARDUINO 
//DEV DAVID 
