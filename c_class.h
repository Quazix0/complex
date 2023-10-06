#ifndef C_CLASS_H_INCLUDED
#define C_CLASS_H_INCLUDED

#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <cmath>

class complex
{
public:
    /// Конструктор
    complex (double re_ = 0, double im_ = 0);

    /// Геттеры
    double get_re() const {return re; }
    double get_im() const {return im; }

    ///Модуль и комплексно-сопряжённое
    double get_abs() const {return sqrt(re * re + im * im); }
    complex get_conj() const {return complex(re, -im); }

    /// Операторы арифметического присваивания
    complex& operator += (const complex& c) {re += c.re; im += c.im; return *this; }
    complex& operator -= (const complex& c) {re -= c.re; im -= c.im; return *this; }
    complex& operator *= (double d) {re *= d; im *= d; return *this; }
    complex& operator /= (double d) {re /= d; im /= d; return *this; }

    complex& operator *= (const complex& c)
    {
        complex r;
        r.re = re * c.re - im * c.im;
        r.im = re * c.im + im * c.re;

        re = r.re;
        im = r.im;

        return *this;
    }

    complex& operator /= (const complex& c)
    {
        double d = c.re *c.re + c.im * c.im;
        complex r = *this, z = c.get_conj();

        r *= z; r /= d;
        re = r.re; im = r.im;

        return *this;
    }

    /// Операторы равенства и неравенства
    bool operator == (const complex& c) const {return re == c.re && im == c.im;}
    friend bool operator == (double d, const complex& c);

    bool operator != (const complex& c) const {return !(*this == c);}
    friend bool operator != (double d, const complex& c);

    /// Операторы сложения и вычитания
    complex operator + (const complex& c) const;
    friend complex operator + (double d, const complex& c);
    complex operator - (const complex& c) const;
    friend complex operator - (double d, const complex& c);

    /// Унарные плюс и минус
    const complex& operator + () const {return *this; }
    complex operator - () const {return complex (-re, -im); }

    /// Операторы умножения
    complex operator * (double d) const;
    friend complex operator * (double d, const complex& c);
    complex operator * (const complex& c) const;

    /// Операторы деления
    complex operator / (double d) const;
    friend complex operator / (double d, const complex& c);
    complex operator / (const complex& c) const;

    /// Операторы ввода и вывода
    friend std::ostream& operator << (std::ostream& stream, const complex& c);
    friend std::istream& operator >> (std::istream& stream, complex& c);

private:
    double re, im;
};

#endif // C_CLASS_H_INCLUDED
