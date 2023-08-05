#include <iostream>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <chrono>
#include <map>
#include <set>
#include <vector>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <utility>

#define ld long double
using namespace std;
// Function to solve the Project Euler problem
// Modify this function based on the specific problem

ld  opr(uint64_t i, uint64_t j){
    return (ld)pow(i,j);
}

uint64_t solveProblem(uint64_t upperBound)
{
    uint64_t result = 0;
    set<ld> powers;
    for (uint64_t i = 2; i <= upperBound; ++i) {
        for (uint64_t j = 2; j <= upperBound; ++j) {
            powers.insert(opr(i,j));
        }
    }
    result = powers.size();
    return result;
}

int main()
{
    cout << "*******************************" << endl;
    cout << "* Project Euler - Problem 29  *" << endl;
    cout << "*        Answer:     9183     *" << endl;
    cout << "*******************************" << endl;

    //Declare your variables 
    uint64_t upperBound;
    //Handle IO
    cout << "Enter an upper bound: ";
    cin >> upperBound;

    // Call the solveProblem function
    auto startTime = chrono::high_resolution_clock::now();
    auto result = solveProblem(upperBound);
    auto endTime = chrono::high_resolution_clock::now();

    // Print the result
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
    cout << "The answer is: " << result  << endl;
    cout << "Execution time: " << duration << " milliseconds" << endl;

    return 0;
}
