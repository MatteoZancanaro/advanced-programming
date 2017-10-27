#include <iostream>
#include <memory>

template <typename num>
class Vector{
<<<<<<< HEAD
  std::unique_ptr<num[]> elems; // Unique pointer is used in order not to write a destructor.
=======
>>>>>>> bd8764c80384a9558887246196791d5d53ae30c4
  unsigned int _size;
  std::unique_ptr<num[]> elems;
public:
  explicit Vector(const unsigned int s);
  // Vector(std::initializer_list<num> lst);
  unsigned int size() const noexcept;

  num& operator[](const unsigned int i) noexcept; // this one will be used when the vector is not const.
  const num& operator[](const unsigned int i) const noexcept; // if vector is called as const, this one is gonna be used.

  num& at(const unsigned int i);
  const num& at(const unsigned int i) const;

  num* begin() noexcept { return elems.get(); } // It returns a num* pointing to the first element of elems.
  num* end() noexcept { return elems.get() + _size; }
  
  const num* begin() const noexcept { return elems.get(); }
  const num* end() const noexcept { return elems.get() + _size; }

  void resize(const Vector& v);
  void resize(const unsigned int s);
};


template <class num>
std::ostream& operator<<(std::ostream& os, const Vector<num>& v)
{
  for (const auto x : v) //auto is a key word that choses between types of variables in an automatic way (in this case it is num).
    os << x << " ";
  os << std::endl;
  return os;
}

template <typename num>
void print_vector(const char* s,const Vector<num>& v)
{
  std::cout <<"-----------------------------------\n"
	    << s << "\n"
	    << " size : "<< v.size() << "\n"
	    << "elems : " << v
	    <<"-----------------------------------\n";
}


int main()
{}
