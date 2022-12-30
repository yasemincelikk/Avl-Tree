#include "Doku.hpp"
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
Doku::Doku()
{
    sayac = 0;
    ilk = 0;
}
Doku::~Doku()
{
    Hucre *gec = ilk;
    while (gec != 0)
    {
        Hucre *sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
}
void Doku::ekle(int veri)
{
    Hucre *yeni = new Hucre(veri);
    if (ilk == 0)
    {
        ilk = yeni;
        sayac++;
    }
    else
    {
        Hucre *gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yeni;
        sayac++;
    }
}

int Doku::elemanSayisiGetir()
{
    return sayac;
}

int Doku::size()
{
    Hucre *gec = ilk;
    int i = 1;
    if (ilk == 0)
    {
        return 0;
    }
    else
    {
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
            i++;
        }
    }
    return i;
}
Hucre *Doku::dugumgetir(int a)
{
    Hucre *gec = ilk;
    for (int i = 0; i < a; i++)
    {
        gec = gec->sonraki;
    }
    return gec;
}
