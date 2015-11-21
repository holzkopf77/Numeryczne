#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/////////////////////////////////////////////////////////////////////////
/*!
 * \file
 * \brief Klasa LZespolona sluzy do przechowywania liczby zespolonej w 
 * programie oraz do wykonywania operacji matematycznych na niej.
 */
class LZespolona
{
  /*!
   * brief czesc rzeczywista liczby zespolonej
   */
  double _re;
  /*!
   * brief czesc urojona liczby zespolonej
   */
  double _im;

public:
  
  /*!
   * brief Domniemany konstruktor liczby zespolonej
   */
  LZespolona(){_re=_im=0;}
  /*!
   * brief Konstruktor liczby zespolonej z 2 argumentami typu double
   */
  LZespolona(double Re,double Im){_re=Re;_im=Im;}

  /*!
   * brief Funkcja zwraca czesc rzeczywista liczby zespolonej
   */
  double Re()const{return _re;}
  /*!
   * brief Funkcja zwraca czesc urojona liczby zespolonej
   */
  double Im()const{return _im;}
  /*!
   * brief Przeciazenie operatora indeksowania dla liczby zespolonej
   */
  double  operator[](int Ind)const {return Ind==0?_re:_im;}
  /*!
   * brief Przeciazenie operatora indeksowania dla liczby zespolonej
   */
  double& operator[](int Ind)      {return Ind==0?_re:_im;}
  /*! 
   * brief Funkcja zwraca modul liczby zespolonej
   */
  double Modul() const;
  /*!
   * brief Przeciazenie operatora porownania dla liczb zespolonych
   */
  int  operator==(LZespolona const &W);
  /*!
   * brief Dodawanie liczb zespolonych
   */
  LZespolona operator+(const LZespolona& Q)const;
  /*!
   * brief Odejmowanie liczb zespolonych
   */
  LZespolona operator-(const LZespolona& B)const;
  /*!
   * brief Mnozenie liczb zespolonych
   */
  LZespolona operator*(const LZespolona& Q)const;
  /*!
   * brief Dzielenie liczb zespolonych
   */
  LZespolona operator/(const LZespolona& Q)const;
  /*!
   * brief Odejmowanie liczb zespolonych
   */
  LZespolona operator-()const;
  /*! 
   * brief Przypisanie wartosci rzeczywistej liczbie zespolonej
   */
  const double& operator=(const double &a);
  /*!
   * brief Przypisanie wartosci calkowitej liczbie zespolonej
   */
  const int& operator=(const int &a);
  /*!
   * brief Dodawanie liczby(nie zespolonej) do liczby zespolonej
   */
  friend LZespolona operator+(const double Liczba,const LZespolona &Z);
    /*!
   * brief Dodawanie liczby(nie zespolonej) do liczby zespolonej
   */
  friend LZespolona operator+(const LZespolona &Z,const double Liczba);
  /*!
   * briefMnozenie liczby(niezespolonej) z liczba niezespolona
   */
  friend LZespolona operator*(const double Liczba,const LZespolona &Z);
    /*!
   * brief Mnozenie liczby(niezespolonej) z liczba niezespolona
   */
  friend LZespolona operator*(const LZespolona &Z,const double Liczba);
  /*!
   * brief Odejmowanie od liczby zespolonej liczby niezespolonej
   */
  friend LZespolona operator-(const LZespolona &Z,const double Liczba);
  /*!
   * brief Dzielenie liczby zespolonej przez liczbe niezespolona
   */
  friend LZespolona operator/(const LZespolona &Z,const double Liczba);
};
/////////////////////////////////////////////////////////////////////////

/*!
 * brief  Wyswietlenie liczby zespolonej
 */
std::ostream& operator<<(std::ostream& Strm, 
			  const LZespolona& WyswLiczba);
/*!
 * brief Wczytywanie liczby zespolonej
 */
std::istream& operator >> (std::istream &Strm, LZespolona &Z);

#endif
