#include <iostream>
#include <chrono>


/* I used the method described in this answer.
 * https://math.stackexchange.com/questions/46864/best-way-of-computing-the-decimal-representation-of-a-fraction-with-an-arbitrary
 * */

// Function to solve the Project Euler problem
// Modify this function based on the specific problem
std::string getDecimalRep(int d){
    int dividend = 10;
    std::string decimalDigits;
    std::unordered_map<int, int> remainderMap; //Maps each dividend to their remainder, if dividend repeats then we have a cycle.

    while (dividend != 0 && remainderMap.find(dividend)==remainderMap.end()){
        remainderMap[dividend] = decimalDigits.length(); //store the position of a particular remainder in the decimalDigits string
        int quotient = dividend / d;
        decimalDigits += std::to_string(quotient);
        dividend = 10 * (dividend - quotient*d); // or 10*(dividend % d) because it7s the same thing
    }

    // Return the result
    return decimalDigits;
}


int solveProblem(long MAX = 1000)
{
    int i , maxDecCycle = 1;
    int maxDecCycleInt ;
    int decCycleLength;
    std::string decimalCycle;
    for (i = 1; i < MAX; i++){
        decimalCycle = getDecimalRep(i);
        decCycleLength = decimalCycle.length();
        if (decCycleLength > maxDecCycle){
            maxDecCycle = decCycleLength;
            maxDecCycleInt = i;
        }
    }
    
    return maxDecCycleInt;
}

int main()
{
    std::cout << "*******************************" << std::endl;
    std::cout << "* Project Euler - Problem 26  *" << std::endl;
    std::cout << "*        Answer: 983          *" << std::endl;
    std::cout << "*******************************" << std::endl;

    //Declare your variables 

    //Handle IO
    // std::cout << "Enter an integer: ";
    // std::cin >> d;
    
    // Call the solveProblem function
    auto startTime = std::chrono::high_resolution_clock::now();
    auto result = solveProblem();
    auto endTime = std::chrono::high_resolution_clock::now();

    // Print the result
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout << "The answer is: " << result  << std::endl;
    std::cout << "Execution time: " << duration << " milliseconds" << std::endl;

    return 0;
}
