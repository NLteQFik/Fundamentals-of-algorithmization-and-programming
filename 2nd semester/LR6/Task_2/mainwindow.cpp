#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = windowFlags();
    flags = flags & (~Qt::WindowCloseButtonHint);
    setWindowFlags(flags);

    text_widget = new TextWidget();
    line_widget = new LineWidget();
    struct_widget = new StructWidget();

    connect(text_widget->text_input, &CustomTextEdit::returnPressed, &loop, &QEventLoop::quit);
    connect(line_widget->text_input, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);
    connect(struct_widget->button, &QPushButton::clicked, &loop, &QEventLoop::quit);
    connect(ui->menuEdit, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);

    ui->menuEdit->setStyleSheet(
        "QLineEdit:disabled {"
        "   background-color: #444; "
        "   color: #888; "
        "   font: bold 12pt 'Source Code Pro'; "
        "   border: 2px solid #666; "
        "   padding: 6px; "
        "   opacity: 0.5; "
        "}"
        "QLineEdit:enabled {"
        "   background-color: rgba(60, 60, 120, 150); "
        "   color: #CCCCCC; "
        "   font: bold 12pt 'Consolas'; "
        "   border: 2px solid #003366; "
        "   padding: 6px; "
        "}"
        );

    setWindowTitle("Program");
    this->setFixedSize(this->size());

    InitMenu();
    InitInfo();

    QTimer::singleShot(50, [&]{
        runProgramm();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitMenu()
{
    ui->menuLabel->setText("Menu:\n"
                           "1. Write paragraph to file\n"
                           "2. Read and print paragraph from file\n"
                           "3. Write massive to file\n"
                           "4. Read and print massive from file\n"
                           "5. Write struct to file\n"
                           "6. Read and print structs from file\n"
                           "7. Write sentence to file\n"
                           "8. Read and print sentences from file\n"
                           "9. Write struct to binary file\n"
                           "10. Read and print structs from binary file\n"
                           "11. Exit\n"
                           "Confirm your choice:\n");
    ui->menuLabel->setWordWrap(true);
}

void MainWindow::InitInfo()
{
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    ui->infoLabel->setWordWrap(true);
    ui->infoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    scrollArea->setWidget(ui->infoLabel);
    scrollArea->setGeometry(320, 0, 630, 630);

    ui->infoLabel->setText("");
    printInfo("Program is running...\n");
}

void MainWindow::printInfo(QString newStr)
{
    ui->infoLabel->setText(ui->infoLabel->text() + newStr);
}

QString MainWindow::readMenuInput()
{
    loop.exec();
    QString ret = ui->menuEdit->text();
    ui->menuEdit->clear();
    printInfo("\n");
    return ret;
}

void MainWindow::runProgramm()
{
    is_running = true;
    while (is_running) {
        switch (readMenuInput().toInt()) {
        case 1:
            writeParagraphToFile(paragraphFile);
            break;
        case 2:
            readAndPrintParagraphFromFile(paragraphFile);
            break;
        case 3:
            writeArrayToFile(arrayFile, '\\');
            break;
        case 4:
            readAndPrintArrayFromFile(arrayFile, '\\');
            break;
        case 5:
            writeStructToFile(structFile);
            break;
        case 6:
            readAndPrintStructsFromFile(structFile);
            break;
        case 7:
            writeSentenceToFile(sentenceFile);
            break;
        case 8:
            readAndPrintSentencesFromFile(sentenceFile);
            break;
        case 9:
            saveStructToBinaryFile(binaryFile);
            break;
        case 10:
            readAndPrintStructsFromBinaryFile(binaryFile);
            break;
        case 11:
            printInfo("Programm is ending...\n");
            is_running = false;
            break;
        default:
            printInfo("Incorrect choice. Please write a number from 1 to 11\n");
        }
    }
    QApplication::quit();
}

void MainWindow::writeParagraphToFile(const std::string &filename)
{
    std::wofstream file(filename, std::ios::out);
    if (!file) {
        QMessageBox::critical(this, "Error!", "Cannot open the file!!");
        return;
    }
    ui->menuEdit->setDisabled(true);
    text_widget->setWindowTitle("Write a paragraph (press 'Enter' for exit)");
    text_widget->show();
    loop.exec();
    QString paragraph = text_widget->text_input->toPlainText();
    text_widget->hide();
    text_widget->text_input->clear();
    file << paragraph.toStdWString();
    printInfo("Paragraph is writen!\n");
    file.close();
    ui->menuEdit->setEnabled(true);
}

void MainWindow::readAndPrintParagraphFromFile(const std::string &filename)
{
    std::wifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Error!", "Cannot open the file!!");
        return;
    }
    ui->menuEdit->setDisabled(true);
    QString fileName(filename.c_str());
    printInfo(QString("Paragraph from file " + fileName + ":" + "\n"));
    wchar_t ch;
    while (file.get(ch)) {
        printInfo(QString(QChar(ch)));
    }
    file.close();
    ui->menuEdit->setEnabled(true);
}

void MainWindow::writeArrayToFile(const std::string &filename, char delimiter)
{
    std::ofstream file(filename, std::ios::out);
    if (!file) {
        QMessageBox::critical(this, "Error!", "Cannot open the file!!");
        return;
    }

    ui->menuEdit->setDisabled(true);

    int size;
    line_widget->setWindowTitle("Write massive's size");
    line_widget->text_input->setValidator(new QIntValidator(0, 1000));
    line_widget->show();
    loop.exec();
    size = line_widget->text_input->text().toInt();
    line_widget->hide();
    line_widget->text_input->clear();

    line_widget->setWindowTitle("Write elements using '" + QString(delimiter) + "'\n");
    line_widget->text_input->setValidator(nullptr);
    line_widget->show();
    loop.exec();
    QString input = line_widget->text_input->text();
    QStringList nums = input.split(delimiter);
    line_widget->hide();
    line_widget->text_input->clear();

    int i = 0;
    for (const QString& num : nums)
    {
        if (++i > size) break;
        file << num.toInt();
        if (i != size) {
            file << delimiter;
        }
    }

    file.close();
    printInfo("Massive is writen!\n");
    ui->menuEdit->setEnabled(true);
    nums.clear();
}

void MainWindow::readAndPrintArrayFromFile(const std::string &filename, char delimiter)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Error!", "Cannot open the file!!");
        return;
    }
    ui->menuEdit->setDisabled(true);
    QString fileName(filename.c_str());
    printInfo(QString("Massive form file " + fileName + ":" + "\n"));
    char value;
    QString ans;
    while (file.get(value)) {
        if (value != delimiter) {
            ans += value;
        }
        else {
            ans += " ";
        }
    }
    printInfo(ans);
    file.close();
    ui->menuEdit->setEnabled(true);
}

