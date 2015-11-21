#include <cmath>
#include <iostream>
#include <cstdlib>
#include "LZespolona.hh"
using namespace std;
/*!
* \file
* \brief Definicja metod klasy LZesp
*
* Zawiera definicje metod klasy LZesp.
*/

/*!
 * \brief Funkcja zwraca modul liczby zespolonej
 * \return zwraca modul liczby zespolonej
 * \pre Poprawne wczytanie liczby zespolonej
*/
double LZespolona::Modul() const
{
  return sqrt(Re()*Re()+Im()*Im());
}

/*!
* \brief Funkcja operatorowa dodaje liczby zespolone.
* \param[in] Q - liczba zespolona.
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
LZespolona LZespolona::operator+(const LZespolona& Q)const
{
  LZespolona Z;
  Z[0]=Q[0]+_re;
  Z[1]=Q[1]+_im;
  return Z;
}

/*!
* \brief Funkcja operatorowa liczbe zespolona na przeciwna
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie  liczby zespolonej
*/
LZespolona LZespolona::operator-()const
{
  LZespolona Q;
  Q[0]=-_re;
  Q[1]=-_im;
  return Q;
}

/*!
* \brief Funkcja operatorowa odejmuje liczby zespolone.
* \param[in] B - liczba zespolona.
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
LZespolona LZespolona::operator-(const LZespolona& B)const
{
  LZespolona Z;
  Z[0]=_re-B[0];
  Z[1]=_im-B[1];
  return Z;
}

/*!
* \brief Funkcja operatorowa mnozy liczby zespolone.
* \param[in] Q - liczba zespolona.
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
LZespolona LZespolona::operator*(const LZespolona& Q)const
{
  LZespolona Z;
  Z[0]=_re*Q[0]-(_im*Q[1]);
  Z[1]=_im*Q[0]+_re*Q[1];
  return Z;
}

/*!
* \brief Funkcja operatorowa sluzy do dzielenia liczby
* zespolonej przez zespolona.
* \param[in] Q - liczba zespolona.
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
LZespolona LZespolona::operator/(const LZespolona& Q)const
{
  LZespolona Z;
  Z[0]=(_re*Q[0]+_im*Q[1])/(Q[0]*Q[0]+Q[1]*Q[1]);
  Z[1]=(_im*Q[0]-_re*Q[1])/(Q[0]*Q[0]+Q[1]*Q[1]);
  return Z;
}

/*!
* \brief Funkcja operatorowa porownuje czesci rzeczywiste
* oraz czesci urojone liczby zespolonej
* \param[in] W - liczba zespolona.
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
int LZespolona::operator==(LZespolona const &W)
{
  return (_re==W[0] && _im==W[1]);
}

/*!
* \brief Funkcja operatorowa dodaje liczbe rzeczywista
* do liczby zespolonej.
* \param Z - liczba zespolona.
* \param Liczba - liczba rzeczywista
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
LZespolona operator+(const double Liczba,const LZespolona &Z)
{
  LZespolona Q=Z;
  Q[0]+=Liczba;
  return Q;
}

/*!
* \brief Funkcja operatorowa dodaje liczbe rzeczywista
* do liczby zespolonej.
* \param Z - liczba zespolona.
* \param Liczba - liczba rzeczywista
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
LZespolona operator+(const LZespolona &Z,const double Liczba)
{
  LZespolona Q=Z;
  Q[0]+=Liczba;
  return Q;
}

/*!
* \brief Funkcja operatorowa odejmuje liczbe rzeczywista
* od liczby zespolonej.
* \param Z - liczba zespolona.
* \param Liczba - liczba rzeczywista
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
LZespolona operator-(const LZespolona &Z,const double Liczba)
{
  LZespolona Q=Z;
  Q[0]-=Liczba;
  return Q;
}

/*!
* \brief Funkcja operatorowa mnozy liczbe rzeczywista
* do liczby zespolonej.
* \param Z - liczba zespolona.
* \param Liczba - liczba rzeczywista
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
LZespolona operator*(const double Liczba,const LZespolona &Z)
{
  LZespolona Q=Z;
  Q[0]*=Liczba;
  Q[1]*=Liczba;
  return Q;
}

/*!
* \brief Funkcja operatorowa mnozy liczbe rzeczywista
* do liczby zespolonej.
* \param Z - liczba zespolona.
* \param Liczba - liczba rzeczywista
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
LZespolona operator*(const LZespolona &Z,const double Liczba)
{
  LZespolona Q=Z;
  Q[0]*=Liczba;
  Q[1]*=Liczba;
  return Q;
}

/*!
* \brief Funkcja operatorowa dzieli liczbe zespolona
* przez liczbe zespolona.
* \param Z - liczba zespolona.
* \param Liczba - liczba rzeczywista
* \return Zwraca liczbe zespolona.
* \pre Poprawne wczytanie dwoch liczb zespolonych
*/
LZespolona operator/(const LZespolona &Z,const double Liczba)
{
  LZespolona Q=Z;
  Q[0]/=Liczba;
  Q[1]/=Liczba;
  return Q;
}

