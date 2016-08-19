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
		_spln(String(t1.elapsedtime()) + "ms passed from timer1: " );
		t1.restart();
	}

	if(t2.istimeout())
	{
		_spln(String(t2.elapsedtime()) + "ms passed from timer2: " );
		t2.restart();
	}

	if(t3.istimeout())
	{
		_spln(String(t3.elapsedtime()) + "ms passed from timer3: " );
		t3.restart();
	}
  
}//loop