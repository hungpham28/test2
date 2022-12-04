#include"Singer.h"
#ifndef SERVICESINGER_H
#define SERVICESINGER_H
#include"Services.h"

class ServiceSinger:public Services<Singer>
{
    public:
        ServiceSinger();
        virtual ~ServiceSinger();

    protected:

    private:
};

#endif // SERVICESINGER_H
