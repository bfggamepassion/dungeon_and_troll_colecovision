#include <coleco.h>
#include <getput1.h>
#include "fonctions.h"

#define SALLE_MAX 255

#define MAXENNEMY 5
#define MAXWEAPON 3

#define MONSTRE_RIEN        0
#define MONSTRE_BAT         1
#define MONSTRE_SERPENT	    2
#define	MONSTRE_SQUELETTE   3
#define MONSTRE_SERPENT2	4
#define	MONSTRE_SQUELETTE2  5

#define MONSTRE_TROLL1		6
#define MONSTRE_TROLL2		7
#define MONSTRE_TROLL3		8

#define MONSTRE_ARAIGNEE_COULEUR1 9
#define MONSTRE_ARAIGNEE_COULEUR2 10

#define MONSTRE_MORT	11 		// Faux monstre : icône de mort pour monstre tué

#define	BASEPATTERN_BAT	8 //2*4
#define	BASEPATTERN_SERPENT_GAUCHE	0 //0*4
#define	BASEPATTERN_SERPENT_DROITE	48 //12*4
#define	BASEPATTERN_SQUELETTE 56 // 14*4
#define	BASEPATTERN2_SQUELETTE 64 // 16*4
#define	BASEPATTERN_SQUELETTE2 72 // 18*4
#define	BASEPATTERN2_SQUELETTE2 80 // 20*4
#define	BASEPATTERN_SERPENT2	88 //22*4
#define	BASEPATTERN_TROLL 96 // 24*4
#define	BASEPATTERN2_TROLL 104 // 26*4
#define BASEPATTERN_ARAIGNEE 240
#define BASEPATTERN_HIDE 252 // 63*4 (pour cacher le joueur quand il sort d'une pièce)
#define BASEPATTERN_MORT 248 // Icône de mort pour les ennemis



// TODO : Changer la numérotation avec le n° de la tile à afficher !!!
#define OBJET_RIEN 						0

#define OBJET_FIXE_ENERGIE_RING 		24
#define OBJET_FIXE_CLE_DOREE 			25
#define OBJET_FIXE_CLE_BLEU 			26
#define OBJET_FIXE_CLE_ROUGE 			27
#define OBJET_RANDOM_POTION_FORCE 		28
#define OBJET_RANDOM_ARME 				29
#define OBJET_FIXE_PORTE_DOREE 			30
#define OBJET_FIXE_PORTE_ROUGE 			31
#define OBJET_FIXE_PORTE_BLEU 			32
#define OBJET_FIXE_NOFIRE_RING 			33
#define OBJET_RANDOM_POTION_ENERGIE 	34

#define OBJET_RANDOM_BOUCLIER			35
#define OBJET_FIXE_TORCHE				36
#define OBJET_RANDOM_ARGENT				37


#define MESSAGE_GOLD		1
#define MESSAGE_SHIELD		2
#define MESSAGE_LIFEPOTION	3
#define MESSAGE_FORCEPOTION 4
#define MESSAGE_BLUEKEY		5
#define MESSAGE_REDKEY		6
#define MESSAGE_GOLDKEY		7
#define MESSAGE_FIRERING	8
#define MESSAGE_ENERGYRING	9
#define MESSAGE_AMMO		10
#define MESSAGE_TORCH		11
#define MESSAGE_NULL		12
#define MESSAGE_FIRE_NORING	13
#define MESSAGE_FIRE_RING	14

#define WORKFLOW_TITLESCREEN	0
#define	WORKFLOW_CHOOSECLASS	1
#define	WORKFLOW_INGAME			2
#define WORKFLOW_GAMEOVER		3
#define WORKFLOW_YOUWIN			4

#define SPATTERN0	0
#define SPATTERN1	4
#define SPATTERN2	8
#define SPATTERN3	12
#define SPATTERN4	16
#define SPATTERN5	20
#define SPATTERN6	24
#define SPATTERN7	28
#define SPATTERN8	32
#define SPATTERN9	36
#define SPATTERN10	40
#define SPATTERN11	44
#define SPATTERN12	48
#define SPATTERN13	52
#define SPATTERN14	56
#define SPATTERN15	60
#define SPATTERN16	64
#define SPATTERN17	68
#define SPATTERN18	72
#define SPATTERN19	76
#define SPATTERN20	80
#define SPATTERN21	84
#define SPATTERN22	88
#define SPATTERN23	92
#define SPATTERN24	96
#define SPATTERN25	100
#define SPATTERN26	104
#define SPATTERN27	108
#define SPATTERN28	112
#define SPATTERN29	116
#define SPATTERN30	120
#define SPATTERN31	124
#define SPATTERN32	128
#define SPATTERN33	132
#define SPATTERN34	136
#define SPATTERN35	140
#define SPATTERN36	144
#define SPATTERN37	148
#define SPATTERN38	152
#define SPATTERN39	156
#define SPATTERN40	160
#define SPATTERN41	164
#define SPATTERN42	168
#define SPATTERN43	172
#define SPATTERN44	176
#define SPATTERN45	180
#define SPATTERN46	184
#define SPATTERN47	188
#define SPATTERN48	192
#define SPATTERN49	196
#define SPATTERN50	200
#define SPATTERN51	204
#define SPATTERN52	208
#define SPATTERN53	212
#define SPATTERN54	216
#define SPATTERN55	220
#define SPATTERN56	224
#define SPATTERN57	228
#define SPATTERN58	232
#define SPATTERN59	236
#define SPATTERN60	240
#define SPATTERN61	244
#define SPATTERN62	248
#define SPATTERN63	252


#define S_TRUE 1
#define S_FALSE 0

#define INACTIF 204
#define INVISIBLE 203

#define HAUT		0
#define HAUT_DROITE 1
#define DROITE		2
#define BAS_DROITE	3
#define BAS			4
#define BAS_GAUCHE  5
#define GAUCHE		6
#define	HAUT_GAUCHE	7

#define W_SPLASH0	0
#define W_SPLASH1	1
#define	W_INIT		2
#define W_MENU		3
#define W_INGAME	4
#define W_GAMEOVER	5
#define W_LOOSELIFE	6

#define PLAYER_TETE		3
#define PLAYER_CORPS	2
#define PLAYER_HIDE1	1
#define PLAYER_HIDE2	0
#define PLAYER_WEAPON	16

#define PLAYERCLASS_WARRIOR		1
#define PLAYERCLASS_ROGUE		2
#define PLAYERCLASS_MAGICIAN	3
#define PLAYERCLASS_ARCHER		4


#define	NO_WEAPON		0
#define	WEAPON_SWORD	1
#define WEAPON_KNIFE	2
#define WEAPON_MAGIC	3

extern const byte CHARSET_NAMERLE[];
extern const byte CHARSET_PATTERNRLE[];
extern const byte CHARSET_COLORRLE[];
extern const byte SPATTERNRLE[];

extern const byte WARRIOR_WEAPON[];
extern const byte ROGUE_WEAPON[];
extern const byte ARCHER_WEAPON[];
extern const byte WIZARD_WEAPON[];

extern const byte* const rooms[];
extern const byte room_contenance[];
extern const byte laby[];
extern const byte laby_contenance[];

/* from music.s */
extern const void music[];
/* from sound.s */
extern const void snd_table[];

// shoot rate
// WARRIOR = 20			-- COURT
// ROGUE = 30			-- MOYEN
// MAGICIAN = 100		-- LONG
// ARCHER = 60			-- MOYEN
const byte shoot_rate_def[] = {0,20,15,100,45};

byte analyze[8];

/************************************/
/** Variable SAS VRAM-->RAM-->VRAM **/
/************************************/
byte room_objstat,room_objstat_tile;	/* Type d'objet statique (porte, clé, ...) et tile ou il se situe */
byte room_bonus,room_bonus_tile;	/* Type de bonus dans la salle, tile ou se trouve le bonus */
byte room_mster1;  /* Type de monstre dans la salle */
byte room_mster2;  /* Type de monstre dans la salle */
byte room_mster3;  /* Type de monstre dans la salle */
byte room_mster4;  /* Type de monstre dans la salle */

byte workflow;

byte cpt;
byte nmi_renderStat;
byte nmi_message;

byte basePattern_tete_droite;
byte basePattern_tete_gauche;
byte basePattern_corps_droite;
byte basePattern_corps_gauche;

volatile byte collision_pied;
volatile byte collision_tete;
volatile byte collision_droite;
volatile byte collision_gauche;

volatile byte collision_pied_valeur;
volatile byte collision_tete_valeur;
volatile byte collision_droite_valeur;
volatile byte collision_gauche_valeur;

volatile byte c1,c1x,c1y;
volatile byte c2,c2x,c2y;
volatile byte c3,c3x,c3y;

volatile int oldRoomNumber;
volatile int currentRoomNumber;


// Va permettre de déterminer la direction du tir
char last_dirx;
char last_diry;

char last_dirx_shoot;
char last_diry_shoot;

byte choice;
int x,y;	 // Position dans la salle courante

byte weapon_deg;
byte weapon_speed;
byte weapon_coll;

byte redraw;

typedef struct
{
	char sprno; 
	byte typobj;
} s_objets;

s_objets objet;

//typedef struct
//{
	byte player_type;
	byte player_x,player_y,player_anim;
	byte player_pattern_tete,player_pattern_corps,player_move;
	byte player_ammo; /* Nombre de munition */
	byte player_ammo_max;
	byte player_pv; /* Nombre de point de vie courant */
	byte player_pv_max; /* Nombre de point de vie maximum */
	byte player_speed; /* vitesse de déplacement du joueur */
	byte player_shoot_rate;
	byte player_canshoot;
	
	/*
	#define OBJET_FIXE_ENERGIE_RING 		24
	#define OBJET_FIXE_CLE_DOREE 			25
	#define OBJET_FIXE_CLE_BLEU 			26
	#define OBJET_FIXE_CLE_ROUGE 			27
	#define OBJET_RANDOM_POTION_FORCE 		28
	#define OBJET_RANDOM_ARME 				29
	#define OBJET_FIXE_PORTE_DOREE 			30
	#define OBJET_FIXE_PORTE_ROUGE 			31
	#define OBJET_FIXE_PORTE_BLEU 			32
	#define OBJET_FIXE_NOFIRE_RING 			33
	#define OBJET_RANDOM_POTION_ENERGIE 	34
	*/
	
	byte player_bouclier;
	byte player_torche;
	byte player_nb_cle_doree;
	byte player_nb_cle_rouge;
	byte player_nb_cle_bleu;
	byte player_energie_ring;
	byte player_nofire_ring;
	unsigned int player_argent;
	
	
//} s_player;

//s_player player;

typedef struct
{
	byte type;	
	byte sprno;
	byte sprno2;
	byte pv;
	byte r1,r2,r3,r4,r5;	
	byte cx,cy,c; // Pixel de colision avec le décor + résultat de collision
	byte cx2,cy2; // Pixel de colision avec le décor + résultat de collision
	byte cx3,cy3; // Pixel de colision avec le décor + résultat de collision
	byte nmiCol; // Active t'on la collision NMI ?
	char direction_x; // Dans quelle direction x + vitesse?
	char direction_y; // Dans quelle direction y + vitesse?
	byte basePattern;
	byte basePattern2;
	char r6;	// registres "interne" des ennemys
	byte base_colour;	// Couleur de base du sprite
	byte touche;	// Pour changer la couleur de l'ennemy quand il est touché
} s_ennemy;

volatile s_ennemy ennemy[MAXENNEMY];

byte animateTimer2frame;
byte timer;

