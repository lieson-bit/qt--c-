#ifndef QUIZE_H
#define QUIZE_H
#include "question.h"
#include <algorithm>
#include <QMainWindow>
#include <QButtonGroup>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class Quize; }
QT_END_NAMESPACE

class Quize : public QMainWindow
{
    Q_OBJECT

public:
    Quize(QWidget *parent = nullptr);
    ~Quize();
    void setquestions();
    void tickingtime();
    int page = 0;
    int point;

private slots:
    void on_ans1_clicked();

    void on_ans2_clicked();

    void on_ans3_clicked();

    void on_ans4_clicked();

    void on_ans5_clicked();

    void on_ans6_clicked();

    void on_ans7_clicked();

    void on_ans8_clicked();

    void on_ans9_clicked();

    void on_pushButton_clicked();



    void on_submit_clicked();

private:
    Ui::Quize *ui;
    std::vector<Question> questions;
    Question currentQuestion;
    int correctans=0;

    //std::vector<std::vector<bool>> checkedStates;

};
#endif // QUIZE_H
