//Wykorzystane ponizej funkcje sa funkcja wykonanymi przez dr Kreczmera
#include "parametry.hh"
#define ROZMIAR_LINII 100
/*!
 * \file
 * \brief funkcje sluzacy do przetwarzania argumentow
 * podanych w konsoli
 */

/*!
 * \brief Kowertuje napis zawierający znaki cyfr na liczbe reprezentowana
 * przez ten napis.
 *
 * \param[in] wNapis - wskaznik na napis reprezentujacy liczbe calkowita,
 * \param[in] Liczba - wpiswany jest do tego parametru wynik konwersji napisu
 *           na liczbe.
 *
 * \pre Napis musi zawierac ciag cyfr, ktore nie sa oddzielne spacjami.
 * \pre Musi on reprezntowac liczbe calkowita, ktora miesci sie w przedziale
 *    wartosci typu int.
 *
 * \return true - jesli operacja konwersji zakonczyla sie poprawnie,
 * \return false - w przypadku przeciwnym.
 */
bool Konwertu_NapisNaLiczbe( const char* wNapis, double &Liczba )
{
  istringstream  StrWe(wNapis);
  char           ZnakTestowy;
  
  StrWe >> Liczba;
  if (StrWe.fail()) return false;
  StrWe >> ZnakTestowy; // Jesl operacja zakonczy sie powodzeniem, to ZLE!!!
                        // Wynika z tego, ze napis zawiera dodatkowe znaki,
                        // ktore nie sa cyframi.
  return StrWe.fail();
}

/*!
 * \brief Analizuje parametry linii wywolania i inicjalizuje odpowienie pola
 * w strukturze "ParametryWywolania", ktore odpowiadaja poszczegolnym
 * parametrom.
 * \param[in]  argc - ilosc parametrow z linii wyolania programu.
 * \param[in]  argv - tablica napisow zawieraja (w postaci napisow) poszczegolne
 *          parametry wywolania programu.
 * \param[in] Param - jego pola odpowiadaja poszczegolnym parametrom wywolania.
 *
 * \pre argc, argv - zawieraja poprawna ilosc i tablice parametrow wywolania.
 *
 * \post Param - zostaje zainicjalizowana zgodnie z lista parametrow wywolania
 *           programu (o ile one wystapily).        
 * \return true - jeśli operacja się powiodła, tzn. wszystkie opcje wywołania i
 *           ich parametry są poprawne,
 * \return false - w przypadku przeciwnym.
 */
bool AnalizujParametry(int argc, char* argv[], ParametryWywolania &  Param)
{
  char Opt;

  while ((Opt = getopt(argc,argv,"t:r:")) != -1) {
    switch (Opt) {

    case 't' :
      Param._Param_opcji_t = optarg;
      break;

    case 'r' :
      if (!Konwertu_NapisNaLiczbe(optarg, Param._Param_opcji_r)) return false;
      break;

    default:
      return false;
    }
  }
  return true;
}
