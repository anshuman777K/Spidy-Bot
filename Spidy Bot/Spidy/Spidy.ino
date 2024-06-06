#include<Servo.h>
#define CH1 44
#define CH4 42
#define CH5 38 
int ch5Value;
int ch1Value;
int ch4Value;

int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
 
// Read the switch channel and return a boolean value
bool readSwitch(byte channelInput, bool defaultValue){
  int intDefaultValue = (defaultValue)? 100: 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}
 

Servo R11;
Servo R12;
Servo R13;

Servo R21;
Servo R22;
Servo R23;

Servo R31;
Servo R32;
Servo R33;

Servo L11;
Servo L12;
Servo L13;

Servo L21;
Servo L22;
Servo L23;

Servo L31;
Servo L32;
Servo L33;


int d1=100;
int d2=50;

void R1()
{
  stand(R11,55);
  stand(R12,105);
  stand(R13,95);//-ve andr
}

void R2()
{
  stand(R21,50);
  stand(R22,115);//-ve upr
  stand(R23,40);//-ve andr
}

void R3()
{
  stand(R31,60);
  stand(R32,140);
  stand(R33,120);
}

void L1()
{
  stand(L11,115);
  stand(L12,70);
  stand(L13,100);
}

void L2()
{
  stand(L21,115);
  stand(L22,85);
  stand(L23,75);
}

void L3()
{
  stand(L31,50);
  stand(L32,65);
  stand(L33,40);
}

void StandAll()
{
  R1();
  L1();
  R2();
  delay(300);
  L2();
  R3();
  L3();
}

void move(Servo &s,int angle)
{
  s.write(angle);
  delay(10);
}

void L1MF()
{
  L12.write(115);
  delay(d1);
  L11.write(145);
  delay(d2);
  L12.write(70);
  delay(d1);
  L11.write(115);
}

void L1MB()
{
    L12.write(115);
  delay(d1);
  L11.write(85);
  delay(d2);
  L12.write(70);
  delay(d1);
  L11.write(115);
}

void R2MF()
{
  R22.write(70);
  delay(d1);
  R21.write(20);
  delay(d2);
  R22.write(115);
  delay(d1);
  R21.write(50);
}

void R2MB()
{
  R22.write(70);
  delay(d1);
  R21.write(80);
  delay(d2);
  R22.write(115);
  delay(d1);
  R21.write(50);
}

void L3MF()
{
  L32.write(110);
  delay(d1);
  L31.write(80);
  delay(d2);
  L32.write(65);
  delay(d1);
  L31.write(50);
}

void L3MB()
{
  L32.write(110);
  delay(d1);
  L31.write(20);
  delay(d2);
  L32.write(65);
  delay(d1);
  L31.write(50);
}

void R1MF()
{
  R12.write(60);
  delay(d1);
  R11.write(25);
  delay(d2);
  R12.write(105);
  delay(d1);
  R11.write(55);
}

void R1MB()
{
  R12.write(60);
  delay(d1);
  R11.write(85);
  delay(d2);
  R12.write(105);
  delay(d1);
  R11.write(55);
}

void L2MF(){
  L22.write(120);
  delay(d1);
  L21.write(145);
  delay(d2);
  L22.write(85);
  delay(d1);
  L21.write(115);
}

void L2MB(){
  L22.write(120);
  delay(d1);
  L21.write(85);
  delay(d2);
  L22.write(85);
  delay(d1);
  L21.write(115);
}

void R3MF()
{
  R32.write(95);
  delay(d1);
  R31.write(30);
  delay(d2);
  R32.write(140);
  delay(d1);
  R31.write(60);

}
void R3MB()
{
  R32.write(95);
  delay(d1);
  R31.write(90);
  delay(d2);
  R32.write(140);
  delay(d1);
  R31.write(60);

}

void R1S()
{
  stand(R11,55);
  stand(R12,50);
  stand(R13,95);//-ve andr
  delay(10);
}

void R2S()
{
  stand(R21,50);
  stand(R22,70);//-ve upr
  stand(R23,40);//-ve andr
  delay(10);
}

void R3S()
{
  stand(R31,60);
  stand(R32,90);
  stand(R33,120);
  delay(10);
}

void L1S()
{
  stand(L11,115);
  stand(L12,115);
  stand(L13,100);
  delay(10);
}

void L2S()
{
  stand(L21,115);
  stand(L22,120);
  stand(L23,75);
  delay(10);
}

void L3S()
{
  stand(L31,50);
  stand(L32,110);
  stand(L33,40);
  delay(10);
}
void stand(Servo &s,int angle)
{
  s.write(angle);
}


void forward()
{
  L1MF();
  R2MF();
  L3MF();
  delay(20);
  R1MF();
  L2MF();
  R3MF();
}

void backward()
{
  L3MB();
  R2MB();
  L1MB();
  
  
  delay(20);
  R3MB();
  L2MB();
  R1MB();
  
  
}

void right()
{
  L1MF();
  R2MB();
  L3MF();
  delay(30);
  R1MB();
  L2MF();
  R3MB();
}

void left()
{
  L1MB();
  R2MF();
  L3MB();
  delay(30);
  R1MF();
  L2MB();
  R3MF();

}

void sit()
{
  R1S();
  L2S();
  R3S();
  delay(100);
  L1S();
  R2S();
  L3S();

  delay(300);
}
 

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  pinMode(CH5, INPUT);
  pinMode(CH1, INPUT);
  //pinMode(CH2, INPUT);
  //pinMode(CH3, INPUT);
  pinMode(CH4, INPUT);

  //right
  R11.attach(2);
  R12.attach(3);
  R13.attach(4);

  R21.attach(5);
  R22.attach(6);
  R23.attach(7);

  R31.attach(46);
  R32.attach(9);
  R33.attach(10);

  //Left

  L11.attach(11);
  L12.attach(12);
  L13.attach(13);

  L21.attach(52);
  L22.attach(50);
  L23.attach(48);

  L31.attach(53);
  L32.attach(51);
  L33.attach(49) ; 
 
}



void loop() {


ch5Value = readChannel(CH5, -1, 1, 0);
ch1Value = readChannel(CH1, -1, 2, 0);
ch4Value = readChannel(CH4,-2,2,0);

Serial.print(" | Ch1: ");
  Serial.print(ch1Value);

  Serial.print(" ");

  Serial.print(" | Ch4: ");
  Serial.print(ch4Value);

  Serial.print(" ");

Serial.print(" | Ch5: ");
  Serial.print(ch5Value);
  Serial.println();


if(ch5Value==0)
{
  sit();
  delay(150);
}
else if(ch5Value==1)
{
  StandAll();
  delay(150);
}
 if(ch1Value==0)
 {
  StandAll();
  delay(150);
 }
 if(ch1Value==1)
 {
  forward();
  delay(150);
 }
 if(ch1Value==-1)
 {
  backward();
  delay(150);
 }

 if(ch4Value==1)
 {
  left();
  delay(150);
 }
 if(ch4Value==-2)
 {
  right();
  delay(150);
 }
 if(ch4Value==-1)
 {
  StandAll();
  delay(150);

 }
}

