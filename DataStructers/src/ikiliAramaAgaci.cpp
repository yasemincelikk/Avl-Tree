#include "ikiliAramaAgaci.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>
#include <queue>
#include "Doku.hpp"
#include "Kontrol.hpp"
#include "Radix.hpp"
using namespace std;
ikiliAramaAgaciDugumu::ikiliAramaAgaciDugumu(Doku *d)
{
    this->veri = d;
    sol = 0;
    sag = 0;
}
ikiliAramaAgaci::ikiliAramaAgaci()
{
    kok = 0;
}
ikiliAramaAgaci::~ikiliAramaAgaci()
{
}
ikiliAramaAgaci *ikiliAramaAgaci::postOrder(ikiliAramaAgaciDugumu *aktif, ikiliAramaAgaci *ikiliAramaAgacii)
{

    if (aktif)
    {
        postOrder(aktif->sol, ikiliAramaAgacii);
        postOrder(aktif->sag, ikiliAramaAgacii);
        for (int k = 0; k < 20; k++)
        {
            if (aktif->veri->ilk->veri % 2 == 0)
            {
                aktif->veri->ilk->veri = aktif->veri->ilk->veri / 2;
            }
            Radix *radix = new Radix(aktif->veri);
            radix->sirala();
            int ortanca = radix->ortancaGetir();
            ikiliAramaAgacii->ekle(ikiliAramaAgacii->kok, aktif->veri, ortanca);
        }
    }

    return ikiliAramaAgacii;
}

int ikiliAramaAgaci::yukseklik(ikiliAramaAgaciDugumu *aktifikiliAramaAgaciDugumu)
{
    if (aktifikiliAramaAgaciDugumu)
    {
        aktifikiliAramaAgaciDugumu->yukseklik = 1 + max(yukseklik(aktifikiliAramaAgaciDugumu->sol),
                                                        yukseklik(aktifikiliAramaAgaciDugumu->sag));
        return aktifikiliAramaAgaciDugumu->yukseklik;
    }
    return -1;
}
void ikiliAramaAgaci::ekle(ikiliAramaAgaciDugumu *aktifikiliAramaAgaciDugumu, Doku *veri, int ortanca)
{
    if (aktifikiliAramaAgaciDugumu == 0)
    {
        kok = new ikiliAramaAgaciDugumu(veri);
    }
    else
    {
        if (aktifikiliAramaAgaciDugumu->veri->ilk->veri <= ortanca)
        {
            if (aktifikiliAramaAgaciDugumu->sol)
                ekle(aktifikiliAramaAgaciDugumu->sol, veri, ortanca);
            else
                aktifikiliAramaAgaciDugumu->sol = new ikiliAramaAgaciDugumu(veri);
        }
        else if (aktifikiliAramaAgaciDugumu->veri->ilk->veri > ortanca)
        {
            if (aktifikiliAramaAgaciDugumu->sag)
                ekle(aktifikiliAramaAgaciDugumu->sag, veri, ortanca);
            else
                aktifikiliAramaAgaciDugumu->sag = new ikiliAramaAgaciDugumu(veri);
        }
        else
            return;
    }
}

int ikiliAramaAgaci::maxDeger(ikiliAramaAgaciDugumu *aktif)
{
    if (aktif->sag)
        return maxDeger(aktif->sag);

    return 0;
}
int ikiliAramaAgaci::dengesizlikYonu(ikiliAramaAgaciDugumu *aktif)
{
    if (aktif == 0)
        return 0;
    return yukseklik(aktif->sol) - yukseklik(aktif->sag);
}
