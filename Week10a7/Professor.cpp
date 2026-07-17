#include <iostream>
#include "Professor.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    Professor::Professor(const char* name, const char* subject, int sections, size_t employeeNo, double salary)
        : Employee(name, employeeNo, salary), m_subject(nullptr), m_sections(sections) {
        ut.alocpy(m_subject, subject);
    }

    Professor::~Professor() {
        delete[] m_subject;
    }

    double Professor::devPay() const {
        return salary() * 0.01 * m_sections;
    }
    
    std::istream& Professor::read(std::istream& istr) {
        Employee::read(istr);
        
        istr.ignore(); 

        char buffer[1024];
        istr.getline(buffer, 1024, ',');
        ut.alocpy(m_subject, buffer);

        istr >> m_sections;
        
        return istr;
    }

    std::ostream& Professor::write(std::ostream& ostr) const {
        Employee::write(ostr);
        
        ostr << " ";

        char subj2print[21]{};
        if (m_subject) {
            ut.strcpy(subj2print, m_subject, 20);
        }

        ostr.width(20);
        ostr.setf(ios::left);
        ostr << subj2print << " | ";
        ostr.unsetf(ios::left);

        ostr.width(5);
        ostr.setf(ios::right);
        ostr << m_sections << " | ";
        ostr.unsetf(ios::right);

        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr.width(8);
        ostr.setf(ios::right);
        ostr << devPay() << " |";
        
        ostr.unsetf(ios::right);
        ostr.unsetf(ios::fixed);

        return ostr;
    }

    std::ostream& Professor::title(std::ostream& ostr) const {
        Employee::title(ostr);
        ostr << " Teaching Subject | Sec # | $Dev Pay |";
        return ostr;
    }

    ostream& operator<<(ostream& ostr, const Professor& P) {
        return P.write(ostr);
    }

    istream& operator>>(istream& istr, Professor& P) {
        return P.read(istr);
    }
}