#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP

#include "Dugum.hpp"

class SatirListesi{
public:
    SatirListesi();
    ~SatirListesi();
    void temizle();
    void ekle(int veri);   
    void sil(int sira);
    void yazdir(int index,int silinecek,bool onay);
    Dugum* yerBul(int sira);
    double getOrtalama();
    int getBoyut();
private:
    Dugum* ilk;
    double ortalamaBul();
    int boyut;    
    double ortalama;
};

#endif