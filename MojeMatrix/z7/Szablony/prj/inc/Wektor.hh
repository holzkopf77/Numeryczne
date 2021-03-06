#ifndef WEKTOR_HH
#define WEKTOR_HH
#include <iomanip>
#include <iostream>
#include "LZespolona.hh"
////////////////////////////////////////////////////////////////////
/*!
 * \file
 * \brief Szablon Klasy wektor modeluje wektor w programie, 
 * przechowuje go jako 3elementowa tablice typu double
 * Jej metody to operacje arytmetyczne na wektorach.
 */
template <typename Typ, int ROZMIAR>
class Wektor {
  Typ _V[ROZMIAR];
    
  public:
  /*!
   * \brief Przeciazenia indeksow dla wektora
   * Funkcja operatorowa [] sluzy do indeksowania
   * klasy Wektor,by moc odnosic sie w bezposredni
   * sposob do tablicy typu double tej klasy.
   * \pre poprawny argument(int) w indeksie
   * \return wynik,jako wartosc double zwracana przez funkcje
   */
  Typ operator[](int Ind)const {return _V[Ind];}
  /*!
   * \brief Przeciazenia indeksow dla wektora
   * Funkcja operatorowa [] sluzy do indeksowania
   * klasy Wektor,by moc odnosic sie w bezposredni
   * sposob do tablicy typu double tej klasy.
   * \pre poprawny argument(int) w indeksie
   * \return wynik,jako wartosc double zwracana przez funkcje
   */
  Typ& operator[](int Ind)      {return _V[Ind];}
  
  /*!
   * \brief Szablon funkcji operatorowej * sluzy do mnozenia wektora przez liczbe
   */
Wektor<Typ,ROZMIAR> operator*(double liczba)const;
  /*!
   * \brief Szablon funkcji operatorowej + sluzy do dodawania dwoch wektorow
   */
  Wektor<Typ,ROZMIAR> operator+(Wektor<Typ,ROZMIAR> Q)const;
  /*!
   * \brief Szablon Funkcji operatorowej - sluzy do odejmowania dwoch wektorow
   */
  Wektor<Typ,ROZMIAR> operator-(Wektor<Typ,ROZMIAR> Q)const;
  /*!
   * \brief Szablon funkcji operatorowej * sluzy do mnozenia liczby przez wektor
   */
template<typename T,int rozmiarek>
friend Wektor<T,rozmiarek> operator*(const double Liczba,const Wektor<T,rozmiarek> _V);
  /*!
   * \brief Szablon funkcji operatorowej / sluzy do dzielenia wektora przez liczbe. 
   */
  Wektor<Typ,ROZMIAR> operator/(double Liczba)const;
  /*!
   * \brief Szablon funkcji operatorowej * sluzy do mnozenia wektor przez wektor
   */
  Typ operator*(Wektor<Typ,ROZMIAR> Q)const;
  /***********************************************************/
};
/////////////////////////////////////////////////////////////////////////

/*!
 * \brief Szablon funkcji operatorowej >> sluzy do wczytywania wektora 
 * skladajacego sie z liczb podanych przez uzytkownika
 * \return referancja do strumienia wejsciowego
 * \param[in,out] &Strm - referencja do strumienia wejsciowego
 * \param[in,out] &Wek - referencja do szablonu klasy typu Wektor
 * \pre Wymagane sa liczby w ilosci stalej ROZMIAR
 */
template<typename Typ,int ROZMIAR>
std::istream& operator>>(std::istream &Strm, Wektor<Typ,ROZMIAR> &Wek)
{
  for(int i=0;i<ROZMIAR;i++)Strm>>Wek[i];
  return Strm;
}

/*!
 * \brief Szablon funkcji operatorowej << sluzy do wypisywanie na strumien wejsciowy 
 * wektora sladajacego sie z liczb znajdujacych sie w pamieci
 * \return  referencja do strumienia wejsciowego
 * \param[in,out] &Strm - referencja do strumienia wejsciowego
 * \param[in,out] &Wek - referencja do szablonu klasy typu Wektor
 */
template<typename Typ,int ROZMIAR>
std::ostream& operator<<(std::ostream &Strm, const Wektor<Typ,ROZMIAR> &Wek)
{
  Strm<<std::setw(6)<<" ";
  for(int i=0;i<ROZMIAR;i++)Strm<<std::setw(5)<<Wek[i]<<" ";
  Strm<<std::endl;
  return Strm;
}

