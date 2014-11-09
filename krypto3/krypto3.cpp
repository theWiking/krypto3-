#include <iostream>
#include <cmath>
using namespace std;
/*
void dodawnieSymetryczne(bool *k0,bool *k){
  for(int i=0;sizeof(k0)>i;i++){
    if(k0[i]==1&&k[i]==1)
      k[i]=0;
    else
      k[i]=1;
    }
} */
int naDziesietny(bool h[4]){
  int a=0;
  for(int i=0;sizeof(h)>i;i++)
    a+=h[3-i]*(pow(2,i));
    return a;
  }
void wezJednaCzwarta(bool *k0,int ktora,bool wyjscie[4]){
  for(int i=0;4>i;i++){
    wyjscie[i]=k0[i+ktora*4-4];
  }
}
void kluczPierwszejRundy(bool *k0,bool *k){
  bool czesc[4]={0};
  wezJednaCzwarta(k0,4,czesc);
  int dziesietny=naDziesietny(czesc);

   bool SboxE[16][4]={ {1,1,1,0},
                      {0,1,0,0},
                      {1,1,0,1},
                      {0,0,0,1},
                      {0,0,1,0},
                      {1,1,1,1},
                      {1,0,1,1},
                      {1,0,0,0},
                      {0,0,1,1},
                      {1,0,1,0},
                      {0,1,1,0},
                      {1,1,0,0},
                      {0,1,0,1},
                      {1,0,0,1},
                      {0,0,0,0},
                      {0,1,1,1}
       };
  for(int i=0;4>i;i++){
    k[i]=(k0[i]+SboxE[dziesietny][i]+(i==3?1:0))%2;
    k[i+4]=(k0[i+4]+k[i])%2;
    k[i+8]=(k0[i+8]+k[i+4])%2;
    k[i+12]=(k0[i+12]+k[i+8])%2;
  }
  for(int i=0;4>i;i++){

  }

  for(int i=0;4>i;i++){

  }

  for(int i=0;4>i;i++){

  }

}
int main(){

  bool SboxE[16][4]={ {1,1,1,0},
                      {0,1,0,0},
                      {1,1,0,1},
                      {0,0,0,1},
                      {0,0,1,0},
                      {1,1,1,1},
                      {1,0,1,1},
                      {1,0,0,0},
                      {0,0,1,1},
                      {1,0,1,0},
                      {0,1,1,0},
                      {1,1,0,0},
                      {0,1,0,1},
                      {1,0,0,1},
                      {0,0,0,0},
                      {0,1,1,1}

       };
bool SboxD[16][4]={{1,1,1,0},
                   {0,0,1,1},
                   {0,1,0,0},
                   {1,0,0,0},
                   {0,0,0,1},
                   {1,1,0,0},
                   {1,0,1,0},
                   {1,1,1,1},
                   {0,1,1,1},
                   {1,1,0,1},
                   {1,0,0,1},
                   {0,1,1,0},
                   {1,0,1,1},
                   {0,0,1,0},
                   {0,0,0,0},
                   {0,1,0,1}

       };

  bool k0[16]={1,0,1,1,0,0,1,0,1,1,1,1,0,1,1,0};
  bool k[16]={0};
  cout<<"Dane wejsciowe K0:\t";
  for(int i=0;sizeof(k0)>i;i++)
    cout<<k0[i];
  cout<<endl;
  cout<<"KluczPierwszejRundy:\t";
  kluczPierwszejRundy(k0,k);
  for(int i=0;sizeof(k)>i;i++)
    cout<<k[i];
  cout<<endl;
  }
