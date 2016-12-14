#include <Wire.h>
#include <Servo.h>
// 建立一個 Servo 物件
Servo myservo;
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  myservo.attach(13);  // Servo 接在 pin 13
  Serial.begin(115200);           // start serial for output
}



// 旋轉角度
int value=0;

void loop(){
  delay(100);
  }

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  if(x == 0){
    digitalWrite(13,HIGH);
    while(0){
      if (value == 0) 
      value = 180;
      else
      value=0;
      myservo.write(value); 
      delay(1500);
      }
  }
  else if(x == 1){
    digitalWrite(13,LOW);
  }
  Serial.println(x);         // print the integer
}

