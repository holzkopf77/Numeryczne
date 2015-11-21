#ifndef MACIERZ_HH
#define MACIERZ_HH
#include "Wektor.hh"
#include <iostream>
#include "LZespolona.hh"
///////////////////////////////////////////////////////////////////
/*!
 * \file
 * \brief Szablon Klasy Macierz modeluje w programie macierz.
 * Macierz jest przechowywana w postaci Wektorow.
 * Ich ilosc zalezy od rozmiaru Macierzy.
 * Sklada sie z metody do obliczania wyznacznika i 
 * operatora indeksujacego,by bezposrednio 
 * odwolywac sie do macierzy. Sklada sie rowniez
 * z funkcji arytmetycznych na macierzach.
 */
template <typename Typ, int ROZMIAR>
class Macierz {
  /*!
   * \brief Szablon macierzy skladajacej sie z wektorow
   */
  Wektor<Typ,ROZMIAR> _Wiersz[ROZMIAR];
public:
  /*************************************************************/
  /*!
   * \brief Przeciazenia indeksow dla macierzy.
   * Funkcja operatorowa [] sluzy do indeksowania
   * klasy Macierz,by moc odnosic sie w bezposredni
   * sposob do tablicy typu Wektor tej klasy.
   * \param[in] Wie - numer wiersza macierzy
   * \pre poprawny argument(int) w indeksie
   * \return wynik,jako wartosc Wektor zwracana przez funkcje
   */
  Wektor<Typ,ROZMIAR>& operator[](int Wie)     {return _Wiersz[Wie];}
  /*!
   * \brief Przeciazenia indeksow dla macierzy.
   * Funkcja operatorowa [] sluzy do indeksowania
   * klasy Macierz,by moc odnosic sie w bezposredni
   * sposob do tablicy typu Wektor tej klasy.
   * \param[in] Wie - numer wiersza macierzy
   * \pre poprawny argument(int) w indeksie
   * \return wynik,jako wartosc Wektor zwracana przez funkcje
   */
  const Wektor<Typ,ROZMIAR>& operator[](int Wie) const{return _Wiersz[Wie];}
  /*************************************************************/
  /*!
   * \brief Szablon funkcji operatorowej * sluzy do mnozenia macierzy przez macierz
   */
  Macierz<Typ,ROZMIAR> operator*(Macierz<Typ,ROZMIAR>& Mac2);
  /*************************************************************/
  /*!
   * \brief Szablon funkcji  operatorowej * sluzy do mnozenia macierzy przez wektor
   */
  Wektor<Typ,ROZMIAR> operator*(const Wektor<Typ,ROZMIAR> Wek)const;
  /**************************************************************/
  /*!
   * \brief Szablon funkcji Transpozycja sluzy do Transponowania macierzy, czyli
   */
  Wektor<Typ,ROZMIAR>& Transpozycja();
  /**************************************************************/
  /*!
   * \brief Szablon funkcji SortowanieWierszy sluzy do zamiany wierszy w macierzy
   */
  double SortowanieWierszy();
  /*************************************************************/
  /*!
 * \brief Szablon funkcji ObliczWyznacznik sluzy do obliczenia wyznacznika
 * macierzy o zadanym rozmiarze.
 */
  Typ ObliczWyznacznik()const;
  /**************************************************************/
};
////////////////////////////////////////////////////////////////////

using namespace std;
/*!
 * \brief Szablon funkcji operatorowej >> sluzy do wczytywania macierzy 
 * skladajacej sie z wektorow podanych przez uzytkownika
 * \return  referencja do strumienia wejsciowego
 * \param[in,out] &Strm - referencja do strumienia wejsciowego
 * \param[in,out] &Mac - referencja do szablonu klasy typu Macierz
 * \return referencja do strumienia wejsciowego
 */
template <typename Typ, int ROZMIAR>
istream& operator>>(istream &Strm, Macierz<Typ, ROZMIAR> &Mac)
{
  for(int i=0;i<ROZMIAR;i++)Strm>>Mac[i];
  return Strm;
}

