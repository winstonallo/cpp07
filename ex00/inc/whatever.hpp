#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <string>

struct Struct {
    int a;
    std::string s;
};

class Class {
  private:
    const int _x;

    Class(const Class &other);
    Class &operator=(const Class &other);

  public:
    Class(const int x);
    ~Class();

    bool operator<(const Class &other) const;
    bool operator>(const Class &other) const;
    bool operator>=(const Class &other) const;
    bool operator<=(const Class &other) const;
    bool operator==(const Class &other) const;
};

namespace mod {

template <typename T> void swap(T &a, T &b) {
    const T temp = a;
    a = b;
    b = temp;
}

template <typename T> const T &min(const T &a, const T &b) { return a < b ? a : b; }

template <typename T> const T &max(const T &a, const T &b) { return a > b ? a : b; }

} // namespace mod

#endif
