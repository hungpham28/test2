#include<string>

#ifndef MUSICIAN_H
#define MUSICIAN_H

#include "Person.h"


class Musician : public Person
{
    public:
        static const string TABLE;
        Musician();
        Musician(const string* data);
        virtual ~Musician();
//        Musician(const Musician& other);

        int GetnumOfSongs() { return numOfSongs; }
        void SetnumOfSongs(int val) { numOfSongs = val; }
        string Getawarded() { return awarded; }
        void Setawarded(string val) { awarded = val; }
        bool operator== (const Musician &musician)const;
        bool operator!= (const Musician &musician)const;
        friend ofstream& operator<<(ofstream& , const Musician& );
        string toString()const;
        string toText();

    private:
        int numOfSongs;
        string awarded;

};

#endif // MUSICIAN_H
