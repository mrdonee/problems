//ints A and B are the first two integers in a Fibbonacci sequence in which arr[x] = arr[x - 1] + arr[x - 2]
//int P is an integer used as a modulo in the problem stated below
//Note: 0 <= A < P && 0 <= B < P && P > 0

//Given the first two integers A and B in a sequence in which all numbers are moduloed by P, print the repeating subsequence
//Example 1:
//A = 0, B = 1, P = 4
//Sequence (prior to applying P as the modulo):       0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ....
//Sequence (after applying modulo P, 4 in this case): 0, 1, 1, 2, 3, 1, 0,  1,  1,  2,  3,  1,   0, ....
//Repeating subsequence: 0, 1, 1, 2, 3, 1

//Example 2:
//A = 2, B = 1, P = 3
//Sequence (prior to applying P as the modulo):       2, 1, 3, 4, 7, 11, 18, 29, 47, 76, 123, 199, 322, ....
//Sequence (after applying modulo P, 4 in this case): 2, 1, 0, 1, 1,  2,  0,  2,  2,  1,   0,   1,   1 ....
//Repeating subsequence: 2, 1, 0, 1, 1, 2, 0, 2

#include <vector>
#include <iostream>
using namespace std;

//Time Complexity: O(n) where n is the length of the subsequence
//Space Complexity: O(n) where n is the length of the subsequence
void pisanoPeriod(int A, int B, int P) {
    if (A >= P || A < 0 || B >= P || B < 0 || P <= 0) {
        cout << "Check your bounds" << endl;
        return;
    }
    vector<int> sequence = {A};
    int newA = B, newB = (A + B) % P;
    
    //when two subsequent numbers in the sequence reappear as the original A and B values the sequence will repeat
    while (newA != A || newB != B) {
        sequence.push_back(newA);
        newA = newB;
        newB = (newA + sequence[sequence.size() - 1]) % P;
    }
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] <<  " ";
    }
    cout << endl;
}

int main() {
    pisanoPeriod(0, 0, 1); // 0
    pisanoPeriod(1, 1, 4); // 1 1 2 3 1 0
    pisanoPeriod(2, 1, 3); // 2 1 0 1 1 2 0 2
    pisanoPeriod(2, 2, 3); // 2 2 1 0 1 1 2 0
}
