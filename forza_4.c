
/*
PROGRAMMA: forza 4
DATA:22/02/2022
PROGRAMMATORE: SERGIO LUCIO
CLASSE: 2C inf.*/
// librerie
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// costanti
#define MAX 7
#define MIN 6
#define GRAVITY 1
#define X 2
#define O 3
#define PARITY 42

// variabili globali
char forza[MIN][MAX];
char player1[CHAR_MAX], player2[CHAR_MAX];
int colonna, check1, j, punteggio_X = 0, punteggio_O = 0, pareggio = 0;

// nomi
void nomi()
{
    // azzeramento dei punti per NUOVA PARTITA
    punteggio_X = 0;
    punteggio_O = 0;

    // player1
    printf("\n player1 inserisci il tuo nome: ");
    scanf("%s", &player1);

    // player2
    printf("\n player2 inserisci il tuo nome:  ");
    scanf("%s", &player2);
}

// azzerare e inizzializaare la matrice
void azzera()
{
    pareggio = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j <= MIN; j++)
        {
            forza[i][j] = ' ';
        }
    }
}

// menu
void menu()
{

    printf("* * * * * * * * * * * * * * * * * * * * * * * * * *  *\n");
    printf("*                       MENU                         *\n");
    printf("*                      FORZA 4                       *\n");
    printf("* [1] NUOVA PARTITA                                  *\n");
    printf("* [2] RIVINCITA                                      *\n");
    printf("* [3] PUNTEGGIO                                      *\n");
    printf("* [4] REGOLE                                         *\n");
    printf("* [0] EXIT                                           *\n");
    printf("*                                                    *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * *  *\n\n");
}

//  creare la matrice
void matrice()
{
    printf("\t\t\t\t   0   1   2   3   4   5   6\n");
    for (int i = 0; i < MIN; i++)
    {
        printf("\t\t\t\t ");
        for (int j = 0; j < MAX; j++)
        {
            printf("| %c ", forza[i][j]);
        }
        printf("|\n");
    }
}

// controllo gravità (controlla la gravità facendo scendere la X o la O )
void check_gravity(int colonna)
{
    for (int i = 5; i >= 0; i--)
    {
        if (forza[i][colonna] == ' ')
        {
            j = i;
            check1 = 1;
            break;
        }
    }
}

// controllo player1
void check_X()
{
    for (int i = 0; i <= MAX; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // controllo orizontale
            if (forza[i][j] == 'X' && forza[i][j + 1] == 'X' && forza[i][j + 2] == 'X' && forza[i][j + 3] == 'X')
            {
                check1 = X;
            }

            // controllo verticale
            if (forza[j][i] == 'X' && forza[j + 1][i] == 'X' && forza[j + 2][i] == 'X' && forza[j + 3][i] == 'X')
            {
                check1 = X;
            }
        }
    }
    // DIAGONALI DA SINISTRA VERSO DESTRA
    for (int i = 0; i <= 3; i++)
    {

        for (int j = 5; j >= 3; j--)
        {

            if (forza[j][i] == 'X' && forza[j - 1][i + 1] == 'X' && forza[j - 2][i + 2] == 'X' && forza[j - 3][i + 3] == 'X')
            {
                check1 = X;
            }
        }
    }

    // DIAGONALI DA DESTRA VERSO SINISTRA
    for (int i = 6; i >= 3; i--)
    {
        for (int j = 5; j >= 3; j--)
        {
            if (forza[j][i] == 'X' && forza[j - 1][i - 1] == 'X' && forza[j - 2][i - 2] == 'X' && forza[j - 3][i - 3] == 'X')
            {
                check1 = X;
            }
        }
    }
}

// controllo player 2
void check_O()
{
    for (int i = 0; i <= MAX; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // controllo orizontale
            if (forza[i][j] == 'O' && forza[i][j + 1] == 'O' && forza[i][j + 2] == 'O' && forza[i][j + 3] == 'O')
            {
                check1 = O;
            }

            // controllo verticale
            if (forza[j][i] == 'O' && forza[j + 1][i] == 'O' && forza[j + 2][i] == 'O' && forza[j + 3][i] == 'O')
            {
                check1 = O;
            }
        }
    }
    // DIAGONALI DA SINISTRA VERSO DESTRA
    for (int i = 0; i <= 3; i++)
    {

        for (int j = 5; j >= 3; j--)
        {

            if (forza[j][i] == 'O' && forza[j - 1][i + 1] == 'O' && forza[j - 2][i + 2] == 'O' && forza[j - 3][i + 3] == 'O')
            {
                check1 = O;
            }
        }
    }
    // DIAGONALI DA DESTRA VERSO SINISTRA
    for (int i = 6; i >= 3; i--)
    {
        for (int j = 5; j >= 3; j--)
        {
            if (forza[j][i] == 'O' && forza[j - 1][i - 1] == 'O' && forza[j - 2][i - 2] == 'O' && forza[j - 3][i - 3] == 'O')
            {
                check1 = O;
            }
        }
    }
}

