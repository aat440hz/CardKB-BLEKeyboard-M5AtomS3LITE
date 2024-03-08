#include <M5AtomS3.h>
#include <Wire.h>
#include <BleKeyboard.h>

#define CARDKB_ADDR 0x5F

BleKeyboard bleKeyboard;
bool isConnected = false;  // Current connection status
bool wasConnected = false; // Last known connection status

void setup() {
    Serial.begin(115200);
    AtomS3.begin();
    // Assuming default I2C for M5Atom S3 LITE, no specific pins needed
    Wire.begin(); 
    bleKeyboard.begin();
    Serial.println("Starting BLE work!");
    // No display, so we don't initialize or use M5.Lcd calls
}

void loop() {
    // Check the current connection status
    isConnected = bleKeyboard.isConnected();

    // Log connection status changes to the Serial Monitor
    if (isConnected != wasConnected) {
        if (isConnected) {
            Serial.println("BLE Connected!");
        } else {
            Serial.println("BLE Disconnected!");
        }
        wasConnected = isConnected;  // Update the remembered status
    }

    // Handling of key presses when BLE is connected
    if (isConnected) {
        Wire.requestFrom(CARDKB_ADDR, 1);
        while (Wire.available()) {
            char c = Wire.read();  // receive a byte as character
            if (c != 0) {
                switch (c) {
                    case 27:  // ASCII for ESC is 27
                        bleKeyboard.write(KEY_ESC);  // Send ESC keypress via BLE Keyboard
                        Serial.println("Sending ESC Key");  // Debugging
                        break;
                    case '\r':  // If Enter key (or the correct character for your CARDKB)
                        bleKeyboard.write(KEY_RETURN);  // Send Enter keypress via BLE Keyboard
                        Serial.println("Sending Enter Key");  // Debugging
                        break;
                    case 0xB5:  // Hexadecimal code for Up Arrow
                        bleKeyboard.write(KEY_UP_ARROW);
                        Serial.println("Sending Up Arrow Key");  // Debugging
                        break;
                    case 0xB6:  // Hexadecimal code for Down Arrow
                        bleKeyboard.write(KEY_DOWN_ARROW);
                        Serial.println("Sending Down Arrow Key");  // Debugging
                        break;
                    case 0xB4:  // Hexadecimal code for Left Arrow
                        bleKeyboard.write(KEY_LEFT_ARROW);
                        Serial.println("Sending Left Arrow Key");  // Debugging
                        break;
                    case 0xB7:  // Hexadecimal code for Right Arrow
                        bleKeyboard.write(KEY_RIGHT_ARROW);
                        Serial.println("Sending Right Arrow Key");  // Debugging
                        break;
                    default:
                        bleKeyboard.print(c);  // Send character as BLE Keyboard
                        Serial.print("Sending: ");  // Debugging
                        Serial.println(c, HEX);
                        break;
                }
            }
        }
    }
    delay(200); // Debounce delay
}
