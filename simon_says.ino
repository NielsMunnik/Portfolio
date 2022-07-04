const int MAX_LVL = 10;

int volgorde[MAX_LVL];

int eigen_volg[MAX_LVL];

int LVL = 1;

int snelheid = 1000;

 

void setup(){

  pinMode(A0, INPUT);

  pinMode(A1, INPUT);

  pinMode(A2, INPUT);

  pinMode(A3, INPUT);

  pinMode(2, OUTPUT);

  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);

  digitalWrite(2, LOW);

  digitalWrite(3, LOW);

  digitalWrite(4, LOW);

  digitalWrite(5, LOW);

}

void loop(){

  if(LVL == 1)

  genereer_volg();

  if(digitalRead(A0) == HIGH && digitalRead(A3) == HIGH || LVL != 1){

    show_volg();

    get_volg();

  }

}

 

void show_volg(){

  digitalWrite(2, LOW);

  digitalWrite(3, LOW);

  digitalWrite(4, LOW);

  digitalWrite(5, LOW);

  for(int i = 0; i < LVL; i++){

    digitalWrite(volgorde[i], HIGH);

    delay(snelheid);

    digitalWrite(volgorde[i], LOW);

    delay(200);

  }

}

 

void get_volg(){

  int vlag = 0;

  for(int i = 0; i < LVL; i++){

    vlag = 0;

    while(vlag == 0){

      if(digitalRead(A0) == LOW){

        digitalWrite(5, HIGH);

        eigen_volg[i] = 5;

        vlag = 1;

        delay(200);

        if(eigen_volg[i] != volgorde[i]){

          verkeerde_volg();

          return;

        }

        digitalWrite(5, LOW);

      }

      if(digitalRead(A1) == LOW){

        digitalWrite(4, HIGH);

        eigen_volg[i] = 4;

        vlag = 1;

        delay(200);

        if(eigen_volg[i] != volgorde[i]){

          verkeerde_volg();

          return;

        }

        digitalWrite(4, LOW);

      }

      if(digitalRead(A2) == LOW){

        digitalWrite(3, HIGH);

        eigen_volg[i] = 3;

        vlag = 1;

        delay(200);

        if(eigen_volg[i] != volgorde[i]){

verkeerde_volg();

return;

}

digitalWrite(3, LOW);

}

if(digitalRead(A3) == LOW){

digitalWrite(2, HIGH);

eigen_volg[i] = 2;

vlag = 1;

        delay(200);

        if(eigen_volg[i] != volgorde[i]){

          verkeerde_volg();

          return;

        }

        digitalWrite(2, LOW);

      }

    }

  }

  goede_volg();

}

 

void genereer_volg(){

  randomSeed(millis());

  for(int i = 0; i < MAX_LVL; i++){

    volgorde[i] = random(2, 6);

  }

}

 

void verkeerde_volg(){

  for(int i = 0; i < 3; i++){

    digitalWrite(2, HIGH);

    digitalWrite(3, HIGH);

    digitalWrite(4, HIGH);

    digitalWrite(5, HIGH);

    delay(250);

    digitalWrite(2, LOW);

    digitalWrite(3, LOW);

    digitalWrite(4, LOW);

    digitalWrite(5, LOW);

    delay(250);

  }

  LVL = 1;

  snelheid = 1000;

}

 

void goede_volg(){

  digitalWrite(2, LOW);

  digitalWrite(3, LOW);

  digitalWrite(4, LOW);

  digitalWrite(5, LOW);

  delay(250);

  digitalWrite(2, HIGH);

  digitalWrite(3, HIGH);

  digitalWrite(4, HIGH);

  digitalWrite(5, HIGH);

  delay(500);

  digitalWrite(2, LOW);

  digitalWrite(3, LOW);

  digitalWrite(4, LOW);

  digitalWrite(5, LOW);

  delay(250);

  if(LVL < MAX_LVL);

  LVL++;

  snelheid -= 100;

}
