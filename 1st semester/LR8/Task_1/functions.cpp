#include "functions.h"

void addition() {
    std::cout << "Введите количество товаров, которое вы хотите добавить:\n";
    
    int plus = posIntegerInput();
    goods = (product*)realloc(goods, (n + plus) * sizeof(product));
    std::string s;

    for (int i = 0; i < plus; i++) {
        std::cout << '\n' << "Введите информацию о товаре " << n + i + 1 << " :\n" << '\n';

        std::cout << "Наименование товара:\n";
        s = nameInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n + i].name[j] = s[j];
        }

        std::cout << "Количество единиц товара:\n";
        goods[n + i].quantity = posIntegerInput();

        std::cout << "Цена единицы:\n";
        goods[n + i].price = posFloatInput();

        std::cout << "Вес единицы:\n";
        goods[n + i].weight = posIntegerInput();

        std::cout << "Дата поступления:\n";
        s = dateInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n].date[j] = s[j];
        }

        if (choice) {
            goods[n + i].details.cost = goods[n + i].quantity * goods[n + i].price;
        }
        else {
            goods[n + i].details.mass = goods[n + i].quantity * goods[n + i].weight;
        }

        n++;
    }

    std::cout << '\n';

    writeFile();
}

void writeFile() {
    std::ofstream file;
    file.open("save.bin", std::ios::out | std::ios::binary);

    int size;
    file.write((char*)&n, sizeof(n));
    file.write((char*)&choice, sizeof(choice));

    for (int i = 0; i < n; i++) {
        size = NAME_SIZE;
        file.write(&goods[i].name[0], size * sizeof(goods[i].name[0]));

        file.write((char*)&goods[i].quantity, sizeof(goods[i].quantity));

        file.write((char*)&goods[i].price, sizeof(goods[i].price));

        file.write((char*)&goods[i].weight, sizeof(goods[i].weight));

        size = DATE_SIZE;
        file.write(&goods[i].date[0], size * sizeof(goods[i].date[0]));

        file.write((char*)&goods[i].details, sizeof(goods[i].details));
    }

    file.close();
}

void readFile() {
    std::ifstream file;
    file.open("save.bin", std::ios::in | std::ios::binary);

    size_t size;
    file.read((char*)&n, sizeof(n));
    file.read((char*)&choice, sizeof(choice));
    goods = (product*)malloc(n * sizeof(product));

    for (int i = 0; i < n; i++) {
        size = NAME_SIZE;
        file.read(&goods[i].name[0], size * sizeof(goods[i].name[0]));

        file.read((char*)&goods[i].quantity, sizeof(goods[i].quantity));

        file.read((char*)&goods[i].price, sizeof(goods[i].price));

        file.read((char*)&goods[i].weight, sizeof(goods[i].weight));

        size = DATE_SIZE;      
        file.read(&goods[i].date[0], size * sizeof(goods[i].date[0]));

        file.read((char*)&goods[i].details, sizeof(goods[i].details));
    }

    file.close();
}

void rewriteFile(int type, int i) {
    std::fstream file;
    file.open("save.bin", std::ios::in | std::ios::out | std::ios::binary);

    int size;
    int position = sizeof(n) + sizeof(choice) + i * (sizeof(product) - 8); //спасибо char и float за 8 лишних байтов
    
    position += 0;
    size = NAME_SIZE;

    if (type == 0) {
        file.seekp(sizeof(n));
        file.write((char*)&choice,sizeof(choice));
    }

    if (type == 1) {
        file.seekp(position);
        file.write(&goods[i].name[0], size * sizeof(goods[i].name[0]));
    }

    position += size * sizeof(goods[i].name[0]);

    if (type == 2) {
        file.seekp(position);
        file.write((char*)&goods[i].quantity, sizeof(goods[i].quantity));
    }

    position += sizeof(goods[i].quantity);

    if (type == 3) {
        file.seekp(position);
        file.write((char*)&goods[i].price, sizeof(goods[i].price));
    }

    position += sizeof(goods[i].price);

    if (type == 4) {
        file.seekp(position);
        file.write((char*)&goods[i].weight, sizeof(goods[i].weight));
    }

    position += sizeof(goods[i].weight);
    size = DATE_SIZE;

    if (type == 5) {
        file.seekp(position);
        file.write(&goods[i].date[0], size * sizeof(goods[i].date[0]));
    }

    position += size * sizeof(goods[i].date[0]);

    if (type == 6) {
        file.seekp(position);
        file.write((char*)&goods[i].details, sizeof(goods[i].details));
    }

    file.close();
}

