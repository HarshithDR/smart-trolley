# Smart Trolley Project
The Smart Trolley project is an Arduino-based system that uses RFID (Radio-Frequency Identification) technology to identify products in a shopping cart. It allows you to create an automated shopping cart system where items are identified using RFID tags, and their details, such as product name and price, are displayed on an LCD screen.

## Project Components
The project consists of the following components:

- Arduino board (e.g., Arduino Uno)
- FID reader (MFRC522)
- LCD display (16x2)
- RFID tags for each product
- Breadboard and jumper wires


## Setup
**Hardware Setup:**

- Connect the RFID reader (MFRC522) to the Arduino board using SPI communication.
- Connect the LCD display to the Arduino using the appropriate pins.
- Ensure that the RFID tags are attached to the products you want to identify.

**Software Setup:**

- Install the necessary libraries for the RFID reader and LCD display.
- Upload the provided Arduino sketch (code) to your Arduino board.
- Running the Project
- When you power up the system, the LCD screen will display "Smart Trolley."


## Working
- Place a product with an RFID tag on the reader.

- The RFID reader will detect the tag and display the product details (name and price) on the LCD screen.

- The system can identify multiple products, and their details will be displayed as they are scanned.

- -If the system doesn't recognize the product, it will display "Product NotFound."

- The project demonstrates how RFID technology can be used in a smart shopping cart system.

## Customization
You can customize the project by adding more RFID tags for additional products. Update the Arduino code with the corresponding RFID tag IDs and product details to match the products you want to identify.

## Arduino Code
The provided Arduino sketch (smart_trolley.ino) contains the code required for this project. You can upload it to your Arduino board.


## Acknowledgments
Special thanks to the Arduino and open-source hardware communities for providing the tools and resources needed to create this project.

**Enjoy using your Smart Trolley project!**
