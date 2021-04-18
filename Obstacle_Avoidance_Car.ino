//www.elegoo.com

#include <Servo.h>  //servo library
#include"pitches.h"
Servo myservo;      // create servo object to control servo

int Echo = A4;  
int Trig = A5; 

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeed 250
int rightDistance = 0, leftDistance = 0, middleDistance = 0;
int melody[] = {
NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4, END

};

int noteDurations[] = {       //duration of the notes
8,4,8,4,
};
int melody2[] = {
NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
END

};
int noteDurations2[] = {       //duration of the notes
8,8,8,8
};

int melody4[] = {
NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4,
END

};
int noteDurations4[] = {       //duration of the notes
8,8,8,8
};

int melody3[] = {
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4,
END

};
int noteDurations3[] = {       //duration of the notes
8,8,8,8
};
int speed=90; 

void forward(){ 
  for (int thisNote = 0; melody4[thisNote]!=-1; thisNote++) {

          int noteDuration4 = speed*noteDurations4[thisNote];
          tone(A3, melody4[thisNote],noteDuration4*.95);
          Serial.println(melody4[thisNote]);

          delay(noteDuration4);

          noTone(3);
   }
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
   
}

void back() {
   for (int thisNote = 0; melody3[thisNote]!=-1; thisNote++) {

          int noteDuration3 = speed*noteDurations3[thisNote];
          tone(A3, melody3[thisNote],noteDuration3*.95);
          Serial.println(melody3[thisNote]);

          delay(noteDuration3);

          noTone(3);
   }
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
  
}

void left() {
  for (int thisNote = 0; melody2[thisNote]!=-1; thisNote++) {

          int noteDuration2 = speed*noteDurations2[thisNote];
          tone(A3, melody2[thisNote],noteDuration2*.95);
          Serial.println(melody2[thisNote]);

          delay(noteDuration2);

          noTone(3);
}
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  Serial.println("Left");
   
}

void right() {
  for (int thisNote = 0; melody[thisNote]!=-1; thisNote++) {

          int noteDuration = speed*noteDurations[thisNote];
          tone(A3, melody[thisNote],noteDuration*.95);
          Serial.println(melody[thisNote]);

          delay(noteDuration);

          noTone(3);
        }
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");
  
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
} 

//Ultrasonic distance measurement Sub function
int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
}  

void setup() { 
  myservo.attach(3,700,2400);  // attach servo on pin 3 to servo object
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
} 

void loop() { 
    myservo.write(90);  //setservo position according to scaled value
    delay(500); 
    middleDistance = Distance_test();
    for (int thisNote = 0; melody[thisNote]!=-1; thisNote++) {

          int noteDuration = speed*noteDurations[thisNote];
          tone(A3, melody[thisNote],noteDuration*.95);
          Serial.println(melody[thisNote]);

          delay(noteDuration);

          noTone(3);
        }

    if(middleDistance <= 40) {     
      stop();
      delay(500);                         
      myservo.write(10);          
      delay(1000);      
      rightDistance = Distance_test();
      
      delay(500);
      myservo.write(90);              
      delay(1000);                                                  
      myservo.write(180);              
      delay(1000); 
      leftDistance = Distance_test();
      
      delay(500);
      myservo.write(90);              
      delay(1000);
      if(rightDistance > leftDistance) {
        right();
         
        delay(360);
    
      }
      else if(rightDistance < leftDistance) {
        left();
        
       
       
    delay(360);
      }
      else if((rightDistance <= 40) || (leftDistance <= 40)) {
        back();
        
        delay(180);
      
      }
      else {
        forward();
        
      
      }
    }  
    else {
        forward();
        
    }                     
}
