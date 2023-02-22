/** 
* @file YoneticiDugum.hpp
* @description Yönetici Listesinin Dugum sınıfının kafası
* @course Birinci öğretim C grubu
* @assignment 1. Ödev
* @date 1.11.2022
* @author burak ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#ifndef YoneticiDugum_hpp
#define YoneticiDugum_hpp

#include "SatirListesi.hpp"

class YoneticiDugum
{
public:
    YoneticiDugum (SatirListesi* veri);
    SatirListesi* veri;          
    YoneticiDugum* sonraki;
    YoneticiDugum* onceki;
};


#endif