#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "design.h"
#include "conio.h"
#include"graphisme.h"
#include "bib.h"
#include "design.h"


int main()
{
    system("mode con LINES=50 COLS=90");            //On Donne une taille au programme
    int a,b=0;
    struct listeABC *t ;

    begining();  //graphisme de début
    do
    {
        choix_menu(&a);
        switch (a)
        {
            case 1: {
                if (b==0)
                {
                gotoxy(32,20) ;
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("Chargement des reservations \n") ;
                textcolor(WHITE);
                t=charg();
                for(b=25;b<70;b++)
                {
                    gotoxy(26,28);
                    textcolor(WHITE);
                 if(b<40){   printf("recuperation du fichier");}
                    textcolor(LIGHTCYAN);
                    gotoxy(b,24);
                    delay(50);
                    printf("%c",219);
                    gotoxy(b,25);
                    printf("%c",219);
                    gotoxy(b,26);
                    printf("%c",219);
                if(b==45){
                        gotoxy(50,28);
                       textcolor(WHITE);
                       delay(60);
                       printf(".");
                       delay(60);
                      printf(" .");
                       delay(60);
                    printf("  .");
                                          }
                    if(b==50){
                                            gotoxy(26,28);
                    textcolor(WHITE);
                    printf("                                           ");
                                    gotoxy(26,28);
                                         printf("Creation des listes");}
                        if(b==55){
                        gotoxy(50,28);
                       textcolor(WHITE);
                       delay(60);
                       printf(".");
                       delay(60);
                      printf(" .");
                       delay(70);
                       printf("  .");
                                          }
                    gotoxy(47,25);
                    textcolor(WHITE);
                    printf("%d%c",b+31,37);

                }
                printf("\n") ;
                printf("\n ") ;
                printf("\n\n");
                   gotoxy(26,28);
                    textcolor(WHITE);
                    printf("                                           ");
                                    gotoxy(38,28);
                                    printf("CHARGEMENT REUSSI\n\n");
                b=1;

                system("pause");
                }
                else
                {
                    printf("ok bb!");
                    printf("\n") ;
                printf("\n ") ;
                printf("\n\n");
                    system("pause");
                }
            }
            break;
            case 2: {
                int c=0 ;
                sauv(t) ;
                     gotoxy(32,20) ;
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("Sauvgarder les reservation\n") ;
                textcolor(WHITE);
                t=charg();
                for(c=25;c<70;c++)
                {
                    gotoxy(26,28);
                    textcolor(WHITE);
                 if(c<40){   printf("Recuperation des donn\202es");}
                    textcolor(LIGHTCYAN);
                    gotoxy(c,24);
                    delay(50);
                    printf("%c",219);
                    gotoxy(c,25);
                    printf("%c",219);
                    gotoxy(c,26);
                    printf("%c",219);
                if(c==45){
                        gotoxy(50,28);
                       textcolor(WHITE);
                       delay(60);
                       printf(".");
                       delay(60);
                      printf(" .");
                       delay(60);
                    printf("  .");
                                          }
                    if(c==50){
                                            gotoxy(26,28);
                    textcolor(WHITE);
                    printf("                                           ");
                                    gotoxy(26,28);
                                         printf("ENREGISTREMENT");
                                         }
                        if(c==55){
                        gotoxy(50,28);
                       textcolor(WHITE);
                       delay(60);
                       printf(".");
                       delay(60);
                      printf(" .");
                       delay(70);
                       printf("  .");
                                          }
                    gotoxy(47,25);
                    textcolor(WHITE);
                    printf("%d%c",c+31,37);

                }
                printf("\n") ;
                printf("\n ") ;
                printf("\n\n");
                   gotoxy(26,28);
                    textcolor(WHITE);
                    printf("                                           ");
                                    gotoxy(38,28);
                                    printf("SAUVGARDE REUSSI\n\n");
                system("pause");
                textcolor(LIGHTCYAN);
                printf("\n\n");
                system("pause");
            }
            break;
            case 3: {
                gotoxy(30,1);
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("Affichage des statuts des reservation\n") ;
                affich(t) ;
                textcolor(WHITE);
                printf("\n\n");
                system("pause");
            }
            break;
            case 4:{
                gotoxy(24,10);
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("Inserer une nouvelle reservation\n") ;
                printf("\n\n") ;
                ajouter_reservation(t) ;
                textcolor(WHITE);
                printf("\n\n");
                system("pause");
            }
            break;
            case 5 : {
                gotoxy(20,10);
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("Modifier une reservation\n");
                printf("\n\n");
                modifier_reservation(t);
                textcolor(WHITE);
                system("pause");
            }
            break;
            case 6: {
                gotoxy(25,10);
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("Suprimer une resarvation\n");
                printf("\n\n");
                suprime_reservation(t);
                printf("\n") ;
                textcolor(WHITE);
                system("pause");
            }
            break;
            case 7:{
                gotoxy(20, 1);
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
//                mis_a_jour_pina(tet,tete1);
                printf("Recherche une chambre\n") ;
                printf("\n\n");
                //affich_pinailite(tete1,tet);
                textcolor(WHITE);
                printf("\n\n");
                system("pause");
            }
            break;
            case 8:{

                gotoxy(20, 1);
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("Recherche par Nom\n") ;
                printf("\n\n");
                //eclat_list(tet,&t1,&t2) ;
                textcolor(WHITE);
                gotoxy(5, 5);
               // printf(" L'enregistrement dans le fichier est  R\202ussi \n") ;
                 gotoxy(5, 6);
               // printf("Veuillez V\202rifier le fichier : Eclatement de la liste\n");
                 printf("\n ") ;
                system("pause");
            }
            break;
            case 9:{
                gotoxy(25,1);
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("Rajouter un hotel\n") ;
                t=ajouthotel(t);
                printf("\n\n");

                textcolor(WHITE);
                printf("\n");
                system("pause");
            }
            break;
            case 10:{
                gotoxy(25, 1);
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("Supprimer un hotel\n");
                printf("\n\n");
                t=supphotel(t);
                textcolor(WHITE);
                printf("\n");
                system("pause");
            }
            break;
            case 11:{
                gotoxy(20, 20);
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("libirer toutes les chambres occup\202es ayant une date pass\202\n");
                printf("\n\n");
                lebiration(t) ;
                textcolor(WHITE);
                printf("\n");
                system("pause");
            }
            break;
            case 12:{
                gotoxy(25, 1);
                textbackground(BLACK);
                textcolor(LIGHTCYAN);
                printf("trier les liste des hotels par ordres alphabitique\n");
                printf("\n\n");
                //recherch_par_motcles(tete) ;
                textcolor(WHITE);
                printf("\n");
                system("pause");
            }
            break;

        }
    }
    while (a != 13 );      //On revient au menu jusqu' on décide de quitter le programme
    ending();
    return 0;
}
