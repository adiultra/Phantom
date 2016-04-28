/****************************************************************************************************
TRIED TO CODE A TRUE LOGORITHMIC CUBE IN C++ FOR MY COLLECTION, (IN THE NAME OF STEP:1 FOR <<Damn+>>)
*****************************************************************************************************/

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

void main() {
    int i, j;
    char a[25][80];

    for (i = 0; i < 25; i++) {
        for (j = 0; j < 79; j++)
            a[i][j] = '.';
        a[i][79] = '\0';
    }

    for (i = 5; i < 14; i++) {

        if (i == 5 || i == 13) {
            for (j = 14; j < 30; j++)
                a[i][j] = '*';
        }

        else {
            a[i][14] = '*';
            a[i][29] = '*';
        }
    }

    for (i = 10; i < 18; i++) {
        if (i == 10 || i == 17) {
            for (j = 14 + 7; j < 29 + 6; j++)
                a[i][j] = '*';
        }
        else {
            a[i][14 + 7] = '*';
            a[i][28 + 6] = '*';
        }
    }

    int k = 0, p = 14;

    for (i = 5; i < 10; i++) {
        a[i][++p] = '*';
    }

    p = 28;

    for (i = 5; i < 10; i++) {
        a[i][++p] = '*';
    }

    p = 12;

    for (i = 14; i < 17; i++) {
        p += 2;
        a[i][p + 1] = '*';

        for (j = p + 2; j < i + 17; j++)
            a[i][j] = '_';
    }

    p = 28;

    for (i = 13; i < 18; i++) {
        p += 1;
        a[i][p] = '*';
    }

    for (i = 5; i < 18; i++) {
        if (i < 14) {
            for (j = 29; j < 29 + i - 5; j++)
                a[i][j] = '|';
        }
        else if (i >= 14) {
            for (j = 17 + i; j < 24 + i; j++)
                a[i][j] = '|';
        }
    }
    
    int t;

    for (j = 71; j >= 0; j--) {
        if (a[10][j] == '*') {
            t = j;
            break;
        }
    }

    for (i = 10; i < 18; i++) {
        a[i][t] = '*';

        for (j = t; j < 71; j++) {
            a[i][j] = '.';
        }
    }

    for (i = 0; i < 25; i++)
        puts(a[i]);

    getch();

    for (i = 0; i < 25; i++) {
        for (j = 0; j <= 78; j++) {
            if (a[i][j] == '*') {
                break;
            }
            else
                a[i][j] = 3;
        }
        for (k = 78; k >= 0; k--) {
            if (a[i][k] == '*' || a[i][k] == '|') {
                break;
            }
            else
                a[i][k] = 3;
        }
    }

    for (i = 0; i < 25; i++)
        puts(a[i]);

    getch();

    for (i = 0; i < 24; i++)

        for (j = 0; j < 80; j++) {

            if (a[i][j] == 3) {

                if (j % 2 == 0)
                    a[i][j] = 3;

                else
                    a[i][j] = 2;
            }

            if (a[i][j] == '.')
                a[i][j] = '/';
        }

    p = -1;
    k = -8;

    for (i = 0; i < 20; i++) {

        for (j = 0; j < 71; j++)

            if (a[i][j] == '/') {
                p = j;
                k = i;
                break;
            }

        if (p != -1 && k != -8)
            break;
    }

    for (i = 0; i < 20; i++) {

        for (j = 0; j < 71; j++)

            if (a[i][j] == '/') {
                a[i][j] = '-';
            }
    }

    for (i = 0; i < 25; i++) {

        for (j = 0; j < 79; j++) {

            if (a[i][j] == '-') {
                a[i][j] = ' ';
            }
        }
    }

    for (i = 0; i < 25; i++)
        puts(a[i]);

    getch();
}
