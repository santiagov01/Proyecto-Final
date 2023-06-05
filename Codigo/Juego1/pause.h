#ifndef PAUSE_H
#define PAUSE_H

#include <QDialog>

namespace Ui {
class Pause;
}

class Pause : public QDialog
{
    Q_OBJECT

public:
    explicit Pause(QWidget *parent = nullptr);
    ~Pause();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Pause *ui;
};

#endif // PAUSE_H