/*!
* \brief Funkcja operatorowa pozwala na wypisanie liczby zespolonej
* \param[in,out] &Strm - referencja do strumienia wyjsciowego
* \param[in,out] &WyswLiczba refencja do klasy typu LZesp
* \return Zwraca referencje do strumienia wyjsciowego
* \pre Poprawne wczytanie liczby zespolonej
*/
std::ostream& operator <<(std::ostream& Strm, const LZespolona& WyswLiczba)
{
  Strm<<"{"<<WyswLiczba[0]<<std::showpos<<WyswLiczba[1]<<"i}";
  return Strm;
}
/*!
 * \brief Funkcja operatorowa = pozwala przypisac
 * liczbe rzeczywista liczbie zespolonej
 * \param[in] &a - referencja do liczby rzeczywistej
 * \return Zwraca referencje do liczby rzeczywistej
 */
const double& LZespolona::operator=(const double &a)
{
  _re=a;
  _im=0;
  return a;
}

/*!
 * \brief Funkcja operatorowa = pozwala przypisac
 * liczbe calkowita liczbie zespolonej
 * \param[in] &a - referencja do liczby calkowitej
 * \return Zwraca referencje do liczby calkowitej
 * \post Liczba zostaje zrzutowana na typ rzeczywisty
 */
const int& LZespolona::operator=(const int &a)
{
  _re=(double)a;
  _im=0;
  return a;
}

/*!
* \brief Funkcja operatorowa pozwala na wczytanie liczby zespolonej
* \param[in,out] &Strm - referencja do strumienia wejsciowego
* \param[in,out] &Z referencja do klasy typu LZesp
* \return Zwraca referencje do strumienia wejsciowego
* \pre Liczbe  nalezy podawac w nawiasach klamrowych
* \pre Zawsze musi byc podana czesc rzeczywista i czesc urojona
*/
std::istream& operator >> (std::istream &Strm, LZespolona &Z)
{
  char znak;
  Strm>>znak;
  if(znak!='{'){
    Strm.setstate(ios::failbit);
    cerr<<"Brak klamry otwierajacej"<<endl;
    exit(0);
  }
  Strm>>Z[0];
  if(Strm.fail()){
    Strm.setstate(ios::failbit);
    cerr<<"Niepoprawna czesc rzeczywista liczby zespolonej"<<endl;
    exit(0);
  }
  Strm>>std::showpos>>Z[1];
  if(Strm.fail()){
    Strm.setstate(ios::failbit);
    cerr<<"Niepoprawna czesc urojona liczby zespolonej"<<endl;
    exit(0);
  }
  Strm>>znak;
  if(znak!='i'){
    Strm.setstate(ios::failbit);
    cerr<<"Brak litery i oznaczacej liczbe zespolona"<<endl;
    exit(0);
  }
  Strm>>znak;
  if(znak!='}'){
    Strm.setstate(ios::failbit);
    cerr<<"Brak klamry zamykajacej"<<endl;
    exit(0);
  }
  
  
  return Strm;
  }
