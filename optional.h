//
// Created by yaroslav on 10/20/18.
//

#ifndef OPTIONAL_OPTIONAL_H
#define OPTIONAL_OPTIONAL_H

#include <iostream>
#include <type_traits>
#include <string>
#include <cassert>

template<class T>
struct optional {
    optional() = default;

    optional(T const &val) {
        is_big = true;
        new(reinterpret_cast<T *>(&data_)) T(val);
    }

    optional(optional const &other) : is_big(other.is_big) {
        if (is_big) {
            new(reinterpret_cast<T *>(&data_)) T(*other);
        }
    }

    optional &operator=(optional const &other) {
        optional tmp = other;
        swap(tmp);
        return *this;
    }

    ~optional() {
        clear();
    }

    explicit operator bool() const {
        return is_big;
    }

    void clear() {
        if (is_big) {
            reinterpret_cast<T *>(&data_)->~T();
            is_big = false;
        }
    }

    void swap(optional &other) {
        if (is_big && other.is_big) {
            std::swap(*reinterpret_cast<T *>(&data_), *reinterpret_cast<T *>(&other.data_));
            std::swap(is_big, other.is_big);
        }
        else if (is_big){
            new(reinterpret_cast<T *>(&other.data_)) T(*(*this));
            this->clear();
            other.is_big = 1;
        }
        else if (other.is_big){
            new(reinterpret_cast<T *>(&data_)) T(*other);
            other.clear();
            is_big = 1;
        }
    }


    T &operator*() {
        assert(is_big);
        return *reinterpret_cast<T *>(&data_);
    }

    T const &operator* () const{
        assert(is_big);
        return *reinterpret_cast<T const *>(&data_);
    }

    T *operator->() {
        assert(is_big);
        return (reinterpret_cast<T *>(&data_));
    }

    T const *operator->() const{
        assert(is_big);
        return (reinterpret_cast<T const *>(&data_));
    }

private:
    typename std::aligned_storage<sizeof(T), alignof(T)>::type data_;
    bool is_big = false;

};

template<typename T>
void swap(optional<T> &a, optional<T> &b) {
    a.swap(b);
}
template <typename T, typename U>
bool operator==(optional<T> &a, optional<U> &b)
{
    if (!a && !b)
        return true;
    if (a && b)
        return reinterpret_cast<T&>(*a) == reinterpret_cast<U&>(*b);
    return false;
}

template <typename T, typename U>
bool operator!=(optional<T> &a, optional<U> &b)
{
    return !(a == b);
}

template <typename T, typename U>
bool operator<(optional<T> &a, optional<U> &b) {
    if (!a && !b)
        return false;
    if (a && b)
        return reinterpret_cast<T&>(*a) < reinterpret_cast<U&>(*b);
    if (!a)
        return true;
    return false;
}

template <typename T, typename U>
bool operator>(optional<T> &a, optional<U> &b) {
    return b < a;
}

template <typename T, typename U>
bool operator>=(optional<T> &a, optional<U> &b) {
    return !(a < b);
}

template <typename T, typename U>
bool operator<=(optional<T> &a, optional<U> &b) {
    return !(b < a);
}



#endif //OPTIONAL_OPTIONAL_H
