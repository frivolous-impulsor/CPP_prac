#include <typeindex>
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm> // for std::max
#include <cmath>     // for std::abs

class Date{
//private:
    int m_year {};
    int m_month {};
    int m_day {};

    void print() {
        std::cout<<m_year<<'/'<<m_month<<'/'<<m_day<<'\n';
    }

};

class point3D{
private:
    int m_x {};
    int m_y {};
    int m_z {};

public:
    point3D(int x, int y, int z){
        m_x = x;
        m_y = y;
        m_z = z;
    }
    void setVals(int x, int y, int z){
        m_x = x;
        m_y = y;
        m_z = z;
    }
    void print() const {//print semantically should not change the calling obj. If a const obj calls, print can only handle with const signiture
        std::cout<<"<"<< m_x << "," << m_y << "," << m_z <<">";
    }

    bool isEqual(point3D p){
        return (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z);
    }

};

class Employee{
private:
    std::string m_name;

public:
    void setName(std::string name){
        m_name = name;
    }



    std::string& getName(){
        std::cout<<&m_name<<'\n';
        return m_name;  //if return by reference, the obj is the original. if not, the returned obj is a temporary obj with no accessible address
    }

};




int main(){
    const point3D p {3,4,5};
    p.print();  
    return 0;
}