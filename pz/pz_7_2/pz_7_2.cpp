#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Student {
    std::string lastName;
    int groupIndex;
    int disciplines[5];
    double averageScore;
};

// Функция для считывания информации о студентах с диска
std::vector<Student> readStudentsFromFile(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return students;
    }

    while (!file.eof()) {
        Student student;
        file >> student.lastName >> student.groupIndex;

        for (int i = 0; i < 5; ++i) {
            file >> student.disciplines[i];
        }

        file >> student.averageScore;

        students.push_back(student);
    }

    file.close();
    return students;
}

// Функция для вывода студентов, выбравших дисциплину X
void printStudentsForDiscipline(const std::vector<Student>& students, int disciplineIndex) {
    std::vector<Student> selectedStudents;

    for (const auto& student : students) {
        if (student.disciplines[disciplineIndex] == 1) {
            selectedStudents.push_back(student);
        }
    }

    // Сортировка студентов по среднему баллу в убывающем порядке
    std::sort(selectedStudents.begin(), selectedStudents.end(),
              [](const Student& a, const Student& b) { return a.averageScore > b.averageScore; });

    // Вывод не более 4 лучших студентов
    int count = std::min(4, static_cast<int>(selectedStudents.size()));
    for (int i = 0; i < count; ++i) {
        const auto& student = selectedStudents[i];
        std::cout << "Фамилия: " << student.lastName << ", Группа: " << student.groupIndex
                  << ", Средний балл: " << student.averageScore << std::endl;
    }
}

int main() {
    std::vector<Student> students = readStudentsFromFile("./pz/pz_7_2/students.txt");

    if (!students.empty()) {
        int disciplineIndex;
        std::cout << "Введите номер дисциплины (0-4): ";
        std::cin >> disciplineIndex;

        if (disciplineIndex >= 0 && disciplineIndex < 5) {
            printStudentsForDiscipline(students, disciplineIndex);
        } else {
            std::cerr << "Недопустимый номер дисциплины" << std::endl;
        }
    }

    return 0;
}
