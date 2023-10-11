// simple project using Arduino UNO and 160x80px SSD1320 IIC OLED Display to display fullscreen image

// created by upir, 2023
// youtube channel: https://www.youtube.com/upir_upir

// YOUTUBE VIDEO: https://youtu.be/91c_AhEqnNE

// Links from the video:
// Arduino UNO: https://s.click.aliexpress.com/e/_AXDw1h
// 160x80 SSD1320 OLED Display (Mirror): https://vi.aliexpress.com/item/1005002000386487.html
// 128x64 SSD1306 OLED Display 1.54": https://s.click.aliexpress.com/e/_DCYdWXb 
// Arduino breadboard prototyping shield: https://s.click.aliexpress.com/e/_ApbCwx
// Image2cpp (convert array to image): https://javl.github.io/image2cpp/
// Photopea (online graphics editor like Photoshop): https://www.photopea.com/
// Greybeard font: https://github.com/flowchartsman/greybeard

// Related videos with Arduino UNO and 128x64 OLED screen:
// Arduino OLED menu: https://youtu.be/HVHVkKt-ldc
// U8g vs U8g2: https://youtu.be/K5e0lFRvZ2E
// Arduino Parking Sensor - https://youtu.be/sEWw087KOj0
// Turbo pressure gauge with Arduino and OLED display - https://youtu.be/JXmw1xOlBdk
// Arduino Car Cluster with OLED Display - https://youtu.be/El5SJelwV_0
// Knob over OLED Display - https://youtu.be/SmbcNx7tbX8
// Arduino + OLED = 3D ? - https://youtu.be/kBAcaA7NAlA
// Arduino OLED Gauge - https://youtu.be/xI6dXTA02UQ
// Smaller & Faster Arduino - https://youtu.be/4GfPQoIRqW8
// Save Image from OLED Display to PC - https://youtu.be/Ft2pRMVm44E


#include <Arduino.h>
#include <U8g2lib.h> // u8g2 library

#include <Wire.h> // library requires for IIC communication

//U8G2_SSD1306_128X64_NONAME_2_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // SSD1306 display - original 128x64px display

//U8G2_SSD1320_160X80_2_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //[page buffer, size = 320 bytes] --- IIC CONNECTION
U8G2_SSD1320_160X80_2_4W_HW_SPI u8g2(U8G2_R0, /*cs*/10, /*dc*/8, /*reset*/ 9);// [page buffer, size = 320 bytes] --- SPI CONNECTION