// punteggio
void punteggio()
{

    printf("\npunteggio %s: %d\n", player1, punteggio_X);
    printf("\npunteggio %s: %d\n", player2, punteggio_O);
}

// giocatore1
void giocatore1()
{
    printf("\n%s [X] e' il tuo turno\n", player1);
    printf("inserisci la colonna: ");
    scanf("%d", &colonna);
    check_gravity(colonna);
    if (colonna < 0 || colonna > 6)
    {
        printf("\n colonna errata riprova\n");
        giocatore1();
    }
    else if (forza[0][colonna] == 'X' || forza[0][colonna] == 'O')
    {
        printf("\n casella gia occupata riprova\n");
        giocatore1();
    }

    else if (check1 == GRAVITY)
    {
        forza[j][colonna] = 'X';
        pareggio++;
        matrice();
    }

    check_X();
}

// giocatore2
void giocatore2()
{
    printf("\n%s [O] e' il tuo turno\n", player2);
    printf("inserisci la colonna: ");
    scanf("%d", &colonna);
    check_gravity(colonna);
    if (colonna < 0 || colonna > 6)
    {
        printf("\n colonna errata riprova\n");
        giocatore2();
    }

    else if (forza[0][colonna] == 'X' || forza[0][colonna] == 'O')
    {
        printf("\n casella gia occupata riprova\n");
        giocatore2();
    }
    else if (check1 == GRAVITY)
    {
        forza[j][colonna] = 'O';
        pareggio++;
        matrice();
    }

    check_O();
}

void rivincita()
{
}

// inizio gioco
void play()
{
    azzera();
    matrice();

    // esce quando qualcuno vince o pareggia
    while (check1 != X || check1 != O || pareggio != PARITY)
    {
        giocatore1();
        if (check1 == X || check1 == O || pareggio == PARITY)
        {
            break;
        }

        giocatore2();
        if (check1 == X || check1 == O || pareggio == PARITY)
        {
            break;
        }
    }

    // vincita player1
    if (check1 == X)
    {
        printf("\n %s HAI VINTO!!!\n", player1);
        punteggio_X++;
    }
    // vincita player2
    else if (check1 == O)
    {
        printf("\n %s HAI VINTO!!!\n", player2);
        punteggio_O++;
    }
    else
        printf("\n PAREGGIO\n");
    // mostra il punteggio di ciascun giocatore
    punteggio();
}

// istruzioni
void istruzioni()
{
    //REGOLE
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*                      REGOLE                                 *\n");
    printf("*                      FORZA 4                                *\n");
    printf("*                                                             *\n");
    printf("* Vince la partita chi allinea per primo in orizzontale       *\n");
    printf("* o verticale o obliquo quattro pedine                        *\n");
    printf("* Lo scopo del gioco e' riuscire ad allineare quattro pedine  *\n");
    printf("* dello stesso segno nella scacchiera di gioco sia            *\n");
    printf("* in verticale, orizzontale o obliquo                         *\n");
    printf("*                                                             *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
}

void casi()
{
    int scelta = getchar();
    // MENU (che si ripete finche l'utente non inserisce 0)
    do
    {
        menu();
        printf("scegli cosa fare: ");
        if (scanf("%d", &scelta))
        {
            switch (scelta)
            {
            //  [1] NUOVA PARTITA
            case 1:
                printf("\t\t\t\t\t\t FORZA 4\n");
                nomi();
                play();
                system("pause");
                break;
            //  [2] RIVINCITA
            case 2:
                play();
                system("pause");
                break;
            //  [3] PUNTEGGIO
            case 3:
                printf("\n\t\t\t\t\t\tPUNTEGGIO:\n");
                punteggio();
                system("pause");
                break;
            //  [4] ISTRUZIONI
            case 4:
                istruzioni();
                break;
            //  [0] EXIT
            case 0:
                break;
            // default
            default:
                break;
            }
        }else{
            printf("\n INSERISCI UN NUMERO!!\n");
            casi();
            break;
        }

    } while (scelta != 0);
}

// main
int main()
{
    printf("PREMI INVIO PER INIZIARE");
    casi();
    return 0;
}
