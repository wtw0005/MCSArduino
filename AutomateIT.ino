
#include "Keyboard.h"

#define Debug 1
//GetSchoolVia IP??
#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT  0x81
#define KEY_LEFT_ALT    0x82
#define KEY_RIGHT_CTRL  0x84
#define KEY_RIGHT_SHIFT 0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_UP_ARROW    0xDA
#define KEY_DOWN_ARROW  0xD9
#define KEY_LEFT_ARROW  0xD8
#define KEY_RIGHT_ARROW 0xD7
#define KEY_BACKSPACE   0xB2
#define KEY_TAB         0xB3
#define KEY_ENTER       0xB0
#define KEY_ESC         0xB1
#define KEY_CAPS_LOCK   0xC1
#define KEY_LEFT_GUI    0x83
#define KEY_END         0xD5
#define KEY_DELETE      0xD4 

void repeatKey(byte key, int num)
{
  for(int i=0;i<num;i++)
  {
    Keyboard.write(key);
    delay(100);
  }
}


int installSophos()
{
  
}

int getSchool()  //Not quite working nslookup isnt a great solution. Schools in Priceville area will use BOE DC 
{
  
  Keyboard.write(KEY_LEFT_GUI);
  delay(3000);
  Keyboard.print("cmd");
  delay(2000);
  Keyboard.write(KEY_ENTER);
  delay(1500);
  Keyboard.print("nslookup something > ipprint.txt");
  delay(1500);
  Keyboard.write(KEY_ENTER);
  delay(1500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('c');
  delay(1500);
  Keyboard.release(KEY_LEFT_CTRL);
  Keyboard.print("ipprint.txt");
  delay(300);
  Keyboard.write(KEY_ENTER);
  delay(500);
  repeatKey(KEY_DELETE,9); //Delete whitespace 
  delay(1000);
  repeatKey(KEY_RIGHT_ARROW,4); //Move to end of School name
  delay(2000);
  repeatKey(KEY_DELETE,50); //Delete domain controller suffix
  delay(500);
  repeatKey(KEY_LEFT_ARROW,10);
  Keyboard.press(KEY_LEFT_SHIFT); //highlight line
  Keyboard.write(KEY_END);
  delay(200);
  Keyboard.release(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_CTRL); //copy to clipboard
  Keyboard.write('c');
  Keyboard.release(KEY_LEFT_CTRL);
  delay(500);
  Keyboard.write(KEY_LEFT_GUI);
  delay(1000);
  Keyboard.print("sysdm.cpl");
  delay(1000);
  repeatKey(KEY_LEFT_SHIFT,2);
  Keyboard.write(KEY_ENTER);
  delay(500);
  repeatKey(KEY_LEFT_ARROW,14);
  delay(300);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('v');
  Keyboard.release(KEY_LEFT_CTRL);
  
  
}

int getSerial()
{
  Keyboard.write(KEY_LEFT_GUI);
  delay(3000);
  Keyboard.print("cmd");
  delay(2000);
  Keyboard.write(KEY_ENTER);
  delay(1500);
  Keyboard.print("wmic bios get serialnumber > tag.txt");
  delay(1500);
  Keyboard.write(KEY_ENTER);
  delay(3000);
  Keyboard.print("tag.txt");
  delay(2000);
  Keyboard.write(KEY_ENTER);
  delay(2000);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(200);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(KEY_END);
  delay(200);
  Keyboard.release(KEY_LEFT_SHIFT);
  delay(200);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('c');
  Keyboard.release(KEY_LEFT_CTRL);
  
}

int domainConfig()
{
  Keyboard.write(KEY_LEFT_GUI);
  delay(3000);
  Keyboard.print("sysdm.cpl");
  delay(200);
  Keyboard.write(KEY_ENTER);
  delay(2000);
  repeatKey(KEY_TAB,2);
  Keyboard.write(KEY_ENTER);
  delay(1000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('v');
  Keyboard.release(KEY_LEFT_CTRL); 
  delay(500);
  //getSchool();
  delay(500);
  repeatKey(KEY_TAB,3);
  delay(300);
  Keyboard.print("morgank12.org");
  delay(300);
  

}

void setup() {
  if(Debug) 
    delay(10000);
    
getSerial();
domainConfig();

installSophos();
}
  
  
  
  // put your setup code here, to run once:



void loop() {
  // put your main code here, to run repeatedly:

}
