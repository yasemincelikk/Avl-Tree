#include "Sistem.hpp"
#include <iomanip>
#include <stdexcept>
#include "Organ.hpp"
Sistem::Sistem()
{
    this->SistemDizisi = new Organ *[100];
}