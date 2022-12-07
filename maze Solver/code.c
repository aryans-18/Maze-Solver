//defining motor pins
int rm1 = 6;
int rm2 = 7;
int lm1 = 8;
int lm2 = 9;

//defining enable pins
int ep1 = 5;
int ep2 = 10;

//speed of motors by pwm
//const int r_pwm = 100;
//const int l_pwm = 100;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //IR pins
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  //Motor pins
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  //Enables pins
  pinMode(ep1, OUTPUT);
  pinMode(ep2, OUTPUT);  
  pinMode(13,OUTPUT);
  
}

void forward() {
  
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  analogWrite(ep1, 180);
  analogWrite(ep2, 180);
}

void right_90() {
  
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  analogWrite(ep1, 120);
  analogWrite(ep2, 120);
}

void left_90() {
  
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  analogWrite(ep1, 120);
  analogWrite(ep2, 120);
}

void r_slight() {
  
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  analogWrite(ep1, 0);
  analogWrite(ep2, 80);
}

void l_slight() {
  
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  analogWrite(ep1, 80);
  analogWrite(ep2, 0);
}

void backward() {
  
  digitalWrite(rm1, LOW); 
  digitalWrite(rm2, HIGH);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  analogWrite(ep1, 80);
  analogWrite(ep2, 80);
}
void forward_slight() {
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  analogWrite(ep1, 90);
  analogWrite(ep2, 90);
  delay(200);
}
void backward_slight() {
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, HIGH);
  analogWrite(ep1, 90);
  analogWrite(ep2, 90);
  delay(200);
}
void pause() {
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(13,HIGH);
}

bool stop = false; 
int back_count = 0;

void loop() {
  if(stop) {
    pause();
  }
  else {
    // put your main code here, to run repeatedly:
    //bool turn = false;
    //IR sensor INPUTs
    int x0 = digitalRead(A0);
    int x1 = digitalRead(A1);
    int x2 = digitalRead(A2);
    int x3 = digitalRead(A3);
    int x4 = digitalRead(A4);

    Serial.print(x0);
    Serial.print(" ");
    Serial.print(x1);
    Serial.print(" ");
    Serial.print(x2);
    Serial.print(" ");
    Serial.print(x3);
    Serial.print(" ");
    Serial.print(x4);
    Serial.print("\n");

    //condition for moving straight
    if(x0==0 && x1==0 && x2==1 && x3==0 && x4==0) {
      forward();
      delay(250);
    }
    //moving backwards all white
//    else if(x0==1 && x1==1 && x2==1 && x3==1 && x4==1) {
//      l_slight();
//      delay(100);
//      if(x0==0 && x1==0 && x2==0 && x3==0 && x4==0) {
//        left_90();
//        delay(200);
//      }
//      else {
//        backward();
//        delay(200);
//      }
//    }

//    //blindspot get back
//    else if(x0==0 && x1==0 && x2==0 && x3==0 && x4==0) {
//      backward();
//      delay(200);
//    }

    //for Z turn left
//     else if(x0==1 && x1==0 && x2==1 && x3==0 && x4==0){
//        left_90();
//        delay(43.00);
//        
//        l_slight();
//        delay(500);
//      }

    
      
     //left turn 90 degree
    else if(x0==1 && x1==1 && x2==1 && x3==0 && x4==0) {
      //slightly ahead
      forward_slight();
      //for straight part
      if(x0==0 && x1==0 && x2==1 && x3==0 && x4==0) {
        backward();
        left_90();
        delay(250);
      }
      
      //left 90 only
      else {
        backward();
        left_90();
        delay(250);
      }
    }

     //Left part of V
//     else if(x0==0 && x1==1 && x2==0 && x3==0 && x4==0){
//       l_slight();
//       delay(250);
//     }
      
    //right turn 90 degree
    else if(x0==0 && x1==0 && x2==1 && x3==1 && x4==1) {
      //slightly ahead
      forward_slight();
      //for straight part
      if(x0==0 && x1==0 && x2==1 && x3==0 && x4==0) {
        backward();
        forward();
        delay(500);
      }
      //right 90 only
      else{
        backward();
        right_90();
        delay(250);
      }
    }

//    //Left part of V
//     else if(x0==0 && x1==1 && x2==0 && x3==0 && x4==0){
//       l_slight();
//       delay(250);
    // }

     //for Z turn right
//      else if(x0==0 && x1==0 && x2==1 && x3==0 && x4==1){
//     
//        right_90();
//        delay(400);
//        
//        r_slight();
//        delay(500);
//      }
      
    //T condition
    else if(x0==1 && x1==1 && x2==1 && x3==1 && x4==1){
      forward_slight();
      delay(150);
      if(x0==1 && x1==1 && x2==1 && x3==1 && x4==1){
          pause();
      }
      else{
          left_90();
          delay(250);
          
      }
      
    }
    //right turn slight
    else if(x0==0 && x1==0 && x2==1 && x3==1 && x4==0) {
      r_slight();
      delay(250);
    }
    //left turn slight
    else if(x0==0 && x1==1 && x2==1 && x3==0 && x4==0 ) {
      l_slight();
      delay(250);
    }
    //right most black 
    else if(x0==0 && x1==0 && x2==0 && x3==0 && x4==1 ) {
      r_slight();
      delay(250);
    }
    //right mid black
    else if(x0==0 && x1==0 && x2==0 && x3==1 && x4==0 ) {
      r_slight();
      delay(250);
    }
    //left most black
    else if(x0==1 && x1==0 && x2==0 && x3==0 && x4==0 ) {
      l_slight();
      delay(250);
    }
    //left mid black
    else if(x0==0 && x1==1 && x2==0 && x3==0 && x4==0 ) {
      l_slight();
      delay(250);
    }

    //All Black.
    else if(x0==0 && x1==0 && x2==0 && x3==0 && x4==0){
      //forward_slight();
      delay(100);
      left_90();
      left_90();
      delay(250);
    }
    
  }
}