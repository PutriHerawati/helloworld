#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract Class (Base Class for all questions)
class QuizQuestion {
public:
    // Pure Virtual Functions
    virtual void displayQuestion() = 0;
    virtual bool checkAnswer(char userChoice) = 0;
};

// Derived Class for Multiple Choice Questions
class AnimalQuestion : public QuizQuestion {
private:
    string questionText;
    vector<string> options;
    char correctAnswer;

public:
    AnimalQuestion(string qText, vector<string> opts, char ans) {
        questionText = qText;
        options = opts;
        correctAnswer = ans;
    }

    void displayQuestion() override {
        cout << "\n" << questionText << endl;
        for (const string& option : options) {
            cout << option << endl;
        }
        cout << "Your Answer (A/B/C/D): ";
    }

    bool checkAnswer(char userChoice) override {
        // Convert input to uppercase just in case
        return (toupper(userChoice) == correctAnswer);
    }
};

int main() {
    cout << "=== OOP ANIMAL QUIZ GAME ===" << endl;
    cout << "----------------------------" << endl;

    // Creating quiz questions using Base Class pointers (Polymorphism)
    vector<QuizQuestion*> quiz;

    quiz.push_back(new AnimalQuestion(
        "1. Which animal is known as the King of the Jungle?",
        {"A. Tiger", "B. Lion", "C. Elephant", "D. Cheetah"},
        'B'
    ));

    quiz.push_back(new AnimalQuestion(
        "2. What is the largest mammal in the world?",
        {"A. Elephant", "B. Blue Whale", "C. Giraffe", "D. Shark"},
        'B'
    ));

    quiz.push_back(new AnimalQuestion(
        "3. Which bird is faster on land than it is in flight?",
        {"A. Ostrich", "B. Eagle", "C. Penguin", "D. Owl"},
        'A'
    ));

    int score = 0;
    char answer;

    // Loop through the quiz questions polymorphically
    for (QuizQuestion* question : quiz) {
        question->displayQuestion();
        cin >> answer;

        if (question->checkAnswer(answer)) {
            cout << "Correct! Great job." << endl;
            score++;
        } else {
            cout << "Incorrect! Better luck next time." << endl;
        }
        cout << "----------------------------" << endl;
    }

    // Display final score
    cout << "\n=== QUIZ OVER ===" << endl;
    cout << "Your Final Score: " << score << " / " << quiz.size() << endl;
    cout << "Thank you for playing Animal Quiz!" << endl;

    // Cleaning up dynamically allocated memory
    for (QuizQuestion* question : quiz) {
        delete question;
    }

    return 0;
}
