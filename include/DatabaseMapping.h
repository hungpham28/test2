#include<string>
using namespace std;
#ifndef DATABASEMAPPING_H
#define DATABASEMAPPING_H
const string URI_DATABASE="./data/";
const string URI_TABLE_SINGER=URI_DATABASE  +"singer.txt";
const string URI_TABLE_MUSICIAN=URI_DATABASE  +"musician.txt";
const string URI_TABLE_MUSIC=URI_DATABASE  +"music.txt";
const string URI_MUSIC_SINGER=URI_DATABASE  +"music_singer.txt";
const string URI_ALBUM_MUSIC=URI_DATABASE  +"album_music.txt";
#include"Services.h"
template<class A, class B>
class Mapping
{
public:
    int key1;
    int key2;
    A* val1;
    B* val2;
    Mapping<A,B>();
    Mapping<A,B>(int m1,A* a,int m2,B* b);
    ~Mapping<A,B>();
    Mapping<A,B>(A& a,B& b);
    Mapping<A,B>(int m1,int m2);
    bool operator== (const Mapping<A,B> &)const;
    bool operator!= (const Mapping<A,B> &)const;
    string toText();
};
#include"../src/DatabaseMapping.hpp"
#endif // DATE_H
