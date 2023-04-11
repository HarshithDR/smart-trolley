#include <SPI.h> 
#include <MFRC522.h> 
#include <LiquidCrystal.h> 

#define SS_PIN 10 
#define RST_PIN 9 
MFRC522 mfrc522(SS_PIN, RST_PIN); 

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() { 
  Serial.begin(9600); 
  SPI.begin(); 
  mfrc522.PCD_Init(); 
  lcd.begin(16, 2); 
  lcd.print("Smart Trolley"); 
} 

void loop() { 
  lcd.print("Smart Trolley  "); 
  if ( ! mfrc522.PICC_IsNewCardPresent()) { 
    return; 
  } 

  if ( ! mfrc522.PICC_ReadCardSerial()) { 
    return; 
  } 

  lcd.clear(); 
  lcd.print("RFID Detected"); 
  delay(1000); 

  String cardId = ""; 

  for (byte i = 0; i < mfrc522.uid.size; i++) { 
    cardId.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "")); 
    cardId.concat(String(mfrc522.uid.uidByte[i], HEX)); 
  } 

  lcd.clear(); 
  //Serial.write(cardId);

  if (cardId == "f13cff19") { // (card)     replace with your RFID tag ID 
    //lcd.print(cardId);
    //delay(1000);
    lcd.print("Product:"); 
    delay(1000);
    lcd.print("bread");
    lcd.setCursor(0, 1); 
    lcd.print("Price: $1.00"); 
    delay(2000); 
  } 
  else if (cardId == "539b6e18") { // (keychain)      replace with your RFID tag ID 
    lcd.print("Product:");
    delay(1000);
    lcd.print("milk");
    lcd.setCursor(0, 1); 
    lcd.print("Price: $2.00"); 
    delay(2000); 
  } 
  else { 
    //lcd.print(cardId);
    lcd.print("Product NotFound"); 
    delay(2000); 
  } 
}
