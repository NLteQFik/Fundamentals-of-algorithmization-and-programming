#include "customtextedit.h"

CustomTextEdit::CustomTextEdit(QTextEdit *parent) : QTextEdit(parent)
{

}

// CustomTextEdit::~CustomTextEdit()
// {

// }

void CustomTextEdit::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        emit returnPressed();
    }
    else
    {
        QTextEdit::keyPressEvent(event);
    }
}
