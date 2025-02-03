#ifndef WHATEVER_HPP
#define WHATEVER_HPP

namespace mod {

template <typename T> void swap(T &a, T &b) {
    const T &temp = a;
    a = b;
    b = temp;
}

template <typename T> const T &min(const T &a, const T &b) { return a < b ? a : b; }

template <typename T> const T &max(const T &a, const T &b) { return a > b ? a : b; }

} // namespace mod

#endif
