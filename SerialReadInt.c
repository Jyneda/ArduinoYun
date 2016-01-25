int value;
//int value1;
boolean stringComplete = false;

void setup() {
  Serial.begin(115200);
 }

void loop(){
  serialEvent();
  if (stringComplete) {
    Serial.println(value);        
//  Serial.println(value1);    
    stringComplete = false;
  }
}

void serialEvent() {
  char c;
  String inputString = "";  
  inputString.reserve(200);
//int i=0;
//char str[200];
  while (stringComplete==false){
    if (Serial.available() > 0){
        if ((c = Serial.read())=='x'){
          while( (c = Serial.read())!=';' ){
                  inputString+=(char)c;
//                str[i]=(char)c;
//                i++;                                
          } 
          value= inputString.toInt();
//        str[i]='\0'; 
//        value1=atoi(str);
//        i=0;
          stringComplete = true;
      }
    }
  }
}
