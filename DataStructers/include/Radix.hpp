#ifndef Radix_hpp
#define Radix_hpp
#include "Doku.hpp"
#include "Kuyruk.hpp"

class Radix
{
public:
    Radix(Doku * hucreler);
    ~Radix();
    int* sirala();
    int  ortancaGetir();
    void KuyrukUzunluklariGetir(int* uzunluklar);
    Kuyruk** Kuyruklar;
    int* hucreler;
    int     maxBasamakSayisiGetir();
    int     basamakSayisiGetir(int sayi);
    int     hucreAdedi;
};

#endif