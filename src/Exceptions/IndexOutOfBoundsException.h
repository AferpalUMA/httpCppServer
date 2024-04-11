#pragma once
#include<exception>
class IndexOutOfBoundsEXception: public std::exception
{
  virtual const char* what() const throw()
  {
    return "IndexOutOfBounds";
  }
};