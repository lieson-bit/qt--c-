#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <vector>

class Question
{
public:
    QString text;
    QString answer1;
    QString answer2;
    QString answer3;
    int correctAnswer;

    Question();
    Question(const QString& text, const QString& ans1, const QString& ans2, const QString& ans3, int correctAns);
};

std::vector<Question> loadQuestions();
QString fixtext(QString text);
int calc(int,int,std::vector<Question> questions);

#endif // QUESTION_H
