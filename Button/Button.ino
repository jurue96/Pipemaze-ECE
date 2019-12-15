const int switchPin = 2;
const int ledPin = 5;

int ledState = LOW;
int currentState = LOW;
int lastState = LOW;

unsigned long lastDebounceTime;
unsigned long debounceTime = 50;


void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int readSwitch = digitalRead(switchPin);

  //check to see if new read is same as old state, if not then new lastDebounceTime
  if(readSwitch != lastState){
    lastDebounceTime = millis();
  }
  
  // put your main code here, to run repeatedly:
  if((millis()-lastDebounceTime)>debounceTime){
    //we only want to do something if the state changes
    if(readSwitch!=currentState){
      currentState = readSwitch;
      if(currentState == HIGH){
        //toggle between on and off
        ledState = !ledState;
      }
    }
  }
  lastState = readSwitch;
  digitalWrite(ledPin,ledState);
}
