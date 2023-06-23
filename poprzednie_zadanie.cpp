#include <iostream>
#include "poprzednie_zadanie.h"

using namespace std;

int wyszukiwanie_binarne(int *tab, int obecna_liczba, int l, int r)
{
    if (l >= r)
    {
        if (obecna_liczba >= tab[l])
            return l + 1;
        else
            return l;
    }

    int sr = (l + r) / 2;
    if (tab[sr] == obecna_liczba)
        return l + 1;
    if (obecna_liczba > tab[sr])
        return wyszukiwanie_binarne(tab, obecna_liczba, sr + 1, r);
    else
        return wyszukiwanie_binarne(tab, obecna_liczba, l, sr - 1);
}
void sortowanie_binarne(int* tab,int* dzialki, int n)
{
    for (int x = 1; x < n; x++)
    {
        int obecna_liczba = tab[x];
        int wybrana_dzialka = dzialki[x];
        int y = x - 1;
        int pozycja = wyszukiwanie_binarne(tab, obecna_liczba, 0, y);

        for (y = x - 1; y >= pozycja; y--)
        {
            tab[y + 1] = tab[y];
            dzialki[y+1]=dzialki[y];
        }
        tab[pozycja] = obecna_liczba;
        dzialki[pozycja] = wybrana_dzialka;
    }
}
