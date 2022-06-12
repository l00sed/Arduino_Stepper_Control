// Pins

int reverseSwitch = 2; // Push button for reverse
int driverPUL = 7; // Driver PUL pin
int driverDIR = 6; // Driver DIR pin
int spd = A0; // Potentiometer

// Vars

int pd = 500; // Pulse delay period
boolean setdir = LOW; // Set the starting direction

// Interrupt Handler

void revmotor() {
  setdir = !setdir;
}

void setup() {
  pinMode (driverPUL, OUTPUT);
  pinMode (dirverDIR, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(reverseSwitch), revmotor, FALLING);
}

void loop() {
  pd = map((analogRead(spd)),0,1023,2000,50);
  digitalWrite(driverDIR,setdir);
  digitalWrite(driverPUL,HIGH);
  delayMicroseconds(pd);
  digitalWrite(driverPUL,LOW);
  delayMicroseconds(pd);
}
