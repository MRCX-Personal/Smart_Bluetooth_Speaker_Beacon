# Smart Speech Recognition Bluetooth Speaker and RGB Full Color light in the shape of the Beacon in game Minecraft

zh-CN/简体中文：[查看链接](https://) <br>

This project is a Smart Bluetooth Speaker in the shape of the Beacon in game Minecraft. <br>
This repository includes programs, circuit information, and 3D models of this project. <br>
The video demonstration and tutorial for this project:[Bilibili](https://www.bilibili.com/video/av1401504252/) <br>
I would greatly appreciate it if you press like or subscribe. <br>

## Features/功能
* Bluetooth speaker/蓝牙音箱
* voice recognize/voice commands/语音控制
* RGB Full Color Night light/Atmosphere light/RGB全彩氛围灯
* Build in Battery/内置电池，可离线使用

![pic1](https://github.com/MRCX-Personal/Smart_Bluetooth_Speaker_Beacon/blob/main/pic/sample.jpg?raw=true)

![pic2](https://github.com/MRCX-Personal/Smart_Bluetooth_Speaker_Beacon/blob/main/pic/top.jpg?raw=true)

![pic3](https://github.com/MRCX-Personal/Smart_Bluetooth_Speaker_Beacon/blob/main/pic/colourful.jpg?raw=true)

## Component List/原件清单
* WS2812/全彩LED灯珠
* asrpro/语音识别开发板，作为主控
* 3.7V battery/电池和3.7-5v充放电升压板
* speaker*2/2个扬声器，这里选用的是2个lg g7的拆机扬声器
* Bluetooth receiver/蓝牙音频接收板，这里选用的是“MH-M18”的板子，支持3.7v或者5v输入，有按键控制
* 音频功放板，如果使用的蓝牙板自带功放，则不需要此原件，这里选用的是PAM8403

## Circuit and connect/电路连接

```
Type-C:
DM-RXD-PB5
DP-TXD-PB6

WS2812:
VCC-5V
GND-GND
IN-PA6

BLE receiver:
key-PA3 
```
you can view this picture as reference.
![pic4](https://github.com/MRCX-Personal/Smart_Bluetooth_Speaker_Beacon/blob/main/pic/connect.jpg?raw=true)


## Reference documents/参考资料
* [ASRPRO扩展库[WS2812]](https://haohaodada.com/new/bbs/forum.php?mod=viewthread&tid=860&extra=)
* [ASRPRO 核心板规格书](http://www.haohaodada.com/jpeguploadfile/twen/ASRPRO/ASRPROCoreV1.1.pdf)
