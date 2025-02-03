#include <whatever.hpp>

Class::Class(const int x) : _x(x) {}
Class::~Class() {};

bool Class::operator<(const Class &other) const { return _x < other._x; }
bool Class::operator>(const Class &other) const { return _x > other._x; }
bool Class::operator>=(const Class &other) const { return _x >= other._x; }
bool Class::operator<=(const Class &other) const { return _x <= other._x; }
bool Class::operator==(const Class &other) const { return _x == other._x; }
