int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;
int ledPin  = 13;

// the setup routine runs once when you press reset:
void setup() {  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);              
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
  pinMode(ledPin,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);

  if(sensorValue == 0){
    //led number display
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW); 
    showZero();
    //set led to low
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  else{
    //based on sensor value set led value
    if(sensorValue > 200){
       digitalWrite(ledPin, HIGH);
    }else{
       digitalWrite(ledPin, LOW);
    }

    //led number display
    String strSensorValue = String(sensorValue);
    
    for(int i=0; i < strSensorValue.length(); i++){
      if(i == 0){
          digitalWrite(D1, LOW);
          digitalWrite(D2, HIGH);
          digitalWrite(D3, HIGH);
          digitalWrite(D4, HIGH); 
          displayNumber(strSensorValue[i]);
          delay(500);
      }else if(i == 1){
          digitalWrite(D1, HIGH);
          digitalWrite(D2, LOW);
          digitalWrite(D3, HIGH);
          digitalWrite(D4, HIGH); 
          displayNumber(strSensorValue[i]);
         delay(500);               
      }else if(i == 2){
         digitalWrite(D1, HIGH);
         digitalWrite(D2, HIGH);
         digitalWrite(D3, LOW);
         digitalWrite(D4, HIGH); 
         displayNumber(strSensorValue[i]);
         delay(500);               
      }else{
        digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, LOW); 
        displayNumber(strSensorValue[i]);
        delay(500);               
      }
    }  
  }
}

void displayNumber(char num){
  switch(num){
    case '1':
    showOne();
    break;
    case '2':
    showTwo();
    break;
    case '3':
    showThree();
    break;
    case '4':
    showFour();
    //Serial.println("4");
    break;
    case '5':
    showFive();
    break;
    case '6':
    showSix();
    break;
    case '7':
    showSeven();
    break;
    case '8':
    showEight();
    break;
    case '9':
    showNine();
    break;
    default:
    // Serial.println("0");
    showZero();
    break;
  }
}

void showZero(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);   
}

void showOne(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW); 
}

void showTwo(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH); 
}

void showThree(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
}

void showFour(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);  
}

void showFive(){
 digitalWrite(pinA, HIGH);   
 digitalWrite(pinB, LOW);   
 digitalWrite(pinC, HIGH);   
 digitalWrite(pinD, HIGH);   
 digitalWrite(pinE, LOW);   
 digitalWrite(pinF, HIGH);   
 digitalWrite(pinG, HIGH);  
}

void showSix(){
 digitalWrite(pinA, HIGH);   
 digitalWrite(pinB, LOW);   
 digitalWrite(pinC, HIGH);   
 digitalWrite(pinD, HIGH);   
 digitalWrite(pinE, HIGH);   
 digitalWrite(pinF, HIGH);   
 digitalWrite(pinG, HIGH);  
}

void showSeven(){
 digitalWrite(pinA, HIGH);   
 digitalWrite(pinB, HIGH);   
 digitalWrite(pinC, HIGH);   
 digitalWrite(pinD, LOW);   
 digitalWrite(pinE, LOW);   
 digitalWrite(pinF, LOW);   
 digitalWrite(pinG, LOW);  
}

void showEight(){
 digitalWrite(pinA, HIGH);   
 digitalWrite(pinB, HIGH);   
 digitalWrite(pinC, HIGH);   
 digitalWrite(pinD, HIGH);   
 digitalWrite(pinE, HIGH);   
 digitalWrite(pinF, HIGH);   
 digitalWrite(pinG, HIGH);  
}

void showNine(){
 digitalWrite(pinA, HIGH);   
 digitalWrite(pinB, HIGH);   
 digitalWrite(pinC, HIGH);   
 digitalWrite(pinD, HIGH);   
 digitalWrite(pinE, LOW);   
 digitalWrite(pinF, HIGH);   
 digitalWrite(pinG, HIGH);  
}

