int value;
boolean stringComplete = false;

void setup() {
  Serial.begin(115200);
 }

void loop(){
  serialEvent();
  if (stringComplete) {
    Serial.println(value);        
    stringComplete = false;
  }
}

void serialEvent() {
  char c;
  String inputString = "";  
  inputString.reserve(200);
  while (stringComplete==false){
    if (Serial.available() > 0){
        if ((c = Serial.read())=='x'){
          while (1){
            while (Serial.available() <= 0) {};
            if ((c = Serial.read())==';') break;
            inputString+=(char)c;
          }
          value= inputString.toInt();
          stringComplete = true;
        }
    }
  }
}
