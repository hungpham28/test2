#include"DatabaseMapping.h"
template<typename A, typename B>
Mapping<A,B>::Mapping<A,B>()
{
    val1=NULL;
    val2=NULL;
}
Mapping<A,B>(int m1,A& a,int m2,B& b)
{
    key1=m1;
    key2=m2;
    val1=&a;
    val2=&b;
}
~Mapping<A,B>()
{
    delete val1;
    delete val2;
}
Mapping<A,B>(A& a,B& b)
{
    key1=&a;
    key2=&b;
}
Mapping<A,B>(int m1,int m2)
{
    key1=m1;
    key2=m2;
    val1=NULL;
    val2=NULL;
}
string getByKey1(int id);
string getByKey2(int id);
string toText()
{
    return to_string(key1)+";"+to_string(key2);
}
