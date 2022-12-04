#include<string>
#include"Date.h"
#include<fstream>
using namespace std;
#ifndef ALBUM_H
#define ALBUM_H


class Album
{
public:
    static const string TABLE;

    Album();
    Album(string* );
    virtual ~Album();

    int getId()const
    {
        return id;
    }
    void setId(int val)
    {
        id = val;
    }
    string getTitle()const
    {
        return title;
    }
    void setTitle(string val)
    {
        title = val;
    }
    string getDescription()const
    {
        return description;
    }
    void setDescription(string val)
    {
        description = val;
    }
    Date getCreatedDate()
    {
        return createdDate;
    }
    void setCreatedDate(string val)
    {
        createdDate = val;
    }
    string toString()const;
    string toText()const;
    bool operator== (const Album &)const;
    bool operator!= (const Album &)const;
    friend ofstream& operator<<(ofstream& , const Album& );
protected:

private:
    int id;
    string title;
    string description;
    Date createdDate;
};

#endif // ALBUM_H
