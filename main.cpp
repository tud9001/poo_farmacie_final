#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include "gestionare.h"
#include "structura_date.h"
#include "farmacii.h"
using namespace std;
structura_date* structura_date::str = 0;
int main(){
structura_date *s=structura_date::getst();
string web;
farmacie *b;
Gestionare_Farmacii<farmacie> g;
    b=new farmacie_online();
    cin>>b;
    s->add(make_tuple(b->getnume(),b->getweb(),b->getviz(),b->getdiscount()));
    auto t=s->entry(b->getnume());
    string lmao=b->getnume();
    g+=lmao;
    //g->add(lmao);
    delete b;
    g.afis();
}
