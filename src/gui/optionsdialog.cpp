/*******************************************************/
//
//
/*******************************************************/
#include <QDebug>
#include <QHBoxLayout>
#include "optionsdialog.h"
#include "ui_optionsdialog.h"

OptionsDialog::OptionsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::OptionsDialog)
{
    // init UI
    ui->setupUi(this);

    // construct Main menu items
    mainList = new QStandardItemModel(this);

    MenuBodyList = ui->frameBody->findChildren<QTabWidget *>();
    if (MenuBodyList.size() > 0)
        {
        QHBoxLayout *layout = new QHBoxLayout;
        layout->setContentsMargins(0, 0, 0, 0);
        for(int i=0; i<MenuBodyList.size(); i++)
            {
            // get current Name and create new item
            QString bufName = MenuBodyList.at(i)->objectName();
            QStandardItem *item = new QStandardItem(QIcon(":/logo.ico"), bufName); //TODO USE ":/bufName.ico" instead
            mainList->setItem(i,item);
            //set and add current TabWidget to the layout
            MenuBodyList.at(i)->setVisible(false);
            layout->addWidget(MenuBodyList.at(i));
            }
        MenuBodyList.at(0)->setVisible(true);
        // add the layout to the central frame
        ui->frameBody->setLayout(layout);
        ui->MainTitle->setText(MenuBodyList.at(0)->objectName());
        }

    ui->mainMenuList->setModel(mainList);
    ui->mainMenuList->
    connect(ui->mainMenuList->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(changeMenu(QItemSelection,QItemSelection)));
}

void OptionsDialog::changeMenu(QItemSelection selected, QItemSelection deselected)
{
    if (selected.indexes().count() > 0)
        {
        QModelIndex idx = selected.indexes().first();
        QString s = mainList->itemFromIndex(idx)->data(Qt::DisplayRole).toString();
        QTabWidget *newTab = getBodyTabByName(s);
        if (newTab != 0)
            {
            // hide old tabs
            for (int i=0; i<ui->frameBody->layout()->count(); i++)
                {
                ui->frameBody->layout()->itemAt(i)->widget()->setVisible(false);
                }
            // show the corresponding tab
            newTab->setVisible(true);
            // Adjust Main Title string
            ui->MainTitle->setText(s);
            }
        }

    return;
}



QTabWidget* OptionsDialog::getBodyTabByName(QString name)
{
    for(int i=0; i<MenuBodyList.size(); i++)
        {
        if ( MenuBodyList.at(i)->objectName() == name )
            {
            return MenuBodyList.at(i);
            }
        }
    return NULL;
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}
