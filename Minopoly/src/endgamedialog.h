#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include <QDialog>

namespace Ui {
class EndGameDialog;
}

class EndGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EndGameDialog(QWidget *parent = nullptr);
    ~EndGameDialog();

    void setMessage(const QString &message);

private:
    Ui::EndGameDialog *ui;
};

#endif // ENDGAMEDIALOG_H
