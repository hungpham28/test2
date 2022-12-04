#include "Singer.h"
#include "StringSupport.h"
const string Singer::TABLE="singer.txt";
Singer::Singer():Person()
{
    ranking="";
    nationality="";
}
Singer::Singer(string* data):Person(data){
    ranking=data[6];
    nationality=data[7];
}
Singer::~Singer()
{

}
string Singer::toString()const{
    if(id==0) return "";
    return mean("id",id)+","
    +mean("fullname",fullname)+","
    +mean("birthday",birthday)+","
    +mean("gender",gender)+","
    +mean("introduction",introduction)+","
    +mean("avatar",avatar)+","
    +mean("ranking",ranking)+","
    +mean("nationality",nationality);
}
string Singer::toText(){
    return Person::toText()+";"+ranking+";"+nationality;
}
bool Singer::operator== (const Singer &singer)const{
    return singer.id==id;
}
bool Singer::operator!= (const Singer &singer)const{
    return singer.id!=id;
}
ofstream& operator<<(ofstream& out, const Singer& s){
    out<<"{"+s.toString()+"}";
    return out;
}
