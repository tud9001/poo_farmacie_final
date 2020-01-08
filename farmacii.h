#ifndef FARMACII_H_INCLUDED
#define FARMACII_H_INCLUDED
#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;
class proprietar{
private:
    string nume;
public:
    proprietar(){}
    string getname(){
    return nume;
    }
    friend istream& operator >>(istream &in, proprietar x)
    {
        in>>x.nume;
        return in;
    }
    proprietar& operator =(const proprietar &ob){
    this->nume=ob.nume;
    return *this;
    }
    friend class farmacie;
};
class farmacie{
protected:
    proprietar x;
    string nume;
public:
    farmacie(string nume):nume(nume){

    }
    farmacie(const farmacie *ob):nume(ob->nume){

    }
    virtual ~farmacie(){}
    //farmacie(){}
    string getnume(){
    return nume;
    }
    virtual void citire(istream&)=0;
    friend istream& operator >>(istream &in,farmacie *a)
    {
        //in>>a->x;
        a->citire(in);
        return in;
    }
    farmacie* operator =(const farmacie* ob)
    {
        this->nume=ob->nume;
        this->x=ob->x;
        return this;
    }
    virtual void afisare()=0;
    virtual string getweb()=0;
    virtual int getviz()=0;
    virtual int getdiscount()=0;
};
class farmacie_offline:public farmacie{
private:
    int nr_angj;
    int profit;
public:
    farmacie_offline():farmacie(nume){}
    farmacie_offline(string nm,int nr, int pro):farmacie(nume){
    //cout<<"vibe check"<<endl;
    //cout<<nume<<" "<<nr<<" "<<pro<<endl;
    this->nume=nm;
    this->nr_angj=nr;
    this->profit=pro;
    //cout<<this->nume<<" "<<this->nr_angj<<" "<<this->profit<<endl;
    }

    ~farmacie_offline(){}
    void citire(istream& in){
    //cout<<"lmao"<<endl;
    in>>nume>>nr_angj>>profit;
    cout<<nume<<" "<<nr_angj<<" "<<profit<<endl;
    }
    string getweb(){}
    int getviz(){}
    int getdiscount(){}
    void afisare(){
    cout<<nume<<endl<<nr_angj<<" "<<profit<<endl;
    }
};
class farmacie_online:public farmacie{
private:
    string web;
    int nr_viz;
    int discount;
public:
    farmacie_online():farmacie(nume){
    }
    farmacie_online(string nm,string adr,int nr,int disc):farmacie(nume){
    this->nume=nm;
    this->web=adr;
    this->nr_viz=nr;
    this->discount=disc;
    }
    //DEQUE(const DEQUE* ob):coada(ob->prim,ob->ultim){}
    farmacie_online(const farmacie_online* ob):farmacie(ob->nume){
    this->nume=ob->nume;
    this->nr_viz=ob->nr_viz;
    this->web=ob->web;
    this->discount=ob->discount;
    }
    void copyy(farmacie_online *ob){
    this->nume=ob->nume;
    this->web=ob->web;
    this->nr_viz=ob->nr_viz;
    this->discount=ob->discount;
    }
    virtual ~farmacie_online(){}
    void citire(istream& in){
    //in>>nume;
    in>>nume>>web>>nr_viz>>discount;
    }
    string getweb(){
    return web;
    }
    int getviz(){
    return nr_viz;
    }
    int getdiscount(){
    return discount;
    }
    void afisare(){
    cout<<nume<<endl<<web<<endl<<nr_viz<<" "<<discount<<endl;
    }
    farmacie_online* operator =(farmacie_online* ob)
    {
        this->nume=ob->nume;
        this->web=ob->web;
        this->nr_viz=ob->nr_viz;
        this->discount=ob->discount;
        return this;
    }
};

#endif // FARMACII_H_INCLUDED
