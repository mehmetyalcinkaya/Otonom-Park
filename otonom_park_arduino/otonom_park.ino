#include <AFMotor.h>
#include <Ultrasonic.h>
#include <avr/wdt.h>
AF_DCMotor Left_Frwd_Engine(4);
AF_DCMotor Right_Frwd_Engine(3);
AF_DCMotor Left_Back_Engine(1);
AF_DCMotor Right_Back_Engine(2);
Ultrasonic ultrasonic_back(53,52),ultrasonic_left_back(47,46),ultrasonic_left_frwd(49,48),ultrasonic_frwd(50,51);
#define Left 0
#define Right 1
#define Forward 2
#define Backward 3
#define minimum_limit 16
#define minimum_limit1 35
byte park_status = 0;
int signal_pin = 35;
int park_button=28;
volatile int val;
int data;
int counter = 0;
int current_status = 0;
int previous_status = 0;
void count(int counterr){
    for (int i = 0 ; i <= counterr; i+1){
        val = digitalRead(signal_pin);
        if (val == LOW){
            current_status = 0;
        }
        else {
        current_status = 1;}
        if(current_status != previous_status){
            if(current_status == 1){
                counter = counter + 1;
            i = i+1;}
            else {
            i = i ;}
        previous_status = current_status;}
        if (i == counterr){
            Left_Frwd_Engine.run(RELEASE);
            Right_Frwd_Engine.run(RELEASE);
            Left_Back_Engine.run(RELEASE);
Right_Back_Engine.run(RELEASE);}}}
void Engine_pinSetup(){
    Left_Frwd_Engine.run(RELEASE);
    Right_Frwd_Engine.run(RELEASE);
    Left_Back_Engine.run(RELEASE);
Right_Back_Engine.run(RELEASE);}
void Car_Movement(byte motor, byte spd){
    if (motor == Forward){
        Left_Frwd_Engine.setSpeed(spd);
        Right_Frwd_Engine.setSpeed(spd);
        Left_Back_Engine.setSpeed(spd);
        Right_Back_Engine.setSpeed(spd);
        Left_Frwd_Engine.run(FORWARD);
        Right_Frwd_Engine.run(FORWARD);
        Left_Back_Engine.run(FORWARD);
    Right_Back_Engine.run(FORWARD);}
    if (motor == Backward){
        Left_Frwd_Engine.setSpeed(spd);
        Right_Frwd_Engine.setSpeed(spd);
        Left_Back_Engine.setSpeed(spd);
        Right_Back_Engine.setSpeed(spd);
        Left_Frwd_Engine.run(BACKWARD);
        Right_Frwd_Engine.run(BACKWARD);
        Left_Back_Engine.run(BACKWARD);
    Right_Back_Engine.run(BACKWARD);}
    if (motor == Left){
        Left_Frwd_Engine.setSpeed(spd);
        Right_Frwd_Engine.setSpeed(spd);
        Left_Back_Engine.setSpeed(spd);
        Right_Back_Engine.setSpeed(spd);
        Left_Frwd_Engine.run(BACKWARD);
        Right_Frwd_Engine.run(FORWARD);
        Left_Back_Engine.run(BACKWARD);
    Right_Back_Engine.run(FORWARD); }
    if (motor == Right){
        Left_Frwd_Engine.setSpeed(spd);
        Right_Frwd_Engine.setSpeed(spd);
        Left_Back_Engine.setSpeed(spd);
        Right_Back_Engine.setSpeed(spd);
        Left_Frwd_Engine.run(FORWARD);
        Right_Frwd_Engine.run(BACKWARD);
        Left_Back_Engine.run(FORWARD);
Right_Back_Engine.run(BACKWARD);}}
void Car_Stop(){
    Left_Frwd_Engine.run(RELEASE);
    Right_Frwd_Engine.run(RELEASE);
    Left_Back_Engine.run(RELEASE);
Right_Back_Engine.run(RELEASE);}
bool Parking_Control(){
    long frwd_Sensor  = ultrasonic_frwd.Ranging(CM);
    long right_Sensor = ultrasonic_left_frwd.Ranging(CM);
    long right_backward_Sensor   =ultrasonic_left_back.Ranging(CM);
    if( (right_Sensor <= minimum_limit)&&(right_backward_Sensor <= minimum_limit)&&(park_status == 0)){
        Car_Movement(Forward, 85);
    park_status = 1;}
    if((right_Sensor > minimum_limit)&&(right_Sensor < minimum_limit1)&&(right_backward_Sensor > minimum_limit)&&(right_backward_Sensor < minimum_limit1)&&(park_status == 1)){
        Car_Movement(Forward, 85);
    park_status = 2;}
    if((right_Sensor >= minimum_limit1)&&(right_backward_Sensor >= minimum_limit1)&&(park_status == 1)){
        Car_Stop() ;
        delay(500);
    park_status = 10;}
    if((right_Sensor <= minimum_limit)&&(right_backward_Sensor <= minimum_limit)&&(park_status == 2)){
    park_status = 3;}
return park_status; }
void Park_bul(){
    Parking_Control();
    if(park_status == 3 ){
        Car_Stop();
        delay(400);
    park_status = 4;}
    if(park_status == 4 ){
        Car_Movement(Backward,100);
        count(20);
        Car_Stop();
        delay(500);
        Car_Movement(Right,150);
        count(10);
        Car_Stop();
        delay(500);
    park_status = 5;}
    if(park_status == 5){
        Car_Movement(Backward,80);
        long backward_Sensor   = ultrasonic_back.Ranging(CM);
        if(backward_Sensor>0 && backward_Sensor <= 9){
            Car_Stop();
            delay(400);
        park_status = 6;}
    return backward_Sensor;}
    if(park_status == 6){
        Car_Movement(Left,95);
        long right_Sensor = ultrasonic_left_frwd.Ranging(CM);
        long right_backward_Sensor   = ultrasonic_left_back.Ranging(CM);
        if(right_Sensor == right_backward_Sensor){
            Car_Stop();
        park_status = 7;}
    return right_Sensor,right_backward_Sensor;}
    if(park_status == 7){
        long frwd_Sensor  = ultrasonic_frwd.Ranging(CM);
        if(frwd_Sensor<=7){
            Car_Stop();
            park_status = 8;
        wdt_enable( WDTO_60MS);}
        else{
        Car_Movement(Forward,75);}
    return frwd_Sensor;}
    if (park_status ==10){
        Car_Movement(Left,150);
        count(20);
        Car_Stop();
        delay(500);
park_status = 7;}}
void setup(){
    Serial.begin(9600);
    attachInterrupt(5, count, CHANGE);
    pinMode (signal_pin, INPUT) ;
    Engine_pinSetup();
pinMode(park_button , INPUT);}
void loop(){
    if(digitalRead(park_button) == HIGH){
while(1){ Park_bul();}}
    if(Serial.available()){
        data = Serial.read();
        if(data == '8' || digitalRead(park_button) == HIGH ){
    while(1){ Park_bul();}}
        else if(data == '1'){Car_Movement(Forward,150 );}
        else if(data == '2'){Car_Movement(Backward,150 );}
        else if(data == '4'){Car_Movement(Right,150 );}
        else if(data == '3'){Car_Movement(Left,150 );}
else{ Car_Stop();}}}
