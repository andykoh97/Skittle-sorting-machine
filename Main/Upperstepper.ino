void Upperstepper(){
  char test;
  char color;
  upperStepper.step(50);
  delay(333);
  test = Colorsensor();
  delay(333);
  color = Colorsensor();
  delay(333);
  color = Colorsensor();
  Serial1.write(color);
  LowerStepper(color);
  delay(500);
}