void MainWindow::writeStructToFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        QMessageBox::critical(this, "Error!", "Cannot open the file!!");
        return;
    }

    ui->menuEdit->setDisabled(true);
    sportsman sb;
    struct_widget->show();
    loop.exec();
    sb.age = struct_widget->age->text().toInt();
    sb.height = struct_widget->height->text().toDouble();
    sb.category = struct_widget->category->text().toStdString().at(0);
    sb.professional = struct_widget->professional->text().toInt();
    strcpy(sb.name, struct_widget->name->text().toStdString().data());
    sb.results[0] = struct_widget->result1->text().toDouble();
    sb.results[1] = struct_widget->result2->text().toDouble();
    sb.results[2] = struct_widget->result3->text().toDouble();
    struct_widget->hide();

    file << sb.age << " | " << sb.height << " | " << sb.category << " | "
         << sb.professional << " | " << sb.name << " | " << sb.results[0]
         << " | " << sb.results[1] << " | " << sb.results[2] << " | " << std::endl;

    file.close();
    printInfo("Struct is written!\n");
    ui->menuEdit->setEnabled(true);
}

void MainWindow::readAndPrintStructsFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Error!", "Cannot open the file!!");
        return;
    }

    ui->menuEdit->setDisabled(true);
    QString fileName(filename.c_str());
    printInfo("Structs from file " + fileName + ":" + "\n");
    sportsman sb;
    char delimiter;
    while (file >> sb.age >> delimiter && delimiter == '|' &&
           file >> sb.height >> delimiter && delimiter == '|' &&
           file >> sb.category >> delimiter && delimiter == '|' &&
           file >> sb.professional >> delimiter && delimiter == '|' &&
           file >> sb.name >> delimiter && delimiter == '|' &&
           file >> sb.results[0] >> delimiter && delimiter == '|' &&
           file >> sb.results[1] >> delimiter && delimiter == '|' &&
           file >> sb.results[2] >> delimiter && delimiter == '|') {
        printInfo(QString::number(sb.age) + "|" + QString::number(sb.height) + "|" +
                      QString(sb.category) + "|" + QVariant(sb.professional).toString() + "|" +
                      QString(sb.name) + "|" + QString::number(sb.results[0]) + " " +
                      QString::number(sb.results[1]) + " " + QString::number(sb.results[2]) + " ;\n");
    }

    file.close();
    ui->menuEdit->setEnabled(true);
}

