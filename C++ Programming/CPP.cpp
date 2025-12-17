#include <iostream>
#include <fstream>
#include <string> // Added for string comparison
using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_DAYS = 30;

// Arrays
int rollNumbers[MAX_STUDENTS];
string names[MAX_STUDENTS];
int marks[MAX_STUDENTS][3];
float averages[MAX_STUDENTS];
char grades[MAX_STUDENTS];
bool attendance[MAX_STUDENTS][MAX_DAYS];

int studentCount = 0;
int totalAttendanceDays = 0;

// --------------------------------------
// NEW PASSWORD FEATURE
// --------------------------------------
bool login() {
    string password = "";
    string correctPassword = "123"; // You can change your password here
    
    cout << "\n---------------------------------";
    cout << "\nSYSTEM LOCKED: Enter Password: ";
    cin >> password;

    if (password == correctPassword) {
        cout << "Access Granted!\n";
        return true;
    } else {
        cout << "Incorrect Password! Access Denied.\n";
        return false;
    }
}

// --------------------------------------
// FUNCTIONS (ORIGINAL CODE UNCHANGED)
// --------------------------------------

char calculateGrade(float avg) {
    if (avg >= 85) return 'A';
    if (avg >= 70) return 'B';
    if (avg >= 50) return 'C';
    return 'F';
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "MAX STUDENTS LIMIT REACHED!\n";
        return;
    }

    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (rollNumbers[i] == roll) {
            cout << "Roll Number Already Exists!\n";
            return;
        }
    }

    rollNumbers[studentCount] = roll;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, names[studentCount]);

    int total = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Enter Marks in Subject " << i + 1 << ": ";
        cin >> marks[studentCount][i];

        if (marks[studentCount][i] < 0 || marks[studentCount][i] > 100) {
            cout << "Invalid Marks Entered!\n";
            return;
        }
        total += marks[studentCount][i];
    }

    averages[studentCount] = total / 3.0;
    grades[studentCount] = calculateGrade(averages[studentCount]);

    for (int d = 0; d < MAX_DAYS; d++) {
        attendance[studentCount][d] = false;
    }

    studentCount++;
    cout << "Student Added Successfully!\n";
}

void displayAll() {
    if (studentCount == 0) {
        cout << "NO STUDENTS FOUND!\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        cout << "\n---------------------------------\n";
        cout << "Name: " << names[i] << endl;
        cout << "Roll: " << rollNumbers[i] << endl;
        cout << "Marks: " << marks[i][0] << ", " << marks[i][1] << ", " << marks[i][2] << endl;
        cout << "Average: " << averages[i] << endl;
        cout << "Grade: " << grades[i] << endl;

        int present = 0;
        for (int d = 0; d < totalAttendanceDays; d++) {
            if (attendance[i][d]) present++;
        }
        float percentage = (totalAttendanceDays == 0) ? 0 : (present * 100.0 / totalAttendanceDays);

        cout << "Attendance: " << percentage << "%\n";
    }
}

int searchStudent(int roll) {
    for (int i = 0; i < studentCount; i++) {
        if (rollNumbers[i] == roll) return i;
    }
    return -1;
}

void updateMarks() {
    int roll;
    cout << "Enter Roll Number to Update: ";
    cin >> roll;

    int index = searchStudent(roll);

    if (index == -1) {
        cout << "Student Not Found!\n";
        return;
    }

    int total = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Enter New Marks for Subject " << i + 1 << ": ";
        cin >> marks[index][i];

        if (marks[index][i] < 0 || marks[index][i] > 100) {
            cout << "Invalid Marks!\n";
            return;
        }
        total += marks[index][i];
    }

    averages[index] = total / 3.0;
    grades[index] = calculateGrade(averages[index]);

    cout << "Marks Updated Successfully!\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to Delete: ";
    cin >> roll;

    int index = searchStudent(roll);

    if (index == -1) {
        cout << "Student Not Found!\n";
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        rollNumbers[i] = rollNumbers[i + 1];
        names[i] = names[i + 1];
        averages[i] = averages[i + 1];
        grades[i] = grades[i + 1];

        for (int j = 0; j < 3; j++)
            marks[i][j] = marks[i + 1][j];

        for (int d = 0; d < MAX_DAYS; d++)
            attendance[i][d] = attendance[i + 1][d];
    }

    studentCount--;
    cout << "Student Deleted Successfully!\n";
}