byte timerInterne;
byte timerAnimation;
byte timerAnimation2;
byte ticks;

void render_gameover(void)
{
	center_string(10,"     GAME OVER     ");
	center_string(14," FINAL SCORE ");
	center_string(15,str(player_argent));
	pause();
}
/* Affiche Nb de PV, Bouclier, Armes */
void renderStat()
{
	//char *nb_cle_rouge;
	//char *nb_cle_bleu;
	//char *nb_cle_doree;
	char *bouclier;
	char *pv;
	char *ammo;
	char *deg;
	byte y;
	byte x;
	
	y=1;
	x=2;
	
	pv = str(player_pv);	
	put_char(x+2,y,251);
	put_char(x+3,y,':');
	put_char(x+4,y,pv[2]);put_char(x+5,y,pv[3]);put_char(x+6,y,pv[4]);
	
	ammo = str(player_ammo);	
	put_char(x+8,y,250);
	put_char(x+9,y,':');
	put_char(x+10,y,ammo[3]);put_char(x+11,y,ammo[4]);
		
	
	if (player_nb_cle_rouge>0) put_char(x+13,y,253); else put_char(x+13,y,255);
	if (player_nb_cle_bleu>0) put_char(x+14,y,252); else put_char(x+14,y,255);
	if (player_nb_cle_doree>0) put_char(x+15,y,254); else put_char(x+15,y,255);
		
	bouclier = str(player_bouclier);	
	put_char(x+17,y,249);
	put_char(x+18,y,':');
	put_char(x+19,y,bouclier[2]);put_char(x+20,y,bouclier[3]);put_char(x+21,y,bouclier[4]);
	
	deg = str(weapon_deg);
	put_char(x+23,y,248);
	put_char(x+24,y,':');
	put_char(x+25,y,deg[3]);put_char(x+26,y,deg[4]);
	
}


/******************************************************************/
/************ GESTION DES ENNEMY *********************************/
/*****************************************************************/
void initEnnemy(void)
{
	char i;
	for (i=0;i<MAXENNEMY;i++)
	{
		ennemy[i].type = INACTIF;
		ennemy[i].nmiCol = 0;
		ennemy[i].sprno = INACTIF;
		ennemy[i].sprno2 = INACTIF;
		ennemy[i].touche = 0;
	}
}

	/*MONSTRE_BAT
	MONSTRE_SQUELETTE
	MONSTRE_SERPENT*/
void createEnnemy(byte x,byte y,byte t,byte r1,byte r2,byte r3,byte r5,char r6)
{
	byte i;
	char spr;
	char spr2;

	/*
	s_ennemy *this_ennemy;
	byte *myEnnemy_type;	
	byte *myEnnemy_basePattern;
	byte *myEnnemy_r5;
	char *myEnnemy_direction_x;
	char *myEnnemy_direction_y;
	*/

	for (i=0;i<MAXENNEMY;i++)
	{
		/*
		this_ennemy = &ennemy[i];
		myEnnemy_type = &this_ennemy->type;
		*/
		
		//if ((*myEnnemy_type)==INACTIF)
		if (ennemy[i].type==INACTIF)
		{			
			spr = getFreeSprite();
			if (spr!=-1)
			{								
				/*
				myEnnemy_basePattern = &this_ennemy->basePattern;	
				myEnnemy_direction_x = &this_ennemy->direction_x;
				myEnnemy_direction_y = &this_ennemy->direction_y;				
				myEnnemy_r5 = &this_ennemy->r5;	
				*/
				
				ennemy[i].type = t;				
				ennemy[i].sprno = spr;
				ennemy[i].sprno2 = INACTIF;
				ennemy[i].r1 = r1;
				ennemy[i].r2 = r2;
				ennemy[i].r3 = r3;				
				//(*myEnnemy_r5) = r5;
				ennemy[i].r5 = r5;
				ennemy[i].r6 = r6;
				

				sprites[spr].colour = 15;	
				ennemy[i].base_colour = 15;
				
				//if ((*myEnnemy_type)== MONSTRE_MORT)
				if (ennemy[i].type==MONSTRE_MORT)
				{
					ennemy[i].basePattern = BASEPATTERN_MORT;
				}
				else
				if (ennemy[i].type== MONSTRE_BAT)
				{
					ennemy[i].r5 = 1;
					ennemy[i].direction_y=(y<96)?1:-1;
					ennemy[i].direction_x=(x<128)?1:-1;
					ennemy[i].basePattern = BASEPATTERN_BAT;
					ennemy[i].pv = rnd_byte(1,2);
					if (weapon_deg>4) ennemy[i].pv+=rnd_byte(0,weapon_deg);
				}
				else
				if ( (ennemy[i].type== MONSTRE_ARAIGNEE_COULEUR1) || (ennemy[i].type== MONSTRE_ARAIGNEE_COULEUR2) )
				{
					ennemy[i].r5 = 1;
					ennemy[i].direction_y = (y<96)?1:-1;
					ennemy[i].direction_x =(x<128)?1:-1;
					ennemy[i].basePattern = BASEPATTERN_ARAIGNEE;
					ennemy[i].pv = rnd_byte(1,10);
					if (weapon_deg>4) ennemy[i].pv+=rnd_byte(0,weapon_deg);
				}
				else
				if (ennemy[i].type== MONSTRE_SERPENT)
				{
					ennemy[i].direction_y=(y<96)?1:-1;
					//if (y<96) (*myEnnemy_direction_y) = 1; else (*myEnnemy_direction_y) = -1;
					if (x<128) {ennemy[i].direction_x = 1;ennemy[i].basePattern=BASEPATTERN_SERPENT_DROITE;} else {ennemy[i].direction_x = -1;ennemy[i].basePattern=BASEPATTERN_SERPENT_GAUCHE;}
					ennemy[i].pv = rnd_byte(1,3);
					if (weapon_deg>4) ennemy[i].pv+=rnd_byte(0,weapon_deg);
				}
				else
				if (ennemy[i].type== MONSTRE_SERPENT2)
				{
					ennemy[i].basePattern = BASEPATTERN_SERPENT2;
					ennemy[i].direction_y = (y<96)?1:-1;
					//if (y<96) (*myEnnemy_direction_y) = 1; else (*myEnnemy_direction_y) = -1;
					ennemy[i].direction_x = (x<128)?1:-1;
					//if (x<128) {(*myEnnemy_direction_x) = 1;} else {(*myEnnemy_direction_x) = -1;}
					ennemy[i].pv = rnd_byte(1,4);
					if (weapon_deg>4) ennemy[i].pv+=rnd_byte(0,weapon_deg);
				}
				else
				if ((ennemy[i].type== MONSTRE_SQUELETTE) || (ennemy[i].type== MONSTRE_SQUELETTE2) || (ennemy[i].type== MONSTRE_TROLL1) || (ennemy[i].type== MONSTRE_TROLL2) || (ennemy[i].type== MONSTRE_TROLL3) )
				{					
					spr2 = getFreeSprite();
					//sprites[spr2].x = sprites[spr].x;
					//sprites[spr2].y = sprites[spr].y+16;
					moveSprite(spr2,sprites[spr].x,sprites[spr].y+16);
					sprites[spr2].colour = 15;						
					ennemy[i].sprno2 = spr2;
					ennemy[i].direction_y=0;
					ennemy[i].direction_x = (x<128)?1:-1;
					//if (x<128) (*myEnnemy_direction_x) = 1; else (*myEnnemy_direction_x) = -1;
					if (ennemy[i].type== MONSTRE_SQUELETTE)
					{
						ennemy[i].basePattern=BASEPATTERN_SQUELETTE;
						ennemy[i].basePattern2=BASEPATTERN2_SQUELETTE;
						ennemy[i].pv = rnd_byte(2,5);
						if (weapon_deg>4) ennemy[i].pv+=rnd_byte(0,weapon_deg);
					} 
					else if (ennemy[i].type== MONSTRE_SQUELETTE2)
					{
						ennemy[i].basePattern=BASEPATTERN_SQUELETTE2;
						ennemy[i].basePattern2=BASEPATTERN2_SQUELETTE2;
						ennemy[i].pv = rnd_byte(2,8);
						if (weapon_deg>4) ennemy[i].pv+=rnd_byte(0,weapon_deg);
					}
					else if ( (ennemy[i].type== MONSTRE_TROLL1) || (ennemy[i].type== MONSTRE_TROLL2) || (ennemy[i].type== MONSTRE_TROLL3) )
					{						
						ennemy[i].pv = rnd_byte(4,15);
						ennemy[i].basePattern=BASEPATTERN_TROLL;
						ennemy[i].basePattern2=BASEPATTERN2_TROLL;
						ennemy[i].r5 = rnd_byte(10,50);
						sprites[spr].colour = ennemy[i].type;
						sprites[spr2].colour = ennemy[i].type;
						ennemy[i].base_colour = ennemy[i].type;
					}
					
				}
				
				sprites[spr].pattern = ennemy[i].basePattern;
				moveSprite(spr,x,y);
				//sprites[spr].x = x;
				//sprites[spr].y = y;
			}
			break;			
		}
	}
}

void destroyEnnemy(byte id)
{
	ennemy[id].type = INACTIF;	
	sprites[ennemy[id].sprno].y = INACTIF;
	if ((ennemy[id].sprno2)!=INACTIF) sprites[ennemy[id].sprno2].y = INACTIF;
	delay(1);
	ennemy[id].sprno = INACTIF;
	ennemy[id].sprno2 = INACTIF;
	ennemy[id].touche=0;
	ennemy[id].nmiCol = 0;
	ennemy[id].r1=0;
	ennemy[id].r2=0;
	ennemy[id].r3=0;
	ennemy[id].r4=0;
	ennemy[id].r5=0;	
	ennemy[id].direction_x=0;
	ennemy[id].direction_y=0;
	ennemy[id].r6=0;	
}

void destroyAllEnnemy()
{
	byte i;
	
	for (i=0;i<MAXENNEMY;i++)
	{
		destroyEnnemy(i);
	}
}

/*
char donneDirectionHasard(void)
{
	if (rnd_byte(0,100)>50) return -1; else return 1;
}*/

