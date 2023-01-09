const int EN=2;         //ENABLE PIN
const int Step=3;       // STEP PIN
const int dir=4;        // DIRECTION PIN
const int closePinAnalog=A0;          // Forward Button PIN Analog
const int openPinAnalog=A1;           // Forward Button PIN Analog
const int buttonReadThreshold = 900;  // Threshold to actuate the analog buttons (full press is 1024)
const int partialTravel = 5000;        // Number of steps to perform a full close  
const int fullTravel = 7000;          // Number of steps to perform a full close      


/*----------------------------SETUP FUNCTION--------------------------*/
void setup()
{
pinMode(EN,OUTPUT);     // ENABLE AS OUTPUT
pinMode(dir,OUTPUT);    // DIRECTION AS OUTPUT
pinMode(Step,OUTPUT);   // STEP AS OUTPUT
//pinMode(forwardPin,INPUT);   // Enable forward pin
//pinMode(reversePin,INPUT);   // Enable reverse pin
digitalWrite(EN,HIGH);   // SET ENABLE TO H
Serial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);
}


/*----------------------------LOOP FUNCTION--------------------------*/
void loop()
{

  // Check open button
 //if( digitalRead(forwardPin) == HIGH ){
//Serial.println("Forward pin");    // Print the analog read you are seeing
//Serial.println(analogRead(forwardPinAnalog));    // Print the analog read you are seeing
// Serial.println("Reverse Pin");    // Print the analog read you are seeing
// Serial.println(analogRead(reversePinAnalog));    // Print the analog read you are seeing
 //delay(250);    // Delay .5 sec to make it readablew

 if( analogRead(closePinAnalog) >= buttonReadThreshold ){
  digitalWrite(EN,LOW);   // SET ENABLE TO LOW to activate the driver
  // full open
  for(int x = 0; x < partialTravel; x++){
    pulse(1);
  }
  digitalWrite(EN,HIGH);   // SET ENABLE TO HIGH to deactivate the driver
 }
 
  // Check close button
 if( analogRead(openPinAnalog) >= buttonReadThreshold ){
 
  digitalWrite(EN,LOW);   // SET ENABLE TO LOW to activate the driver
  // full open
  for(int x = 0; x < partialTravel; x++){
    pulse(0);
  }
  digitalWrite(EN,HIGH);   // SET ENABLE TO HIGH to deactivate the driver
 }

}


void pulse(int forward){
  // Determine direction
  if( forward == 1 ){digitalWrite(dir,LOW);}        // SET DIRECTION LOW FOR FORWARD ROTATION
  else{digitalWrite(dir,HIGH);}                      // SET DIRECTION HIGH FOR REVERSE ROTATION

  // Step once
  digitalWrite(Step,HIGH);    // STEP HIGH
  delay(1);                   // WAIT
  digitalWrite(Step,LOW);     // STEP LOW
  delay(1);                   // WAIT
  
}



void run(){

  int forward = 1;

  if(forward == 1){
    digitalWrite(dir,LOW);        // SET DIRECTION LOW FOR FORWARD ROTATION
  }
for(int x = 0; x < 1000; x++) // LOOP 1000 TIMES FOR 1000 RISING EDGE ON STEP PIN
{
digitalWrite(Step,HIGH);    // STEP HIGH
delay(1);                   // WAIT
digitalWrite(Step,LOW);     // STEP LOW
delay(1);                   // WAIT
}


}
