#include <iostream>
//#include <cmath>
#include <type_traits>

template<int exp,typename Enable=void>
struct power;

template<int exp>
struct power<exp, std::enable_if_t<(exp == 0)>> {
    template<typename T>
    static constexpr T Pow(T mantissa) {
        return 1;
    }
};

template<int exp>
struct power<exp, std::enable_if_t<(exp > 0)>> {
    template<typename T>
    static constexpr T Pow(T mantissa) {
        return mantissa * power<exp-1>::Pow(mantissa);
    }
};

template<int exp>
struct power<exp, std::enable_if_t<(exp < 0)>> {
    template<typename T>
    static constexpr T Pow(T mantissa) {
        return 1 / (mantissa * power<exp + 1>::Pow(mantissa));
    }
};




int main() {

    constexpr auto static mantissan=2;
    constexpr auto static exponenten=2;
    std::cout<<mantissan<<" upphöjt med "<<exponenten<<" ger "<<power<exponenten>::Pow(mantissan);

    return 0;
}
