#ifndef STRUCTURA_DATE_H_INCLUDED
#define STRUCTURA_DATE_H_INCLUDED
#include "farmacii.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;
class structura_date{
private:
    static structura_date *str;
    vector<tuple<string,string,int,int>> t;
    structura_date(){}
public:
    static structura_date* getst(){
    if(str==0)
    {
        str=new structura_date();
    }
    return str;
    }
    void add(auto tt)
    {
    t.push_back(tt);
    }
    void afis()
    {
    for(auto &i:t)
    {
        cout<<get<0>(i)<<endl<<get<1>(i)<<" "<<get<2>(i)<<" "<<get<3>(i)<<endl;
    }
    }
    auto entry(string s)
    {
    for(auto &i:t)
    {
        if(get<0>(i)==s)return make_tuple(get<0>(i),get<1>(i),get<2>(i),get<3>(i));
    }
    }
    int getviews(){
    int views=0;
    for(auto &i:t)
    {
        views+=get<2>(i);
    }
    return views;
    }
};

#endif // STRUCTURA_DATE_H_INCLUDED