// !!!! R6 = direction à prendre !!!!
// 25/30 par seconde
// 1 fois, check des collisions,
// 1 fois, mouvement !
void intern_moveEnnemy(byte i)
{

	s_ennemy *this_ennemy = &ennemy[i];
	byte *myEnnemy_type = &this_ennemy->type;
	byte *myEnnemy_r1 = &this_ennemy->r1;
	byte *myEnnemy_r2 = &this_ennemy->r2;
	byte *myEnnemy_r3 = &this_ennemy->r3;	
	byte *myEnnemy_r5 = &this_ennemy->r5;
	char *myEnnemy_r6 = &this_ennemy->r6;
	byte *myEnnemy_sprno = &this_ennemy->sprno;
	byte *myEnnemy_sprno2 = &this_ennemy->sprno2;
	byte *myEnnemy_cx = &this_ennemy->cx;
	byte *myEnnemy_cy = &this_ennemy->cy;
	byte *myEnnemy_c = &this_ennemy->c;	
	byte *myEnnemy_nmiCol = &this_ennemy->nmiCol;	
	byte *myEnnemy_basePattern = &this_ennemy->basePattern;	
	byte *myEnnemy_basePattern2 = &this_ennemy->basePattern2;	
	char *myEnnemy_direction_x = &this_ennemy->direction_x;	
	char *myEnnemy_direction_y = &this_ennemy->direction_y;	

	sprite_t *this_sprite = &sprites[(*myEnnemy_sprno)];
	byte *mySprite_x = &this_sprite->x;
	byte *mySprite_y = &this_sprite->y;
	byte *mySprite_pattern = &this_sprite->pattern;
	byte *mySprite_colour = &this_sprite->colour;
	
	byte playerSprite_x;
	byte playerSprite_y;

	playerSprite_x = sprites[PLAYER_CORPS].x;
	playerSprite_y = sprites[PLAYER_CORPS].y;

	if ((timerInterne&7)==0) timerAnimation2+=4;
	if (timerAnimation2==8) timerAnimation2=0;
	timerInterne++;
	
	if (ennemy[i].touche>0) 
	{
		ennemy[i].touche--;
		(*mySprite_colour)=12;
		if (ennemy[i].sprno2!=INACTIF) sprites[ennemy[i].sprno2].colour = 12;
	}
	else
	{
		(*mySprite_colour)=ennemy[i].base_colour;
		if (ennemy[i].sprno2!=INACTIF) sprites[ennemy[i].sprno2].colour = ennemy[i].base_colour;
	}
	
	// Pas de collision dans la direction suivante, on va bouger l'ennemy
	if ((ennemy[i].c==0) && (*myEnnemy_type!=MONSTRE_MORT))
	{	
		if ((*myEnnemy_type)!=MONSTRE_SERPENT) 
		{
			(*mySprite_x)+=(*myEnnemy_direction_x);
			(*mySprite_y)+=(*myEnnemy_direction_y);	 	
		}
		else
		{
			if ((timerInterne&1)==0)
			{
				(*mySprite_x)+=(*myEnnemy_direction_x);
				(*mySprite_y)+=(*myEnnemy_direction_y);
			}
		}
	}
	
	
	// On repositionne à un endroit sans collision
	if (ennemy[i].c==1)
	{
		if (((*myEnnemy_type)==MONSTRE_TROLL1) || ((*myEnnemy_type)==MONSTRE_TROLL2) || ((*myEnnemy_type)==MONSTRE_TROLL3) ) {}
		else
		{
			(*mySprite_x)-=(*myEnnemy_direction_x);
			(*mySprite_y)-=(*myEnnemy_direction_y);		
		}
	}
	
	if ((*myEnnemy_sprno2)!=INACTIF)
	{
		sprites[(*myEnnemy_sprno2)].x = (*mySprite_x);
		sprites[(*myEnnemy_sprno2)].y = (*mySprite_y) + 16;
	}
	
	if ((*myEnnemy_r5)>0) (*myEnnemy_r5)--; // Variable commune à tout les ennemy
	
	// Calcul du prochain mouvement si nécessaire.
	if ( ((*myEnnemy_type)==MONSTRE_BAT) || ((*myEnnemy_type)==MONSTRE_ARAIGNEE_COULEUR1) || ((*myEnnemy_type)==MONSTRE_ARAIGNEE_COULEUR2))
	{
		// On décompte le nbre de mouvement
		//if ((*myEnnemy_r5)>0) (*myEnnemy_r5)--;
		// Si il y à une collision on force un changement de direction
		if ((*myEnnemy_c)==1) {(*myEnnemy_r5)=0;/*(*myEnnemy_c)=0;*/}
		
		// Si on à atteind le nombre de changement MAX, on demande un changement de direction
		if ((*myEnnemy_r5)==0)
		{
			if ((*myEnnemy_type)==MONSTRE_BAT) (*myEnnemy_r5) = 1; else (*myEnnemy_r5) = 3; // Petit changement d'IA pour les araignées
			
			// Si l'ennemi se déplaçait de manière horizontale
			if  ((*myEnnemy_direction_x)!=0)
			{
				// On va le faire aller en vertical par rappor au joueur.
				(*myEnnemy_direction_x) = 0;
				if ((*mySprite_y)>playerSprite_y) (*myEnnemy_direction_y) = -1;
				else (*myEnnemy_direction_y) = 1;
			}
			else
			{
				(*myEnnemy_direction_y) = 0;
				// On va le faire aller à l'horizontal par rappor au joueur.
				if ((*mySprite_x)>playerSprite_x) (*myEnnemy_direction_x) = -1;
				else (*myEnnemy_direction_x) = 1;
			}
		}			
	}
	else
	if (((*myEnnemy_type)==MONSTRE_SERPENT) || ((*myEnnemy_type)==MONSTRE_SERPENT2))
	{
		if ((*myEnnemy_c)==1)
		{
			(*myEnnemy_direction_x) = (rnd_byte(0,100)>50)?-1:1;
			(*myEnnemy_direction_y) = (rnd_byte(0,100)>50)?-1:1;
			if ((*myEnnemy_type)==MONSTRE_SERPENT)
			{
				if ((*myEnnemy_direction_x)==-1)(*myEnnemy_basePattern)=BASEPATTERN_SERPENT_GAUCHE; else (*myEnnemy_basePattern)=BASEPATTERN_SERPENT_DROITE;
			}
		}
	}
	else
	if ((*myEnnemy_type)==MONSTRE_SQUELETTE)
	{
				if ((*myEnnemy_c)==1)
				{
					// SENS HORAIRE
					if ((*myEnnemy_direction_x)==1) {(*myEnnemy_direction_x)=0;(*myEnnemy_direction_y)=1;}
					else
					if ((*myEnnemy_direction_y)==1) {(*myEnnemy_direction_y)=0;(*myEnnemy_direction_x)=-1;}
					else
					if ((*myEnnemy_direction_x)==-1) {(*myEnnemy_direction_x)=0;(*myEnnemy_direction_y)=-1;}
					else
					if ((*myEnnemy_direction_y)==-1) {(*myEnnemy_direction_y)=0;(*myEnnemy_direction_x)=1;}
				}
	}
	else
	if ((*myEnnemy_type)==MONSTRE_SQUELETTE2)
	{
				if ((*myEnnemy_c)==1)
				{
					// SENS ANTI-HORAIRE
					if ((*myEnnemy_direction_x)==1) {(*myEnnemy_direction_x)=0;(*myEnnemy_direction_y)=-1;}
					else
					if ((*myEnnemy_direction_y)==1) {(*myEnnemy_direction_y)=0;(*myEnnemy_direction_x)=1;}
					else
					if ((*myEnnemy_direction_x)==-1) {(*myEnnemy_direction_x)=0;(*myEnnemy_direction_y)=1;}
					else
					if ((*myEnnemy_direction_y)==-1) {(*myEnnemy_direction_y)=0;(*myEnnemy_direction_x)=-1;}
				}
	}
	if ( ((*myEnnemy_type)==MONSTRE_TROLL1) || ((*myEnnemy_type)==MONSTRE_TROLL2) || ((*myEnnemy_type)==MONSTRE_TROLL3) )
	{
		if ((*myEnnemy_r5)>0) (*myEnnemy_r5)--;
		if ((*myEnnemy_c)==1) (*myEnnemy_r5)=0;
		if ((*myEnnemy_r5)==0)
		{
			(*myEnnemy_r5) = rnd_byte(10,50);
			if  ((*myEnnemy_direction_x)!=0)
			{
				// On va le faire aller en vertical par rappor au joueur.
				(*myEnnemy_direction_x) = 0;
				(*myEnnemy_direction_y) = ((*mySprite_y)>playerSprite_y)?-1:1;
			}
			else
			{
				(*myEnnemy_direction_y) = 0;
				// On va le faire aller à l'horizontal par rappor au joueur.
				(*myEnnemy_direction_x) = ((*mySprite_x)>playerSprite_x)?-1:1;
			}
		}	
	}
	
	(*mySprite_pattern) = ((*myEnnemy_type)!=MONSTRE_MORT)?(*myEnnemy_basePattern)+timerAnimation2:(*myEnnemy_basePattern);
	if ((*myEnnemy_sprno2)!=INACTIF) sprites[(*myEnnemy_sprno2)].pattern = (*myEnnemy_basePattern2)+timerAnimation2;
	/*
	if ((*myEnnemy_type)!=MONSTRE_MORT) (*mySprite_pattern) = (*myEnnemy_basePattern)+timerAnimation2;
	else (*mySprite_pattern) = (*myEnnemy_basePattern);
	*/
	
	
	
}

void intern_checkNextMoveEnnemy(byte i)
{
	s_ennemy *this_ennemy = &ennemy[i];
	byte *myEnnemy_sprno = &this_ennemy->sprno;
	byte *myEnnemy_sprno2 = &this_ennemy->sprno2;
	byte *myEnnemy_cx = &this_ennemy->cx;
	byte *myEnnemy_cy = &this_ennemy->cy;
	byte *myEnnemy_cx2 = &this_ennemy->cx2;
	byte *myEnnemy_cy2 = &this_ennemy->cy2;
	byte *myEnnemy_cx3 = &this_ennemy->cx3;
	byte *myEnnemy_cy3 = &this_ennemy->cy3;
	byte *myEnnemy_nmiCol = &this_ennemy->nmiCol;	
	
	byte deltax,deltay,deltax1,deltay1,deltax2,deltay2;
	
	char myEnnemy_direction_x = ennemy[i].direction_x;
	char myEnnemy_direction_y = ennemy[i].direction_y;

	sprite_t *this_sprite = &sprites[(*myEnnemy_sprno)];
	byte *mySprite_x = &this_sprite->x;
	byte *mySprite_y = &this_sprite->y;
	
	deltax=0;deltay=0;
	deltax1=0;deltay1=0;
	deltax2=0;deltay2=0;
	
	// Cas des sprites 16*16
	if (((myEnnemy_direction_x)==0) && ((myEnnemy_direction_y)==-1))
	{
		deltax=2;deltay=0;
		deltax1=13;deltay1=0;
		deltax2=13;deltay2=0;		
	} else
	if (((myEnnemy_direction_x)==1) && ((myEnnemy_direction_y)==-1))
	{
		deltax=8;deltay=0;
		deltax1=15;deltay1=0;
		deltax2=15;deltay2=8;				
	} else
	if (((myEnnemy_direction_x)==1) && ((myEnnemy_direction_y)==0))
	{
		deltax=14;deltay=1;
		deltax1=14;deltay1=14;
		deltax2=14;deltay2=14;		
		if ((*myEnnemy_sprno2)!=INACTIF)
		{
				deltay1=18;
				deltay2=18;
		}		
	} else
	if (((myEnnemy_direction_x)==1) && ((myEnnemy_direction_y)==1))
	{
		deltax=14;deltay=8;
		deltax1=14;deltay1=14;
		deltax2=8;deltay2=14;		
		if ((*myEnnemy_sprno2)!=INACTIF)
		{
				deltay1=20;
				deltay2=20;
		}		
	} else
	if (((myEnnemy_direction_x)==0) && ((myEnnemy_direction_y)==1))
	{
		deltax=2;deltay=14;
		deltax1=14;deltay1=14;
		deltax2=14;deltay2=14;		
		if ((*myEnnemy_sprno2)!=INACTIF)
		{
				deltay=20;
				deltay1=20;
				deltay2=20;
		}		
	} else
	if (((myEnnemy_direction_x)==-1) && ((myEnnemy_direction_y)==1))
	{
		deltax=2;deltay=8;
		deltax1=2;deltay1=14;
		deltax2=14;deltay2=14;		
		if ((*myEnnemy_sprno2)!=INACTIF)
		{
				deltay1=20;
				deltay2=20;
		}		
	} else
	if (((myEnnemy_direction_x)==-1) && ((myEnnemy_direction_y)==0))
	{
		deltax=2;deltay=0;
		deltax1=2;deltay1=14;
		deltax2=2;deltay2=14;		
		if ((*myEnnemy_sprno2)!=INACTIF)
		{
				deltay1=18;
				deltay2=18;
		}		
	} else
	if (((myEnnemy_direction_x)==-1) && ((myEnnemy_direction_y)==-1))
	{
		deltax=2;deltay=0;
		deltax1=8;deltay1=0;
		deltax2=2;deltay2=8;		
	}
	
	(*myEnnemy_cx) = ((*mySprite_x)+deltax)>>3;
	(*myEnnemy_cy) = ((*mySprite_y)+deltay)>>3;

	(*myEnnemy_cx2) = ((*mySprite_x)+deltax1)>>3;
	(*myEnnemy_cy2) = ((*mySprite_y)+deltay1)>>3;

	(*myEnnemy_cx3) = ((*mySprite_x)+deltax2)>>3;
	(*myEnnemy_cy3) = ((*mySprite_y)+deltay2)>>3;

	(*myEnnemy_nmiCol) = 1;	
}

