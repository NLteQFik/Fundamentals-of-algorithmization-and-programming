#include "functions.h"

void addition() {
    std::cout << "Введите количество квитанций, которое вы хотите добавить:\n";
    
    int plus = posIntegerInput();
    tech = (radio*)realloc(tech, (n + plus) * sizeof(radio));
    std::string s;

    for (int i = n; i < n + plus; i++) {
        std::cout << "Введите информацию о квитанции " << i + 1 << " :\n" << '\n';

        std::cout << "Наименование группы изделий:\n";
        s = nameInput();
        strcpy(tech[i].name, s.c_str());

        std::cout << "Марка изделия:\n";
        s = nameInput();
        strcpy(tech[i].mark, s.c_str());

        std::cout << "Дата поступления в ремонт:\n";
        s = dateInput();
        strcpy(tech[i].date, s.c_str());

        std::cout << "Состояние готовности заказа (Выполнен / Не выполнен):\n";
        s = statInput();
        strcpy(tech[i].state, s.c_str());

        if (choice) {
            std::cout << "Введите цену:\n";
            tech[i].details.price = posFloatInput();
        }
        else {
            std::cout << "Введите вес:\n";
            tech[i].details.price = posFloatInput();
        }

        std::cout << '\n';
    }
    n += plus;

    std::cout << '\n';

    writeWorkFile();
}

void change() {

    if (n == 0) {
        std::cout << "\nИзменение невозможно! Нет квитанций\n\n";
        return;
    }

    std::cout << "Выберите признак:\n";
    std::cout << "1. Наименование группы изделий\n";
    std::cout << "2. Марка изделия\n";
    std::cout << "3. Дата поступления в ремонт\n";
    std::cout << "4. Состояние готовности заказа\n";
    if (choice) {
        std::cout << "5. Цена\n";
    }
    else {
        std::cout << "5. Вес\n";
    }

    int type;
    while (true) {
        type = posIntegerInput();

        std::cout << '\n';

        if (type > 5) {
            std::cout << "Неверный формат ввода!";
            continue;
        }
        break;
    }

    std::cout << "Введите информацию о признаке:\n" << '\n';

    std::string name, mark, date, state, new_name, new_mark, new_date, new_state;
    int weight, new_weight;
    float price, new_price;
    int counter = 0;

    switch (type) {
        case 1:
            std::cout << "Наименование группы изделий:\n";
            name = nameInput();
            std::cout << "\nВведите новое наименование:\n";
            new_name = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(name.c_str(), tech[i].name) == 0) {
                    strcpy(tech[i].name, new_name.c_str());
                    rewriteFile(type, i);
                    counter++;
                }
            }
            break;

        case 2:
            std::cout << "Марка изделия:\n";
            mark = nameInput();
            std::cout << "Введите новое марку:\n";
            new_mark = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(mark.c_str(), tech[i].mark) == 0) {
                    strcpy(tech[i].mark, new_mark.c_str());
                    rewriteFile(type, i);
                    counter++;
                }                   
            }
            break;
        case 3:
            std::cout << "Дата поступления в ремонт:\n";
            date = dateInput();
            std::cout << "Введите новое дату:\n";
            new_date = dateInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(date.c_str(), tech[i].date) == 0) {
                    strcpy(tech[i].date, new_date.c_str());
                    rewriteFile(type, i);
                    counter++;
                }                   
            }
            break;
        case 4:
            std::cout << "Cостояние готовности заказа:\n";
            state = statInput();
            std::cout << "Введите новое состояние:\n";
            new_state = statInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(state.c_str(), tech[i].state) == 0) {
                    strcpy(tech[i].state, new_state.c_str());
                    rewriteFile(type, i);
                    counter++;
                }                   
            }
            break;
        case 5:
            if (choice) {
                std::cout << "Цена:\n";
                price = posFloatInput();
                std::cout << "Новая цена:\n";
                new_price = posFloatInput();

                for (int i = 0; i < n; i++) {
                    if (price == tech[i].details.price) {
                        tech[i].details.price = price;
                        rewriteFile(type, i);
                        counter++;
                    }
                }
                break;
            }
            else {
                std::cout << "Вес:\n";
                weight = posIntegerInput();
                std::cout << "Вес:\n";
                new_weight = posIntegerInput();

                for (int i = 0; i < n; i++) {
                    if (weight == tech[i].details.weight) {
                        tech[i].details.weight = weight;
                        rewriteFile(type, i);
                        counter++;
                    }
                }
                break;
            }
            
    }
     
    if (counter) {
        std::cout << '\n' << "Характеристики квитанций изменены\n" << '\n';
        writeWorkFile();
    }
    else {
        std::cout << '\n' << "Квитанций не найдено\n" << '\n';
    }
}