void change() {

    if (n == 0) {
        std::cout << "\nИзменение невозможно! Нет товаров\n\n";
        return;
    }

    std::cout << "Выберите признак:\n";
    std::cout << "1. Наименование товара\n";
    std::cout << "2. Количество единиц товара\n";
    std::cout << "3. Цена единицы\n";
    std::cout << "4. Вес единицы\n";
    std::cout << "5. Дата поступления\n";

    int type;
    while (true) {
        type = posIntegerInput();

        std::cout << '\n';

        if (type > 6) {
            std::cout << "Неверный формат ввода!";
            continue;
        }
        break;
    }

    std::cout << "Введите информацию о признаке:\n" << '\n';

    std::string name, date, new_name, new_date;
    int quantity, weight, new_quantity, new_weight;
    float price, new_price;
    long long mass, new_mass;
    double cost, new_cost;
    int counter = 0;

    switch (type) {
        case 1:
            std::cout << "Наименование товара:\n";
            name = nameInput();
            std::cout << "\nВведите новое наименование:\n";
            new_name = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(name.c_str(), goods[i].name) == 0) {
                    strcpy(goods[i].name, new_name.c_str());
                    rewriteFile(type, i);
                    counter++;
                }
            }
            break;

        case 2:
            std::cout << "Количество единиц товара:\n";
            quantity = posIntegerInput();
            std::cout << "Введите новое количество:\n";
            new_quantity = posIntegerInput();

            for (int i = 0; i < n; i++) {
                if (goods[i].quantity == quantity) {
                    goods[i].quantity = new_quantity;
                    rewriteFile(type, i);
                    counter++;                    

                    if (choice) {
                        goods[i].details.cost = goods[i].quantity * goods[i].price;
                        rewriteFile(6, i);
                    }                
                    else {
                        goods[i].details.mass = goods[i].quantity * goods[i].weight;
                        rewriteFile(6, i);               
                    }
                }
            }
            break;
        case 3:
            std::cout << "Цена единицы:\n";
            price = posFloatInput();
            std::cout << "Новая цена:\n";
            new_price = posFloatInput();

            for (int i = 0; i < n; i++) {
                if (goods[i].price == price) {
                    goods[i].price = new_price;
                    rewriteFile(type, i);
                    counter++;

                    if (choice) {
                        goods[i].details.cost = goods[i].quantity * goods[i].price;
                        rewriteFile(6, i);
                    }    
                }
            }
            break;
        case 4:
            std::cout << "Вес единицы:\n";
            weight = posIntegerInput();
            std::cout << "Новый вес:\n";
            new_weight = posIntegerInput();
            
            for (int i = 0; i < n; i++) {
                if (goods[i].weight == weight) {
                    goods[i].weight = new_weight;
                    rewriteFile(type, i);
                    counter++;

                    if (!choice) {
                        goods[i].details.mass = goods[i].quantity * goods[i].weight;
                        rewriteFile(6, i);
                    }    
                }
            }
            break;
        case 5:
            std::cout << "Дата поступления:\n";
            date = dateInput();
            std::cout << "Новая дата поступления:\n";
            new_date = dateInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(date.c_str(), goods[i].date) == 0) {
                    strcpy(goods[i].date, new_date.c_str());
                    rewriteFile(type, i);
                    counter++;
                }
            }
            break;
    }
     
    if (counter) {
        std::cout << '\n' << "Характеристики товаров изменены\n" << '\n';
    }
    else {
        std::cout << '\n' << "Товаров не найдено\n" << '\n';
    }
}

