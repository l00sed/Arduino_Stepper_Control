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
  Serial.begin(9600);
  pinMode (driverPUL, OUTPUT);
  pinMode (driverDIR, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(reverseSwitch), revmotor, FALLING);
}

void loop() {
  pd = map((analogRead(spd)),0,1023,2000,50);
  Serial.println(analogRead(spd));
  Serial.println(pd);
  digitalWrite(driverDIR,setdir);
  digitalWrite(driverPUL,HIGH);
  delayMicroseconds(pd);
  digitalWrite(driverPUL,LOW);
  delayMicroseconds(pd);
}
