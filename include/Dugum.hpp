/** 
* @file Dugum.hpp
* @description Düğüm sınınıfın header dosyası
* @course 1. öğretim C grubu
* @assignment 1. ödev
* @date 08.11.2022
* @author Gruptakilerin yazar adları ve mail adresleri
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum
{
public:
    Dugum (int veri);
    int veri;          
    Dugum* sonraki;
    Dugum* onceki;
};


#endif
