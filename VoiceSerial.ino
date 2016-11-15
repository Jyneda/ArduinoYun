#include <SoftwareSerial.h>
#include <Bridge.h>

SoftwareSerial mySerial(8, 9); // RX, TX
String value;
boolean stringComplete = false;
char pin13[2];
int outcomming=0;
char outcome[4];

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);
  pinMode(13,OUTPUT);  
  Bridge.begin();
}

void loop(){
    value = Event();
    if (stringComplete){
      Serial.print("outcomming value = ");
      Serial.println(value);
      Bridge.put("CMD-I", value);
      itoa( (outcomming=outcomming^1), outcome, 10);
      Bridge.put("outcomming_CMD-I", outcome);
      Serial.print("outcomming state = ");
      Serial.println(outcome);
      stringComplete = false;
    }    
}

char ReadSerial(){
    char c;
    while (mySerial.available() <= 0){
      Bridge.get("Reg_done",  pin13, 2);
      digitalWrite(13, atoi(pin13));    
    }
    c = mySerial.read();
    return c;
}

String Event() {
  char c;
  String inputString = "";  
  inputString.reserve(200);
  while (stringComplete==false){
      c = ReadSerial();    
      Serial.print(c);
      if (c == 'x'){
          while ((c = ReadSerial()) != ';'){ 
             Serial.print(c);
             inputString+=c;
          }
          Serial.println(c);
          value = inputString;
          stringComplete = true;
          return inputString;
      }
  }
}
