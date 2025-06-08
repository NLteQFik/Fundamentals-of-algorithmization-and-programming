#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QEventLoop>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

#include <fstream>
#include <string>

#include "sportsman.h"
#include "textwidget.h"
#include "linewidget.h"
#include "structwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void InitMenu();
    void InitInfo();

    void printInfo(QString newStr);
    QString readMenuInput();

    void runProgramm();

    void writeParagraphToFile(const std::string& filename);
    void readAndPrintParagraphFromFile(const std::string& filename);
    void writeArrayToFile(const std::string& filename, char delimiter);
    void readAndPrintArrayFromFile(const std::string& filename, char delimiter);
    void writeStructToFile(const std::string& filename);
    void readAndPrintStructsFromFile(const std::string& filename);
    void writeSentenceToFile(const std::string& filename);
    void readAndPrintSentencesFromFile(const std::string& filename);

    void saveStructToBinaryFile(const std::string& filename);
    void readAndPrintStructsFromBinaryFile(const std::string& filename);

private:
    void closeEvent(QCloseEvent *event);

    const std::string surname = "AreshchankaLab20";
    const std::string paragraphFile = surname + ".txt";
    const std::string arrayFile = surname + "_0.txt";
    const std::string structFile = surname + "_1.txt";
    const std::string binaryFile = surname + "_2.bin";
    const std::string sentenceFile = surname + "_3.txt";

    Ui::MainWindow *ui;
    QEventLoop loop;
    QScrollArea *scrollArea;
    bool is_running = false;

    TextWidget *text_widget;
    LineWidget *line_widget;
    StructWidget* struct_widget;
};
#endif // MAINWINDOW_H
