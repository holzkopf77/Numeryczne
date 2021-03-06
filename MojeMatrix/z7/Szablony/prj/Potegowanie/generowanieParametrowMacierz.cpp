#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
int main(int argc, char *argv[])
{
  fstream plik;
  fstream plikOutxy;
  //  fstream plikOuty;
  fstream plikOutxz;
  double temp=0;
  plik.open("daneLotu1.txt",ios::in);
  plikOutxy.open("daneWyjscioweLotuxy.txt",ios::out);
  //plikOuty.open("daneWyjscioweLotuy.txt",ios::out);
  plikOutxz.open("daneWyjscioweLotuxz.txt",ios::out);
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
  //dane x + wektor y
  for(int i=0;i<=potega;++i)
    {
      for(int j=0;j<danex.size();++j)
	plikOutxy<<" "<<pow(daney[j],potega-i); //uwaga y
      plikOutxy<<endl;
    }
  for(int i=0;i<daney.size();++i)
    {
      plikOutxy<<" "<<danex[i]; //uwaga x
    }

  for(int i=0;i<=potega;++i)
    {
      for(int j=0;j<danex.size();++j)
	plikOutxz<<" "<<pow(danex[j],potega-i);
      plikOutxz<<endl;
    }
  for(int i=0;i<daney.size();++i)
    {
      plikOutxz<<" "<<danez[i];
    }

  /*  for(int i=0;i<=potega;++i)
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
      }*/
  cout<<(potega+1);
  return 0;
}
