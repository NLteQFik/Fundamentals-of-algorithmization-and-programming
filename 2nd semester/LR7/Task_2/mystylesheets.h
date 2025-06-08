#ifndef MYSTYLESHEETS_H
#define MYSTYLESHEETS_H

#include <QString>

class MyStyleSheets
{
public:
    MyStyleSheets();

    inline static const QString greenButtonStyle = "QPushButton {"
                                                   "background-color: #28A745;"
                                                   "color: white;"
                                                   "border-radius: 6px;"
                                                   "padding: 6px 12px;"
                                                   "font-size: 14px;"
                                                   "font-weight: bold;"
                                                   "border: 2px solid #218838;"
                                                   "}"
                                                   "QPushButton:hover {"
                                                   "background-color: #218838;"
                                                   "}"
                                                   "QPushButton:pressed {"
                                                   "background-color: #1E7E34;"
                                                   "}"
                                                   "QPushButton:disabled {"
                                                   "background-color: #A5D6A7;"
                                                   "color: #6C8E6C;"
                                                   "border: 2px solid #85B785;"
                                                   "}";

    inline static const QString redButtonStyle = "QPushButton {"
                                                 "background-color: #DC3545;"
                                                 "color: white;"
                                                 "border-radius: 6px;"
                                                 "padding: 6px 12px;"
                                                 "font-size: 14px;"
                                                 "font-weight: bold;"
                                                 "border: 2px solid #C82333;"
                                                 "}"
                                                 "QPushButton:hover {"
                                                 "background-color: #C82333;"
                                                 "}"
                                                 "QPushButton:pressed {"
                                                 "background-color: #B21F2D;"
                                                 "}"
                                                 "QPushButton:disabled {"
                                                 "background-color: #E6B0AA;"
                                                 "color: #AA6F6F;"
                                                 "border: 2px solid #D49A9A;"
                                                 "}";

    inline static const QString blueButtonStyle = "QPushButton {"
                                                  "background-color: #007BFF;"
                                                  "color: white;"
                                                  "border-radius: 6px;"
                                                  "padding: 6px 12px;"
                                                  "font-size: 14px;"
                                                  "font-weight: bold;"
                                                  "border: 2px solid #0056B3;"
                                                  "}"
                                                  "QPushButton:hover {"
                                                  "background-color: #0056B3;"
                                                  "}"
                                                  "QPushButton:pressed {"
                                                  "background-color: #004085;"
                                                  "}"
                                                  "QPushButton:disabled {"
                                                  "background-color: #B0C4DE;"
                                                  "color: #6A7E99;"
                                                  "border: 2px solid #98B0C4;"
                                                  "}";

    inline static const QString mainWindowStyle = "QMainWindow {"
                                                    "background-color: #F8F8F8;"
                                                    "color: #333333;"
                                                    "font-size: 14px;"
                                                    "border: 1px solid #CCCCCC;"
                                                    "}";
    inline static const QString tableWidgetStyle =  "QTableWidget {"
                                                    "background-color: #AABBFF;"
                                                    "color: #000000;"
                                                    "font-size: 14px;"
                                                    "gridline-color: #8899AA;"
                                                    "border: 2px solid #CCCCCC;"
                                                    "}"

                                                    "QTableWidget::item:selected {"
                                                    "background-color: #3399FF;"
                                                    "color: white;"
                                                    "}";

    inline static const QString headerStyle = "QHeaderView::section {"
                                                "background-color: #4455AA;"
                                                "color: white;"
                                                "font: bold 14px 'Verdana';"
                                                "border: 1px solid #222266;"
                                                "padding: 6px;"
                                                "text-align: center;"
                                                "}"

                                                "QHeaderView::section:hover {"
                                                "background-color: #6677DD;"
                                                "}";

    inline static const QString treeWidgetStyle = "QTreeWidget {"
                                                      "background-color: #FFBBFF;"
                                                      "color: #000000;"
                                                      "font-size: 14px;"
                                                      "border: 2px solid #CCCCCC;"
                                                      "}"
                                                      "QTreeWidget::item:selected {"
                                                      "background-color: #9944AA;"
                                                      "color: white;"
                                                      "}";
    inline static const QString altTreeWidgetStyle = "QTreeWidget {"
                                                  "background-color: #FFFFBB;"
                                                  "color: #000000;"
                                                  "font-size: 14px;"
                                                  "border: 2px solid #CCCCCC;"
                                                  "}"
                                                  "QTreeWidget::item:selected {"
                                                  "background-color: #99AA44;"
                                                  "color: white;"
                                                  "}";
    inline static const QString labelStyle = "QLabel {"
                                                 "background-color: #DDFFDD;"
                                                 "color: #115522;"
                                                 "border-radius: 4px;"
                                                 "padding: 4px 8px;"
                                                 "border: 2px solid #88AA88;"
                                                 "font-size: 14px;"
                                                 "padding: 2px;"
                                                 "}";

    inline static const QString neonLabelStyle = "QLabel {"
                                                 "background-color: black;"
                                                 "color: #00FF00;"
                                                 "border-radius: 6px;"
                                                 "padding: 6px;"
                                                 "font-size: 18px;"
                                                 "font-weight: bold;"
                                                 "text-shadow: 0px 0px 8px #00FF00;"
                                                 "}";

    inline static const QString lightLabelStyle = "QLabel {"
                                                  "background-color: #F8F8F8;"
                                                  "color: #222222;"
                                                  "border-radius: 6px;"
                                                  "padding: 6px;"
                                                  "border: 2px solid #CCCCCC;"
                                                  "font-size: 16px;"
                                                  "font-style: italic;"
                                                  "}";

    inline static const QString lineEditStyle = "QLineEdit {"
                                                "background-color: #E8F5E9;"
                                                "color: #1B5E20;"
                                                "font-size: 14px;"
                                                "border: 2px solid #66BB6A;"
                                                "border-radius: 4px;"
                                                "padding: 4px;"
                                                "}"
                                                "QLineEdit:focus {"
                                                "border: 2px solid #43A047;"
                                                "background-color: #C8E6C9;"
                                                "}";

    inline static const QString spinBoxStyle = "QSpinBox {"
                                               "background-color: #FFF3E0;"
                                               "color: #BF360C;"
                                               "font-size: 14px;"
                                               "border: 2px solid #FB8C00;"
                                               "border-radius: 4px;"
                                               "padding: 4px;"
                                               "}"
                                               "QSpinBox:focus {"
                                               "border: 2px solid #EF6C00;"
                                               "background-color: #FFE0B2;"
                                               "}";


    inline static const QString plainTextEditStyle = "QPlainTextEdit {"
                                                     "background-color: #E3F2FD;"
                                                     "color: #0D47A1;"
                                                     "font-size: 14px;"
                                                     "border: 2px solid #42A5F5;"
                                                     "border-radius: 4px;"
                                                     "padding: 6px;"
                                                     "}"
                                                     "QPlainTextEdit:focus {"
                                                     "border: 2px solid #1E88E5;"
                                                     "background-color: #BBDEFB;"
                                                     "}";


};

#endif // MYSTYLESHEETS_H
