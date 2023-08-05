// #include <iostream>
// #include <iterator>
// #include <map>
// #include <chrono>
// #include <vector>
// #include <unordered_set>
// #include <cmath>
// #include <utility>

// using namespace std;
// // https://www.educative.io/answers/how-to-solve-the-number-spiral-diagonals-problem
// // Function to solve the Project Euler problem
// // Modify this function based on the specific problem

// uint64_t solveProblem(int upperBound)
// {
//     uint64_t result = 0;
//     const int rows = upperBound;
//     const int cols = upperBound;

//     // int matrix[rows][cols];
//     int j = 0;
//     for (int i = 1; i < rows+1; i+=2){
//         // cout << j++ << ":" << 1+(i*(i+2)-i) << endl ; // bottom right direction
//         // cout << j++ << ":" << 1+(i*i-1) << endl ;     // top right direction
//         // cout << j++ << ":" << 1+(i*(i-1)) << endl ;      // top left direction
//         // cout << j++ << ":" << 1+(i*(i-2)+1) << endl ; // bottom left direction
//         result += 1+(i*(i+2)-i);
//         result += 1+(i*i-1);
//         result += 1+(i*(i-1));
//         result += 1+(i*(i-2)+1);
//     }
//     result -= 4 + 1;

//     return result;
// }

// int main()
// {
//     cout << "*******************************" << endl;
//     cout << "* Project Euler - Problem 28  *" << endl;
//     cout << "*        Answer:  669171001   *" << endl;
//     cout << "*******************************" << endl;

//     //Declare your variables 
//     int upperBound;
//     //Handle IO
//     cout << "Enter an upper bound: ";
//     cin >> upperBound;

//     // Call the solveProblem function
//     auto startTime = chrono::high_resolution_clock::now();
//     auto result = solveProblem(upperBound);
//     auto endTime = chrono::high_resolution_clock::now();

//     // Print the result
//     auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
//     cout << endl << "The answer is: " << result  << endl;
//     cout <<         "Execution time: " << duration << " milliseconds" << endl;

//     return 0;
// }


#include <iostream>
using namespace std;
// declare function sum
int sum(int dim)
{
  int n = (dim - 1) /2;//find n 
  // use the formula defined above
  int x = (3 + 2 * n * ( 8 * n * n + 15 * n +13)) /3;

  return x;
}
int main() {
  // call the function and print the value
  int diagonal = sum(1001);
  cout << diagonal << endl;
  return 0;
}
