void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);

}

void loop() {



  int frecuencia = 500000; //Hz
  int amplitud = 10; //normalizado de 0 a 100
  int volSal = (117*amplitud+13800)/100;
  //int volSal = map(amplitud,0,100,138,255);
  //Serial.println(volSal);
  onOffAnalog(frecuencia,9,volSal);




}

void onOffAnalog(int frecuencia,int pinSal, int volSal){
  int tiempo = 0;
  if (frecuencia<500) {
    tiempo = 500/frecuencia;
    ntoBits(volSal);
    delay(tiempo);
    cero();
    delay(tiempo);
  }
  else{
    tiempo = 500000 /frecuencia;  //us
    ntoBits(volSal);
    delayMicroseconds(tiempo);
    cero();
    delayMicroseconds(tiempo);
  }
  /*if (frecuencia>=62) {
      tiempo = 500000 /frecuencia;  //us
      ntoBits(volSal);
      //analogWrite(pinSal,230);
      delayMicroseconds(tiempo);
      PORTD = B00000000;
      //analogWrite(pinSal,0);
      delayMicroseconds(tiempo);
  }
  else{
    tiempo = 5000/ frecuencia;//ms
    analogWrite(pinSal,volSal);
    delay(tiempo);
    analogWrite(pinSal,0);
    delay(tiempo);
  }*/

}


void ntoBits(int numero) {
  short int Bit = 0;
  for(int i=0;i<=7;i++){
    if(numero>0){
      Bit=numero%2;
      digitalWrite(i,Bit);
      numero = numero/2;
    }
    else{
      digitalWrite(i,0);
    }
  }
}

void cero(){
  for (int i = 0; i < 7; i++) {
    digitalWrite(i,LOW);
  }
}