void topStudents() {
    if (studentCount < 3) {
        cout << "NOT ENOUGH STUDENTS!\n";
        return;
    }

    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (averages[j] < averages[j + 1]) {
                swap(rollNumbers[j], rollNumbers[j + 1]);
                swap(names[j], names[j + 1]);
                swap(averages[j], averages[j + 1]);
                swap(grades[j], grades[j + 1]);

                for (int s = 0; s < 3; s++)
                    swap(marks[j][s], marks[j + 1][s]);
            }
        }
    }

    cout << "\n=== TOP 3 STUDENTS ===\n";
    for (int i = 0; i < 3; i++) {
        cout << names[i] << " (" << rollNumbers[i] << ") - " << averages[i] << "%\n";
    }
}

void passFailSummary() {
    int A = 0, B = 0, C = 0, F = 0;

    for (int i = 0; i < studentCount; i++) {
        if (grades[i] == 'A') A++;
        else if (grades[i] == 'B') B++;
        else if (grades[i] == 'C') C++;
        else F++;
    }

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    cout << "F: " << F << endl;

    cout << "\nFailed Students:\n";
    for (int i = 0; i < studentCount; i++) {
        if (grades[i] == 'F')
            cout << names[i] << " - " << rollNumbers[i] << endl;
    }
}

void markAttendance() {
    if (totalAttendanceDays >= MAX_DAYS) {
        cout << "Attendance Days Full!\n";
        return;
    }

    cout << "\nMarking Attendance for Day " << totalAttendanceDays + 1 << endl;

    for (int i = 0; i < studentCount; i++) {
        char ch;
        cout << names[i] << " (P/A): ";
        cin >> ch;
        attendance[i][totalAttendanceDays] = (ch == 'P' || ch == 'p');
    }

    totalAttendanceDays++;
    cout << "Attendance Marked!\n";
}

void displayAttendanceStudent() {
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    int index = searchStudent(roll);

    if (index == -1) {
        cout << "Student Not Found!\n";
        return;
    }

    for (int d = 0; d < totalAttendanceDays; d++) {
        cout << "Day " << d + 1 << ": " << (attendance[index][d] ? "P" : "A") << endl;
    }
}

void attendanceReport() {
    cout << "\n=== ATTENDANCE REPORT ===\n";

    for (int i = 0; i < studentCount; i++) {
        int present = 0;
        for (int d = 0; d < totalAttendanceDays; d++)
            if (attendance[i][d]) present++;

        float percent = (totalAttendanceDays == 0) ? 0 : present * 100.0 / totalAttendanceDays;

        cout << names[i] << " - " << percent << "%";

        if (percent < 75) cout << "  (LOW ATTENDANCE)";
        cout << endl;
    }
}

void exportToFile() {
    ofstream file("Report.txt");

    for (int i = 0; i < studentCount; i++) {
        file << "Name: " << names[i] << endl;
        file << "Roll: " << rollNumbers[i] << endl;
        file << "Average: " << averages[i] << endl;
        file << "Grade: " << grades[i] << endl;

        int present = 0;
        for (int d = 0; d < totalAttendanceDays; d++)
            if (attendance[i][d]) present++;

        float percent = (totalAttendanceDays == 0) ? 0 : present * 100.0 / totalAttendanceDays;

        file << "Attendance: " << percent << "%\n";
        file << "------------------\n";
    }

    file.close();
    cout << "Report Exported Successfully!\n";
}

// --------------------------------------
// MAIN MENU
// --------------------------------------

int main() {
    // Check password before showing the menu
    if (!login()) {
        return 0; // Close the program if password is wrong
    }

    int choice;

    do {
        cout << "\n==== STUDENT MANAGEMENT SYSTEM ====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Marks\n";
        cout << "5. Delete Student\n";
        cout << "6. Top 3 Students\n";
        cout << "7. Pass/Fail Summary\n";
        cout << "8. Mark Attendance\n";
        cout << "9. Display Attendance of Student\n";
        cout << "10. Attendance Report\n";
        cout << "11. Export to File\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: {
                int roll;
                cout << "Enter Roll Number: ";
                cin >> roll;
                int index = searchStudent(roll);
                if (index == -1) cout << "Not Found!\n";
                else {
                    cout << "Name: " << names[index] << endl;
                    cout << "Avg: " << averages[index] << endl;
                    cout << "Grade: " << grades[index] << endl;
                }
            } break;
            case 4: updateMarks(); break;
            case 5: deleteStudent(); break;
            case 6: topStudents(); break;
            case 7: passFailSummary(); break;
            case 8: markAttendance(); break;
            case 9: displayAttendanceStudent(); break;
            case 10: attendanceReport(); break;
            case 11: exportToFile(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
