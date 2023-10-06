#include "c_class.h"

complex::complex (double re_, double im_): re(re_), im(im_) {}

complex complex::operator + (const complex& c) const
{
    complex r = *this; r += c; return r;
}
complex complex::operator - (const complex& c) const
{
    complex r = *this; r -= c; return r;
}

complex complex::operator * (double d) const
{
    complex r = *this; r *= d; return r;
}
complex operator * (double d, const complex& c)
{
    return complex (d * c.re, d * c.im);
}
complex complex::operator / (double d) const
{
    complex r = *this; r /= d; return r;
}

std::ostream& operator << (std::ostream& stream, const complex& c)
{
    if (c.im == 0) return (stream << c.re);
    if (c.re == 0)
    {
        if (c.im == -1) return (stream << "-i");
        if (c.im == 1) return (stream << "i");
        return (stream << c.im << "i");
    }
    if (c.im < 0)
    {
        if (c.im == -1) return (stream << c.re << " - " << "i");
        return (stream << c.re << " - " << -c.im << "i");
    }
    if (c.im == 1) return (stream << c.re << " + " << "i");
    return (stream << c.re << " + " << c.im << "i");
}
std::istream& operator >> (std::istream& stream, complex& c)
{
    return (stream >> c.re >> c.im);
}

complex complex::operator * (const complex& c) const
{
    complex r = *this; r *= c; return r;
}

complex complex::operator / (const complex& c) const
{
    complex r = *this; r /= c; return r;
}

complex operator / (double d, const complex& c)
{
    complex r; r.re = d; r /= c; return r;
}

complex operator + (double d, const complex& c)
{
    return c + d;
}

complex operator - (double d, const complex& c)
{
    return -c + d;
}

bool operator == (double d, const complex& c)
{
    return (c == d);
}

bool operator != (double d, const complex& c)
{
    return (c != d);
}