void moveEnnemy(void)
{
	byte i;
	for (i=0;i<MAXENNEMY;i++)
	{
		if (ennemy[i].type!=INACTIF) 
		{
			if ((timer&1)==0) intern_checkNextMoveEnnemy(i);
			else intern_moveEnnemy(i);
		}
	}
}

/******************************************************************/
/************ FIN GESTION DES ENNEMY *****************************/
/*****************************************************************/




// Charge une image Dan0 dans la dest (soit vidéo, soit buffer)
// p = pattern
// c = colortab
// n = name
// show = 1 : afficher 0 : ne pas afficher
// des : chrtab ou buffer
/*void LoadPatternAndshowAScreenDan0(char* p,char *c,char *n,char show,unsigned dest)
{
	if (show==1) dan0alt(dest,n);
	dan0alt(chrgen,p);	
	dan0alt(coltab,c);
	dan0alt(coltab+2048,c);
	dan0alt(coltab+4096,c);
	duplicate_pattern();
}*/


byte getRoomCode(byte x,byte y)
{
	return laby[(y*16)+x];
}

// Recopie une tile de h(auteur),l(argeur) du buffer qui se trouve en sx,sy
// Vers l'écran en position dx,dy
// Exemple : Pour des tiles de 4*4 en buffer
//
// T00T01T02T03T04T05T06T07
// T08T09T10T11T12T13T14T15
//
// sx = (numero_tile%8)*4
// sy = (numero_tile/8)*4;
//

 
void readContenuLaby(int roomNumber)
{
	int offset;
	offset = roomNumber<<3;
	
	//room_objstat = peekVram(offset);
	//room_objstat_tile = peekVram(offset+1);
	room_objstat = peekVram(offset+2);
	room_objstat_tile= peekVram(offset+3);
	room_mster1= peekVram(offset+4);
	room_mster2= peekVram(offset+5);
	room_mster3= peekVram(offset+6);
	room_mster4= peekVram(offset+7);
}

void writeContenuLaby(int roomNumber)
{
	int offset;
	offset = roomNumber<<3;

	//pokeVram(offset+0,room_objstat);
	//pokeVram(offset+1,room_objstat_tile);	
	pokeVram(offset+2,room_objstat);
	pokeVram(offset+3,room_objstat_tile);
	pokeVram(offset+4,room_mster1);
	pokeVram(offset+5,room_mster2);
	pokeVram(offset+6,room_mster3);
	pokeVram(offset+7,room_mster4);
	
}

byte searchFreeTile(byte n)
{
	byte r;
	byte p;
	byte sortie;
	p = rooms[n][0];
	r=0;
	sortie = 0;
		
	while (sortie==0) // A la recherche d'une salle vide
	{
		r = rnd_byte(8,26);		
		p = rooms[n][r];
		
		if ((r!=13) && (r!=14) && (r!=20) && (r!=21) && (r!=27) && (p==21))
			sortie=1	;		
	}
	return r;
}
/* Pour trouver les données de contenu de salle par rapport à un x,y de salle */
/* Offset départ = (x*4) + (y*64) */
void initContenuLaby()
{
	int i;
	int offset;
	byte r;
	
	byte tile_objet,type_objet;	// Tile qui va contenir un objet aléatoire et quel type d'objet
	byte type_monstre1;	
	byte type_monstre2;	
	byte type_monstre3;	
	byte type_monstre4;	

	SCREEN_OFF
	type_objet = 0;tile_objet=0;
	
	/*
	#define OBJET_FIXE_ENERGIE_RING 		24
	#define OBJET_FIXE_CLE_DOREE 			25
	#define OBJET_FIXE_CLE_BLEU 			26
	#define OBJET_FIXE_CLE_ROUGE 			27
	
	#define OBJET_FIXE_PORTE_DOREE 			30
	#define OBJET_FIXE_PORTE_ROUGE 			31
	#define OBJET_FIXE_PORTE_BLEU 			32
	#define OBJET_FIXE_NOFIRE_RING 			33
	
	#define OBJET_RANDOM_POTION_FORCE 		28
	#define OBJET_RANDOM_ARME 				29
	#define OBJET_RANDOM_POTION_ENERGIE 	34

	#define OBJET_RANDOM_BOUCLIER			35
	#define OBJET_FIXE_TORCHE				36
	#define OBJET_RANDOM_ARGENT				37
	
	*/
	
	/* Initialisation en VRAM du contenu des salles du labyrinthe */
	for (i=0;i<SALLE_MAX;i++)
	{
		tile_objet=0;
		type_objet=0;
		type_monstre1 = 0;		
		type_monstre2 = 0;
		type_monstre3 = 0;
		type_monstre4 = 0;		
		offset = i<<3;		
	
			/*******************************************************/
			/* Si on est dans la salle finale sans anneau anti feu */
			/* Alors afficher un effet de flamme *******************/
			/*******************************************************/
			if (i==19)
			{
				/* TODO : effet de feu */
			}
			
			/**********************************************************************************************/
			/* Salles spéciales */
			/* ----------------- */
			/* (0,0)(r15)(t7) = 0 - Porte dorée / Sortie */
			/* (5,1)(r10)(t12) = 21 - Clé bleu */
			/* (8,1)(r11)(t20) = 24 - Clé rouge*/
			/* (13,0)(r15)(t20) = 13 - Porte rouge*/
			/* (14,1)(r4)(t20) = 30 - Porte bleu*/
			/* (7,7)(r11)(t20) = 119 - Dragon / Clé dorée*/
			/* (0,10)(r12)(t15) = 160 - Torche*/
			/* (1,10)(r5)(t14) = 161 - Porte Bleu*/
			/* (2,13)(r9)(t8) = 210 - Clé rouge*/
			/* (6,9)(r11)(t19) = 150 - Clé bleu*/
			/* (13,6)(r11)(t19) = 109 - Clé bleu*/
			/* (7,11)(r15)(t20) = 183 - Porte bleu*/
			/* (7,14)(r3)(t14) = 231 - Porte bleu --> NE SERT A RIEN */
			/* (15,12)(r5)(t14) = 207 - Porte rouge*/
			/* (15,13)(r11)(t20)= 223 - anneau de résistance*/
			/* (15,0)(r9)(t8) = 15 - anneau antiflamme*/
			/************************************/
			
			//else if (i==2){tile_objet = 12;type_objet = OBJET_RANDOM_POTION_FORCE;} 
			if (i==0){tile_objet = 7;type_objet = OBJET_FIXE_PORTE_DOREE;}
			else if (i==21){tile_objet = 12;type_objet = OBJET_FIXE_CLE_BLEU;}
			else if (i==24){tile_objet = 19;type_objet = OBJET_FIXE_CLE_ROUGE;}
			else if (i==13){tile_objet = 20;type_objet = OBJET_FIXE_PORTE_ROUGE;}
			else if (i==30){tile_objet = 20;type_objet = OBJET_FIXE_PORTE_BLEU;}
			else if (i==119){tile_objet = 19;type_objet = OBJET_FIXE_CLE_DOREE;}
			else if (i==160){tile_objet = 15;type_objet = OBJET_FIXE_TORCHE;}
			else if (i==161){tile_objet = 14;type_objet = OBJET_FIXE_PORTE_BLEU;}
			else if (i==210){tile_objet = 8;type_objet = OBJET_FIXE_CLE_ROUGE;}
			else if (i==150){tile_objet = 19;type_objet = OBJET_FIXE_CLE_BLEU;}
			else if (i==183){tile_objet = 20;type_objet = OBJET_FIXE_PORTE_BLEU;}
			else if (i==109){tile_objet = 10;type_objet = OBJET_FIXE_CLE_BLEU;}
			else if (i==207){tile_objet = 14;type_objet = OBJET_FIXE_PORTE_ROUGE;}
			else if (i==223){tile_objet = 19;type_objet = OBJET_FIXE_ENERGIE_RING;}
			else if (i==15){tile_objet = 8;type_objet = OBJET_FIXE_NOFIRE_RING;}
			else
			{
				if (laby[i]!=32)
				{
					r = rnd(0,100);
					tile_objet = 0;type_objet = 0;
					if ((r>=50) && (r<55)) {tile_objet = searchFreeTile(laby[i]);type_objet = OBJET_RANDOM_POTION_FORCE;} // 5 %
					else 
					if ((r>=60) && (r<70)) {tile_objet = searchFreeTile(laby[i]);type_objet = OBJET_RANDOM_ARME;} // 10 %
					else
					if ((r>=70) && (r<80)) {tile_objet = searchFreeTile(laby[i]);type_objet = OBJET_RANDOM_POTION_ENERGIE;}	// 10 %
					else
					if ((r>=80) && (r<90)) {tile_objet = searchFreeTile(laby[i]);type_objet = OBJET_RANDOM_BOUCLIER;}	// 10 %										
					else
					if (r<30)  {tile_objet = searchFreeTile(laby[i]);type_objet = OBJET_RANDOM_ARGENT;}	// 30 %
					
				}
			}
				
			type_monstre1 = rnd_byte(1,8);
			
			if (
				((i>=128) && (i<=135)) ||
				((i>=144) && (i<=151)) ||
				((i>=160) && (i<=167)) ||
				((i>=176) && (i<=183)) ||
				((i>=192) && (i<=199)) ||
				((i>=208) && (i<=215)) ||
				((i>=224) && (i<=231)) ||
				((i>=240) && (i<=247))				
			   )	type_monstre2 = rnd_byte(0,8);

			if (
				((i>=8) && (i<=15)) ||
				((i>=24) && (i<=31)) ||
				((i>=40) && (i<=47)) ||
				((i>=56) && (i<=63)) ||
				((i>=72) && (i<=79)) ||
				((i>=88) && (i<=95)) ||
				((i>=104) && (i<=111)) ||
				((i>=120) && (i<=127))				
			   )	
			   {
				type_monstre2 = rnd_byte(0,8);
				type_monstre3 = rnd_byte(0,8);
				type_monstre4 = rnd_byte(0,8);
			   }
			   
			if (
				((i>=136) && (i<=143)) ||
				((i>=152) && (i<=159)) ||
				((i>=168) && (i<=175)) ||
				((i>=184) && (i<=191)) ||
				((i>=200) && (i<=207)) ||
				((i>=216) && (i<=223)) ||
				((i>=232) && (i<=239)) ||
				((i>=248) && (i<=255))				
			   )	
			   {
				type_monstre2 = rnd_byte(0,8);
				type_monstre3 = rnd_byte(0,8);
			   }
			   
			if (i==0)
			{
				type_monstre1 = 0;		
				type_monstre2 = 0;
				type_monstre3 = 0;
				type_monstre4 = 0;		
			}
			
			//if (i>64)  type_monstre2 = rnd_byte(0,8); else type_monstre2=0;
			//if (i>128) type_monstre3 = rnd_byte(0,8); else type_monstre3=0;
			//if (i>192) type_monstre4 = rnd_byte(0,8); else type_monstre4=0;
/*
		if (i==0)
		{
			type_monstre1 = 0;
		
			// Choisit le monstre aléatoire 2
			type_monstre2 = 0;
			type_monstre3 = 0;
			type_monstre4 = 0;
		}
		*/
		pokeVram(offset,0);		
		pokeVram(offset+1,0);	
		pokeVram(offset+2,type_objet);  // Type de bonus aléatoire
		pokeVram(offset+3,tile_objet); // Tile Position du bonus  
		pokeVram(offset+4,type_monstre1);	// Type de monstre 1		
		pokeVram(offset+5,type_monstre2);		// Type du monstre 2
		pokeVram(offset+6,type_monstre3);		
		pokeVram(offset+7,type_monstre4);		
		
		
	}	
	
	readContenuLaby(0); // Initialise les variables globales pour la 1ere salle
	
	SCREEN_ON
}

