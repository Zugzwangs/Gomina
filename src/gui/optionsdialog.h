/*******************************************************/
//
//
/*******************************************************/

#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QTabWidget>
#include <QStandardItemModel>

namespace Ui { class OptionsDialog; }

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();
    QStandardItemModel* mainList;

private:
    Ui::OptionsDialog *ui;
    QList<QTabWidget *> MenuBodyList;
    QTabWidget* getBodyTabByName(QString name);

private slots:
    void changeMenu(QItemSelection selected, QItemSelection deselected);
    void saveSettings(); // ?

};

#endif // OPTIONSDIALOG_H
