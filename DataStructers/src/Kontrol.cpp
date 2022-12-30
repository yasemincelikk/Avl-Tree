#include "Kontrol.hpp"
#include <iomanip>
#include <stdexcept>
#include "iostream"
#include "Doku.hpp"
#include "ikiliAramaAgaci.hpp"
#include "Radix.hpp"
using namespace std;
int kontrolllist = 0;
Kontrol::Kontrol()
{
}
bool Kontrol::mutasyonVarMi(ikiliAramaAgaciDugumu *ikiliAramaAgacii)
{
    Radix *radix = new Radix(ikiliAramaAgacii->veri);
    radix->sirala();
    int ortanca = radix->ortancaGetir();
    return ortanca % 50 ? 0 : 1;
}