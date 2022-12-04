#define null -1
#ifndef OPTIONAL_H
#define OPTIONAL_H
enum OptionValue{null};
template<typename T>
class Optional
{
    public:
        Optional();
        virtual ~Optional();
        void setVal(T a){val=a};
        T getVal(){return val;};
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
    private:
        T val;
};

#endif // OPTIONAL_H
