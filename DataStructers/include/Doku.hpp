#ifndef Doku_hpp
#define Doku_hpp
#include "Hucre.hpp"

class Doku
{
    public:
        Doku();
        ~Doku();
        void ekle(int veri);
        int elemanSayisiGetir();
        Hucre  *dugumgetir(int a);
        int size();
        Hucre *ilk;
        int sayac;
        int elemanSayisi;
};
#endif

