#include <iostream>
#include "NagyEgesz.cpp"

using namespace std;

int main()
{
    // Tesztadatok
    int szamjegyekA[20] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int szamjegyekB[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    // NagyEgesz objektumok létrehozása
    NagyEgesz a(1, 20, szamjegyekA);
    NagyEgesz b(-1, 20, szamjegyekB);

    // A NagyEgesz objektumok használata
    NagyEgesz c = a + b;
    NagyEgesz d = a - b;
    NagyEgesz e = a * b;
    NagyEgesz f = a / b;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << c << std::endl;
    std::cout << "a - b: " << d << std::endl;
    std::cout << "a * b: " << e << std::endl;
    std::cout << "a / b: " << f << std::endl;

    // A ++ és -- operátorok használata
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "b--: " << b-- << std::endl;
    std::cout << "--b: " << --b << std::endl;

    // Az += és -= operátorok használata
    a += b;
    std::cout << "a += b: " << a << std::endl;
    b -= a;
    std::cout << "b -= a: " << b << std::endl;

    // Az *= és /= operátorok használata
    a *= b;
    std::cout << "a *= b: " << a << std::endl;
    b /= a;
    std::cout << "b /= a: " << b << std::endl;

    return 0;
    return 0;
}