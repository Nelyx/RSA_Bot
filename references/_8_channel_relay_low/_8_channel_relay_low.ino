//the relays connect to
int IN4 = 4;
int IN5 = 5;

#define ON   0
#define OFF  1
void setup() 
{
  relay_init();//initialize the relay
}

void loop() {

  relay_SetStatus(ON, OFF);//turn on RELAY_1 
  delay(2000);//delay 2s
  relay_SetStatus(OFF, ON);//turn on RELAY_2
  delay(2000);//delay 2s
}
void relay_init(void)//initialize the relay
{  
  //set all the relays OUTPUT
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
 
  relay_SetStatus(OFF,OFF);//turn off all the relay
}
//set the status of relays
void relay_SetStatus( unsigned char status_1,  unsigned char status_2)
{
  digitalWrite(IN4, status_1);
  digitalWrite(IN5, status_2);
 

}
