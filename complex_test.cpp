#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>
#include "complex_test.h"
#include "c_class.h"

complex c1(0, 1), c2(1), c3(3, -5), c4(4, 2.5), c5(-3.5, 1.1);

void test_getters()
{
    assert(c1.get_re() == 0);
    assert(c2.get_re() == 1);
    assert(c3.get_re() == 3);
    assert(c4.get_re() == 4);
    assert(c5.get_re() == -3.5);

    assert(c1.get_im() == 1);
    assert(c2.get_im() == 0);
    assert(c3.get_im() == -5);
    assert(c4.get_im() == 2.5);
    assert(c5.get_im() == 1.1);

    assert(c1.get_abs() == 1);
    assert(c2.get_abs() == 1);
    assert(c3.get_abs() == sqrt(34));
    assert(c4.get_abs() == sqrt(22.25));
    assert(c5.get_abs() == sqrt(13.46));

    assert(c1.get_conj() == complex(0, -1));
    assert(c2.get_conj() == 1);
    assert(c3.get_conj() == complex(3, 5));
    assert(c4.get_conj() == complex(4, -2.5));
    assert(c5.get_conj() == complex(-3.5, -1.1));

    std::cout << "Getters have been tested succesfully." << std::endl;
}

void test_assign()
{
    assert(+c1 == c1);
    assert(+c2 == c2);
    assert(+c3 == c3);
    assert(+c4 == c4);
    assert(+c5 == c5);

    assert(-c1 == complex(0, -1));
    assert(-c2 == -1);
    assert(-c3 == complex(-3, 5));
    assert(-c4 == complex(-4, -2.5));
    assert(-c5 == complex(3.5, -1.1));

    complex nc1 = c1, nc2 = c2, nc3 = c3, nc4 = c4, nc5 = c5;

    nc1 += c3;
    nc2 -= c4;
    nc3 *= c5;
    nc4 /= c1;
    nc5 *= c2;

    assert(nc1 == complex(3, -4));
    assert(nc2 == complex(-3, -2.5));
    assert(nc3 == complex(-5, 20.8));
    assert(nc4 == complex(2.5, -4));
    assert(nc5 == complex(-3.5, 1.1));

    nc5 += 2;
    nc4 -= 1.3;
    nc3 /= 20.8;
    nc2 *= -2.5;
    nc1 /= -2;

    assert(nc1 == complex(-1.5, 2));
    assert(nc2 == complex(7.5, 6.25));
    assert(nc3 == complex(-5 / 20.8, 1));
    assert(nc4 == complex(1.2, -4));
    assert(nc5 == complex(-1.5, 1.1));

    std::cout << "Both unary and arithmetic assignment operators have been tested succesfully." << std::endl;
}

void test_arithmetic()
{
    assert((c1 + c3) == complex(3, -4));
    assert((c2 - c4) == complex(-3, -2.5));
    assert((c3 * c5) == complex(-5, 20.8));
    assert((c4 / c1) == complex(2.5, -4));
    assert((c5 * c2) == complex(-3.5, 1.1));

    assert((c1 - 2.1) == complex(-2.1, 1));
    assert((c2 * -1.111) == -1.111);
    assert((c3 / 7) == complex(3 / 7., -5 / 7.));
    assert((c4 + 15.3) == complex(19.3, 2.5));
    assert((c5 / -2.5) == complex(1.4, 1.1 / -2.5));

    assert((3.7 * c1) == complex(0, 3.7));
    assert((11 / c2) == 11);
    assert((-0.5 + c3) == complex(2.5, -5));
    assert((1.8 - c4) == complex(-2.2, -2.5));
    assert((11.9 + c5) == complex(8.4, 1.1));

    std::cout << "Arithmetic operators have been tested succesfully." << std::endl;
}

void test_io()
{
    std::stringstream ss_c1, ss_c2, ss_c3, ss_c4, ss_c5;

    ss_c1 << c1; ss_c2 << c2; ss_c3 << c3; ss_c4 << c4; ss_c5 << c5;

    assert(ss_c1.str() == "i");
    assert(ss_c2.str() == "1");
    assert(ss_c3.str() == "3 - 5i");
    assert(ss_c4.str() == "4 + 2.5i");
    assert(ss_c5.str() == "-3.5 + 1.1i");

    std::cout << "Output have been tested succesfully." << std::endl;
}
