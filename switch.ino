int led1=2;
int switch1=6;
int led=10;
int switch2=8;

void setup(){
  pinMode(led1, OUTPUT);
 
  pinMode(switch1, INPUT);
  pinMode(led, OUTPUT);
 
  pinMode(switch2, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  if (digitalRead(switch1)==HIGH){
    digitalWrite(led1, LOW);
    
    Serial.println("Your switch1 is Closed");
  }
  else if (digitalRead(switch2)==HIGH){
    digitalWrite(led, LOW);
    
    Serial.println("Your switch2 is Closed");
  }
  else {
    digitalWrite(led1, HIGH);
    digitalWrite(led, HIGH);
    
    
    Serial.println("Your switch is Open");
  }
  delay(1);
}
