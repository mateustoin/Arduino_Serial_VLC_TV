#include <IRremote.h>  
  
int RECV_PIN = 8;  
float armazenavalor;
int test;
int led = 9;
int buzzer = 11;
int contLD = 0;
  
IRrecv irrecv(RECV_PIN);  
decode_results results;  
  
void setup()  
{ 
  pinMode (led, OUTPUT);  
  pinMode (buzzer, OUTPUT);
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR  
}  
   
void loop()  
{  
  if (irrecv.decode(&results))  
  {   
  armazenavalor = (results.value);
  Serial.println (results.value, HEX);
  
  if(armazenavalor == 0x1002609F){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = -1;
      Serial.println(test); 
    }
  
  if(armazenavalor == 0x100210EF){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 0;
      Serial.println(test); 
    }
    if(armazenavalor == 0x1002906F){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 1;
      Serial.println(test); 
    }
    if(armazenavalor == 0x100250AF){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 2;
      Serial.println(test); 
    }
    if(armazenavalor == 0x100230CF){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 3;
      Serial.println(test); 
    }
    if(armazenavalor == 0x1002B04F){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 4;
      Serial.println(test); 
    } 
   if(armazenavalor == 0x1002708F){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 5;
      Serial.println(test);
   }
    if(armazenavalor == 0x1002F807){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 6;
      Serial.println(test);
   }
   if(armazenavalor == 0x10028877){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 7;
      Serial.println(test);
   }
  if(armazenavalor == 0x1002A857){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 8;
      Serial.println(test); 
    } 
    if(armazenavalor == 0x1002D02F){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 9;
      Serial.println(test);
    }
    if(armazenavalor == 0x1002F00F){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 10;
      Serial.println(test);
    }
    if(armazenavalor == 0x10029867){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 11;
      Serial.println(test);
    }
    if(armazenavalor == 0x100218E7){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 12;
      Serial.println(test);
    }
    if(armazenavalor == 0x10027887){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      test = 13;
      Serial.println(test);
    }
    
    if (armazenavalor == 0x100240BF){ //Botao store
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      Serial.println (16);
    }
    
    if(armazenavalor == 0x100220DF){
      digitalWrite (led, HIGH);
      digitalWrite (buzzer, HIGH);
      delay (50);
      if (contLD == 0){
      test = 14;
      Serial.println(test);
      contLD++;  
  }
      else if (contLD == 1){
      Serial.println(15);
      contLD--;
      }
    }
  irrecv.resume(); //Le o próximo valor  
  }  
  
  digitalWrite (led, LOW);
  digitalWrite (buzzer, LOW);
} 
