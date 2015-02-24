#ifndef DIALOGFINDPLAYER_H
#define DIALOGFINDPLAYER_H

#include <QDialog>

namespace Ui {
class DialogFindPlayer;
}

class DialogFindPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFindPlayer(QWidget *parent = 0);
    ~DialogFindPlayer();

private:
    Ui::DialogFindPlayer *ui;
};

#endif // DIALOGFINDPLAYER_H
