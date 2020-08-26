#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define TAILLE_MAX 1000
typedef
struct ch
{
    int num;
    int type;
    int prix;
    int fix;
    int status;
struct reserv *res;
struct ch *next;
} ch;
struct reserv
{
    char nom[TAILLE_MAX];
    int datedebut;
    int datefin;
    struct reserv *next;
} ;
struct hotel
{
    char nomh[100];
    char ville[100];
    int cap;
    int lib;
    int inf;
    int sup;
    int fix ;
    struct ch *tete1;
    struct hotel *next;
};
typedef struct listeABC
{
    char i;
    int nombr;
    struct hotel *tete;
    struct listeABC *next;
}listeABC;

struct listeABC *nliste(int n);
struct listeABC *charg();
struct ch *cre(int a,int b,int nomb);
void affich(struct listeABC *tete);
void recupere_date(int *datd,int *datf);
int compare_date(int d ,int f ,int dd, int ff);
void existe_num (struct hotel *tete , int i , struct ch  **pp);
void ajouter_reservation(struct listeABC *tete);
void existe_hotel(struct listeABC *tete,char nomhotel[TAILLE_MAX],struct hotel **p);
void suprime_reservation(struct listeABC *tete ) ;
void suprime_maillon(struct ch *tete , struct reserv *sup);
void recupere_hotel(struct listeABC *tete , struct hotel **p);
void recupere_num(struct hotel *tete , struct ch **p) ;
void existe_nom(struct reserv *tete ,char nom[TAILLE_MAX] , struct reserv **p);
void menu();
void modifier_reservation(struct listeABC *t);
void lebiration(struct listeABC *tete);
void sauv(struct listeABC *tete);
struct listeABC *ajouthotel(struct listeABC *tete);
struct listeABC *supphotel(struct listeABC *tete);
int cmpstr(char d[100],char s[100],int nb);

