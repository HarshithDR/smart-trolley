#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Get the current UID
    byte currentUid[4];
    for (int i = 0; i < 4; i++) {
      currentUid[i] = mfrc522.uid.uidByte[i];
    }

    // Print the current UID
    Serial.print("Current UID: ");
    for (int i = 0; i < 4; i++) {
      Serial.print(currentUid[i], HEX);
    }
    Serial.println();

    // Set the new UID
    byte newUid[4] = {0xAB, 0xCD, 0xEF, 0x01};  // Change this to the new UID you want to set
    bool success = mfrc522.MIFARE_SetUid(newUid, 4, true);

    if (success) {
      Serial.println("New UID set successfully");
    } else {
      Serial.println("Failed to set new UID");
    }

    // Get the new UID
    byte updatedUid[4];
    for (int i = 0; i < 4; i++) {
      updatedUid[i] = mfrc522.uid.uidByte[i];
    }

    // Print the updated UID
    Serial.print("Updated UID: ");
    for (int i = 0; i < 4; i++) {
      Serial.print(updatedUid[i], HEX);
    }
    Serial.println();

    // Halt the tag and stop reading
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}
