// ===========================================
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    string Major;
    string Hobby;
    double GPA;
    string email;
    string city;
};
// CSCI 271 Write all students to file
void saveToFile(Student s[], int n, const string& filename) {
    ofstream outFile(filename);
    if (outFile.fail()) {
        cout << "Error:  open file for writing " << filename << endl;
        return;
    }
    cout << "[1] Saving data to " << filename << " ..." << endl;

    for (int i = 0; i < n; i++) {
        outFile << s[i].id << " " << s[i].name << " "<< s[i].Major << " " << s[i].Hobby << " " << s[i].GPA << " " << s[i].email << " " << s[i].city << endl;
    }
    outFile.close();
}

int loadFromFile(Student s[], const string& filename) {
    ifstream inFile(filename);
    if (inFile.fail()) {
        cout << "Error: open file for reading " << filename << endl;
        return 0;
    }
    cout << "[2] Loading data from " << filename << " ..." << endl;

    int n = 0;
    while (inFile >> s[n].id >> s[n].name >> s[n].Major >> s[n].Hobby >> s[n].GPA >> s[n].email >> s[n].city) {
        n++;
    }
    inFile.close();
    return n;
}
// Step 3 Display all students
void displayAll(Student s[], int n) {
// TODO: Loop through all students and print formatted info
cout << "[3] Displaying all students:" << endl;
for(int i = 0; i < n; i++) {
    cout << s[i].id << " " << s[i].name << " " << s[i].Major << " " << s[i].city << " " << s[i].GPA << endl;
}
}
void countHighGPA (Student s[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].GPA > 3.5) {
            count++;
        }
    }
    cout << "[4] Number of students with GPA > 3.5: " << count << endl;
}
// Step 5 Query by city
void queryByCity(Student s[], int n, const string& city) {
    cout << "[5] Querying students from " << city << ":" << endl;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s[i].city == city) {
            cout << s[i].id << " " << s[i].name << " " << s[i].Major << " " << s[i].city << " " << s[i].GPA << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found in that city." << endl;
    }
}
// =======================
// Main Function
// =======================
int main() {
    Student students[100];
int n = 3;
// Step 1 Write to file
students [0]= Student {"S01", "Tom", "Math", "Football", 2.8, "tom@google.com", "Modesto"};
students [1]= Student {"S02", "Alice", "CS", "Reading", 3.5, "alice@google.com", "Modesto"};
students [2]= Student {"S03", "Scott", "CS", "Basketball", 3.2, "scott@google.com", "SanJose"};
saveToFile(students, n, "students.txt");
Student loaded[100];
int count = loadFromFile(loaded, "students.txt");
displayAll(loaded, count);
countHighGPA(loaded, count);
queryByCity(loaded, count, "Modesto");
cout << "\nProgram finished." << endl;
 return 0; 
}