/*!
 * \brief Szablon funkcji operatorowej << sluzy do zapisywania
 * na strumien wyjsciowy macierzy sladajacej sie z 
 * liczb znajdujacych sie w pamieci
 * \return Zwraca referencje do strumienia wyjsciowego
 * \param[in,out] &Strm - referencja do strumienia wyjsciowego
 * \param[in,out] &Mac - referencja do szablonu klasy typu Macierz
 */
template <typename Typ, int ROZMIAR>
ostream& operator<<(ostream &Strm, const Macierz<Typ,ROZMIAR> &Mac)
{
  for(int i=0;i<ROZMIAR;i++)Strm<<Mac[i];
  return Strm;
}

  /*!
   * \brief Szablon funkcji  operatorowej * sluzy do mnozenia macierzy przez wektor
   * \param[in] Wek - wektor
   * \pre  poprawne wczytanie wektora i macierzy
   * \return mnozenie macierzy przez wektor, wynik jako wartosc zwracana przez funkcje
   */
template <typename Typ, int ROZMIAR>
Wektor<Typ,ROZMIAR> Macierz<Typ,ROZMIAR>::operator*(const Wektor<Typ,ROZMIAR> Wek)const
{
  Wektor<Typ,ROZMIAR> kopia;
  for(int i=0;i<ROZMIAR;i++)
    kopia[i]=_Wiersz[i]*Wek;
  return kopia;
}

/*!
 * \brief Szablon funkcji Transpozycja sluzy do Transponowania macierzy, czyli
 * zamiany wierszy z kolumnami. Zwraca element typu o wektor
 * o rozmiarze macierzy.Jej elementem jest referencja do macierzy.
 * \pre Poprawnie wczytana macierz
 * \return Wiersze i kolumny zostaja zamienione w macierzy
 */
template <typename Typ, int ROZMIAR>
Wektor<Typ,ROZMIAR>& Macierz<Typ,ROZMIAR>::Transpozycja()
{
  Macierz kopia;
  for(int i=0;i<ROZMIAR;i++)
   for(int j=0;j<ROZMIAR;j++)
     kopia[i][j]=_Wiersz[j][i];

  for(int i=0;i<ROZMIAR;i++)
    _Wiersz[i]=kopia[i];
 return _Wiersz[ROZMIAR];
}

/*!
 * \brief Szablon funkcji operatorowej * sluzy do mnozenia macierzy przez macierz
 * \return element typu Macierz
 * \param[in] &Mac2 - szablon referencji do klasy typu Macierz 
 * \pre poprawne wczytanie macierzy
 * \return  mnozenie macierzy przez macierz, wynik jako wartosc zwracana przez funkcje
*/
template <typename Typ, int ROZMIAR>
Macierz<Typ,ROZMIAR> Macierz<Typ,ROZMIAR>::operator*(Macierz<Typ,ROZMIAR>& Mac2)
{
  Macierz<Typ,ROZMIAR> kopia;
  Mac2.Transpozycja();
 for(int i=0;i<ROZMIAR;i++)
   {
     for(int j=0;j<ROZMIAR;j++)
       kopia[i][j]=_Wiersz[i]*Mac2[j];
   }
 Mac2.Transpozycja();
 return kopia;
}

/*!
 * \brief Szablon funkcji SortowanieWierszy sluzy do zamiany wierszy w macierzy
 * by na jej glownej przekatnej znajdowala sie liczba rozna od 0
 * Jako argument przyjmuje referencje do macierzy. Zwraca element
 * typu double.
 * \pre Poprawnie wczytana macierz
 * \return wynik typu double jest rowny 1,gdy 2n wierszy zamienione, -1 gdy 2n+1
 */
