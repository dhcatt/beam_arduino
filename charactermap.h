/*
===========================================================================    

  This is the library for Beam. 
  
  Beam is a beautiful LED matrix — features 120 LEDs that displays scrolling text, animations, or custom lighting effects. 
  Beam can be purchased here: http://www.hoverlabs.co
  
  Written by Emran Mahbub and Jonathan Li for Hover Labs.  
  BSD license, all text above must be included in any redistribution
  
===========================================================================
*/ 

uint8_t charactermap[66][7] = {
{0x00,0x00,0xFF,0xFF,0xFF,0xFF},      // SPACE
{0x17,0x0,0xFF,0xFF,0xFF,0xFF,0xFF},      // !
{0x3,0x0,0x3,0x0,0xFF,0x0,0xFF},       // "
{0xA,0x1F,0xA,0x1F,0xA,0x0,0xFF},     // #
{0x17,0x15,0x1F,0x15,0x1D,0x0,0xFF},  // $
{0x12,0x8,0x4,0x12,0x0,0xFF,0xFF},     // %
{0xA,0x15,0xE,0x10,0x0,0xFF,0xFF},     // &
{0x3,0x0,0xFF,0xFF,0xFF,0xFF,0xFF},       // '
{0xE,0x11,0x0,0xFF,0xFF,0xFF,0xFF},      // (
{0x11,0xE,0x0,0xFF,0xFF,0xFF,0xFF},      // )
{0x5,0x2,0x5,0x0,0xFF,0xFF,0xFF},       // *
{0x8,0x1C,0x8,0x0,0xFF,0xFF,0xFF},      // +
{0x10,0x8,0x0,0xFF,0xFF,0xFF,0xFF},      // ,
{0x4,0x4,0x0,0xFF,0xFF,0xFF,0xFF},       // -
{0x10,0x0,0xFF,0xFF,0xFF,0xFF,0xFF},      // .
{0x18,0xE,0x3,0x0,0xFF,0xFF,0xFF},      // /
{0x1F,0x11,0x1F,0x0,0xFF,0xFF,0xFF},    // 0
{0x2,0x1F,0x0,0xFF,0xFF,0xFF,0xFF},      // 1
{0x1D,0x15,0x17,0x0,0xFF,0xFF,0xFF},    // 2
{0x15,0x15,0x1F,0x0,0xFF,0xFF,0xFF},    // 3
{0x7,0x4,0x1F,0x0,0xFF,0xFF,0xFF},      // 4
{0x17,0x15,0x1D,0x0,0xFF,0xFF,0xFF},    // 5
{0x1F,0x15,0x1D,0x0,0xFF,0xFF,0xFF},    // 6
{0x1,0x1,0x1F,0x0,0xFF,0xFF,0xFF},      // 7
{0x1F,0x15,0x1F,0x0,0xFF,0xFF,0xFF},    // 8
{0x17,0x15,0x1F,0x0,0xFF,0xFF,0xFF},    // 9
{0xA,0x0,0xFF,0xFF,0xFF,0xFF,0xFF},       // :
{0xA,0x0,0xFF,0xFF,0xFF,0xFF,0xFF},       // ;
{0x4,0xA,0x11,0x0,0xFF,0xFF,0xFF},      // <
{0xA,0xA,0xA,0x0,0xFF,0xFF,0xFF},       // =
{0x11,0xA,0x4,0x0,0xFF,0xFF,0xFF},      // >
{0x1,0x15,0x7,0x0,0xFF,0xFF,0xFF},      // ?
{0x1F,0x11,0x1D,0x15,0x1F,0x0,0xFF},  // @
{0x1F,0x05,0x05,0x1F,0x00,0xFF,0xFF},  // A
{0x1F,0x15,0x15,0x0A,0x00,0xFF,0xFF},  // B
{0x0E,0x11,0x11,0x0A,0x00,0xFF,0xFF},  // C
{0x1F,0x11,0x11,0x0E,0x00,0xFF,0xFF},  // D
{0x1F,0x15,0x15,0x15,0x00,0xFF,0xFF},  // E
{0x1F,0x5,0x5,0x0,0xFF,0xFF,0xFF},     // F
{0x1F,0x11,0x15,0x1D,0x0,0xFF,0xFF},   // G
{0x1F,0x4,0x4,0x1F,0x0,0xFF,0xFF},     // H
{0x11,0x1F,0x11,0x0,0xFF,0xFF,0xFF},   // I
{0x18,0x10,0x1F,0x0,0xFF,0xFF,0xFF},   // J
{0x1F,0x4,0x1B,0x0,0xFF,0xFF,0xFF},    // K
{0x1F,0x10,0x10,0x0,0xFF,0xFF,0xFF},   // L
{0x1F,0x2,0x4,0x2,0x1F,0x00,0xFF},     // M
{0x1F,0x2,0x4,0x8,0x1F,0x00,0xFF},     // N
{0xE,0x11,0x11,0x11,0xE,0x00,0xFF},    // O
{0x1F,0x5,0x7,0x0,0xFF,0xFF,0xFF},     // P
{0x1F,0x11,0x15,0x19,0x1F,0x00,0xFF},  // Q
{0x1F,0x5,0xD,0x17,0x0,0xFF,0xFF},     // R
{0x17,0x15,0x15,0x1D,0x0,0xFF,0xFF},   // S
{0x1,0x1F,0x1,0x0,0xFF,0xFF,0xFF},     // T
{0x1F,0x10,0x10,0x1F,0x0,0xFF,0xFF},   // U
{0x7,0x8,0x10,0x8,0x7,0x00,0xFF},      // V
{0xF,0x10,0xC,0x10,0xF,0x00,0xFF},     // W
{0x11,0xA,0x4,0xA,0x11,0x00,0xFF},     // X
{0x1,0x2,0x1C,0x2,0x1,0x00,0xFF},      // Y
{0x11,0x19,0x15,0x13,0x0,0xFF,0xFF},   // Z
{0x1F,0x11,0x0,0xFF,0xFF,0xFF,0xFF},       //[
{0x3,0xE,0x18,0x0,0xFF,0xFF,0xFF},        ///
{0x11,0x1F,0x0,0x0,0xFF,0xFF,0xFF},       //]
{0x6,0xE,0x1C,0xE,0x6,0x0,0xFF},        //^
{0x10,0x10,0x10,0x0,0xFF,0xFF,0xFF},      //_
{0x1,0x2,0x0,0xFF,0xFF,0xFF,0xFF},         //'


};
