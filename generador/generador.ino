void setup() {
  pinMode(1,OUTPUT);
  Serial.begin(9600);

}

void loop() {


  
  int frecuencia = 1000; //Hz
  int amplitud = 10; //normalizado de 0 a 100
  int volSal = (117*amplitud+13800)/100;
  //Serial.println(volSal);
  onOffAnalog(frecuencia,9,volSal);




}

void onOffAnalog(int frecuencia,int pinSal, int volSal){
  int tiempo = 0;
  if (frecuencia>=62) {
      tiempo = 500000 /frecuencia;  //us
      analogWrite(pinSal,230);
      delayMicroseconds(tiempo);
      //analogWrite(pinSal,0);
      delayMicroseconds(tiempo);
  }
  else{
    tiempo = 5000/ frecuencia;//ms
    analogWrite(pinSal,volSal);
    delay(tiempo);
    analogWrite(pinSal,0);
    delay(tiempo);
  }

}

void onOff(int frecuencia,int pinSal){
  int tiempo = 0;
  if (frecuencia>=62) {
      tiempo = 1000000 /frecuencia;  //us
      digitalWrite(pinSal,HIGH);
      delayMicroseconds(tiempo);
      digitalWrite(pinSal,LOW);
      delayMicroseconds(tiempo);
  }
  else{
    tiempo = 1000/ frecuencia;//ms
    digitalWrite(pinSal,HIGH);
    delay(tiempo);
    digitalWrite(pinSal,LOW);
    delay(tiempo);
  }
}
