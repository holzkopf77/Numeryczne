//Model struktury zostaly wykorzystany z materialow danych przez dr Kreczmera
#ifndef PARAMETRY_HH
#define PARAMETRY_HH

#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include <unistd.h>
#define ROZMIAR_LINII 100
using namespace std;
/*!
 * \file
 * \brief Struktura zawiera wszystkie pola odpowiadajace parametrom 
 * z jakimi moze zostac wywolany program. Posiada funkcje
 * analizujaca parametry i Konwertujaca napis na liczbe
 */
struct ParametryWywolania {
  string    _Param_opcji_t;
  double  _Param_opcji_r;

  ParametryWywolania() 
   {    
     _Param_opcji_r = numeric_limits<double>::max(); 
   }
};

/*!
 * \brief Kowertuje napis zawierający znaki cyfr na liczbe reprezentowana
 * przez ten napis.
 */
bool Konwertu_NapisNaLiczbe( const char* wNapis, double &Liczba );

/*!
 * \brief Analizuje parametry linii wywolania i inicjalizuje odpowienie pola
 * w strukturze "ParametryWywolania", ktore odpowiadaja poszczegolnym
 * parametrom.
 */
bool AnalizujParametry(int argc, char* argv[], ParametryWywolania &  Param);

#endif
