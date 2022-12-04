#include "Person.h"

int Person::number=0;

Person::Person():id(0)
{
}
Person::Person(const string* data){
    id=stoi(data[0]);
    fullname=data[1];
    birthday=Date(data[2]);
    gender=data[3];
    introduction=data[4];
    avatar=data[5];
}
Person::~Person()
{
    //dtor
}

//Person::Person(const Person& other)
//{
//    //copy ctor
//}
//string Person::showGender(Gender gender){
//    switch(gender){
//        case Gender::MALE :
//            return "Male";
//        case Gender::FEMALE :
//            return "Female";
//        case Gender::OTHER :
//            return "Other";
//        default:
//            return "";
//    }
//}
//Person& Person::operator=(const Person& rhs)
//{
//    if (this == &rhs) return *this; // handle self assignment
//    //assignment operator
//    return *this;
//}
string Person::toText(){
    return to_string(id)+";"+fullname+";"+birthday.getDate()+";"+gender+";"+introduction+";"+avatar;
}
