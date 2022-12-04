#include<string>
#include"Date.h"

using namespace std;
#ifndef PERSON_H
#define PERSON_H

#include"../Gender.h"


class Person
{
    public:

        static int number;
        Person();
        Person(const string* );
        virtual ~Person();
//        Person(const Person& other);
//        Person& operator=(const Person& other);

        int getId() const{ return id; }
        void setId(int val) { id = val; }
        string getFullname() const{ return fullname; }
        void setFullname(string val) { fullname = val; }
        Date getBirthday() { return birthday; }
        void setBirthday(Date val) { birthday = val; }
        string getGender() { return gender; }
        void setGender(string val) { gender = val; }
        string getIntroduction() { return introduction; }
        void setIntroduction(string val) { introduction = val; }
        string getAvatar() { return avatar; }
        void setAvatar(string val) { avatar = val; }
        string toText();


    protected:
        int id;
        string fullname;
        Date birthday;
        string gender;
        string introduction;
        string avatar;
};

#endif // PERSON_H