void showRoom(byte n,byte crn)
{
	byte sortie = 0;
	byte i,j;
	byte *p;
	byte t,tr,tx,ty,tx2,ty2;
	byte currentTile;
	byte ft,ft2,ft3,ft4;
		

	p = &rooms[n][0];
	
	// Emplacement aléatoire d'apparition des streums
	ft = searchFreeTile(n);
	ft2 = ft;
	while(ft2==ft) ft2 = searchFreeTile(n);
	ft3 = searchFreeTile(n);
	ft4 = ft3;
	while(ft4==ft3) ft3 = searchFreeTile(n);
	tr = searchFreeTile(n);
	
	i=0;
	j=0;
	currentTile = 0;
	fill_vram(chrtab,107,768); //cls
	//center_string(0,str(crn));
	
	while (sortie==0)
	{		
		t = (*p);			// t donne le code de la tile à affiche
		tx = (t%8)*4;		// tx donne la position x de la tile dans l'image des tiles
		ty = (t/8)*4;		// ty donne la position x de la tile dans l'image des tiles
						
		copyTileXY(tx,ty,i+2,j+2);		
		
		
			// Ennemy aléatoire !
		if ((room_mster1==0) && (rnd_byte(0,100)<10) && (tr==currentTile))
		{		
			if (rnd_byte(0,100)<50) createEnnemy((i+2)<<3,(j+2)<<3,MONSTRE_ARAIGNEE_COULEUR1,0,0,0,0,0);
			else createEnnemy((i+2)<<3,(j+2)<<3,MONSTRE_ARAIGNEE_COULEUR2,0,0,0,0,0);
		}

		if ( (currentTile == room_objstat_tile) && (room_objstat!=0) )
		{
			tx2 = (room_objstat%8)*4;
			ty2 = (room_objstat/8)*4;
			copyTileXY(tx2,ty2,i+2,j+2);		// Affiche l'objet en caractères.
		}
		else
		if ( (currentTile == ft) && (room_mster1!=0) )
		{
			createEnnemy((i+2)<<3,(j+2)<<3,room_mster1,0,0,0,0,0);
		}
		if ( (currentTile == ft2) && (room_mster2!=0) )
		{
			createEnnemy((i+2)<<3,(j+2)<<3,room_mster2,0,0,0,0,0);
		}
		if ( (currentTile == ft3) && (room_mster3!=0) )
		{
			createEnnemy((i+2)<<3,(j+2)<<3,room_mster3,0,0,0,0,0);
		}
		if ( (currentTile == ft4) && (room_mster4!=0) )
		{
			createEnnemy((i+2)<<3,(j+2)<<3,room_mster4,0,0,0,0,0);
		}
		
		currentTile++;
		p++;
		i+=4;
		if (i==28)
		{
			j+=4;
			i=0;
		}
		if (j==20) sortie=1;
	}
	
	/* Salles dans le noir */
	/***********************/
	/* 9,10,11,12,13,14,15, */
	/* 25,26,27,28,29,30,31, */
	/* 41,42,43,44,45,46,47 */
	/* 57,58,59,60,61,62,63 */
	
	if ((
	((crn>=9) && (crn<=15)) 
	|| ((crn>=25) && (crn<=31)) 
	|| ((crn>=41) && (crn<=47)) 
	|| ((crn>=57) && (crn<=63)) 	
	   ) && (player_torche==0))
	  {
		// Dans le noir !!
		fill_vram(coltab+(100*8),0,62*8);
	  }
	 else
	 {
		// dans la lumière
		if (crn==119)
		{
			if (player_nofire_ring==0) center_string(22,"THE ROOM IS BURNING"); else center_string(22,"THE FIRE RING PROTECT YOU");
			// Flammes de l'enfer !!
		}
		else
		rle2vram(CHARSET_COLORRLE,coltab);
	 }
		
	 nmi_renderStat=1;	 
}


// Sélection de la classe du joueur et initialisation de ce dernier
void chooseClass(void)
{	
	byte base_pix_x;
	byte base_pix_y;
	byte sortie;
	byte i;
	
	sortie=0;

	cls(); // ATTENTION AVEC LE CLS SEMBLE EFFACER EGALEMENT LA ZONE VRAM LIBRE ...	
	
	player_x = 150;
	player_y = 75;
	
	center_string(0,"CHOOSE YOUR HERO");
	base_pix_x = 32;
	base_pix_y = 16;
	
	// WARRIOR
	
	//sprites[5].x = base_pix_x;
	//sprites[5].y = base_pix_y;
	//sprites[5].pattern = SPATTERN28;
	//sprites[5].colour = 15;
	//sprites[6].x = base_pix_x;
	//sprites[6].y = base_pix_y+16;
	//sprites[6].pattern = SPATTERN29;
	//sprites[6].colour = 15;
	setSprite(5,base_pix_x,base_pix_y,15,SPATTERN28);
	setSprite(6,base_pix_x,base_pix_y+16,15,SPATTERN29);	
	print_at(12,4,"1 - WARRIOR");
	
	base_pix_y+=32;
	// ROGUE
	/*
	sprites[7].x = base_pix_x;
	sprites[7].y = base_pix_y;
	sprites[7].pattern = SPATTERN44;
	sprites[7].colour = 7;
	sprites[8].x = base_pix_x;
	sprites[8].y = base_pix_y+16;
	sprites[8].pattern = SPATTERN45;
	sprites[8].colour = 7;
	*/
	setSprite(7,base_pix_x,base_pix_y,7,SPATTERN44);
	setSprite(8,base_pix_x,base_pix_y+16,7,SPATTERN45);	
	print_at(12,8,"2 - THIEF");
	
	base_pix_y+=32;
	// ARCHER
	/*
	sprites[9].x = base_pix_x;
	sprites[9].y = base_pix_y;
	sprites[9].pattern = SPATTERN4;
	sprites[9].colour = 2;
	sprites[10].x = base_pix_x;
	sprites[10].y = base_pix_y+16;
	sprites[10].pattern = SPATTERN5;
	sprites[10].colour = 2;
	*/
	
	setSprite(9,base_pix_x,base_pix_y,2,SPATTERN4);
	setSprite(10,base_pix_x,base_pix_y+16,2,SPATTERN5);		
	print_at(12,12,"3 - ARCHERY");
	
	base_pix_y+=32;
	// MAGO
	/*
	sprites[11].x = base_pix_x;
	sprites[11].y = base_pix_y;
	sprites[11].pattern = SPATTERN36;
	sprites[11].colour = 11;
	sprites[12].x = base_pix_x;
	sprites[12].y = base_pix_y+16;
	sprites[12].pattern = SPATTERN37;
	sprites[12].colour = 11;
	*/
	setSprite(11,base_pix_x,base_pix_y,11,SPATTERN36);
	setSprite(12,base_pix_x,base_pix_y+16,11,SPATTERN37);			
	print_at(12,16,"4 - WIZARD");
		
	SCREEN_ON

	while (sortie==0)
	{
		if (keypad_1==1) {choice = PLAYERCLASS_WARRIOR ; sortie =1;}
		if (keypad_1==2) {choice = PLAYERCLASS_ROGUE ; sortie =1;}
		if (keypad_1==3) {choice = PLAYERCLASS_ARCHER ; sortie =1;}
		if (keypad_1==4) {choice = PLAYERCLASS_MAGICIAN; sortie =1;}
		
	}	
	for (i=5;i<13;i++) sprites[i].y=INACTIF;
	delay(1);
	SCREEN_OFF
	// Mettre ici le menu graphique de sélection de la classe
	if (choice==PLAYERCLASS_WARRIOR)
	{
		player_speed = 1;
		sprites[PLAYER_TETE].colour = 15;
		sprites[PLAYER_CORPS].colour = 15;	
		basePattern_tete_droite=SPATTERN28;		
		basePattern_corps_droite=SPATTERN29;
		basePattern_tete_gauche=SPATTERN32;
		basePattern_corps_gauche=SPATTERN33;
		put_vram(sprtab+(52*32),WARRIOR_WEAPON,4*32);		
		player_ammo_max = 8;
		player_ammo = 8;
		weapon_speed = 1;
		weapon_deg = 3;
		player_pv = 150;
		player_pv_max =  150;	
		sprites[PLAYER_WEAPON].colour = 15;		
	}
	else if (choice==PLAYERCLASS_ROGUE)
	{
		player_speed = 1;
		sprites[PLAYER_TETE].colour = 7;
		sprites[PLAYER_CORPS].colour = 7;
		basePattern_tete_droite=SPATTERN44;		
		basePattern_corps_droite=SPATTERN45;
		basePattern_tete_gauche=SPATTERN48;
		basePattern_corps_gauche=SPATTERN49;	
		put_vram(sprtab+(52*32),ROGUE_WEAPON,4*32);		
		weapon_deg = 2;
		player_ammo_max = 12;
		player_ammo = 12;
		weapon_speed = 3;
		player_pv = 100;
		player_pv_max =  100;		
		sprites[PLAYER_WEAPON].colour = 15;		
	}
	else if (choice==PLAYERCLASS_ARCHER)
	{
		player_speed = 1;
		sprites[PLAYER_TETE].colour = 2;
		sprites[PLAYER_CORPS].colour = 2;
		basePattern_tete_droite=SPATTERN4;		
		basePattern_corps_droite=SPATTERN5;
		basePattern_tete_gauche=SPATTERN8;
		basePattern_corps_gauche=SPATTERN9;	
		put_vram(sprtab+(52*32),ARCHER_WEAPON,4*32);	
		weapon_deg = 2;
		player_ammo_max = 12;
		player_ammo = 12;
		weapon_speed = 2;
		player_pv = 100;
		player_pv_max =  100;	
		sprites[PLAYER_WEAPON].colour = 10;		
	}	
	else  // MAGICIAN
	{
		player_speed = 1;
		sprites[PLAYER_TETE].colour = 11;
		sprites[PLAYER_CORPS].colour = 11;
		basePattern_tete_droite=SPATTERN36;		
		basePattern_corps_droite=SPATTERN37;
		basePattern_tete_gauche=SPATTERN40;
		basePattern_corps_gauche=SPATTERN41;		
		put_vram(sprtab+(52*32),WIZARD_WEAPON,4*32);				
		weapon_deg = 1;
		player_ammo_max = 25;
		player_ammo = 25;
		weapon_speed = 3;
		player_pv = 70;
		player_pv_max =  70;			
		sprites[PLAYER_WEAPON].colour = 6;		
	}
	
	
	player_bouclier = 0;
	player_torche = 0;
	player_nb_cle_doree = 0;
	player_nb_cle_rouge = 0;
	player_nb_cle_bleu = 0;
	player_argent = 0;
	player_energie_ring = 0;
	player_nofire_ring = 0;
	
}


