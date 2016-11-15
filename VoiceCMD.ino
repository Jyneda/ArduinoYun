#include <Voice.h>

#define SUM 4 //SUM識別關鍵字的個數,最大不超過50個
uint8  nAsrStatus=0;

char sRecog[SUM][80] = {"guan bi deng dian", "da kai deng dian", "feng shan qi dong", "feng shan guan bi"};//每個關鍵字拼音字母個數不超過79個,用戶可以自行修改       ? 

int state=7;  //狀態指示燈
int led=8;    //受控制數字口


void finally (unsigned char n)
{
switch(n)  //n為陣列中對應關鍵字的序號，例如陣列sRecog中的第一個關鍵字為“kai deng”則對應的序號為0；

  {
  case 0:
    Serial.println( "guan bi deng dian x0;");
    break;
  case 1:
    Serial.println( "da kai deng dian x1;");
    break;
  case 2:
    Serial.println( "feng shan qi dong x2;");
    break;
  case 3:
    Serial.println( "feng shan guan bi x3;");
    break;
  default:
          Serial.println( "error");
                Serial.println( " ");
    break;  
  }
}

void ExtInt0Handler ()
{
  Voice.ProcessInt0();  //晶片送出中斷信號        
}

void setup()
{
  Serial.begin(9600);
  Voice.Initialise(MIC,VoiceRecognitionV1);//Initialise mode MIC or MONO,default is MIC
                                           //VoiceRecognitionV1 is VoiceRecognitionV1.0 shield
                                           //VoiceRecognitionV2 is VoiceRecognitionV2.1 module
  attachInterrupt(0,ExtInt0Handler,LOW);
  pinMode(led,OUTPUT);
  pinMode(state,OUTPUT);
  digitalWrite(state,HIGH);
  digitalWrite(led,HIGH);
}
void loop()
{  
        uint8 nAsrRes;
  nAsrStatus = LD_ASR_NONE;

  while(1)
  {
    switch(nAsrStatus)
    {
      case LD_ASR_RUNING:
      case LD_ASR_ERROR:    
        break;
      case LD_ASR_NONE:
      {
        nAsrStatus=LD_ASR_RUNING;
                            if (Voice.RunASR(SUM,80,sRecog)==0)  //識別不正確
        {      
          nAsrStatus= LD_ASR_ERROR;
                                        Serial.println( "ASR_ERROR"); 
        }
                              digitalWrite(state,LOW);
                              Serial.println( "ASR_RUNING.....");
        break;
      }
      case LD_ASR_FOUNDOK:
      {
                                digitalWrite(state,HIGH);
        nAsrRes =Voice. LD_GetResult();//一次ASR識別流程結束，去取ASR識別結果
                                finally(nAsrRes); 
        nAsrStatus = LD_ASR_NONE;
        break;
      }
      case LD_ASR_FOUNDZERO:
      default:
      {
        
        nAsrStatus = LD_ASR_NONE;
        break;
      }
           }// switch
              delay(500);
  }// while
}

