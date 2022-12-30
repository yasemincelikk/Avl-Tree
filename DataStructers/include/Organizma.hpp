#ifndef organizma_hpp
#define organizma_hpp
#include "Sistem.hpp"
class OrganizmaDugum
{
public:
    OrganizmaDugum(Sistem * veri);
    Sistem *veri;
    OrganizmaDugum* sonraki;
};
class Organizma
{
    public:
        Organizma();
        ~Organizma();
        void ekle(Sistem *veri);
        int elemanSayisiGetir();
        OrganizmaDugum *ilk;
        int sayac;
};
#endif


