
#include "Student.h"
#include "global.h"

int main() {


    Student student;
    student.setName("Marius");
    student.setHisGrade(5);
    student.setEngGrade(3);
    student.setMathGrade(4);
    student.calculateAvgGrade();
    student.showInfo();

    Student student1("Andrei", 3, 7, 4);
    student1.calculateAvgGrade();
    student1.showInfo();

    Student student2("George");
    student2.setMathGrade(4);
    student2.setEngGrade(10);
    student2.setHisGrade(1);
    student2.calculateAvgGrade();
    student2.showInfo();

    std::cout<<'\n';

    int result1 = compare_name(student1,student2);
    int result2 = compare_mathGrade(student1,student2);
    int result3 = compare_engGrade(student1,student2);
    int result4= compare_hisGrade(student1,student2);
    int result5 = compare_avgGrade(student1,student2);

    std::cout<<result1<<'\n'<<result2<<'\n'<<result3<<'\n'<<result4<<'\n'<<result5<<'\n';
    return 0;
}
