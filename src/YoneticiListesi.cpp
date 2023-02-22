#include "YoneticiListesi.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream> 
using namespace std;
YoneticiListesi::YoneticiListesi()
{
    ilk = 0;
    boyut =-1;
    int index=0;
    int satirIndex=0;
    char ch;
    ifstream listeOku("./doc/veriler.txt");
    listeOku.seekg(0);
    while(!listeOku.eof())
    {
        int alinanSira;
        string alinanVeri = "";
        SatirListesi* satirListesi= new SatirListesi();
        getline(listeOku,alinanVeri);
        while(alinanVeri.length()>2)
        {
            satirListesi->ekle(stoi(alinanVeri.substr(0,2)));
            alinanVeri=alinanVeri.substr(3,alinanVeri.length()-3);
        }
        ekle(satirListesi);       
    }
    bool onay=false;
    int silinecek=-1;
    while(true)
    {   
        system("cls");//Ekranı temizliyor
        if(onay && silinecek>=0){
            yerBul(satirIndex+index*8)->veri->sil(silinecek);
            if(yerBul(satirIndex+index*8)->veri->yerBul(0)==0)
            {
                sil(satirIndex+index*8);
            }
            silinecek=-1;
        }
        if(onay)
            onay=false;
        sirala();
        yazdir(index,satirIndex,silinecek,onay);

        cin>>ch;
        if(ch=='a' && index!=0)
        {
            index--;
        }else if(ch=='d' && listeBoyutu()/8>index)
        {
            index++;
            if(index==listeBoyutu()/8&&satirIndex>listeBoyutu()%8)
            {
                satirIndex=listeBoyutu()%8 -1;
            }
        }else if(ch=='z'&&!(index==0 && satirIndex==0))
        {
            if(index!=0&&satirIndex==0)
            {
                index--;
                satirIndex=7;
            }else{
                satirIndex--;
            }
            
        }else if(ch=='c')
        {
            if(satirIndex!=8)
            {
                satirIndex++;
            }
            if(satirIndex==8 && listeBoyutu()/8>index)
            {
                index++;
                satirIndex=0;
            }
            if(listeBoyutu()/8==index && listeBoyutu()%8==satirIndex)
            {
                satirIndex--;
            }
        }else if(ch=='p')
        {
            sil(index*8+satirIndex);
        }else if(ch=='k')
        {
            if(silinecek < 0)
            {
                silinecek=rand()%yerBul(index*8+satirIndex)->veri->getBoyut();
            }else{
                onay=true;
            }           
        }
    }
}
YoneticiListesi::~YoneticiListesi(){
    temizle();
}
void YoneticiListesi::ekle(SatirListesi* veri){
    if(ilk==0)
    {
        YoneticiDugum* gec=new YoneticiDugum(veri);
        ilk = gec;
        boyut++;
    }else{
        YoneticiDugum* gec= yerBul(boyut);
        YoneticiDugum* gelenVeri= new YoneticiDugum(veri);
        gec->sonraki=gelenVeri;
        gelenVeri->onceki=gec;
        boyut++;
    }

}

