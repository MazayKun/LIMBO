#include <Keyboard.h>
unsigned long lastCheck;
int j_button_pin = 2;
int color_button_analog = A0;
int j_x_analog = A1;
int j_y_analog = A2;
bool isLeft;
bool isRight;
bool isUp;
bool isDown;
bool isCtrl;
bool isEsc;
bool isEnter;

void setup() {
  isLeft = false;
  isRight = false;
  isUp = false;
  isDown = false;
  isCtrl = false;
  isEsc = false;
  isEnter = false;
  pinMode(j_button_pin, INPUT);
  lastCheck = millis();
}

void loop() {
  if(millis() - lastCheck > 10){
    lastCheck = millis();
    if( (analogRead(j_x_analog) > 450) && (analogRead(j_x_analog) < 650) && (isLeft || isRight)){
      isLeft = false;
      isRight = false;
      Keyboard.release(KEY_LEFT_ARROW);
      Keyboard.release(KEY_RIGHT_ARROW);
    }
    if( (analogRead(j_x_analog) < 450) && !isLeft){
      isLeft = true;
      Keyboard.press(KEY_LEFT_ARROW);
    }
    if( (analogRead(j_x_analog) > 650) && !isRight){
      isRight = true;
      Keyboard.press(KEY_RIGHT_ARROW);
    }
    if( (analogRead(j_y_analog) > 450) && (analogRead(j_y_analog) < 650) && (isUp || isDown)){
      isUp = false;
      isDown = false;
      Keyboard.release(KEY_UP_ARROW);
      Keyboard.release(KEY_DOWN_ARROW);
    }
    if( (analogRead(j_y_analog) < 450) && !isUp){
      isUp = true;
      Keyboard.press(KEY_UP_ARROW);
    }
    if( (analogRead(j_y_analog) > 650) && !isDown){
      isDown = true;
      Keyboard.press(KEY_DOWN_ARROW);
    }
    if(((analogRead(color_button_analog) < 350) || (analogRead(color_button_analog) > 380)) && isCtrl){
      isCtrl = false;
      Keyboard.release(KEY_LEFT_CTRL);
    }
    if((analogRead(color_button_analog) > 350) && (analogRead(color_button_analog) < 380) && !isCtrl){
      isCtrl = true;
      Keyboard.press(KEY_LEFT_CTRL);
    }
    if(((analogRead(color_button_analog) < 1000) && isEsc)){
      isEsc = false;
      Keyboard.release(KEY_ESC);
    }
    if((analogRead(color_button_analog) > 1000) && !isEsc){
      isEsc = true;
      Keyboard.press(KEY_ESC);
    }
    if(((analogRead(color_button_analog) < 300) || (analogRead(color_button_analog) > 315)) && isEnter){
      isEnter = false;
      Keyboard.release(KEY_RETURN);
    }
    if((analogRead(color_button_analog) > 300) && (analogRead(color_button_analog) < 315) && !isEnter){
      isEnter = true;
      Keyboard.press(KEY_RETURN);
    }
  }
}
