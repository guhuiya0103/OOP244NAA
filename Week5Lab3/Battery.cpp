#include "Battery.h"
 
using namespace std;
 
namespace sdds {
    void Battery::setEmpty(){
        m_charge = -1;
    }

    Battery::Battery(){
        m_charge = 0;
    }
    Battery::Battery(int charge){
        set(charge);
    }
    Battery& Battery::set(int charge){
        if(charge >= 0 && charge <= 100){
            m_charge = charge;
        }else{
            setEmpty();
        }
        return *this; //this means return type is Battery not Battery pointer Battery*
    }
    ostream& Battery::display(ostream& ostr) const{
        if (m_charge >=0 && m_charge <=100){
            ostr << "Battery: " << m_charge << "%";
        } else {
            ostr << "Invalid Battery";
        }
        return ostr;
    }

    Battery& Battery::operator+=(int value) {
        if (m_charge >= 0 && m_charge <= 100 && (m_charge + value <= 100)) {
            m_charge += value;
        }
        return *this;
    }

    Battery& Battery::operator-=(int value) {
        if (m_charge >= 0 && m_charge <= 100 && (m_charge - value >= 0)) {
            m_charge -= value;
        }
        return *this;
    }


    Battery& Battery::operator++() {
        if (m_charge >= 0 && m_charge < 100) {
            m_charge++;
        }
        return *this;
    }

    Battery Battery::operator++(int){
        Battery previous = *this;
        ++(*this);
        return previous;
    }

    Battery::operator bool() const {
        return m_charge > 0;
    }

    Battery::operator int() const {
        if (m_charge >= 0 && m_charge <= 100) {
            return m_charge;
        } else {
            return 0;
        }
    }
}
