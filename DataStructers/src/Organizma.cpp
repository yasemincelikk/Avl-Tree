#include "Organizma.hpp"
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
Organizma::Organizma()
{
    sayac = 0;
    ilk = 0;
}

OrganizmaDugum::OrganizmaDugum(Sistem *veri)
{
    this->veri = veri;
    sonraki = 0;
}

Organizma::~Organizma()
{
    OrganizmaDugum *gec = ilk;
    while (gec != 0)
    {
        OrganizmaDugum *sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
}

void Organizma::ekle(Sistem *veri)
{
    OrganizmaDugum *yeni = new OrganizmaDugum(veri);
    if (ilk == 0)
    {
        ilk = yeni;
        sayac++;
    }
    else
    {
        OrganizmaDugum *gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yeni;
        sayac++;
    }
}

int Organizma::elemanSayisiGetir()
{
    return sayac;
}