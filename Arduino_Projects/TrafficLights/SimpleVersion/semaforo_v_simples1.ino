// C++ code
// Created by Daniela Carolina Freitas Pinheiro 

//Carro
int cv = 13;
int ca = 12;
int cverd = 11;
//Pedestre
int pv = 10;
int pverd= 9;
int bot = 7;
//Outros
int pot = 0;
int foto = 1;
int buzzer = 8;
//variaveis extras
int liga;
int luz, limiar;

void setup()
{
  pinMode(buzzer,OUTPUT);
  pinMode(pverd,OUTPUT);
  pinMode(pv,OUTPUT);
  pinMode(cverd,OUTPUT);
  pinMode(ca,OUTPUT);
  pinMode(cv,OUTPUT);
  Serial.begin(9600);

}

void loop()
{ 
  luz = analogRead(foto);
  limiar = analogRead(pot);
  Serial.println(luz);
  //Serial.println(limiar);
  delay(3000);
  //De dia
  while (luz < limiar)
  {
    liga = digitalRead(bot);
    if (liga != 0)
    {
   	  digitalWrite(cv,HIGH);
      digitalWrite(cverd,LOW);
      digitalWrite(ca,LOW);
      digitalWrite(pv,LOW);
      digitalWrite(pverd,HIGH);
    } 
    //VERDE
    digitalWrite(cv,LOW);
    digitalWrite(cverd,HIGH);
    digitalWrite(ca,LOW);
    digitalWrite(pv,HIGH);
    digitalWrite(pverd,LOW);
    delay(15000);
    
    //VERMELHO
    digitalWrite(cv,HIGH);
    digitalWrite(cverd,LOW);
    digitalWrite(ca,LOW);
    digitalWrite(pv,LOW);
    digitalWrite(pverd,HIGH);
    delay(8000);
    
    //AMARELO
    digitalWrite(cv,LOW);
    digitalWrite(ca,HIGH);
    digitalWrite(cverd,LOW);
    delay(2000);
    
    luz = analogRead(foto);
  	limiar = analogRead(pot);
  }
  //De noite
   while (luz > limiar)
  {
     digitalWrite(ca,HIGH);
     digitalWrite(cv,LOW);
     digitalWrite(cverd,LOW);
     digitalWrite(pv,LOW);
     digitalWrite(pverd,LOW);
     delay(1000);
     digitalWrite(ca,LOW);
     delay(1000);
     luz = analogRead(foto);
  	 limiar = analogRead(pot);
   }

}