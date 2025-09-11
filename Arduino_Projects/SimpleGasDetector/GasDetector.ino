// C++ code
//
int motor = 12;
int sensor = 0;
int buzzer = 11;
int bot = 13;
int limiar = 120;
bool mudou = true;

void setup()
{
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
}

void loop()
{
  sensor = analogRead(A0);
  bot = digitalRead(13);
  Serial.println(bot);
  
  if(bot!=1){
  mudou=false;
  }
  
  if (mudou == true)
  {
  	if (sensor >= limiar)
 	{
    	digitalWrite(motor,HIGH);
    	tone(buzzer,523,100);
  	}
  	else 
    	digitalWrite(motor,LOW);
    
  	}

  else 
  {
    delay(2000);
    mudou = true;
    digitalWrite(motor,LOW);
 
  }
    
  
}