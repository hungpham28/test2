#include <iostream>
#include <fstream>
#include <string>
#include"Date.h"
#include"Music.h"
#include"Musician.h"
#include"Singer.h"
#include"ManagedServices.h"
using namespace std;
ManagedServices program;
enum API
{
    GET_ALL_MUSICS=0,
    GET_ALL_MUSICIANS=1,
    GET_ALL_SINGERS=2,
    GET_ALL_ALBUM=3,
    GET_DETAILS_MUSIC=4,
    GET_DETAILS_MUSICIAN=5,
    GET_DETAILS_SINGER=6,
    GET_DETAILS_ALBUM=7,
    ADD_MUSIC=8,
    ADD_MUSICIAN=9,
    ADD_SINGER=10,
    ADD_ALBUM=11,
    UPDATE_MUSIC=12,
    UPDATE_MUSICIAN=13,
    UPDATE_SINGER=14,
    UPDATE_ALBUM=15,
    DELETE_MUSIC=16,
    DELETE_MUSICAN=17,
    DELETE_SINGER=18,
    DELETE_ALBUM=19,
    SEARCH_MUSICS=20,
    SEARCH_MUSICIAN=21,
    SEARCH_SINGER=22,
    GET_SORT_MUSICS_BY_NAME=23,
    GET_SORT_MUSICS_BY_VIEW=24,
    GET_MUSICS_BY_SINGER_ID=25,
    GET_MUSICS_BY_MUSICIAN_ID=26,
    GET_ALL_TYPE=27,
    ADD_TYPE=28,
    DELETE_TYPE=29,
    INCREASE_VIEW=30,
    EXIT
};
string file(int op);
string fileData(int op);
istream& operator>>(istream& is, API& i );
bool cmpMusicView(const Music& m1,const Music& m2){
    return m1.getView()>m2.getView();
}
bool cmpMusicName(const Music& m1,const Music& m2){
    string name1= m1.getName();
    string name2= m2.getName();
    unsigned int sz = name1.size()>name2.size() ? name2.size():name1.size();
    for (unsigned int i = 0; i < sz; ++i){
        if (tolower(name1[i])>tolower(name2[i]))
            return false;
        if (tolower(name1[i])<tolower(name2[i]))
            return true;
    }
    return false;
}
int main()
{
    string line,data,*o;

    int id;
    ofstream out_file;
    ifstream in_file;
    API option;
    do
    {
        cin>>option;
        out_file.open(file(option));
        cin.ignore();
        switch(option)
        {
        case GET_ALL_MUSICS:
            out_file<<program.getEagerMusics()<<endl;
            out_file.close();
            break;
        case GET_ALL_MUSICIANS:
            out_file<<program.getEagerMusicians()<<endl;
            out_file.close();
            break;
        case GET_ALL_SINGERS:
            out_file<<program.getEagerSingers()<<endl;
            out_file.close();
            break;
        case GET_ALL_ALBUM:
            out_file<<program.getEagerAlbums()<<endl;
            out_file.close();
            break;
        case GET_DETAILS_MUSIC:
            cin>>id;
            out_file<<program.getEagerMusicById(id)<<endl;
            out_file.close();
            break;
        case GET_DETAILS_MUSICIAN:
            cin>>id;
            out_file<<program.serviceMusician.getById(id)<<endl;
            out_file.close();
            break;
        case GET_DETAILS_SINGER:
            cin>>id;
            out_file<<program.serviceSinger.getById(id)<<endl;
            out_file.close();
            break;
        case GET_DETAILS_ALBUM:
            cin>>id;
            out_file<<program.getEagerAlbumById(id)<<endl;
            out_file.close();
            break;
        case ADD_MUSIC:
            in_file.open(fileData(option));
            getline(in_file,data);
            o=split(data,';');
            program.addMusic(Music(o),o[10]);
            in_file.close();
            out_file.close();
            break;
        case ADD_MUSICIAN:
            in_file.open(fileData(option));
            getline(in_file,data);
            o=split(data,';');
            program.serviceMusician.add(Musician(o));
            in_file.close();
            out_file.close();
            break;
        case ADD_SINGER:
            in_file.open(fileData(option));
            getline(in_file,data);
            o=split(data,';');
            program.serviceSinger.add(Singer(o));
            in_file.close();
            out_file.close();
            break;
        case ADD_ALBUM:
            in_file.open(fileData(option));
            getline(in_file,data);
            o=split(data,';');
            program.addAlbum(Album(o),o[4]);
            in_file.close();
            out_file.close();
            break;
        case DELETE_MUSIC:
            cin>>id;
            program.deleteMusicById(id);
            out_file.close();
            break;
        case DELETE_MUSICAN:
            cin>>id;
            program.serviceMusician.deleteById(id);
            out_file.close();
            break;
        case DELETE_SINGER:
            cin>>id;
            program.deleteSingerById(id);
            out_file.close();
            break;
        case DELETE_ALBUM:
            cin>>id;
            program.deleteAlbumById(id);
            out_file.close();
            break;
        case SEARCH_MUSICS:
            in_file.open(fileData(option));
            getline(in_file,data);
            o=split(data,';');
            out_file<<program.searchMusics(Music(o));
            in_file.close();
            out_file.close();
            break;
//        case SEARCH_MUSICIAN:
//            getline(cin,data);
//            o=split(data,';');
//            program.serviceMusician.add(Musician(o));
//            out_file.close();
//            break;
//        case SEARCH_SINGER:
//            getline(cin,data);
//            o=split(data,';');
//            program.serviceMusician.add(Musician(o));
//            out_file.close();
//            break;
        case GET_SORT_MUSICS_BY_NAME:
            out_file<<program.serviceMusic.sorting(cmpMusicName);
            out_file.close();
            break;
        case GET_SORT_MUSICS_BY_VIEW:
            out_file<<program.serviceMusic.sorting(cmpMusicView);
            out_file.close();
            break;
        case GET_MUSICS_BY_SINGER_ID:
            cin>>id;
            out_file<<program.getMusicsBySingerId(id);
            out_file.close();
            break;
//        case GET_MUSICS_BY_MUSICIAN_ID:
//            cin>>id;
////            program.get;
//            out_file.close();
//            break;
        case GET_ALL_TYPE:
            out_file<<program.serviceType.getJSON_Objects()<<endl;
            out_file.close();
            break;
        case ADD_TYPE:
            in_file.open(fileData(option));
            getline(in_file,data);
            o=split(data,';');
            program.serviceType.add(Type(o));
            in_file.close();
            out_file.close();
            break;
        case DELETE_TYPE:
            cin>>id;
            program.serviceType.deleteById(id);
            out_file.close();
            break;
        case UPDATE_MUSIC:
            in_file.open(fileData(option));
            getline(in_file,data);
            o=split(data,';');
            program.updateMusic(Music(o),o[10]);
            in_file.close();
            out_file.close();
            break;
        case UPDATE_MUSICIAN:
            in_file.open(fileData(option));
            getline(in_file,data);
            o=split(data,';');
            program.serviceMusician.update(Musician(o));
            in_file.close();
            out_file.close();
            break;
        case UPDATE_SINGER:
            in_file.open(fileData(option));
            getline(in_file,data);
            o=split(data,';');
            program.serviceSinger.update(Singer(o));
            in_file.close();
            out_file.close();
            break;
        case UPDATE_ALBUM:
            in_file.open(fileData(option));
            getline(in_file,data);
            o=split(data,';');
            program.updateAlbum(Album(o),o[4]);
            in_file.close();
            out_file.close();
            break;
        case INCREASE_VIEW:
            cin>>id;
            program.updateView(id);
            out_file.close();
            break;
        case EXIT:
            out_file<<""<<endl;
            out_file.close();
            break;

        default:
            out_file<<"Page not found 404"<<endl;
            out_file.close();
        }
    }
    while(option!=EXIT);
    system("pause");
    return 0;
}
istream& operator>>(istream& is, API& i )
{
    int tmp ;
    if ( is >> tmp )
        i = static_cast<API>( tmp ) ;
    return is ;
}
string file(int op)
{
    return "API"+to_string(op)+".txt";
}
string fileData(int op)
{
    return "API_In"+to_string(op)+".txt";
}
