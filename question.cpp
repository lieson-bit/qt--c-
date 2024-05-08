#include "question.h"


Question::Question() {}

Question::Question(const QString& text, const QString& ans1, const QString& ans2, const QString& ans3, int correctAns)
    : text(text), answer1(ans1), answer2(ans2), answer3(ans3), correctAnswer(correctAns) {}

//std::vector<Question> questions;
std::vector<Question> loadQuestions() {

    std::vector<Question> questions;
    // Add your questions here
    Question q1 = Question("What is the capital of France?", "Rome", "Paris", "Berlin", 2);
    Question q2 = Question("Which planet is known as the Red Planet?", "Earth", "Mars", "Jupiter", 2);
    Question q3 = Question("What is the chemical symbol for water?", "H2O", "CO2", "NaCl", 1);
    Question q4 = Question("What is the tallest mammal?", "Elephant", "Giraffe", "Lion", 2);
    Question q5 = Question("Who wrote 'Romeo and Juliet'?", "William Shakespeare", "Charles Dickens", "Jane Austen", 1);
    Question q6 = Question("What is the fastest land animal?", "Cheetah", "Lion", "Elephant", 1);
    Question q7 = Question("How many continents are there in the world?", "Five", "Six", "Seven", 3);


    questions.push_back(q1);
    questions.push_back(q2);
    questions.push_back(q3);
    questions.push_back(q4);
    questions.push_back(q5);
    questions.push_back(q6);
    questions.push_back(q7);

    return questions;
}

QString fixtext(QString text){
    const int maxLineLength = 85; // Maximum characters per line
    int pos = maxLineLength;

    while (pos < text.length()) {
        // Find the nearest space before maxLineLength
        pos = text.lastIndexOf(" ", pos);
        if (pos == -1) { // No space found, insert a line break at maxLineLength
            text.insert(maxLineLength, "\n");
            pos += maxLineLength;
        } else {
            // Insert line break after the space
            text.insert(pos, "\n");
            pos += maxLineLength + 1; // Move to the next position after the line break
        }
    }
    return text;
}

int calc(int ans,int num,std::vector<Question> questions)
{
    int ad = 0;
    if(questions.at(num).correctAnswer == ans){
        ad++;
    }
    return ad;
}


