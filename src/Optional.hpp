#include "Optional.h"

Optional::Optional()
{
    //ctor
}

Optional::~Optional()
{
    //dtor
}
friend istream &operator >>(istream &, T &);
friend ostream &operator <<(ostream &, const T &);
T operator + (const T &);
T operator - (const T &);
T operator * (const T &);
int &operator [] (int ) const;
const T& operator= (const T& );
friend bool operator== (const T& c1, const T& c2);
friend bool operator!= (const T& c1, const T& c2);

friend bool operator< (const T& c1, const T& c2);
friend bool operator> (const T& c1, const T& c2);

friend bool operator<= (const T& c1, const T& c2);
friend bool operator>= (const T& c1, const T& c2);
