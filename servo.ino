#include "servo360.h"
Servo360 myservo;
void setup(){
    Serial.begin(115200);
    myservo.attach(9);
}
void loop(){
    while(Serial.available()){
        String inp1 = Serial.readString();
        int inp2 = inp1.toInt();
        Serial.println(inp2);
        myservo.turndeg(inp2);
    }

}
// #include<Servo.h>
// Servo myServo;
// void setup(){
//     myServo.attach(9);
//     Serial.begin(115200);
// }
// void loop(){
//     while(Serial.available()){
//         String inp1 = Serial.readString();
//         int inp2 = inp1.toInt();
//         myServo.write(inp2);
//     }

// }