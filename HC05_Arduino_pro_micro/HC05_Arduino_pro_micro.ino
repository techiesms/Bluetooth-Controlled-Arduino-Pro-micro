
/*
   Modified by team @techiesms
*/

#include <Keyboard.h>
int dataFromMaster = 0;

// Init function
void setup()
{

  Serial.begin(115200);
  Serial1.begin(38400);


}

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void loop() 
{
  if (Serial1.available() > 0) { // Checks whether data is comming from the Serial1 port
    dataFromMaster = Serial1.read(); // Reads the data from the Serial1 port and store it in dataFromMaster variable
    Serial1.println(dataFromMaster);
    Serial.println(dataFromMaster);
  }
  // Controlling the led
  if (dataFromMaster == 'L' || dataFromMaster == 'l')
  {
    LOCK();
  }
}


void LOCK() {
  // Begining the stream
  Keyboard.begin();

  // Waiting 500ms for init
  delay(500);

  // Lock Me 0.3 - Script opens Notepad and types a message concerning locking the computer - by SurfKahuna (RJC)
  delay(500);

// CMD+SHIFT+q
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('q');
  Keyboard.releaseAll();

  delay(200);

  typeKey(KEY_RETURN);
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  typeKey(KEY_RETURN);

  Keyboard.releaseAll();

}
