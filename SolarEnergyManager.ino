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

#include <ArduinoRS485.h>  // Waveshare RS485 communication board
                           // for communication with power measurement
                           // library source folder: "ArduinoRS485-1.0.5"

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


// #########################################################################
// ########################     i n i t     ################################
// #########################################################################
void setup() {
  Serial.begin(9600);

  // enable remote control transmitter
  mySwitch.enableTransmit(REMOTECTRL);

  // set baud rate for RS485 communication
  RS485.begin(9600);


  Serial.println("init finished");
}

// #########################################################################
// ########################     l o o p     ################################
// #########################################################################
void loop() {


  //Serial.println("loop finished");
}

// #########################################################################
// #################    f u n c t i o n s     ##############################
// #########################################################################
