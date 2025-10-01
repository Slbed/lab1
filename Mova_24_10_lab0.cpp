// Mova_24_10_lab0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
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

void inputPipe(Pipe& t) {
    cout << "=== Enter data Pipe ===\n";

    cout << "Pipe name: ";
    clearInputBuffer();
    getline(cin, t.name);

    t.length = inputPositiveFloat("Enter the length of the pipe (km): ");
    t.diametr = inputPositiveInt("Enter the pipe diameter (mm): ");
    t.status = inputBool("Is the pipe under repair?");

    cout << "The pipe has been added successfully!\n";
}

void showPipe(const Pipe& t) {
    cout << "\n=== Inf about Pipe ===\n";
    cout << "Pipe name: " << t.name << endl;
    cout << "Length: " << t.length << " km" << endl;
    cout << "Diametr: " << t.diametr << " mm" << endl;
    cout << "Under repair?: " << (t.status ? "Yes" : "No") << endl;
}

void editPipe(Pipe& t) {
    if (t.name.empty()) {
        cout << "Add the pipe first!\n";
        return;
    }

    cout << "\n=== Edit Pipe ===\n";
    cout << "Status: " << (t.status ? "Under repair" : "Work") << endl;
    t.status = inputBool("Change status?");
    cout << "Repair status update!\n";
}

void inputCS(CS& cs) {
    cout << "=== Enter data about CS ===\n";

    cout << "CS name: ";
    clearInputBuffer();
    getline(cin, cs.name);

    cs.number_work = inputPositiveInt("Enter the total number of workshops: ");

    while (true) {
        cs.number_work_online = inputPositiveInt("Enter the number of workshops online: ");
        if (cs.number_work_online <= cs.number_work) {
            break;
        }
        cout << "Error! Online workshops >>> total workshops. "
            << cs.number_work << ")\n";
    }

    cout << "Class of CS station: ";
    clearInputBuffer();
    getline(cin, cs.class_cs);

    cout << "CS added successfully!\n";
}

void showCS(const CS& cs) {
    cout << "\n=== Inf about CS ===\n";
    cout << "Name: " << cs.name << endl;
    cout << "Total workshops: " << cs.number_work << endl;
    cout << "Online workshops: " << cs.number_work_online << endl;
    cout << "Class station: " << cs.class_cs << endl;
}

void editCS(CS& cs) {
    if (cs.name.empty()) {
        cout << "First add the CS!\n";
        return;
    }

    cout << "\n=== Edit CS ===\n";
    cout << "Online workshops: " << cs.number_work_online << " of " << cs.number_work << " total\n";
    cout << "1 - Run workshop\n";
    cout << "2 - Stop workshop цех\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        if (cs.number_work_online < cs.number_work) {
            cs.number_work_online++;
            cout << "Workshop online! Online: " << cs.number_work_online << endl;
        }
        else {
            cout << "Error! All workshops online.\n";
        }
    }
    else if (choice == 2) {
        if (cs.number_work_online > 0) {
            cs.number_work_online--;
            cout << "Workshop stoped! Online: " << cs.number_work_online << endl;
        }
        else {
            cout << "Error! All workshops offline.\n";
        }
    }
    else {
        cout << "Wrong choice!\n";
    }
    clearInputBuffer();
}

void saveToFile(const Pipe& t, const CS& cs) {
    ofstream file("data.txt");
    if (!file.is_open()) {
        cout << "Wrong open file!\n";
        return;
    }

    file << "PIPE\n";
    file << t.name << "\n";
    file << t.length << "\n";
    file << t.diametr << "\n";
    file << t.status << "\n";

    file << "CS\n";
    file << cs.name << "\n";
    file << cs.number_work << "\n";
    file << cs.number_work_online << "\n";
    file << cs.class_cs << "\n";

    file.close();
    cout << "Data successfully saved!\n";
}

void loadFromFile(Pipe& t, CS& cs) {
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Wrong reading!\n";
        return;
    }

    string marker;

    file >> marker;
    if (marker == "PIPE") {
        clearInputBuffer();
        getline(file, t.name);
        file >> t.length;
        file >> t.diametr;
        file >> t.status;
    }

    file >> marker;
    if (marker == "CS") {
        clearInputBuffer();
        getline(file, cs.name);
        file >> cs.number_work;
        file >> cs.number_work_online;
        clearInputBuffer();
        getline(file, cs.class_cs);
    }

    file.close();
    cout << "Data successfully loaded!\n";
}

void ShowMenu(Pipe& t, CS& cs) {
    int option;
    while (true) {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Add Pipe\n";
        cout << "2. Add CS\n";
        cout << "3. View all objects\n";
        cout << "4. Edit Pipe\n";
        cout << "5. Edit CS\n";
        cout << "6. Save\n";
        cout << "7. Load\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";

        cin >> option;

        if (cin.fail()) {
            cout << "Error! Enter integer from 0 to 7.\n";
            cin.clear();
            clearInputBuffer();
            continue;
        }

        switch (option) {
        case 1:
            inputPipe(t);
            break;
        case 2:
            inputCS(cs);
            break;
        case 3:
            showPipe(t);
            showCS(cs);
            break;
        case 4:
            editPipe(t);
            break;
        case 5:
            editCS(cs);
            break;
        case 6:
            saveToFile(t, cs);
            break;
        case 7:
            loadFromFile(t, cs);
            break;
        case 0:
            cout << "Exit from programm.\n";
            return;
        default:
            cout << "Wrong choice! Try again.\n";
            break;
        }
    }
}


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