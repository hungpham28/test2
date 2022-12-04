#include"Services.h"
#include"Musician.h"
#include"Music.h"
#include"Singer.h"
#include"Album.h"
#include"Type.h"
#ifndef MANAGEDSERVICES_H
#define MANAGEDSERVICES_H


class ManagedServices
{
    public:
        ManagedServices();
        virtual ~ManagedServices();
        Services<Musician> serviceMusician;
        Services<Singer> serviceSinger;
        Services<Music> serviceMusic;
        Services<Album> serviceAlbum;
        Services<Type> serviceType;
        string getEagerMusics();
        string getEagerAlbums();
        string getEagerMusicians();
        string getEagerSingers();
        string getEagerMusicById(int );
        string getEagerAlbumById(int );
        string getSingersByMusicId(int );
        string getMusicsBySingerId(int );
        string getMusicsByMusicianId(int );
        void deleteMusicById(int );
        void addMusic(const Music& ,const string& );
        void addAlbum(const Album& ,const string& );
        void updateMusic(const Music& ,const string& );
        void updateAlbum(const Album& ,const string& );
        void deleteSingerById(int );
        void deleteAlbumById(int );
        string getAlbumsByMusicId(int );
        string getMusicsByAlbumId(int );
        string searchMusics(const Music& );
        string getMusicsBySortView();
        void updateView(int );

    protected:
        void save();
    private:
        LinkedList<Mapping<Music,Singer>> music_singers;
        LinkedList<Mapping<Album,Music>> album_music;

};

#endif // MANAGEDSERVICES_H