void initPlayer()
{
	player_shoot_rate = 0;	// Il peut tirer
	
	sprites[PLAYER_TETE].x = player_x;
	sprites[PLAYER_TETE].y = player_y;
		
	sprites[PLAYER_CORPS].x = player_x;
	sprites[PLAYER_CORPS].y = player_y+16;
		
	player_pattern_tete=basePattern_tete_droite;
	player_pattern_corps=basePattern_corps_droite;
	sprites[PLAYER_TETE].pattern = player_pattern_tete;
	sprites[PLAYER_CORPS].pattern = player_pattern_corps;	
		
	sprites[PLAYER_HIDE1].x = player_x;
	sprites[PLAYER_HIDE1].y = INVISIBLE;
	sprites[PLAYER_HIDE1].colour = 1;
	sprites[PLAYER_HIDE1].pattern = BASEPATTERN_HIDE;
	
	sprites[PLAYER_HIDE2].x = player_x;
	sprites[PLAYER_HIDE2].y = INVISIBLE;
	sprites[PLAYER_HIDE2].colour = 1;
	sprites[PLAYER_HIDE2].pattern = BASEPATTERN_HIDE;
	
	// Initialisation de l'arme du joueur
	sprites[PLAYER_WEAPON].y = INVISIBLE;
	
}

void move_shoot()
{
	byte i,t;
	
	if (player_shoot_rate!=0)
	{	
//		for (i=0;i<weapon_speed;i++)
		{			
			// Check des collisions player_shoot / ennemy !
			if (sprites[PLAYER_WEAPON].y!=INVISIBLE)
			{
				sprites[PLAYER_WEAPON].x+=last_dirx_shoot;
				sprites[PLAYER_WEAPON].y+=last_diry_shoot;
				player_shoot_rate--;
				
				if (
						(sprites[PLAYER_WEAPON].x>226)
					||	(sprites[PLAYER_WEAPON].x<16)
					||	(sprites[PLAYER_WEAPON].y>163)
					||	(sprites[PLAYER_WEAPON].y<16)
					||	(weapon_coll == 1)
					)
					{
						sprites[PLAYER_WEAPON].y = INVISIBLE;
						player_shoot_rate=0;
					}
				
				for (i=0;i<MAXENNEMY;i++)
				{
					t = ennemy[i].type;
					if ((t!=INACTIF) && (t!=MONSTRE_MORT))
					{ 
						if (isCollision(sprites[PLAYER_WEAPON].x+6,sprites[PLAYER_WEAPON].y,16,8,sprites[ennemy[i].sprno].x+6,sprites[ennemy[i].sprno].y,16,8)==S_TRUE)
						{
							player_shoot_rate=0;
							sprites[PLAYER_WEAPON].y=INVISIBLE;		
							stop_sound(3);
							play_sound(3);
							if (weapon_deg>=ennemy[i].pv)	// On fait plus de dégats à l'ennemi qu'il n'à de PV
							{					
								if ((t != MONSTRE_SQUELETTE) && (t != MONSTRE_SQUELETTE2))
								{
									if (t==room_mster1) room_mster1 = MONSTRE_RIEN;
									else if (t==room_mster2) room_mster2 = MONSTRE_RIEN;
									else if (t==room_mster3) room_mster3 = MONSTRE_RIEN;
									else if (t==room_mster4) room_mster4 = MONSTRE_RIEN;
								}
								createEnnemy(sprites[ennemy[i].sprno].x,sprites[ennemy[i].sprno].y,MONSTRE_MORT,0,0,0,0,0);
								
								destroyEnnemy(i);
								//ennemy[i].type = INACTIF;
								//sprites[ennemy[i].sprno].y = INACTIF;
								//if ((ennemy[i].sprno2)!=INACTIF) sprites[ennemy[i].sprno2].y = INACTIF;																				
							}
							else
							{
								ennemy[i].pv-=weapon_deg;
								ennemy[i].touche=5;								
							}
						}
					}					
				}
			}			
		}				
	} 	
	else {sprites[PLAYER_WEAPON].y = INVISIBLE;player_shoot_rate=0;}
}

// Récupération du bonus
void getBonus(void)
{
	byte tx;
	byte ty;
	byte dx;
	byte dy;
	byte bonusget;
	//center_string(0,str(room_objstat));
	//pause();
	if (room_objstat==0) return;
	
	bonusget=0;
	
	
	// room_objstat_tile = n° de tile à effacer !!
	// romm_objstat = bonus récolté
	
	tx = (21%8)*4;
	ty = (21/8)*4;
	dx = ((room_objstat_tile%7)*32)/8;
	dy = ((room_objstat_tile/7)*32)/8;

	if ((room_objstat!=OBJET_FIXE_PORTE_ROUGE) && (room_objstat!=OBJET_FIXE_PORTE_BLEU) && (room_objstat!=OBJET_FIXE_PORTE_DOREE))
	{
		copyTileXY(tx,ty,dx+2,dy+2);	bonusget=1;
	}
	else
	if ((room_objstat==OBJET_FIXE_PORTE_ROUGE) && (player_nb_cle_rouge>0))
	{
		copyTileXY(tx,ty,dx+2,dy+2);	bonusget=1;
		player_nb_cle_rouge--;
	}
	else
	if ((room_objstat==OBJET_FIXE_PORTE_BLEU) && (player_nb_cle_bleu>0))
	{
		copyTileXY(tx,ty,dx+2,dy+2);	bonusget=1;
		player_nb_cle_bleu--;
	}
	else
	if ((room_objstat==OBJET_FIXE_PORTE_DOREE) && (player_nb_cle_doree>0))
	{
		copyTileXY(tx,ty,dx+2,dy+2);	bonusget=1;
		player_nb_cle_doree--; workflow=WORKFLOW_YOUWIN;
	}
	
	
			/*
		#define MESSAGE_GOLD		1
		#define MESSAGE_SHIELD		2
		#define MESSAGE_LIFEPOTION	3
		#define MESSAGE_FORCEPOTION 4
		#define MESSAGE_BLUEKEY		5
		#define MESSAGE_REDKEY		6
		#define MESSAGE_GOLDKEY		7
		#define MESSAGE_FIRERING	8
		#define MESSAGE_ENERGYRING	9
		#define MESSAGE_AMMO		10
		*/
	
	if (bonusget==1)
	{
		stop_sound(5);
		play_sound(5);
		
		if (room_objstat==OBJET_FIXE_ENERGIE_RING) {player_energie_ring+=2;nmi_message=MESSAGE_ENERGYRING;}
		if (room_objstat==OBJET_FIXE_NOFIRE_RING) {player_nofire_ring++;nmi_message=MESSAGE_FIRERING;}
		if (room_objstat==OBJET_FIXE_CLE_DOREE) {player_nb_cle_doree++;nmi_message=MESSAGE_GOLDKEY;}
		if (room_objstat==OBJET_FIXE_CLE_BLEU) {player_nb_cle_bleu++;nmi_message=MESSAGE_BLUEKEY;}
		if (room_objstat==OBJET_FIXE_CLE_ROUGE) {player_nb_cle_rouge++;nmi_message=MESSAGE_REDKEY;}
		if (room_objstat==OBJET_RANDOM_POTION_ENERGIE) {player_pv_max+=5;player_pv=player_pv_max;nmi_message=MESSAGE_LIFEPOTION;}
		if (room_objstat==OBJET_RANDOM_ARME) {player_ammo_max+=1;player_ammo=player_ammo_max;nmi_message=MESSAGE_AMMO;}
		if (room_objstat==OBJET_RANDOM_POTION_FORCE) {weapon_deg++;player_ammo_max+=1;nmi_message=MESSAGE_FORCEPOTION;}
	
		if (room_objstat==OBJET_RANDOM_BOUCLIER) {player_bouclier+=20;if (player_bouclier>200) player_bouclier = 200;nmi_message=MESSAGE_SHIELD;}
		if (room_objstat==OBJET_FIXE_TORCHE) {player_torche=1;nmi_message=MESSAGE_TORCH;}
		if (room_objstat==OBJET_RANDOM_ARGENT) 
		{
			player_argent+=10;
			nmi_message=MESSAGE_GOLD;
			if (rnd_byte(0,100)>50){ player_pv_max+=3;player_ammo_max+=1;}
		}
		
		room_objstat=0;
	}
		
	nmi_renderStat = 1;
	
}

