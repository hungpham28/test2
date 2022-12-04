#include"Musician.h"
#ifndef SERVICEMUSICIAN_H
#define SERVICEMUSICIAN_H
#include"Services.h"

class ServiceMusician:public Services<Musician>
{
    public:
        ServiceMusician();
        virtual ~ServiceMusician();

    protected:

    private:
};

#endif // SERVICEMUSICIAN_H
