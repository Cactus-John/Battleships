
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    char ocean[11][11];
    char znak = 'A';

    for (int i = 0; i < 11; i++)
    {
        ocean[i][0] = i + 1;

        for (int j = 0; j < 11; j++)
        {
            znak++;

            if (i == 0)
                ocean[i][j] = znak - 2;

            else
                ocean[i][j] = '~';
        }
    }

    char player_ocean[11][11];
    znak = 'A';
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
            player_ocean[i][j] = ocean[i][j];
    }
    char ocean_PLAYER_1[11][11];
    znak = 'A';
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
            ocean_PLAYER_1[i][j] = player_ocean[i][j];
    }
    char ocean_PLAYER_2[11][11];
    znak = 'A';
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
            ocean_PLAYER_2[i][j] = ocean_PLAYER_1[i][j];
    }
    // selecting difficulty
    int diff = 0;
    printf("Select difficulty:\n\t\t\t1.NOOB\n\t\t\t2.IMPOSSIBLE\n");
    scanf("%d", &diff);
    system("clear");
    //AI GENERATED BATTLESHIP
    int r, p;
    r = rand() % 10 + 1;
    r = r % 2;
    if (r == 0)
    {
        r = rand() % 10 + 1;
        while (r + 4 > 10)
        {
            r = rand() % 10 + 1;

        }
        p = rand() % 10 + 1;
        int Battleship_cordsAI[4][4];
        for (int i = 0; i < 4; i++)
        {
            Battleship_cordsAI[i][0] = r;
            Battleship_cordsAI[i][1] = p;
            ocean[r + i][p] = '#';
        }
    }
    else
    {
        r = rand() % 10 + 1;
        p = rand() % 10 + 1;
        while (p + 4 > 10)
            p = rand() % 10 + 1;
        int Battleship_cordsAI[4][4];
        for (int i = 0; i < 4; i++)
        {
            Battleship_cordsAI[i][0] = r;
            Battleship_cordsAI[i][1] = p;
            ocean[r][p + i] = '#';
        }
    }

    // AI GENERATED CARRIER

    int sus = 0; //sus -> ships under ships
    r = rand() % 10 + 1;
    int zastavica = 0;
    r = r % 2;
    if (r == 0)
    {
        while (zastavica == 0)
        {
            r = rand() % 10 + 1;
            while (r + 5 > 10)
            {
                r = rand() % 10 + 1;
            }
            p = rand() % 10 + 1;
            int Carrier_cordsAI[5][5];
            for (int i = 0; i < 5; i++)
            {
                Carrier_cordsAI[i][0] = r;
                Carrier_cordsAI[i][1] = p;
                if (ocean[r + i][p] == '#')
                    continue;
            }
            for (int i = 0; i < 5; i++)
            {
                Carrier_cordsAI[i][0] = r;
                Carrier_cordsAI[i][1] = p;
                ocean[r + i][p] = '#';
            }
            zastavica = 1;
        }
    }
    else
    {
        while (zastavica == 0)
        {
            sus = 0;
            r = rand() % 10 + 1;
            p = rand() % 10 + 1;
            while (p + 5 > 10)
                p = rand() % 10 + 1;
            int Carrier_cordsAI[5][5];
            for (int i = 0; i < 5; i++)
            {
                Carrier_cordsAI[i][0] = r;
                Carrier_cordsAI[i][1] = p;
                if (ocean[r][p + i] == '#')
                    sus = 1;
            }
            if (sus == 1)
                continue;

            for (int i = 0; i < 5; i++)
            {
                Carrier_cordsAI[i][0] = r;
                Carrier_cordsAI[i][1] = p;
                ocean[r][p + i] = '#';
            }
            zastavica = 1;
        }
    }

    // AI GENERATED CRUISER_SHIP
    sus = 0;
    r = rand() % 10 + 1;
    zastavica = 0;
    r = r % 2;
    if (r == 0)
    {
        while (zastavica == 0)
        {
            sus = 0;
            r = rand() % 10 + 1;
            while (r + 3 > 10)
            {
                r = rand() % 10 + 1;
            }
            p = rand() % 10 + 1;
            int Cruiser_cordsAI[5][5];
            for (int i = 0; i < 3; i++)
            {
                Cruiser_cordsAI[i][0] = r;
                Cruiser_cordsAI[i][1] = p;
                if (ocean[r + i][p] == '#')
                    sus = 1;
            }
            if (sus == 1)
                continue;

            //Zapisuje u ploču
            for (int i = 0; i < 3; i++)
            {
                Cruiser_cordsAI[i][0] = r;
                Cruiser_cordsAI[i][1] = p;
                ocean[r + i][p] = '#';
            }
            zastavica = 1;
        }
    }
    else
    {
        while (zastavica == 0)
        {
            sus = 0;
            r = rand() % 10 + 1;
            p = rand() % 10 + 1;
            while (p + 3 > 10)
                p = rand() % 10 + 1;
            int Cruiser_cordsAI[3][3];
            for (int i = 0; i < 3; i++)
            {
                Cruiser_cordsAI[i][0] = r;
                Cruiser_cordsAI[i][1] = p;
                if (ocean[r][p + i] == '#')
                    sus = 1;
            }
            if (sus == 1)
                continue;

            for (int i = 0; i < 3; i++)
            {
                Cruiser_cordsAI[i][0] = r;
                Cruiser_cordsAI[i][1] = p;
                ocean[r][p + i] = '#';
            }
            zastavica = 1;
        }
    }

    // AI GENERATED SUBMARINE_SHIP

    sus = 0;
    r = rand() % 10 + 1;
    zastavica = 0;
    r = r % 2;
    if (r == 0)
    {
        while (zastavica == 0)
        {
            sus = 0;
            r = rand() % 10 + 1;
            while (r + 3 > 10)
            {
                r = rand() % 10 + 1;
            }
            p = rand() % 10 + 1;
            int Submarine_cordsAI[3][3];
            for (int i = 0; i < 3; i++)
            {
                Submarine_cordsAI[i][0] = r;
                Submarine_cordsAI[i][1] = p;
                if (ocean[r + i][p] == '#')
                    sus = 1;
            }
            if (sus == 1)
                continue;
            //Zapisuje u ploču
            for (int i = 0; i < 3; i++)
            {
                Submarine_cordsAI[i][0] = r;
                Submarine_cordsAI[i][1] = p;
                ocean[r + i][p] = '#';
            }
            zastavica = 1;
        }
    }
    else
    {
        while (zastavica == 0)
        {
            sus = 0;
            r = rand() % 10 + 1;
            p = rand() % 10 + 1;
            while (p + 3 > 10)
                p = rand() % 10 + 1;
            int Submarine_cordsAI[3][3];
            for (int i = 0; i < 3; i++)
            {
                Submarine_cordsAI[i][0] = r;
                Submarine_cordsAI[i][1] = p;
                if (ocean[r][p + i] == '#')
                    sus = 1;
            }
            if (sus == 1)
                continue;

            for (int i = 0; i < 3; i++)
            {
                Submarine_cordsAI[i][0] = r;
                Submarine_cordsAI[i][1] = p;
                ocean[r][p + i] = '#';
            }
            zastavica = 1;
        }
    }
    // AI GENERATED DESTROYER_SHIP

    sus = 1;
    r = rand() % 10 + 1;
    zastavica = 0;
    r = r % 2;
    if (r == 0)
    {
        while (zastavica == 0)
        {
            sus = 0;
            r = rand() % 10 + 1;
            while (r + 2 > 10)
            {
                r = rand() % 10 + 1;
            }
            p = rand() % 10 + 1;
            int Destroyer_cordsAI[2][2];
            for (int i = 0; i < 2; i++)
            {
                Destroyer_cordsAI[i][0] = r;
                Destroyer_cordsAI[i][1] = p;
                if (ocean[r + i][p] == '#')
                    sus = 1;
            }
            if (sus == 1)
                continue;
            //Zapisuje u ploču
            for (int i = 0; i < 2; i++)
            {
                Destroyer_cordsAI[i][0] = r;
                Destroyer_cordsAI[i][1] = p;
                ocean[r + i][p] = '#';
            }
            zastavica = 1;
        }
    }
    else
    {
        while (zastavica == 0)
        {
            sus = 0;
            r = rand() % 10 + 1;
            p = rand() % 10 + 1;
            while (p + 2 > 10)
                p = rand() % 10 + 1;
            int Destroyer_cordsAI[2][2];
            for (int i = 0; i < 2; i++)
            {
                Destroyer_cordsAI[i][0] = r;
                Destroyer_cordsAI[i][1] = p;
                if (ocean[r][p + i] == '#')
                    sus = 1;
            }
            if (sus == 1)
                continue;
            for (int i = 0; i < 2; i++)
            {
                Destroyer_cordsAI[i][0] = r;
                Destroyer_cordsAI[i][1] = p;
                ocean[r][p + i] = '#';
            }
            zastavica = 1;
        }
    }


    printf(" Enemy teritory\n");
    //Ispisuje igraču ploču protivnika
    for (int i = 0; i < 11; i++)
    {
        if (i != 10)
            printf(" %d ", i);
        else
            printf("%d ", i);
        for (int j = 1; j < 11; j++)
        {
            printf("%c\t", player_ocean[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");



    printf(" Your teritory\n");
    // Ispisuje igraču ploču igrača
    for (int i = 0; i < 11; i++)
    {
        if (i != 10)
            printf(" %d ", i);
        else
            printf("%d ", i);
        for (int j = 1; j < 11; j++)
        {
            printf("%c\t", player_ocean[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // Upsiuje koordinate carriera (1)
    int x;
    char y;
    printf("PLAYER1: place a carrier (occupies 5 spaces):\n");
    for (int i = 0; i < 5; i++)
    {
        scanf(" %c %d", &y, &x);
        switch (y)
        {
        case('A'):y = 1; break;
        case('B'):y = 2; break;
        case('C'):y = 3; break;
        case('D'):y = 4; break;
        case('E'):y = 5; break;
        case('F'):y = 6; break;
        case('G'):y = 7; break;
        case('H'):y = 8; break;
        case('I'):y = 9; break;
        case('J'):y = 10; break;
        }
        player_ocean[x][y] = '#';
        system("clear");
        for (int i = 0; i < 11; i++)
        {
            if (i != 10)
                printf(" %d ", i);
            else
                printf("%d ", i);
            for (int j = 1; j < 11; j++)
            {
                printf("%c\t", player_ocean[i][j]);
            }
            printf("\n");
        }
    }
    printf("PLAYER1: place a battleship (occupies 4 places)\n ");

    for (int i = 0; i < 4; i++)
    {
        scanf(" %c %d", &y, &x);
        switch (y)
        {
        case('A'):y = 1; break;
        case('B'):y = 2; break;
        case('C'):y = 3; break;
        case('D'):y = 4; break;
        case('E'):y = 5; break;
        case('F'):y = 6; break;
        case('G'):y = 7; break;
        case('H'):y = 8; break;
        case('I'):y = 9; break;
        case('J'):y = 10; break;
        }
        player_ocean[x][y] = '#';
        system("clear");
        for (int i = 0; i < 11; i++)
        {
            if (i != 10)
                printf(" %d ", i);
            else
                printf("%d ", i);
            for (int j = 1; j < 11; j++)
            {
                printf("%c\t", player_ocean[i][j]);
            }
            printf("\n");
        }
    }
    printf("PLAYER1: place a Submarine ship (occupies 3 spaces):\n");
    for (int i = 0; i < 3; i++)
    {
        scanf(" %c %d", &y, &x);
        switch (y)
        {
        case('A'):y = 1; break;
        case('B'):y = 2; break;
        case('C'):y = 3; break;
        case('D'):y = 4; break;
        case('E'):y = 5; break;
        case('F'):y = 6; break;
        case('G'):y = 7; break;
        case('H'):y = 8; break;
        case('I'):y = 9; break;
        case('J'):y = 10; break;
        }
        player_ocean[x][y] = '#';
        system("clear");
        for (int i = 0; i < 11; i++)
        {
            if (i != 10)
                printf(" %d ", i);
            else
                printf("%d ", i);
            for (int j = 1; j < 11; j++)
            {
                printf("%c\t", player_ocean[i][j]);
            }
            printf("\n");
        }
    }
    printf("PLAYER1: place a Cruiser ship (occupies 3 spaces)\n");
    for (int i = 0; i < 3; i++)
    {
        scanf(" %c %d", &y, &x);
        switch (y)
        {
        case('A'):y = 1; break;
        case('B'):y = 2; break;
        case('C'):y = 3; break;
        case('D'):y = 4; break;
        case('E'):y = 5; break;
        case('F'):y = 6; break;
        case('G'):y = 7; break;
        case('H'):y = 8; break;
        case('I'):y = 9; break;
        case('J'):y = 10; break;
        }
        player_ocean[x][y] = '#';
        system("clear");
        for (int i = 0; i < 11; i++)
        {
            if (i != 10)
                printf(" %d ", i);
            else
                printf("%d ", i);
            for (int j = 1; j < 11; j++)
            {
                printf("%c\t", player_ocean[i][j]);
            }
            printf("\n");
        }
    }
    printf("Place a Destroyer ship (occupies 2 spaces): \n");
    for (int i = 0; i < 2; i++)
    {
        scanf(" %c %d", &y, &x);
        switch (y)
        {
        case('A'):y = 1; break;
        case('B'):y = 2; break;
        case('C'):y = 3; break;
        case('D'):y = 4; break;
        case('E'):y = 5; break;
        case('F'):y = 6; break;
        case('G'):y = 7; break;
        case('H'):y = 8; break;
        case('I'):y = 9; break;
        case('J'):y = 10; break;
        }
        player_ocean[x][y] = '#';
        system("clear");
        for (int i = 0; i < 11; i++)
        {
            if (i != 10)
                printf(" %d ", i);
            else
                printf("%d ", i);
            for (int j = 1; j < 11; j++)
            {
                printf("%c\t", player_ocean[i][j]);
            }
            printf("\n");
        }
    }

    int hits_by_player = 0, hits_by_AI = 0, turns = 1;

    system("clear");

    // Inicijalizira igraču ploču za igrača 2 (AI)

    char ocean_PLAYER_AI[11][11];
    znak = 'A';
    for (int i = 0; i < 11; i++)
    {
        ocean_PLAYER_AI[i][0] = i + 1;
        znak++;
        for (int j = 0; j < 11; j++)
        {
            if (j == 0)
                ocean_PLAYER_AI[i][j] = ocean[i][j];
            if (i != 0)
                ocean_PLAYER_AI[i][j] = '~';
        }
    }

    // Ispisuje polje igraća 2 (AI-player 2)

    for (int i = 0; i < 11; i++)
    {
        if (i != 10)
            printf(" %d ", i);
        else
            printf("%d ", i);
        for (int j = 1; j < 11; j++)
        {
            printf("%c\t", ocean_PLAYER_2[i][j]);
        }
        printf("\n\n");
    }
    //Ispisuje polje igrača 1 (player)
    for (int i = 0; i < 11; i++)
    {
        if (i != 10)
            printf(" %d ", i);
        else
            printf("%d ", i);
        for (int j = 1; j < 11; j++)
        {
            printf("%c\t", player_ocean[i][j]);
        }
        printf("\n\n");
    }

    turns = -1;
    if (diff == 1)
    {
        while (hits_by_player < 17 || hits_by_AI < 17)
        {
            turns = turns + 1;
            // player turn
            if (turns % 2 == 0)
            {
                printf("Upisite koordinate gdje zelite gađati:\n");
                scanf(" %c %d", &y, &x);
                switch (y)
                {
                case('A'):y = 1; break;
                case('B'):y = 2; break;
                case('C'):y = 3; break;
                case('D'):y = 4; break;
                case('E'):y = 5; break;
                case('F'):y = 6; break;
                case('G'):y = 7; break;
                case('H'):y = 8; break;
                case('I'):y = 9; break;
                case('J'):y = 10; break;
                }

                if (ocean[x][y] == '#')
                {
                    hits_by_player++;
                    ocean_PLAYER_2[x][y] = 'X';
                    ocean[x][y] = 'X';
                }
                else
                {
                    ocean_PLAYER_2[x][y] = 'O';
                }
                system("clear");
                // Ispisuje polje igraća 2 (AI-player 2)
                for (int i = 0; i < 10; i++)
                {
                    if (i != 10)
                        printf(" %d ", i);
                    else
                        printf("%d ", i);
                    for (int j = 1; j < 11; j++)
                    {
                        printf("%c\t", ocean_PLAYER_2[i][j]);
                    }
                    printf("\n\n");
                }
                //Ispisuje polje igrača 1 (player)
                for (int i = 0; i < 11; i++)
                {
                    if (i != 10)
                        printf(" %d ", i);
                    else
                        printf("%d ", i);
                    for (int j = 1; j < 11; j++)
                    {
                        printf("%c\t", player_ocean[i][j]);
                    }
                    printf("\n\n");
                }
            }

            // AI turn
            if (turns % 2 == 1)
            {
                r = rand() % 10 + 1;
                p = rand() % 10 + 1;
                if (player_ocean[r][p] == '#')
                {
                    hits_by_AI++;
                    player_ocean[r][p] = 'X';
                }

                else
                {
                    player_ocean[r][p] = 'O';
                }
                system("clear");

                // Ispisuje polje igraća 2 (AI-player 2)
                for (int i = 0; i < 11; i++)
                {
                    if (i != 10)
                        printf(" %d ", i);
                    else
                        printf("%d ", i);
                    for (int j = 1; j < 11; j++)
                    {
                        printf("%c\t", ocean_PLAYER_2[i][j]);
                    }
                    printf("\n\n");
                }
                //Ispisuje polje igrača 1 (player)
                for (int i = 0; i < 11; i++)
                {
                    if (i != 10)
                        printf(" %d ", i);
                    else
                        printf("%d ", i);
                    for (int j = 1; j < 11; j++)
                    {
                        printf("%c\t", player_ocean[i][j]);
                    }
                    printf("\n\n");
                }

            }
        }
    }
    system("clear");
    // pro bot
    if (diff == 2)
    {
        turns = 0;
        while (hits_by_player < 17 || hits_by_AI < 17)
        {
            if (turns % 2 == 1)
            {
                printf("\nEnter cordinates where you want to shoot:\n");
                scanf(" %c %d", &y, &x);
                switch (y)
                {
                case('A'):y = 1; break;
                case('B'):y = 2; break;
                case('C'):y = 3; break;
                case('D'):y = 4; break;
                case('E'):y = 5; break;
                case('F'):y = 6; break;
                case('G'):y = 7; break;
                case('H'):y = 8; break;
                case('I'):y = 9; break;
                case('J'):y = 10; break;
                }
                if (ocean[x][y] == '#')
                {
                    ocean_PLAYER_2[x][y] = 'X';
                    ocean[x][y] = 'X';
                    hits_by_player++;
                }
                else
                {
                    ocean_PLAYER_2[x][y] = 'O';
                }
                // Ispisuje polje igraća 2 (AI-player 2)
                system("clear");

                for (int i = 0; i < 11; i++)
                {
                    if (i != 10)
                        printf(" %d ", i);
                    else
                        printf("%d ", i);
                    for (int j = 1; j < 11; j++)
                    {
                        printf("%c\t", ocean_PLAYER_2[i][j]);
                    }
                    printf("\n\n");
                }
                //Ispisuje polje igrača 1 (player)
                for (int i = 0; i < 11; i++)
                {
                    if (i != 10)
                        printf(" %d ", i);
                    else
                        printf("%d ", i);
                    for (int j = 1; j < 11; j++)
                    {
                        printf("%c\t", player_ocean[i][j]);
                    }
                    printf("\n\n");
                }
                // turns++;
            }
            //AI turn    
            if (turns % 2 == 0)
            {
                while (zastavica == 0 || player_ocean[r][p] != '#')
                {
                    r = rand() % 10 + 1;
                    p = rand() % 10 + 1;
                    zastavica = 1;
                }
                if (player_ocean[r][p] == '#')
                {
                    hits_by_AI++;
                    player_ocean[r][p] = 'X';
                }
                else
                    player_ocean[r][p] = 'O';
                // Ispisuje polje igraća 2 (AI-player 2)
                system("clear");

                for (int i = 0; i < 11; i++)
                {
                    if (i != 10)
                        printf(" %d ", i);
                    else
                        printf("%d ", i);
                    for (int j = 1; j < 11; j++)
                    {
                        printf("%c\t", ocean_PLAYER_2[i][j]);
                    }
                    printf("\n\n");
                }
                //Ispisuje polje igrača 1 (player)
                for (int i = 0; i < 11; i++)
                {
                    if (i != 10)
                        printf(" %d ", i);
                    else
                        printf("%d ", i);
                    for (int j = 1; j < 11; j++)
                    {
                        printf("%c\t", player_ocean[i][j]);
                    }
                    printf("\n\n");
                }
            }

            turns++;
        }

    }

    return 0;
}

}
