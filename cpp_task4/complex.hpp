#include <iostream>
using namespace std;
template<typename T>
class Complex{
    T real;
    T img;
public:
    Complex()
    {
        real=0;
        img=0;
    }
    Complex(T real, T img){
        this->real=real;
        this->img=img;
    }
    T get_real(){
        return real;
    }
    T get_img(){
        return img;
    }

    friend bool operator==(const Complex& first,const Complex& sec){
        if(first.real==sec.real && first.img==sec.img){
            return true;
        }
        return false;
    }
    friend bool operator!=(const Complex& first,const Complex& sec)
    {
        return !(first==sec);
    }

    friend ostream& operator<<(ostream& out, const Complex& complex) {
		out << complex.real << "+" <<complex.img<<"i";
		return out;
	}
};