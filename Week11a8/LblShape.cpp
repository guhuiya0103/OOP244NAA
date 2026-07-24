#include <iostream>
#include "LblShape.h"
#include "Utils.h"

namespace seneca {

   const char* LblShape::label() const {
      return m_label;
   }

   LblShape::LblShape(const char* label) {
      ut.alocpy(m_label, label);
   }

   LblShape::~LblShape() {
      delete[] m_label;
      m_label = nullptr;
   }

   void LblShape::getSpecs(std::istream& is) {
      char* buffer = new char[81];
      is.getline(buffer, 81, ',');
      ut.alocpy(m_label, buffer);
   }

}