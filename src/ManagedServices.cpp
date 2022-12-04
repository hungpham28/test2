#include "ManagedServices.h"
#include "DatabaseMapping.h"
#include<sstream>
ManagedServices::ManagedServices()
{
    //Mapping relationship with singers
    string line;
    string* data;
    ifstream input_file(URI_MUSIC_SINGER);

    while(input_file>>line)
    {
        data=split(line,';');
        music_singers.push_back(Mapping<Music,Singer>(stoi(data[0]),stoi(data[1])));
    }
    for(Node<Music>* music=serviceMusic.listObjects.begin(); music!=NULL; music=music->next)
    {
        for (Node<Mapping<Music,Singer>>* row=music_singers.begin(); row!=NULL; row=row->next)
        {
            if(music->data.getId()==row->data.key1)
            {
                row->data.val1=&(music->data);
            }
        }
    }

    for(Node<Singer>* singer=serviceSinger.listObjects.begin(); singer!=NULL; singer=singer->next)
    {
        for (Node<Mapping<Music,Singer>>* row=music_singers.begin(); row!=NULL; row=row->next)
        {
            if(singer->data.getId()==row->data.key2)
            {
                row->data.val2=&(singer->data);
            }
        };
    }
    //Mapping relationship with singers
    ifstream input_file2(URI_ALBUM_MUSIC);
    while(input_file2>>line)
    {
        data=split(line,';');
        album_music.push_back(Mapping<Album,Music>(stoi(data[0]),stoi(data[1])));
    }

    for(Node<Album>* album=serviceAlbum.listObjects.begin(); album!=NULL; album=album->next)
    {
        for (Node<Mapping<Album,Music>>* row=album_music.begin(); row!=NULL; row=row->next)
        {
            if(album->data.getId()==row->data.key1)
            {
                row->data.val1=&(album->data);
            }
        };
    }

    for(Node<Music>* music=serviceMusic.listObjects.begin(); music!=NULL; music=music->next)
    {
        for (Node<Mapping<Album,Music>>* row=album_music.begin(); row!=NULL; row=row->next)
        {
            if(music->data.getId()==row->data.key2)
            {
                row->data.val2=&(music->data);
            }
        }
    }


}

ManagedServices::~ManagedServices()
{

}
string ManagedServices::getEagerMusics()
{
    string JSON="";
    for(Node<Music>* it = serviceMusic.listObjects.begin(); it != NULL; it=it->next)
    {
        const Music& music=it->data;
        JSON+="{"+music.toString()+","+FormatStringJSON("singers")+":"
              +getSingersByMusicId(music.getId())+",";
        JSON+=FormatObjectJSON("type",serviceType.getById(music.getTypeId()).toString())+",";
        JSON+=FormatObjectJSON("musician",serviceMusician.getById(music.getMusicianId()).toString())+"}";
        if(it->next!=NULL) JSON+=",";
    }
    return FormatListJSON(JSON,false);
};
string ManagedServices::getEagerAlbums()
{
    string JSON="";
    for(Node<Album>* it = serviceAlbum.listObjects.begin(); it != NULL; it=it->next)
    {
        const Album& album=it->data;
        JSON+="{"+album.toString()+","+FormatStringJSON("musics")+":"
              +getMusicsByAlbumId(album.getId())+"}";
        if(it->next!=NULL) JSON+=",";
    }
    return FormatListJSON(JSON,false);
};
string ManagedServices::getEagerSingers()
{
    string JSON="";
    for(Node<Singer>* it = serviceSinger.listObjects.begin(); it != NULL; it=it->next)
    {
        const Singer& singer=it->data;
        JSON+="{"+singer.toString()+","+FormatStringJSON("musics")+":"
              +getMusicsBySingerId(singer.getId())+"}";
        if(it->next!=NULL) JSON+=",";
    }
    return FormatListJSON(JSON,false);
};
string ManagedServices::getEagerMusicians()
{
    string JSON="";
    for(Node<Musician>* it = serviceMusician.listObjects.begin(); it != NULL; it=it->next)
    {
        const Musician& musician=it->data;
        JSON+="{"+musician.toString()+","+FormatStringJSON("musics")+":"
              +getMusicsByMusicianId(musician.getId())+"}";
        if(it->next!=NULL) JSON+=",";
    }
    return FormatListJSON(JSON,false);
};
string ManagedServices::getMusicsByMusicianId(int id){
    string JSON="";
    bool c=false;
    for(Node<Music>* it =serviceMusic.listObjects.begin(); it != NULL; it=it->next)
    {
        const Music& music=it->data;
        if(music.getMusicianId()==id)
        {
            if(c) JSON+=",";
            JSON+="{"+FormatObjectJSON("type",serviceType.getById(music.getTypeId()).toString())+",";
            JSON+=music.toString()+"}";
            c=true;
        }
    }
    return FormatListJSON(JSON);
}
string ManagedServices::getEagerMusicById(int id)
{
    string JSON="";
    for(Node<Music>* it =serviceMusic.listObjects.begin(); it != NULL; it=it->next)
    {
        const Music& music=it->data;
        if(music.getId()==id)
        {
            JSON+=FormatObjectJSON("type",serviceType.getById(music.getTypeId()).toString())+",";
            JSON+=music.toString()+","+FormatStringJSON("singers")+":"+getSingersByMusicId(music.getId())+",";
            JSON+=FormatObjectJSON("musician",serviceMusician.getById(music.getMusicianId()).toString());
            return FormatObjectJSON(JSON);
        }
    }
    return FormatObjectJSON(JSON);
}

