/*
This firmware was developed by @LifeHackerMax for LHM_Morph_32 Keyboard.
*/

#include <Keypad.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("LHM Morph Keydoard", "LifeHackerMax", 100);

int LAYER (0);

const unsigned long
    FIRST_PRESS_DELAY(300),    
    REPEAT_FIRST(40),              // ms required before repeating on long press
    REPEAT_INCR(80);             // repeat interval for long press

    
const byte ROWS = 4; //four rows
const byte COLS = 8; //eight columns
const byte RPT = 33;
char keys[ROWS][COLS] = {
{'7','f','e','g','6','j','d','v'},
{'i','h','a','c','5','b','1','3'},
{'u','r','t','n','9','p','0','y'},
{'w','o','8','m','4','2','s','l'}
};
byte rowPins[ROWS] = {32, 33, 14, 4}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {5, 18, 19, 21, 27, 26, 22, 23}; //connect to the column pinouts of the kpd
long rptx[RPT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33};
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long 
but1Time, but2Time, but3Time, but4Time, but5Time, but6Time, but7Time, but8Time, but9Time, but10Time,
but11Time, but12Time, but13Time, but14Time, but15Time, but16Time, but17Time, but18Time, but19Time, but20Time,
but21Time, but22Time, but23Time, but24Time, but25Time, but26Time, but27Time, but28Time, but29Time, but30Time,
but31Time, but32Time;

int 
but1 = 0, but2 = 0, but3 = 0, but4 = 0, but5 = 0, but6 = 0, but7 = 0, but8 = 0, but9 = 0, but10 = 0,
but11 = 0, but12 = 0, but13 = 0, but14 = 0, but15 = 0, but16 = 0, but17 = 0, but18 = 0, but19 = 0, but20 = 0,
but21 = 0, but22 = 0, but23 = 0, but24 = 0, but25 = 0, but26 = 0, but27 = 0, but28 = 0, but29 = 0, but30 = 0,
but31 = 0, but32 = 0;

  static const unsigned long REFRESH_INTERVAL = 9000; // ms
  static unsigned long lastRefreshTime = 0;

  static const unsigned long SLEEP_REFRESH_INTERVAL = 900000; // ms
  static unsigned long lastSleepRefreshTime = 0;
  
void callback(){
}  

void setup() {
    Serial.begin(115200);
    
    kpd.setHoldTime(REPEAT_FIRST);
    kpd.setDebounceTime(6);
    
    Serial.println("Starting BLE work!");
    bleKeyboard.begin();
    
    touchAttachInterrupt(T7, callback, CHANGE);
    esp_sleep_enable_touchpad_wakeup();
}

