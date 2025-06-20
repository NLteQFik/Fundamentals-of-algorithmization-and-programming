#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setLayout(ui->gridLayout);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    currState = 0;
    currStepOfSearch = 0;
    amountOfElementsInArray = 100;
    on_fillButton_clicked();

    ui->amountOfElementsSpinBox->setValue(100);

    on_fillButton_clicked();

    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, [=]{
        if (currState == listOfStates.size() - 1) {
            ui->amountOfElementsSpinBox->setDisabled(false);
            ui->sortButton->setDisabled(false || isSorted);
            ui->findButton->setDisabled(!isSorted);
            return;
        }
        ui->amountOfElementsSpinBox->setDisabled(true);
        ui->sortButton->setDisabled(true);
        ui->findButton->setDisabled(true);
        currState++;
        drawArr();
    });
    animationTimer->start(50);

    on_fillButton_clicked();

    isSorted = false;

    searchAnimationTimer = new QTimer(this);
    listOfSearch.append(0);
    connect(searchAnimationTimer, &QTimer::timeout, [=]{
        if (!isSorted) return;
        if (currStepOfSearch == listOfSearch.size() - 1) {
            if (isElement) {
                rects[listOfSearch[listOfSearch.size() - 1]]->setBrush(QBrush(Qt::green));
            }
            ui->amountOfElementsSpinBox->setDisabled(false);
            ui->sortButton->setDisabled(false || isSorted);
            ui->findButton->setDisabled(!isSorted);
            return;
        }
        ui->amountOfElementsSpinBox->setDisabled(true);
        ui->sortButton->setDisabled(true);
        ui->findButton->setDisabled(true);
        currStepOfSearch++;
        drawSearch();
    });
    searchAnimationTimer->start(500);

    setWindowTitle("Sorts");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fillButton_clicked()
{
    vectForTime.clear();
    vectForAniamtion.clear();
    listOfStates.clear();
    int addedElement = 0;
    isElement = false;
    isSorted = false;
    currState = 0;
    listOfSearch.clear();
    listOfSearch.append(0);
    currStepOfSearch = 0;
    for (int i = 0; i < amountOfElementsInArray; ++i) {
        addedElement = QRandomGenerator::global()->bounded(1, 100);
        vectForTime.append(addedElement);
        vectForAniamtion.append(addedElement);
    }
    listOfStates.append(vectForAniamtion);
    drawArr();
}

void MainWindow::on_sortButton_clicked()
{
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    switch (ui->sortingComboBox->currentIndex()) {
    case 0:
        start = std::chrono::high_resolution_clock::now();
        MergeSorter::Sort(vectForTime);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        ui->sortingInfoLabel->setText("Time on merge sort: " +
                                      QString::number(duration.count())
                                      + " ms");
        MergeSorter::SortAnimation(vectForAniamtion, listOfStates);
        isSorted = true;
        break;
    case 1:
        start = std::chrono::high_resolution_clock::now();
        QSorter::Sort(vectForTime);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        ui->sortingInfoLabel->setText("Time on quick sort: " +
                                      QString::number(duration.count())
                                      + " ms");
        QSorter::SortAnimation(vectForAniamtion, listOfStates);
        isSorted = true;
        break;
    case 2:
        start = std::chrono::high_resolution_clock::now();
        HeapSorter::Sort(vectForTime);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        ui->sortingInfoLabel->setText("Time on heap sort: " +
                                      QString::number(duration.count())
                                      + " ms");
        HeapSorter::SortAnimation(vectForAniamtion, listOfStates);
        isSorted = true;
        break;
    case 3:
        start = std::chrono::high_resolution_clock::now();
        InterpolationSorter::Sort(vectForTime);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        ui->sortingInfoLabel->setText("Time on interpolation sort: " +
                                      QString::number(duration.count())
                                      + " ms");
        InterpolationSorter::SortAnimation(vectForAniamtion, listOfStates);
        isSorted = true;
        break;
    default:
        break;
    }
}

void MainWindow::drawArr()
{
    scene->clear();
    rects.clear();
    qreal w = ui->graphicsView->width() - 50;
    for (int i = 0; i < amountOfElementsInArray; ++i) {
        rects.append(scene->addRect(QRectF(25 + i * w / amountOfElementsInArray, 0,
                                           w / amountOfElementsInArray, listOfStates[currState][i] * 5)));
    }
}

int MainWindow::binarySearch(int searched, int l, int r)
{
    int m = (l + r) / 2;
    listOfSearch.append(m);
    if (qAbs(l - r) <= 1) {
        if (vectForTime[l] == searched) {
            listOfSearch.append(l);
            return l;
        }
        if (vectForTime[r] == searched) {
            listOfSearch.append(r);
            return r;
        }
        return -1;
    }
    if (vectForTime[m] > searched) {
        return binarySearch(searched, l, m);
    }
    else {
        return binarySearch(searched, m, r);
    }

}

void MainWindow::drawSearch()
{
    if (currStepOfSearch != 0) {
        rects[listOfSearch[currStepOfSearch - 1]]->setBrush(QBrush(Qt::white));
    }
    rects[listOfSearch[currStepOfSearch]]->setBrush(QBrush(Qt::red));
}

long long MainWindow::binpow(long long base, long long pow, long long mod)
{
    if (pow == 0) return 1;
    long long half = binpow(base, pow / 2, mod);
    if (pow % 2 == 0) {
        return (half * half) % mod;
    }
    else {
        return (((half * half) % mod) * (base % mod)) % mod;
    }
}

void MainWindow::on_findButton_clicked()
{
    currStepOfSearch = 0;
    listOfSearch.clear();
    isElement = true;
    int resOfSearch = binarySearch(ui->searchingSpinBox->value(), 0, vectForTime.size() - 1);
    for (auto& st : rects) {
        st->setBrush(QBrush(Qt::white));
    }
    if (resOfSearch == -1) {
        ui->searchingInfoLabel->setText("There is no such element!");
        isElement = false;
    }
    else {
        ui->searchingInfoLabel->
            setText("Number of element " + QString::number(resOfSearch + 1) +
                    "\n binpow(" + QString::number(resOfSearch + 1) +
                    ", " + QString::number(amountOfElementsInArray) + ", " + ui->modSpinBox->text() +
                    ") = " + QString::number(binpow(resOfSearch + 1,
                                                    amountOfElementsInArray, ui->modSpinBox->value())));
    }
}

void MainWindow::showEvent(QShowEvent *event)
{
    on_fillButton_clicked();
    QWidget::showEvent(event);
}


void MainWindow::on_amountOfElementsSpinBox_valueChanged(int arg1)
{
    amountOfElementsInArray = arg1;
    on_fillButton_clicked();
}
