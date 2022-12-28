#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Base{
    int trains;
    string type;
    string destination;
    int hours;
    int minutes;
    int typeOfTheTrain;
};

void setBase(Base* e, int size){
    int N;

    for(int i = 0; i != size; i++){
        cout << "Пункт призначення: ";
        cin >> e[i].destination;
        cout << "Тип поїзда: " << endl
                << "    1 - звичайний " << endl
                << "    2 - підвищеного комфорту" << endl
                << "    3 - швидкісний експрес" << endl;
        cout << "Введіть цифру: ";
        cin >> e[i].typeOfTheTrain;
        if(e[i].typeOfTheTrain == 1){
            e[i].type = "звичайний";
        } else if (e[i].typeOfTheTrain == 2){
            e[i].type = "підвищеного комфорту";
        } else if (e[i].typeOfTheTrain == 3){
            e[i].type = "швидкісний експрес";
        }
        cout << "Введіть годину відправлення: ";
        cin >> e[i].hours;
        cout << "Введіть хвилину відправлення: ";
        cin >> e[i].minutes;
    }
}

void showBase(Base* e, int size){
    cout << "------------------------------------------------------------------" << endl;
    cout << "| No | Пункт призначення |     Тип поїзда     | Час відправлення |" << endl;
    cout << "------------------------------------------------------------------" << endl;

    for(int i = 0; i != size; i++){
        cout << "| " << i + 1 << "  ";
        cout << "| " << e[i].destination << "          |" << e[i].type << "              |";
        cout << e[i].hours << ":" << e[i].minutes << "|" << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
}

void baseSortByDestination(Base* e, int size){
    Base temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(e[j].destination > e[j + 1].destination){
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

void baseSortByTime(Base* e, int size){
    Base temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(e[j].hours > e[j + 1].hours
            ||
            (e[j].hours == e[j + 1].hours) &&
            e[j].minutes > e[j + 1].minutes){
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

void trainsThatDepartAfterCertainTime(Base* e, int size){
    int neededHours, neededMinutes;
    cout << "Введіть годину: "; cin >> neededHours;
    cout << "Введіть хвилину: "; cin >> neededMinutes;

    cout << "------------------------------------------------------------------" << endl;
    cout << "| No | Пункт призначення |     Тип поїзда     | Час відправлення |" << endl;
    cout << "------------------------------------------------------------------" << endl;

    for(int i = 0; i != size; i++){
        if(e[i].hours > neededHours
        ||
        (e[i].hours == neededHours && e[i].minutes > neededMinutes)){
            cout << "| " << i + 1 << "  ";
            cout << "| " << e[i].destination << "          |" <<
                 setw(20) << e[i].type << "              |";
            cout << e[i].hours << ":" << e[i].minutes << "|" << endl;
        }
    }
    cout << "------------------------------------------------------------------" << endl;
}

int main() {
    int size;
    cout << "Введіть кількість поїздів: "; cin >> size;
    Base* base;
    base = new Base[size];

    int menuItem;
    do {
        cout << endl;
        cout << " [1] - ввід з клавіатури" << endl;
        cout << " [2] - вивід на екран" << endl;
        cout << " [3] - сортування за пунктом призначення" << endl;
        cout << " [4] - сортування за часом відправлення" << endl;
        cout << " [5] - вивід на екран інформації про поїзди, що відходять після заданого часу" << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl;

        switch (menuItem)
        {
            case 1:
                setBase(base, size);
                break;
            case 2:
                showBase(base, size);
                break;
            case 3:
                baseSortByDestination(base, size);
                break;
            case 4:
                baseSortByTime(base, size);
                break;
            case 5:
                trainsThatDepartAfterCertainTime(base, size);
                break;
            case 0:
                break;
        }
    } while (menuItem != 0);

    return 0;
}
