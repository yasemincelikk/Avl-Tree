#ifndef ikiliAramaAgaci_hpp
#define ikiliAramaAgaci_hpp
#include<iostream>
#include "Doku.hpp"
using namespace std;

class ikiliAramaAgaciDugumu
{
public:
    int ortanca;
    ikiliAramaAgaciDugumu* sag;
    ikiliAramaAgaciDugumu* sol;
	Doku*veri;
	int yukseklik;
    ikiliAramaAgaciDugumu(Doku*veri);
    ~ikiliAramaAgaciDugumu();
};

class ikiliAramaAgaci
{
public:
	ikiliAramaAgaci();
	~ikiliAramaAgaci();
	void ekle( ikiliAramaAgaciDugumu*veri,Doku* veri2,int ortanca);
	int dengesizlikYonu(ikiliAramaAgaciDugumu* aktif);
	ikiliAramaAgaci *postOrder(ikiliAramaAgaciDugumu* aktif,ikiliAramaAgaci *ikiliAramaAgacii);
	int maxDeger(ikiliAramaAgaciDugumu* aktif);
	int yukseklik(ikiliAramaAgaciDugumu* aktifDugum);
	ikiliAramaAgaciDugumu* kok;
	Doku **dokulist;
};

#endif