void controlPlayer()
{
		char decalx;
		char decaly;
		byte i;
		byte deg_rate;
		byte r;
		
		player_move=0;
		
		/***********************************************************************/
		/* Si on est dans la salle finale sans l'anneau anti feu ... Ouille !! */
		/***********************************************************************/
		if ((currentRoomNumber==119) && (player_nofire_ring==0))
		{
			if (player_pv>2) player_pv-=2; else player_pv=0;
			nmi_renderStat = 1;
			if (player_pv==0) workflow = WORKFLOW_GAMEOVER;
		}
		
		/**************************/
		/* Gestion des contrôles */
		/**************************/


		if (joypad_1 & DOWN)
		{
			if (collision_pied==0) {
				player_y+=player_speed;
				//stop_sound(8);
				play_sound(8);}

			if (player_y>=171)
			{
				stop_sound(8);
				y++;
				redraw=1;
				player_y=10;
			}
			player_move=1;

			last_dirx = 0;
			last_diry = 1;			
		} else
		if (joypad_1 & UP)
		{
			if (collision_tete==0) {player_y-=player_speed;play_sound(8);}
			
			if (player_y<=2)
			{
				stop_sound(8);
				y--;
				redraw=1;
				player_y=160;
			}
			player_move=1;
		
			last_dirx = 0;
			last_diry = -1;
		} else
		if (joypad_1 & LEFT)
		{
			if (collision_gauche==0) {player_x-=player_speed;play_sound(8);}
			
			if (player_x<=2)
			{
				stop_sound(8);
				x--;
				player_x=230;
				redraw=1;
			}
			player_pattern_tete = basePattern_tete_gauche;
			player_pattern_corps = basePattern_corps_gauche;	
			player_move=1;	
			
			last_dirx = -1;
			last_diry = 0;
		} else 
		if (joypad_1 & RIGHT)
		{
			if (collision_droite==0) {player_x+=player_speed;play_sound(8);}
		
			if (player_x>=233)
			{
				stop_sound(8);
				x++;				
				player_x=3;
				redraw=1;
			}
			player_pattern_tete = basePattern_tete_droite;
			player_pattern_corps = basePattern_corps_droite;	
			player_move=1;	
			
			last_dirx = 1;
			last_diry = 0;
		}
		
		
		if ( (!(joypad_1&FIRE1)) && (!(joypad_1&FIRE2)) )
		{
			player_canshoot=1;
		}
		
		// Gestion du tir
		if (((joypad_1&FIRE1) || (joypad_1&FIRE2)) && (player_shoot_rate==0) && (player_ammo>0) && (player_canshoot==1))
		{
			player_canshoot=0;
			if ((last_dirx==0) && (last_diry==-1)) sprites[PLAYER_WEAPON].pattern = SPATTERN52;
			else
			if ((last_dirx==1) && (last_diry==0)) sprites[PLAYER_WEAPON].pattern = SPATTERN53;
			else
			if ((last_dirx==0) && (last_diry==1)) sprites[PLAYER_WEAPON].pattern = SPATTERN54;
			if ((last_dirx==-1) && (last_diry==0)) sprites[PLAYER_WEAPON].pattern = SPATTERN55;
			
			last_dirx_shoot = last_dirx*weapon_speed;
			last_diry_shoot = last_diry*weapon_speed;

			decalx=0;
			decaly=0;
			
			if ((choice==PLAYERCLASS_WARRIOR) || (choice==PLAYERCLASS_MAGICIAN))
			{
					stop_sound(2);
					play_sound(2);
			} else
			{
					stop_sound(1);
					play_sound(1);	
			}
			
			if ((last_dirx==0) && (last_diry==-1)) 
			{
				if (choice==PLAYERCLASS_WARRIOR) {decalx=0;decaly=8;}
				if (choice==PLAYERCLASS_ROGUE) {decalx=0;decaly=-8;}
				if (choice==PLAYERCLASS_ARCHER) {decalx=0;decaly=-7;}
				if (choice==PLAYERCLASS_MAGICIAN) {decalx=0;decaly=16;}
			}  /* HAUT */
			else
			if ((last_dirx==1) && (last_diry==0)) 
			{
				if (choice==PLAYERCLASS_WARRIOR) {decalx=5;decaly=13;}
				if (choice==PLAYERCLASS_ROGUE) {decalx=0;decaly=13;}
				if (choice==PLAYERCLASS_ARCHER) {decalx=10;decaly=13;}
				if (choice==PLAYERCLASS_MAGICIAN) {decalx=5;decaly=13;}
			} /* DROITE */
			else
			if ((last_dirx==0) && (last_diry==1)) 
			{
				if (choice==PLAYERCLASS_WARRIOR) {decalx=0;decaly=25;}
				if (choice==PLAYERCLASS_ROGUE) {decalx=0;decaly=18;}
				if (choice==PLAYERCLASS_ARCHER) {decalx=0;decaly=18;}
				if (choice==PLAYERCLASS_MAGICIAN) {decalx=0;decaly=16;}
			} /* BAS */
			else
			if ((last_dirx==-1) && (last_diry==0)) 
			{
				if (choice==PLAYERCLASS_WARRIOR) {decalx=-5;decaly=13;}
				if (choice==PLAYERCLASS_ROGUE) {decalx=5;decaly=13;}
				if (choice==PLAYERCLASS_ARCHER) {decalx=0;decaly=13;}
				if (choice==PLAYERCLASS_MAGICIAN) {decalx=-5;decaly=13;}
				
			} /* GAUCHE */
			
			sprites[PLAYER_WEAPON].x = player_x + decalx;				
			sprites[PLAYER_WEAPON].y = player_y + decaly;			
			//sprites[PLAYER_WEAPON].colour = 5;

			player_shoot_rate = shoot_rate_def[choice];			

			player_ammo--;
			nmi_renderStat=1;
		}
		
		if (player_move==1)
		{
			sprites[PLAYER_TETE].pattern = player_pattern_tete+animateTimer2frame;
			sprites[PLAYER_CORPS].pattern = player_pattern_corps+animateTimer2frame;
		}
		else
		{
			sprites[PLAYER_TETE].pattern = player_pattern_tete;
			sprites[PLAYER_CORPS].pattern = player_pattern_corps;
		}
		
		moveSprite(PLAYER_TETE,player_x,player_y);
		//sprites[PLAYER_TETE].x = player_x;
		//sprites[PLAYER_TETE].y = player_y;		
		//sprites[PLAYER_TETE].colour = 6;

		moveSprite(PLAYER_CORPS,player_x,player_y+16);
		//sprites[PLAYER_CORPS].x = player_x;
		//sprites[PLAYER_CORPS].y = player_y+16;	
		//sprites[PLAYER_CORPS].colour = 6;
		
		// Positionnement des blocs de cache
		if (sprites[PLAYER_TETE].x<32) 
		{	
			moveSprite(PLAYER_HIDE1,0,player_y);
			//sprites[PLAYER_HIDE1].x=0;
			//sprites[PLAYER_HIDE1].y=player_y;
			
			moveSprite(PLAYER_HIDE2,0,player_y+16);
			//sprites[PLAYER_HIDE2].x=0;
			//sprites[PLAYER_HIDE2].y=player_y+16;
		}
		else if (sprites[PLAYER_TETE].x>226) 
		{
			moveSprite(PLAYER_HIDE1,240,player_y);
			//sprites[PLAYER_HIDE1].x=240;
			//sprites[PLAYER_HIDE1].y=player_y;
			
			moveSprite(PLAYER_HIDE2,240,player_y+16);
			//sprites[PLAYER_HIDE2].x=240;
			//sprites[PLAYER_HIDE2].y=player_y+16;		
		}
		else if (sprites[PLAYER_TETE].y>147) 
		{
			moveSprite(PLAYER_HIDE1,player_x,INVISIBLE);
			//sprites[PLAYER_HIDE1].x=player_x;
			//sprites[PLAYER_HIDE1].y=INVISIBLE;
			
			moveSprite(PLAYER_HIDE2,player_x,176);
			//sprites[PLAYER_HIDE2].x=player_x;
			//sprites[PLAYER_HIDE2].y=176;		
		}
		else
		{
			sprites[PLAYER_HIDE1].y=INVISIBLE;
			sprites[PLAYER_HIDE2].y=INVISIBLE;
		}

		/* CHECK DES COLLISION AVEC ENNEMY */
		for (i=0;i<MAXENNEMY;i++)
		{
			if ((ennemy[i].type!=INACTIF) && (ennemy[i].type!=MONSTRE_MORT))
			{
				if (isCollision(sprites[PLAYER_CORPS].x,sprites[PLAYER_CORPS].y,16,16,sprites[ennemy[i].sprno].x,sprites[ennemy[i].sprno].y,16,16)==S_TRUE)
				{
					if (player_bouclier>0)	// Si on à une charge de bouclier
					{
						if ((cpt&3)==0)
						{
							player_bouclier--;	// On décrémente le bouclier
							stop_sound(4);
							play_sound(4);
							nmi_renderStat=1;
						}
					}
					else	// Sinon on décrément l'énergie
					{
						if (player_energie_ring==1) deg_rate=7; else deg_rate=3;	// Si on à l'énergie ring, on perd moins vite
					
						if ((cpt&deg_rate)==0)
						{
							stop_sound(4);
							play_sound(4);
							if (player_pv>0) player_pv--;
							else workflow = WORKFLOW_GAMEOVER;
							nmi_renderStat=1;
						}					
					
					
					}
				}
			}
			else if (ennemy[i].type==MONSTRE_MORT)
			{
				if (isCollision(sprites[PLAYER_CORPS].x,sprites[PLAYER_CORPS].y,16,16,sprites[ennemy[i].sprno].x,sprites[ennemy[i].sprno].y,16,16)==S_TRUE)
				{
					stop_sound(5);
					play_sound(5);
					destroyEnnemy(i);
					r=rnd_byte(0,100);
					
								/*
		#define MESSAGE_GOLD		1
		#define MESSAGE_SHIELD		2
		#define MESSAGE_LIFEPOTION	3
		#define MESSAGE_FORCEPOTION 4
		#define MESSAGE_BLUEKEY		5
		#define MESSAGE_REDKEY		6
		#define MESSAGE_GOLDKEY		7
		#define MESSAGE_FIRERING	8
		#define MESSAGE_ENERGYRING	9
		#define MESSAGE_AMMO		10
		*/
		
		
					if (r<=25) {player_argent+=rnd_byte(1,20);nmi_renderStat=1;nmi_message=MESSAGE_GOLD;}		// Argent
					else if ((r>25) && (r<=50)) {player_pv+=rnd_byte(10,20);if (player_pv>player_pv_max) player_pv=player_pv_max;nmi_renderStat=1;nmi_message=MESSAGE_LIFEPOTION;}	// Point de vie
					else if ((r>50) && (r<=75)) {player_ammo+=rnd_byte(1,5);if (player_ammo>player_ammo_max) player_ammo=player_ammo_max;nmi_renderStat=1;nmi_message=MESSAGE_AMMO;}	// Armes
					else if (r>75) {player_bouclier+=rnd_byte(10,20);if (player_bouclier>200) player_bouclier=200;nmi_renderStat=1;nmi_message=MESSAGE_SHIELD;}	// Bouclier
				}				
			}
		}
		
}


void main(void)
{		
	set_snd_table(snd_table);
	stop_music();
	screen_mode_2_text();
	workflow = WORKFLOW_TITLESCREEN;

	
	
	/* INITIALISATIONS OBLIGATOIRES */

	while(1)
	{
		if (workflow==WORKFLOW_INGAME)
		{
			/* BOUCLE PRINCIPALE */
			cpt++;
			ticks=0;
			// On entre dans une nouvelle salle
			if (redraw==1)
			{
				delay(1); // Attend la fin de la nmi
				SCREEN_OFF
				destroyAllEnnemy();		// Mise à 0 des ennemys
				oldRoomNumber = currentRoomNumber;	// On garde en mémoire le n° de la salle que l'on quitte
				currentRoomNumber = x + y*16;	// On calule le n° de la nouvelle salle
				redraw = 0;
			
				/* Ecrit ce qui à changé dans l'ancienne pièce */
				writeContenuLaby(oldRoomNumber);			
				/* Récupère les objets actifs de la pièce courante */
				readContenuLaby(currentRoomNumber);
				/* Affiche graphiquement la pièce */
				showRoom(getRoomCode(x,y),currentRoomNumber);
			
				SCREEN_ON
				delay(1);	// Attend la fin de la nmi
			}	
			moveEnnemy();
		
			// Gestion des mouvements du joueur
			controlPlayer();
			//if (player_pv<200) player_pv=200;
			move_shoot();
		
			if (ticks==0) delay(1);
		
			timer++;
			if ((timer&7)==0) animateTimer2frame+=8;
			if (animateTimer2frame==16) animateTimer2frame = 0;
		}
		else if (workflow==WORKFLOW_GAMEOVER)
		{
			render_gameover();
			workflow = WORKFLOW_TITLESCREEN;
		}
		else if (workflow==WORKFLOW_YOUWIN)
		{
			render_gameover();
			workflow = WORKFLOW_TITLESCREEN;
		}
		else 		if (workflow==WORKFLOW_TITLESCREEN)
		{
			workflow = WORKFLOW_CHOOSECLASS;
		}
		else if (workflow==WORKFLOW_CHOOSECLASS)
		{
			delay(1);
			SCREEN_OFF			
			cpt=0;
			nmi_renderStat=0;
			nmi_message=0;
			player_canshoot=1;
			load_patternrle(CHARSET_PATTERNRLE);
			rle2vram(CHARSET_COLORRLE,coltab);

			LoadPatternAndshowAScreen(CHARSET_PATTERNRLE,CHARSET_COLORRLE,CHARSET_NAMERLE,1,buffer);
			LoadPatternAndshowAScreen(CHARSET_PATTERNRLE,CHARSET_COLORRLE,CHARSET_NAMERLE,0,chrtab);
			rle2vram(SPATTERNRLE,sprtab);	
	
			initSprites();
			last_dirx=1; 
			last_diry=0;
	
			x = 0;
			y = 0;
			animateTimer2frame=0;
			timer=0;
			chooseClass();		
			initContenuLaby();
			initEnnemy();

			/* FIN INITIALISATIONS OBLIGATOIRES */
			initPlayer();
			SCREEN_ON
			delay(1);
			
			redraw=1;
			oldRoomNumber=0;
			currentRoomNumber=0;
			/**********************************************************************************************/
			/* Salles spéciales */
			/* ----------------- */
			/* (0,0)(r15)(t7) = 0 - Porte dorée / Sortie */
			/* (5,1)(r10)(t12) = 21 - Clé bleu */
			/* (8,1)(r11)(t20) = 24 - Clé rouge*/
			/* (13,0)(r15)(t20) = 13 - Porte rouge*/
			/* (14,1)(r4)(t20) = 30 - Porte bleu*/
			/* (7,7)(r11)(t20) = 119 - Dragon / Clé dorée*/
			/* (0,10)(r12)(t15) = 160 - Torche*/
			/* (1,10)(r5)(t14) = 161 - Porte Bleu*/
			/* (2,13)(r9)(t8) = 210 - Clé rouge*/
			/* (6,9)(r11)(t19) = 150 - Clé bleu*/
			/* (13,6)(r11)(t19) = 109 - Clé bleu*/
			/* (7,11)(r15)(t20) = 183 - Porte bleu*/
			/* (7,14)(r3)(t14) = 231 - Porte bleu --> NE SERT A RIEN */
			/* (15,12)(r5)(t14) = 207 - Porte rouge*/
			/* (15,13)(r11)(t20)= 223 - anneau de résistance*/
			/* (15,0)(r9)(t8) = 15 - anneau antiflamme*/
			/************************************/
			x=0;y=0;
			workflow = WORKFLOW_INGAME;
		} 
		
	}
}

