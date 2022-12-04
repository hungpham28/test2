#include "Type.h"
#include "StringSupport.h"
const string Type::TABLE="type.txt";
Type::Type():id(0),name("")
{
    //ctor
}
Type::Type(string* data)
{
    id=stoi(data[0]);
    name=data[1];
}
Type::~Type()
{
    //dtor
}
string Type::toString()const{
    if(id==0) return "";
    return mean("id",id)+","+mean("name",name);
}
string Type::toText(){
return to_string(id)+";"+name;
}
bool Type::operator== (const Type &type)const{
    return type.id==id;
}
bool Type::operator!= (const Type &type)const{
    return type.id!=id;
}
ofstream& operator<<(ofstream& out, const Type& t){
    out<<"{"+t.toString()+"}";
    return out;
}
