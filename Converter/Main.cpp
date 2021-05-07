#include <iostream> 
#include <cstdio>

using namespace std;

void decimalToBinary(int number);
void binaryToDecimal(int number);
int takeAndCheckIfCorrect();
char repeatConvertion();
bool checkIfBinary(int number);

int main()
{
    int selectedOption = 0;
    int number = 0;
    char answer = 0;

    do {
        cout << "Select option:\n1) Convert decimal to binary\n2) Convert binary to decimal\n";
        cout << "Type your option: ";
        selectedOption = takeAndCheckIfCorrect();

        if (selectedOption == 1)
        {
            cout << "Type your number to conversion: ";
            number = takeAndCheckIfCorrect();
            decimalToBinary(number);
            answer = repeatConvertion();
        }
        else if (selectedOption == 2)
        {
            cout << "Type your number to conversion: ";
            number = takeAndCheckIfCorrect();
            if (checkIfBinary(number)) {
                binaryToDecimal(number);
            }
            else {
                cout << "It is not a binary value.\n";
            }

            answer = repeatConvertion();
        }
        else {
            cout << "You put wrong answer. Choose between 1 and 2.\n";
            answer = repeatConvertion();
        }
    } while (answer == 'Y' || answer == 'y');

    cout << "You didn't choose to continue. Program is closing.";
    return 0;
}

void decimalToBinary(int number) {

    int binaryNum[32];
    int i = 0;
    while (number > 0)
    {
        binaryNum[i] = number % 2;
        number = number / 2;
        i++;
    }

    cout << "\nYour converted number is: ";

    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];

    cout << "\n";

}

void binaryToDecimal(int number)
{
    int decimalValue = 0;
    int binaryBase = 1;
    int temp = number;

    while (temp) {
        int lastDigit = temp % 10;
        temp = temp / 10;

        decimalValue += lastDigit * binaryBase;

        binaryBase = binaryBase * 2;
    }

    cout << "\nYour converted number is: " << decimalValue << "\n";

}

int takeAndCheckIfCorrect() {

    int selectedOption = 0;

    cin >> selectedOption;
    while (1) {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered wrong data type. Try again.\n"; // z³y typ
            cin >> selectedOption;
        }
        else {
            return selectedOption;
        }
    }
}

char repeatConvertion() {

    char answer = 0;

    cout << "Do you want make another conversion? Press 'Y' to restart program and try again.\n";
    cin >> answer;
    cin.clear(); cin.sync();

    return answer;
}

bool checkIfBinary(int number) {

    while (number) {
        if ((number % 10) > 1)
            return false;
        number /= 10;
    }
    return true;

}
