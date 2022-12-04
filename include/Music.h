#include"Date.h"
#include<string>

#include"LinkedList.h"

using namespace std;
#ifndef MUSIC_H
#define MUSIC_H


class Music
{
public:
    static const string TABLE;
    Music();
    Music(string* );
    virtual ~Music();

    int getId()const{return id;}
    void setId(int val){id=val;}
    string getName()const{return name;}
    void setName(string val){name=val;}
    Date getCreatedDate()const{return createdDate;}
    void setCreatedDate(Date val){createdDate=val;}
    int getTypeId()const{return typeId;}
    void setTypeId(int val){typeId=val;}
    string getLyric()const{return lyric;}
    void setLyric(string val){lyric=val;}
    string getUrlMV()const{return urlMV;}
    void setUrlMV(string val){urlMV=val;}
    string getUrlAudio()const{return urlAudio;}
    void setUrlAudio(string val){urlAudio=val;}
    int getMusicianId()const{return musicianId;}
    void setMusicianId(int val){musicianId=val;}
    int getView()const{return view;}
    void setView(int val){view=val;}
    bool operator== (const Music &music)const;
    bool operator!= (const Music &music)const;
    friend ofstream& operator<<(ofstream& , const Music& );
    friend bool as(const Music& );
    string toString()const;
    string toText();
    bool as(const Music& )const;

private:
    int id;
    string name;
    Date createdDate;
    int typeId;
    string lyric;
    string urlMV;
    string urlAudio;
    int view;
    int duration;
    int musicianId;
};
bool equalMusic(const Music& );
#endif // MUSIC_H
