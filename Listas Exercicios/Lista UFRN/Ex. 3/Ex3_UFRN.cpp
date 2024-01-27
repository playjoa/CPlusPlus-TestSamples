#include <iostream>
#include <list>

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

    list<int> GetNumberDivisors(int targetNumber)
    {
        list<int> targetNumberDivisors{};

        for (int i = 1; i <= targetNumber; i++)
        {
            if (targetNumber % i == 0)
            {
                targetNumberDivisors.push_back(i);
            }
        }

        return targetNumberDivisors;
    }

    int GetFactorialNumber(int desiredNumber)
    {
        int numbersSum = 1;
        for (size_t i = 1; i < desiredNumber + 1; i++)
        {
            numbersSum *= i;
        }

        return numbersSum;
    }
};

int main()
{
    cout << "--------------- Exercicio 3 - UFRN ---------------" << endl;

    NumberProcessor numProcessor;
    int desiredNumber;

    cout << "Input desired number:" << endl;
    cin >> desiredNumber;

    int factorialNumber = numProcessor.GetFactorialNumber(desiredNumber);

    cout << "Factorial Number: " << factorialNumber << endl;

    return 0;
}