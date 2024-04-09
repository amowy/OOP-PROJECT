#include "NagyEgesz.h"

NagyEgesz NagyEgesz::osszead(const NagyEgesz &other) const
{
    int maxlen = std::max(hossz, other.hossz);
    int szj[maxlen];
    int i = hossz - 1, j = other.hossz - 1, k = maxlen - 1, carry = 0, curr_szamjegy;
    while (i >= 0 && j >= 0)
    {
        curr_szamjegy = szamjegyek[i] + other.szamjegyek[j] + carry;
        if(curr_szamjegy > 9)
        {
            curr_szamjegy -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        szj[k] = curr_szamjegy;
        i--;
        j--;
        k--;
    }
    while( i>= 0)
    {
        if(szamjegyek[i] + carry > 9)
        {
            carry = 1;
            szj[i] = 0;
        }
        else
        {
            szj[i] = szamjegyek[i] + carry;
            carry = 0;
        }
        i--;
    }
    while (j >= 0)
    {
        if (other.szamjegyek[j] + carry > 9)
        {
            carry = 1;
            szj[j] = 0;
        }
        else
        {
            szj[j] = other.szamjegyek[j] + carry;
            carry = 0;
        }
        j--;
    }
    NagyEgesz ans(elojel,maxlen,szj);
    if(carry)
    {
        return ans.osszefuz(1);
    }
    return ans;
}

NagyEgesz NagyEgesz::kivon(const NagyEgesz &other) const
{
    NagyEgesz seged(other);
    if(seged > *this)
    {
        return seged.kivon(*this);
    }
    int maxlen = std::max(hossz, other.hossz);
    int carry = 0, i = hossz - 1, j = other.hossz-1, k = maxlen - 1, curr_szamjegy;
    int szj[maxlen];
    while (i >= 0 && j >= 0)
    {
        curr_szamjegy = szamjegyek[i] - other.szamjegyek[j] - carry;
        if (curr_szamjegy < 0)
        {
            szj[k] = curr_szamjegy + 10;
            carry = 1;
        }
        else
        {
            szj[k] = curr_szamjegy;
            carry = 0;
        }
        i--;
        j--;
        k--;
    }
    while (i >= 0)
    {
        if (szamjegyek[i] - carry < 0)
        {
            carry = 1;
            szj[i] = 9;
        }
        else
        {
            szj[i] = szamjegyek[i] - carry;
            carry = 0;
        }
        i--;
    }
    while (j >= 0)
    {
        if (other.szamjegyek[j] - carry < 0)
        {
            carry = 1;
            szj[j] = 9;
        }
        else
        {
            szj[j] = other.szamjegyek[j] - carry;
            carry = 0;
        }
        j--;
    }
    NagyEgesz ans(elojel,maxlen,szj);
    return ans.squash();
}

NagyEgesz NagyEgesz::osszefuz(const NagyEgesz& other) const
{
    NagyEgesz res;
    res.hossz = hossz + other.hossz;
    res.szamjegyek = new int[res.hossz];
    res.elojel = elojel;
    int k = 0;
    for (int j = 0; j < other.hossz; j++)
    {
        res.szamjegyek[k] = other.szamjegyek[j];
        k++;
    }
    for(int i = 0; i < hossz; i++)
    {
        res.szamjegyek[k] = szamjegyek[i];
        k++;
    }
    return res.squash();
}

NagyEgesz NagyEgesz::osszefuz_hatul(const NagyEgesz &other) const
{
    NagyEgesz res;
    res.hossz = hossz + other.hossz;
    res.szamjegyek = new int[res.hossz];
    res.elojel = elojel;
    int k = 0;
    for (int i = 0; i < hossz; i++)
    {
        res.szamjegyek[k] = szamjegyek[i];
        k++;
    }
    for (int j = 0; j < other.hossz; j++)
    {
        res.szamjegyek[k] = other.szamjegyek[j];
        k++;
    }
    return res.squash();
}

NagyEgesz& NagyEgesz::squash()
{
    if( hossz == 1)
        return *this;
    int i = 0, newlen = hossz;
    while (i < hossz - 1 && szamjegyek[i] == 0)
    {
        i++;
        newlen--;
    }
    if (newlen < hossz)
    {
        int ujszj[newlen];
        int j = 0;
        while(i < hossz)
        {
            ujszj[j] = szamjegyek[i];
            i++;
            j++;
        }
        delete[] szamjegyek;
        szamjegyek = new int[newlen];
        hossz = newlen;
        for(int i = 0; i < hossz; i++)
        {
            szamjegyek[i] = ujszj[i];
        }
        if(hossz == 1 && szamjegyek[0] == 0)
        {
            elojel = 0;
        }
    }
    return *this;
}

NagyEgesz NagyEgesz::neg() const
{
    NagyEgesz ans(*this);
    ans.elojel *= -1; 
    return ans;
}

NagyEgesz::NagyEgesz()
{
    elojel = 0;
    hossz = 1;
    szamjegyek = new int[1];
    szamjegyek[0] = 0;
}

NagyEgesz::NagyEgesz(int elojel, int hossz, const int *szamjegyek)
{
    this->elojel = elojel;
    this->hossz = hossz;
    this->szamjegyek = new int[hossz];
    for (int i = 0; i < hossz; i++)
    {
        this->szamjegyek[i] = szamjegyek[i];
    }
}

NagyEgesz::NagyEgesz(const NagyEgesz &other)
{
    elojel = other.elojel;
    hossz = other.hossz;
    szamjegyek = new int[hossz];
    for(int i = 0; i < hossz; i++)
    {
        szamjegyek[i] = other.szamjegyek[i];
    }
}

NagyEgesz::NagyEgesz(int szam)
{
    if(szam == 0)
    {
        elojel = 0;
        hossz = 1;
        szamjegyek = new int[1];
        szamjegyek[0] = 0;
    }
    else
    {
        if(szam > 0)
        {
            elojel = 1;
        }
        else
        {
            elojel = -1;
            szam *= -1;
        }
        hossz = 0;
        int seged = szam;
        while (seged)
        {
            hossz++;
            seged /= 10;
        }
        szamjegyek = new int[hossz];
        for (int i = hossz - 1; i >= 0; i--)
        {
            szamjegyek[i] = szam % 10;
            szam /= 10;
        }
    }
}

NagyEgesz::NagyEgesz(long szam)
{
    if (szam == 0)
    {
        NagyEgesz();
    }
    else
    {
        if (szam > 0)
        {
            elojel = 1;
        }
        else
        {
            elojel = -1;
            szam *= -1;
        }
        hossz = 0;
        int seged = szam;
        while (seged)
        {
            hossz++;
            seged /= 10;
        }
        szamjegyek = new int[hossz];
        for (int i = hossz - 1; i >= 0; i--)
        {
            szamjegyek[i] = szam % 10;
            szam /= 10;
        }
    }
}

NagyEgesz::~NagyEgesz()
{
    delete[] szamjegyek;
}

std::ostream& operator<<(std::ostream &os, const NagyEgesz& a)
{
    if(a.elojel == 0)
    {
        os << "0";
        return os;
    }
    if (a.elojel == -1)
    {
        os << "-";
    }
    for(int i = 0; i < a.hossz; i++)
    {
        os << a.szamjegyek[i];
    }
    return os;
}

bool NagyEgesz::operator>(const NagyEgesz other) const
{
    if(hossz > other.hossz)
        return true;
    if(hossz < other.hossz)
        return false;
    int i = 0;
    while(i < hossz && szamjegyek[i] == other.szamjegyek[i])
    {
        i++;
    }
    if( i == hossz)
        return false;
    return szamjegyek[i] > other.szamjegyek[i];
}


NagyEgesz NagyEgesz::operator+(const NagyEgesz & other) const
{
    if (elojel == other.elojel)
    {
        NagyEgesz ans(osszead(other));
        return ans;
    }
    else
    {
        NagyEgesz ans(kivon(other));
        return ans;
    }
}

NagyEgesz NagyEgesz::operator-(const NagyEgesz &other) const
{
    if(elojel != other.elojel)
    {
        NagyEgesz ans(osszead(other.neg()));
        return ans;
    }
    else
    {
        NagyEgesz ans(kivon(other.neg()));
        return ans;
    }
}

NagyEgesz NagyEgesz::operator*(const NagyEgesz & other) const
{
    if( elojel == 0 or other.elojel == 0)
    {
        return NagyEgesz();
    }
    NagyEgesz ans;
    ans.elojel = elojel * other.elojel;
    ans.hossz = hossz + other.hossz;
    ans.szamjegyek = new int[ans.hossz];
    int carry = 0, curr_szamjegy, k = ans.hossz - 1;
    for(int i = 0; i <= k; i++)
    {
        ans.szamjegyek[i] = 0;
    }
    for(int i = hossz - 1; i >= 0; i--)
    {
        carry = 0;
        for(int j = other.hossz - 1; j >= 0; j--)
        {
            curr_szamjegy = ans.szamjegyek[k] + szamjegyek[i] * other.szamjegyek[j] + carry;
            ans.szamjegyek[k] = curr_szamjegy % 10;
            carry = curr_szamjegy / 10;
            k--;
        }
        ans.szamjegyek[k] += carry;
        k--;
        k+=other.hossz;// j visszaadasa
    }
    return ans.squash();
}

NagyEgesz NagyEgesz::operator/(const NagyEgesz& other) const
{
    if(other.elojel == 0)
    {
        throw NullavalValoOsztas();
    }
    NagyEgesz temp(szamjegyek[0]), seged(other), oszto;
    if(elojel == 0 or seged > *this)
    {
        return NagyEgesz();
    }
    NagyEgesz ans;
    ans.elojel = elojel * other.elojel;
    ans.hossz = 1;
    ans.szamjegyek = new int[1];
    ans.szamjegyek[0] = 0;
    int i = 1;
    while(i < hossz)
    {
        while(i < hossz && seged > temp)
        {
            temp = temp.osszefuz_hatul(szamjegyek[i]);
            i++;
        }
        while( temp > oszto*seged)
        {
            oszto = oszto + 1;
        }
        oszto = oszto - 1;
        ans = ans.osszefuz_hatul(oszto);
        temp = temp - (oszto * seged);
        oszto = 0;
    }
    return ans.squash();
}

NagyEgesz& NagyEgesz::operator=(const NagyEgesz &other)
{
    delete[] szamjegyek;
    hossz = other.hossz;
    elojel = other.elojel;
    szamjegyek = new int[hossz];
    for(int i = 0; i < hossz; i++)
    {
        szamjegyek[i] = other.szamjegyek[i];
    }
    return *this;
}

NagyEgesz& NagyEgesz::operator+=(const NagyEgesz &other)
{
    *this = *this + other;
    return *this;
}

NagyEgesz &NagyEgesz::operator-=(const NagyEgesz &other)
{
    *this = *this - other;
    return *this;
}

NagyEgesz &NagyEgesz::operator*=(const NagyEgesz &other)
{
    *this = *this * other;
    return *this;
}

NagyEgesz &NagyEgesz::operator/=(const NagyEgesz &other)
{
    *this = *this / other;
    return *this;
}

NagyEgesz &NagyEgesz::operator++()
{
    *this += 1;
    return *this;
}

NagyEgesz NagyEgesz::operator++(int)
{
    NagyEgesz temp(*this);
    *this += 1;
    return temp;
}

NagyEgesz &NagyEgesz::operator--()
{
    *this -= 1;
    return *this;
}

NagyEgesz NagyEgesz::operator--(int)
{
    NagyEgesz temp(*this);
    *this -= 1;
    return temp;
}