#pragma once
#include "EP.h"


using namespace std;


typedef pair<string, Item> Pair;


class VO {
public:
    int InsereBB(vector<Pair>& v, const Pair& x);
    Pair* BuscaBB(vector<Pair>& v, const string& x);
    VO(){
        vector<Pair> v; 
    }
    
};