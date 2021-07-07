#ifndef POSITION_H
#define POSITION_H

using namespace std;


class Position
{
private:
    int x;
    int y;
public:
    Position(int,int);
    virtual ~Position();
    int getX() const;
    int getY() const;
    void setX(unsigned int);
    void setY(unsigned int);
    bool operator==(Position const&);
protected:
};


#endif // POSITION_H
