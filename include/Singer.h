
#ifndef SINGER_H
#define SINGER_H

#include "Person.h"

class Singer: public Person
{
    public:
        static const string TABLE;
        Singer();
        Singer(string* );
        virtual ~Singer();
//        Singer(const Singer& other);

        string Getranking(){ return ranking; }
        void Setranking(string val) { ranking = val; }
        string Getnationality() { return nationality; }
        void Setnationality(string val) { nationality = val; }
        string toString()const;
        string toText();
        bool operator== (const Singer &singer)const;
        bool operator!= (const Singer &singer)const;
        friend ofstream& operator<<(ofstream& , const Singer& );
    protected:

    private:
        string ranking;
        string nationality;
};

#endif // SINGER_H
