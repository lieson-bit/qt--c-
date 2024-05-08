#include "quize.h"
#include "ui_quize.h"

Quize::Quize(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Quize)
{
    ui->setupUi(this);
    page =0;

    setquestions();
    tickingtime();
    ui->submit->setVisible(false);
    ui->lab->setVisible(false);
    ui->points->setVisible(false);
}

Quize::~Quize()
{
    delete ui;
}

void Quize::setquestions()
{
    questions = loadQuestions();

    ui->groupBox1->setHidden(true);
    ui->groupBox2->setHidden(true);
    ui->groupBox3->setHidden(true);

    int maxNoOfPage = 3;
    int startIndex = page * maxNoOfPage;
    int endIndex = std::min((page + 1) * maxNoOfPage, static_cast<int>(questions.size()));

    for (int i = startIndex; i < endIndex; ++i) {
        currentQuestion = questions.at(i);
        QString text = fixtext(currentQuestion.text);

        switch (i - startIndex) {
            case 0:
                ui->ans1->setText(currentQuestion.answer1);
                ui->ans2->setText(currentQuestion.answer2);
                ui->ans3->setText(currentQuestion.answer3);
                ui->groupBox1->setTitle(QString::number(i + 1) + ". " + text);
                ui->groupBox1->setHidden(false);             
                break;
            case 1:
                ui->ans4->setText(currentQuestion.answer1);
                ui->ans5->setText(currentQuestion.answer2);
                ui->ans6->setText(currentQuestion.answer3);
                ui->groupBox2->setTitle(QString::number(i + 1) + ". " + text);
                ui->groupBox2->setHidden(false);               
                break;
            case 2:
                ui->ans7->setText(currentQuestion.answer1);
                ui->ans8->setText(currentQuestion.answer2);
                ui->ans9->setText(currentQuestion.answer3);
                ui->groupBox3->setTitle(QString::number(i + 1) + ". " + text);
                ui->groupBox3->setHidden(false);          
                break;
        }
    }
}


void Quize::on_ans1_clicked()
{
    correctans = 1;
    if(page== 0){
        point = point + calc(correctans,0,questions);

    }else if(page == 1){
        point = point + calc(correctans,3,questions);

    }else if(page == 2){
        point = point + calc(correctans,6,questions);

    }
}


void Quize::on_ans2_clicked()
{
    correctans = 2;
    if(page== 0){
        point = point + calc(correctans,0,questions);
    }else if(page == 1){
        point = point + calc(correctans,3,questions);

    }else if(page == 2){
        point = point + calc(correctans,6,questions);

    }
}


void Quize::on_ans3_clicked()
{
    correctans = 3;
    if(page== 0){
        point = point + calc(correctans,0,questions);

    }else if(page == 1){
        point = point + calc(correctans,3,questions);

    }else if(page == 2){
        point = point + calc(correctans,6,questions);
    }
}




void Quize::on_ans4_clicked()
{
    correctans = 1;
    if(page== 0){
        point = point + calc(correctans,1,questions);
    }else if(page == 1){
        point = point + calc(correctans,4,questions);
    }
}

void Quize::on_ans5_clicked()
{
    correctans = 2;
    if(page== 0){
        point = point + calc(correctans,1,questions);
    }else if(page == 1){
        point = point + calc(correctans,4,questions);
    }
}


void Quize::on_ans6_clicked()
{
    correctans = 3;
    if(page== 0){
        point = point + calc(correctans,1,questions);
    }else if(page == 1){
        point = point + calc(correctans,4,questions);
    }
}


void Quize::on_ans7_clicked()
{
    correctans = 1;
    if(page== 0){
        point = point + calc(correctans,2,questions);
    }else if(page == 1){
        point = point + calc(correctans,5,questions);
    }
}


void Quize::on_ans8_clicked()
{
    correctans = 2;
    if(page== 0){
        point = point + calc(correctans,2,questions);
    }else if(page == 1){
        point = point + calc(correctans,5,questions);
    }
}


void Quize::on_ans9_clicked()
{
    correctans = 3;
    if(page== 0){
        point = point + calc(correctans,2,questions);
    }else if(page == 1){
        point = point + calc(correctans,5,questions);
    }
}


void Quize::on_pushButton_clicked()
{
    ui->ans1->setCheckable(false);
    ui->ans2->setCheckable(false);
    ui->ans3->setCheckable(false);
    ui->ans4->setCheckable(false);
    ui->ans5->setCheckable(false);
    ui->ans6->setCheckable(false);
    ui->ans7->setCheckable(false);
    ui->ans8->setCheckable(false);
    ui->ans9->setCheckable(false);

    ui->ans1->setCheckable(true);
    ui->ans2->setCheckable(true);
    ui->ans3->setCheckable(true);
    ui->ans4->setCheckable(true);
    ui->ans5->setCheckable(true);
    ui->ans6->setCheckable(true);
    ui->ans7->setCheckable(true);
    ui->ans8->setCheckable(true);
    ui->ans9->setCheckable(true);

    if (page < (static_cast<int>(questions.size()) + 1) / 3) {
        ++page;

        setquestions(); // Update the questions when page changes
    }
    if(page ==2){
        ui->submit->setVisible(true);
        ui->lab->setVisible(true);
        ui->points->setVisible(true);
        ui->pushButton->setDisabled(true);
    }

}


void Quize::on_submit_clicked()
{
    if (page == (static_cast<int>(questions.size()) + 1) / 3) {
        ui->points->setText(QString::number(point)+ "/7");
    }
}

void Quize::tickingtime() {
    QTimer *timer = new QTimer(this);
    QTime startTime(0, 0, 59); // Start from 02:59
    int remainingTime = startTime.msecsSinceStartOfDay() + 1000; // Add 1000 ms to ensure it starts ticking from 03:00:00
    connect(timer, &QTimer::timeout, this, [=]() mutable {
        remainingTime -= 1000; // Subtract one second
        if (remainingTime <= 0) {
            // Stop the timer when the time reaches zero
            timer->stop();
            ui->timedisplay->setText("00:00:00"); // Display 00:00:00 when time's up
            // Navigate to the last page and display the result
            page = 2;
            setquestions();
            ui->submit->setVisible(true);
            ui->lab->setVisible(true);
            ui->points->setVisible(true);
            ui->points->setText(QString::number(point)+ "/7");
            ui->ans1->setCheckable(false);
            ui->ans2->setCheckable(false);
            ui->ans3->setCheckable(false);
            ui->submit->setDisabled(true);
            ui->pushButton->setDisabled(true);
            return;
        }
        QTime currentTime = QTime::fromMSecsSinceStartOfDay(remainingTime);
        QString text = currentTime.toString("hh:mm:ss");
        ui->timedisplay->setText(text); // Update the text of the QLabel
    });
    timer->start(1000); // Start the timer with an interval of 1000 milliseconds (1 second)
}

