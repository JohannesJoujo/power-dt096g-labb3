#include <iostream>
template<typename T>
struct power{
    T mantissa;
    power(T mantissa):mantissa(mantissa){}
    T Pow(int exponent){
        if(exponent==0){
            return 1;
        } else if(exponent >0){
            return mantissa* Pow(exponent-1);
        }else{
            return 1/mantissa* Pow(exponent+1);
        }
    }
};
int main() {
    power<double> value(2);
    std::cout<<"4^2= "<<value.Pow(2)<<"\n";
    return 0;
}