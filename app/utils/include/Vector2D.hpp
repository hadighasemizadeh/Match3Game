#ifndef _VECTOR_2D_HPP_
#define _VECTOR_2D_HPP_

#include <iostream>
#include <math.h>

namespace Utils 
{
    template <typename T> struct Vector2D 
    {
        T c, r;
        
        Vector2D() : c(0), r(0){}

        Vector2D(const T c, const T r) : c(c), r(r){}

        Vector2D(const Vector2D& other) : c(other.c), r(other.r) {}

        Vector2D(Vector2D&& other) noexcept : c(std::move(other.c)), r(std::move(other.r)) {}

        ~Vector2D() {}

        bool operator==(const Vector2D& other)
        {
            return c == other.c && r == other.r;
        }

        bool operator!=(const Vector2D& other)
        {
            return !(*this == other);
        }

        Vector2D& operator=(const Vector2D& other)
        {
            if (*this != other)
            {
                c = other.c;
                r = other.r;
            }

            return *this;
        }

        Vector2D& operator=(Vector2D&& other) noexcept
        {
            if (*this != other)
            {
                c = std::move(other.c);
                r = std::move(other.r);
            }
            return *this;
        }

        explicit Vector2D(const T unit) : c(unit), r(unit){}

        template <typename T> friend float distance(const Vector2D<T>& A, const Vector2D<T>& B);

        template <typename T> friend Vector2D<T> operator+(Vector2D<T>& A, const Vector2D<T>& B);

        template <typename T> friend Vector2D<T>& operator+=(Vector2D<T>& A, const Vector2D<T>& B);

        template <typename T> friend Vector2D<T> operator-(Vector2D<T>& A, const Vector2D<T>& B);

        template <typename T> friend Vector2D<T>& operator-=(Vector2D<T>& A, const Vector2D<T>& B);

        template <typename T> friend Vector2D<T> operator*(Vector2D<T>& A, const T B);
        
        template <typename T> friend Vector2D<T>& operator*=(Vector2D<T>& A, const T B);

        template <typename T> friend Vector2D<T> operator*(Vector2D<T>& A, Vector2D<T>& B);

        template <typename T> friend Vector2D<T>& operator*=(Vector2D<T>& A, Vector2D<T>& B);

        template <typename T> friend bool operator==(const Vector2D<T>& A, const Vector2D<T>& B);

        template <typename T> friend bool operator!=(const Vector2D<T>& A, const Vector2D<T>& B);

        template <typename T> friend float magnitude(Vector2D<T> vec);

        template <typename T> friend Vector2D<T> normalize(Vector2D<T> vec);

        template <typename T> friend std::ostream& operator<<(std::ostream& os, Vector2D<T>& A);

        template <typename T> friend void swap(Vector2D<T>& A, Vector2D<T>& B);

    };

    template <typename T> float distance(const Vector2D<T>& A, const Vector2D<T>& B)
    {
        return sqrtf(((B.c - A.c) * (B.c - A.c)) + ((B.r - A.r) * (B.r - A.r)));
    }

    template <typename T> Vector2D<T> operator+(Vector2D<T>& A, const Vector2D<T>& B)
    {
        return Vector2D<T>(A.c + B.c, A.r + B.r);
    }

    template <typename T> Vector2D<T>& operator+=(Vector2D<T>& A, const Vector2D<T>& B)
    {
        A.c += B.c;
        A.r += B.r;
        return A;
    }

    template <typename T> Vector2D<T> operator-(Vector2D<T>& A, const Vector2D<T>& B)
    {
        return Vector2D<T>(A.c - B.c, A.r - B.r );
    }

    template <typename T> Vector2D<T>& operator-=(Vector2D<T>& A, const Vector2D<T>& B)
    {
        A.c -= B.c;
        A.r -= B.r;
        return A;
    }

    template <typename T> Vector2D<T> operator*(Vector2D<T>& A, const T B)
    {
        return Vector2D<T>(A.c * B, A.r * B);
    }
    
    template <typename T> Vector2D<T>& operator*=(Vector2D<T>& A, const T B)
    {
        A.c *= B;
        A.r *= B;
        return A;
    }

    template <typename T> Vector2D<T> operator*(Vector2D<T>& A, Vector2D<T>& B)
    {
        return Vector2D<T>(A.c * B.c, A.r * B.r);
    }

    template <typename T> Vector2D<T>& operator*=(Vector2D<T>& A, Vector2D<T>& B)
    {
        A.c *= B.c;
        A.r *= B.r;
        return A;
    }

    template <typename T> bool operator==(const Vector2D<T>& A, const Vector2D<T>& B)
    {
        return A.c == B.c && A.r == B.r;
    }

    template <typename T> bool operator!=(const Vector2D<T>& A, const Vector2D<T>& B)
    {
        return !(A == B);
    }

    template <typename T> float magnitude(Vector2D<T> vec)
    {
        return sqrtf(vec.c * vec.c + vec.r * vec.r);
    }

    template <typename T> Vector2D<T> normalize(Vector2D<T> vec)
    {
        float norm;
        norm = magnitude(vec);

        if (0.0f == norm)
            return Vector2D<T>( 0, 0 );

        vec *= (1.0f / norm);

        return vec;
    }

    template <typename T> std::ostream& operator<<(std::ostream& os, Vector2D<T>& A)
    {
        os << "[" << A.c << "," << A.r << "]\n";
        return os;
    }

    template <typename T> void swap(Vector2D<T>& A, Vector2D<T>& B)
    {
        std::swap(A.c, B.c);
        std::swap(A.r, B.r);
    }
}
#endif