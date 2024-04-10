#include <iostream>

namespace convertTemperature{
    constexpr long double operator"" _Kelvin(long double kelvin) {
        return kelvin-273.15;
    }

    constexpr long double operator"" _Kelvin( unsigned long long kelvin) {
        return (long double)kelvin-273.15;
    }

    constexpr long double operator"" _Fahrenheit(long double fahrenheit) {
        return (fahrenheit-32)*5/9;
    }

    constexpr long double operator"" _Fahrenheit(unsigned long long fahrenheit) {
        return (long double) (fahrenheit-32)*5/9;
    }
}
int main() {
    using namespace convertTemperature;
    using namespace std;
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout<<a<<" "<<b;
    return 0;
}
