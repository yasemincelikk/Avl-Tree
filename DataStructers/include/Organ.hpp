#ifndef Organ_hpp
#define Organ_hpp
#include "ikiliAramaAgaci.hpp"
class OrganDugum
{
public:
    OrganDugum(ikiliAramaAgaci * veri);
    ikiliAramaAgaci *veri;
    OrganDugum* sonraki;
};

class Organ
{
public:
    Organ();
    ~Organ();
    void ekle(ikiliAramaAgaci* veri);
    int uzunluk();
    OrganDugum *ilk;
    int sayac;
};
#endif
























