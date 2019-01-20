# feeder is arduino project for my fish's feeder device
- Base on ESP8266 in Nodemcu board to control feeder can feed my fish
- It can connect to iot server to receive/send useful data

# Hardware
- NodeMCU 1.0

# Prepare
- Install NodeMCU driver from Silicon Labs [link](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)
- Install ESP8266 module
    - Add http://arduino.esp8266.com/stable/package_esp8266com_index.json into Preferences
    - `Tools -> Board -> Boards Manager`
    - Search `ESP8266` and install it
- Install [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
- Install [ConfigManager](https://github.com/nrwiersma/ConfigManager)
- [Arduino Plugin](https://github.com/esp8266/arduino-esp8266fs-plugin) to upload files to ESP8266 file system

# TODO
- [ ] Install Wifi
    - [x] Create a folder named `data` and add `index.html`
    - [x] Open wifi access point and try to connect
    - [ ] ...
