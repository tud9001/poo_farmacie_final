#ifndef GESTIONARE_H_INCLUDED
#define GESTIONARE_H_INCLUDED
#include "structura_date.h"
#include "farmacii.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;
template<class x>
class Gestionare_Farmacii{
private:
    const int idlant=1;
    int index;
    x *lant[101];
public:
    Gestionare_Farmacii(){
    index=0;
    }
    ~Gestionare_Farmacii(){
    for(int i=1;i<=index;i++)
        delete lant[i];
    delete lant;
    }
    void add(string s){
    structura_date *st=structura_date::getst();
    index++;
    cout<<"i try so hard"<<endl;
    auto t=st->entry(s);
    lant[index]=new farmacie_online(get<0>(t),get<1>(t),get<2>(t),get<3>(t));
    cout<<"esketit"<<endl;
    cout<<"this is so sad"<<endl;
    }
    Gestionare_Farmacii<x>* operator +=(string s){
    this->add(s);
    return this;
    }
    void afis(){
    cout<<"am ajuns in afisare"<<endl;
    cout<<index<<endl;
    cout<<lant[index]->getnume()<<" "<<lant[index]->getweb()<<" "<<lant[index]->getviz()<<" "<<lant[index]->getdiscount()<<endl;
    }
    friend class structura_date;
};
template<>
class Gestionare_Farmacii<farmacie_online>{
    int views_total;
public:
    int getallviews(){
    structura_date *s=structura_date::getst();
    views_total=s->getviews();
    return views_total;
    }
};
#endif // GESTIONARE_H_INCLUDED
