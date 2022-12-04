#include<string>

#ifndef MUCIAN_H
#define MUCIAN_H

#include "Person.h"


class Mucian : public Person
{
    public:
        Mucian();
        virtual ~Mucian();
        Mucian(const Mucian& other);

        int GetnumOfSongs() { return numOfSongs; }
        void SetnumOfSongs(int val) { numOfSongs = val; }
        string Getawarded() { return awarded; }
        void Setawarded(string val) { awarded = val; }
        string toString();
        static const string attributes;
        static const string table;

    private:
        int numOfSongs;
        string awarded;
};

#endif // MUCIAN_H
