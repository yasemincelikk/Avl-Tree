#include "Radix.hpp"
#include "Doku.hpp"
#include <iomanip>
Radix::Radix(Doku *hucreler)
{
    this->hucreAdedi = hucreler->elemanSayisiGetir();

    this->hucreler = new int[hucreAdedi];

    for (int i = 0; i < hucreAdedi; i++)
        this->hucreler[i] = hucreler->dugumgetir(i)->veri;

    Kuyruklar = new Kuyruk *[10];
    for (int i = 0; i < 10; i++)
        Kuyruklar[i] = new Kuyruk();
}
Radix::~Radix()
{
    delete[] hucreler;
    for (int i = 0; i < 10; i++)
        delete Kuyruklar[i];
    delete[] Kuyruklar;
}

int *Radix::sirala()
{

    for (int i = 0; i < hucreAdedi; i++)
    {
        int sonBasamak = hucreler[i] % 10;

        Kuyruklar[sonBasamak]->ekle(hucreler[i]);
    }
    int maxBasamakSayisi = maxBasamakSayisiGetir();

    int basamakCarpani = 10;

    for (int i = 1; i < maxBasamakSayisi; i++)
    {
        int uzunluklar[10];

        KuyrukUzunluklariGetir(uzunluklar);

        for (int j = 0; j < 10; j++)
        {
            int es = uzunluklar[j];

            while (es)
            {
                int siradakiSayi = Kuyruklar[j]->getir();

                Kuyruklar[j]->cikar();
                int basamak = (siradakiSayi / basamakCarpani) % 10;
                Kuyruklar[basamak]->ekle(siradakiSayi);
                es--;
            }
        }
        basamakCarpani *= 10;
    }
    int diziIndex = 0;
    for (int i = 0; i < 10; i++)
    {
        while (!Kuyruklar[i]->bosmu())
        {
            hucreler[diziIndex] = Kuyruklar[i]->getir();
            Kuyruklar[i]->cikar();
            diziIndex++;
        }
    }

    return hucreler;
}

int Radix::maxBasamakSayisiGetir()
{
    int maxBasamakSayisi = basamakSayisiGetir(hucreler[0]);

    for (int i = 1; i < hucreAdedi; i++)
    {
        int siradakiBasamakSayisi = basamakSayisiGetir(hucreler[i]);
        if (maxBasamakSayisi < siradakiBasamakSayisi)
            maxBasamakSayisi = siradakiBasamakSayisi;
    }
    return maxBasamakSayisi;
}
int Radix::basamakSayisiGetir(int sayi)
{
    int basamakSayisi = 0;
    while (sayi)
    {
        sayi = sayi / 10;
        basamakSayisi++;
    }
    return basamakSayisi;
}

void Radix::KuyrukUzunluklariGetir(int *uzunluklar)
{
    for (int i = 0; i < 10; i++)
    {
        uzunluklar[i] = Kuyruklar[i]->elemanSayisiGetir();
    }
}
int Radix::ortancaGetir()
{
    return hucreler[hucreAdedi / 2];
}