#include <cassert>
#include <iostream>
#include <string>
#include <whatever.hpp>

void testSwapString() {
    std::string a = "Hello", b = "World";

    mod::swap(a, b);

    assert(a == "World");
    assert(b == "Hello");
}

void testSwapInt() {
    int a = 420, b = 69;

    mod::swap(a, b);

    assert(a == 69);
    assert(b == 420);
}

void testSwapStruct() {
    struct Struct a = {.a = 69, .s = "Hello"}, b = {.a = 420, .s = "World"};

    mod::swap(a, b);

    assert(a.a == 420);
    assert(a.s == "World");

    assert(b.a == 69);
    assert(b.s == "Hello");
}

void testMinString() {
    const std::string a = "Hello", b = "World";

    const std::string &c = mod::min(a, b);

    assert(c == "Hello");
    assert(&c == &a);
}

void testMinStringEqual() {
    const std::string a = "Hello", b = "Hello";

    const std::string &c = mod::min(a, b);

    assert(c == b);
    assert(&c == &b);
}

void testMinInt() {
    const int a = 69, b = 420;

    const int &c = mod::min(a, b);

    assert(c == a);
    assert(&c == &a);
}

void testMinIntEqual() {
    const int a = 69, b = 69;

    const int &c = mod::min(a, b);

    assert(c == b);
    assert(&c == &b);
}

void testMinClass() {
    const Class a(69), b(420);

    const Class &c = mod::min(a, b);

    assert(c == a);
    assert(&c == &a);
}

void testMinClassEqual() {
    const Class a(69), b(69);

    const Class &c = mod::min(a, b);

    assert(c == b);
    assert(&c == &b);
}

void testMaxString() {
    const std::string a = "Hello", b = "World";

    const std::string &c = mod::max(a, b);

    assert(c == "World");
    assert(&c == &b);
}

void testMaxStringEqual() {
    const std::string a = "Hello", b = "Hello";

    const std::string &c = mod::max(a, b);

    assert(c == b);
    assert(&c == &b);
}

void testMaxInt() {
    const int a = 69, b = 420;

    const int &c = mod::max(a, b);

    assert(c == b);
    assert(&c == &b);
}

void testMaxIntEqual() {
    const int a = 69, b = 69;

    const int &c = mod::max(a, b);

    assert(c == b);
    assert(&c == &b);
}

void testMaxClass() {
    const Class a(69), b(420);

    const Class &c = mod::max(a, b);

    assert(c == b);
    assert(&c == &b);
}

void testMaxClassEqual() {
    const Class a(69), b(69);

    const Class &c = mod::max(a, b);

    assert(c == b);
    assert(&c == &b);
}

void subjectMain() {
    int a = 2;
    int b = 3;
    mod::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << mod::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << mod::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    mod::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << mod::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << mod::max(c, d) << std::endl;
}

int main() {
    testSwapString();
    testSwapInt();
    testSwapStruct();

    testMinString();
    testMinStringEqual();
    testMinInt();
    testMinIntEqual();
    testMinClass();
    testMinClassEqual();

    testMaxString();
    testMaxStringEqual();
    testMaxInt();
    testMaxIntEqual();
    testMaxClass();
    testMaxClassEqual();

    subjectMain();
}
