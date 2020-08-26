#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#define down 80             //code ascii de la touche bas
#define up 72              //code ascii de la touche haut
#define entr 13            //code ascii de la touche entrée

void choix_menu (int *choice)
/**Procedure d'ffichage du menu qu'on parcoure avec les fleches bidirectionnelles et qui retourne le choix**/
{
    char choix[][100]={
        "Cherger les donnees",
        "Sauvgarder les reservation",
        "Affichage des statuts des reservation",  //tableau contenant les choix
        "Inserer une nouvelle reservation",
         "Modifier une reservation",
        "Suprimer une resarvation",
       "Recherche une chambre",
       "Recherche par Nom ",
       "Rajouter un hotel",
        "Supprimer un hotel ",
        "libirer touts les chambres occupées ayant une date passé",
        "trier les liste des hotels par ordres alphabitique",
        "Quitter",
          };
    int i, x= 13, y = 16;  //x et y sont les coordonnées du point où commence le menu
    char point, point2;
    acc();                 //Donne au programme sa forme générale
    gotoxy(30, 12);
    textbackground(BLACK);
    textcolor(LIGHTCYAN);
    printf(" Menu Principal ");       //titre du menu
    textcolor(WHITE);
    for (i=0; i<13; i++)
    {
        gotoxy(x,i+y);                   //On écrit les différents choix du menu chacun dans une ligne
        printf("%s", choix[i]);
    }
    gotoxy(x,y);
    textcolor(YELLOW);
    printf("%s", choix[0]);               //On réécrit la premiere ligne en bleu (séléction)
    do
    {
        point = getch();                 //lire le code ascii d'une touche du clavier
        if (point == entr) *choice = wherey() -y+1;       // la touche entrée permet de valider le choix selectionné
        else if (point == -32)   //la touche est une des flèches bidirectionnelles
        {
            point2 = getch();
            switch (point2)
            {
                case up :
                    {
                        if (wherey() == y)           //si la selection est en haut et que la flèche est vers le haut
                        {                            //la selection pointe sur le dernier choix
                            gotoxy(x,y);
                            textcolor(WHITE);       //On déselectionne le premier choix
                            printf("%s", choix[0]);
                            gotoxy(x,i+y-1);
                            textcolor(YELLOW);
                            printf("%s", choix[12]);     //On selectionne le dernier
                        }

                        else
                        {                                               //Sinon la selection passe vers la ligne suivante
                            gotoxy(x, wherey());
                            textcolor(WHITE);
                            printf("%s", choix[wherey()-y]);        //Déselection
                            gotoxy(x, wherey()-1);
                            textcolor(YELLOW);
                            printf("%s", choix[wherey()-y]);
                        }
                    }
                break;
                case down :
                    {
                        if (wherey() == y+12)                //si la selection est en bas et que la flèche est vers le bas
                        {                                  //la selection pointe sur le premier choix
                            gotoxy(x,y+12);
                            textcolor(WHITE);
                            printf("%s", choix[12]);
                            gotoxy(x,y);
                            textcolor(YELLOW);
                            printf("%s", choix[0]);
                        }
                        else                                            //Sinon,la selection passe vers la ligne précédante
                        {
                            gotoxy(x, wherey());
                            textcolor(WHITE);
                            printf("%s", choix[wherey()-y]);
                            gotoxy(x, wherey()+1);
                            textcolor(YELLOW);
                            printf("%s", choix[wherey()-y]);
                        }
                    }
                break;
            }
        }
    }
    while (point != entr )  ;      //on continue de lire jusqu'à ce que le choix est validé
    system("cls");
    textcolor(LIGHTCYAN);
}

void acc()
/**Donne la forme générale du programme**/
{
    int i=rand(); //génération d'un nombre aléatoir
    system("color 66");     //couleur de fond et de texte
    system("cls");
    gotoxy(1,3);
    printf("_________________________________________________________________________________________");
    gotoxy(1,5);
    printf("    TP1 ALSDD        |       Yacine Chergui & Mcharbet Lotfi      |        2017/2018  ");
    gotoxy(1,7);
    printf("_________________________________________________________________________________________");

}

