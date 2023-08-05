#include <iostream>
#include <iterator>
#include <map>
#include <chrono>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <utility>
/*
https://mathworld.wolfram.com/Prime-GeneratingPolynomial.html
*/


std::vector<uint64_t> generate(uint64_t N=1000) {
    std::vector<uint64_t> primes;
    std::vector<bool> isPrime(N+1,true); //flags for if i is prime
    isPrime[0] = isPrime[1] = false;
    uint64_t nsqrt = sqrt(N);
    for(uint64_t i=2;i<=nsqrt;i++){
        if(isPrime[i]){
            for(uint64_t j=i*i;j<=N;j+=i){
                isPrime[j] = false; // condition true only if number is not prime
            }
        }

    }
    for(uint64_t i=2;i<=N;i++){
        if(isPrime[i] == true)
            primes.push_back(i); // save i if i is prime
    }

    return primes;
}

// Function to solve the Project Euler problem
// Modify this function based on the specific problem

int64_t solveProblem(uint64_t upperBound)
{
    std::vector<uint64_t> primes = generate(upperBound);
    std::unordered_set<uint64_t> bField(primes.begin(), primes.end());
    std::vector<std::pair<uint64_t,uint64_t> > abField;

    for (uint64_t b : bField) {
        for(uint64_t a=0;a<upperBound;a++){
            if(bField.find(1+a+b)!=bField.end()){    
                abField.push_back(std::make_pair(a,b));
            }
        }
        for(uint64_t a=0;a<upperBound;a++){
            if(bField.find((uint64_t)std::abs((signed long long)(1-a+b))) != bField.end()){
                abField.push_back(std::make_pair(a,b));
            }
        }
    }

    uint64_t i = 0;
    uint64_t maxPrimeCount = 1;
    int64_t product = 0;
    for(const auto& ab : abField) {
        uint64_t a = ab.first;
        uint64_t b = ab.second;
        //Check for when a is positive
        while (bField.find(i*i + a*i + b) != bField.end())
        {
            i++;
        }
        if(i>maxPrimeCount){
            maxPrimeCount = i;
            product = (int64_t) a * b;
        }
        i = 0;

        //Check for when a is negative
        while (bField.find(i*i - a*i + b) != bField.end())
        {
            i++;
        }
        if(i>maxPrimeCount){
            maxPrimeCount = i;
            product = (int64_t) -a * b;
        }
    }


    std::cout << std::endl;

    return product;
}

int main()
{
    std::cout << "*******************************" << std::endl;
    std::cout << "* Project Euler - Problem 27  *" << std::endl;
    std::cout << "*        Answer: -59231       *" << std::endl;
    std::cout << "*******************************" << std::endl;

    //Declare your variables 
    uint64_t upperBound;
    //Handle IO
    std::cout << "Enter an upper bound: ";
    std::cin >> upperBound;
    
    // Call the solveProblem function
    auto startTime = std::chrono::high_resolution_clock::now();
    auto result = solveProblem(upperBound);
    auto endTime = std::chrono::high_resolution_clock::now();

    // Print the result
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout << "The answer is: " << result  << std::endl;
    std::cout << "Execution time: " << duration << " milliseconds" << std::endl;

    return 0;
}
