#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 20


void Intro();

void Affichage(char*,char*,char);

void flushstdin();

void CoupRestant(int,char*);





int main()
{

   // Intro();

    int i=0, l=0, coupRestant=10;
    char mot[TAILLE];


    printf("ecrire un mot\n");
    scanf("%s",&mot);
    system("cls");

    l = strlen(mot);

    // Tableau de caractères révélés (trouvés par le joueur).
    // Chaque élément est un booléen (0 : caché, 1 : affiché).
    char revealed[TAILLE];
    memset(revealed, 0, TAILLE); //remplis la zone mémoire de revealed

    // Boucle de jeu

    while (1)
    {
        // Afficher le mot

        for (i = 0; i < l; i++)
        {
            putchar(revealed[i] ? mot[i] : '-');
        }
        putchar('\n');

        char c;
        flushstdin();
        printf("ecrire un caractere\n");
        scanf("%c", &c);

         if(c != revealed[i])
        {
            coupRestant--;
            CoupRestant(coupRestant,mot);
        }
        Affichage(mot, revealed, c);
    }






    return 0;
}

/*********************************************************

BUT : Afficher l'intro du pendu

ENTREE : /

SORTIE : La fin du pendu

*********************************************************/

void Intro()
{
    char car;


    printf("Bienvenue sur le pendu\n");
    printf("\n");
    printf("Le but va etre de trouver le mot secret avant votre pandaison, vous aurez le droit a 10 tour\n");
    printf("\n");
    printf("appuyez sur ENTRER pour continuer\n");
        scanf("%c",&car);
        fflush(stdin);
        system("cls");
    printf("Que la pandaison comence !\n\n");
    printf("appuyez sur ENTRER pour lancer le jeux\n");
        scanf("%c",&car);
    system("cls");
}

/**************************************************************************************************************

BUT : Le mot que l'utilisateur est cachée et lorsque le deuxième utilisateur trouve une lettre elle s'affiche

ENTREE : l'utilisateur rentre un mot au choix

SORTIE : le mot est caché sauf la lettre qui est appelée

***************************************************************************************************************/

void Affichage(char* mot, char* revealed, char r) // fonction affichage caractere
{
    int i=0;

    while(mot[i])
    {
        if(mot[i]==r)
            revealed[i]=1;
        i++;
    }
}

/*********************************************************

BUT :

ENTREE :

SORTIE :

*********************************************************/

void flushstdin()
{
    char c;

     while ( (c = getchar()) != '\n' && c != EOF );
}

/*********************************************************

BUT : Affichage du pendu par erreur

ENTREE : L'utilisateur rnetre une erreur

SORTIE : Le pendu se dessine

*********************************************************/

void CoupRestant(int coupRestant,char *revealed)
{
    int vie=0;


    vie=coupRestant;

    system("cls");


    switch (vie)
    {

        case 10 : //Le joueur a 10 vies
                printf("\n");
                break;
            case 9 : //Le joueur a 9 vies
                printf("_|__\n"); //Le joueur perd une vie, on construit la potence
                break;
            case 8 : //Le joueur a 8 vies
                printf(" " "|\n"); //Le joueur perd une vie, on construit la potence
                printf("_|__\n");
                break;
            case 7 : //Le joueur a 7 vies
                printf(" " "|\n"); //Le joueur perd une vie, on construit la potence
                printf(" " "|\n");
                printf("_|__\n");
                break;
            case 6 : //Le joueur a 6 vies
                printf(" " "|\n"); //Le joueur perd une vie, on construit la potence
                printf(" " "|\n");
                printf(" " "|\n");
                printf("_|__\n");
                break;
            case 5 : //Le joueur a 5 vies
                printf(" " "|\n"); //Le joueur perd une vie, on construit la potence
                printf(" " "|\n");
                printf(" " "|\n");
                printf(" " "|\n");
                printf("_|__\n");
                break;
            case 4 : //Le joueur a 4 vies
                printf("____________\n"); //Le joueur perd une vie, on construit la potence
                printf(" " "|\n");
                printf(" " "|\n");
                printf(" " "|\n");
                printf(" " "|\n");
                printf("_|__\n");
                break;
            case 3 : //Le joueur a 3 vies
                printf("____________\n"); //Le joueur perd une vie, on construit la potence
                printf(" " "|" " " " " " " " " " " " " " " "|\n");
                printf(" " "|\n");
                printf(" " "|\n");
                printf(" " "|\n");
                printf(" " "|\n");
                printf("_|__\n");
                break;
            case 2 : //Le joueur a 2 vies
                printf("____________\n"); //Le joueur perd une vie, on construit la potence
                printf(" " "|" " " " " " " " " " " " " " " "|\n");
                printf(" " "|" " " " " " " " " " " " " " " "O\n");
                printf(" " "|\n");
                printf(" " "|\n");
                printf(" " "|\n");
                printf("_|__\n");
                break;
            case 1 : //Le joueur a 1 vie
                printf("____________\n"); //Le joueur perd une vie, on construit la potence
                printf(" " "|" " " " " " " " " " " " " " " "|\n");
                printf(" " "|" " " " " " " " " " " " " " " "O\n");
                printf(" " "|" " " " " " " " " " "" " "/" "|" "\\\n");
                printf(" " "|\n");
                printf(" " "|\n");
                printf("_|__\n");
                break;

    }

    printf("\n");


    if(vie<1)
    {
        //
        printf("_" "_" "_" "_" "_" "_" "_" "_" "_" "_" "_" "_\n");
        printf(" " "|" " " " " " " " " " " " " " " "|\n");
        printf(" " "|" " " " " " " " " " " " " " " "O\n");
        printf(" " "|" " " " " " " " " " "" " "/" "|" "\\\n");
        printf(" " "|" " " " " " " " " " " " " "/" " " "\\\n");
        printf(" " "|\n");
        printf("_|__\n");
        //
        printf("Votre pendaison est complete, le mot etait %c\n",revealed);
    }else
        {
            printf("vous avez reussi a survivre\n");
        }

}



