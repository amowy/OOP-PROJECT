#ifndef _NagyEgesz_H_
#define _NagyEgesz_H_

#include <iostream>

class NagyEgesz
{
    int elojel, hossz;
    int* szamjegyek;
    NagyEgesz osszead(const NagyEgesz &) const;
    NagyEgesz kivon(const NagyEgesz &) const;
    NagyEgesz osszefuz(const NagyEgesz &) const;
    NagyEgesz osszefuz_hatul(const NagyEgesz &) const;
    NagyEgesz& squash();
    NagyEgesz neg() const;
public:
    NagyEgesz();
    NagyEgesz(int, int, const int*);
    NagyEgesz(const NagyEgesz &);
    NagyEgesz(int);
    NagyEgesz(long);
    ~NagyEgesz();
    friend std::ostream &operator<<(std::ostream &, const NagyEgesz &);
    bool operator>(const NagyEgesz) const;
    NagyEgesz operator+(const NagyEgesz&) const;
    NagyEgesz operator-(const NagyEgesz&) const;
    NagyEgesz operator*(const NagyEgesz&) const;
    NagyEgesz operator/(const NagyEgesz&) const;
    NagyEgesz& operator=(const NagyEgesz&);
    NagyEgesz& operator+=(const NagyEgesz&);
    NagyEgesz &operator-=(const NagyEgesz &);
    NagyEgesz &operator*=(const NagyEgesz &);
    NagyEgesz &operator/=(const NagyEgesz &);
    NagyEgesz& operator++();
    NagyEgesz operator++(int);
    NagyEgesz &operator--();
    NagyEgesz operator--(int);
    class NullavalValoOsztas{};

};

#endif