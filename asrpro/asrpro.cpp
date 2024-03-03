#define N_PIXELS 1
#include "asr.h"
extern "C"{ void * __dso_handle = 0 ;}
#include "setup.h"
#include "newS2812.h"
//by ACG_Create 渺若尘兮

uint32_t snid;
WS2812 ws2812 = WS2812(6,1,255);//初始化（1）个ws2812在PA_6端口
uint8_t rainbows = 1;
uint8_t var;

void rainbow(){
	randomSeed(millis());
	while(rainbows == 1){
	  ws2812.rainbowCycle(10);//修改这个函数调用以修改ID91效果

	}
	ws2812.clear();
	vTaskDelete(NULL);
}

  void welcome(){
  ws2812.pixel_set_all_color(255,0,0);
  ws2812.pixel_show();
  delay(300);
  ws2812.pixel_set_all_color(0,255,0);
  ws2812.pixel_show();
  delay(300);
  ws2812.pixel_set_all_color(0,0,255);
  ws2812.pixel_show();
  delay(300);
  ws2812.pixel_set_all_color(0,0,0);
  ws2812.pixel_show();
    //上电欢迎，RGB闪一次 
  }

void ASR_CODE();

//{speak:小蝶-清新女声,vol:10,speed:10,platform:haohaodada}
//{playid:10001,voice:}
//10001欢迎语音
//{playid:10002,voice:}
//10002退出语音

void ASR_CODE(){
    set_state_enter_wakeup(120000);
    
    
 
    
  //case后面的是语音识别的ID 
  switch (snid) {

    case 0:
        ws2812.pixel_set_all_color(255,255,255);
        ws2812.pixel_show();
        delay(300);
        ws2812.pixel_set_all_color(0,0,0);
        ws2812.pixel_show();
        delay(300);
        ws2812.pixel_set_all_color(255,255,255);
        ws2812.pixel_show();
        delay(300);
        ws2812.pixel_set_all_color(0,0,0);
        ws2812.pixel_show();
    break;



    case 11:
        ws2812.pixel_set_all_color(0,255,255);
        ws2812.pixel_show();
    break;

    case 10:
        rainbows = 0;
        ws2812.pixel_set_all_color(0,0,0);
        ws2812.pixel_show();       
    break;

    case 12:
        ws2812.setBrightness(254);
        ws2812.pixel_show(); 
    break;

    case 13:
        ws2812.setBrightness(100);
        ws2812.pixel_show();         
    break;


    case 14:
        while(1 == 1){
            for (int a=0; a<=255;a++){
                ws2812.setBrightness(a);
                ws2812.pixel_show();
                delay(8);
            }
             for (int a=255; a>=0;a--){
                ws2812.setBrightness(a);
                ws2812.pixel_show();
                delay(8);
            }
        }
    break;

    case 21:
      digitalWrite(3,1);
      ws2812.pixel_set_all_color(255,0,0);
      ws2812.pixel_show();
      delay(400);
      ws2812.pixel_set_all_color(0,0,255);
      ws2812.pixel_show();
      delay(800);
      ws2812.pixel_set_all_color(0,0,0);
      ws2812.pixel_show();
    break;
    case 20:
      digitalWrite(3,0);
      ws2812.pixel_set_all_color(0,0,255);
      ws2812.pixel_show();
      delay(400);
      ws2812.pixel_set_all_color(255,0,0);
      ws2812.pixel_show();
      delay(800);
      ws2812.pixel_set_all_color(0,0,0);
      ws2812.pixel_show();
    break;

    case 31:
      ws2812.pixel_set_all_color(255,0,0);
      ws2812.pixel_show();
    break;

    case 32:
      ws2812.pixel_set_all_color(0,255,0);
      ws2812.pixel_show();    
    break;

    case 33:
      ws2812.pixel_set_all_color(0,0,255);
      ws2812.pixel_show();    
    break;

    case 34:
      //int rr = random(50,255);
      //int rg = random(50,255);
      //int rb = random(50,255);
      ws2812.pixel_set_all_color(random(0,255),random(0,255),random(0,255));
      ws2812.pixel_show(); 
    break;

    case 36:
      ws2812.pixel_set_all_color(0,255,255);
      ws2812.pixel_show();    
    break;

    case 37:
      ws2812.pixel_set_all_color(255,0,255);
      ws2812.pixel_show();    
    break;

    case 38:
      ws2812.pixel_set_all_color(255,100,0);
      ws2812.pixel_show();    
    break;

    case 39:
      ws2812.pixel_set_all_color(255,255,0);
      ws2812.pixel_show();    
    break;

    case 310:
      ws2812.pixel_set_all_color(255,255,255);
      ws2812.pixel_show();
    break;

    case 91:
      rainbows = 1;
      xTaskCreate(rainbow,"rainbow",128,NULL,4,NULL);
    break;

    case 90:
      rainbows = 0;
    break;

  }

}

void hardware_init(){
  vol_set(1);
  setPinFun(3,FIRST_FUNCTION);
  pinMode(3,output);
  //PA_3设置为输出,PA3接蓝牙板的VCC，蓝牙板和asr共地
  digitalWrite(3,0);//上电默认蓝牙为关
  vTaskDelete(NULL);
  welcome();
}

void setup()
{ 
  //{ID:0,keyword:"唤醒词",ASR:"蓝牙信标",ASRTO:"我在"}

  //{ID:11,keyword:"命令词",ASR:"打开灯光",ASRTO:"好的"}
  //{ID:10,keyword:"命令词",ASR:"关闭灯光",ASRTO:"好的"}
  //{ID:21,keyword:"命令词",ASR:"打开蓝牙",ASRTO:"好的"}
  //{ID:20,keyword:"命令词",ASR:"关闭蓝牙",ASRTO:"好的"}
  //{ID:12,keyword:"命令词",ASR:"高亮度",ASRTO:"好的"}
  //{ID:13,keyword:"命令词",ASR:"低亮度",ASRTO:"好的"}

  //{ID:31,keyword:"命令词",ASR:"红色",ASRTO:"好的"}
  //{ID:32,keyword:"命令词",ASR:"绿色",ASRTO:"好的"}
  //{ID:33,keyword:"命令词",ASR:"蓝色",ASRTO:"好的"}
  //{ID:36,keyword:"命令词",ASR:"青色",ASRTO:"好的"}
  //{ID:37,keyword:"命令词",ASR:"紫色",ASRTO:"好的"}
  //{ID:38,keyword:"命令词",ASR:"橙色",ASRTO:"好的"}
  //{ID:39,keyword:"命令词",ASR:"黄色",ASRTO:"好的"}
  //{ID:310,keyword:"命令词",ASR:"白色",ASRTO:"好的"}
  //{ID:34,keyword:"命令词",ASR:"随机颜色",ASRTO:"好的"}

  //{ID:91,keyword:"命令词",ASR:"打开彩灯",ASRTO:"好的"}
  //{ID:90,keyword:"命令词",ASR:"关闭彩灯",ASRTO:"好的"}
}



