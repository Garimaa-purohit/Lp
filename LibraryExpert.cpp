#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LibraryExpertSystem {
private:
    struct BookRecommendation {
        string genre;
        string bookTitle;
        string recommendation;
    };
    vector<BookRecommendation> recommendations;

public:
    void recommendBook() {
        cout << "\nEnter your name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        
        cout << "\nLibrary Book Recommendation System" << endl;
        cout << "Answer the following questions to get your book recommendation (yes/no):" << endl;
        
        int score = 0;
        vector<string> questions = {
            "Do you enjoy reading fiction? ",
            "Do you prefer adventure and mystery? ",
            "Are you interested in science fiction? ",
            "Do you like to read self-help books? ",
            "Do you enjoy historical fiction? ",
            "Do you prefer non-fiction books? ",
            "Are you interested in technology and innovation? ",
            "Do you enjoy philosophical discussions? ",
            "Do you like reading classic literature? ",
            "Are you a fan of thrillers and suspense? "
        };
        
        vector<string> negative_reasons;
        for (const auto& question : questions) {
            string answer;
            cout << question << "? ";
            cin >> answer;
            if (answer == "yes" || answer == "YES" || answer == "Yes" || answer == "y" || answer == "Y") { 
                score++;
            } else {
                negative_reasons.push_back("Not interested in " + question.substr(3));
            }
        }
        
        string recommendation;
        string bookTitle;
        if (score >= 8) {
            recommendation = "Highly Recommended";
            bookTitle = "The Catcher in the Rye";
        } else if (score >= 6) {
            recommendation = "Recommended";
            bookTitle = "To Kill a Mockingbird";
        } else if (score >= 4) {
            recommendation = "Maybe Consider";
            bookTitle = "The Great Gatsby";
        } else {
            recommendation = "Not Recommended";
            bookTitle = "Introduction to Programming";
        }
        
        recommendations.push_back({name, bookTitle, recommendation});
        
        cout << "\nBook Recommendation for " << name << ": " << bookTitle << endl;
        cout << "Recommendation: " << recommendation << endl;
        cout << "Reasons for Recommendation:" << endl;
        for (const auto& reason : negative_reasons) {
            cout << "- " << reason << endl;
        }
    }
    
    void showRecommendations() {
        if (recommendations.empty()) {
            cout << "\nNo book recommendations available." << endl;
            return;
        }
        
        cout << "\nBook Recommendations:" << endl;
        int highlyRecommended = 0, recommended = 0, maybeConsider = 0, notRecommended = 0;
        for (const auto& record : recommendations) {
            cout << "Name: " << record.genre << ", Book: " << record.bookTitle << ", Recommendation: " << record.recommendation << endl;
            
            if (record.recommendation == "Highly Recommended") highlyRecommended++;
            else if (record.recommendation == "Recommended") recommended++;
            else if (record.recommendation == "Maybe Consider") maybeConsider++;
            else notRecommended++;
        }
        
        cout << "\nRecommendation Statistics:" << endl;
        cout << "Highly Recommended: " << highlyRecommended << endl;
        cout << "Recommended: " << recommended << endl;
        cout << "Maybe Consider: " << maybeConsider << endl;
        cout << "Not Recommended: " << notRecommended << endl;
    }
    
    void run() {
        while (true) {
            cout << "\nMenu:" << endl;
            cout << "1. Recommend Book" << endl;
            cout << "2. Show Book Recommendations" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                recommendBook();
            } else if (choice == 2) {
                showRecommendations();
            } else if (choice == 3) {
                cout << "Exiting... Goodbye!" << endl;
                break;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main() {
    LibraryExpertSystem system;
    system.run();
    return 0;
}
