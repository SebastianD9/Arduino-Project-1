

#include "Keyboard.h"
#define BUTTON 7
#define BUTTON_EXIT 4
#define BUTTON_SPOTIFY 2
#define VOLUME A5

int x = 0;
int y=0;
int z=0;

void setup() {

  Serial.begin(9600);
  
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUTTON_EXIT, INPUT_PULLUP);
  pinMode(BUTTON_SPOTIFY, INPUT_PULLUP);

  Keyboard.begin();

  x=analogRead(VOLUME);
  x=map(x, 0, 1000, 0, 100);
  
}

void loop() {

  y=analogRead(VOLUME);
  y=map(y, 20, 900, 0, 100);
  
  Serial.println(y);
  delay(100);
  if(x!=y && (x+1)!=y && (x-1)!=y && x!=(y+1) && x!=(y-1) && (x+2)!=y && (x-2)!=y && x!=(y+2) && x!=(y-2)){
    z=x;
    x=y;
    Serial.println(y);
    delay(100);
    
    if(y>z) {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_UP_ARROW);
      delay(100);
      Keyboard.releaseAll();
      delay(100);
      }
    else {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_DOWN_ARROW);
      delay(100);
      Keyboard.releaseAll();
      delay(100);
      }
    
    }
  
  if (digitalRead(BUTTON) == LOW ){
    Keyboard.press(KEY_LEFT_GUI);
    delay(100);
    Keyboard.release(KEY_LEFT_GUI);
    delay(200);
    Keyboard.println("Chrome");
    delay(100);
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(1000);
    }
   
   if(digitalRead(BUTTON_EXIT) == LOW){
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F4);
    delay(100);
   Keyboard.releaseAll();
    delay(200);
    }

    if(digitalRead(BUTTON_SPOTIFY)==LOW){
      Keyboard.press(KEY_LEFT_GUI);
      delay(100);
      Keyboard.release(KEY_LEFT_GUI);
      delay(100);
      Keyboard.println("spotify");
      delay(100);
      Keyboard.press(KEY_RETURN);
      delay(100);
      Keyboard.release(KEY_RETURN);
      delay(3000);
      Keyboard.write((char) 32);
      delay(100);
      }
}
