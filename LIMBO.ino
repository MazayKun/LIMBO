#include <Keyboard.h>
unsigned long lastCheck;
int j_button_pin = 2;
int color_button_analog = A0;
int j_x_analog = A1;
int j_y_analog = A2;
bool isLeft;
bool isRight;
bool isJump;
bool isDown;
bool isCtrl;
bool isEsc;
bool isEnter;

void setup() {
  Serial.begin(9600);
  isLeft = false;
  isRight = false;
  isJump = false;
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
    if( (analogRead(j_x_analog) > 50) && (analogRead(j_x_analog) < 850) && (isLeft || isRight)){
      isLeft = false;
      isRight = false;
      Keyboard.release(KEY_LEFT_ARROW);
      Keyboard.release(KEY_RIGHT_ARROW);
    }
    if( (analogRead(j_x_analog) < 50) && !isLeft){
      isLeft = true;
      Keyboard.press(KEY_LEFT_ARROW);
    }
    if( (analogRead(j_x_analog) > 850) && !isRight){
      isRight = true;
      Keyboard.press(KEY_RIGHT_ARROW);
    }
 
    if(((analogRead(color_button_analog) < 230) || (analogRead(color_button_analog) > 300)) && isCtrl){
      isCtrl = false;
      Keyboard.release(KEY_LEFT_CTRL);
    }
    if((analogRead(color_button_analog) > 230) && (analogRead(color_button_analog) < 300) && !isCtrl){
      isCtrl = true;
      Keyboard.press(KEY_LEFT_CTRL);
    }
    if(((analogRead(color_button_analog) < 1000) && isJump)){
      isJump = false;
      Keyboard.release(KEY_UP_ARROW);
    }
    if((analogRead(color_button_analog) > 1000) && !isJump){
      isJump = true;
      Keyboard.press(KEY_UP_ARROW);
    }
    if(((analogRead(color_button_analog) < 300) || (analogRead(color_button_analog) > 390)) && isDown){
      isDown = false;
      Keyboard.release(KEY_DOWN_ARROW);
    }
    if((analogRead(color_button_analog) > 300) && (analogRead(color_button_analog) < 390) && !isDown){
      isDown = true;
      Keyboard.press(KEY_DOWN_ARROW);
    }
    Serial.println(analogRead(j_x_analog));
  }
}
