The Student Management system is designed to manage student records, allowing users to input, organize, and retrieve student data efficiently. The project uses an array to store basic student information and a binary tree to organize and search student records by their unique student ID.
#Features : 
1. Add New Student: Users can input student details (e.g., ID, name, age, grade) to add a student to the system.
2. Search Student by ID: Users can search for a student by their ID using the binary tree.
3. Display All Students: The system can display all students sorted by their ID.
4. Remove a Student: Users can remove a student from the system by their ID.
5. Update Student Information: Users can update the details of an existing student.
Data Structue and it's implementation :
1. Array for Student Storage:
   - Purpose: Store basic student details such as ID, name, age, and grade.
   - Working: 
     - Each entry in the array is a structure or class instance containing the details of a student.
     - The array provides direct access to the student's details and allows for operations like updating information.

2. Binary Tree for Organizing Students by ID:
   - Purpose: Organize students by their ID, enabling efficient searching and sorting.
   - Working:
     - Each node in the binary tree represents a student and contains a pointer to the corresponding entry in the array.
     - The tree is structured such that the left child contains students with lower IDs, and the right child contains students with higher IDs.
     - This structure allows for efficient search and retrieval operations.
   

