#include "Musician.h"
#include "StringSupport.h"
#include "LinkedList.h"
const string Musician::TABLE="musician.txt";

Musician::Musician():Person()
{
}
Musician::Musician(const string* data):Person(data){
    if(data[6]!="")
        numOfSongs=stoi(data[6]);
    awarded=data[7];
}
Musician::~Musician()
{

}

//Musician::Musician(const Musician& other)
//{
//}
string Musician::toString()const{
    if(id==0) return "";
    return mean("id",id)+","
    +mean("fullname",fullname)+","
    +mean("birthday",birthday)+","
    +mean("gender",gender)+","
    +mean("introduction",introduction)+","
    +mean("avatar",avatar)+","
    +mean("numOfSongs",numOfSongs)+","
    +mean("awarded",awarded);
}
string Musician::toText(){
    return Person::toText()+";"+to_string(numOfSongs)+";"+awarded;
}
bool Musician::operator== (const Musician &musician)const{
    return musician.id==id;
}
bool Musician::operator!= (const Musician &musician)const{
    return musician.id!=id;
}
ofstream& operator<<(ofstream& out, const Musician& m){
    out<<"{"+m.toString()+"}";
    return out;
}
