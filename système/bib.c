#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include "bib.h"
#include "conio.h"


/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------                                 -------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/
/**--------------------------------------------------------------------------------------------------------------------------------**/


struct listeABC *nliste(int n)
{
    FILE *fil;
    fil=fopen("ABC.txt","r+");
    struct listeABC *l,*p,*tete;
    tete =  malloc(sizeof(struct listeABC));
    l=tete;
    tete->i=fgetc(fil);
   for(int j=1;j<n;j++)
    {
        p= malloc(sizeof(struct listeABC));
        p->i=fgetc(fil);
        l->tete=NULL;
        l->next=p;
        l=p;
    }
    l->next= NULL ;

    return tete;
}

struct listeABC *charg()
{
    FILE *fich;
    fich=fopen("hotel.txt","rw");
    struct listeABC *tete;

    tete=nliste(27);
struct listeABC *p;
    p=tete;
    char f[100];
while (fgets(f,100,fich)!=NULL)
{
    char c;int nh,nb,nu,cp,i;char ff[100];
    c=fgetc(fich);
    fscanf(fich,"%d\n",&nh);

while (c!=p->i)
    {
        p=p->next;
    }
    p->nombr=nh;
char s[100];
    struct hotel *l,*g;
    struct ch *f;
    struct reserv *r,*x,*w;
    p->tete= malloc(sizeof(struct hotel));
    l=p->tete;
    int cpt=0;
while ((fich!=EOF)&&(cpt<(nh)))
{
            cpt=cpt+1;
                    if(cpt==1)
                       {
                            fscanf(fich,"%s\n",&p->tete->nomh);
                             fscanf(fich,"%s\n",&p->tete->ville);
                            fscanf(fich,"%d\n",&(p->tete)->cap);
                            fscanf(fich,"%d\n",&(p->tete)->fix);(p->tete)->lib=(p->tete)->fix;
                            fscanf(fich,"%d\n",&(p->tete)->inf);
                            fscanf(fich,"%d\n",&(p->tete)->sup);
                            p->tete->tete1=cre((p->tete)->inf,(p->tete)->sup,(p->tete)->cap);
                            l=p->tete;
                            i=0;
                    while (i<(p->tete->cap)-(p->tete->fix))
                    {
                        i=i+1;
                        fscanf(fich,"%d &",&nu);
                        f=p->tete->tete1;
                        while (f->num!=nu)
                                      {
                                        f=f->next;
                                       }
                                       f->fix=1;
                                       fscanf(fich," %d &",&f->type);
                                       fscanf(fich," %d &",&f->prix);
                                       fscanf(fich," %d\n",&f->status);
                                cp=0;
                                 while (cp<f->status)
                                  {

                                         cp=cp+1;
                                       if (cp==1)
                                          {

                                               r=malloc(sizeof(struct reserv));
                                                f->res=r;
                                                fscanf(fich,"%s\n%d & %d\n",&r->nom,&r->datedebut,&r->datefin);
                                                x=f->res;
                                          }
                                     else
                                          {
                                               r=malloc(sizeof(struct reserv));
                                                fscanf(fich,"%s\n%d & %d\n",&r->nom,&r->datedebut,&r->datefin);
                                                x->next=r;
                                                x=r;
                                          }

                                      }
                                x->next=NULL;

                          }
                        }

                    else
                      {
                              g=malloc(sizeof(struct hotel));
                              fscanf(fich,"%s\n",&s);
                              strcpy(g->nomh,s);
                              fscanf(fich,"%s\n",&g->ville);
                               fscanf(fich,"%d\n",&g->cap);
                               fscanf(fich,"%d\n",&g->lib);g->fix=g->lib;
                               fscanf(fich,"%d\n",&g->inf);
                               fscanf(fich,"%d\n",&g->sup);
                               g->tete1=cre(g->inf,g->sup,(p->tete)->cap);
                               f=g->tete1;i=0;
                    while (i<(g->cap)-(g->fix))
                    {
                        i=i+1;
                        fscanf(fich,"%d &",&nu);
                        f=g->tete1;
                               while (f->num!=nu)
                                      {
                                        f=f->next;
                                       }

                                fscanf(fich," %d &",&f->type);
                                fscanf(fich," %d &",&f->prix);
                                fscanf(fich," %d\n",&f->status);
                                cp=0;
                                 while (cp<nb)
                                  {
                                        cp=cp+1;
                                       if (cp==1)
                                          {
                                               r=malloc(sizeof(struct reserv));
                                                f->res=r;
                                                fscanf(fich,"%s\n%d & %d\n",&r->nom,&r->datedebut,&r->datefin);
                                                x=f->res;
                                          }
                                     else
                                          {
                                               r=malloc(sizeof(struct reserv));
                                                 fscanf(fich,"%s\n%d & %d\n",&r->nom,&r->datedebut,&r->datefin);
                                                  x->next=r;
                                                  x=r;
                                          }

                                      }
                                x->next=NULL;

                          }
                 l->next=g;
                 l=g;
                }
}
l->next=NULL;
}
p->next=NULL;
p=tete;
while (p!=NULL)
{
    if (p->tete==NULL)
    {
        p->nombr=0;
    }
    p=p->next;
}
fclose(fich);
return tete;
}
struct ch *cre(int a,int b,int nomb)
{
    struct ch *l,*p,*tete;
    tete =  malloc(sizeof(struct ch));
    l=tete;
    int r,i,fact;
    tete->num=1;
    i=2;
    tete->type=fact%2;
    r=3;
    tete->fix=0;tete->status=0;
    tete->res=NULL;
tete->prix=a+r%(b-a);
    for(int j=1;j<nomb;j++)
    {
        p= malloc(sizeof(struct ch));
        p->num=j+1;fact=i+r;i=r;r=fact;
        p->type=fact%2;
        p->fix=0;p->status=0;
        p->res=NULL;
        if (p->type==1)
        {p->prix=a+(fact%(b-a))*2;}
        else
        {p->prix=a+fact%(b-a);}
        l->next=p;if (p->prix<0){p->prix=-p->prix;}
        l=p;
    }
    l->next= NULL ;
    return tete;
}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void affich(struct listeABC *tete)
{
    struct hotel *q ;
    struct ch *l ;
    struct reserv *m ;
        struct listeABC *p ;
     p=tete ;
      while(p!=NULL)
      {
          q = p->tete ;
      while(q!=NULL)
      {
       l = q->tete1 ;
      while (l!=NULL)
      {
          m = l->res ;
          int cpt = 1 ;
          while (m!=NULL)
          {
              if (cpt==1)
{
         printf("LE NOM DE HOTEL [%s\n",q->nomh);
         printf("LA CHAMBRE:__[%d]__a[%d] reservastion_",l->num,l->status);
         printf("LE TYPE:__[%d]__",l->type);
         printf("LE PRIX:__[%d $]__\n",l->prix);
             cpt=0; }
         printf("..%s\n",m->nom);
          m=m->next ;
          }
          l=l->next ;
      }
      q=q->next ;
      }
      p=p->next ;
      }
}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void recupere_date(int *datd,int *datf)
{
    int jour , mois , anne ,m,j,a, fini =1 ;
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);
     j = instant.tm_mday ;
     m = instant.tm_mon+1 ;
     a = instant.tm_year+1900 ;
                      gotoxy(38,28);printf("                                            ");
                      gotoxy(37,29);printf("                                            ");
                      gotoxy(34,30);printf("                                            ");
                      gotoxy(38,33);printf("                                            ");
                      gotoxy(38,34);printf("                                            ");
                      gotoxy(38,35);printf("                                            ");
     textcolor(YELLOW);
     gotoxy(5,27);
      printf("Entrez la date du debut\n");
                gotoxy(7,28);
                textcolor(YELLOW);
     printf("Entrez l'anne sous forme aaaa:\n");
      gotoxy(7,29);
     printf("Entrez le mois sous forme mm:");
     gotoxy(7,30);
     printf("Entrez jour sous forme jj:");
     gotoxy(38,28);
    textcolor(WHITE);
     scanf("%d",&anne);
     while ((anne<a) || (anne>a+5))
     {
         textcolor(LIGHTRED);
         gotoxy(45,28);
         printf("Erreur!\n");
         getch();gotoxy(38,28);printf("                                            ");
         textcolor(WHITE);
         gotoxy(38,28);
     scanf("%d",&anne);
     }
     gotoxy(37,29);
    textcolor(WHITE);
     scanf("%d",&mois);
     while ((mois<0) || (mois>12)||((anne==a)&&(mois<m)))
     {
         textcolor(LIGHTRED);
            gotoxy(40,29);
         if((anne==a)&&(mois<m))
         {printf("Erreur ce mois est d\202ja passer\n ");}
          else{ printf("EROOR !\n");}
     getch();gotoxy(37,29);printf("                                            ");
            gotoxy(37,29);
             textcolor(WHITE);
           scanf("%d",&mois);
     }
     gotoxy(34,30);
    textcolor(WHITE);
     scanf("%d",&jour);
     while ((jour<1) || ((jour<j)&&(anne==a)&&(mois==m))||(jour>31))
     {
         textcolor(LIGHTRED);
            gotoxy(40,30);
        if((jour<j)&&(anne==a)&&(mois==m)){ printf("Ce jour est deja passer\n");}
        else{ printf("EROOR\n");}
             getch();gotoxy(34,30);printf("                                              ");
        gotoxy(34,30);
            textcolor(WHITE);
     scanf("%d",&jour);
     }
                anne = anne *10000 ;
                mois=mois*100;
               (*datd) = (anne+jour+mois ) ;
                while (fini == 1)
                {
                 textcolor(YELLOW);
     gotoxy(5,32);
      printf("Entrez la date du la fin\n");
                gotoxy(7,33);
                textcolor(YELLOW);
     printf("Entrez l'anne sous forme aaaa:\n");
      gotoxy(7,34);
     printf("Entrez le mois sous forme mm:");
     gotoxy(7,35);
     printf("Entrez jour sous forme jj:");
     gotoxy(38,33);
    textcolor(WHITE);
     scanf("%d",&anne);

                    while ((anne<a) || (anne>a+5))
     {
         textcolor(LIGHTRED);
         gotoxy(45,33);
         printf("Erreur!\n");
         getch();gotoxy(38,33);printf("                                            ");
         textcolor(WHITE);
         gotoxy(38,33);
     scanf("%d",&anne);
     }
     textcolor(WHITE);
         gotoxy(38,34);
     scanf("%d",&mois);
     while ((mois<0) || (mois>12))
     {
          textcolor(LIGHTRED);
         gotoxy(45,34);
         printf("EROOR\n");
         getch();gotoxy(38,34);printf("                                            ");
         textcolor(WHITE);
         gotoxy(38,34);
         scanf("%d",&mois);
     }
     textcolor(WHITE);
         gotoxy(38,35);
     scanf("%d",&jour);
     while ((jour<1) || (jour>31))
     {
         textcolor(LIGHTRED);
         gotoxy(45,35);
         printf("EROOR\n");
          getch();gotoxy(38,35);printf("                           ");
         textcolor(WHITE);
         gotoxy(38,35);
     scanf("%d",&jour);
     }
               anne = anne *10000 ;
                mois=mois*100 ;
                (*datf) = (anne+jour+mois ) ;
                    if ((*datf)-(*datd)>0)
                    {
                        fini = 0 ;
                    }
                    else {   textcolor(LIGHTRED);
                                gotoxy(20,36);
                            printf("erreur dans la date de fin!\n");

                    getch();gotoxy(38,33);printf("                                            ");
                    gotoxy(20,36);printf("                                            ");
                      gotoxy(38,34);printf("                                            ");
                      gotoxy(38,35);printf("                                            ");
                }
}
}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
int compare_date(int d ,int f ,int dd, int ff)
{
    int cpt = 0 ;
    if (ff-d<0){cpt=1;}
    if (dd-f>0){cpt=1;}
    return cpt ;
}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void existe_num (struct hotel *tete , int i , struct ch  **pp)
{
    struct ch *q ;
    int trouve = 1 ;
    q = tete->tete1 ;
    (*pp) = NULL ;
    while( (q != NULL) && (trouve != 0) )
    {
        if (q->num == i)
            { trouve = 0 ;
                  (*pp)=q ;
                              }
        q = q->next ;
    }
}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void ajouter_reservation(struct listeABC *tete)
{
    int  numero , a,b ,end=0;
    struct hotel *p  ;
    struct ch    *pp ;
    struct reserv *n ,*nv ;
    char nomhotel[TAILLE_MAX] , nom[TAILLE_MAX] ;


     recupere_hotel(tete,&p);
  recupere_num(p,&pp);
  gotoxy(5,19);
        textcolor(YELLOW);
        printf("Entrez le nom :\n");
                gotoxy(22,19);
                textcolor(WHITE);
           scanf("%s",nom);
       n = pp->res ;
       gotoxy(26,23);
        textcolor(YELLOW);
        printf("'Recuperation de la date'\n");
       while(end == 0)
        {
         recupere_date(&a,&b);
         if (n==NULL) {end = 1 ;}
         else
         {
         while ((n!=NULL )&&(end==0))
         {
             if (compare_date(n->datedebut,n->datefin,a,b)==0)
                {
                    end=1 ;
                      }
            n = n->next ;
         }
         if (end==1){   n = pp->res ;
                       gotoxy(10,37);
                      textcolor(LIGHTRED);
                        printf("Cette chambre est deja reserver peandant cette periode !\n");
                        getch();
                                               gotoxy(10,37);
                        printf("                                                              ");

                                    end = 0   ;    }
         else { end = 1 ;}
        }
        }
        gotoxy(10,37);
        textcolor(YELLOW);
        printf("Pour (sauvgardez|annulez) la reservation appuiez sur la (touche entrer|\202chap)\n");
                 if (getch()==27){textcolor(LIGHTCYAN);gotoxy(10,39);printf("RESERVATION NON SAUVGARDER ...");goto menu1;}
                 else{textcolor(LIGHTCYAN);gotoxy(10,39);printf("RESERVATION SAUVGARDER ... ");p->fix=p->fix-1;}
            nv= malloc(sizeof(struct reserv)) ;
            strcpy(nv->nom,nom) ;
            nv->datedebut = a ;
            nv->datefin = b ;
           if (pp->res==NULL) { nv->next = NULL; pp->status = 0; }
           else {  nv->next = pp->res;}
                pp->res = nv ;
                pp->status = pp->status + 1 ;
                menu1 :  ;

}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void existe_hotel(struct listeABC *tete,char nomhotel[TAILLE_MAX],struct hotel **p)
{
    struct listeABC *q ;
    struct hotel *y ;
    q = tete ;
    *p=NULL ;
    while ( q!=NULL )
    {
            y = q->tete ;
        while (y !=NULL)
        {
            if ((strncasecmp(nomhotel,y->nomh,strlen(y->nomh))==0)&&((strlen(y->nomh))==strlen(nomhotel)))
            {
                *p = y ;
            }
            y = y->next ;
        }
        q = q->next ;
    }
}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void suprime_reservation(struct listeABC *tete )
{
    struct ch *pp ;
    int i=0 , numero  ;
    struct reserv *q ;
    struct hotel *p  ;
    char nomhotel[TAILLE_MAX] , nom[TAILLE_MAX] ;
    suite :
    recupere_hotel(tete,&p);
              if ((p->cap)-(p->lib)==0)
        {
                   gotoxy(43,17);
                   textcolor(LIGHTRED);
            printf("|tout les chambres cette hotel sont libres|\n");
                   getch();
                   gotoxy(38,17);
                   printf("                                   ");
            i = 0 ;
            goto suite ;
        }
        suite3 :
                     recupere_num(p,&pp);
               if (pp->res==NULL)
               {
                   gotoxy(43,17);
                   textcolor(LIGHTRED);
                   printf("chambre [%d] est deja libre!\n",pp->num);
                   getch();
                   gotoxy(38,17);
                   printf("                                   ");
                   goto suite3 ;
               }
                   gotoxy(8,20);
                   textcolor(YELLOW);
                    printf("il existe [%d] RESERVATION dans la chambre [%d]\n",pp->status,pp->num);
             printf("     entrez le nom  : \n");
             do
             {
                 gotoxy(22,21);
                 textcolor(WHITE);
             scanf("%s",nom);
             existe_nom(pp->res,nom,&q) ;
             if (q==NULL){gotoxy(29,21);
                 textcolor(LIGHTRED);printf("cette perssonne n'existe pas!\n");
                 getch();gotoxy(22,21);printf("                                     ");}
             }
             while (q==NULL);
                 gotoxy(5,22);
                 textcolor(YELLOW);
        printf("pour (confirmer|annulez) la supression appuiez la touche (entrer|\202chap)\n");
                 if (getch()==27){gotoxy(22,27) ;textcolor(LIGHTCYAN); printf("supression non valide\n");goto menu3;}
                 else{gotoxy(22,27); textcolor(LIGHTCYAN);   printf("supression avec succe\n");
}
                  suprime_maillon(pp,q);
                  (pp->status)=(pp->status) -1 ;
                  p->lib=(p->lib)+1 ;
                menu3:;
}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void suprime_maillon(struct ch *tete , struct reserv *sup)
{
    struct reserv *pre , *q ;
   q = tete->res ;
   if (sup==q){tete->res = q->next ;}
   else
   {
       while (q!=sup)
       {
           pre = q ;
           q=q->next;
       }

       pre->next = q->next ;
   }
   free(sup);
}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void recupere_hotel(struct listeABC *tete , struct hotel **p)
 {
     char nomhotel[TAILLE_MAX] ;
     int i=0 ;
 do
    {
        if (i!=0) {gotoxy(40,15);textcolor(LIGHTRED);printf("Hotel [%s] n'exite pas!\n",nomhotel); getch();gotoxy(29,15);printf("                                          ");}
           gotoxy(5,15);
            textcolor(YELLOW);
            printf("Entrez le nom d'hotel :\n");
            gotoxy(29,15);
            textcolor(WHITE);
            scanf("%s",nomhotel);
            existe_hotel(tete,nomhotel,&(*p)); //procedure retourne un ptr (p) NULL si hotel existe pas sinon elle retourne ptr sur le maillon
            i=1 ;
    }
    while ((*p)==NULL);
 }
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
 void recupere_num(struct hotel *p , struct ch **pp)
{
    int numero ;
    textcolor(YELLOW);
    gotoxy(5,17);
     printf("Entrez le numero de la chambre : \n");
     textcolor(WHITE);
            gotoxy(38,17);
              scanf("%d",&numero);
    do
    {
              while(((p->cap)<numero) || (1>numero) )
              {
                   gotoxy(41,17);
                  textcolor(LIGHTRED);
              printf("La chambre (%d) n existe pas dans cette hotel \n",numero);
              getch();
              gotoxy(38,17);printf("                                                               ");
              gotoxy(38,17);
              textcolor(WHITE);
              scanf("%d",&numero);
              }
            existe_num(p,numero,&(*pp)); //procedure retourne un ptr (p) NULL si nombre chambre existe pas ou occupé sinon elle retourne ptr sur le maillon
    }
        while ((*pp)==NULL);
}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void existe_nom(struct reserv *tete ,char nom[TAILLE_MAX] , struct reserv **p)
{
    int trouve =0 ;
    struct reserv *q ;
      (*p)=NULL ;
      q =tete ;
    while((q!=NULL)&&(trouve==0))
    {
        if((strncasecmp(nom,(q)->nom,strlen(q->nom))==0))
             {
                 trouve = 1 ;
             }
              if(trouve!=1) {q = q->next;}
    }
    if(trouve==1){(*p)=q;}
}
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void modifier_reservation(struct listeABC *t)
{
    struct hotel *p ;
    struct ch *l ;
    char nom[TAILLE_MAX];
    struct reserv *q,*n ;
    do
    {
    recupere_hotel(t,&p);
       if (p->cap==p->lib){textcolor(RED);printf(" tout les chambre sont libre\n");getch();gotoxy(38,17);printf("                                                    ");
}
          }
          while(p->cap==p->lib);
    do
    {
    recupere_num(p,&l);
    if (l->res==NULL){textcolor(LIGHTRED);gotoxy(41,17);printf("cette chambre est libre!\n ");getch();gotoxy(38,17);printf("                                                    ");}
    }
    while (l->res==NULL);
    gotoxy(5,19);
    textcolor(YELLOW);
    printf("Entrez le nom de la perssonne:\n ");
             do
             {
                 gotoxy(36,19);
             textcolor(WHITE);
             scanf("%s",nom);
             existe_nom(l->res,nom,&q) ;
             if (q==NULL){gotoxy(45,19);textcolor(LIGHTRED);printf("Cette perssonne n'existe pas!\n");
             getch();gotoxy(35,19);printf("                                                                 ");}
             }
             while (q==NULL);
               textcolor(YELLOW);
               gotoxy(5,21);
             printf("Entrez (1/2) pour changer (le nom de la perssonne)/(la date de la reservation):\n ");
             int i , end=0,a,b;
             gotoxy(84,21);
             textcolor(WHITE);
          scanf("%d",&i) ;
            switch(i)
                {
                   case 1:
                    gotoxy(5,23);
                    textcolor(YELLOW);
                    printf("Entrez le nom de la perssonne:\n") ;
                    gotoxy(36,23);
                    textcolor(WHITE);
                   scanf("%s",nom);
                   strcpy(q->nom,nom) ;
                   gotoxy(36,40);
                   textcolor(LIGHTCYAN);
                   printf("Mofication reussi\n");
                   goto fin1;
                   case (2) : {   gotoxy(5,23);
                                  textcolor(LIGHTCYAN);
            printf("La date de cette reservation de %d|%d|%d a %d|%d|%d\n",(q->datedebut)%100,((q->datedebut)%10000)/100,(q->datedebut)/10000,(q->datefin)%100,((q->datefin)%10000)/100,(q->datefin)/10000);
                                gotoxy(27,25);
                                  textcolor(YELLOW);
                                  printf("'La nouvelle date'\n");
                                  textcolor(LIGHTCYAN);
                    suprime_maillon(l,q);
                    n=l->res ;
                    while(end==0)
                    {
                    recupere_date(&a,&b);
                       if (n==NULL) {end = 1 ;gotoxy(38,37);textcolor(LIGHTCYAN);printf("mofication reussi\n");}
                       else{
         while ((n!=NULL )&&(end==0))
         {
             if (compare_date(n->datedebut,n->datefin,a,b)==0)
                {
                    end=1 ;
                      }
            n = n->next ;
         }
         if (end==1){   n = l->res ;
                            gotoxy(15,37);
                            textcolor(LIGHTRED);
                        printf("     Cette chambre est d\202ja reserver peandant cette periode !\n");
                                    end = 0   ;
                                    getch();
                                    gotoxy(15,37);
                                    printf("                                                                          "); }
         else {textcolor(LIGHTCYAN);gotoxy(38,37);printf("Mdification reussi \n ");
                      end = 1 ;}
        }}}}

        struct reserv *nv ;
        nv= malloc(sizeof(struct reserv)) ;
            strcpy(nv->nom,nom) ;
            nv->datedebut = a ;
            nv->datefin = b ;
           if (l->status==0) { nv->next = NULL; }
           else {  nv->next = l->res;}
                l->res = nv ;
                           fin1 : ;
                }
