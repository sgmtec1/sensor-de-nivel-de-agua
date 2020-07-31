/*
Sensor de água
*/
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define pino_sinal_analogico A0
int valor_analogico;
int medicao_agua;

void setup() {
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  lcd.begin(16, 2);
}
void loop() {
  //Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.print(" NIVEL DA AGUA: ");
  Serial.print(valor_analogico);
  lcd.clear();
  // Print a message to the LCD.
  lcd.print(" SENSOR DE AGUA ");
  lcd.setCursor(0,1);
  lcd.print("  SGMAUTOMACAO");
 
  //SEM AGUA
  if (valor_analogico > 0 && valor_analogico < 220)
  {
    Serial.println(" Status: SEM  AGUA");
      lcd.clear();
      // Print a message to the LCD.
      lcd.setCursor(0,0);
      lcd.print("NIVEL AGUA: 0%");
      lcd.setCursor(0,1);
      lcd.print("SEM AGUA ");     
  }
 
  //Solo com umidade moderada, acende led amarelo
  if (valor_analogico > 220 && valor_analogico < 430)
  {
    Serial.println(" Status: NIVEL BAIXO");
      lcd.clear();
      // Print a message to the LCD.
      lcd.setCursor(0,0);
      lcd.print("NIVEL AGUA: ");
      lcd.setCursor(0,1);
      lcd.print("BAIXO ");
  }
 
  //Solo seco, acende led vermelho
  if (valor_analogico > 430 && valor_analogico < 700)
  {
    Serial.println(" Status: NIVEL ALTO");
    lcd.clear();
    // Print a message to the LCD.
      lcd.setCursor(0,0);
      lcd.print("NIVEL AGUA: 100%");
      lcd.setCursor(0,1);
      lcd.print("ALTO ");
  }
  delay(100);

  
  // Turn off the blinking cursor:
  lcd.noBlink();
  delay(1000);
  // Turn on the blinking cursor:
  lcd.blink();
  delay(1000);
}
