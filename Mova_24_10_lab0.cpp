// Mova_24_10_lab0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct Pipe {
    string name;
    float length;
    int diametr;
    bool status;
};

struct CS {
    string name;
    int number_work;
    int number_work_online;
    string class_cs;
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int inputPositiveInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cout << "Error! Please put polojitelnoe chislo: ";
            cin.clear();
            clearInputBuffer();
        }
        else {
            clearInputBuffer();
            return value;
        }
    }
}

float inputPositiveFloat(const string& prompt) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cout << "Error! Please put polojitelnoe chislo: ";
            cin.clear();
            clearInputBuffer();
        }
        else {
            clearInputBuffer();
            return value;
        }
    }
}

bool inputBool(const string& prompt) {
    string input;
    while (true) {
        cout << prompt << " (1 - yes, 0 - no): ";
        cin >> input;
        if (input == "1" || input == "да" || input == "yes") {
            clearInputBuffer();
            return true;
        }
        else if (input == "0" || input == "нет" || input == "no") {
            clearInputBuffer();
            return false;
        }
        else {
            cout << "Error! Put in 1 or 0: ";
            clearInputBuffer();
        }
    }
}

void ShowMenu(Pipe t, CS cs)
{
    int option;
    while (1) {
        cout << "\n Chooose options: \n1. Add pipe \n2. Add CS \n3. Show all objects \n4. Edit the pipe \n5. Edit the CS \n";
        cin >> option;
        switch (option) {
        case 1:
            cout << "Insert pipe name pls: ";
            cin >> t.name;
            break;
        case 2:
            cout << "Insert CS name pls: ";
            cin >> cs.name;
        case 3:
            cout << "\nPipe name: " << t.name;
            cout << "\n\tLength: " << t.length;
            cout << "\nCS name: " << cs.name;
            break;
        case 4:
            cout << "Insert pipe diametr pls:";
            cin >> t.diametr;
            cout << "Insert pipe length pls:";
            cin >> t.length;
            cout << "Insert pipe status pls:";
            cin >> t.status;
            break;
        case 5:
            break;
        }
    }
};


int main()
{
    cout << "Hello World!\n";
    Pipe truba;
    CS comp_station;
    ShowMenu(truba, comp_station);
    return 1;
}

//Ввод имени трубы с пробеломб отрицательные значения, нулевое значение в кол-ве цехов и др
//