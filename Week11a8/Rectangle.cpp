#include <iostream>
#include "Rectangle.h"
#include "Utils.h"

namespace seneca {
   Rectangle::Rectangle(const char* label1, int width, int height) 
      : LblShape(label1), m_width(width), m_height(height) {
      if (m_height < 3) {
         m_height = 3;
      }
      int minWidth = 0;
      if (label()) {
        minWidth = ut.strlen(label()) + 2;
      }
      if (m_width < minWidth) {
         m_width = minWidth;
      }
   }

   void Rectangle::getSpecs(std::istream& is) {
      LblShape::getSpecs(is);
      is >> m_width;
      is.ignore();
      is >> m_height;
      is.ignore(1000, '\n');
   }

   void Rectangle::draw(std::ostream& os) const {
      if (m_width > 0 && m_height > 0) {
         os << '+';
         for (int i = 0; i < m_width - 2; ++i) os << '-';
         os << "+\n";
         os << '|';
         os.setf(std::ios::left);
         os.width(m_width - 2);
         os << (label() ? label() : "");
         os << "|\n";
         os.unsetf(std::ios::left);
         for (int i = 0; i < m_height - 3; ++i) {
            os << '|';
            os.width(m_width - 2);
            os.fill(' ');
            os << "";
            os << "|\n";
         }
         os << '+';
         for (int i = 0; i < m_width - 2; ++i) os << '-';
         os << '+';
      }
   }

}