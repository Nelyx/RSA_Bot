/*
This is the code that gives live to RSA_BOT
He was brought into this world to love everyone and make them happy
except the North Korea
fuck them

*/

// defined pins for relay board
#define pump_water 2
#define pump_alcohol = 3
#define led_green1 = 7
#define led_green2 = 8
#define led_orange = 9
#define led_red = 10
#define led_blue1 = 11
#define led_blue2 = 12

// This is were i put varaiables that are important, really its just a waste of memory, define is a better way to do this
int Wtr_Pump = 2;
int Alc_Pump = 3;
int ledGrnl = 7;
int ledGrnh = 8;
int ledOrg = 9;
int ledRed = 10;
int ledBlul = 11;
int ledBluh = 12;


int ledSeq[6] = {ledBluh, ledBlul, ledRed, ledOrg, ledGrnh, ledGrnl}; // high to low

// This is also pointless, i need to remember the length of this array to change the pinSet function...
int outPins[] = {Wtr_Pump, Alc_Pump, ledGrnl, ledGrnh, ledOrg, ledRed, ledBlul, ledBluh, enbSens};



// the setup routine runs once when you press reset, this isn't your dads regular interupt:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("About to set the pins!!!!");
  pinSet(outPins);
  dWh(enbSens);
  ledFlash(10,1000);
  ledStep(1000,true);
  ledStep(1000,false);
  ledStep(1000,true);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  Serial.println(readSens());


  delay(1000);        // delay in between reads for stability
  
}

void pinSet(int pins[]) {
  //This is the "clever" little sub that will set all the pinmodes right. I think its very smart.
  for (int i = 0; i <= 8; i++){
    pinMode(pins[i], OUTPUT);
    dWl(pins[i]);
    Serial.print("set ");
    Serial.print(pins[i]);
    Serial.print(" to output.");
    Serial.println();
  }
}

//this is where i put a pointless overload just to be cool
void dWh(int x){
  digitalWrite(x, HIGH); 
}

void dWl(int x){
  digitalWrite(x, LOW);
}

int readSens() {
  int Val;
  int sensAvg1 = analogRead(A0);
  delay(10);
  int sensAvg2 = analogRead(A0);
  delay(10);
  int sensAvg3 = analogRead(A0);
  delay(10);
  int sensAvg = (sensAvg1 + sensAvg2 + sensAvg3)/3;
  Val = map(sensAvg, 140, 500, 0 , 6); //best values so far are 140 lower to 500 upper
  return Val;
}

// ledStep takes t time and steps through the led's high to low in that time
void ledStep(int t, bool Up){
  int intv = t / 6;
  if (Up == true){
    for (int i = 0; i <= 5; i++){
      dWh(ledSeq[i]);
      delay(intv);
      dWl(ledSeq[i]);
    } 
  }
  else {
    for (int j = 5; j >= 0; j--){
      dWh(ledSeq[j]);
      delay(intv);
      dWl(ledSeq[j]);
    } 
  }
  
}

// ledFlash flashes the leds for x intervals with y delay overall
void ledFlash(int x, int y){
    int del = y / (x/2);
    do {
      for (int i = 0; i <= 5; i++){
      dWh(ledSeq[i]);
      }
      delay(del);
      for (int j = 0; j <= 5; j++){
      dWl(ledSeq[j]);
      }
      delay(del);
      x--; 
    } while (x >= 0);
}

// ledLevel makes the light readout the level of drunk
void ledLevel(int x){
  
}