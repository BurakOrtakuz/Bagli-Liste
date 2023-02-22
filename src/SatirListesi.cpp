#include "SatirListesi.hpp"
#include <iomanip>
#include <iostream>
SatirListesi::SatirListesi()
{
    ilk = 0;
    boyut =-1;
    //ortalama=0;
}
SatirListesi::~SatirListesi(){
    temizle();
}
void SatirListesi::ekle(int veri){
    if(ilk==0)
    {
        Dugum* gec=new Dugum(veri);
        ilk = gec;
        boyut++;
    }else{
        Dugum* gec= yerBul(boyut);
        Dugum* gelenVeri= new Dugum(veri);
        gec->sonraki=gelenVeri;
        gelenVeri->onceki=gec;
        boyut++;
    }
    ortalama=ortalamaBul();
}

void SatirListesi::sil(int sira){
    
    if(ilk==0) return;//Eleman olmaması durumu
    if(ilk->sonraki==0){//1 Eleman olması durumu
        delete ilk;
        ilk=0;
    }else if(sira==0)
    {
        Dugum* gec= ilk;
        ilk=ilk->sonraki;
        delete gec;
    }else if(sira>=boyut){//Son elemanı veya toplam eleman sayısından fazla elemanı silme durumu 
        Dugum* gec= yerBul(boyut);
        gec->onceki->sonraki=0;
        delete gec;
    }else{   //Boyut içindeki elemanları silme durumu
        Dugum* gec= yerBul(sira);
        gec->onceki->sonraki= gec->sonraki;
        gec->sonraki->onceki=gec->onceki;
        delete gec;
    }
    boyut--;
    ortalama=ortalamaBul();
    std::cout<<"Guncel Ortalama:"<<ortalama<<std::endl;
}   
void SatirListesi::yazdir(int index,int silinecek,bool onay){
    if(ilk != 0){
        Dugum* gecici;
        int sayac=0;
        gecici = ilk;
        int bosluk=index*(11)+(index)*4+1;
        std::cout<<std::endl<<std::setw(bosluk)<<"^";
        std::cout <<"^^^^^^^^^^"<<std::endl;
        while(gecici != 0){
            std::cout <<std::endl;
            if(silinecek==sayac&&onay)
            {
                gecici=gecici->sonraki;
                if(gecici==0)
                    break;
            }
            std::cout <<std::setw(bosluk)<<" "<<std::setw(9)<<gecici<<std::endl;
            std::cout <<std::setw(bosluk)<<"-";
            std::cout <<"----------"<<std::endl;
            std::cout <<std::setw(bosluk)<<"|"<< std::setw(5)<<gecici->veri<<std::setw(5) << "|"<<std::endl;
            std::cout <<std::setw(bosluk)<<"-";
            std::cout <<"----------";
            if(silinecek ==sayac)
            {
                std::cout <<"<---- silinecek secili";
            }
            std::cout<<std::endl;
            std::cout <<std::setw(bosluk)<<"|"<< std::setw(9)<<gecici->sonraki<< "|"<<std::endl;
            std::cout <<std::setw(bosluk)<<"-";
            std::cout <<"----------"<<std::endl;
            std::cout <<std::endl;
            gecici= gecici->sonraki;
            sayac++;
        }
      
    }    
}

void SatirListesi::temizle(){
    Dugum* gecici;
    gecici=ilk;
    while(gecici!=0){
        Dugum* silinecek=gecici;
        gecici=gecici->sonraki;
        delete silinecek;
    }
    boyut=-1;
}
 
Dugum* SatirListesi::yerBul(int sira){
    Dugum* gecici=ilk;
    if(sira==0){
        return ilk;
    }else{        
        for(int i=0;i<sira;i++){
            gecici=gecici->sonraki;
        }
        return gecici;
    }
}
double SatirListesi::getOrtalama(){return ortalama;}
double SatirListesi::ortalamaBul(){
    if(ilk ==0){
        return -1;
    }    
    else if(ilk->sonraki==0)
    {
        return ilk->veri;
    }else 
    {
        double toplam=0;
        Dugum* gecici= ilk; 
        int i=0;
        while(gecici!=0)
        {
            
            toplam+=gecici->veri;
            gecici=gecici->sonraki;
            i++;
        }
        return toplam/i;
    }
}
int SatirListesi::getBoyut(){return boyut+1;}
