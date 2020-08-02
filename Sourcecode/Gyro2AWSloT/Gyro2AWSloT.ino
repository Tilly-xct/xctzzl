#include "sea_esp32_qspi.h"
#include "SimpleDHT.h"
#include "string.h"

#include "AWS_IOT.h"
#include "WiFi.h"

#define limit 500
#define back 120
#define rt 5000


AWS_IOT hornbill;

char WIFI_SSID[]="oshxctkkk";
char WIFI_PASSWORD[]="555111222";
char HOST_ADDRESS[]="a33k6ol1qy8r3i-ats.iot.us-east-1.amazonaws.com";
char CLIENT_ID[]= "ESP32";
char TOPIC_NAME[]= "$aws/things/ESP32/shadow/update";


int status = WL_IDLE_STATUS;
int tick=0,msgCount=0,msgReceived = 0,tick1=0;
char payload[512];
char rcvdPayload[512];
uint8_t data1[4] = {41,42,43,44};
uint8_t data2[32];
void mySubCallBackHandler (char *topicName, int payloadLen, char *payLoad)
{
    strncpy(rcvdPayload,payLoad,payloadLen);
    rcvdPayload[payloadLen] = 0;
    msgReceived = 1;
}
 int16_t read(int qy)
 {
  uint8_t a[4];
  int16_t *b;
  SeaTrans.read(qy,a,4);
  uint8_t c[2]={a[2],a[3]};
  b=(int16_t*)c;
  return *b;
  }
  int8_t state()
  {
    int16_t base=read(0);
    if(base+back<-limit)
    return -1;
    else if(base-back>limit)
    return 1;
    else
    return 0;
    }

void setup()
{
  
  Serial.begin(115200);
  //SeaTrans.begin();
  //SeaTrans.write(0, data1, 4);
  //SeaTrans.read(0, data2, 4);
  Serial.printf("%d %d %d %d\r\n",data2[0],data2[1],data2[2],data2[3]);
  delay(2000);

    while (status != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(WIFI_SSID);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

        // wait 5 seconds for connection:
        delay(5000);
    }

    Serial.println("Connected to wifi");

    if(hornbill.connect(HOST_ADDRESS,CLIENT_ID)== 0)
    {
        Serial.println("Connected to AWS");
        delay(1000);

        if(0==hornbill.subscribe(TOPIC_NAME,mySubCallBackHandler))
        {
            Serial.println("Subscribe Successfully");
        }
        else
        {
            Serial.println("Subscribe Failed, Check the Thing Name and Certificates");
            while(1);
        }
    }
    else
    {
        Serial.println("AWS connection failed, Check the HOST Address");
        while(1);
    }

    delay(2000);
  
}

void loop()
{
   uint8_t i;
    int count2=0; 
    int count=0;
    int ps=0;    
    int cs=0;    
    Serial.println("Ready go!");
    unsigned long st=millis();    
    while(millis()-st<rt)
    {
      cs=state();
      if(((cs==1)||(cs==-1))&&(cs!=ps))    count2++;
      ps=cs;
      
    }
    count=count2/2;

    sprintf(payload,"%d秒内摇动次数为%d",rt/1000,count);
   
   if(hornbill.publish(TOPIC_NAME,payload) == 0)
        {        
            Serial.println("Publish successfully!");
            Serial.println(payload);
        }
        else
        {
            Serial.println("Publish failed!");
        }
    
    msgReceived = 0;
    vTaskDelay(1000 / portTICK_RATE_MS); 
   
    tick++;

}
