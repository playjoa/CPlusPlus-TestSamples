#include <iostream>
using namespace std;

class NumberProcessor
{
    public:
        int GetSumOfNumbers(int countNumber)
        {
            int numbersSum = 0;
            for (size_t i = 0; i < countNumber + 1; i++)
            {
                numbersSum += i;
            }

            return numbersSum;    
        }
};

int GetSumOfNumbers(int countNumber)
{
    return countNumber;
}

int main() 
{
    NumberProcessor numberProcessor;

    cout << "--------------- Exercicio 1 - PUCRS ---------------" << endl;

    int desiredNumber;

    cout << "Input desired number:" << endl;
    cin >> desiredNumber;
    int sumOf100 = numberProcessor.GetSumOfNumbers(desiredNumber);
    cout << "Sum of "<< desiredNumber << " is " << sumOf100 << endl;

    return 0;
}