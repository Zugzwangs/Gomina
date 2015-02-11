/*******************************************************/
//
//
/*******************************************************/

#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QScrollArea>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QScrollArea
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = 0);
    ~ChatWindow();

private:
    Ui::ChatWindow *ui;
};

#endif // CHATWINDOW_H
