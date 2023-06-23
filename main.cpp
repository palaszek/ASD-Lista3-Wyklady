#include <iostream>
#include <algorithm>
#include "poprzednie_zadanie.h"
using namespace std;

struct Wyklad
{
	int start, koniec;
	int czas_wykladu;
};

bool Czym_sortowac(Wyklad wyklad1, Wyklad wyklad2)
{
	return wyklad1.koniec < wyklad2.koniec;
}

int Maksymalne_wykorzystanie(Wyklad wyklady[], int n)
{
	int i = 1, j = 0;
	int* maksymalne_czasy_wykladow = new int[n];
	for (int x = 0; x < n; x++)
	{
		maksymalne_czasy_wykladow[x] = wyklady[x].czas_wykladu;
	}

	while (i < n)
	{
		if (wyklady[j].koniec <= wyklady[i].start)
		{
			if (maksymalne_czasy_wykladow[j] + wyklady[i].czas_wykladu > maksymalne_czasy_wykladow[i])
				maksymalne_czasy_wykladow[i] = maksymalne_czasy_wykladow[j] + wyklady[i].czas_wykladu;
		}
		j++;
		if (i == j || wyklady[j].koniec > wyklady[i].start)
		{
			j = 0;
			i++;
		}
	}
	int max_czas = maksymalne_czasy_wykladow[0];
	for(int i = 1; i < n; i++)
    {
        if(max_czas < maksymalne_czasy_wykladow[i])
            max_czas = maksymalne_czasy_wykladow[i];
    }
    return max_czas;
}

int main()
{
	int n;
	cin >> n;
	Wyklad *wyklady = new Wyklad[n];
	for (int i = 0; i < n; i++)
	{
		cin >> wyklady[i].start >> wyklady[i].koniec;
		wyklady[i].czas_wykladu = wyklady[i].koniec - wyklady[i].start;
	}

	sort(wyklady, wyklady + n, Czym_sortowac);
	cout << Maksymalne_wykorzystanie(wyklady, n);
}
