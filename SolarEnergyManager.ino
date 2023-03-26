// Date:        2023-01-18
// Description: maximize inhouse consumption of solar system be activating/
//              deactivating consumers using wireless sockets and
//              measuring electric power at grid connection point
//
// ToDo
// - will the recieve transmit of RS485 work together with the monitor? I guess not....

// ############################### includes ################################
#include <RCSwitch.h>  // remote control (DEBO 433 RX) for wireless sockets
                       // library source folder: "rc-switch-2.6.4"

//#include <ArduinoRS485.h>  // Waveshare RS485 communication board
                           // for communication with power measurement
                           // library source folder: "ArduinoRS485-1.0.5"

#include <ModbusMaster.h>  // do we need the ArduinoRS485.h library or
                           // is it suficient to only habe the Modbus lib?

// ############################### defines #################################
#define REMOTECTRL 10  // signal remote control transmit at input 10


// ############################### constants ###############################
const bool bCXXX = true;  // xxx
const float fCXXX = 0.0;  // xxx


// ############################### variables ###############################
float fFFFF;         // FFFF
bool bBBBB = false;  // BBBB


// ######################### create classes ################################
RCSwitch mySwitch = RCSwitch();  // remote control

ModbusMaster RelayBoard; // instantiate ModbusMaster object

// #########################################################################
// ########################     i n i t     ################################
// #########################################################################
void setup() {
  Serial.begin(9600);

  // enable remote control transmitter
  mySwitch.enableTransmit(REMOTECTRL);

  // set baud rate for RS485 communication
  //RS485.begin(9600);

  // communicate with Modbus Relay Board (default adress 255) over Serial (port 0)
  RelayBoard.begin(255, Serial);
  // Questions:
  // - how to set baudrate
  // - the relay module default adress is 255.
  //   - how can this adress be changed?
  // - which port of the Arduino is used? is this the TX?

  Serial.println("init finished");
}

// #########################################################################
// ########################     l o o p     ################################
// #########################################################################
void loop() {

   // test code switching on/off relay 1 and 2 in 1s cycle
   RelayBoard.writeSingleCoil(0x0000, 0xFF); // switch ON (0xFF) relay 1 (0x0000);
   delay(1000);
   RelayBoard.writeSingleCoil(0x0001, 0xFF); // switch ON (0xFF) relay 2 (0x0001);
   delay(1000);
   RelayBoard.writeSingleCoil(0x0000, 0x00); // switch OFF (0x00) relay 1 (0x0000);
   delay(1000);
   RelayBoard.writeSingleCoil(0x0001, 0x00); // switch OFF (0x00) relay 2 (0x0001);
   delay(1000) ;

  //Serial.println("loop finished");
}

// #########################################################################
// #################    f u n c t i o n s     ##############################
// #########################################################################
