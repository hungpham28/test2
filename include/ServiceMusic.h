#include"Music.h"
#include"LinkedList.h"
#ifndef SERVICEMUSIC_H
#define SERVICEMUSIC_H
#include "Services.h"
#include "DatabaseMapping.h"
class ServiceMusic:public Services<Music>
{
    public:
        ServiceMusic();
        ServiceMusic(LinkedList<Singer>& ,LinkedList<Musician>& );
        virtual ~ServiceMusic();

        string getEagerMusics();
        string getEagerById(int );
        void deleteById(int );
        void add(const Music& ,const string& );
        void update(const Music& ,const string& );
        void save();

    protected:
        LinkedList<Mapping<Music,Singer>> music_singers;
        LinkedList<Singer>* singerMembers;
        LinkedList<Musician>* musicianMembers;
        string getSingersByMusicId(int );
        string getMusicsBySingerId(int );
};

#endif // SERVICEMUSIC_H
