char Colorsensor() {
  char color;
  uint16_t r, g, b, c, colorTemp, lux;
  
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);
  uint32_t sum = c;
  float R, G, B;
  R=r; R/= sum;
  G=g; G /= sum;
  B=b; B/= sum;
  R*=256; G*=256; B*=256; /* change the value from the sensor to a range of 0-255 */
  Serial.print("R: "); Serial.print(R); Serial.print(" ");
  Serial.print("G: "); Serial.print(G); Serial.print(" ");
  Serial.print("B: "); Serial.print(B); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");

  if(R > 190 && c > 400 && c < 995){
    color = 'R';
    }
    
  else if(R > 150 && c > 995){
    color = 'O';
    }
    
  else if(G > 120){
    color = 'G';
    }
    
  else if( R> 110 && G > 90 && c > 1000 ){
    color = 'Y';
    }
    
  else if(c < 400){
    color = 'P';
    }
   else {color = ' '; }
  Serial.print(color);
  Serial.println(" ");
  return color;
}
 
