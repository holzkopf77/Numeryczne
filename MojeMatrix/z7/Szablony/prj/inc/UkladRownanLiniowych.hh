#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH
#include "Macierz.hh"
#include <iostream>
#include <cstdlib>
using namespace std;
///////////////////////////////////////////////////////////////////////////
/*!
 * \file
 * \brief Klasa UkladRownanLiniowych modeluje w programie
 * Macierz wspolczynnikow rownania, wektor wyrazow
 * wolnych. Sklada sie z metody do rozwiazania ukladu i 
 * wyswietlenia tego rozwiazania.
 */
template <typename Typ, int ROZMIAR>
class UkladRownanLiniowych {  
  
  Macierz<Typ,ROZMIAR> Mac;
  Wektor<Typ,ROZMIAR> WyrazyWolne;
  
public:
/*!
 * \brief Szablon funkcji RozwiazUklad_WyswietlRozwiazanie sluzy do rozwiazania
 */
  Wektor<Typ,ROZMIAR> RozwiazUklad_WyswietlRozwiazanie()const;
/*!
 * \brief Szablon funkcji operatorowej >> sluzy do wczytywania 
 * calego wyrazenia (tj macierzy wspolczynnikow oraz 
 * wektora wyrazow wolnych podanych przez uzytkownika)
 */
  template <typename T,int rozmiarek>
  friend std::istream& operator >> (std::istream &Strm, 
				  UkladRownanLiniowych<T,rozmiarek> &UklRown);
/*!
 * \brief Szablon funkcji operatorowej << sluzy do wypisywania na strumien wyjsciowy
 * calego wyrazenia skladajacego sie z liczb znajdujacych sie w pamieci
 */
  template <typename T,int rozmiarek>
  friend std::ostream& operator << (std::ostream &Strm, 
				    const UkladRownanLiniowych<T,rozmiarek> &UklRown);
/**********************************************************************/
};
//////////////////////////////////////////////////////////////////////////

/*!
 * \brief Szablon funkcji operatorowej >> sluzy do wczytywania 
 * calego wyrazenia (tj macierzy wspolczynnikow oraz 
 * wektora wyrazow wolnych podanych przez uzytkownika)
 * \return  referencja do strumienia wejsciowego
 * \param[in,out] &Strm - referencja do strumienia wejsciowego
 * \param[in,out] &UklRown - referencja do szablonu klasy typu UkladRownanLiniowych
 */
template <typename Typ, int ROZMIAR>
istream& operator>>(istream &Strm, UkladRownanLiniowych<Typ,ROZMIAR> &UklRown)
{
  Strm>>UklRown.Mac>>UklRown.WyrazyWolne;
  return Strm;
}

/*!
 * \brief Szablon funkcji operatorowej << sluzy do wypisywania na strumien wyjsciowy
 * calego wyrazenia skladajacego sie z liczb znajdujacych sie w pamieci
 * \return  referencja do strumienia wyjsciowego
 * \param[in,out] &Strm - referencja do strumienia wyjsciowego
 * \param[in,out] &UklRown - referencja do szablonu klasy typu UkladRownanLiniowych
 * \pre Wymagane uprzednie wczytanie liczb w ilosci 
 */
template <typename Typ, int ROZMIAR>
ostream& operator<<(ostream &Strm, const UkladRownanLiniowych<Typ,ROZMIAR> &UklRown)
{
  cout<<"Macierz A^T:"<<endl;
  cout<<UklRown.Mac<<endl;
  cout<<"Wektor wyrazow wolnych b:"<<UklRown.WyrazyWolne<<endl;
  return Strm;
}

/*!
 * \brief Szablon funkcji RozwiazUklad_WyswietlRozwiazanie sluzy do rozwiazania
 * ukladu rownan liniowych metoda cramera.
 * \pre Poprawne wczytanie UkladuRownanLiniowych
 * \return Rozwiazanie ukladu rownan i wyswietlenie wyniku.
 * \post Jezeli wyznacznik jest rowny 0, nastepuje zakonczenie programu i
 * wyswietlenie komunikatu, ze wyzacznik jest zerowy.
 */
template <typename Typ, int ROZMIAR>
Wektor<Typ,ROZMIAR> UkladRownanLiniowych<Typ,ROZMIAR>::RozwiazUklad_WyswietlRozwiazanie()const
{
  Macierz<Typ,ROZMIAR> kopia;
  kopia=Mac;
  Wektor<Typ,ROZMIAR> Wyznacznik,Wynik,WektorBledu;
  for(int i=0;i<ROZMIAR;++i)
    WektorBledu[i]=0;
  Typ WyznacznikGlowny=Mac.ObliczWyznacznik();
  cout<<endl<<WyznacznikGlowny<<endl;
  Typ blad;
  blad=0;
  Typ ZERO;
  ZERO=0;
  if(WyznacznikGlowny==ZERO){
    cerr<<"Wyznacznik glowny jest rowny 0, uklad nie moze"
	<<" byc rozwiazany metoda Cramera, Koniec dzialania programu"<<endl;
    exit(0);
  }
  //Obliczenie wyznacznikow i sprawdzenie czy sa rowne 0
  //Gdy rowne 0, koniec dzialania programu
  for(int i=0;i<ROZMIAR;i++)
    {
      kopia[i]=WyrazyWolne;
      if((Wyznacznik[i]=kopia.ObliczWyznacznik())==ZERO){
	cerr<<"Wyznacznik "<<i+1<<" jest rowny 0, uklad nie posiada"
	    <<" jednego rozwiazania, Koniec dzialania programu."<<endl<<endl;
	exit(0);
      }
      kopia[i]=Mac[i];
      Wynik[i]=Wyznacznik[i]/WyznacznikGlowny;
    }

  cout<<endl<<"Macierz A^T:"<<endl<<endl;
  cout<<Mac<<endl;
  cout<<"Wektor wyrazow wolnych b:"<<endl<<endl<<WyrazyWolne<<endl;
  cout<<"Rozwiazanie x= (";
  
  for(int i=0;i<ROZMIAR-1;i++)
    cout<<"x"<<i+1<<", ";
  cout<<"x"<<ROZMIAR<<") :"<<endl<<endl<<Wynik<<endl<<endl;
  
  //Obliczenie wektora bledu i wyswietlenie jego wartosci
  kopia.Transpozycja();
  WektorBledu=kopia*Wynik-WyrazyWolne;
  blad=(WektorBledu*WektorBledu);
  cout<<setw(22)<<"Wektor bledu:"<<setw(9)<<"Ax-b"<<"   = (";
  for(int i=0;i<ROZMIAR-1;i++)
    cout<<WektorBledu[i]<<", ";
  cout<<WektorBledu[ROZMIAR-1]<<")"<<endl;
  cout<<setw(22)<<"Dlugosc wektora bledu:"<<setw(14)
      <<"||Ax-b|| = "<<blad<<endl<<endl;

  return Wynik;
}

#endif