// 'menu_project_180x60px_v2', 160x80px
// generated from the image2cpp website
const unsigned char epd_bitmap_menu_project_180x60px_v2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x0c, 0x0c, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x60, 0x80, 0xd0, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x06, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x40, 0x0e, 0x88, 0x80, 
	0x07, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x40, 0x1c, 0x80, 0x80, 0x08, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x60, 0x20, 0x39, 0x20, 0x81, 0x10, 0x0f, 0x8f, 0x8e, 0x0e, 0x0f, 0x8f, 0x1d, 
	0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xf0, 0x00, 0x81, 0x10, 0x90, 0x90, 0x91, 
	0x91, 0x10, 0x10, 0x93, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x20, 0x21, 0x21, 0x81, 
	0x10, 0x90, 0x80, 0x90, 0x90, 0x10, 0x10, 0x81, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x20, 0x21, 0x21, 0x81, 0x10, 0x1f, 0x83, 0x90, 0x90, 0x10, 0x1f, 0x81, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x60, 0x20, 0xc0, 0x03, 0x81, 0x90, 0x10, 0x8c, 0x90, 0x90, 0x90, 0x10, 0x81, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x01, 0x23, 0x81, 0x90, 0x10, 0x90, 0x90, 
	0x90, 0x90, 0x10, 0x81, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x40, 0x00, 0x80, 0x80, 
	0x88, 0x98, 0x90, 0x90, 0x91, 0x90, 0x18, 0x81, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x40, 0x04, 0x88, 0x80, 0x07, 0x17, 0x8f, 0x90, 0x0e, 0x0f, 0x17, 0x01, 0x17, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x60, 0x80, 0xe0, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x10, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0xe3, 0x31, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf0, 0x00, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xfe, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 
	0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x80, 0xf3, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x03, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 
	0x03, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x67, 0x03, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe3, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x83, 0x20, 0x88, 0x80, 
	0x1f, 0x00, 0x80, 0x01, 0x06, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 
	0x83, 0x50, 0x10, 0x81, 0x31, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x80, 0x31, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x67, 0x43, 0x48, 0x10, 0x81, 0x31, 0x9f, 0xbb, 0x31, 0xc7, 0x8e, 0x17, 0x80, 
	0x01, 0x9e, 0x1d, 0x1f, 0x9f, 0x3b, 0x00, 0x07, 0xe3, 0x47, 0x20, 0x81, 0x31, 0x33, 0xb7, 0x11, 
	0xc6, 0xd9, 0x1c, 0x00, 0x07, 0xb3, 0xb3, 0xb1, 0x31, 0x37, 0x00, 0x67, 0x03, 0x80, 0x24, 0x81, 
	0x1f, 0x30, 0xa3, 0x09, 0xc6, 0xd8, 0x0c, 0x00, 0x9e, 0xb1, 0xb1, 0x83, 0x31, 0x23, 0x00, 0x07, 
	0x03, 0x9e, 0x24, 0x81, 0x01, 0x3f, 0x83, 0x0d, 0xc6, 0xd8, 0x0c, 0x00, 0x98, 0xbf, 0x31, 0x8f, 
	0x31, 0x03, 0x00, 0x67, 0x03, 0xa1, 0x24, 0x81, 0x81, 0x31, 0x83, 0x0f, 0xc6, 0x98, 0x07, 0x00, 
	0xb0, 0x81, 0x31, 0x9c, 0x31, 0x03, 0x00, 0x07, 0x03, 0xa1, 0x24, 0x81, 0x81, 0x31, 0x83, 0x19, 
	0xc6, 0xd8, 0x00, 0x80, 0xb0, 0x81, 0x31, 0xb0, 0x31, 0x03, 0x00, 0x67, 0x63, 0xa1, 0x20, 0x81, 
	0x81, 0x39, 0x83, 0x31, 0xc6, 0x98, 0x0f, 0x80, 0x31, 0xb3, 0xb1, 0xb1, 0x31, 0x03, 0x00, 0x07, 
	0x03, 0x21, 0x10, 0x81, 0x01, 0x37, 0x83, 0xb1, 0xdf, 0x98, 0x1f, 0x80, 0x1f, 0x9e, 0x31, 0x1f, 
	0x1f, 0x03, 0x00, 0x67, 0x03, 0x1e, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x10, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x03, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0xc0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x03, 0x00, 0x40, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 
	0x03, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x67, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x07, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x67, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x61, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0xf8, 0x0f, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x60, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x40, 0x00, 0x00, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x40, 0xf0, 0x0f, 0x81, 0x3f, 0x00, 0x40, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x60, 0x20, 0x08, 0xf1, 0x00, 0x04, 0x00, 0x40, 0x00, 0x00, 0x00, 0x11, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x94, 0x42, 0x00, 0x44, 0xc8, 0x4e, 0x87, 
	0x07, 0x80, 0x00, 0x8f, 0x10, 0x17, 0x07, 0x00, 0x00, 0x00, 0x00, 0x60, 0x20, 0x64, 0x42, 0x00, 
	0x44, 0x88, 0xc9, 0x48, 0x08, 0x80, 0x00, 0x90, 0x90, 0x88, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x20, 0x64, 0x42, 0x00, 0x44, 0x88, 0x40, 0x48, 0x08, 0x80, 0x1c, 0x90, 0x90, 0x48, 0x08, 0x00, 
	0x00, 0x00, 0x00, 0x60, 0x20, 0x94, 0x42, 0x00, 0x44, 0x88, 0x40, 0x48, 0x08, 0x80, 0x10, 0x9f, 
	0x90, 0xc8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x08, 0x41, 0x00, 0x44, 0x88, 0x40, 0x48, 
	0x08, 0x80, 0x90, 0x90, 0x90, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x40, 0xf0, 0x20, 0x00, 
	0x44, 0x88, 0x40, 0x48, 0x08, 0x80, 0x90, 0x90, 0x10, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x40, 0x00, 0x20, 0x00, 0x44, 0x8c, 0xc0, 0x48, 0x08, 0x00, 0x91, 0x98, 0x98, 0x80, 0x08, 0x00, 
	0x00, 0x00, 0x00, 0x60, 0x80, 0x00, 0x10, 0x00, 0x84, 0x8b, 0x40, 0x87, 0x07, 0x00, 0x1e, 0x17, 
	0x17, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x80, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x06, 0x06, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x10, 0x00, 0x00, 0x00, 0x40, 0x5d, 0x07, 
	0x00, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 
	0x00, 0x40, 0x15, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x4d, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x44, 0x65, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void setup(void) {
  u8g2.begin(); // start the u8g2 library
}



void loop(void) {

  u8g2.firstPage(); // select the first page of the display (page is 160x8px or 160x16px), since we are using the page drawing method of the u8g2 library
  do { // draw

    u8g2.drawXBMP(0, 0, 160, 80, epd_bitmap_menu_project_180x60px_v2); // draw a fullscreen image

  } while ( u8g2.nextPage() ); // go over all the pages until the whole display is updated

}

