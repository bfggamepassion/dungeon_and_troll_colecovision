#include <coleco.h>

const byte laby[] = {
  0x0F, 0x10, 0x05, 0x09, 0x0F, 0x00, 0x00, 0x00, 0x05, 0x0C, 0x05, 0x0F, 0x05, 0x0F, 0x05, 0x09,
  0x11, 0x0C, 0x03, 0x02, 0x06, 0x0A, 0x0F, 0x05, 0x0B, 0x0F, 0x03, 0x02, 0x01, 0x01, 0x04, 0x02,
  0x04, 0x05, 0x04, 0x05, 0x04, 0x00, 0x02, 0x01, 0x0F, 0x02, 0x04, 0x05, 0x04, 0x03, 0x05, 0x20,
  0x20, 0x01, 0x0F, 0x03, 0x00, 0x05, 0x0C, 0x03, 0x02, 0x20, 0x0F, 0x02, 0x0F, 0x02, 0x06, 0x0A,
  0x0C, 0x03, 0x02, 0x01, 0x09, 0x04, 0x0A, 0x01, 0x09, 0x0F, 0x03, 0x00, 0x03, 0x05, 0x06, 0x0A,
  0x0C, 0x03, 0x05, 0x01, 0x04, 0x00, 0x05, 0x01, 0x06, 0x02, 0x01, 0x0F, 0x08, 0x03, 0x03, 0x0A,
  0x0F, 0x02, 0x0D, 0x01, 0x0F, 0x00, 0x02, 0x01, 0x04, 0x05, 0x04, 0x02, 0x07, 0x0B, 0x04, 0x05,
  0x0B, 0x0F, 0x0E, 0x02, 0x01, 0x0F, 0x05, 0x0B, 0x0F, 0x02, 0x0F, 0x00, 0x02, 0x0F, 0x00, 0x02,  
  0x0F, 0x02, 0x01, 0x0C, 0x03, 0x02, 0x01, 0x09, 0x0B, 0x0F, 0x03, 0x00, 0x05, 0x04, 0x00, 0x05,
  0x04, 0x00, 0x03, 0x00, 0x03, 0x05, 0x0B, 0x01, 0x0F, 0x02, 0x0B, 0x0F, 0x02, 0x0C, 0x00, 0x02,
  0x0C, 0x05, 0x04, 0x05, 0x01, 0x04, 0x05, 0x04, 0x03, 0x00, 0x05, 0x01, 0x0F, 0x00, 0x05, 0x09,
  0x0F, 0x02, 0x0F, 0x02, 0x01, 0x0F, 0x02, 0x0F, 0x03, 0x05, 0x0B, 0x04, 0x03, 0x05, 0x06, 0x02,
  0x01, 0x0F, 0x02, 0x0F, 0x03, 0x02, 0x0F, 0x02, 0x01, 0x01, 0x0F, 0x00, 0x03, 0x02, 0x06, 0x05,
  0x01, 0x01, 0x09, 0x01, 0x01, 0x0F, 0x02, 0x09, 0x01, 0x04, 0x03, 0x00, 0x03, 0x00, 0x02, 0x0B,
  0x01, 0x04, 0x03, 0x02, 0x04, 0x02, 0x0C, 0x03, 0x03, 0x00, 0x02, 0x09, 0x04, 0x00, 0x00, 0x05,
  0x04, 0x00, 0x02, 0x0C, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x0A, 0x04, 0x00, 0x00, 0x00, 0x02
};

