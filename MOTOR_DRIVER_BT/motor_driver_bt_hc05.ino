//control code


//speed 0-255: low: High Its a analog

const int speed = 255;
// const int turn_speed = 50;
const int curving_speed = 20;


//Bluetooth pin connection Tx-RX
//Bluetooth reading variable

String bt_sig;

//BTS pin connection


//********************B1***************************
// This pin is same for both of the bts always high
const int B1_R_EN = 2;
const int B1_L_EN = 4;

// This pin is same for both of the bts always low
const int B1_R_IS = 6;
const int B1_L_IS = 7;

//This is pin used for speed 
const int B1_R_PWM = 3;
const int B1_L_PWM = 5;

//********************B2***************************

// This pin is same for both of the bts always high
const int B2_R_EN = 8;
const int B2_L_EN = 10;

// This pin is same for both of the bts always low
const int B2_R_IS = 12;
const int B2_L_IS = 13;

//This is pin used for speed 
const int B2_R_PWM = 9; 
const int B2_L_PWM = 11;


void setup(){
    //Serail Monitor

    Serial.begin(9600);

    //B1
    pinMode(B1_R_EN,OUTPUT);
    pinMode(B1_L_EN,OUTPUT);
    pinMode(B1_R_IS,OUTPUT);
    pinMode(B1_L_IS,OUTPUT);
    pinMode(B1_R_PWM,OUTPUT);
    pinMode(B1_L_PWM,OUTPUT);
    //B2
    pinMode(B2_R_EN,OUTPUT);
    pinMode(B2_L_EN,OUTPUT);
    pinMode(B2_R_IS,OUTPUT);
    pinMode(B2_L_IS,OUTPUT);
    pinMode(B2_R_PWM,OUTPUT);
    pinMode(B2_L_PWM,OUTPUT);

    //IS PINS;

    digitalWrite(B1_R_IS,LOW);
    digitalWrite(B1_L_IS,LOW);
    digitalWrite(B2_R_IS,LOW);
    digitalWrite(B2_L_IS,LOW);

    // EN Pins;

    digitalWrite(B1_R_EN,HIGH);
    digitalWrite(B1_L_EN,HIGH);
    digitalWrite(B2_R_EN,HIGH);
    digitalWrite(B2_L_EN,HIGH);

}


void loop(){

//start monitoring bluettooh buttons 

//    while(Serial.available()){
//        Serial.println("Bluetooh Key:");
//        Serial.println(Serial.read());
//    }



    //sotring command into variable for oparating the bot
    bt_sig = "";
    while(Serial.available()){
        
        bt_sig = (char)Serial.read();
        // Serial.println(bt_sig);
    }


    if(bt_sig == "F"){
        forward();
        Serial.println("move forward");
    }
    else if(bt_sig == "L"){
        turn_left();
        Serial.println("move left");
    }
    else if(bt_sig == "R"){
        turn_right();
        Serial.println("move right");
    }
    else if(bt_sig == "B"){
        backward();
        Serial.println("move back");
    }
    else if (bt_sig == "S") {
        stop_bot();
        Serial.println("stop");
    }
    else if (bt_sig == "G") {
      //fwrd - left
        Left_forward();
        Serial.println("Fwd left");
    }
    else if (bt_sig == "I") {
        //frwd right
        right_forward();
        Serial.println("Fwd Right");
    }
    else if (bt_sig == "H") {
        left_backward();
        Serial.println("Back left");
    }
    else if (bt_sig == "J") {
        right_backward();
        Serial.println("Back right");
    }
    else if(bt_sig == "X"){
        kachra_dance();
        delay(600);
        stop_bot();
        kachra_dance_2();
        Serial.println("Kachra dance");

    }                


}


//Movement core 

void stop_bot(){

    analogWrite(B1_R_PWM, 0);
    analogWrite(B1_L_PWM, 0);
    analogWrite(B2_R_PWM, 0);
    analogWrite(B2_L_PWM, 0);
    

}


void forward(){

//CW->ClockWise (1-0)-(1-0)

    analogWrite(B1_R_PWM, speed);
    analogWrite(B1_L_PWM, 0);
    analogWrite(B2_R_PWM, speed);
    analogWrite(B2_L_PWM, 0);

}

void backward(){

//CCW - Counter Clock Wise  (0-1)-(0-1)
    analogWrite(B1_R_PWM, 0);
    analogWrite(B1_L_PWM, speed);
    analogWrite(B2_R_PWM, 0);
    analogWrite(B2_L_PWM, speed);

}

void turn_left(){
    //b1-cw and b2-ccw (1-0)-(0-1)

    analogWrite(B1_R_PWM, 0);
    analogWrite(B1_L_PWM, speed);
    analogWrite(B2_R_PWM, speed);
    analogWrite(B2_L_PWM, 0);    

}

void turn_right(){
    //b1-CCW and b2-CW (0-1)-(1-0)
    analogWrite(B1_R_PWM, speed);
    analogWrite(B1_L_PWM, 0);
    analogWrite(B2_R_PWM, 0);
    analogWrite(B2_L_PWM, speed);


}


// *******curving extra**************

void Left_forward(){
    analogWrite(B1_R_PWM, curving_speed);
     analogWrite(B1_L_PWM, 0);
     analogWrite(B2_R_PWM, speed);
     analogWrite(B2_L_PWM, 0);  

 }

 void right_forward(){
     analogWrite(B1_R_PWM, speed);
     analogWrite(B1_L_PWM, 0);
     analogWrite(B2_R_PWM, curving_speed);
     analogWrite(B2_L_PWM, 0);
 }

 
 void left_backward(){
     analogWrite(B1_R_PWM, 0);
     analogWrite(B1_L_PWM, curving_speed);
     analogWrite(B2_R_PWM, 0);
     analogWrite(B2_L_PWM, speed);
 }

 
 void right_backward(){
     analogWrite(B1_R_PWM, 0);
     analogWrite(B1_L_PWM, speed);
     analogWrite(B2_R_PWM, 0);
     analogWrite(B2_L_PWM, curving_speed);
 }

 void kachra_dance(){
    analogWrite(B1_R_PWM, 0);
    analogWrite(B1_L_PWM, speed);
    analogWrite(B2_R_PWM, 0);
    analogWrite(B2_L_PWM, 75);
 }

 void kachra_dance_2(){
      analogWrite(B1_R_PWM, speed);
    analogWrite(B1_L_PWM, 0);
    analogWrite(B2_R_PWM, 0);
    analogWrite(B2_L_PWM, 65);
  }
