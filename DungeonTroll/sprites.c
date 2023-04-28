/********************************************/
/*                                          */
/*   GRAPHICS TABLES  -  WIN ICVGM v3.00    */
/*                                          */
/*        WARNING : RLE COMPRESSION         */
/*                                          */
/********************************************/

#include <coleco.h>

// Les sprites des armes seront stock�s en non compress�, car j'ai plus de 64 patterns
// de sprites je vais donc devoir les modifier "� la vol�e", ou plut�t � la s�lection
// du joueur
const byte WARRIOR_WEAPON[] = {  
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x09, 0x07, 0x01, 0x01, 0x01, 0x00, 0x01,
  0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x48, 0xF0, 0xC0, 0xC0, 0xC0, 0x00, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x04, 0xBF, 0xBC, 0xBF, 0x04, 0x04, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x03, 0x03, 0x03, 0x0F, 0x12, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01,
  0x80, 0x00, 0x80, 0x80, 0x80, 0xE0, 0x90, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x40, 0x20, 0x20, 0xFD, 0x3D, 0xFD, 0x20, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00
};

const byte ROGUE_WEAPON[] = {
  0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x04, 0x07, 0x00, 0x01, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x08, 0xAB, 0x08, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x00, 0x80, 0x00, 0xE0, 0x20, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x10, 0xD5, 0x10, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00
};

const byte ARCHER_WEAPON[] = {
  0x00, 0x01, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x05, 0x00,
  0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x5F, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0xFE, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
  0x00, 0xA0, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0x80, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x7F, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0xFA, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00
};
const byte WIZARD_WEAPON[] = {
  0x00, 0x00, 0x00, 0x03, 0x06, 0x05, 0x0F, 0x07, 0x0F, 0x17, 0x03, 0x05, 0x01, 0x02, 0x01, 0x01,
  0x00, 0x00, 0x00, 0x80, 0x40, 0xC0, 0xE0, 0xC0, 0xC0, 0xA0, 0x80, 0x40, 0x00, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x02, 0x01, 0x0B, 0x27, 0xDF, 0x07, 0x29, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x40, 0xF0, 0xD8, 0xE8, 0xE8, 0xF0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x02, 0x00, 0x02, 0x01, 0x05, 0x03, 0x03, 0x07, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00,
  0x80, 0x80, 0x40, 0x80, 0xA0, 0xC0, 0xE8, 0xF0, 0xE0, 0xF0, 0xA0, 0x60, 0xC0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0F, 0x17, 0x17, 0x1B, 0x0F, 0x02, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x94, 0xE0, 0xFB, 0xE4, 0xD0, 0x80, 0x40, 0x00, 0x00, 0x00
};

