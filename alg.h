#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

// A utility function that returns true if x is perfect square 
bool isPerfectSquare(int x) 
{ 
    int s = sqrt(x); 
    return (s*s == x); 
}

// Returns true if n is a Fibinacci Number, else false 
bool isFibonacci(int n) 
{ 
    // n is Fibinacci if one of 5*n*n + 4 or 5*n*n - 4 or both 
    // is a perferct square 
    return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4); 
} 

//First algorithm
template<typename T>
bool Fib(T b , T e){
    while (b != e){
        if(!isFibonacci(*b))
            return false;
        b++;
    }
    return true;
}
//Second algorithm
template<typename T>
T Transpose (T b, T e){
    if((e-b)%2 != 0)
        return b;

    while(b != e){
        auto temp = *b;
        *b = *(b+1);
        *(b+1) = temp;
        b = b+2;
    }
    return e;
}
//Third algorithm
template < typename T1 , typename T2>
T2 Transform2(T1 b , T1 e , T2 b2 , int f(int, int)){
    auto end = e;
    if((e-b)%2 != 0)
        end = (e-1);

    while(b != end){
        auto function = f(*b, *(b+1));
        *b2 = function;
        b2++;
        b = b+2;
    }
    return b2;
}
