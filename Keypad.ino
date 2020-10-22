#include<Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const byte Filas = 4;
const byte Columnas = 4;
har matriz[Filas][Columnas] = 
{
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte pinesFilas[Filas] = {9,8,7,6};
byte pinesColumnas[Columnas] = {5,4,3,2};
Keypad Teclado = Keypad(makeKeymap(matriz),pinesFilas,pinesColumnas,Filas,Columnas);
void setup()
{
Serial.begin(9600);
}
void loop(){
char key = Teclado.getKey();
if (key != NO_KEY)   
if (key != 0)
Serial.print(key);
}