void YoneticiListesi::sil(int sira){
    if(ilk==0) return;//Eleman olmaması durumu
    if(ilk->sonraki==0){//1 Eleman olması durumu
        delete ilk;
        ilk=0;
    }else if(sira==0)
    {
        YoneticiDugum* gec= ilk;
        ilk=ilk->sonraki;
        delete gec;
    }else if(sira>=boyut){//Son elemanı veya toplam eleman sayısından fazla elemanı silme durumu 
        YoneticiDugum* gec= yerBul(boyut);
        gec->onceki->sonraki=0;
        delete gec;
    }else{   //Boyut içindeki elemanları silme durumu
        YoneticiDugum* gec= yerBul(sira);
        gec->onceki->sonraki= gec->sonraki;
        gec->sonraki->onceki=gec->onceki;
        delete gec;
    }
    boyut--;
    sirala();
}   
void YoneticiListesi::yazdir(int index,int satirIndex,int silinecek,bool onay){
    if(ilk != 0)
    {
        boslariSil();
        sirala();
        if((boyut+1)/9<index)
        {
            index=(boyut+1)/9;
        }
        if(index==0)
            cout<<"ilk";
        else
            cout<<"<---";
        if((index+1)*8>boyut)
        {
            if(boyut==7)//İlk ve son aynı sayfada olma durumu
            {
                cout<<setw((8*11+7*4)-3)<<"son"<<endl;
            }
            else
            {
                cout<<setw((((boyut+1)%8)*11+(((boyut+1)%8)-1)*4)-4)<<"son"<<endl;
            }        
        }
        else
        {
            cout<<setw(8*11+7*4-3)<<"--->"<<endl;
        }
        for(int i=0;i<8; i++)
        {
            if(yerBul(index*8+i)!=0)
            {
                cout<< setw(10)<<yerBul(index*8+i)<<setw(5)<<" ";
            }
        }
        cout<<endl;
        for(int i=0;i<8; i++)
        {
            if(yerBul(index*8+i)!=0)
            {
                cout<<"-----------"<<setw(4)<<" ";
            }
        }
        cout<<endl;
        for(int i=0;i<8; i++)
        {
            if(yerBul(index*8+i)!=0)
            {
                cout<<"|"<<setw(9)<<yerBul(index*8+i)->onceki<<"|"<<setw(4)<<" ";
            }     
        }
        cout<<endl;
        for(int i=0;i<8; i++)
        {
            if(yerBul(index*8+i)!=0)
            {
                cout<<"-----------"<<setw(4)<<" ";
            }
        }
        cout<<endl;
        for(int i=0;i<8; i++)
        {
            if(yerBul(index*8+i)!=0)
            {
                cout<<"|"<<setw(9)<<yerBul(index*8+i)->veri->getOrtalama()<<"|"<<setw(4)<<" ";
            }
        }
        cout<<endl;
        for(int i=0;i<8; i++)
        {
            if(yerBul(index*8+i)!=0)
            {
                cout<<"-----------"<<setw(4)<<" ";
            }
        }
        cout<<endl;
        for(int i=0;i<8; i++)
        {
            if(yerBul(index*8+i)!=0)
            {
                cout<<"|"<<setw(9)<<yerBul(index*8+i)->sonraki<<"|"<<setw(4)<<" ";
            }
        }
        cout<<endl;
        for(int i=0;i<8; i++)
        {
            if(yerBul(index*8+i)!=0)
            {
                cout<<"-----------"<<setw(4)<<" ";
            }
        }
        cout<<endl;
        yerBul(index*8+satirIndex)->veri->yazdir(satirIndex,silinecek,onay);
    }    
}

void YoneticiListesi::temizle(){
    YoneticiDugum* gecici;
    gecici=ilk;
    while(gecici!=0){
        YoneticiDugum* silinecek=gecici;
        gecici=gecici->sonraki;
        delete silinecek;
    }
    boyut=-1;
}
int YoneticiListesi::listeBoyutu(){return boyut+1;}
YoneticiDugum* YoneticiListesi::yerBul(int sira){
    YoneticiDugum* gecici=ilk;
    if(sira==0)
    {
        return ilk;
    }
    else if(sira >boyut+1)
    {
        return 0;
    }    
    else
    {        
        for(int i=0;i<sira;i++)
        {
            gecici=gecici->sonraki;
        }
        return gecici;
    }
}
void YoneticiListesi::sirala()
{
    if(ilk!=0)
    {
        for(int i=0;i<boyut+1;i++)
        {
            YoneticiDugum* gec = yerBul(i);
            for(int j=i+1;j<boyut+1;j++)
            {
                YoneticiDugum* gec2= yerBul(j);
                if(gec2->veri->getOrtalama()<gec->veri->getOrtalama())
                {
                    SatirListesi* gec3= gec->veri;
                    gec->veri= gec2->veri;
                    gec2->veri=gec3;                
                }
            }
        }
    }
    
}

void YoneticiListesi::boslariSil(){
    if(ilk!=0)
    {
        YoneticiDugum* gec=ilk;
        int sayac=0;
        while(gec->sonraki!=0)
        {
            if(gec->veri->yerBul(0)==0)
            {
                sil(sayac);
            }
            gec=gec->sonraki;
            sayac++;
        }
    }
}
