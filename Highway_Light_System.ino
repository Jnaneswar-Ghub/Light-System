
// IR Sensors connections
int IR1 = 8;
int IR2 = 9;
int IR3 = 2;
int IR4 = 11;
// LED's of respective IR's
int LED1 = 5;
int LED2 = 6;
int LED3 = 10;
int LED4 = 3;
// cars/vehicles
int vehicle = 0;
int vehicle1 = 1;
// connecting LDR.
int LDR;
int LDRstatus;
int LDRpin = A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
   pinMode(LED3,OUTPUT);
   pinMode(LED4,OUTPUT);
}
void loop() {
 
   LDRstatus = analogRead(LDRpin);
  if (LDRstatus <= 200)
      {
analogWrite(LED1,255);
Sensor_check();
        delay(100);
      }
  
  else {
         Serial.print("Its BRIGHT, no need of LEDs ");
       }
  
}

void Sensor_check()
{
  if (digitalRead(IR1) == 0)//Car captured in 1st sensor
  {

    if (digitalRead(IR2) == 1)//Car still didnt reach the 2nd sensor
    { vehicle = 1;
      if (vehicle == 1)
      {
        
        analogWrite(LED1, 255);
        analogWrite(LED2, 125);

      }
    }
  }
 if (digitalRead(IR2) == 0)//Car reached the 2nd sensor
  { //No cars detected behind the first car
    if (digitalRead(IR1) == 1)
    {
      vehicle = 0;
      vehicle1 = 1;
      if (vehicle == 0 && vehicle1 == 1)
      {
        analogWrite(LED2, 255);
        analogWrite(LED3, 125);
      }
    }

    else if (digitalRead(IR1) == 0 )
    {
      analogWrite(LED1, 255);
      analogWrite(LED2, 255);
      analogWrite(LED3, 125);
    }
  }

 if (digitalRead(IR3) == 0) //car reached the 3rd sensor
  {
    //No cars detected behind the first car
    if (digitalRead(IR2) == 1)
    {
      vehicle = 0;

      vehicle1 = 0;
      if (vehicle == 0 && vehicle1 == 0) {
        analogWrite(LED3, 255);
        analogWrite(LED4, 125);
      }
    }
    else if (digitalRead(IR2) == 0 )
    {
      vehicle = 0;
      vehicle1 = 1;
      if (vehicle == 0 && vehicle1 == 1) {
        analogWrite(LED2, 255);
        analogWrite(LED3, 255);
        analogWrite(LED4, 125);
      }
    }
  }
if (digitalRead(IR4) == 0) //car reached the 4rd sensor
  {
    //No cars detected behind the first car
    if (digitalRead(IR3) == 1)
    {
      vehicle = 0;
      vehicle1 = 0;
      if (vehicle == 0 && vehicle1 == 0)
      {
        analogWrite(LED4, 255);
      }
    }

 else if (digitalRead(IR3) == 0 )
    {
      vehicle = 0;
      vehicle1 = 1;
      if (vehicle == 0 && vehicle1 == 1)
      {
        analogWrite(LED3, 255);
        analogWrite(LED4, 255);
      }
    }
    if (digitalRead(IR2) == 1)
    {
      vehicle = 0;
      vehicle1 = 0;
      if (vehicle == 0 && vehicle1 == 0)
      {
        analogWrite(LED3, 255);
        analogWrite(LED4, 255);
      }
    }
    else if (digitalRead(IR2) == 0 )
    {
      vehicle = 0;
      vehicle1 = 1;
      if (vehicle == 0 && vehicle1 == 1)
      {
        analogWrite(LED2, 255);
        analogWrite(LED3, 255);
        analogWrite(LED4, 255);
      }
    }

  }
}