/**----------------------------------------------------------------------------------------------------------------------**/
/**----------------------------------------------------------------------------------------------------------------------**/
void lebiration(struct listeABC *tete)
{
   int datejour ;
    struct hotel *q ;
    struct ch *l ;
    struct reserv *m ;
        struct listeABC *p ;
        time_t secondes;
    struct tm instant;
    int b ;
    for(b=25;b<70;b++)
                {
                    gotoxy(26,28);
                    textcolor(WHITE);
                    printf("Suppression des chambres");
                    textcolor(LIGHTCYAN);
                    gotoxy(b,24);
                    delay(50);
                    printf("%c",219);
                    gotoxy(b,25);
                    printf("%c",219);
                    gotoxy(b,26);
                    printf("%c",219);
                     gotoxy(50,28);
                       textcolor(WHITE);
                if(b==45){
                        printf(".");
                        }
                if(b==55){
                       printf("..");}
                            if(b==60)
                   {
                         printf("...");
                                          }
                    if(b==70){
                                            gotoxy(26,28);
                    textcolor(WHITE);
                    printf("                                           ");

                }
                gotoxy(47,25);
                    textcolor(WHITE);
                    printf("%d%c",b+31,37);

                }
                    gotoxy(26,28);
                    textcolor(WHITE);
                    printf("                                           ");
                                    gotoxy(38,28);
                                    printf("SUPPRESSION REUSSI\n\n");
    time(&secondes);
    instant=*localtime(&secondes);
     datejour = (instant.tm_mday)+(instant.tm_mon+1)*100+(instant.tm_year+1900)*10000 ;
     p=tete ;
      while(p!=NULL)
      {
          q = p->tete ;
      while(q!=NULL)
      {
       l = q->tete1 ;
      while (l!=NULL)
      {
          m = l->res ;
          int cpt = 1 ;
          while (m!=NULL)
          {
            if (m->datefin < datejour ){l->status = l->status -1; suprime_maillon(l,m);}
          m=m->next ;
          }
          l=l->next ;
      }
      q=q->next ;
      }
      p=p->next ;
      }
}
//---------------------------------------------------------------------------------------------------
void sauv(struct listeABC *tete)
{
    struct listeABC *a;
    struct hotel *p;
    struct ch *c;
    int cpt;
    struct reserv *r;

    FILE *fich ;
      fich = fopen("h.txt","a");
      a=tete;
      while (a!=NULL)
      {
          if(a->nombr!=0)
          {
            fprintf(fich,"debut\n");
          fprintf(fich,"%c\n",a->i);
          fprintf(fich,"%d\n",a->nombr);
          p=a->tete;
             while(p!=NULL)
             {
                 fprintf(fich,"%s\n",p->nomh);
                 fprintf(fich,"%s\n",p->ville);
                 fprintf(fich,"%d\n",p->cap);
                 fprintf(fich,"%d\n",p->fix);
                fprintf(fich,"%d\n",p->inf);
                fprintf(fich,"%d\n",p->sup);
                    c=p->tete1;cpt=0;
                      while(c!=NULL)
                      {
                          if ((c->status!=0)||(c->fix!=0))
                          {

                              fprintf(fich,"%d &",c->num);
                             fprintf(fich," %d &",c->type);
                              fprintf(fich," %d &",c->prix);
                              fprintf(fich," %d\n",c->status);
                              r=c->res;
                              while(r!=NULL)
                              {
                                  fprintf(fich,"%s\n",r->nom);
                                   fprintf(fich,"%d &",r->datedebut);
                                   fprintf(fich," %d\n",r->datefin);
                                  r=r->next;
                              }
                            }
                            c=c->next;
                        }

                p=p->next;
             }

          }
             a=a->next;
      }
      fclose(fich);
      remove("hotel.txt");
      rename("h.txt","hotel.txt");

}

