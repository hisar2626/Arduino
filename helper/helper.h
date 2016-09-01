/****************************************************************
	@By his 15.07.2015
	To help for programming Arduino IDE easily.

	TODO: Compatibility with different kind of boards
/****************************************************************/
#define HELPER_LIBRARY_VERSION 1.0


//No need for Serial.println command. easily use _spln()
#define _sp(f_, ...) Serial.print((f_),##__VA_ARGS__)
#define _spln(f_, ...) Serial.println((f_),##__VA_ARGS__)
#define _sln  Serial.println("")

//DEBUG MODE ON-OFF control
//#define SERIALDEBUGMODE 0x1  //uncomment to see the debug strings

//if debug mode activated, you can see your debug strings
// from the serial monitor.
#ifdef SERIALDEBUGMODE  //IF DEBUG MODE Active or not?
#define _dp(f_, ...) Serial.print((f_),##__VA_ARGS__)
#define _dpln(f_, ...) Serial.println((f_),##__VA_ARGS__)
#define _dln  Serial.println("");
#define _dp1(f_, ...) Serial1.print((f_),##__VA_ARGS__)
#define _dpln1(f_, ...) Serial1.println((f_),##__VA_ARGS__)
#define _dln1  Serial1.println("");
#define _dp2(f_, ...) Serial2.print((f_),##__VA_ARGS__)
#define _dpln2(f_, ...) Serial2.println((f_),##__VA_ARGS__)
#define _dln2  Serial2.println("");
#define _dp3(f_, ...) Serial3.print((f_),##__VA_ARGS__)
#define _dpln3(f_, ...) Serial3.println((f_),##__VA_ARGS__)
#define _dln3  Serial3.println("");

#else  // IF DEBUG MODE off, do nothing; this can be used for
	   // release mode.
#define _dp(f_, ...)
#define _dpln(f_, ...)
#define _dln
#define _dp1(f_, ...)
#define _dpln1(f_, ...)
#define _dln1
#define _dp2(f_, ...)
#define _dpln2(f_, ...)
#define _dln2
#define _dp3(f_, ...)
#define _dpln3(f_, ...)
#define _dln3
#endif
//****************************************************************


//TODO: Maybe new elapsedtimer class for micros can be written.

//Creates a timer using difference of millis time
//@restart: 	will restart the timer. istimeout function will return
//true if timeoutval+restart time bigger.
//@elapsedtime: returns how many ms passed after initialization of
//elapsedtimer.
//@istimeout:	will return true if the time difference is bigger then
//				timeout value + elapsedtimer creation or restart time.
class elapsedtimer
{
  public:
    elapsedtimer(uint32_t timeout = 0) {
      tnow = millis();
      timeoutval = timeout;
    }
    void restart() {
      tnow = millis();
    }

    uint32_t elapsedtime() {
      return millis() - tnow;
    }

    bool istimeout() {
      return ((millis() - tnow) >= timeoutval);
    }

  private:
    uint32_t tnow, timeoutval;
};

