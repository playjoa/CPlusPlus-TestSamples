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

    bool TryGetFirstSquareNumberBiggerThen(int desiredNumber, int &validNumber)
    {
        int numbersSum = 1;

        for (size_t i = 1; i < desiredNumber; i++)
        {
            if (i * i > desiredNumber)
            {
                validNumber = static_cast<int>(i);
                return true;
            }
        }

        return false;
    }
};

int main()
{
    cout << "--------------- Exercicio 4 - UFRN ---------------" << endl;

    NumberProcessor numProcessor;
    int desiredNumber;
    int result;

    cout << "Input desired number:" << endl;
    cin >> desiredNumber;

    if (numProcessor.TryGetFirstSquareNumberBiggerThen(desiredNumber, result))
    {
        cout << "Smaller Number With Bigger Square: " << result << " Square: " << result * result << endl;
    }
    else
    {
        cout << "No value found for desired number: " << desiredNumber << endl;
    }

    return 0;
}