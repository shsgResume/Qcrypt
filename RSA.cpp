#include <stdio.h>
#include <vector>
#include <iostream>
#include <random>
#include <math.h>
#include <string>
#include <boost/math/common_factor.hpp> 

//#include "RSA.h"

// key generators
vector<int> keyGen(void){

    vector<int> keys;

    //choose two large primes
    primes = primeGen();

    //compute the modulus
    signed long modulus = primes[0]*primes[1];

    //compute the totient function, change the totient function if needed
    signed long lambda_n = Carmi_tot(primes[0],primes[1]);
    
    //get the encryption integer
    std::random_device num;
    std::mt19937 rng(num());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,lambda_n);
    signed long e = __gcd(dist6(rng), lambda_n);
    keys.push_back(e);

    //get the decryption integer
    signed long d = pow(e, -1) % lambda_n;
    keys.push_back(d);

    return keys;
}

// prime generators
vector<signed long> primeGen(void){
    
    vector<signed long> primes(2);

    //uses the std::random_device as an example
    std::random_device num;
    std::mt19937 rng(num());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,4508649259272);

    // check if the random number is a prime using the Miller-Rabin test
    // an even number is a trivial non-prime case
    for (int i=0; i<primes.size();i++){
        signed long test = dist6(rng);

        //change primality test below if needed
        while(test%2==0 || MR_test(test)==0){ //while the number isnt prime, dont take it in
            signed long test = dist6(rng);
        }
        primes.push_back(test);
    }
    return primes;

}

//Miller-Rabin primality test
bool MR_test(signed long prime, int k){ 

    bool result;
    int i = 1; // i is the exponent in n-1 = 2^k *m

    while (i <= k){
        if (isdigit((prime-1)/pow(2,k)) == 0 ){ 
            //need to check if this gives half values or not first
            break;
        }
        i++;
    }
    int m;

    // gets a random a
    std::random_device num;
    std::mt19937 rng(num());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,prime-1);
    int a = dist6(rng);

    //computes the first check
    signed long b0 = pow(a,m) % prime;

    if (b0==1 || b0==-1){
        result = 1;
    }
    else{
        //iterate over the b's until either 1 or -1
    }
    //include for if infinite loop

    return result;
}

//Carmichael totient function
signed long Carmi_tot(signed long p, signed long q){
    return boost::math::lcm(p-1,q-1);
}

int main(void){

    std::string message;

    //ask for message to send
    std::cout << "What is the message?" << std::endl;
    std::cin >> message;

    vector<int> keys = keyGen();

    //decrypt the message

    
    return 0;
}

//get a bat or sh for easier running