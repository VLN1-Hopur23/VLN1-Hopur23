#ifndef DETAILS_H
#define DETAILS_H

#include <QDialog>
#include <QPixmap>
#include <QFileDialog>
#include "scientist.h"
#include "computer.h"

namespace Ui {
class Details;
}

class Details : public QDialog
{
    Q_OBJECT

public:
    explicit Details(QWidget *parent = 0, Scientist* scientist = NULL);
    explicit Details(QWidget *parent = 0, Computer* computer = NULL);
    ~Details();

    void ScientistDetails();
    void ComputerDetails();

private slots:
    void on_label_name_linkActivated();
    void on_button_browse_image_clicked();

private:
    Ui::Details *ui;
    Scientist _scientist;
    Computer _computer;
};

#endif // DETAILS_H
