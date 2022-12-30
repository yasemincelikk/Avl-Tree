#include <fstream>
#include <string>
#include <iostream>
#include "Doku.hpp"
#include "Kuyruk.hpp"
#include "Radix.hpp"
#include "Organ.hpp"
#include "ikiliAramaAgaci.hpp"
#include "Sistem.hpp"
#include "Organizma.hpp"
#include "Kontrol.hpp"
#include "sstream"
#include "Test.hpp"
using namespace std;
int main()
{
    ikiliAramaAgaci *ikiliAramaAgacii = new ikiliAramaAgaci();
    Organ *organ = new Organ();
    Sistem *sistem = new Sistem();
    Organizma *organizma = new Organizma();
    ifstream veri;
    string satir;
    int dokuSayisi = 0, organSayisi = 0;
    int i = 0;
    veri.open("./veriler.txt");
    while (!veri.eof())
    {
        while (getline(veri, satir))
        {

            Doku *dokuListesi = new Doku();
            int siradakisayi;
            dokuSayisi++;
            stringstream satirokuyucu(satir);
            while (satirokuyucu >> siradakisayi)
            {
                dokuListesi->ekle(siradakisayi);
            }
            Radix *radix = new Radix(dokuListesi); // radix kuyrukla işle yapılacak şekilde düzenlenecek
            radix->sirala();
            int ortanca = radix->ortancaGetir();
            ikiliAramaAgacii->ekle(ikiliAramaAgacii->kok, dokuListesi, ortanca);
            if (dokuSayisi == 20)
            {
                organSayisi++;

                organ = new Organ();
                organ->ekle(ikiliAramaAgacii);
                sistem->SistemDizisi[i] = organ;
                i++;
                if (organSayisi == 100)
                {
                    organizma->ekle(sistem);
                    sistem = new Sistem();
                    organSayisi = 0;
                    i = 0;
                }
                ikiliAramaAgacii = new ikiliAramaAgaci();
                dokuSayisi = 0;
            }
        }
    }
     system("clear");
       cout<< "                   "     "ORGANIZMA" << endl; 
    OrganizmaDugum *gec = organizma->ilk;
    for (int i = 0; i < organizma->elemanSayisiGetir(); i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (abs(gec->veri->SistemDizisi[j]->ilk->veri->dengesizlikYonu(gec->veri->SistemDizisi[j]->ilk->veri->kok)) > 1)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        gec = gec->sonraki;
    }
    gec = organizma->ilk;
    for (int i = 0; i < organizma->elemanSayisiGetir(); i++)
    {
        for (int j = 0; j < 100; j++)
        {
            Kontrol *t = new Kontrol();
            Radix *radix = new Radix(gec->veri->SistemDizisi[j]->ilk->veri->kok->veri);
            radix->sirala();
            int ortanca = radix->ortancaGetir();
            if (t->mutasyonVarMi(gec->veri->SistemDizisi[j]->ilk->veri->kok))
            {
                Sistem *sis = gec->veri;
                ikiliAramaAgaci *r = new ikiliAramaAgaci();
                sis->SistemDizisi[j]->ilk->veri = sis->SistemDizisi[j]->ilk->veri->postOrder(sis->SistemDizisi[j]->ilk->veri->kok, r);
            }
        }
        gec = gec->sonraki;
    }
   
    Test *r=new Test();
    system("clear");
    gec = organizma->ilk;
    cout<< "             "     "ORGANIZMA(MUTASYONA UGRADI)" << endl;
    for (int i = 0; i < organizma->elemanSayisiGetir(); i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (abs(gec->veri->SistemDizisi[j]->ilk->veri->dengesizlikYonu(gec->veri->SistemDizisi[j]->ilk->veri->kok)) > 1)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        gec = gec->sonraki;
    }
}