void loop() {  
                     
     static int lastLayer(0);     
     static int state(0);
     static int interLayer(0);

 int batValue = analogRead(35);
 batValue = map(batValue, 1850, 2450, 0, 100);
   


  if(millis() - lastRefreshTime >= REFRESH_INTERVAL)
  {
    lastRefreshTime += REFRESH_INTERVAL;
     bleKeyboard.setBatteryLevel(batValue);
  }       

    if(millis() - lastSleepRefreshTime >= SLEEP_REFRESH_INTERVAL)
  {
    lastSleepRefreshTime += SLEEP_REFRESH_INTERVAL;

    esp_deep_sleep_start();
  }    
  
if (but1 == 0) rptx[1]= REPEAT_FIRST;
if (but2 == 0) rptx[2]= REPEAT_FIRST;
if (but3 == 0) rptx[3]= REPEAT_FIRST;
if (but4 == 0) rptx[4]= REPEAT_FIRST;
if (but5 == 0) rptx[5]= REPEAT_FIRST;
if (but6 == 0) rptx[6]= REPEAT_FIRST;
if (but7 == 0) rptx[7]= REPEAT_FIRST;
if (but8 == 0) rptx[8]= REPEAT_FIRST;
if (but9 == 0) rptx[9]= REPEAT_FIRST;
if (but10 == 0) rptx[10]= REPEAT_FIRST;
if (but11 == 0) rptx[11]= REPEAT_FIRST;
if (but12 == 0) rptx[12]= REPEAT_FIRST;
if (but13 == 0) rptx[13]= REPEAT_FIRST;
if (but14 == 0) rptx[14]= REPEAT_FIRST;
if (but15 == 0) rptx[15]= REPEAT_FIRST;
if (but16 == 0) rptx[16]= REPEAT_FIRST;
if (but17 == 0) rptx[17]= REPEAT_FIRST;
if (but18 == 0) rptx[18]= REPEAT_FIRST;
if (but19 == 0) rptx[19]= REPEAT_FIRST;
if (but20 == 0) rptx[20]= REPEAT_FIRST;
if (but21 == 0) rptx[21]= REPEAT_FIRST;
if (but22 == 0) rptx[22]= REPEAT_FIRST;
if (but23 == 0) rptx[23]= REPEAT_FIRST;
if (but24 == 0) rptx[24]= REPEAT_FIRST;
if (but25 == 0) rptx[25]= REPEAT_FIRST;
if (but26 == 0) rptx[26]= REPEAT_FIRST;
if (but27 == 0) rptx[27]= REPEAT_FIRST;
if (but28 == 0) rptx[28]= REPEAT_FIRST;
if (but29 == 0) {
  if (but30 == 0) {
    if (lastLayer != interLayer){
    lastLayer = interLayer;
    } 
  }
  LAYER = lastLayer;
  rptx[29]= REPEAT_FIRST;
}

if (but30 == 0) {
  if (but29 == 0) {
    if (lastLayer != interLayer){
    lastLayer = interLayer;
    } 
  }
  LAYER = lastLayer;
  rptx[30]= REPEAT_FIRST;
}

if (but31 == 0) rptx[31]= REPEAT_FIRST;
if (but32 == 0) rptx[32]= REPEAT_FIRST;

    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
              lastSleepRefreshTime = millis();
             // lastSleepRefreshTime += SLEEP_REFRESH_INTERVAL;
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    state = 1;
                break;
                    case HOLD:
                    state = 1;
                break;
                    case RELEASED:
                    state = 0;
                break;
                    case IDLE:
                    state = 0;
                }             
                if ((kpd.key[i].kchar == '1') && (state == 0)) but1 = 0;                
                if ((kpd.key[i].kchar == '1') && (state == 1)) {
                  but1Time = millis();
                  but1 = 1;       
                }
                if ((kpd.key[i].kchar == 'a') && (state == 0)) but2 = 0;                
                if ((kpd.key[i].kchar == 'a') && (state == 1)) {
                  but2Time = millis();
                  but2 = 1;       
                }
                if ((kpd.key[i].kchar == 'd') && (state == 0)) but3 = 0;                
                if ((kpd.key[i].kchar == 'd') && (state == 1)) {
                  but3Time = millis();
                  but3 = 1;       
                }
                if ((kpd.key[i].kchar == 'e') && (state == 0)) but4 = 0;                
                if ((kpd.key[i].kchar == 'e') && (state == 1)) {
                  but4Time = millis();
                  but4 = 1;       
                }
               if ((kpd.key[i].kchar == 'h') && (state == 0)) but5 = 0;                
                if ((kpd.key[i].kchar == 'h') && (state == 1)) {
                  but5Time = millis();
                  but5 = 1;       
                }            
                if ((kpd.key[i].kchar == '3') && (kpd.key[i].kstate == RELEASED)) but6 = 3;  
                if ((kpd.key[i].kchar == '3') && (kpd.key[i].kstate == IDLE)) but6 = 0;              
                if ((kpd.key[i].kchar == '3') && (state == 1)) {
                  but6Time = millis();
                  but6 = 1;       
                }      
                if ((kpd.key[i].kchar == 'c') && (state == 0)) but7 = 0;                
                if ((kpd.key[i].kchar == 'c') && (state == 1)) {
                  but7Time = millis();
                  but7 = 1;       
                }      
                if ((kpd.key[i].kchar == 'v') && (state == 0)) but8 = 0;                
                if ((kpd.key[i].kchar == 'v') && (state == 1)) {
                  but8Time = millis();
                  but8 = 1;       
                }      
                if ((kpd.key[i].kchar == 'g') && (state == 0)) but9 = 0;                
                if ((kpd.key[i].kchar == 'g') && (state == 1)) {
                  but9Time = millis();
                  but9 = 1;       
                }
                if ((kpd.key[i].kchar == 'i') && (state == 0)) but10 = 0;                
                if ((kpd.key[i].kchar == 'i') && (state == 1)) {
                  but10Time = millis();
                  but10 = 1;       
                }  
                
                if ((kpd.key[i].kchar == 'l') && (state == 0)) but11 = 0;                
                if ((kpd.key[i].kchar == 'l') && (state == 1)) {
                  but11Time = millis();
                  but11 = 1;       
                } 
                if ((kpd.key[i].kchar == 'n') && (state == 0)) but12 = 0;                
                if ((kpd.key[i].kchar == 'n') && (state == 1)) {
                  but12Time = millis();
                  but12 = 1;       
                } 
                if ((kpd.key[i].kchar == 'r') && (state == 0)) but13 = 0;                
                if ((kpd.key[i].kchar == 'r') && (state == 1)) {
                  but13Time = millis();
                  but13 = 1;       
                } 
                if ((kpd.key[i].kchar == 'o') && (state == 0)) but14 = 0;                
                if ((kpd.key[i].kchar == 'o') && (state == 1)) {
                  but14Time = millis();
                  but14 = 1;       
                } 
                if ((kpd.key[i].kchar == '2') && (state == 0)) but15 = 0;                
                if ((kpd.key[i].kchar == '2') && (state == 1)) {
                  but15Time = millis();
                  but15 = 1;       
                } 

                if ((kpd.key[i].kchar == 's') && (state == 0)) but16 = 0;                
                if ((kpd.key[i].kchar == 's') && (state == 1)) {
                  but16Time = millis();
                  but16 = 1;       
                } 
                if ((kpd.key[i].kchar == 't') && (state == 0)) but17 = 0;                
                if ((kpd.key[i].kchar == 't') && (state == 1)) {
                  but17Time = millis();
                  but17 = 1;       
                } 
                if ((kpd.key[i].kchar == 'u') && (state == 0)) but18 = 0;                
                if ((kpd.key[i].kchar == 'u') && (state == 1)) {
                  but18Time = millis();
                  but18 = 1;       
                } 
                if ((kpd.key[i].kchar == 'w') && (state == 0)) but19 = 0;                
                if ((kpd.key[i].kchar == 'w') && (state == 1)) {
                  but19Time = millis();
                  but19 = 1;       
                } 
                if ((kpd.key[i].kchar == '4') && (state == 0)) but20 = 0;                
                if ((kpd.key[i].kchar == '4') && (state == 1)) {
                  but20Time = millis();
                  but20 = 1;       
                } 
                if ((kpd.key[i].kchar == 'b') && (kpd.key[i].kstate == RELEASED)) but21 = 3;  
                if ((kpd.key[i].kchar == 'b') && (kpd.key[i].kstate == IDLE)) but21 = 0;              
                if ((kpd.key[i].kchar == 'b') && (state == 1)) {
                  but21Time = millis();
                  but21 = 1;       
                }    
                if ((kpd.key[i].kchar == 'j') && (kpd.key[i].kstate == RELEASED)) but22 = 3;  
                if ((kpd.key[i].kchar == 'j') && (kpd.key[i].kstate == IDLE)) but22 = 0;              
                if ((kpd.key[i].kchar == 'j') && (state == 1)) {
                  but22Time = millis();
                  but22 = 1;       
                }    

                if ((kpd.key[i].kchar == 'f') && (kpd.key[i].kstate == RELEASED)) but23 = 3;  
                if ((kpd.key[i].kchar == 'f') && (kpd.key[i].kstate == IDLE)) but23 = 0;              
                if ((kpd.key[i].kchar == 'f') && (state == 1)) {
                  but23Time = millis();
                  but23 = 1;       
                }    

                if ((kpd.key[i].kchar == 'm') && (kpd.key[i].kstate == RELEASED)) but24 = 3;  
                if ((kpd.key[i].kchar == 'm') && (kpd.key[i].kstate == IDLE)) but24 = 0;              
                if ((kpd.key[i].kchar == 'm') && (state == 1)) {
                  but24Time = millis();
                  but24 = 1;       
                }    

                if ((kpd.key[i].kchar == 'p') && (kpd.key[i].kstate == RELEASED)) but25 = 3;  
                if ((kpd.key[i].kchar == 'p') && (kpd.key[i].kstate == IDLE)) but25 = 0;              
                if ((kpd.key[i].kchar == 'p') && (state == 1)) {
                  but25Time = millis();
                  but25 = 1;       
                }    

                if ((kpd.key[i].kchar == 'y') && (kpd.key[i].kstate == RELEASED)) but26 = 3;  
                if ((kpd.key[i].kchar == 'y') && (kpd.key[i].kstate == IDLE)) but26 = 0;              
                if ((kpd.key[i].kchar == 'y') && (state == 1)) {
                  but26Time = millis();
                  but26 = 1;       
                }    
                
                if ((kpd.key[i].kchar == '5') && (kpd.key[i].kstate == RELEASED)) but27 = 3;  
                if ((kpd.key[i].kchar == '5') && (kpd.key[i].kstate == IDLE)) but27 = 0;              
                if ((kpd.key[i].kchar == '5') && (state == 1)) {
                  but27Time = millis();
                  but27 = 1;       
                } 
                if ((kpd.key[i].kchar == '6') && (kpd.key[i].kstate == RELEASED)) but28 = 3;  
                if ((kpd.key[i].kchar == '6') && (kpd.key[i].kstate == IDLE)) but28 = 0;              
                if ((kpd.key[i].kchar == '6') && (state == 1)) {
                  but28Time = millis();
                  but28 = 1;       
                } 
                                                
                if ((kpd.key[i].kchar == '7') && (state == 0)) but29 = 0;                
                if ((kpd.key[i].kchar == '7') && (state == 1)) {
                  but29Time = millis();
                  but29 = 1;       
                }           
                if ((kpd.key[i].kchar == '8') && (state == 0)) but30 = 0;                
                if ((kpd.key[i].kchar == '8') && (state == 1)) {
                  but30Time = millis();
                  but30 = 1;       
                }    
                if ((kpd.key[i].kchar == '9') && (kpd.key[i].kstate == RELEASED)) but31 = 3;  
                if ((kpd.key[i].kchar == '9') && (kpd.key[i].kstate == IDLE)) but31 = 0;              
                if ((kpd.key[i].kchar == '9') && (state == 1)) {
                  but31Time = millis();
                  but31 = 1;       
                } 
                if ((kpd.key[i].kchar == '0') && (kpd.key[i].kstate == RELEASED)) but32 = 3;  
                if ((kpd.key[i].kchar == '0') && (kpd.key[i].kstate == IDLE)) but32 = 0;              
                if ((kpd.key[i].kchar == '0') && (state == 1)) {
                  but32Time = millis();
                  but32 = 1;       
                }  
                           
                Serial.print("Key ");
              //  Serial.print(but6);
                Serial.println(kpd.key[i].kchar);                                                                                                                  
            }
        }
    }
  