struct listeABC *ajouthotel(struct listeABC *tete)
{
    struct listeABC *ptr;
    int indu,min,max,v,numo,nb,cp;
    struct hotel *p;char choix[10];
    struct ch *w;
    p=malloc(sizeof(struct hotel));
    gotoxy(3,10);
    textcolor(LIGHTGREEN);
    printf("Entrez le premier caractere en maj");
    textcolor(YELLOW);
    gotoxy(5,12);
    printf("Entrez le nom de l hotel : ");
        gotoxy(5,14);
    printf("Entrez le nom de la ville de l hotel :  ");
        gotoxy(5,16);
    printf("Entrez la capacite de l hotel : ");
  suite1:
      gotoxy(32,12);
    textcolor(WHITE);
    scanf("%s",&p->nomh);
    if((p->nomh[0]<64) ||(p->nomh[0]>91) )
    {
        textcolor(LIGHTRED);
        gotoxy(40,12);
        printf("erreur!");
        getch();
        gotoxy(31,12);
          printf("                                           ");
        goto suite1 ;
    }
        gotoxy(45,14);
    scanf("%s",&p->ville);
            gotoxy(36,16);
    scanf("%d",&p->cap);
    p->fix=p->cap;
    p->inf=p->sup=0;
    textcolor(YELLOW);
    gotoxy(5,18);
    printf("entrez l intervales de prix des chambres min=     max=");
      suite2:   textcolor(WHITE);
         gotoxy(51,18);
         scanf("%d",&p->inf);
         gotoxy(60,18);
         scanf("%d",&p->sup);
          if (p->inf >= p->sup)
     {
         textcolor(LIGHTRED);
         gotoxy(64,18);
         printf("erreur");
         getch();
         gotoxy(51,18);
         printf("    ");
         gotoxy(60,18);
         printf("                  ");
         goto suite2 ;
     }
     gotoxy(5,20);
     textcolor(YELLOW);
    printf("le prix de chambre sont pris aleatoirement ");
     gotoxy(5,21);
    printf("voulez vous fixer le prix ou le type de certain chambre ? (oui|non)");
    textcolor(WHITE);
    gotoxy(75,21);
    scanf("%s",&choix);
    p->tete1=cre(p->inf,p->sup,p->cap);
    if (strcmp("oui",choix)==0)
    {
        textcolor(YELLOW);
        gotoxy(5,23);
        printf("Entrez le nombre de chmabres que vous voulez fixer le type et le prix  ");
    suite3:    gotoxy(75,23);
               textcolor(WHITE);
               scanf("%d",&nb);
               if ((nb<0)||(nb>p->cap))
                      {
                              textcolor(LIGHTRED);
                              gotoxy(80,23);
                              printf("Erreur");
                              getch();
                              gotoxy(75,23);
                              printf("                 ");
                              goto suite3 ;
                                    }
        cp=0;p->fix=p->cap-nb;
        while(cp<nb)
        {
            textcolor(YELLOW);
            gotoxy(5,25);
            printf("Entrez le numero de la chambre: ");
            textcolor(WHITE);
            gotoxy(36,25);
            scanf("%d",&numo);
            w=p->tete1;

            while((w!=0)&&(w->num!=numo))
            {
                w=w->next;
            }
            if (w!=NULL)
            {
                textcolor(YELLOW);
                gotoxy(5,27);
                printf("Entrez le type de la chambre ",w->num);
                gotoxy(5,28);
                printf("(0) pour [individuelle] (1) pour [deux] : ");
                gotoxy(5,29);
                printf("Entrez le prix de la chambre [%d] : ",w->num);
                gotoxy(46,28);
                textcolor(WHITE);
                scanf("%d",&w->type);
                gotoxy(40,29);
                scanf("%d",&w->prix);
                w->fix=1;
                getch();
                gotoxy(36,25);
                printf("       ");
                gotoxy(40,29);
                printf("       ");
                gotoxy(46,28);
                printf("       ");
                cp=cp+1 ;
            }
            else
            {
                gotoxy(5,32);
                textcolor(LIGHTRED);
                printf("Cette chambre n existe pas!");
                getch();
                gotoxy(5,32);
                printf("                               ");
                gotoxy(36,25);
                printf("                               ");

            }
        }
    }
ptr=tete;
char c=p->nomh[0];
v=ptr->i-c;
while(v!=0)
{
    ptr=ptr->next;
    v=ptr->i-c;
}
int cpt;cpt=1;ptr->nombr=ptr->nombr+1;
struct hotel *b,*prec;
b=ptr->tete;
prec=ptr->tete;
do
{
if (cpt!=1)
{
prec=b;
b=b->next;
}
cpt=cpt+1;
}while (b!=NULL);
if (prec!=NULL)
{
prec->next=p;
p->next=NULL;
}
else
{
    ptr->tete=p;
    p->next=NULL;
}
return tete;
}

