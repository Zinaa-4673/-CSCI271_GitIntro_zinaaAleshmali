 #include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 5;
const int COURSE_COUNT = 3;

// Function prototypes
void calculateStudent(int i, double Score[][3], double &total, double &average);
void displayAll(int n, string NameArr[], double Score[][3]);
int findTopStudent(int n, double Score[][3]);

int main()
{
    // Test data stored directly in main()
    int n = 3;
    string NameArr[MAX] = {"Alice", "Bob", "Carl"};
    double Score[MAX][3] = {
        {90, 85, 95},
        {70, 80, 75},
        {88, 92, 84}
    };

    cout << fixed << setprecision(2);

    // TODO:
    // 1. print the title
    cout << "Student Grades Report" << endl;
    cout << "=====================" << endl;

    // 2. call displayAll(...)
    displayAll(n, NameArr, Score);

    // 3. find the top student index
    int topStudentIndex = findTopStudent(n, Score);

    // 4. call calculateStudent(...) for the top student
    double topTotal, topAverage;
    calculateStudent(topStudentIndex, Score, topTotal, topAverage);

    // 5. print the top student's name and total
    cout << "Top Student: " << NameArr[topStudentIndex] << endl;
    cout << "Total Score: " << topTotal << endl;
    cout << "Average Score: " << topAverage << endl;
    return 0;
}

// Calculate total and average for one student
void calculateStudent(int i, double Score[][3], double &total, double &average)
{
    // TODO:
    // 1. calculate the total of the 3 courses for student i
    total = Score[i][0] + Score[i][1] + Score[i][2];
    // 2. calculate the average
    average = total / 3.0;
}

// Display all students' information
void displayAll(int n, string NameArr[], double Score[][3])
{
    // TODO:
    // 1. loop through each student
    for (int i = 0; i < n; i++)
    {
        // 2. call calculateStudent(...) for each student
        double total = 0.0;
        double average = 0.0;
        calculateStudent(i, Score, total, average);

        // 3. print name, 3 grades, total, and average
        cout << "Name: " << NameArr[i] << endl;
        cout << "Grades: " << " Math:"<< Score[i][0] << ", C++: " << Score[i][1] << ", OS: " << Score[i][2] << endl;
        cout << "Total: " << total << endl;
        cout << "Average: " << average << endl;
        cout << endl;
    }
}

// Find the index of the student with the highest total score
int findTopStudent(int n, double Score[][3])
{
    double highestTotal = -1.0;
    int topindex = -1;

    double total = 0.0;
    double average = 0.0;
    for (int i = 0; i < n; i++)
    {
        calculateStudent(i, Score, total, average);
        if (total > highestTotal)
        {
            highestTotal = total;
            topindex = i;
        }
    }
    return topindex;
}