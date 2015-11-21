#include <iostream>
#include <cmath>
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "LZespolona.hh"
#include "Wektor.hh"
#include "parametry.hh"
using namespace std;

int main(int argc, char* argv[])
{
  ParametryWywolania  Param;

  if (!AnalizujParametry(argc,argv,Param)) {
    cout << endl
	 << "Wywolanie programu jest nieprawidlowe." << endl
	 << endl;
    cout<<"Poprawne wywolanie programu:"<<endl
	<< "./uklad_rownan -t [r | z ]   -r [2-5] "<<endl;
    return 1;
  }
  
  if(Param._Param_opcji_t=="r")
    {
      if(Param._Param_opcji_r==2){
	UkladRownanLiniowych<double,2>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==3){
	UkladRownanLiniowych<double,3>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==4){
	UkladRownanLiniowych<double,4>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==5){
	UkladRownanLiniowych<double,5>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==6){
	UkladRownanLiniowych<double,6>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==10){
	UkladRownanLiniowych<double,10>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==15){
	UkladRownanLiniowych<double,15>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==20){
	UkladRownanLiniowych<double,20>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==30){
	UkladRownanLiniowych<double,30>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
    }

  else if(Param._Param_opcji_t=="z")
    {
      if(Param._Param_opcji_r==2){
	UkladRownanLiniowych<LZespolona,2>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==3){
	UkladRownanLiniowych<LZespolona,3>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==4){
	UkladRownanLiniowych<LZespolona,4>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==5){
	UkladRownanLiniowych<LZespolona,5>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
      else if(Param._Param_opcji_r==6){
	UkladRownanLiniowych<LZespolona,6>   UklRown;
	cin>>UklRown;
	UklRown.RozwiazUklad_WyswietlRozwiazanie();
      }
    }

  else {
    cout << endl
	  << "Wywolanie programu jest nieprawidlowe." << endl
	  << endl;
    cout<<"Poprawne wywolanie programu:"<<endl
	<< "./uklad_rownan -t [r | z ]   -r [2-6] "<<endl;
    return 1;
  } 
}
