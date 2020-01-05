#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define OLED_RESET -1
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

uint8_t tiktok_logo[] = {// 'tiktoklogo2', 44x44px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 
0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfc, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 
0x01, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 
0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x01, 0xf7, 0xf0, 0x00, 0x00, 0x03, 0xe1, 0xf0, 
0xf0, 0x00, 0x00, 0x0f, 0xf1, 0xf0, 0x08, 0x00, 0x00, 0x1f, 0xf1, 0xf0, 0x00, 0x00, 0x00, 0x3f, 
0xf1, 0xf0, 0x00, 0x00, 0x00, 0x3f, 0xf1, 0xf0, 0x00, 0x00, 0x00, 0x7f, 0x09, 0xf0, 0x00, 0x00, 
0x00, 0x7e, 0x81, 0xf0, 0x00, 0x00, 0x00, 0xfd, 0x01, 0xf0, 0x00, 0x00, 0x00, 0xfc, 0x01, 0xf0, 
0x00, 0x00, 0x00, 0xfc, 0x01, 0xf0, 0x00, 0x00, 0x00, 0xfc, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x7e, 
0x03, 0xf0, 0x00, 0x00, 0x00, 0x7e, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x7f, 0x0f, 0xf8, 0x00, 0x00, 
0x00, 0x3f, 0xff, 0xe8, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xd0, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x80, 
0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 
0xf1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { 
    Serial.println(F("SSD1306 allocation failed"));
  }
  display.clearDisplay();
  display.setRotation(2);
  display.setTextColor(WHITE);
}

void showText(){
  display.clearDisplay();
  display.setCursor(0, 10);
  display.setTextSize(2);
  display.println("Tomas'");
  display.println("project");
  display.display();
  delay(1000);
}

void showImg(){
  display.clearDisplay();
  display.drawBitmap(0, 0, tiktok_logo, 44, 44, WHITE);
  display.display();
  delay(1000);
}

void drawTrinangle(){

  float p1[] = {0, 0.866f};
  float p2[] = {1, -0.866f};
  float p3[] = {-1, -0.866f};

  float* points[] = {p1, p2, p3};
  float out[] = {0, 0, 0, 0, 0, 0};

  for(int i = 0; i < 120; i+=18){
    float angle = 2*PI / 360.0f * i;
    display.clearDisplay();
    for(int i = 0; i < 3; i++){
      float rx = points[i][0]* cos(angle) - points[i][1]* sin(angle);
      float ry = points[i][0]* sin(angle) + points[i][1]* cos(angle);
      float x = rx*8 + 64;
      float y = ry*8 + 12;
      out[i*2] = x;
      out[i*2 + 1] = y;
    }
    display.fillTriangle(out[0], out[1], out[2], out[3], out[4], out[5], WHITE);
    display.display();
    delay(100);
  }
}

void sinus(){
  int x = 0;
  while(x < 150){
    display.clearDisplay();
    float angle = 2*PI / 360.0f;
    for(int i = 0; i < 128; i++){
      display.fillRect(i, 10 + 10*sin(angle * (i + x)*3), 1, 2, WHITE);
      display.fillRect(i, 10 + 10*cos(angle * (i - x)*3), 1, 1, WHITE);
    }
    delay(20);
    display.display();
    x+=6;
  }
}


void increasingText(){
    int number = 0;
    for(;number <= 2700; number+=5){
      display.clearDisplay();
      display.setTextSize(3);
      display.setCursor(36, 2);
      display.printf("%d", number);
      display.display();
      delay(50);
    }
    display.clearDisplay();
    display.setCursor(36, 2);
    display.println("2700");
    display.display();
    delay(100);
}

void chessboard(){
  int a = 0;
  while(a < 6){
    display.clearDisplay();
    for(int i = -1; i <17; i++){
      int x = i*8 + a;
      if(x > 126){
        x-=127;
      }
      for(int j = 0; j < 5; j++){
        int y = j* 8;
        display.fillRect(x, y, 8, 8, (i+j) %2 == 0 ?WHITE: BLACK);
      }
    }
    display.display();
    delay(80);
  a++;
  }
}

int getX(float point[], float angle){
  float oldx = (point[0]) * 20;
  float x = point[0] * cos(angle) + sin(angle) * point[2];
  float z = -point[0]*sin(angle) + point[2]*cos(angle) + 1.55f;
  return 64 + (int)(x/z * 20);
}

int getY(float point[], float angle){
  float z = -(point[0]) *sin(angle) + point[2]*cos(angle)+ 1.55f;
  float y = 22  + ((point[1]) / z) * 10;
  return (int)y;
}

float ppoint0[] = {-0.8f, 1.f, -0.8f};
float ppoint1[] = {0.8f, 1, -0.8f};
float ppoint2[] = {0.8f, 1, 0.8f};
float ppoint3[] = {-0.8f, 1, 0.8f};
float ppoint4[] = {0, -2.5f, 0};

float* ppoints[] = {ppoint0, ppoint1, ppoint2, ppoint3, ppoint4};
  
void rotatingPyramid(){
  for(int a = 0; a < 90; a+=10){
    float angle = 2*PI / 360 * a;
    display.clearDisplay();
    
    for(int i = 0; i < 5; i++){
      int x1 = getX(ppoints[i], angle);
      int y1 = getY(ppoints[i], angle);
      int x2; int y2;
      if(i < 4){
        x2 = getX(ppoints[i + 1], angle);
        y2 = getY(ppoints[i + 1], angle);
        display.drawLine(x1, y1, x2, y2, WHITE); 
      }
      if(i == 0){
        x2 = getX(ppoints[3], angle);
        y2 = getY(ppoints[3], angle);
        display.drawLine(x1, y1, x2, y2, WHITE); 
        x2 = getX(ppoints[4], angle);
        y2 = getY(ppoints[4], angle);
        display.drawLine(x1, y1, x2, y2, WHITE); 
      }else if(i == 1){
        x2 = getX(ppoints[4], angle);
        y2 = getY(ppoints[4], angle);
        display.drawLine(x1, y1, x2, y2, WHITE); 
      }else if(i == 2){
        x2 = getX(ppoints[4], angle);
        y2 = getY(ppoints[4], angle);
        display.drawLine(x1, y1, x2, y2, WHITE); 
      }
    } 
    display.display();
    delay(100);
  }
}

void loop() {
  rotatingPyramid();
  //chessboard();
  /*increasingText();
  sinus();
  showText();
  showImg();
  drawTrinangle();*/
}
