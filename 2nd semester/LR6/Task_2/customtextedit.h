#ifndef CUSTOMTEXTEDIT_H
#define CUSTOMTEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>

class CustomTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    CustomTextEdit(QTextEdit *parent = nullptr);
    ~CustomTextEdit() {}

protected:
    void keyPressEvent(QKeyEvent * event) override;

signals:
    void returnPressed();
};

#endif // CUSTOMTEXTEDIT_H
