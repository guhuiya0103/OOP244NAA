#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include <iostream>
#include "Employee.h"

namespace seneca {
    class Professor : public Employee {
        char* m_subject{};
        int m_sections{};
        
        double devPay() const;
    public:
        Professor() = default;
        Professor(const char* name, const char* subject, int sections, size_t employeeNo, double salary);

        ~Professor();
        Professor(const Professor&) = delete;
        Professor& operator=(const Professor&) = delete;

        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::ostream& title(std::ostream& ostr = std::cout) const;
    };

    std::ostream& operator<<(std::ostream& ostr, const Professor& P);
    std::istream& operator>>(std::istream& istr, Professor& P);
}

#endif // !SENECA_PROFESSOR_H