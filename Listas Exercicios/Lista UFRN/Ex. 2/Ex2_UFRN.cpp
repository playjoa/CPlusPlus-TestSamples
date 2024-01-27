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
};

int main()
{
    cout << "--------------- Exercicio 2 - UFRN ---------------" << endl;

    NumberProcessor numProcessor;
    int desiredNumber;

    cout << "Input desired number:" << endl;
    cin >> desiredNumber;

    list<int> divisorsList = numProcessor.GetNumberDivisors(desiredNumber);
    cout << "The divisors for number " << desiredNumber << " are: " << endl;

    for (const auto &divisorNum : divisorsList)
    {
        cout << "Number: " << divisorNum << endl;
    }

    return 0;
}