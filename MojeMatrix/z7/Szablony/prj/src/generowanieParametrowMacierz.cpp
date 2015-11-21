#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
int main(int argc, char *argv[])
{
  fstream plik;
  fstream plikOutx;
  fstream plikOuty;
  fstream plikOutz;
  double temp=0;
  plik.open("daneLotu1.txt",ios::in);
  plikOutx.open("daneWyjscioweLotux.txt",ios::out);
  plikOuty.open("daneWyjscioweLotuy.txt",ios::out);
  plikOutz.open("daneWyjscioweLotuz.txt",ios::out);
  vector<double> danex;  vector<double> daney;   vector<double> danez;
  int wspolrzedna=0; //jezeli 0-x,1-y,2-z

  while(!plik.eof()){
    plik>>temp;
    if(temp==-123456789)//bo wczytujemy double a nie int
      {
      wspolrzedna++;
      plik>>temp;
	}
    if(!wspolrzedna)
      danex.push_back(temp);
    else if(wspolrzedna==1)
      daney.push_back(temp);
    else if(wspolrzedna==2)
    danez.push_back(temp);
  }
  danez.pop_back(); //bo dodatkowy znak na koncu
  int potega=danex.size()-1;
  for(int i=0;i<=potega;++i)
    {
      for(int j=0;j<danex.size();++j)
	plikOutx<<" "<<pow(danex[j],potega-i);
      plikOutx<<endl;
    }
    for(int i=0;i<=potega;++i)
    {
      for(int j=0;j<daney.size();++j)
	plikOuty<<" "<<pow(daney[j],potega-i);
      plikOuty<<endl;
    }

  for(int i=0;i<=potega;++i)
    {
      for(int j=0;j<danez.size();++j)
	plikOutz<<" "<<pow(danez[j],potega-i);
      plikOutz<<endl;
      }
  cout<<potega;
  return 0;
}
