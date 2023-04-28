#define chrtab  0x1800 /* écran en linéaire */
#define chrgen  0x0000 /* table des caractères */
#define coltab  0x2000 /* couleur des caractères */
#define sprtab  0x3800 /* sprite_pattern_table */
#define sprgen  0x1b00 /* sprite_attribute_table */
#define buffer  0x1c00 /* buffer screen 2 */
#define freevr	0x2800 /* Zone libre pour mode graphique texte */

#define SCREEN_ON	screen_on();enable_nmi();
#define SCREEN_OFF  disable_nmi();screen_off();

unsigned char isCollision(int x1,int y1,unsigned char h1,unsigned char l1,int x2,int y2,unsigned char h2,unsigned char l2);
void initSprites();
char getFreeSprite();
void showSprites();
void setSprite(unsigned char ss,unsigned char xs,unsigned char ys,unsigned char cs,unsigned char ps);
void moveSprite(unsigned char ss,unsigned char xs,unsigned char ys);
void LoadPatternAndshowAScreen(char* p,char *c,char *n,char show,unsigned dest);
unsigned char get_char_protected(unsigned char x,unsigned char y);
void copyTileXY(unsigned char sx,unsigned char sy,unsigned char dx,unsigned char dy);
unsigned char peekVram(int offset);
void pokeVram(int offset,int v);