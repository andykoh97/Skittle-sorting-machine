  int moves=0;
  int steps=0;
  int currentpos=1;
  int Ystep=1;
  int Rstep=2;
  int Pstep=3;
  int Ostep=4;
  int Gstep=5;
void LowerStepper(char color){
if (color != ' '){
  if(color == 'Y'){
    steps = Ystep - currentpos;
    currentpos = Ystep;
    moves = steps*40;
  }
  if(color == 'R'){
    steps = Rstep - currentpos;
    currentpos = Rstep;
    moves = steps*40;
  }
  if(color == 'P'){
    steps = Pstep - currentpos;
    currentpos = Pstep;
    moves = steps*40;
  }
  if(color == 'O'){
    steps = Ostep - currentpos;
    currentpos = Ostep;
    moves = steps*40;
  }
  if(color == 'G'){
    steps = Gstep-currentpos;
    currentpos = Gstep;
    moves = steps*40;
  }
  if(moves == -120){
    moves = 80;
    }
  if(moves == 120){
    moves = -80;
    }
  if(moves == -160){
    moves = 40;
    }
  if(moves == 160){
    moves = -40;
    }
   lowerStepper.step(moves);
}
}