void nmi() 
{
	byte k;
	
	s_ennemy	*myEnnemy;
	byte		*myEnnemy_type;
	byte		*myEnnemy_nmiCol;
	byte		*myEnnemy_c;
	byte		*myEnnemy_cx;
	byte		*myEnnemy_cy;
	byte		*myEnnemy_cx2;
	byte		*myEnnemy_cy2;
	byte		*myEnnemy_cx3;
	byte		*myEnnemy_cy3;
	char		myEnnemy_directionx;
	char		myEnnemy_directiony;
	byte 		cx,cy,cx2,cy2,cx3,cy3;
	byte 		s,y,x;
	byte 		wc;
	byte 		i;	

	update_music();
	++ticks;

				
	if (nmi_renderStat==1)
	{
		nmi_renderStat=0;
		renderStat();
	}
	
	if (nmi_message!=0)
	{
		y=22;
		s=nmi_message;
		nmi_message=0;		
		for (x=0;x<32;x++)  put_char(x,y,107);
		
		/*
		#define MESSAGE_GOLD		1
		#define MESSAGE_SHIELD		2
		#define MESSAGE_LIFEPOTION	3
		#define MESSAGE_FORCEPOTION 4
		#define MESSAGE_BLUEKEY		5
		#define MESSAGE_REDKEY		6
		#define MESSAGE_GOLDKEY		7
		#define MESSAGE_FIRERING	8
		#define MESSAGE_ENERGYRING	9
		#define MESSAGE_AMMO		10
		*/
		
		if (s==MESSAGE_GOLD) center_string(y,"GOLD FOUND");
		else if (s==MESSAGE_SHIELD) center_string(y,"SHIELD FOUND");
		else if (s==MESSAGE_LIFEPOTION) center_string(y,"LIFE POTION FOUND");
		else if (s==MESSAGE_FORCEPOTION) center_string(y,"FORCE POTION FOUND");
		else if (s==MESSAGE_BLUEKEY) center_string(y,"BLUE KEY FOUND");
		else if (s==MESSAGE_REDKEY) center_string(y,"RED KEY FOUND");
		else if (s==MESSAGE_GOLDKEY) center_string(y,"GOLD KEY FOUND");
		else if (s==MESSAGE_FIRERING) center_string(y,"FIRE RING FOUND");
		else if (s==MESSAGE_ENERGYRING) center_string(y,"DEFENSE RING FOUND");
		else if (s==MESSAGE_AMMO) center_string(y,"AMMO FOUND");				
		else if (s==MESSAGE_TORCH) center_string(y,"TORCH FOUND");	
		else if (s==MESSAGE_NULL) {for (x=0;x<32;x++)  put_char(x,y,107);}
	}
	
	showSprites();
	
	for (k=0;k<MAXENNEMY;k++)
	{
		myEnnemy = &ennemy[k];
		myEnnemy_type = &myEnnemy->type;
		myEnnemy_nmiCol = &myEnnemy->nmiCol;
		
		if ( ((*myEnnemy_type)!=INACTIF) && ((*myEnnemy_nmiCol)==1) )
		{
			myEnnemy_c = &myEnnemy->c;
			myEnnemy_cx = &myEnnemy->cx;
			myEnnemy_cy = &myEnnemy->cy;		
			myEnnemy_cx2 = &myEnnemy->cx2;
			myEnnemy_cy2 = &myEnnemy->cy2;		
			myEnnemy_cx3 = &myEnnemy->cx3;
			myEnnemy_cy3 = &myEnnemy->cy3;		
			myEnnemy_directionx = ennemy[k].direction_x;
			myEnnemy_directiony = ennemy[k].direction_y;
			cx = (*myEnnemy_cx);
			cy = (*myEnnemy_cy);
			cx2 = (*myEnnemy_cx2);
			cy2 = (*myEnnemy_cy2);
			cx3 = (*myEnnemy_cx3);
			cy3 = (*myEnnemy_cy3);

			
			/*
			if  (
				(*myEnnemy_type==MONSTRE_SQUELETTE) || 
				(*myEnnemy_type==MONSTRE_SQUELETTE2) ||
				(*myEnnemy_type==MONSTRE_TROLL1) ||
				(*myEnnemy_type==MONSTRE_TROLL2) ||
				(*myEnnemy_type==MONSTRE_TROLL3)
				)
			{
					if ((myEnnemy_directiony)>0) cy += 1;
			}*/
				
			(*myEnnemy_nmiCol)=0;
			(*myEnnemy_c) = 0;
			if ((get_char_protected(cx,cy)!=107) || (get_char_protected(cx2,cy2)!=107) || (get_char_protected(cx3,cy3)!=107))
				(*myEnnemy_c) = 1; 

				if (((*myEnnemy_cx)<=3) || ((*myEnnemy_cx)>=30) || ((*myEnnemy_cy)>=22) || ((*myEnnemy_cy)<=1))(*myEnnemy_c) = 1;
				
		}
	}
		if ( (player_y<160) && (player_x<240) && (player_x>0) && (player_y>0) )
		{
			get_bkgrnd(&analyze, (player_x)>>3, (player_y)>>3, 2, 4);
			//put_frame(&analyze,0,0,2,4);
		
			for (i=0;i<8;i++)
			{
				if ((analyze[i]>161) && (analyze[i]<240)) 
				{
					if (joypad_1 & RIGHT)
					{
						if (((analyze[1]>199) && (analyze[1]<224)) ||
						((analyze[3]>199) && (analyze[3]<224)) ||
						((analyze[5]>199) && (analyze[5]<224)) ||
						((analyze[7]>199) && (analyze[7]<224)) )
						{
							player_x-=player_speed;
						}
					}
					if (joypad_1 & LEFT)
					{
						if (((analyze[0]>199) && (analyze[0]<224)) ||
						((analyze[2]>199) && (analyze[2]<224)) ||
						((analyze[4]>199) && (analyze[4]<224)) ||
						((analyze[6]>199) && (analyze[6]<224)) )
						{
						player_x+=player_speed;
						}
					}
					getBonus();
					break;
				}
			}
		}
		
		if ( (joypad_1 & DOWN))
		{
			c1x = (player_x+4)>>3;
			c1y = (player_y+32)>>3;
			c1 = get_char_protected(c1x,c1y);
			c2x = (player_x+12)>>3;
			c2y = (player_y+32)>>3;
			c2 = get_char_protected(c2x,c2y);

			if (((c1>32) && (c1<91)) || ((c2>32) && (c2<91)))
				nmi_message = MESSAGE_NULL;
			
			//if ( (c1!=107) || (c2!=107) )
			if ((((c1>=100) && (c1<=106)) || ((c1>=108) && (c1<=161)) ||(c1>=240) )
			|| (((c2>=100) && (c2<=106)) || ((c2>=108) && (c2<=161))  ||(c2>=240) ))

			{
					collision_pied = c1y;
					collision_pied_valeur=c1;
			}
			else
				{collision_pied=0;}
										
		}
		else
		if ( (joypad_1 & UP))
		{
			c1x = (player_x+4)>>3;
			c1y = (player_y+7)>>3;
			c1 = get_char_protected(c1x,c1y);
			c2x = (player_x+12)>>3;
			c2y = (player_y+7)>>3;		
			c2 = get_char_protected(c2x,c2y);

			// Touche t'on les caractères des stats ?
			if (((((c1>33) && (c1<90)) || ((c2>33) && (c2<90))) || (c1>247) || (c2>247) ))
			{
				for (x=0;x<32;x++)  put_char(x,1,107);
			}
			
			//if ( (c1!=107) || (c2!=107) ) 
			if ((((c1>=100) && (c1<=106)) || ((c1>=108) && (c1<=161)) ||(c1>=240) )
			|| (((c2>=100) && (c2<=106)) || ((c2>=108) && (c2<=161))  ||(c2>=240) ))
			{
				
					collision_tete = c1y;
					collision_tete_valeur=c1;
			}
			else
			{
				collision_tete=0;
			}
			

		}
	
		if ( (joypad_1 & LEFT))
		{
			c1x = (player_x+1)>>3;
			c1y = (player_y+8)>>3;
			c1 = get_char_protected(c1x,c1y);
			c2x = (player_x+1)>>3;
			c2y = (player_y+30)>>3;		
			c2 = get_char_protected(c2x,c2y);
			
			//if ( (c1!=107) || (c2!=107) )
			if ((((c1>=100) && (c1<=106)) || ((c1>=108) && (c1<=161)) ||(c1>=240) )
			|| (((c2>=100) && (c2<=106)) || ((c2>=108) && (c2<=161))  ||(c2>=240) ))
				{collision_gauche = c1y;}
			else
				{collision_gauche=0;}

		}
		else
		if ( (joypad_1 & RIGHT))
		{
			c1x = (player_x+14)>>3;
			c1y = (player_y+8)>>3;
			c1 = get_char_protected(c1x,c1y);
			c2x = (player_x+14)>>3;
			c2y = (player_y+30)>>3;		
			c2 = get_char_protected(c2x,c2y);
			//if ( (c1!=107) || (c2!=107) )
			if ((((c1>=100) && (c1<=106)) || ((c1>=108) && (c1<=161)) ||(c1>=240) )
			|| (((c2>=100) && (c2<=106)) || ((c2>=108) && (c2<=161))  ||(c2>=240) ))
				{collision_droite = c1y;}
			else
				{collision_droite=0;}
						

		}	

		if (sprites[PLAYER_WEAPON].y!=INVISIBLE)
		{
			wc = get_char_protected((sprites[PLAYER_WEAPON].x+9)>>3,(sprites[PLAYER_WEAPON].y+9)>>3);
			if (wc!=107) weapon_coll = 1;
			else weapon_coll = 0;
		}
		else weapon_coll = 0;
		
		if (currentRoomNumber==119)
		{
			if ((timerInterne&1) == 0 ) fill_vram(coltab+(107*8),128,8); else fill_vram(coltab+(107*8),0,8);
		}

}