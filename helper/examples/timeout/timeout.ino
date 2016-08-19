#include <helper.h>

elapsedtimer t1(5000);
elapsedtimer t2(3000);
elapsedtimer t3(1000);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(t1.istimeout())
 {
  _spln("5 seconds passed from t1");
  t1.restart();
 }
  if(t2.istimeout())
  {
    _spln("3 seconds passed from t2");
    t2.restart();
  }
  

  if(t3.istimeout())
  {
    _spln("1 second  passed from t3");
    t3.restart();
  }
  
  
}
