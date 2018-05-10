void Containerservo () {
  if(Serial1.available() > 0){
    char val = Serial1.read();
    switch (val){ /* receive the signal from the app and move the corrsponding servo motor */
    case 'R':
      Serial.print(val);
      Serial.print('\t');
      myservoR.write(180);
      delay(500); 
      myservoR.write(0);
      delay(500); 
      break; 
      
      case 'O':
      Serial.print(val);
      Serial.print('\t');
      myservoO.write(180);

      delay(500); 
      myservoO.write(0);
      delay(500); 
      break;
       
      case 'Y':
      Serial.print(val);
      Serial.print('\t');
      myservoY.write(180);
      delay(500); 
      myservoY.write(0);
      delay(500); 
      break;
      
      case 'G':
      Serial.print(val);
      Serial.print('\t');
      myservoG.write(180);
      delay(500); 
      myservoG.write(0);
      delay(500); 
      break;
      
      case 'P':
      Serial.print(val);
      Serial.print('\t');
      myservoP.write(180);
      delay(500); 
      myservoP.write(0);
      delay(500); 
      break;
      default:
      break;
}
  }
  }
