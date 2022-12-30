#include "Kuyruk.hpp"
#include <iomanip>
#include <stdexcept>
Kuyruk::Kuyruk()
{
    ilk = son = 0;
    elemanSayisi = 0;
}
Kuyruk::~Kuyruk()
{
    while (ilk != 0)
    {
        Hucre *gec = ilk;
        ilk = ilk->sonraki;
        delete gec;
    }
}
bool Kuyruk::bosmu()
{
    if (ilk == 0)
        return true;
    return false;
}
int Kuyruk::elemanSayisiGetir()
{
    return elemanSayisi;
}
void Kuyruk::ekle(int veri)
{
    if (ilk == 0)
    {
        ilk = new Hucre(veri);
        son = ilk;
    }
    else
    {
        Hucre *yeni = new Hucre(veri);
        son->sonraki = yeni;
        son = yeni;
    }
    elemanSayisi++;
}
void Kuyruk::cikar()
{
    if (ilk != 0)
    {
        Hucre *gec = ilk->sonraki;
        delete ilk;
        ilk = gec;
        if (ilk == 0)
            son = 0;
        elemanSayisi--;
    }
}
Hucre *Kuyruk::dugumgetir(int deger)
{
    Hucre *gec = ilk;
    for (int i = 0; i < deger; i++)
    {
        gec = gec->sonraki;
    }
    return gec;
}

ostream &operator<<(ostream &os, Kuyruk &Kuyruk)
{
    if (Kuyruk.ilk == 0)
        os << "----Kuyruk BOS----";
    Hucre *gec = Kuyruk.ilk;
    while (gec != 0)
    {
        os << setw(5) << gec->veri;
        gec = gec->sonraki;
    }

    os << endl;
    return os;
}

int Kuyruk::getir()
{

    if (ilk != 0)
        return ilk->veri;
    throw std::out_of_range("Kuyruk Bos");
}