void input() {
    std::cout << "Режимы ввода:\n";
    std::cout << "1. Ввод заранее заданного количества товаров\n";
    std::cout << "2. Ввод до появления заданного признака\n";
    std::cout << "3. Ввод с диалогом о необходимости продолжать ввод\n";
    std::cout << "Выберите режим ввода:\n";

    n = 0;
    free(goods);
    goods = NULL;

    int type;
    bool b;
    while (true) {
        b = 0;
        type = posIntegerInput();

        std::cout << '\n';

        switch (type) {
            case 1:
                firstInput();
                break;
            case 2:
                secondInput();
                break;
            case 3:
                thirdInput();
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
}

void firstInput() {
    std::cout << "Введите количество товаров:\n";

    n = posIntegerInput();
    goods = (product*)malloc(n * sizeof(product));
    std::string s;

    std::cout << '\n';

    for (int i = 0; i < n; i++) {
        std::cout << "Введите информацию о товаре " << i + 1 << " :\n" << '\n';

        std::cout << "Наименование товара:\n";
        s = nameInput();
        for (int j = 0; j < NAME_SIZE; j++) {
            goods[i].name[j] = s[j];
        }

        std::cout << "Количество единиц товара:\n";
        goods[i].quantity = posIntegerInput();

        std::cout << "Цена единицы:\n";
        goods[i].price = posFloatInput();

        std::cout << "Вес единицы:\n";
        goods[i].weight = posIntegerInput();

        std::cout << "Дата поступления:\n";
        s = dateInput();
        for (int j = 0; j < DATE_SIZE; j++) {
            goods[i].date[j] = s[j];
        }

        if (choice) {
            goods[i].details.cost = goods[i].quantity * goods[i].price;
        }
        else {
            goods[i].details.mass = goods[i].quantity * goods[i].weight;
        }

        std::cout << '\n';
    }

    std::cout << '\n';

    writeFile();
}

void secondInput() { 
    std::cout << "Выберите признак:\n";
    std::cout << "1. Наименование товара\n";
    std::cout << "2. Количество единиц товара\n";
    std::cout << "3. Цена единицы\n";
    std::cout << "4. Вес единицы\n";
    std::cout << "5. Дата поступления\n";

    std::string name, date;
    int quantity, weight;
    float price;

    int type;
    bool b;
    while (true) {
        b = 0;
        std::cout << '\n';
        type = posIntegerInput();
        switch (type) {
            case 1:
                name = nameInput();
                break;
            case 2:
                quantity = posIntegerInput();
                break;
            case 3:
                price = posFloatInput();
                break;
            case 4:
                weight = posIntegerInput();
                break;
            case 5:
                date = dateInput();
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
    
    std::string s;

    std::cout << '\n';

    while (true) {
        b = 0;
        goods = (product*)realloc(goods, (n + 1) * sizeof(product));
        std::cout << "Введите информацию о товаре " << n + 1 << " :\n" << '\n';

        std::cout << "Наименование товара:\n";
        s = nameInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n].name[j] = s[j];
        }
        if (type == 1 && s == name) {
            b = 1;
        }

        std::cout << "Количество единиц товара:\n";
        goods[n].quantity = posIntegerInput();
        if (type == 2 && goods[n].quantity == quantity) {
            b = 1;
        }

        std::cout << "Цена единицы:\n";
        goods[n].price = posFloatInput();
        if (type == 3 && goods[n].price == price) {
            b = 1;
        }

        std::cout << "Вес единицы:\n";
        goods[n].weight = posIntegerInput();
        if (type == 4 && goods[n].weight == weight) {
            b = 1;
        }

        std::cout << "Дата поступления:\n";
        s = dateInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n].date[j] = s[j];
        }
        if (type == 5 && s == date) {
            b = 1;
        }

        if (choice) {
            goods[n].details.cost = goods[n].quantity * goods[n].price;
        }
        else {
            goods[n].details.mass = goods[n].quantity * goods[n].weight;
        }

        n++;
        if (b) {
            break;
        }

        std::cout << '\n';
    }

    std::cout << '\n';

    writeFile();
}