struct listeABC *supphotel(struct listeABC *tete)
{
    int v,cpt;
    struct listeABC *ptr;
    struct hotel *e,*prec,*p;
    struct ch *m,*suiv;
    char s[100];char choix[10];
    printf("entrez le nom de l'hotel que vous voulez supprimer ");
    scanf("%s",&s);
ptr=tete;
char c=s[0];
v=ptr->i-c;
while(v!=0)
{
ptr=ptr->next;
v=ptr->i-c;
}
e=ptr->tete;
cpt=1;existe_hotel(tete,s,&p);
if(p!=NULL)
{
if(e!=NULL)
{
while((strncmp(s,e->nomh,strlen(e->nomh)-1)!=0)&&(e!=NULL))
{
    e=e->next;
    cpt=cpt+1;
}
if (e->cap>e->lib)
{
    printf("attention l hotel contient des reservation si vous voulez le supprimer comme meme tapez oui ");
}
else
{
    printf("vous etes sure que vous voulez supprimer l hotel ");
}
scanf("%s",&choix);
if(cmpstr(choix,"oui",strlen("oui"))==0)
{

if (e!=NULL)
  {
      if(cpt==1)
      {
          ptr->tete=e->next;
          m=e->tete1;
      }
      else
      {
          prec->next=e->next;
          m=e->tete1;
      }
       while(m!=NULL)
        {
        suiv=m->next;
        free(m);
        m=suiv;
        }
   free(e);
   printf("l'hotel a ete supprimer ");
  }

else
{
        printf("cet hotel n existe pas");
}

}
}
}
else
{
  printf("cet hotel n existe pas");
}
return tete;
}
int cmpstr(char d[100],char s[100],int nb)
{
int i;
if (strlen(s)>=nb)
{
  i=0;
while ((d[i]==s[i])&&(i<nb))
    {
      i=i+1;
    }
    if (i==nb)
    {
       return 0;
    }
    else
    {

        return 1;
    }
}
else
{
return -1;
}
};

