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

    list<int> GetMultiplicationTable(int targetNumber)
    {
        list<int> multiplicationTable{};
        
        for (int i = 1; i <= 10; i++)
        {
            multiplicationTable.push_back(i * targetNumber);
        }

        return multiplicationTable;
    }
};

void PrintNumberList(string logPrefix, list<int> desiredList)
{
    for (const auto &listMember : desiredList)
    {
        cout << logPrefix << listMember << endl;
    }
}

int main()
{
    cout << "--------------- Exercicio 5 - UFRN ---------------" << endl;

    NumberProcessor numProcessor;
    int desiredNumber;

    cout << "Input your desired number to calculate Multiplication Table:" << endl;
    cin >> desiredNumber;

    list<int> desiredNumberMultTable = numProcessor.GetMultiplicationTable(desiredNumber);

    PrintNumberList("Multiplication Table: ", desiredNumberMultTable);

    return 0;
}