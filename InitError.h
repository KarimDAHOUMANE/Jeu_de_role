#ifndef INITERROR_H
#define INITERROR_H
#include <iostream>
#include <exception>

using namespace std;

class InitError : public exception
{
    string msg;
public:
    InitError() :
        exception(),
        msg( SDL_GetError() )
    {
    }
    InitError( const string & m ) :
        exception(),
        msg( m )
    {
    }
    virtual ~InitError() throw()
    {
    }
    virtual const char * what() const throw()
    {
        return msg.c_str();
    }
};

#endif // INITERROR_H