void input() {
    n = 0;
    free(tech);
    tech = NULL;

    std::cout << "Введите количество квитанций:\n";

    n = posIntegerInput();
    tech = (radio*)malloc(n * sizeof(radio));
    std::string s;

    std::cout << '\n';

    for (int i = 0; i < n; i++) {
        std::cout << "Введите информацию о квитанции " << i + 1 << " :\n" << '\n';

        std::cout << "Наименование группы изделий:\n";
        s = nameInput();
        strcpy(tech[i].name, s.c_str());

        std::cout << "Марка изделия:\n";
        s = nameInput();
        strcpy(tech[i].mark, s.c_str());

        std::cout << "Дата поступления в ремонт:\n";
        s = dateInput();
        strcpy(tech[i].date, s.c_str());

        std::cout << "Состояние готовности заказа (Выполнен / Не выполнен):\n";
        s = statInput();
        strcpy(tech[i].state, s.c_str());

        if (choice) {
            std::cout << "Введите цену:\n";
            tech[i].details.price = posFloatInput();
        }
        else {
            std::cout << "Введите вес:\n";
            tech[i].details.price = posFloatInput();
        }

        std::cout << '\n';
    }

    std::cout << '\n';

    writeWorkFile();
}

int posIntegerInput() {
    int n;
    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (std::cin.peek() != '\n') {
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (n <= 0) {
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        break;
    }
    return n;
}

long long posLongLongInput() {
    long long n;
    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (std::cin.peek() != '\n') {
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (n <= 0) {
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        break;
    }
    return n;
}

float posFloatInput() {
    float n;
    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (std::cin.peek() != '\n') {
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (n <= 0) {
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        break;
    }
    return n;
}

double posDoubleInput() {
    double n;
    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (std::cin.peek() != '\n') {
            std::cin.ignore(100000, '\n');
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (n <= 0) {
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        break;
    }
    return n;
}

std::string dateInput() {
    std::string s;
    while (true) {
        bool b = 0;
        char c;
        while (true) {
            c = getchar();

            if (c == '\n' && b == 0) {
                continue;
                b = 1;
            }
            if (c == '\n') {
                break;
            }

            s += c;
            b = 1;
        }
        b = 0;

        if (s.size() != DATE_SIZE - 1) {
            std::cout << "Неверный формат ввода!\n";
            continue; 
        }
        if (s[2] != '.' || s[5] != '.') {
            std::cout << "Неверный формат ввода!\n";
            continue;
        }
        for (int i = 0; i < 8; i++) {
            if (i == 2 || i == 5) {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                continue;
            }
            else {
                b = 1; 
                break;
            }
        }

        int n = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        if (n == 0) {
            b = 1;
        }
        if (m > 12 || m == 0) {
            b = 1;
        }

        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            if (n > 31) {
                b = 1;
            }
        }
        else if (m == 2) {
            if (n > 28) { //29 февраля склад не работает - традиция
                b = 1;
            }
        }
        else {
            if (n > 30) {
                b = 1;
            }
        }

        if (b) {
            std::cout << "Неверный формат ввода!\n";
            continue;
        }
        break;
    }
    s += '\0';
    return s;
}

std::string nameInput() {
    std::string s;

    while (true) {
        bool b = 0;
        char c;
        while (true) {
            c = getchar();

            if (c == '\n' && b == 0) {
                continue;
                b = 1;
            }
            if (c == '\n') {
                break;
            }

            s += c;
            b = 1;
        }
        b = 0;

        if (s.size() >= NAME_SIZE - 1) {
            std::cout << "Неверный формат ввода!\n";
            continue;
        }
        break;
    }

    while (s.size() != NAME_SIZE) {
        s += '\0';
    }

    return s;
}

std::string statInput() {
    std::string s;

    while (true) {
        bool b = 0;
        char c;
        while (true) {
            c = getchar();

            if (c == '\n' && b == 0) {
                continue;
                b = 1;
            }
            if (c == '\n') {
                break;
            }

            s += c;
            b = 1;
        }
        b = 0;

        if (s.size() >= STAT_SIZE - 1) {
            std::cout << "Неверный формат ввода!\n";
            continue;
        }
        if (s != "Выполнен" && s != "Не выполнен") {
            std::cout << "Неверный формат ввода!\n";
            continue;
        }
        break;
    }

    while (s.size() != STAT_SIZE) {
        s += '\0';
    }

    return s;
}

void option() {
    std::cout << "\nВыберите тип шестого поля:\n";
    std::cout << "1. Цена\n";
    std::cout << "2. Вес\n";

    bool b;
    int sel;

    while (true) {
        sel = posIntegerInput();
        b = 0;

        std::cout << '\n';

        switch (sel) {
            case 1:
                choice = 1;
                rewriteFile(0, 0);
                for (int i = 0; i < n; i++) {
                    std::cout << "\nИзделие " << i + 1;
                    std::cout << "\nВведите цену:\n";
                    tech[i].details.price = posFloatInput();
                    rewriteFile(6, i);
                }
                break;
            case 2:
                choice = 0;
                rewriteFile(0, 0);
                for (int i = 0; i < n; i++) {
                    std::cout << "\nИзделие " << i + 1;
                    std::cout << "\nВведите вес:\n";
                    tech[i].details.weight = posIntegerInput();
                    rewriteFile(6, i);
                } 
                break;
            default:
                std::cout << "Неверный формат ввода!\n";
                b = 1;
        }
        if (b) {
            continue;
        }
        break;
    }

    writeWorkFile();
}

void output() {
    for (int i = 0; i < n; i++) {
        std::cout << '\n' << "Информация о квитанции " << i + 1 << " :\n";
        std::cout << "Наименование группы изделий:\n" << tech[i].name << '\n';
        std::cout << "Марка изделия:\n" << tech[i].mark << '\n';
        std::cout << "Дата поступления в ремонт:\n" << tech[i].date << '\n';
        std::cout << "Состояние готовности заказа:\n" << tech[i].state << '\n';
        if (choice) {
            std::cout << "Цена:\n" << tech[i].details.price;
        }
        else {
            std::cout << "Вес:\n" << tech[i].details.weight;
        }
        std::cout << '\n';
    }

    if (n == 0) {
        std::cout << '\n' << "Информации о квитанциях нет\n" << '\n';
    }

    std::cout << '\n';
}

void sortOutput() {
    sort();

    if (n == 0) {
        std::cout << "\nСортировка невозможна! Нет изделий\n\n";
        return;
    }

    std::cout << "\nИнформация о состоянии заказов по группам изделий\n\n";

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            std::cout << "\nНаименование группы изделий:\n" << tech[i].name << '\n';
        }
        else if (strcmp(tech[i].name, tech[i - 1].name) != 0){
            std::cout << "\nНаименование группы изделий:\n" << tech[i].name << '\n';
        }
        std::cout << '\n' << "Информация о квитанции " << i + 1 << " :\n";
        std::cout << "Марка изделия:\n" << tech[i].mark << '\n';
        std::cout << "Дата поступления в ремонт:\n" << tech[i].date << '\n';
        std::cout << "Состояние готовности заказа:\n" << tech[i].state << '\n';
        if (choice) {
            std::cout << "Цена:\n" << tech[i].details.price;
        }
        else {
            std::cout << "Вес:\n" << tech[i].details.weight;
        }
        std::cout << '\n';
    }

}

void removal() {

    if (n == 0) {
        std::cout << "\nУдаление невозможно! Нет квитанций\n\n";
        return;
    }

    std::cout << "Выберите признак:\n";
    std::cout << "1. Наименование группы изделий\n";
    std::cout << "2. Марка изделия\n";
    std::cout << "3. Дата поступления в ремонт\n";
    std::cout << "4. Состояние готовности заказа\n";
    if (choice) {
        std::cout << "5. Цена\n";
    }
    else {
        std::cout << "5. Вес\n";
    }

    int type;
    while (true) {
        type = posIntegerInput();

        std::cout << '\n';

        if (type > 5) {
            std::cout << "Неверный формат ввода!";
            continue;
        }
        break;
    }

    std::cout << "Введите информацию о признаке:\n" << '\n';

    std::string name, mark, date, state;
    int weight;
    float price;
    int counter = 0;
    short *wrong = new short[n]{0};

    switch (type) {
        case 1:
            std::cout << "Наименование группы изделий:\n";
            name = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(name.c_str(), tech[i].name) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 2:
            std::cout << "Марка изделия:\n";
            mark = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(mark.c_str(), tech[i].mark) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 3:
            std::cout << "Дата поступления в ремонт:\n";
            date = dateInput();

            for (int i = 0; i < n; i++) {
                    if (strcmp(date.c_str(), tech[i].date) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 4:
            std::cout << "Состояние готовности заказа:\n";
            state = statInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(state.c_str(), tech[i].state) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 5:
            if (choice) {
                std::cout << "5. Цена:\n";
                price = posFloatInput();

                for (int i = 0; i < n; i++) {
                    if (tech[i].details.price == price) {
                        wrong[i] = 1;
                        counter++;
                    }
                }
                break;                
            }
            else {
                std::cout << "5. Вес:\n";
                weight = posIntegerInput();

                for (int i = 0; i < n; i++) {
                    if (tech[i].details.weight == weight) {
                        wrong[i] = 1;
                        counter++;
                    }
                }
                break;                
            }                
    }

    if (counter == 0) {
        std::cout << '\n' << "Квитанций не найдено\n" << '\n';
        delete[] wrong; 
        return;
    }

    int j = 0;

    for (int i = 0; i < n; i++) {
        if (!wrong[i]) {
            tech[j] = tech[i];
            j++;
        }
    }

    n -= counter;
    tech = (radio*)realloc(tech, n * sizeof(radio));
    delete[] wrong; 

    std::cout << '\n' << "Квитанции удалены\n" << '\n';

    writeWorkFile();
}

void sort() {
    for (int i = 0; i < n; i++) {
        radio key = tech[i];
        int j = i - 1;
        while (j >= 0 && strcmp(tech[j].name, key.name) < 0) {
            tech[j + 1] = tech[j];
            j--;
        }
        tech[j + 1] = key;
    }
}

void writeWorkFile() {
    std::ofstream file;
    file.open("work.txt", std::ios::out);

    int size;
    file << n << '\n';
    file << choice << '\n';

    for (int i = 0; i < n; i++) {
        file << tech[i].name << '\n'; 
        file << tech[i].mark << '\n';
        file << tech[i].date << '\n';
        file << tech[i].state << '\n';
        if (choice) {
            file << tech[i].details.price << '\n';
        }
        else {
            file << tech[i].details.weight << '\n';
        }
    }

    file.close();
}

void readWorkFile() {
    std::ifstream file;
    file.open("work.txt", std::ios::in);

    std::string s;
    file >> n;
    tech = (radio*)malloc(n * sizeof(radio));
    file >> choice;

    for (int i = 0; i < n; i++) {
        file >> tech[i].name;
        file >> tech[i].mark;
        file >> tech[i].date;
        file >> tech[i].state;
        if (choice) {
            file >> tech[i].details.price;
        }
        else {
            file >> tech[i].details.weight;
        }
    }

    file.close();
}

void rewriteFile(int type, int i) {
}

void writeFinalFile() {
    std::ofstream file;
    file.open("text.txt", std::ios::out);

    for (int i = 0; i < n; i++) {
        file << "Содержание квитанции " << i + 1 << '\n';
        file << "Наименование группы изделий: " << tech[i].name << '\n'; 
        file << "Марка изделия: " << tech[i].mark << '\n';
        file << "Дата поступления в ремонт: " << tech[i].date << '\n';
        file << "Состояние готовности заказа: " << tech[i].state << '\n';
        if (choice) {
            file << "Цена: " << tech[i].details.price << '\n';
        }
        else {
            file << "Вес: " << tech[i].details.weight << '\n';
        }
        file << '\n';
    }
    file.close();
}

void view() {
    std::cout << '\n' << "Вид структуры:\n";
    std::cout << "1. Наименование группы изделий:\n"; 
    std::cout << "2. Марка изделия:\n";
    std::cout << "3. Дата поступления в ремонт:\n";
    std::cout << "4. Состояние готовности:\n";
    std::cout << "5. Цена / вес изделия. Сейчас ";
    if (choice) {
        std::cout << "цена\n"; 
    }
    else {
        std::cout << "вес\n";
    }
    std::cout << '\n';
}