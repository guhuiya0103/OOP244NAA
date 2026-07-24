#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H

#include "LblShape.h"

namespace seneca {

   class Rectangle : public LblShape {
      int m_width;
      int m_height;

   public:
      // Default constructor
      Rectangle() = default;

      // Constructor that initializes label, width, and height
      Rectangle(const char* label1, int width, int height);

      // Draws the rectangle using label, width, and height
      void draw(std::ostream& os) const override;

      // Gets specifications of the rectangle from input
      void getSpecs(std::istream& is) override;
   };

}

#endif // !SENECA_RECTANGLE_H