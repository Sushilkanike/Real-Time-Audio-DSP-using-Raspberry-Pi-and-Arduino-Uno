const int pots = 6;
int val[pots];
float val_mapped[6];

void setup() {
  Serial.begin(9600);
  

}

void loop() {
  for(int i=0;i<pots;i++){
    val[i] = analogRead(i);
  }
  for(int i=0;i<pots;i++){
    val_mapped[0] = mapfloat(val[0],0.00,1023.00,0.00,15.00);
    val_mapped[1] = mapfloat(val[1],0.00,1023.00,0.00,15.00);
    val_mapped[2] = mapfloat(val[2],0.00,1023.00,0.00,15.00);
    val_mapped[3] = mapfloat(val[3],0.00,1023.00,0.00,2.00);
    val_mapped[4] = mapfloat(val[4],0.00,1023.00,0.00,2.00);
    val_mapped[5] = mapfloat(val[5],0.00,1023.00,0.00,2.00);
    //val_mapped[6] = 2.00 - val_mapped[5]; 
    Serial.print(val_mapped[i]);
    Serial.print(" ");
  }
  Serial.print(2-val_mapped[5]);
  Serial.print(" ");
  Serial.println();
  delay(100);

}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
