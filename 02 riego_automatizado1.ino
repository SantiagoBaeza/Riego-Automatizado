#include <LiquidCrystal.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int verde = 4;
int amarillo = 5;
int rojo = 6;
int rele = 2;

int humedad;
String estadoActual = "";

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Sistema Riego");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();

  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(rele, OUTPUT);
}

void loop() {
  humedad = analogRead(A0);
  String nuevoEstado;

  if (humedad < 300) {
    // Suelo seco
    digitalWrite(rojo, HIGH);
    digitalWrite(amarillo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(rele, HIGH);
    nuevoEstado = "Suelo seco";
  } 
  else if (humedad < 700) {
    // Suelo con humedad media
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(rele, LOW);
    nuevoEstado = "Humedad media";
  } 
  else {
    // Suelo húmedo
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(verde, HIGH);
    digitalWrite(rele, LOW);
    nuevoEstado = "Suelo humedo";
  }

  // Solo actualiza el LCD si cambia el estado
  if (nuevoEstado != estadoActual) {
    estadoActual = nuevoEstado;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(estadoActual);

    lcd.setCursor(0, 1);
    if (humedad < 300) {
      lcd.print("Bomba: ENCENDIDA");
    } else {
      lcd.print("Bomba: apagada ");
    }
  }

  delay(500);  // Pequeño retardo para estabilidad
}
