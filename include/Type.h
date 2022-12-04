#include<string>
using namespace std;
#ifndef TYPE_H
#define TYPE_H


class Type
{
    public:
        static const string TABLE;
        Type();
        Type(string* );
        virtual ~Type();
        int getId() { return id; }
        void setId(int val) { id = val; }
        string getName() { return name; }
        void setName(string val) { name = val; }
        string toString()const;
        string toText();
        bool operator== (const Type &)const;
        bool operator!= (const Type &)const;
        friend ofstream& operator<<(ofstream& , const Type& );
    protected:

    private:
        int id;
        string name;
};

#endif // TYPE_H
