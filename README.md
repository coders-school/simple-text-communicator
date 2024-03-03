# simple-text-communicator
![Diagram UML](/res/diagram_uml)

### Code Guidelines

1. **Class Naming Conventions:**
   - Class names should begin with a capital letter, following CamelCase convention. For example: `DatabaseHandler`.

2. **Private Class Members:**
   - Private class members should be named with an underscore suffix. For instance, `int m_counter`.

3. **Variable Naming:**
   - Use meaningful and descriptive names for variables.
   - Follow camelCase convention for variable names.
   - Avoid single-letter names or abbreviations unless they are widely recognized.
   - Global variables should be avoided whenever possible. If needed, prefix them with "g_" for clarity.

4. **Function Naming:**
   - Use verbs or verb phrases to describe functions' actions.
   - Follow camelCase convention for function names and function arguments

5. **Comments:**
   - Use comments to explain complex algorithms, non-trivial decisions, or any code that might be unclear.
   - Comments should be clear, concise, and written in English.
   - Avoid redundant comments that merely restate the code.

6. **Indentation and Formatting:**
   - Use formatting from .clang-format(in VS code ctrl + shift + i)

7. **Error Handling:**
   - Always handle errors gracefully. Use exceptions where appropriate.
   - Use descriptive error messages for better debugging and maintenance.

8. **Memory Management:**
   - Prefer smart pointers (e.g., `std::unique_ptr`, `std::shared_ptr`) over raw pointers whenever possible.
   - Use RAII (Resource Acquisition Is Initialization) principle for resource management.

9. **Const-Correctness:**
   - Utilize `const` keyword appropriately to indicate immutability where applicable.
   - Prefer `const` references over pass-by-value for function parameters when the parameter won't be modified.

10. **Code Reusability and Modularity:**
    - Write modular and reusable code.
    - Break down complex functionalities into smaller, more manageable functions or classes.

11. **Standard Library Usage:**
    - Utilize features provided by the C++ Standard Library whenever possible rather than reinventing the wheel.

12. **Naming Conventions for Constants:**
    - Constants should be all uppercase with underscores separating words. For example: `const int MAX_SIZE = 100;`.

13. **File Organization:**
    - Each class declaration and its implementation should reside in separate header (.h) and source (.cpp) files, respectively.
    - Group related header files in a separate directory (e.g., `include`).

14. **Version Control:**
    - Utilize version control systems (e.g., Git) effectively.
    - Commit regularly with meaningful commit messages.
    - Please squash your commits before you push it to remote repository

15. **Testing:**
    - Write comprehensive unit tests to validate the correctness of the code.
    - Test edge cases and unexpected inputs.
