int led=3;
int nabizsensor=A0;
double alpha=0.75;
int periyot=20;
double degisim=0.0;

void setup() 
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);

}

void loop()
{
  static double eskideger=0;
  static double eskidegisim=0;
  int hamdeger=analogRead(nabizsensor);
  double deger= alpha*eskideger+(1-alpha)*hamdeger;
  degisim=deger-eskideger;
  Serial.println(degisim);

  digitalWrite(led,(degisim<-5.0 && eskidegisim>5.0));
  eskideger=deger;
  eskidegisim=degisim;
  delay(periyot);

}
