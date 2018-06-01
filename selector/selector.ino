void setup() {
        for (int i = 0; i < 2; i++) {
                pinMode(i,OUTPUT);
        }
}

void loop() {
        int señal=0;
        digitaWrite(señal,HIGH);
        for (int i = 0; i < 3; i++) {
                if(i!=señal) {
                        digitaWrite(i,LOW);
                }
        }

}
