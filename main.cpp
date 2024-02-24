#include <iostream>
template<typename T1>
struct power{
    T1 Pow(T1 mantissa,int exponent){
        if(exponent==0){
            return 1;
        } else{
            return mantissa* Pow(mantissa,exponent-1);
        }
    }
};
int main() {
    //std::cout << "Hello, World!" << std::endl;
    power<double> value;
    std::cout<<"5^2= "<<value.Pow(2.2,2)<<"\n";
    return 0;
}
