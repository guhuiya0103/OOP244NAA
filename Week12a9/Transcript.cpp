#include <iostream>
#include "Transcript.h"
#include "Utils.h"

using namespace std;

namespace seneca {

   Transcript::Transcript(const char* name, unsigned int studentNum) {
        ut.alocpy(m_studentName, name);
        m_studentNum = studentNum;
   }

   Transcript::Transcript(const Transcript& other) {
        Marks(other);
        ut.alocpy(m_studentName, other.m_studentName);
        m_studentNum = other.m_studentNum;
   }

   Transcript& Transcript::operator=(const Transcript& other) {
        if (this != &other) {
            Marks::operator=(other);

            ut.alocpy(m_studentName, other.m_studentName);
            m_studentNum = other.m_studentNum;
        }
        return *this;
   }

   Transcript::~Transcript() {
        delete[] m_studentName;
        m_studentName = nullptr;
   }

   ostream& Transcript::display(ostream& ostr) const {
        ostr << m_studentName << " (" << m_studentNum << ")" << endl;
        ostr << "--------------------------------------------------------------------------" << endl;
        Marks::display(ostr);
        return ostr;
   }
}