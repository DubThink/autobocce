#ifndef COORD_H
#define COORD_H
#include <stdio.h>

/**
 * @brief Header only integer coordinate class
 */
class Coord{
public:
    int x,y;

    Coord(int x, int y){
        this->x=x;
        this->y=y;
    }
    Coord operator+(const Coord& c) const{
        Coord coord(x+c.x,y+c.y);
        return coord;
    }       // operator+()
    Coord operator-(const Coord& c) const{
        Coord coord(x-c.x,y-c.y);
        return coord;
    }
    Coord& operator+=(const Coord& c){
        x+=c.x;
        y+=c.y;
        return *this;
    }
    Coord& operator-=(const Coord& c){
        x-=c.x;
        y-=c.y;
        return* this;
    }
    float dist2(Coord& c){
        //printf(" T: (%d, %d)\n",x,y);
        //printf(" c: (%d, %d)\n",c.x,c.y);
        return (x-c.x)*(x-c.x)+(y-c.y)*(y-c.y);
    }
    static void unitTest(){
     Coord a=Coord(2,3);
     printf("Coord a: (%d, %d)\n",a.x,a.y);
     a.x=14;
     printf("Coord a: (%d, %d)\n",a.x,a.y);
     Coord b=Coord(2,2);
     printf("Coord b: (%d, %d)\n",b.x,b.y);
     Coord c=b-a;
     printf("Coord c: (%d, %d)\n",c.x,c.y);
     printf("Coord a: (%d, %d)\n",a.x,a.y);
     a+=b;
     printf("Coord a: (%d, %d)\n",a.x,a.y);
     printf("Dist: %.3f\n",a.dist2(c));
    }
};
#endif // COORD_H