const byte SPATTERNRLE[] = {
  0x81, 0x00, 0x0C, 0x38, 0x5C, 0xFE, 0x6E, 0x0E, 0x1D, 0x39, 0x73, 0xE3, 0xE7, 0xFF, 0x7E,
  0x3C, 0x83, 0x00, 0x1B, 0x38, 0x7C, 0xFC, 0xCC, 0xDC, 0x98, 0x99, 0xB2, 0x32, 0x76, 0x7E, 0x3C,
  0x00, 0x38, 0x5C, 0xFE, 0x66, 0x06, 0x0E, 0x0C, 0x1C, 0x38, 0x71, 0x71, 0x73, 0x7B, 0x3F, 0x1E,
  0x87, 0x00, 0x07, 0x70, 0xF8, 0xFA, 0xD9, 0xDD, 0x9F, 0x0F, 0x06, 0x82, 0x00, 0x06, 0x04, 0x13,
  0x18, 0x3F, 0x7B, 0xC4, 0x80, 0x88, 0x00, 0x06, 0x80, 0x20, 0x60, 0xF0, 0x78, 0x8C, 0x04, 0x87,
  0x00, 0x06, 0xC0, 0x64, 0x73, 0x38, 0x1F, 0x13, 0x04, 0x88, 0x00, 0x06, 0x0C, 0x98, 0x38, 0x70,
  0xE0, 0x20, 0x80, 0x8F, 0x00, 0x07, 0x08, 0x0F, 0x0F, 0x0A, 0x07, 0x0B, 0x14, 0x3A, 0x89, 0x00,
  0x01, 0xA0, 0x20, 0x82, 0x10, 0x1F, 0x88, 0x19, 0x2E, 0x17, 0x09, 0x0C, 0x0F, 0x0E, 0x09, 0x0C,
  0x18, 0x28, 0x70, 0x20, 0xC0, 0xC0, 0x60, 0x0A, 0xFF, 0xEA, 0x88, 0x08, 0x10, 0x90, 0xD0, 0xE0,
  0x40, 0x60, 0x30, 0x2C, 0x18, 0x10, 0x88, 0x00, 0x07, 0x08, 0x0F, 0x0F, 0x0A, 0x07, 0x0B, 0x0C,
  0x15, 0x89, 0x00, 0x02, 0x80, 0x20, 0x20, 0x82, 0x10, 0x15, 0x1A, 0x0D, 0x17, 0x0B, 0x0D, 0x0E,
  0x0C, 0x03, 0x06, 0x07, 0x05, 0x06, 0x06, 0x02, 0x0C, 0x0F, 0x08, 0x0A, 0xFF, 0xEA, 0x88, 0x08,
  0x82, 0x10, 0x81, 0x20, 0x8E, 0x00, 0x01, 0x05, 0x04, 0x82, 0x08, 0x00, 0x11, 0x87, 0x00, 0x27,
  0x10, 0xF0, 0xF0, 0x50, 0xE0, 0xD0, 0x28, 0x5C, 0x50, 0xFF, 0x57, 0x11, 0x10, 0x08, 0x09, 0x0B,
  0x07, 0x02, 0x06, 0x0C, 0x34, 0x18, 0x08, 0x00, 0x98, 0x74, 0xE8, 0x90, 0x30, 0xF0, 0x70, 0x90,
  0x30, 0x18, 0x14, 0x0E, 0x04, 0x03, 0x03, 0x06, 0x89, 0x00, 0x02, 0x01, 0x04, 0x04, 0x82, 0x08,
  0x87, 0x00, 0x0D, 0x10, 0xF0, 0xF0, 0x50, 0xE0, 0xD0, 0x30, 0xA8, 0x10, 0x50, 0xFF, 0x57, 0x11,
  0x10, 0x82, 0x08, 0x81, 0x04, 0x84, 0x00, 0x0F, 0x58, 0xB0, 0xE8, 0xD0, 0xB0, 0x70, 0x30, 0xC0,
  0x60, 0xE0, 0xA0, 0x60, 0x60, 0x40, 0x30, 0xF0, 0x82, 0x00, 0x0B, 0x1C, 0x3E, 0x3F, 0x33, 0x3B,
  0x19, 0x99, 0x4D, 0x4C, 0x6E, 0x7E, 0x3C, 0x82, 0x00, 0x0C, 0x1C, 0x3A, 0x7F, 0x76, 0x70, 0xB8,
  0x9C, 0xCE, 0xC7, 0xE7, 0xFF, 0x7E, 0x3C, 0x87, 0x00, 0x60, 0x0E, 0x1F, 0x5F, 0x9B, 0xBB, 0xF9,
  0xF0, 0x60, 0x00, 0x1C, 0x3A, 0x7F, 0x66, 0x60, 0x70, 0x30, 0x38, 0x1C, 0x8E, 0x8E, 0xCE, 0xDE,
  0xFC, 0x78, 0x00, 0x00, 0x07, 0x0F, 0x19, 0x1B, 0x0E, 0x0F, 0x02, 0x03, 0x0D, 0x11, 0x77, 0xE1,
  0x8F, 0x85, 0x98, 0x00, 0x80, 0xC0, 0x00, 0x40, 0xCA, 0xCC, 0x84, 0xA2, 0x17, 0xFE, 0x00, 0xF0,
  0x00, 0x70, 0x08, 0x00, 0x01, 0x03, 0x00, 0x02, 0x53, 0x33, 0x21, 0x45, 0xE8, 0x7F, 0x00, 0x0F,
  0x00, 0x0E, 0x10, 0x00, 0xE0, 0xF0, 0x98, 0xD8, 0x70, 0xF0, 0x40, 0xC0, 0xB0, 0x88, 0xEE, 0x87,
  0xF1, 0xA1, 0x19, 0x30, 0x28, 0x34, 0x0A, 0x05, 0x03, 0x03, 0x0E, 0x87, 0x00, 0x06, 0x0C, 0x14,
  0x28, 0x50, 0x60, 0x30, 0x18, 0x88, 0x00, 0x06, 0x30, 0x28, 0x14, 0x0A, 0x06, 0x0C, 0x18, 0x88,
  0x00, 0x07, 0x0C, 0x14, 0x2C, 0x50, 0xA0, 0xC0, 0xC0, 0x70, 0x87, 0x00, 0x42, 0x07, 0x0F, 0x89,
  0x89, 0x86, 0x87, 0x85, 0x80, 0x83, 0x8E, 0xBB, 0xA0, 0x83, 0x82, 0x81, 0x86, 0xC0, 0xE0, 0x20,
  0x20, 0xC0, 0xC0, 0x40, 0x00, 0xE0, 0xBC, 0xE2, 0x82, 0xE6, 0xA6, 0xF0, 0x18, 0x83, 0x87, 0x84,
  0x84, 0x83, 0x83, 0x82, 0xA0, 0xBB, 0x8E, 0x83, 0x80, 0x83, 0x82, 0x87, 0x0C, 0xE0, 0xF0, 0x90,
  0x90, 0x60, 0xE0, 0xA0, 0x00, 0xE0, 0xB8, 0xEF, 0x83, 0xE0, 0xA0, 0xC0, 0x30, 0x8C, 0x08, 0x38,
  0x8C, 0x00, 0x01, 0x08, 0x0E, 0x8D, 0x00, 0x01, 0x08, 0x38, 0x8D, 0x00, 0x02, 0x18, 0x08, 0x0E,
  0x8C, 0x00, 0x08, 0x07, 0x0D, 0x0F, 0x0C, 0x04, 0x05, 0x03, 0x1D, 0x7E, 0x82, 0xE0, 0x78, 0x70,
  0x7F, 0x1E, 0x00, 0xC0, 0x60, 0xE0, 0x60, 0x40, 0x40, 0x80, 0xD8, 0xFE, 0x67, 0x63, 0x63, 0xC3,
  0xC6, 0x1C, 0xF0, 0x00, 0x03, 0x07, 0x0F, 0x0F, 0x0A, 0x07, 0x15, 0x7F, 0xE0, 0xE0, 0xF0, 0x7F,
  0x1F, 0x00, 0x00, 0xF0, 0xF8, 0xFC, 0x9C, 0x8E, 0x8E, 0x06, 0x66, 0xFE, 0x3F, 0x4F, 0x37, 0xDB,
  0xC6, 0x00, 0x00, 0x03, 0x07, 0x02, 0x17, 0x35, 0x30, 0x62, 0xCD, 0xEA, 0xA4, 0x87, 0x4F, 0x0F,
  0x17, 0x38, 0x28, 0x80, 0xC0, 0xC0, 0xD0, 0x18, 0x18, 0x8C, 0x6C, 0xA6, 0x4E, 0xCA, 0xE2, 0xA4,
  0xC0, 0x30, 0x50, 0x01, 0x03, 0x03, 0x0B, 0x18, 0x18, 0x31, 0x36, 0x65, 0x72, 0x53, 0x47, 0x25,
  0x03, 0x0C, 0x0A, 0xC0, 0xE0, 0x40, 0xE8, 0xAC, 0x0C, 0x46, 0xB3, 0x57, 0x25, 0xE1, 0xF2, 0xF0,
  0xE8, 0x1C, 0x14, 0x30, 0x30, 0x28, 0x18, 0x70, 0x8A, 0x00, 0x04, 0x38, 0x18, 0x10, 0x0C, 0x0E,
  0x8A, 0x00, 0x04, 0x1C, 0x18, 0x08, 0x30, 0x70, 0x8A, 0x00, 0x81, 0x0C, 0x02, 0x14, 0x18, 0x0E,
  0x92, 0x00, 0x07, 0x0F, 0x0C, 0x0E, 0x0F, 0x0B, 0x04, 0x0E, 0x15, 0x8F, 0x00, 0x0F, 0x0A, 0x0D,
  0x16, 0x0B, 0x01, 0x0A, 0x0C, 0x03, 0x06, 0x07, 0x05, 0x06, 0x06, 0x02, 0x0C, 0x0F, 0x82, 0x00,
  0x02, 0x40, 0xFF, 0x40, 0x92, 0x00, 0x06, 0x0F, 0x0C, 0x0E, 0x0F, 0x0B, 0x14, 0x3A, 0x8E, 0x00,
  0x11, 0x80, 0x11, 0x26, 0x37, 0x31, 0x1A, 0x0F, 0x02, 0x09, 0x0C, 0x18, 0x28, 0x70, 0x20, 0xC0,
  0xC0, 0x60, 0x00, 0x82, 0x80, 0x0A, 0x00, 0xFF, 0x80, 0xC0, 0xE0, 0x40, 0x60, 0x30, 0x2C, 0x18,
  0x10, 0x98, 0x00, 0x07, 0xF0, 0x30, 0x70, 0xF0, 0xD0, 0x20, 0x70, 0xA8, 0x82, 0x00, 0x02, 0x02,
  0xFF, 0x02, 0x89, 0x00, 0x0F, 0x50, 0xB0, 0x68, 0xD0, 0x80, 0x50, 0x30, 0xC0, 0x60, 0xE0, 0xA0,
  0x60, 0x60, 0x40, 0x30, 0xF0, 0x8E, 0x00, 0x00, 0x01, 0x88, 0x00, 0x07, 0xF0, 0x30, 0x70, 0xF0,
  0xD0, 0x28, 0x5C, 0x00, 0x82, 0x01, 0x1B, 0x00, 0xFF, 0x01, 0x03, 0x07, 0x02, 0x06, 0x0C, 0x34,
  0x18, 0x08, 0x00, 0x88, 0x64, 0xEC, 0x8C, 0x58, 0xF0, 0x40, 0x90, 0x30, 0x18, 0x14, 0x0E, 0x04,
  0x03, 0x03, 0x06, 0x88, 0x00, 0x06, 0x0F, 0x1F, 0x3F, 0x7F, 0x6B, 0xD4, 0x1A, 0x88, 0x00, 0x25,
  0x82, 0xC5, 0x85, 0x84, 0x04, 0x04, 0x84, 0x35, 0x3F, 0x37, 0x37, 0x1B, 0x1C, 0x0F, 0x1D, 0x09,
  0x1D, 0x39, 0x7D, 0x3F, 0xDC, 0xC0, 0x60, 0x04, 0x04, 0xAC, 0xEC, 0xE4, 0xE4, 0x24, 0xC4, 0xE4,
  0x44, 0x64, 0xF0, 0xEC, 0xD8, 0x10, 0x88, 0x00, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0x6B, 0xD4, 0x0E,
  0x15, 0x87, 0x00, 0x03, 0x82, 0xC5, 0x85, 0x84, 0x83, 0x04, 0x16, 0x1A, 0x1F, 0x17, 0x0B, 0x04,
  0x0B, 0x0C, 0x0F, 0x1C, 0x3E, 0x1C, 0x3E, 0x1F, 0x33, 0x0C, 0x0F, 0x04, 0xAC, 0xEC, 0xE4, 0xE4,
  0xA4, 0x84, 0x82, 0xC4, 0x82, 0xC0, 0x00, 0xE0, 0x8A, 0x00, 0x06, 0x41, 0xA3, 0xA1, 0x21, 0x20,
  0x20, 0x21, 0x88, 0x00, 0x26, 0xF0, 0xF8, 0xFC, 0xFE, 0xD6, 0x2B, 0x58, 0x20, 0x20, 0x35, 0x37,
  0x27, 0x27, 0x24, 0x23, 0x27, 0x22, 0x26, 0x0F, 0x37, 0x1B, 0x08, 0x00, 0xAC, 0xFC, 0xEC, 0xEC,
  0xD8, 0x38, 0xF0, 0xB8, 0x90, 0xB8, 0x9C, 0xBE, 0xFC, 0x3B, 0x03, 0x06, 0x87, 0x00, 0x03, 0x41,
  0xA3, 0xA1, 0x21, 0x83, 0x20, 0x87, 0x00, 0x0E, 0xF0, 0xF8, 0xFC, 0xFE, 0xD6, 0x2B, 0x70, 0xA8,
  0x20, 0x35, 0x37, 0x27, 0x27, 0x25, 0x21, 0x82, 0x23, 0x82, 0x03, 0x12, 0x07, 0x00, 0x00, 0x58,
  0xF8, 0xE8, 0xD0, 0x20, 0xD0, 0x30, 0xF0, 0x38, 0x7C, 0x38, 0x7C, 0xF8, 0xCC, 0x30, 0xF0, 0x88,
  0x00, 0x06, 0x07, 0x0E, 0x09, 0x0F, 0x1B, 0x0E, 0x17, 0x89, 0x00, 0x00, 0x80, 0x84, 0x00, 0x15,
  0x0B, 0x0D, 0x16, 0x0B, 0x01, 0x0A, 0x0C, 0x03, 0x06, 0x07, 0x05, 0x06, 0x06, 0x02, 0x0C, 0x0F,
  0x00, 0x00, 0x20, 0x40, 0x80, 0x80, 0x93, 0x00, 0x05, 0x07, 0x0E, 0x09, 0x0F, 0x13, 0x1C, 0x8A,
  0x00, 0x00, 0x80, 0x83, 0x00, 0x1E, 0x3E, 0x1F, 0x26, 0x37, 0x33, 0x1A, 0x09, 0x03, 0x09, 0x0C,
  0x18, 0x28, 0x60, 0xC0, 0x40, 0x60, 0x80, 0x00, 0x88, 0x90, 0x60, 0x20, 0x80, 0x80, 0xC0, 0xE0,
  0x40, 0x60, 0x2C, 0x18, 0x10, 0x8A, 0x00, 0x00, 0x01, 0x8D, 0x00, 0x0C, 0xE0, 0x70, 0x90, 0xF0,
  0xD8, 0x70, 0xE8, 0x00, 0x00, 0x04, 0x02, 0x01, 0x01, 0x89, 0x00, 0x0F, 0xD0, 0xB0, 0x68, 0xD0,
  0x80, 0x50, 0x30, 0xC0, 0x60, 0xE0, 0xA0, 0x60, 0x60, 0x40, 0x30, 0xF0, 0x8A, 0x00, 0x00, 0x01,
  0x8D, 0x00, 0x25, 0xE0, 0x70, 0x90, 0xF0, 0xC8, 0x38, 0x01, 0x00, 0x11, 0x09, 0x06, 0x04, 0x01,
  0x01, 0x03, 0x07, 0x02, 0x06, 0x34, 0x18, 0x08, 0x00, 0x7C, 0xF8, 0x64, 0xEC, 0xCC, 0x58, 0x90,
  0xC0, 0x90, 0x30, 0x18, 0x14, 0x06, 0x03, 0x02, 0x06, 0xFE, 0x00, 0xFC, 0x00, 0x83, 0x00, 0x4C,
  0x47, 0x8D, 0x9B, 0x9B, 0xDB, 0xCD, 0x67, 0x3B, 0x77, 0x67, 0x2B, 0x26, 0x12, 0x13, 0x10, 0x08,
  0xC4, 0x62, 0xB2, 0xB2, 0xB6, 0x66, 0xCC, 0xB8, 0xDC, 0xCC, 0xA8, 0xC8, 0x90, 0x90, 0x10, 0x20,
  0x27, 0x4D, 0x9B, 0x9B, 0xDB, 0xCD, 0x27, 0x3B, 0x37, 0x67, 0x2B, 0x26, 0x12, 0x1B, 0x09, 0x04,
  0xC8, 0x64, 0xB2, 0xB2, 0xB6, 0x66, 0xC8, 0xB8, 0xD8, 0xCC, 0xA8, 0xC8, 0x90, 0xB0, 0x20, 0x40,
  0x00, 0x1B, 0x77, 0x64, 0x14, 0x07, 0x05, 0x11, 0x01, 0x0C, 0x3E, 0x34, 0x0C, 0x82, 0x00, 0x0F,
  0x0C, 0xEC, 0xFE, 0x9E, 0x90, 0x70, 0x50, 0xC4, 0xC0, 0x30, 0x38, 0x9E, 0x1E, 0x08, 0x00, 0x00,
  0x9F, 0xFF, 0xFF};