if(bleKeyboard.isConnected()) {

// Changing Layers ------------------------------------------------------------------
  
    if (lastLayer == 0){
           
        if((but29 == 1) &&  (but30 == 0)){  
          LAYER = 1;
        }
        if((but30 == 1) &&  (but29 == 0)){  
          LAYER = 2;
        } 
        if((but30 == 1) &&  (but29 == 1)){  
          LAYER = 3;
       }
    }
      if (lastLayer == 1){
        
        if((but29 == 1) &&  (but30 == 0)){  
          LAYER = 0;
        }
        if((but30 == 1) &&  (but29 == 0)){  
          LAYER = 2;
        }
        if((but30 == 1) &&  (but29 == 1)){  
          LAYER = 3;
       }
    }

    if (lastLayer == 2){
      
        if((but29 == 1) &&  (but30 == 0)){  
          LAYER = 0;
        }
        if((but30 == 1) &&  (but29 == 0)){  
          LAYER = 1;
        }
        if((but30 == 1) &&  (but29 == 1)){  
          LAYER = 3;
       }
    }
    
     if (lastLayer == 3){
    
        if((but29 == 1) &&  (but30 == 0)){  
          LAYER = 0;
        }
        if((but30 == 1) &&  (but29 == 0)){  
          LAYER = 1;
        }
        if((but30 == 1) &&  (but29 == 1)){  
          LAYER = 2;
       }
    }
    if ((but1 == 1) && (but6 == 1)) {                  
    if((but29 == 1) || (but30 == 1) || (but29 == 1) &&  (but30 == 1)){  
       interLayer = LAYER;
    }   
   }
   
// button1 ----------------------------------------------------------------                     

if ((but1 == 1) && (millis()- but1Time > rptx[1])) {          
          if (rptx[1] != REPEAT_FIRST) { 
             rptx[1] += REPEAT_INCR;    
         }
          else{
          rptx[1] += FIRST_PRESS_DELAY;
         }      
          bleKeyboard.write(KEY_ESC);
           }
           
// button2 ---------------------------------------------------------------- 
          
if ((but2 == 1) && (millis()- but2Time > rptx[2])) {          
          if (rptx[2] != REPEAT_FIRST) { 
             rptx[2] += REPEAT_INCR;    
         }
          else{
          rptx[2] += FIRST_PRESS_DELAY;
         }  
         if(but7 == 0) {
          if (LAYER == 0) bleKeyboard.print("a");
          if (LAYER == 1) bleKeyboard.print("1");
          if (LAYER == 2) bleKeyboard.write(KEY_TAB);
          if (LAYER == 3) bleKeyboard.write(KEY_F1);
        }
        if(but7 == 1) {
          if (LAYER == 0) bleKeyboard.print("b");
          if (LAYER == 1) bleKeyboard.print("!");    
           }
        }
        
// Button 3 ----------------------------------------------------------------
           
if ((but3 == 1) && (millis()- but3Time > rptx[3])) {          
          if (rptx[3] != REPEAT_FIRST) { 
             rptx[3] += REPEAT_INCR;    
         }
          else{
          rptx[3] += FIRST_PRESS_DELAY;
         }      
          if(but8 == 0) {
          if (LAYER == 0) bleKeyboard.print("d");
          if (LAYER == 1) bleKeyboard.print("2");
          if (LAYER == 2) bleKeyboard.write(KEY_MEDIA_LOCAL_MACHINE_BROWSER);
          if (LAYER == 3) bleKeyboard.write(KEY_F2);
        }
        if(but8 == 1) {
          if (LAYER == 0) bleKeyboard.print("j");
          if (LAYER == 1) bleKeyboard.print("@");
          if (LAYER == 2) bleKeyboard.print("<");
//          if (LAYER == 3) bleKeyboard.write(KEY_F2);
        }
      }    

// Button 4 ----------------------------------------------------------------
         
if ((but4 == 1) && (millis()- but4Time > rptx[4])) {          
          if (rptx[4] != REPEAT_FIRST) { 
             rptx[4] += REPEAT_INCR;    
         }
          else{
          rptx[4] += FIRST_PRESS_DELAY;
         }      
        if(but9 == 0) {
          if (LAYER == 0) bleKeyboard.print("e");
          if (LAYER == 1) bleKeyboard.print("3");
          if (LAYER == 2) bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
          if (LAYER == 3) bleKeyboard.write(KEY_F3);
        }
        if(but9 == 1) {
          if (LAYER == 0) bleKeyboard.print("f");
          if (LAYER == 1) bleKeyboard.print("#");
          if (LAYER == 2) bleKeyboard.write(KEY_MEDIA_MUTE);
//          if (LAYER == 3) bleKeyboard.write(KEY_F3);
        }
           }      

// Button 5 ----------------------------------------------------------------
            
if ((but5 == 1) && (millis()- but5Time > rptx[5])) {          
          if (rptx[5] != REPEAT_FIRST) { 
             rptx[5] += REPEAT_INCR;    
         }
          else{
          rptx[5] += FIRST_PRESS_DELAY;
         }      
         
        if((but11 == 0) && (but10 == 0)) {
          if (LAYER == 0) bleKeyboard.print("h");
          if (LAYER == 1) bleKeyboard.print("4");
          if (LAYER == 2) bleKeyboard.write(KEY_PAGE_UP);
          if (LAYER == 3) bleKeyboard.write(KEY_F4);
        }
        if((but11 == 1) && (but10 == 0)) {
          if (LAYER == 0) bleKeyboard.print("q");
          if (LAYER == 1) bleKeyboard.print("(");
//          if (LAYER == 2) bleKeyboard.write(KEY_PAGE_UP);
//          if (LAYER == 3) bleKeyboard.write(KEY_F4);
        }
          if((but11 == 0) && (but10 == 1)) {
          if (LAYER == 0) bleKeyboard.print("z");
          if (LAYER == 1) bleKeyboard.print("$");
          if (LAYER == 2) bleKeyboard.write(KEY_PAGE_DOWN);
//          if (LAYER == 3) bleKeyboard.write(KEY_F4);
        }
           }
           
// Button 6 ---------------------------------------------------------------- 
              
if ((but6 == 1) && (millis()- but6Time > rptx[6])) {          
          if (rptx[6] != REPEAT_FIRST) { 
             rptx[6] += REPEAT_INCR;    
         }
          else{
          rptx[6] += FIRST_PRESS_DELAY;
         }      
          bleKeyboard.press(KEY_LEFT_CTRL);
           } 
           
if (but6 == 3) bleKeyboard.release(KEY_LEFT_CTRL);
           
// Button 7 ----------------------------------------------------------------                     

if ((but7 == 1) && (millis()- but7Time > rptx[7])) {          
          if (rptx[7] != REPEAT_FIRST) { 
             rptx[7] += REPEAT_INCR;    
         }
          else{
          rptx[7] += FIRST_PRESS_DELAY;
         }      
        if((but2 == 0)) {
          if (LAYER == 0) bleKeyboard.print("c");
          if (LAYER == 1) bleKeyboard.print("/");
          if (LAYER == 2) bleKeyboard.write(KEY_CAPS_LOCK);
          if (LAYER == 3) bleKeyboard.print(",");
        }
}

// Button 8 ----------------------------------------------------------------
           
if ((but8 == 1) && (millis()- but8Time > rptx[8])) {          
          if (rptx[8] != REPEAT_FIRST) { 
             rptx[8] += REPEAT_INCR;    
         }
          else{
          rptx[8] += FIRST_PRESS_DELAY;
         }      
          if((but3 == 0)) {
          if (LAYER == 0) bleKeyboard.print("v");
          if (LAYER == 1) bleKeyboard.print("[");
          if (LAYER == 2) bleKeyboard.write(KEY_LEFT_GUI);
          if (LAYER == 3) bleKeyboard.print(".");
        }   
}      

// Button 9 ----------------------------------------------------------------
                
if ((but9 == 1) && (millis()- but9Time > rptx[9])) {          
          if (rptx[9] != REPEAT_FIRST) { 
             rptx[9] += REPEAT_INCR;    
         }
          else{
          rptx[9] += FIRST_PRESS_DELAY;
         }      
         if((but4 == 0)) {
          if (LAYER == 0) bleKeyboard.print("g");
          if (LAYER == 1) bleKeyboard.print("]");
          if (LAYER == 2) bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
          if (LAYER == 3) bleKeyboard.print(";");
        } 
}

// Button 10 ----------------------------------------------------------------
                          
if ((but10 == 1) && (millis()- but10Time > rptx[10])) {          
          if (rptx[10] != REPEAT_FIRST) { 
             rptx[10] += REPEAT_INCR;    
         }
          else{
          rptx[10] += FIRST_PRESS_DELAY;
         }      
         if((but5 == 0) && (but16 == 0)) {
          if (LAYER == 0) bleKeyboard.print("i");
          if (LAYER == 1) bleKeyboard.print("\\");
          if (LAYER == 2) bleKeyboard.write(KEY_PAGE_DOWN);
          if (LAYER == 3) bleKeyboard.print("'");
         } 
                  
          if((but5 == 0) && (but16 == 1)) {
          if (LAYER == 0) bleKeyboard.print("x");
          if (LAYER == 1) bleKeyboard.print(")");
//          if (LAYER == 2) bleKeyboard.write(KEY_PAGE_DOWN);
//          if (LAYER == 3) bleKeyboard.print("'");
         }  
}           
// Button 11 ----------------------------------------------------------------  

if ((but11 == 1) && (millis()- but11Time > rptx[11])) {          
          if (rptx[11] != REPEAT_FIRST) { 
             rptx[11] += REPEAT_INCR;    
         }
          else{
          rptx[11] += FIRST_PRESS_DELAY;
         }
        if((but16 == 0) && (but5 == 0)) {
          if (LAYER == 0) bleKeyboard.print("l");
          if (LAYER == 1) bleKeyboard.print("5");
          if (LAYER == 2) bleKeyboard.write(KEY_HOME);
          if (LAYER == 3) bleKeyboard.write(KEY_F5);
        }
        if((but16 == 1) && (but5 == 0)) {
          if (LAYER == 0) bleKeyboard.print("k");
          if (LAYER == 1) bleKeyboard.print("%");
//          if (LAYER == 2) bleKeyboard.write(KEY_HOME);
//          if (LAYER == 3) bleKeyboard.write(KEY_F5);
        }
    }

// Button 12 ---------------------------------------------------------------- 

if ((but12 == 1) && (millis()- but12Time > rptx[12])) {          
          if (rptx[12] != REPEAT_FIRST) { 
             rptx[12] += REPEAT_INCR;    
         }
          else{
          rptx[12] += FIRST_PRESS_DELAY;
         }
         if((but17 == 0)) {
          if (LAYER == 0) bleKeyboard.print("n");
          if (LAYER == 1) bleKeyboard.print("6");
          if (LAYER == 2) bleKeyboard.write(KEY_UP_ARROW);
          if (LAYER == 3) bleKeyboard.write(KEY_F6);
        }
        if((but17 == 1)) {
          if (LAYER == 0) bleKeyboard.print("m");
          if (LAYER == 1) bleKeyboard.print("^");
//          if (LAYER == 2) bleKeyboard.write(KEY_UP_ARROW);
//          if (LAYER == 3) bleKeyboard.write(KEY_F6);
        }
  
    }

// Button 13 ----------------------------------------------------------------   

if ((but13 == 1) && (millis()- but13Time > rptx[13])) {          
          if (rptx[13] != REPEAT_FIRST) { 
             rptx[13] += REPEAT_INCR;    
         }
          else{
          rptx[13] += FIRST_PRESS_DELAY;
         }
        if((but18 == 0)) {
          if (LAYER == 0) bleKeyboard.print("r");
          if (LAYER == 1) bleKeyboard.print("7");
          if (LAYER == 2) bleKeyboard.write(KEY_END);
          if (LAYER == 3) bleKeyboard.write(KEY_F7);
        }   
        if((but18 == 1)) {
          if (LAYER == 0) bleKeyboard.print("p");
          if (LAYER == 1) bleKeyboard.print("&");
//          if (LAYER == 2) bleKeyboard.write(KEY_END);
//          if (LAYER == 3) bleKeyboard.write(KEY_F7);
        }   

     }

// Button 14 ----------------------------------------------------------------

if ((but14 == 1) && (millis()- but14Time > rptx[14])) {          
          if (rptx[14] != REPEAT_FIRST) { 
             rptx[14] += REPEAT_INCR;    
         }
          else{
          rptx[14] += FIRST_PRESS_DELAY;
         }
          if((but19 == 0)) {
          if (LAYER == 0) bleKeyboard.print("o");
          if (LAYER == 1) bleKeyboard.print("8");
          if (LAYER == 2) bleKeyboard.write(KEY_DELETE);
          if (LAYER == 3) bleKeyboard.write(KEY_F8);
        }   
        if((but19 == 1)) {
          if (LAYER == 0) bleKeyboard.print("y");
          if (LAYER == 1) bleKeyboard.print("*");
//          if (LAYER == 2) bleKeyboard.write(KEY_DELETE);
//          if (LAYER == 3) bleKeyboard.write(KEY_F8);
        }   
    }

// Button 15 ----------------------------------------------------------------

if ((but15 == 1) && (millis()- but15Time > rptx[15])) {          
          if (rptx[15] != REPEAT_FIRST) { 
             rptx[15] += REPEAT_INCR;    
         }
          else{
          rptx[15] += FIRST_PRESS_DELAY;
         }
       bleKeyboard.write(KEY_BACKSPACE);
   }

// Button 16 ----------------------------------------------------------------

if ((but16 == 1) && (millis()- but16Time > rptx[16])) {          
          if (rptx[16] != REPEAT_FIRST) { 
             rptx[16] += REPEAT_INCR;    
         }
          else{
          rptx[16] += FIRST_PRESS_DELAY;
         }
         if((but10 == 0) && (but11 == 0)){
          if (LAYER == 0) bleKeyboard.print("s");
          if (LAYER == 1) bleKeyboard.print("=");
          if (LAYER == 2) bleKeyboard.write(KEY_LEFT_ARROW);
          if (LAYER == 3) bleKeyboard.write(KEY_F12);
        } 
   }

// Button 17 ----------------------------------------------------------------

if ((but17 == 1) && (millis()- but17Time > rptx[17])) {          
          if (rptx[17] != REPEAT_FIRST) { 
             rptx[17] += REPEAT_INCR;    
         }
          else{
          rptx[17] += FIRST_PRESS_DELAY;
         }
        if((but12 == 0)) {
          if (LAYER == 0) bleKeyboard.print("t");
          if (LAYER == 1) bleKeyboard.print("-");
          if (LAYER == 2) bleKeyboard.write(KEY_DOWN_ARROW);
          if (LAYER == 3) bleKeyboard.write(KEY_F11);
        }  
   }  
// Button 18 ----------------------------------------------------------------

if ((but18 == 1) && (millis()- but18Time > rptx[18])) {          
          if (rptx[18] != REPEAT_FIRST) { 
             rptx[18] += REPEAT_INCR;    
         }
          else{
          rptx[18] += FIRST_PRESS_DELAY;
         }
        if((but13 == 0)) {
          if (LAYER == 0) bleKeyboard.print("u");
          if (LAYER == 1) bleKeyboard.print("0");
          if (LAYER == 2) bleKeyboard.write(KEY_RIGHT_ARROW);
          if (LAYER == 3) bleKeyboard.write(KEY_F10);
        } 
   }

// Button 19 ----------------------------------------------------------------

if ((but19 == 1) && (millis()- but19Time > rptx[19])) {          
          if (rptx[19] != REPEAT_FIRST) { 
             rptx[19] += REPEAT_INCR;    
         }
          else{
          rptx[19] += FIRST_PRESS_DELAY;
         }
        if((but14 == 0)) {
          if (LAYER == 0) bleKeyboard.print("w");
          if (LAYER == 1) bleKeyboard.print("9");
          if (LAYER == 2) bleKeyboard.write(KEY_INSERT);
          if (LAYER == 3) bleKeyboard.write(KEY_F9);
        }
   }

// Button 20 ----------------------------------------------------------------

if ((but20 == 1) && (millis()- but20Time > rptx[20])) {          
          if (rptx[20] != REPEAT_FIRST) { 
             rptx[20] += REPEAT_INCR;    
         }
          else{
          rptx[20] += FIRST_PRESS_DELAY;
         }
       bleKeyboard.write(KEY_RETURN);
   }


// Button 21 ----------------------------------------------------------------

if ((but21 == 1) && (millis()- but21Time > rptx[21])) {          
          if (rptx[21] != REPEAT_FIRST) { 
             rptx[21] += REPEAT_INCR;    
         }
          else{
          rptx[21] += FIRST_PRESS_DELAY;
         } 
          if (LAYER == 0) bleKeyboard.print(",");
          if (LAYER == 1) bleKeyboard.print(",");
          if (LAYER == 2) bleKeyboard.print(",");
          if (LAYER == 3) bleKeyboard.print(",");
         } 
//if (but21 == 3) bleKeyboard.release(KEY_LEFT_CTRL); 


// Button 22 ----------------------------------------------------------------

if ((but22 == 1) && (millis()- but22Time > rptx[22])) {          
          if (rptx[22] != REPEAT_FIRST) { 
             rptx[22] += REPEAT_INCR;    
         }
          else{
          rptx[22] += FIRST_PRESS_DELAY;
         } 
          if (LAYER == 0) bleKeyboard.print(".");
          if (LAYER == 1) bleKeyboard.print(".");
          if (LAYER == 2) bleKeyboard.print(".");
          if (LAYER == 3) bleKeyboard.print(".");
        } 
//if (but22 == 3) bleKeyboard.release(KEY_LEFT_CTRL); 



// Button 23 ----------------------------------------------------------------

if ((but23 == 1) && (millis()- but23Time > rptx[23])) {          
          if (rptx[23] != REPEAT_FIRST) { 
             rptx[23] += REPEAT_INCR;    
         }
          else{
          rptx[23] += FIRST_PRESS_DELAY;
         } 
          if (LAYER == 0) bleKeyboard.write(KEY_DELETE); //bleKeyboard.print(";");
          if (LAYER == 1) bleKeyboard.print(";");
          if (LAYER == 2) bleKeyboard.print(";");
          if (LAYER == 3) bleKeyboard.print(";");
         } 
//if (but23 == 3) bleKeyboard.release(KEY_LEFT_CTRL); 



// Button 24  ----------------------------------------------------------------

if ((but24 == 1) && (millis()- but24Time > rptx[24])) {          
          if (rptx[24] != REPEAT_FIRST) { 
             rptx[24] += REPEAT_INCR;    
         }
          else{
          rptx[24] += FIRST_PRESS_DELAY;
         } 
          if (LAYER == 0) bleKeyboard.print("/");
          if (LAYER == 1) bleKeyboard.print("/");
          if (LAYER == 2) bleKeyboard.print("/");
          if (LAYER == 3) bleKeyboard.print("/");
         } 
//if (but24 == 3) bleKeyboard.release(KEY_LEFT_CTRL); 



// Button 25 ----------------------------------------------------------------

if ((but25 == 1) && (millis()- but25Time > rptx[25])) {          
          if (rptx[25] != REPEAT_FIRST) { 
             rptx[25] += REPEAT_INCR;    
         }
          else{
          rptx[25] += FIRST_PRESS_DELAY;
         } 
          if (LAYER == 0) bleKeyboard.print("-");
          if (LAYER == 1) bleKeyboard.print("-");
          if (LAYER == 2) bleKeyboard.print("-");
          if (LAYER == 3) bleKeyboard.print("-");
           } 
//if (but25 == 3) bleKeyboard.release(KEY_LEFT_CTRL); 



// Button 26 ----------------------------------------------------------------

if ((but26 == 1) && (millis()- but26Time > rptx[26])) {          
          if (rptx[26] != REPEAT_FIRST) { 
             rptx[26] += REPEAT_INCR;    
         }
          else{
          rptx[26] += FIRST_PRESS_DELAY;
         } 
          if (LAYER == 0) bleKeyboard.print("=");
          if (LAYER == 1) bleKeyboard.print("=");
          if (LAYER == 2) bleKeyboard.print("=");
          if (LAYER == 3) bleKeyboard.print("=");
           } 
//if (but26 == 3) bleKeyboard.release(KEY_LEFT_CTRL); 


   
// Button 27 ----------------------------------------------------------------

if ((but27 == 1) && (millis()- but27Time > rptx[27])) {          
          if (rptx[27] != REPEAT_FIRST) { 
             rptx[27] += REPEAT_INCR;    
         }
          else{
          rptx[27] += FIRST_PRESS_DELAY;
         } 
          bleKeyboard.press(KEY_LEFT_SHIFT);
           } 
if (but27 == 3) bleKeyboard.release(KEY_LEFT_SHIFT); 

   
// Button 28 ----------------------------------------------------------------

if ((but28 == 1) && (millis()- but28Time > rptx[28])) {          
          if (rptx[28] != REPEAT_FIRST) { 
             rptx[28] += REPEAT_INCR;    
         }
          else{
          rptx[28] += FIRST_PRESS_DELAY;
         } 
          bleKeyboard.press(KEY_LEFT_ALT);
           } 
if (but28 == 3) bleKeyboard.release(KEY_LEFT_ALT); 



// Button 29 FN1 KEY -------------------------------------------------------



// Button 30 FN2 KEY -------------------------------------------------------


   
// Button 31 ----------------------------------------------------------------

if ((but31 == 1) && (millis()- but31Time > rptx[31])) {          
          if (rptx[31] != REPEAT_FIRST) { 
             rptx[31] += REPEAT_INCR;    
         }
          else{
          rptx[31] += FIRST_PRESS_DELAY;
         }
       bleKeyboard.print(' ');
   }    
   
// Button 32 ----------------------------------------------------------------

if ((but32 == 1) && (millis()- but32Time > rptx[32])) {          
          if (rptx[32] != REPEAT_FIRST) { 
             rptx[32] += REPEAT_INCR;    
         }
          else{
          rptx[32] += FIRST_PRESS_DELAY;
         }
          bleKeyboard.press(KEY_RIGHT_SHIFT);
           } 
if (but32 == 3) bleKeyboard.release(KEY_RIGHT_SHIFT); 

        
    }
}  // End loop
