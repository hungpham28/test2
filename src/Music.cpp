#include "Music.h"
#include "StringSupport.h"

const string Music::TABLE="music.txt";

Music::Music():id(0)
{
}
Music::Music(string* arr)
{
    id=arr[0]!="" ? stoi(arr[0]):0;
    name=arr[1];
    createdDate=Date(arr[2]);
    typeId=arr[3]!="" ? stoi(arr[3]):0;
    lyric=arr[4];
    urlMV=arr[5];
    urlAudio=arr[6];
    view=arr[7]!="" ? stoi(arr[7]):0;
    duration=arr[8]!="" ? stoi(arr[8]):0;
    musicianId=arr[9]!="" ? stoi(arr[9]):0;
}
Music::~Music()
{
    //dtor
}
string Music::toString()const{
    if(id==0) return "";
    return mean("id",id)+","
    +mean("name",name)+","
    +mean("createdDate",createdDate)+","
    +mean("typeId",typeId)+","
    +mean("lyric",lyric)+","
    +mean("urlMV",urlMV)+","
    +mean("urlAudio",urlAudio)+","
    +mean("view",view,false)+","
    +mean("duration",duration)+","
    +mean("musicianId",musicianId);
}
string Music::toText(){
    return to_string(id)+";"+name+";"+createdDate.getDate()+";"+to_string(typeId)+";"+lyric+";"+urlMV+";"+urlAudio
    +";"+to_string(view)+";"+to_string(duration)+";"+to_string(musicianId);
}
bool Music::operator== (const Music &music)const{
    return music.id==id;
}
bool Music::operator!= (const Music &music)const{
    return music.id!=id;
}
ofstream& operator<<(ofstream& out, const Music& m){
    out<<"{"+m.toString()+"}";
    return out;
}
bool Music::as(const Music& m)const{
    if(m.name!="" &&!search(m.name,name)) return false;
    if(!m.createdDate &&!search(m.createdDate.getDate(),createdDate.getDate())) return false;
    if(m.musicianId!=0 && musicianId!=m.musicianId) return false;
    if(m.typeId!=0 && typeId!=m.typeId) return false;
    return true;
}
