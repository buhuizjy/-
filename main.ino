#include <Key.h>
#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4); // RX, TX 摄像头
const byte rows = 4; //four rows
const byte cols = 3; //three columns
char shuru[4][10];
char quchu[10];
int i=0;
int j=0;
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[rows] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[cols] = {8, 7, 6}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols ); 
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  mySerial.begin(9600); // set the data rate for the SoftwareSerial port
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
 oledinit();

}

void loop() {
  // put your main code here, to run repeatedly:
   display.clearDisplay();
   char key= keypad.getKey();
 if(key==1){
   display.clearDisplay();
   display.setTextSize(4);
   display.setCursor(8,16);
   display.println("请扫描条形码");
   display.display();
   delay(2000);
   if (mySerial.available()) // Check if there is Incoming Data in the Serial Buffer.
  {
     display.clearDisplay();
    display.setCursor(0, 0); //oled display
 
    while (mySerial.available()) // Keep reading Byte by Byte from the Buffer till the Buffer is empty
    {
      int input = mySerial.read(); // Read 1 Byte of data and store it in a character variable
      Serial.print(input); // Print the Byte
 
  shuru[j][i]=input;
 
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.print(input);
      display.display();
      delay(5);
      i++;
   

    }
  display.setTextSize(2);
  display.setCursor(4,0);
  display.println("确定请按4");
  display.setCursor(6,0);
  display.println("错误请按5");
  display.display();
  }
  j++;
}


if(key==2){
   display.clearDisplay();

     display.setTextSize(4);
   display.setCursor(8,16);
  display.println("请扫描条形码");
  display.display();
  delay(2000);
   if (mySerial.available()) // Check if there is Incoming Data in the Serial Buffer.
  {
     display.clearDisplay();
    display.setCursor(0, 0); //oled display
 
    while (mySerial.available()) // Keep reading Byte by Byte from the Buffer till the Buffer is empty
    {
      int input = mySerial.read(); // Read 1 Byte of data and store it in a character variable
      Serial.print(input); // Print the Byte
 
  shuru[j][i]=input;
 
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.print(input);
      display.display();
      delay(5);
      i++;
    }
  }
}
 if(key==3){
  //发送信号给机器人
  }
 if(key==4){
  //打开陀机
  oledinit();
  } 
  if(key==5){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("请重新扫描条形码");
  j--;
  display.display();
  delay(2000);
   if (mySerial.available()) // Check if there is Incoming Data in the Serial Buffer.
  {
     display.clearDisplay();
    display.setCursor(0, 0); //oled display
 
    while (mySerial.available()) // Keep reading Byte by Byte from the Buffer till the Buffer is empty
    {
      int input = mySerial.read(); // Read 1 Byte of data and store it in a character variable
      Serial.print(input); // Print the Byte
 
  shuru[j][i]=input;
 
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.print(input);
      display.display();
      delay(5);
      i++;
   

    }
  display.setTextSize(2);
  display.setCursor(4,0);
  display.println("确定请按4");
  display.setCursor(6,0);
  display.println("错误请按5");
  display.display();
  }
  j++;        
  }
}
void oledinit()
{
 display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("存储请按1");
  display.setTextSize(1);
   display.setCursor(1,0);
  display.println("取出请按2");
   display.setTextSize(1);
   display.setCursor(1,0);
  display.println("结束请按3");
  display.display();
  delay(2000);
}
