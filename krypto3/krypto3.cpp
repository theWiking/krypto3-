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
void kluczPierwszejRundy(bool SboxE[16][4],bool *k0,bool *k){
  bool czesc[4]={0};
  wezJednaCzwarta(k0,4,czesc);
  int dziesietny=naDziesietny(czesc);

  for(int i=0;4>i;i++){
    k[i]=(k0[i]+SboxE[dziesietny][i]+(i==3?1:0))%2;
    k[i+4]=(k0[i+4]+k[i])%2;
    k[i+8]=(k0[i+8]+k[i+4])%2;
    k[i+12]=(k0[i+12]+k[i+8])%2;
  }

}
void kluczDrugiejRundy(bool SboxE[16][4],bool *k1,bool *k2){
  bool czesc[4]={0};
  wezJednaCzwarta(k1,4,czesc);
  int dziesietny=naDziesietny(czesc);

  for(int i=0;4>i;i++){
    k2[i]=(k1[i]+SboxE[dziesietny][i]+(i==2?1:0))%2;
    k2[i+4]=(k1[i+4]+k2[i])%2;
    k2[i+8]=(k1[i+8]+k2[i+4])%2;
    k2[i+12]=(k1[i+12]+k2[i+8])%2;
  }
}
void ZK(bool *A,bool *ZK){

  for(int i=0;16>i;i++){
    if(i>8-1)
      ZK[i]=A[i<12?i+4:i-4];
    else
      ZK[i]=A[i];
  }
}
void dzielenieBinarne(bool wejscie[7],bool wyjscie[7]){
  bool redukcyjny[5]={1,0,0,1,1};
  bool pomocnicza[7]={0};

  for(int i=0;7>i;i++)
    wyjscie[i]=wejscie[i];
  for(int j=0;j<3;j++)
    if(wyjscie[j]==1){
      for(int i=0;7>i;i++){
        pomocnicza[i]=0;
      }
      for(int i=0;sizeof(redukcyjny)>i;i++){
       pomocnicza[i+j]=redukcyjny[i];
      }
      for(int i=0;7>i;i++){
      if((wyjscie[i]==1&&pomocnicza[i]==1)||(wyjscie[i]==0&&pomocnicza[i]==0))
        wyjscie[i]=0;
        else
          wyjscie[i]=1;
         }
  }
}
void redukcja(bool *wejscie,bool *wyjscie){
for(int i=0;4>i;i++)
  wyjscie[i]=wejscie[i+3];
}
void mnozenieBinarne(bool a[4],bool b[4],bool wyjscie [7]){
  for(int i=0;4>i;i++)
    if(b[i]==1)
      for(int j=0;4>j;j++){
        wyjscie[j+i]=(wyjscie[j+i]+a[j])%2;
      }
}
void mB(bool *a,bool *b,bool wyjscie[4]){

  bool pomoc[7]={0};
  bool pomoc2[7]={0};
  mnozenieBinarne(a,b,pomoc);
  dzielenieBinarne(pomoc,pomoc2);
  redukcja(pomoc2,wyjscie);
}
void laczenieMacierzy(bool wejscie[2][2][4],bool wyjscie[16]){
  for(int h=0;2>h;h++)
    for(int j=0;2>j;j++)
      for(int i=0;16>i;i++)
        wyjscie[i]=wejscie[j][h][i%4];
}
void MM(bool m[16],bool A[16],bool MM[16]){
  bool czescOdA[4][4]={0}; //[4komurki][4dane w kom]
  bool czescOdm[4][4]={0};
  bool pomoc[4]={0};
  bool pomoc2[4]={0};
  bool mm[2][2][4]={0};

  for(int i=0;4>i;i++)
    wezJednaCzwarta(A,i+1,czescOdA[i]);
  for(int i=0;4>i;i++)
    wezJednaCzwarta(m,i+1,czescOdm[i]);

  for(int h=0;4>h;h+=2)
  for(int j=0;4>j;j++){
    mB(czescOdA[h],czescOdm[j],pomoc);
    mB(czescOdA[h+1],czescOdm[j],pomoc2);
    for(int i=0;4>i;i++)
      mm[j/2][h/2][i]=(pomoc[i]+pomoc2[i])%2;
  }
  laczenieMacierzy(mm,MM);
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
  bool m[16]={1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};
  bool mm[16]={0};
  bool k1[16]={0};
  bool k2[16]={0};
  bool zk[16]={0};

  cout<<"Dane wejsciowe K0:\t";
  for(int i=0;sizeof(k0)>i;i++){
    cout<<k0[i];
    (i+1)%4==0?cout<<" ":cout<<"";
  }
  cout<<endl;
  cout<<"KluczPierwszejRundy:\t";
  kluczPierwszejRundy(SboxE,k0,k1);
  for(int i=0;sizeof(k1)>i;i++){
    cout<<k1[i];
     (i+1)%4==0?cout<<" ":cout<<"";
  }
  cout<<endl;
  cout<<"KluczDrugiejRundy:\t";
  kluczDrugiejRundy(SboxE,k1,k2);
  for(int i=0;sizeof(k2)>i;i++){
    cout<<k2[i];
     (i+1)%4==0?cout<<" ":cout<<"";
  }
  cout<<endl;
  cout<<"Testowanie alg ZK:\t";
  ZK(k0,zk);
  for(int i=0;sizeof(zk)>i;i++){
      cout<<zk[i];
     (i+1)%4==0?cout<<" ":cout<<"";
  }
  cout<<endl;
  cout<<"Mnozenie maczierzy:\t";
  MM(m,k0,mm);
  for(int i=0;sizeof(mm)>i;i++){
      cout<<mm[i];
     (i+1)%4==0?cout<<" ":cout<<"";
  }
  return 0;

}