template <typename Typ, int ROZMIAR>
double Macierz<Typ,ROZMIAR>::SortowanieWierszy()
{
  int znak_wyznacznika=1;
  Typ ZERO;
  ZERO=0;
  for(int i=0;i<ROZMIAR;i++)
    {
      if(_Wiersz[i][i]==ZERO)
	{
	  int k=i;
	  while(_Wiersz[k][i]==ZERO && k<ROZMIAR)k++;
	  if(k<ROZMIAR){
	  //Zamiana wierszy,znaku wyznacznika
	    Wektor<Typ,ROZMIAR> temp=_Wiersz[k];
	    _Wiersz[k]=_Wiersz[i];
	    _Wiersz[i]=temp;
	    znak_wyznacznika*=-1;
	  }
	}
    }
  return znak_wyznacznika;
}

/*!
 * \brief Szablon funkcji ObliczWyznacznik sluzy do obliczenia wyznacznika
 * macierzy o zadanym rozmiarze. Zwraca element typu bool
 * Jej elementem jest referencja do macierzy
 * \pre Poprawnie wczytana macierz
 * \return Zostaje obliczony wyznacznik
 * \return wartosc true gdy wyznacznik rozny od 0, false,gdy rowny 0.
 */
template <typename Typ, int ROZMIAR>
Typ Macierz<Typ,ROZMIAR>::ObliczWyznacznik()const
{
  Typ ZERO;
  ZERO=0;
  int znak_wyznacznika=1;   //ustalenie znaku przy zamianie wierszy,kolumn
  Macierz<Typ,ROZMIAR> macierz;      //kopia danej macierzy
  for(int i=0;i<ROZMIAR;i++)
    macierz[i]=_Wiersz[i];
  int ilosc_zer=0;          //sprawdza ilosc 0 czy wiersz lub kolumna zerowa
  Typ wyznacznik;
  
  //Jezeli wiersz  macierzy ma same 0 wyznacznik=0
  // for(int i=0;i<ROZMIAR;i++)
   for(int i=0;i<ROZMIAR;i++)
    {
      ilosc_zer=0;
      for(int j=0;j<ROZMIAR;j++)
	{
	  if((macierz[i][j])==ZERO)ilosc_zer++;
	  else break;
	}
      if(ilosc_zer==ROZMIAR)return ZERO;
    }
  
   
  //Jezeli kolumna macierzy ma same 0 wyznacznik=0
  //Zostaly zamienione tyllko liczniki i,j w stosunku do tamtej petli
  for(int j=0;j<ROZMIAR;j++)
    {
      ilosc_zer=0;
      for(int i=0;i<ROZMIAR;i++)
	{
	  if(macierz[i][j]==ZERO)ilosc_zer++;
	  else break;
	}
      if(ilosc_zer==ROZMIAR)return ZERO;
    }
  
  //Sortowanie wierszy,by umozliwic obliczenie wyznacznika
  znak_wyznacznika*=macierz.SortowanieWierszy();
  //Sortowanie kolumn, by umozliwic obliczenie wyznacznika
  macierz.Transpozycja();
  znak_wyznacznika*=macierz.SortowanieWierszy();
  macierz.Transpozycja();
  
  Typ mnoznik;
  int k;
  //eliminacja wspolczynnikow
      for(int i=0;i<ROZMIAR-1;i++)
	{
	  for(int j=i+1;j<ROZMIAR;j++)
	    {
	      //Jezeli po wszystkich sortowaniach wystepuje
	      //element zerowy na przekatnej to Wyznacznik=0
	      if(macierz[i][i]==ZERO)return ZERO;
	      mnoznik=(-macierz[j][i])/macierz[i][i];
	      for(k=i;k<ROZMIAR;k++)
		macierz[j][k]=macierz[j][k]+mnoznik*macierz[i][k];
	    }
	  znak_wyznacznika*=macierz.SortowanieWierszy();
	}
      
      //Obliczenie Wyznacznika
      wyznacznik=macierz[0][0];
      for(int i=0;i+1<ROZMIAR;i++)
	wyznacznik=wyznacznik*macierz[i+1][i+1];
      wyznacznik=wyznacznik*znak_wyznacznika;
	
return wyznacznik;
}
#endif
