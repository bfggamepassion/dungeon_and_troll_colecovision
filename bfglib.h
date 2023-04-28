

byte odd;

/* Ajout BFG */
byte isCollision(int x1,int y1,byte h1,byte l1,int x2,int y2,byte h2,byte l2);
void put_char_protected(byte x,byte y,byte c);
byte get_char_protected(byte x,byte y);
char getFreeSprite();
void put_frame_fast(byte *tile,char x,char y,char w,char h);
void put_frame_crop_H24(byte *tile,char x,char y,char w,char h);