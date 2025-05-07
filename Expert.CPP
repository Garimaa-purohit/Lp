#include <iostream>
#include <vector>
#include <string>

using namespace std;

class EmployeeExpertSystem {
private:
    struct EmployeeRecord {
        string name;
        int score;
        string performance;
    };
    vector<EmployeeRecord> employeeRecords;
    
public:
    void evaluateEmployee() {
        cout << "\nEnter Employee Name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        
        cout << "\nEmployee Performance Review System" << endl;
        cout << "Answer the following questions about the employee (yes/no):" << endl;
        
        int score = 0;
        vector<string> questions = {
            "Does the employee meet deadlines ",
            "Does the employee work well in a team ",
            "Does the employee take initiative ",
            "Does the employee have leadership qualities ",
            "Does the employee consistently exceed expectations ",
            "Is the employee be  punctual ",
            "Does the employee adapt well to new challenges ",
            "Does the employee show strong problem-solving skills ",
            "Does the employee maintain a positive attitude ",
            "Does the employee effectively communicate with colleagues "
        };
        
        vector<string> negative_reasons;
        for (const auto& question : questions) {
            string answer;
            cout << question << "? ";
            cin >> answer;
            if (answer == "yes" || answer == "YES" || answer == "Yes" || answer == "y" || answer == "Y") { 
                score++;
            } else {
                negative_reasons.push_back("Not able to " + question.substr(17));
            }
        }
        
        string performance;
        if (score >= 9) {
            performance = "Excellent";
        } else if (score >= 6) {
            performance = "Good";
        } else if (score >= 4) {
            performance = "Average";
        } else {
            performance = "Poor";
        }
        
        employeeRecords.push_back({name, score, performance});
        
        cout << "\nFinal Evaluation: " << performance << endl;
        cout << "Reasons:" << endl;
        for (const auto& reason : negative_reasons) {
            cout << "- " << reason << endl;
        }
    }
    
    void showEmployeeRecords() {
        if (employeeRecords.empty()) {
            cout << "\nNo employee records available." << endl;
            return;
        }
        
        cout << "\nEmployee Records:" << endl;
        int excellent = 0, good = 0, average = 0, poor = 0;
        for (const auto& record : employeeRecords) {
            cout << "Name: " << record.name << ", Score: " << record.score << ", Performance: " << record.performance << endl;
            
            if (record.performance == "Excellent") excellent++;
            else if (record.performance == "Good") good++;
            else if (record.performance == "Average") average++;
            else poor++;
        }
        
        cout << "\nPerformance Statistics:" << endl;
        cout << "Excellent: " << excellent << endl;
        cout << "Good: " << good << endl;
        cout << "Average: " << average << endl;
        cout << "Poor: " << poor << endl;
    }
    
    void run() {
        while (true) {
            cout << "\nMenu:" << endl;
            cout << "1. Evaluate Employee" << endl;
            cout << "2. Show Employee Records" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                evaluateEmployee();
            } else if (choice == 2) {
                showEmployeeRecords();
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
    EmployeeExpertSystem system;
    system.run();
    return 0;
}