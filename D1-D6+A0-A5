#include <Bridge.h>

char pin13[2];

char D2[5];
char D3[5];
char D4[5];
char D5[5];
char D6[5];
char D7[5];
char D8[5];

char incomming_D2[2]={'\0'};
char incomming_D3[2]={'\0'};
char incomming_D4[2]={'\0'};
char incomming_D5[2]={'\0'};
char incomming_D6[2]={'\0'};
char incomming_D7[2]={'\0'};
char incomming_D8[2]={'\0'};

int previous_incomming_D2=999;
int previous_incomming_D3=999;
int previous_incomming_D4=999;
int previous_incomming_D5=999;
int previous_incomming_D6=999;
int previous_incomming_D7=999;
int previous_incomming_D8=999;

int outcomming_A0=0;
int outcomming_A1=0;
int outcomming_A2=0;
int outcomming_A3=0;
int outcomming_A4=0;
int outcomming_A5=0;
char outcome[4];

float value;
char  valueString[23];

void setup() {
    pinMode(13,OUTPUT);
    pinMode(2,OUTPUT);    
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);    
    pinMode(5,OUTPUT);    
    pinMode(6,OUTPUT);    
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);    

    Bridge.begin();   // Pins 0 and 1 should be avoided as they are used by the Bridge library.
    Serial.begin(115200);
}
 
void loop() {
    Bridge.get("Reg_done",  pin13, 2);
    digitalWrite(13, atoi(pin13));    
   
    Bridge.get("incomming_D2",  incomming_D2, 2);
    if (atoi(incomming_D2)!=previous_incomming_D2){
        Bridge.get("D2",  D2, 5);
        D2[4]='\0';
        previous_incomming_D2=atoi(incomming_D2);
        digitalWrite(2, atoi(D2));        
    }

    Bridge.get("incomming_D3",  incomming_D3, 2);
    if (atoi(incomming_D3)!=previous_incomming_D3){
        Bridge.get("D3",  D3, 5);
        D3[4]='\0';
        previous_incomming_D3=atoi(incomming_D3);
        digitalWrite(3, atoi(D3));        
    }

    Bridge.get("incomming_D4",  incomming_D4, 2);
    if (atoi(incomming_D4)!=previous_incomming_D4){
        Bridge.get("D4",  D4, 5);
        D4[4]='\0';
        previous_incomming_D4=atoi(incomming_D4);
        digitalWrite(4, atoi(D4));        
    }

    Bridge.get("incomming_D5",  incomming_D5, 2);
    if (atoi(incomming_D5)!=previous_incomming_D5){
        Bridge.get("D5",  D5, 5);
        D5[4]='\0';
        previous_incomming_D5=atoi(incomming_D5);
        digitalWrite(5, atoi(D5));        
    }

    Bridge.get("incomming_D6",  incomming_D6, 2);
    if (atoi(incomming_D6)!=previous_incomming_D6){
        Bridge.get("D6",  D6, 5);
        D6[4]='\0';
        previous_incomming_D6=atoi(incomming_D6);
        digitalWrite(6, atoi(D6));        
    }

    Bridge.get("incomming_D7",  incomming_D7, 2);
    if (atoi(incomming_D7)!=previous_incomming_D7){
        Bridge.get("D7",  D7, 5);
        D7[4]='\0';
        previous_incomming_D7=atoi(incomming_D7);
        digitalWrite(7, atoi(D7));        
    }

    Bridge.get("incomming_D8",  incomming_D8, 2);
    if (atoi(incomming_D8)!=previous_incomming_D8){
        Bridge.get("D8",  D8, 5);
        D8[4]='\0';
        previous_incomming_D8=atoi(incomming_D8);
        digitalWrite(8, atoi(D8));        
    }

    value = analogRead(0);
    Serial.println(value);
    dtostrf(value, 10, 10, valueString); 
    Serial.println(valueString);
    Bridge.put("A0", valueString);
    itoa( (outcomming_A0=outcomming_A0^1), outcome, 10);
    Bridge.put("outcomming_A0", outcome);

    value = analogRead(1);
    dtostrf(value, 10, 10, valueString);     
    Bridge.put("A1", valueString);
    itoa( (outcomming_A1=outcomming_A1^1), outcome, 10);
    Bridge.put("outcomming_A1", outcome);

    value = analogRead(2);
    dtostrf(value, 10, 10, valueString);     
    Bridge.put("A2", valueString);
    itoa( (outcomming_A2=outcomming_A2^1), outcome, 10);
    Bridge.put("outcomming_A2", outcome);

    value = analogRead(3);
    dtostrf(value, 10, 10, valueString);     
    Bridge.put("A3", valueString);
    itoa( (outcomming_A3=outcomming_A3^1), outcome, 10);
    Bridge.put("outcomming_A3", outcome);

    value = analogRead(4);
    dtostrf(value, 10, 10, valueString);     
    Bridge.put("A4", valueString);
    itoa( (outcomming_A4=outcomming_A4^1), outcome, 10);
    Bridge.put("outcomming_A4", outcome);      

    value = analogRead(5);
    dtostrf(value, 10, 10, valueString);     
    Bridge.put("A5", valueString);
    itoa( (outcomming_A5=outcomming_A5^1), outcome, 10);
    Bridge.put("outcomming_A5", outcome);    

    delay(50);
}
