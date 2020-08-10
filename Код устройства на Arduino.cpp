#define LED_PIN  13
#define LDR_PIN  A0
void setup() {
 pinMode(LED_PIN, OUTPUT);
 Serial.begin(9600);
}
void loop() {
  //Serial.print("5");
String text="";
  if (Serial.available()){
    //lcd.print("Start");
    delay(100);
    while(Serial.available()>0)
    {
    text = Serial.readString();
    }
      text = text.substring(0,5);
     
  }


  if(text == "hello"){
    
    int threshold = analogRead(LDR_PIN);
    digitalWrite(LED_PIN, HIGH);
   

    if (threshold<300) {  
      Serial.print("dark");
      digitalWrite(LED_PIN, HIGH);
  } 
    else {
      Serial.print("bright");
      digitalWrite(LED_PIN, LOW);
 }
}
}