void thirdInput() { 
    bool b;
    std::string s;

    while(true) {
        b = 0;
        goods = (product*)realloc(goods, (n + 1) * sizeof(product));

        std::cout << "Введите информацию о товаре " << n + 1 << " :\n" << '\n';

        std::cout << "Наименование товара:\n";
        s = nameInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n].name[j] = s[j];
        }

        std::cout << "Количество единиц товара:\n";
        goods[n].quantity = posIntegerInput();

        std::cout << "Цена единицы:\n";
        goods[n].price = posFloatInput();

        std::cout << "Вес единицы:\n";
        goods[n].price = posIntegerInput();

        std::cout << "Дата поступления:\n";
        s = dateInput();
        for (int j = 0; j < s.size(); j++) {
            goods[n].date[j] = s[j];
        }

        if (choice) {
            goods[n].details.cost = goods[n].quantity * goods[n].price;
        }
        else {
            goods[n].details.mass = goods[n].quantity * goods[n].weight;
        }

        std::cout << '\n' << "Введитие 1, если хотите продолжить ввод и 2, если не хотите:\n";
        int type;
        bool c;
        while (true) {
            c = 0;
            type = posIntegerInput();

            switch (type) {
                case 1:
                    b = 1;
                    break;
                case 2:
                    b = 0;
                    break;
                default:
                    std::cout << "Неверный формат ввода!\n";
                    c = 1;
            }
            if (c) {
                continue;
            }
            break;
        }

        n++;

        if (b) {
            continue;
        }
        break;
    }

    std::cout << '\n';

    writeFile();
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

    while (true) {
        std::string s;
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
        std::cout << s;

        b = 0;
        
        if (s.size() != DATE_SIZE - 1) {
            std::cout << "Неверный формат ввода 5555!\n";
            continue; 
        }
        if (s[2] != '.' || s[5] != '.') {
            std::cout << "Неверный формат ввода 4444!\n";
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
            std::cout << "Неверный формат ввода  888888!\n";
            continue;
        }
        s += '\0';
        return s;
        break;
    }
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

void option() {
    std::cout << "\nВыберите тип шестого поля:\n";
    std::cout << "1. Стоимость товара\n";
    std::cout << "2. Масса товара\n";

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
                    goods[i].details.cost = goods[i].quantity * goods[i].price;
                    rewriteFile(6, i);
                }
                break;
            case 2:
                choice = 0;
                rewriteFile(0, 0);
                for (int i = 0; i < n; i++) {
                    goods[i].details.mass = goods[i].quantity * goods[i].weight;
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
}

void output() {
    for (int i = 0; i < n; i++) {
        std::cout << '\n' << "Информация о товаре " << i + 1 << " :\n";
        std::cout << "Наименование товара:\n" << goods[i].name << '\n';
        std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
        std::cout << "Цена единицы:\n" << goods[i].price << '\n';
        std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
        std::cout << "Дата поступления:\n" << goods[i].date << '\n';
        if (choice) {
            std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
        }
        else {
            std::cout << "Масса товара:\n" << goods[i].details.mass;
        }
        std::cout << '\n';
    }

    if (n == 0) {
        std::cout << '\n' << "Информации о товарах нет\n" << '\n';
    }

    std::cout << '\n';
}

void sortOutput() {
    if (!choice) {
        std::cout << "\nСортировка невозможна! Измените шестое поле структуры\n\n";
        return;
    }
    else {
        sort();

        if (n == 0) {
            std::cout << "\nСортировка невозможна! Нет товаров\n\n";
            return;
        }

        std::cout << "\nПродукты со стоимостью более 100.341 рублей, отсортированные по убыванию\n\n";
        int i = 0;
        while (goods[i].details.cost > 100.341) {
            std::cout << '\n' << "Информация о товаре " << i + 1 << " :\n";
            std::cout << "Наименование товара:\n" << goods[i].name << '\n';
            std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
            std::cout << "Цена единицы:\n" << goods[i].price << '\n';
            std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
            std::cout << "Дата поступления:\n" << goods[i].date << '\n';
            if (choice) {
                std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
            }
            else {
                std::cout << "Масса товара:\n" << goods[i].details.mass;
            }
            std::cout << '\n' << '\n';
            i++;
        }

        if (i == 0) {
            std::cout << "Таких товаров нет\n\n";
        }

        free(goods);
        readFile();
    }
}

