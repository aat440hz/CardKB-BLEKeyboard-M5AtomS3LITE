# CardKB-BLEKeyboard-M5AtomS3LITE

This project turns your M5AtomS3 LITE into a BLE (Bluetooth Low Energy) keyboard using the M5Stack-ATOMS3 board package. It demonstrates how to use the M5AtomS3 LITE, along with a CardKB (I2C Mini Keyboard) to send keystrokes over BLE to a connected device.

## Prerequisites

Before you get started, ensure you have the following:
- An M5AtomS3 LITE device.
- A CardKB I2C Mini Keyboard.
- Arduino IDE installed on your computer.
- The ESP32 board package installed in Arduino IDE. Add the following URL to your Arduino IDE preferences in the "Additional Board Manager URLs" field:
https://dl.espressif.com/dl/package_esp32_index.json

- Install the M5Stack-ATOMS3 board package from the Boards Manager in Arduino IDE. Search for "M5Stack-ATOMS3" and install it. Note: The standard M5Stack board package does not work for this project.

## Installation

1. Connect your M5AtomS3 LITE to your computer via USB.
2. Open the Arduino IDE and select the correct port for your M5AtomS3 LITE.
3. Open the provided sketch file.
4. Compile and upload the sketch to your M5AtomS3 LITE.

## Usage

Once the sketch is uploaded:
1. Power on your M5AtomS3 LITE.
2. Enable Bluetooth on your target device and pair it with the M5AtomS3 LITE, which appears as a BLE Keyboard.
3. The M5AtomS3 LITE will automatically start scanning for keypresses on the CardKB and send them over BLE to the connected device.
4. Tested to work with Windows 10.

## Features

- BLE Keyboard emulation.
- Supports sending basic keypresses and some special keys (e.g., ESC, Enter, Arrow Keys) from the CardKB to the connected BLE device.

## Customization

You can modify the key mapping in the sketch to support additional keys based on your needs. Simply adjust the switch-case statements to match the desired key codes.

## Contributing

Feel free to fork this project and submit pull requests with your improvements or open an issue if you encounter any problems.

## License

This project is released under the MIT License. See the LICENSE file for details.
