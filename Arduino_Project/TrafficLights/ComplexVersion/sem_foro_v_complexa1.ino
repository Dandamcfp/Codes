// C++ code by Daniela Pinheiro
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

//SINAL PEDESTRE
void pedestre()
{
  
  digitalWrite(pverd,HIGH);
  digitalWrite(cv,HIGH);
  digitalWrite(ca,LOW);
  digitalWrite(cverd,LOW);
  digitalWrite(pv,LOW);
  tone(buzzer,500,2000);
  delay(8000);
}

//SINAL CARRO
void carro()
{
  liga = digitalRead(bot);
  verde();
  if(liga !=0)
  {
  pedestre();
  }
  amarelo();
}

//SINAL VERDE CARRO
void verde()
{
  
  for(int varia = 0; varia < 9; varia++) 
  {
  int liga = digitalRead(bot);
  if(liga !=0)
  {
  pedestre();
  }
    digitalWrite(cverd, HIGH);
    digitalWrite(cv, LOW);
    digitalWrite(ca,LOW);
    digitalWrite(pverd,LOW);
    digitalWrite(pv,HIGH);
    delay(1400);
  liga = digitalRead(bot);
  if(liga !=0)
  {
  pedestre();
  }
    
  }
}

//Sinal Amarelo
void amarelo()
{
  
  for(int varia = 0; varia < 2; varia++) 
  {
  int liga = digitalRead(bot);
  if(liga !=0)
  {
  pedestre();
  }
    digitalWrite(ca,HIGH);
    digitalWrite(cv,LOW);
    digitalWrite(cverd,LOW);
    digitalWrite(pv,HIGH);
    digitalWrite(pverd,LOW);
    delay(1000);
  }
}
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
    pedestre();
    } 
    carro(); 
    pedestre();
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