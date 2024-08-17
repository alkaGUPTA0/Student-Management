#include <iostream>
#include <string>
#include <vector>

// Structure to represent a student
struct Student {
    int id;
    std::string name;
    int age;
    char grade;
};

// Node structure for the binary tree
struct TreeNode {
    Student student;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(Student s) : student(s), left(nullptr), right(nullptr) {}
};

class StudentManagementSystem {
private:
    std::vector<Student> students;  // Array to store student information
    TreeNode *root;                 // Root of the binary tree
    
    // Function to insert a student into the binary tree
    TreeNode* insertIntoTree(TreeNode *node, Student s) {
        if (node == nullptr) {
            return new TreeNode(s);
        }
        if (s.id < node->student.id) {
            node->left = insertIntoTree(node->left, s);
        } else if (s.id > node->student.id) {
            node->right = insertIntoTree(node->right, s);
        }
        return node;
    }
    
    // Function to search for a student in the binary tree
    TreeNode* searchInTree(TreeNode *node, int id) {
        if (node == nullptr || node->student.id == id) {
            return node;
        }
        if (id < node->student.id) {
            return searchInTree(node->left, id);
        } else {
            return searchInTree(node->right, id);
        }
    }
    
    // In-order traversal of the binary tree to display all students
    void inOrderTraversal(TreeNode *node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        std::cout << "ID: " << node->student.id << ", Name: " << node->student.name 
                  << ", Age: " << node->student.age << ", Grade: " << node->student.grade << "\n";
        inOrderTraversal(node->right);
    }
    
public:
    StudentManagementSystem() : root(nullptr) {}
    
    // Add a new student
    void addStudent(int id, const std::string &name, int age, char grade) {
        Student newStudent = {id, name, age, grade};
        students.push_back(newStudent);
        root = insertIntoTree(root, newStudent);
    }
    
    // Search for a student by ID
    void searchStudent(int id) {
        TreeNode *result = searchInTree(root, id);
        if (result != nullptr) {
            std::cout << "Student found: " << result->student.name << ", Age: " << result->student.age 
                      << ", Grade: " << result->student.grade << "\n";
        } else {
            std::cout << "Student not found.\n";
        }
    }
    
    // Display all students sorted by ID
    void displayAllStudents() {
        std::cout << "All students sorted by ID:\n";
        inOrderTraversal(root);
    }
    
    // Update student information
    void updateStudent(int id, const std::string &newName, int newAge, char newGrade) {
        TreeNode *result = searchInTree(root, id);
        if (result != nullptr) {
            result->student.name = newName;
            result->student.age = newAge;
            result->student.grade = newGrade;
            std::cout << "Student information updated.\n";
        } else {
            std::cout << "Student not found.\n";
        }
    }
    
    // Remove a student by ID
    void removeStudent(int id) {
        root = removeNode(root, id);
    }

    // Function to remove a node from the binary tree
    TreeNode* removeNode(TreeNode* node, int id) {
        if (!node) return nullptr;
        if (id < node->student.id) {
            node->left = removeNode(node->left, id);
        } else if (id > node->student.id) {
            node->right = removeNode(node->right, id);
        } else {
            if (!node->left) return node->right;
            if (!node->right) return node->left;
            TreeNode* minNode = findMin(node->right);
            node->student = minNode->student;
            node->right = removeNode(node->right, minNode->student.id);
        }
        return node;
    }

    // Helper function to find the minimum node in the right subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
};

int main() {
    StudentManagementSystem sms;
    
    int choice;
    do {
        std::cout << "\nStudent Management System Menu\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Search Student by ID\n";
        std::cout << "3. Display All Students\n";
        std::cout << "4. Update Student Information\n";
        std::cout << "5. Remove Student by ID\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        int id, age;
        std::string name;
        char grade;

        switch(choice) {
            case 1:
                std::cout << "Enter Student ID: ";
                std::cin >> id;
                std::cin.ignore(); // Clear the input buffer
                std::cout << "Enter Student Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Student Age: ";
                std::cin >> age;
                std::cout << "Enter Student Grade (A-F): ";
                std::cin >> grade;
                sms.addStudent(id, name, age, grade);
                break;
            case 2:
                std::cout << "Enter Student ID to search: ";
                std::cin >> id;
                sms.searchStudent(id);
                break;
            case 3:
                sms.displayAllStudents();
                break;
            case 4:
                std::cout << "Enter Student ID to update: ";
                std::cin >> id;
                std::cin.ignore(); // Clear the input buffer
                std::cout << "Enter new name: ";
                std::getline(std::cin, name);
                std::cout << "Enter new age: ";
                std::cin >> age;
                std::cout << "Enter new grade (A-F): ";
                std::cin >> grade;
                sms.updateStudent(id, name, age, grade);
                break;
            case 5:
                std::cout << "Enter Student ID to remove: ";
                std::cin >> id;
                sms.removeStudent(id);
                break;
            case 6:
                std::cout << "Exiting the system...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}