#include"DatabaseMapping.h"
template<typename A, typename B>
Mapping<A,B>::Mapping()
{
    val1=NULL;
    val2=NULL;
}
template<typename A, typename B>
Mapping<A,B>::Mapping(int m1,A* a,int m2,B* b)
{
    key1=m1;
    key2=m2;
    val1=a;
    val2=b;
}
template<typename A, typename B>
Mapping<A,B>::~Mapping()
{

}
template<typename A, typename B>
Mapping<A,B>::Mapping(A& a,B& b)
{
    key1=&a;
    key2=&b;
}
template<typename A, typename B>
Mapping<A,B>::Mapping(int m1,int m2)
{
    key1=m1;
    key2=m2;
    val1=NULL;
    val2=NULL;
}
template<typename A, typename B>
string Mapping<A,B>::toText()
{
    return to_string(key1)+";"+to_string(key2);
}
template<typename A, typename B>
bool Mapping<A,B>::operator== (const Mapping<A,B>& temp)const{
    return ((temp.key1==this->key1) || (temp.key2==this->key2));
}
template<typename A, typename B>
bool Mapping<A,B>::operator!= (const Mapping<A,B>& temp)const{
    return ((temp.key1!=this->key1) && (temp.key2!=this->key2));
}
