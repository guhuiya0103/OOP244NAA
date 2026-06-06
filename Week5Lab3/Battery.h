#ifndef SDDS_BATTERY_H
#define SDDS_BATTERY_H
#include <iostream>

namespace sdds{
    class Battery
    {
        int m_charge;
        void setEmpty();
        
    public:
        Battery();
        Battery(int charge);
        Battery& set(int charge);
        std::ostream& display(std::ostream& ostr = std::cout) const;
        Battery& operator+=(int value);
        Battery& operator-=(int value);
        Battery& operator++();
        Battery operator++(int);
        operator bool() const;
        operator int() const;

    };
    
}
#endif