/*!
   * \brief Szablon funkcji operatorowej * sluzy do mnozenia wektora przez liczbe
   * \return element typu Wektor
   * \param Liczba- liczba rzeczywista
   * \pre poprawne wczytanie wektora i podanie liczby
   * \return mnozenie wektora przw wektor, wartosc zwracana przez funkcje
   */
template<typename Typ,int ROZMIAR>
Wektor<Typ, ROZMIAR>Wektor<Typ, ROZMIAR>::operator*(double Liczba)const
{
  Wektor<Typ,ROZMIAR> Q;
  for(int i=0;i<ROZMIAR;i++) Q[i]=Q[i]*_V[i]*Liczba;
  return Q;
}

/*!
   * \brief Szablon funkcji operatorowej * sluzy do mnozenia liczby przez wektor
   * \return referencja Wektor
   * \param[in] Liczba - liczba rzeczywista
   * \param[in] _V - wektor
   * \pre  poprawne wczytanie wektora i podanie liczby
   * \return mnozenie liczby przez wektor, wynik jako wartosc zwracana przez funkcje
   */
template<typename Typ,int ROZMIAR>
Wektor<Typ,ROZMIAR> operator*(const double Liczba,const Wektor<Typ,ROZMIAR> _V)
{
  Wektor<Typ,ROZMIAR> Q=_V;
  for(int i;i<ROZMIAR;i++) Q[i]=Q[i]*Liczba;
  return Q;
}

/*!
   * \brief Szablon funkcji operatorowej * sluzy do mnozenia wektor przez wektor
   * \return  element typu double
   * \param[in] Q- element typu szablon wektor
   * \pre  poprawne wczytanie 2 wektorow
   * \return  mnozenie wektora przez wektor, wynik jako wartosc zwracana przez funkcje
   */
template<typename Typ,int ROZMIAR>
Typ Wektor<Typ, ROZMIAR>::operator*(Wektor<Typ,ROZMIAR> Q)const
{
  Typ wynik_skalaru;
  for(int i=0;i<ROZMIAR;i++)
    wynik_skalaru=wynik_skalaru+_V[i]*Q[i];
  return wynik_skalaru;
}

  /*!
   * \brief Szablon funkcji operatorowej + sluzy do dodawania dwoch wektorow
   * \return  referencja Wektor
   * \param[in] Q - argument typu szablon Wektor
   * \pre poprawne wczytanie dwoch wektorow
   * \return dodanie dwoch wektorow, wynik jako wartosc zwracana przez funkcje
   */
template<typename Typ,int ROZMIAR>
Wektor<Typ,ROZMIAR> Wektor<Typ, ROZMIAR>::operator+(Wektor<Typ,ROZMIAR> Q)const
{
  Wektor<Typ,ROZMIAR> Z;
  for(int i=0;i<ROZMIAR;i++)Z[i]=_V[i]+Q[i];
  return Z;
}

/*!
   * \brief Szablon Funkcji operatorowej - sluzy do odejmowania dwoch wektorow
   * \return  referencja do Wektor
   * \param[in] Q - argument typu szablon Wektor
   * \pre  poprawne wczytanie dwoch wektorow
   * \return odjecie dwoch wektorow, wynik jako wartosc zwracana przez funkcje
   */
template<typename Typ,int ROZMIAR>
Wektor<Typ, ROZMIAR> Wektor<Typ, ROZMIAR>::operator-(Wektor<Typ, ROZMIAR> Q)const
{
  Wektor Z;
  for(int i=0;i<ROZMIAR;i++) Z[i]=_V[i]-Q[i];
  return Z;
}

  /*!
   * \brief Szablon funkcji operatorowej / sluzy do dzielenia wektora przez liczbe. 
   * \return referencja Wektor
   * \param[in] Liczba - liczba rzeczywista
   * \pre poprawne wczytanie wektora i podanie liczby
   * \return dzielenie wektora przez liczbe, wynik jako wartosc zwracana przez funkcje
   */
template<typename Typ,int ROZMIAR>
Wektor<Typ,ROZMIAR> Wektor<Typ, ROZMIAR>::operator/(double Liczba)const
{
  Wektor<Typ,ROZMIAR> Z;
  for(int i=0;i<ROZMIAR;i++)Z[i]=_V[i]/Liczba;
  return Z;
}

#endif