void MainWindow::writeSentenceToFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        QMessageBox::critical(this, "Error!", "Cannot open the file!!");
        return;
    }
    ui->menuEdit->setDisabled(true);
    text_widget->setWindowTitle("Write a sentence (press 'Enter' for exit");
    text_widget->show();
    loop.exec();
    QString paragraph = text_widget->text_input->toPlainText();
    text_widget->hide();
    text_widget->text_input->clear();
    file << paragraph.toStdString() << '\n';
    printInfo("Sentence is writen!\n");
    file.close();
    ui->menuEdit->setEnabled(true);
}

void MainWindow::readAndPrintSentencesFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        QMessageBox::critical(this, "Error!", "Cannot open the file!!");
        return;
    }
    QString fileName(filename.c_str());
    printInfo("Sentences from file " + fileName + ":" + "\n");
    std::string sentence;
    while (getline(file, sentence)) {
        printInfo(QString(sentence.c_str()) + "\n");
    }
    file.close();
    ui->menuEdit->setEnabled(true);
}

void MainWindow::saveStructToBinaryFile(const std::string &filename)
{
    std::ofstream file(filename, std::ios::app | std::ios::binary);
    if (!file) {
        QMessageBox::critical(this, "Error!", "Cannot open the file!!");
        return;
    }

    ui->menuEdit->setDisabled(true);
    sportsman sb;
    struct_widget->show();
    loop.exec();
    sb.age = struct_widget->age->text().toInt();
    sb.height = struct_widget->height->text().toDouble();
    sb.category = struct_widget->category->text().toStdString().at(0);
    sb.professional = struct_widget->professional->text().toInt();
    strcpy(sb.name, struct_widget->name->text().toStdString().data());
    sb.results[0] = struct_widget->result1->text().toDouble();
    sb.results[1] = struct_widget->result2->text().toDouble();
    sb.results[2] = struct_widget->result3->text().toDouble();
    struct_widget->hide();

    file.write(reinterpret_cast<const char*>(&sb), sizeof(sportsman) + 1);

    file.close();
    printInfo("Struct is written!\n");
    ui->menuEdit->setEnabled(true);
}

void MainWindow::readAndPrintStructsFromBinaryFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        QMessageBox::critical(this, "Error!", "Cannot open the file!!");
        return;
    }

    ui->menuEdit->setDisabled(true);
    QString fileName(filename.c_str());
    printInfo("Structs from file " + fileName + ":" + "\n");
    sportsman sb;
    while (file.read(reinterpret_cast<char*>(&sb), sizeof(sportsman) + 1)) {
        printInfo(QString::number(sb.age) + "|" + QString::number(sb.height) + "|" +
                  QString(sb.category) + "|" + QVariant(sb.professional).toString() + "|" +
                  QString(sb.name) + "|" + QString::number(sb.results[0]) + " " +
                  QString::number(sb.results[1]) + " " + QString::number(sb.results[2]) + " ;\n");
    }
    file.close();
    ui->menuEdit->setEnabled(true);

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    is_running = false;
    QApplication::quit();
}