void ManagedServices::addMusic(const Music& m,const string& rel)
{
    serviceMusic.add(m);
    stringstream in(rel);
    LinkedList<int> singerIds;
    int singerId;
    Music& music=serviceMusic.listObjects.end()->data;
    while(in>>singerId)
    {
        singerIds.push_back(singerId);
    }
    for(Node<Singer>* singer=serviceSinger.listObjects.begin(); singer!=NULL; singer=singer->next)
    {
        for(Node<int>* id=singerIds.begin(); id!=NULL; id=id->next)
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
void ManagedServices::addAlbum(const Album& m,const string& rel)
{
    serviceAlbum.add(m);
    stringstream in(rel);
    LinkedList<int> musicIds;
    int musicId;
    Album& album=serviceAlbum.listObjects.end()->data;
    while(in>>musicId)
    {
        musicIds.push_back(musicId);
    }
    for(Node<Music>* music=serviceMusic.listObjects.begin(); music!=NULL; music=music->next)
    {
        for(Node<int>* id=musicIds.begin(); id!=NULL; id=id->next)
        {
            if(music->data.getId()==id->data)
            {
                album_music.push_back(Mapping<Album,Music>(album.getId(), id->data));
                album_music.end()->data.val1=&album;
                album_music.end()->data.val2=&(music->data);
            }

        }
    }
    save();
}
void ManagedServices::save()
{
    //Mở file bằng ofstream
    ofstream output_file(URI_MUSIC_SINGER);

    for(Node<Mapping<Music,Singer>>* o=music_singers.begin(); o!=NULL; o=o->next)
    {
        output_file<<o->data.toText()<<"\n";
    }
    output_file.close();
    ofstream output_file2(URI_ALBUM_MUSIC);
    for(Node<Mapping<Album,Music>>* o=album_music.begin(); o!=NULL; o=o->next)
    {
        output_file2<<o->data.toText()<<"\n";
    }
    output_file2.close();
}
void ManagedServices::deleteMusicById( int id)
{
    serviceMusic.deleteById(id);
    Mapping<Music,Singer> a(id,0);
    music_singers.remove(a);
    save();
}
void ManagedServices::updateMusic(const Music& m,const string& rel)
{
    serviceMusic.update(m);
    Mapping<Music,Singer> a(m.getId(),0);
    music_singers.remove(a);
    stringstream in(rel);
    Music* music;
    for(Node<Music>* temp=serviceMusic.listObjects.begin(); temp!=NULL; temp=temp->next)
    {
        if(temp->data.getId()==m.getId())
        {
            music=&(temp->data);
            break;
        }
    }
    int singerId;
    while(in>>singerId)
    {
        music_singers.push_back(Mapping<Music,Singer>(m.getId(),singerId));
        for(Node<Singer>* singer=serviceSinger.listObjects.begin(); singer!=NULL; singer=singer->next)
        {
            if(singer->data.getId()==singerId)
            {
                music_singers.end()->data.val1=music;
                music_singers.end()->data.val2=&(singer->data);
            }
        }
    }
    save();
}
void ManagedServices::updateAlbum(const Album& m,const string& rel)
{
    serviceAlbum.update(m);
    Mapping<Album,Music> a(m.getId(),0);
    album_music.remove(a);
    stringstream in(rel);
    Album* album;
    for(Node<Album>* temp=serviceAlbum.listObjects.begin(); temp!=NULL; temp=temp->next)
    {
        if(temp->data.getId()==m.getId())
        {
            album=&(temp->data);
            break;
        }
    }
    int musicId;
    while(in>>musicId)
    {
        album_music.push_back(Mapping<Album,Music>(m.getId(),musicId));
        for(Node<Music>* music=serviceMusic.listObjects.begin(); music!=NULL; music=music->next)
        {
            if(music->data.getId()==musicId)
            {
                album_music.end()->data.val1=album;
                album_music.end()->data.val2=&(music->data);
            }
        }
    }
    save();
}
string ManagedServices::getSingersByMusicId(int id)
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
    return FormatListJSON(JSON,false);
}
string ManagedServices::getMusicsBySingerId(int id)
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
    return FormatListJSON(JSON,false);
}
void ManagedServices::deleteSingerById(int id)
{
    serviceSinger.deleteById(id);
    Mapping<Music,Singer> a(0,id);
    music_singers.remove(a);
    save();
}
void ManagedServices::deleteAlbumById(int id)
{
    serviceAlbum.deleteById(id);
    Mapping<Album,Music> a(id,0);
    album_music.remove(a);
    save();
}
string ManagedServices::getAlbumsByMusicId(int id)
{
    string JSON="";
    bool c=false;
    for (Node<Mapping<Album,Music>>* itAM=album_music.begin(); itAM!=NULL; itAM=itAM->next)
    {
        const Mapping<Album,Music>& row=itAM->data;
        if(row.key2==id)
        {
            if(c) JSON+=",";
            JSON+=FormatObjectJSON(row.val1->toString());
            c=true;
        }
    }
    return FormatListJSON(JSON,false);
}
string ManagedServices::getMusicsByAlbumId(int id)
{
    string JSON="";
    bool c=false;
    for (Node<Mapping<Album,Music>>* itAM=album_music.begin(); itAM!=NULL; itAM=itAM->next)
    {
        const Mapping<Album,Music>& row=itAM->data;
        if(row.key1==id)
        {
            if(c) JSON+=",";
            JSON+=FormatObjectJSON(row.val2->toString());
            c=true;
        }
    }
    return FormatListJSON(JSON,false);
}
string ManagedServices::searchMusics(const Music& m)
{
    string JSON="";
    bool c=false;
    for (Node<Music>* it=serviceMusic.listObjects.begin(); it!=NULL; it=it->next)
    {
        const Music& row=it->data;
        if(row.as(m))
        {
            if(c) JSON+=",";
            JSON+=FormatObjectJSON(row.toString());
            c=true;
        }
    }
    return FormatListJSON(JSON,false);
}
void ManagedServices::updateView(int id)
{
    for(Node<Music>* music=serviceMusic.listObjects.begin(); music!=NULL; music=music->next)
    {
        if(music->data.getId()==id)
        {
            music->data.setView(music->data.getView()+1);
            serviceMusic.save();
            cout<<"enter";
            break;
        }
    }
}
string ManagedServices::getEagerAlbumById(int id)
{
    string JSON="";
    for(Node<Album>* it =serviceAlbum.listObjects.begin(); it != NULL; it=it->next)
    {
        const Album& album=it->data;
        if(album.getId()==id)
        {
            JSON+=album.toString()+","+FormatStringJSON("musics")+":"+getMusicsByAlbumId(album.getId());
            return FormatObjectJSON(JSON);
        }
    }
    return FormatObjectJSON(JSON);
}
