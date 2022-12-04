#include "Album.h"
#include <fstream>
#include"StringSupport.h"
const string Album::TABLE="album.txt";
Album::Album():id(0)
{
    //ctor
}
Album::Album(string* arr)
{
    id=stoi(arr[0]);
    title=arr[1];
    description=arr[2];
    createdDate=arr[3];
}
Album::~Album()
{
    //dtor
}
string Album::toText()const{
    return to_string(id)+";"+title+";"+description+";"+createdDate.getDate();
}
string Album::toString()const{
    if(id==0) return "";
    return mean("id",id)+","
    +mean("title",title)+","
    +mean("description",description)+","
    +mean("createdDate",createdDate);
}
bool Album::operator== (const Album &a)const{
    return a.id==id;
}
bool Album::operator!= (const Album &a)const{
    return a.id!=id;
}
ofstream& operator<<(ofstream& out, const Album& a){
    out<<"{"+a.toText()+"}";
    return out;
}
