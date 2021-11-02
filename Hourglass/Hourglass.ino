const int tiltSwitch = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 1250;h 

void setup() {
  // put your setup code here, to run once:
  
  for(int i=2;i<8;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(tiltSwitch, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  if(currentTime - previousTime > interval)
  {
    previousTime = currentTime;
    digitalWrite(led,HIGH);
    led++;
    if (led == 7)
    {}
  }
  switchState = digitalRead(tiltSwitch);
  if(switchState != prevSwitchState)
  {
    for(int i=2;i<8;i++)
    {
      digitalWrite(i,LOW);
    }
    led = 2;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
}
