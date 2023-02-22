#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp
#include "YoneticiDugum.hpp"
class YoneticiListesi{
public:
    YoneticiListesi();
    ~YoneticiListesi();
    void temizle();
    void ekle(SatirListesi* veri);   
    void sil(int sira);
    void yazdir(int index,int satirIndex,int silinecek,bool onay);
    int listeBoyutu();
    YoneticiDugum* yerBul(int sira);
    void sirala();
private:
    void boslariSil();
    YoneticiDugum* ilk;
    int boyut; 
};

#endif