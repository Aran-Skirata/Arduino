const int button=2;
const int LED_Red=13;
const int LED_Blue=12;

int LED1Status = LOW;
int LED2Status = LOW;

unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;

int lastButtonState=0;

void setup() {
  pinMode(button, INPUT);
  pinMode(LED_Red,OUTPUT);
  pinMode(LED_Blue,OUTPUT);
}

void loop() {

  if(millis() - lastTimeButtonStateChanged > debounceDuration)
  {
    
    byte buttonState = digitalRead(button);
    
    if(buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
        if(buttonState == HIGH) {
          unsigned long startTime = millis();
          unsigned long endTime = startTime;
          while((endTime - startTime) <= 30000) {
            digitalWrite(LED_Red, HIGH);
            delay(100);
            digitalWrite(LED_Blue, HIGH);
            delay(100);
            digitalWrite(LED_Red, LOW);
            delay(100);
            digitalWrite(LED_Blue, LOW);
            delay(100);
            endTime = millis();
          }
        }
        if(buttonState == LOW)
        {
            digitalWrite(LED_Red, LOW);
            digitalWrite(LED_Blue, LOW);
        }
    }
  }

  // if(digitalRead(button) == HIGH) {
  //   delay(500);
  //   if(digitalRead(button) == HIGH) 
  //   {
  //     lastButtonState = 0;
  //   }
  //   lastButtonState+=1;
  // }

  // if(lastButtonState == 1) {
  //   digitalWrite(LED_Red, HIGH);
  //   delay(100);
  //   digitalWrite(LED_Blue, HIGH);
  //   delay(100);
  //   digitalWrite(LED_Red, LOW);
  //   delay(100);
  //   digitalWrite(LED_Blue, LOW);
  //   delay(100);
  // }
  // if(lastButtonState==0)
  // {
  //   digitalWrite(LED_Red, LOW);
  //   digitalWrite(LED_Blue, LOW);
  // }


}