void removal() {

    if (n == 0) {
        std::cout << "\nУдаление невозможно! Нет товаров\n\n";
        return;
    }

    std::cout << "Выберите признак:\n";
    std::cout << "1. Наименование товара\n";
    std::cout << "2. Количество единиц товара\n";
    std::cout << "3. Цена единицы\n";
    std::cout << "4. Вес единицы\n";
    std::cout << "5. Дата поступления\n";
    if (choice) {
        std::cout << "6. Cтоимость товара\n";
    }
    else {
        std::cout << "6. Масса товара\n";
    }

    int type;
    while (true) {
        type = posIntegerInput();

        std::cout << '\n';

        if (type > 6) {
            std::cout << "Неверный формат ввода!";
            continue;
        }
        break;
    }

    std::cout << "Введите информацию о признаке:\n" << '\n';

    std::string name, date;
    int quantity, weight;
    float price;
    long long mass;
    double cost;
    int counter = 0;
    short *wrong = new short[n]{0};

    switch (type) {
        case 1:
            std::cout << "Наименование товара:\n";
            name = nameInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(name.c_str(), goods[i].name) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 2:
            std::cout << "Количество единиц товара:\n";
            quantity = posIntegerInput();

            for (int i = 0; i < n; i++) {
                if (goods[i].quantity == quantity) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 3:
            std::cout << "Цена единицы:\n";
            price = posFloatInput();

            for (int i = 0; i < n; i++) {
                if (goods[i].price == price) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 4:
            std::cout << "Вес единицы:\n";
            weight = posIntegerInput();

            for (int i = 0; i < n; i++) {
                if (goods[i].weight == weight) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;

        case 5:
            std::cout << "Дата поступления:\n";
            date = dateInput();

            for (int i = 0; i < n; i++) {
                if (strcmp(goods[i].date, date.c_str()) == 0) {
                    wrong[i] = 1;
                    counter++;
                }
            }
            break;  

        case 6:
            if (choice) {
                std::cout << "6. Cтоимость товара:\n";
                cost = posDoubleInput();

                for (int i = 0; i < n; i++) {
                    if (goods[i].details.cost == cost) {
                        wrong[i] = 1;
                        counter++;
                    }
                }
                break;                
            }
            else {
                std::cout << "6. Масса товара:\n";
                mass = posLongLongInput();

                for (int i = 0; i < n; i++) {
                    if (goods[i].details.mass == mass) {
                        wrong[i] = 1;
                        counter++;
                    }
                }
                break;                
            }                
    }

    if (counter == 0) {
        std::cout << '\n' << "Товаров не найдено\n" << '\n';
        delete[] wrong; 
        return;
    }

    int j = 0;

    for (int i = 0; i < n; i++) {
        if (!wrong[i]) {
            goods[j] = goods[i];
            j++;
        }
    }

    n -= counter;
    goods = (product*)realloc(goods, n * sizeof(product));
    delete[] wrong; 

    std::cout << '\n' << "Товары удалены\n" << '\n';

    writeFile();
}

void search() {

    if (n == 0) {
        std::cout << "\nПоиск невозможен! Нет товаров\n\n";
        return;
    }

    std::cout << "Выберите признак:\n";
    std::cout << "1. Наименование товара\n";
    std::cout << "2. Количество единиц товара\n";
    std::cout << "3. Цена единицы\n";
    std::cout << "4. Вес единицы\n";
    std::cout << "5. Дата поступления\n";
    if (choice) {
        std::cout << "6. Cтоимость товара\n";
    }
    else {
        std::cout << "6. Масса товара\n";
    }

    int type;
    while (true) {
        type = posIntegerInput();

        std::cout << '\n';

        if (type > 6) {
            std::cout << "Неверный формат ввода!";
            continue;
        }
        break;
    }

    std::cout << "Введите информацию о признаке:\n" << '\n';

    std::string name, date;
    int quantity, weight;
    float price;
    long long mass;
    double cost;
    int counter = 0;

    switch (type) {
        case 1:
            std::cout << "Наименование товара:\n";
            name = nameInput();

            std::cout << '\n' << "Найденные результаты:\n" << '\n';

            for (int i = 0; i < n; i++) {
 
                if (strcmp(name.c_str(), goods[i].name) == 0) {
                    std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                    std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                    std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                    std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                    std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                    if (choice) {
                        std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                    }
                    else {
                        std::cout << "Масса товара:\n" << goods[i].details.mass;
                    }
                    std::cout << '\n';

                    counter++;
                }
            }

            if (counter == 0) {
                std::cout << '\n' << "Информации о товарах нет\n" << '\n';;
            }
            break;

        case 2:
            std::cout << "Количество единиц товара:\n";
            quantity = posIntegerInput();

            std::cout << '\n' << "Найденные результаты:\n" << '\n';

            for (int i = 0; i < n; i++) {
                if (goods[i].quantity == quantity) {
                    std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                    std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                    std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                    std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                    std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                    if (choice) {
                        std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                    }
                    else {
                        std::cout << "Масса товара:\n" << goods[i].details.mass;
                    }
                    std::cout << '\n';

                    counter++;
                }
            }

            if (counter == 0) {
                std::cout << '\n' << "Информации о товарах нет\n" << '\n';;
            }
            break;
        case 3:
            std::cout << "Цена единицы:\n";
            price = posFloatInput();

            std::cout << '\n' << "Найденные результаты:\n" << '\n';

            for (int i = 0; i < n; i++) {
                if (goods[i].price == price) {
                    std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                    std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                    std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                    std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                    std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                    if (choice) {
                        std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                    }
                    else {
                        std::cout << "Масса товара:\n" << goods[i].details.mass;
                    }
                    std::cout << '\n';

                    counter++;
                }
            }

            if (counter == 0) {
                std::cout << '\n' << "Информации о товарах нет\n" << '\n';
            }
            break;
        case 4:
            std::cout << "Вес единицы:\n";
            weight = posIntegerInput();

            std::cout << '\n' << "Найденные результаты:\n" << '\n';

            for (int i = 0; i < n; i++) {
                if (goods[i].weight == weight) {
                    std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                    std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                    std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                    std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                    std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                    if (choice) {
                        std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                    }
                    else {
                        std::cout << "Масса товара:\n" << goods[i].details.mass;
                    }
                    std::cout << '\n';

                    counter++;
                }
            }

            if (counter == 0) {
                std::cout << '\n' << "Информации о товарах нет\n" << '\n';
            }
            break;            
        case 5:
            std::cout << "Дата поступления:\n";
            date = dateInput();

            std::cout << '\n' << "Найденные результаты:\n" << '\n';

            for (int i = 0; i < n; i++) {
                if (strcmp(goods[i].date, date.c_str()) == 0) {
                    std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                    std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                    std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                    std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                    std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                    if (choice) {
                        std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                    }
                    else {
                        std::cout << "Масса товара:\n" << goods[i].details.mass;
                    }
                    std::cout << '\n';

                    counter++;
                }
            }

            if (counter == 0) {
                std::cout << '\n' << "Информации о товарах нет\n" << '\n';
            }
            break;            
        case 6:
            if (choice) {
                std::cout << "6. Cтоимость товара:\n";
                cost = posDoubleInput();

                std::cout << '\n' << "Найденные результаты:\n" << '\n';

                for (int i = 0; i < n; i++) {
                    if (goods[i].details.cost == cost) {
                        std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                        std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                        std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                        std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                        std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                        if (choice) {
                            std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                        }
                        else {
                            std::cout << "Масса товара:\n" << goods[i].details.mass;
                        }
                        std::cout << '\n';

                        counter++;
                    }
                }

                if (counter == 0) {
                    std::cout << '\n' << "Информации о товарах нет\n" << '\n';
                }
                break;                
            }
            else {
                std::cout << "6. Масса товара:\n";
                mass = posLongLongInput();

                std::cout << '\n' << "Найденные результаты:\n" << '\n';

                for (int i = 0; i < n; i++) {
                    if (goods[i].details.mass == mass) {
                        std::cout << "Наименование товара:\n" << goods[i].name << '\n';
                        std::cout << "Количество единиц товара:\n" << goods[i].quantity << '\n';
                        std::cout << "Цена единицы:\n" << goods[i].price << '\n';
                        std::cout << "Вес единицы:\n" << goods[i].weight << '\n';
                        std::cout << "Дата поступления:\n" << goods[i].date << '\n';
                        if (choice) {
                            std::cout << "Cтоимость товара:\n" << goods[i].details.cost;
                        }
                        else {
                            std::cout << "Масса товара:\n" << goods[i].details.mass;
                        }
                        std::cout << '\n';

                        counter++;
                    }
                }

                if (counter == 0) {
                    std::cout << '\n' << "Информации о товарах нет\n" << '\n';
                }
                break;                
            }                
    }

    std::cout << '\n';    
}

void sort() {
    for (int i = 0; i < n; i++) {
        product key = goods[i];
        int j = i - 1;
        while (j >= 0 && goods[j].details.cost < key.details.cost) {
            goods[j + 1] = goods[j];
            j--;
        }
        goods[j + 1] = key;
    }
}

void view() {
    std::cout << '\n' << "Вид структуры:\n";
    std::cout << "1. Наименование товара:\n"; 
    std::cout << "2. Количество единиц товара:\n";
    std::cout << "3. Цена единицы:\n";
    std::cout << "4. Вес единицы:\n";
    std::cout << "5. Дата поступления:\n";
    std::cout << "6. Cтоимость / масса товара. Сейчас ";
    if (choice) {
        std::cout << "стоимость\n"; 
    }
    else {
        std::cout << " масса товара\n";
    }
    std::cout << '\n';
}