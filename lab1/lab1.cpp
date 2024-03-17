//Task 1
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int summation(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int maximum(const vector<int>& arr) {
    int max = arr.empty() ? INT_MIN : arr[0];
    for (int num : arr) {
        if (num > max) max = num;
    }
    return max;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Summation: " << summation(arr) << endl;
    cout << "Maximum: " << maximum(arr) << endl;

    return 0;
}








//Task 2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Course {
    string course_code;
    string course_name;
};

struct Grade {
    int mark;
    char the_grade;

    void calculateGrade() {
        if (mark > 69) the_grade = 'A';
        else if (mark > 59) the_grade = 'B';
        else if (mark > 49) the_grade = 'C';
        else if (mark > 39) the_grade = 'D';
        else the_grade = 'E';
    }
};

struct Student {
    string registration_number;
    string name;
    int age;
    Course course;
    Grade grade;
};

void addStudent(vector<Student>& students) {
    if (students.size() >= 40) {
        cout << "Maximum number of students reached." << endl;
        return;
    }

    Student new_student;
    cout << "Enter registration number: ";
    cin >> new_student.registration_number;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, new_student.name);
    cout << "Enter age: ";
    cin >> new_student.age;
    cout << "Enter course code: ";
    cin >> new_student.course.course_code;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, new_student.course.course_name);
    cout << "Enter mark: ";
    cin >> new_student.grade.mark;
    new_student.grade.calculateGrade();

    students.push_back(new_student);
    cout << "Student added successfully." << endl;
}

void editStudent(vector<Student>& students, const string& reg_no) {
    for (Student& student : students) {
        if (student.registration_number == reg_no) {
            cout << "Editing student: " << reg_no << endl;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, student.name);
            cout << "Enter new age: ";
            cin >> student.age;
            cout << "Student details updated." << endl;
            return;
        }
    }
    cout << "Student with registration number " << reg_no << " not found." << endl;
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to display." << endl;
        return;
    }

    for (const Student& student : students) {
        cout << "Registration Number: " << student.registration_number << endl;
        cout << "Name: " << student.name << endl;
        cout << "Age: " << student.age << endl;
        cout << "Course Code: " << student.course.course_code << endl;
        cout << "Course Name: " << student.course.course_name << endl;
        cout << "Mark: " << student.grade.mark << endl;
        cout << "Grade: " << student.grade.the_grade << endl;
        cout << "---------------------------------" << endl;
    }
}

int main() {
    vector<Student> students;
    int choice;
    string reg_no;

    do {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Edit Student" << endl;
        cout << "3. Display All Students" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                cout << "Enter Registration Number of the student to edit: ";
                cin >> reg_no;
                editStudent(students, reg_no);
                break;
            case 3:
                displayStudents(students);
                break;
            case 4:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


//Abstract data types list 
std::stack  -A Stack is a collection that follows the Last-In-First-Out (LIFO) principle. The last element added to the stack will be the first one to be removed.

#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    while (!stack.empty()) {
        std::cout << stack.top() << std::endl; 
        stack.pop(); // Remove the top element
    }

    return 0;
}
std::queue  -A Queue is a collection that follows the First-In-First-Out (FIFO) principle. The first element added to the queue will be the first one to be removed.
#include <iostream>
#include <queue>

int main() {
    std::queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    while (!queue.empty()) {
        std::cout << queue.front() << std::endl; // Show the front element
        queue.pop(); // Remove the front element
    }

    return 0;
}
std::map  -A Map is a collection of key-value pairs with unique keys

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> map;

    // Insert key-value pairs
    map["apple"] = 5;
    map["banana"] = 8;
    map["orange"] = 3;

    // iterate over elements
    for (const auto &pair : map) {
        std::cout << pair.first << " has value " << pair.second << std::endl;
    }

    return 0;
}

std::vector -Represents a sequence of elements

#include <iostream>
#include <vector>

int main() {
    // Declare a vector of integers
    std::vector<int> vec;

    // Add elements to the vector
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    
    std::cout << "Element at index 1: " << vec[1] << std::endl;

    // Iterate over the vector and print elements
    std::cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Using range-based for loop
    std::cout << "Using range-based for loop: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

