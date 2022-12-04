#include"LinkedList.h"
#include<string>
using namespace std;
#ifndef SERVICES_H
#define SERVICES_H
template<typename T>
class Services{
    public:
        Services();
        ~Services();
        void add(T );
        T getById(int );
        void deleteById(int );
        void update(const T& );
        void save();
        LinkedList<T>& getEntities();
        string getJSON_Objects();
        LinkedList<T>& sorting(bool cmp(const T& ,const T& ));
    protected:
        static int generate_id;
        LinkedList<T> listObjects;
        friend class ManagedServices;
};
#include"../src/Services.hpp"
#endif // SERVICES_H
