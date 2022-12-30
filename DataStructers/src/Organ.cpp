#include "Organ.hpp"
#include <iomanip>
#include <stdexcept>
OrganDugum::OrganDugum(ikiliAramaAgaci *veri)
{

    this->veri = veri;
    sonraki = 0;
}
Organ::Organ()
{
    sayac = 0;
    ilk = 0;
}
Organ::~Organ()
{
    OrganDugum *gec = ilk;
    while (gec != 0)
    {
        OrganDugum *sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
}

void Organ::ekle(ikiliAramaAgaci *veri)
{
    OrganDugum *yeni = new OrganDugum(veri);
    if (ilk == 0)
    {
        ilk = yeni;
        sayac++;
    }
    else
    {
        OrganDugum *gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yeni;
        sayac++;
    }
}

int Organ::uzunluk()
{
    OrganDugum *gec = ilk;
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