void begining () /**graphisme de début**/
{
    int i;
    system ("color 44");
    gotoxy (15,5);
    printf ("   \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\n");
    delay (10);
    gotoxy (15,6);
    printf ("   \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\n");
    delay (10);
    gotoxy (15,7);
    printf ("   \333\333\333                 \333\333\333                                       \n");
    delay (10);
    gotoxy (15,8);
    printf ("   \333\333\333                 \333\333\333      \n");
delay (10);
    gotoxy (15,9);
    printf ("   \333\333\333                 \333\333\333                 \333\333\333\n");
    delay (10);
    gotoxy (15,10);
    printf ("   \333\333\333                 \333\333\333                 \333\333\333\n");
    gotoxy (15,11);
    delay (10);
    printf ("   \333\333\333                 \333\333\333                 \333\333\333\n");
    gotoxy (15,12);
    delay (10);
    printf ("   \333\333\333                 \333\333\333                 \333\333\333\n");
    gotoxy (15,13);
    delay (10);
    printf ("   \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\n");
    gotoxy (15,14);
    delay (10);
    printf ("   \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\n");
    gotoxy (15,15);
    delay (10);
    printf ("   \333\333\333                            \333\333\333      \333\333\333\n");
    delay (10);
    gotoxy (15,16);
    printf ("   \333\333\333                            \333\333\333      \333\333\333\n");
    gotoxy (15,17);
    delay (10);
    printf ("   \333\333\333                            \333\333\333      \333\333\333\n");
    gotoxy (15,18);
    delay (10);
    printf ("   \333\333\333                            \333\333\333      \333\333\333\n");
    gotoxy (15,19);
    delay (10);
    printf ("   \333\333\333                            \333\333\333      \333\333\333\n");
    gotoxy (15,20);
    delay (10);
    printf ("   \333\333\333                            \333\333\333      \333\333\333\n");
    delay (10);
    gotoxy (15,21);
    printf ("   \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\n");
    gotoxy (15,22);
    delay (10);
    printf ("   \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\333\333\333\333\333\333\333\333\333\333\333      \333\333\333\n");
    gotoxy(10,25);
    textcolor (LIGHTCYAN);
    for (i=0; i<54;i++)
    {
        printf("\333");
        delay (15);
    }
    textbackground(BLACK);
    textcolor(LIGHTCYAN);
    gotoxy (5,29);
    printf ("                  Gestion des Reservations d'Hotel ");
    gotoxy (2,32);
    system ("pause");
    system ("cls");
}

void ending() /**Graphisme de fin**/
{

    system("cls");
    textcolor(LIGHTCYAN);
    gotoxy(1,10);
    printf("                 ######    ######                                    ###   \n");
    delay(5);
    printf("                  ####      ####                                     ### \n ");
    delay(5);
    printf("                 #####    #####                                     ###\n ");
    delay(5);
    printf("                 #####    #####                                   \n ");
    delay(5);
    printf("                 #####    #####     ####     #### ###     #######   ### \n");
    delay(5);
    printf("                  ##############    #######   ########    ########   ### \n ");
    delay(5);
    printf("                 ### ###### ###    ###  ##    #######    ########   ###\n ");
    delay(5);
    printf("                 ### ###### ###    ###  ###   ####       ###        ###\n");
    delay(5);
    printf("                  ### ###### ###    ########   ####       ###        ### \n  ");
    delay(5);
    printf("                ###  ####  ###    ###        ####       ###        ### \n");
    delay(5);
    printf("                  ###  ####  ###    ###        ####       ###        ### \n  ");
    delay(5);
    printf("                ###   ##   ###    ######     ####       ########   ### \n");
    delay(5);
    printf("                 #####  ##  #####  /######    .####       ########   ### \n  ");
    delay(5);
    printf("               #####      #####  . #####.   ######.      #######   ###\n");
    gotoxy (3,30);
    system("pause");
}


