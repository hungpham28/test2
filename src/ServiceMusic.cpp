#include "ServiceMusic.h"
#include<sstream>
#include <algorithm>
ServiceMusic::ServiceMusic():singerMembers(NULL),musicianMembers(NULL)
{
}

ServiceMusic::~ServiceMusic()
{
    //dtor
}
ServiceMusic::ServiceMusic(LinkedList<Singer>& singers,LinkedList<Musician>& musicians)
    :singerMembers(&singers),musicianMembers(&musicians)
{

    //Mapping relationship
    string line;
    string* data;
    string filename(URI_MUSIC_SINGER);
    ifstream input_file(filename);

    while(input_file>>line)
    {
        data=split(line,';');
        music_singers.push_back(Mapping<Music,Singer>(stoi(data[0]),stoi(data[1])));
    }
    for(Node<Music>* music=listObjects.begin(); music!=NULL; music=music->next)
    {
        for (Node<Mapping<Music,Singer>>* row=music_singers.begin(); row!=NULL; row=row->next)
        {
            if(music->data.getId()==row->data.key1)
            {
                row->data.val1=&(music->data);
            }
        }
    }

    for(Node<Singer>* singer=singerMembers->begin(); singer!=NULL; singer=singer->next)
    {
        for (Node<Mapping<Music,Singer>>* row=music_singers.begin(); row!=NULL; row=row->next)
        {
            if(singer->data.getId()==row->data.key2)
            {
                row->data.val2=&(singer->data);
            }
        };
    }
}
string ServiceMusic::getEagerMusics()
{
    string JSON="";
    for(Node<Music>* it = listObjects.begin(); it != NULL; it=it->next)
    {
        const Music& music=it->data;
        JSON+="{"+music.toString()+","+"singers"+":"
              +getSingersByMusicId(music.getId())+",";
        string JSON_Musician="";
        for( Node<Musician>* musician=musicianMembers->begin(); musician=NULL; musician=musician->next)
        {
            if(musician->data.getId()==music.getMusicianId())
            {
                JSON_Musician=musician->data.toString();
                break;
            }
        }
        JSON+=FormatObjectJSON("musician",JSON_Musician);
        JSON+="}";
        if(it->next!=NULL) JSON+=",";
    }
    return FormatListJSON(JSON);
};
string ServiceMusic::getEagerById(int id)
{
    string JSON="";
    for(Node<Music>* it = listObjects.begin(); it != listObjects.end(); it=it->next)
    {
        const Music& music=it->data;
        if(music.getId()==id)
        {
            JSON+=music.toString()+","+"singers"+":"+getSingersByMusicId(music.getId())+",";
            string JSON_Musician="";
            for( Node<Musician>* musician=musicianMembers->begin(); musician=NULL; musician=musician->next)
            {
                if(musician->data.getId()==music.getMusicianId())
                {
                    JSON_Musician=musician->data.toString();
                    break;
                }
            }
            JSON+=FormatObjectJSON("musician",JSON_Musician);
            return FormatObjectJSON(JSON);
        }
    }
    return FormatObjectJSON(JSON);
}
void ServiceMusic::add(const Music& m,const string& rel)
{
    Services<Music>::add(m);
    stringstream in(rel);
    LinkedList<int> singerIds;
    int singerId;
    Music& music=listObjects.end()->data;
    while(in>>singerId)
    {
        singerIds.push_back(singerId);
    }
    for(Node<Singer>* singer=singerMembers->begin(); singer!=NULL; singer=singer->next)
    {
        for(Node<int>* id=singerIds.begin();id!=NULL; id=id->next)
        {
            if(singer->data.getId()==id->data)
            {
                music_singers.push_back(Mapping<Music,Singer>(music.getId(), id->data));
                music_singers.end()->data.val1=&music;
                music_singers.end()->data.val2=&(singer->data);
            }

        }
    }
    save();
}
void ServiceMusic::save()
{
    //Mở file bằng ofstream
    ofstream output_file(URI_MUSIC_SINGER);

    for(Node<Mapping<Music,Singer>>* o=music_singers.begin(); o!=NULL; o=o->next)
    {
        output_file<<o->data.toText()<<"\n";
    }
    output_file.close();
}
void ServiceMusic::deleteById( int id)
{
    Services<Music>::deleteById(id);
    Music m; m.setId(id);
    listObjects.remove(m);
    save();
}
void ServiceMusic::update(const Music& m,const string& rel)
{
    Services<Music>::update(m);

    Mapping<Music,Singer> a(m.getId(),0);
    music_singers.remove(a);
    stringstream in(rel);
    int singerId;
    while(in>>singerId)
    {
        music_singers.push_back(Mapping<Music,Singer>(m.getId(),singerId));
    }
    save();
}
string ServiceMusic::getSingersByMusicId(int id)
{
    string JSON="";
    bool c=false;
    for (Node<Mapping<Music,Singer>>* itMS=music_singers.begin(); itMS!=NULL; itMS=itMS->next)
    {
        const Mapping<Music,Singer>& row=itMS->data;
        if(row.key1==id)
        {
            if(c) JSON+=",";
            JSON+=FormatObjectJSON(row.val2->toString());
            c=true;
        }
    }
    return FormatListJSON(JSON);
}
string ServiceMusic::getMusicsBySingerId(int id)
{
    string JSON="";
    bool c=false;
    for (Node<Mapping<Music,Singer>>* itMS=music_singers.begin(); itMS!=NULL; itMS=itMS->next)
    {
        const Mapping<Music,Singer>& row=itMS->data;
        if(row.key2==id)
        {
            if(c) JSON+=",";
            JSON+=FormatObjectJSON(row.val1->toString());
            c=true;
        }
    }
    return FormatListJSON(JSON);
}
