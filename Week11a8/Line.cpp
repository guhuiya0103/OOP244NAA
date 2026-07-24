#include <iostream>
#include "Line.h"
#include "Utils.h"

namespace seneca {

   Line::Line(const char* label, int length) : LblShape(label) {
      m_length = length;
      if (label && m_length < ut.strlen(label)) {
         m_length = ut.strlen(label);
      }
   }

   void Line::getSpecs(std::istream& is) {
      LblShape::getSpecs(is);
      is >> m_length;
      is.ignore(1000, '\n');
   }

   void Line::draw(std::ostream& os) const {
      if (m_length > 0 && label() != nullptr) {
         os << label() << "\n";
         for (int i = 0; i < m_length; ++i) {
            os << '=';
         }
      }
   }

}