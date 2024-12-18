using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    static void Main()
    {
        string[] months = {
            "June", "July", "May",
            "December", "January", "February",
            "March", "April", "August",
            "September", "October", "November" 
        };

        MonthQueries monthQueries = new(months);
        monthQueries.MonthsWithLength(7);
        monthQueries.SummerAndWinterMonths();
        monthQueries.SortedMonths();
        monthQueries.MonthsWithU();

        List<Student> students = new()
        {
            new Student("Александр", "Смирнов", "Александрович", new DateTime(1999, 1, 20), "ул. Невского, д. 12", "+7 (123) 321-4567", "ИСИТ", 3, 1),
            new Student("Екатерина", "Васильева", "Дмитриевна", new DateTime(2002, 6, 15), "пр. Ленина, д. 8", "+7 (987) 654-3210", "ПИ", 2, 6),
            new Student("Сергей", "Петров", "Иванович", new DateTime(2001, 3, 5), "ул. Центральная, д. 25", "+7 (555) 111-2222", "ЦД", 4, 4),
            new Student("Мария", "Кузнецова", "Анатольевна", new DateTime(1998, 10, 30), "ул. Солнечная, д. 7", "+7 (999) 876-5432", "ИСИТ", 1, 2),
            new Student("Дмитрий", "Сидоров", "Сергеевич", new DateTime(2000, 11, 1), "ул. Победы, д. 15", "+7 (777) 333-4444", "ПИ", 3, 7),
            new Student("Анна", "Федорова", "Петровна", new DateTime(1997, 4, 18), "пр. Гагарина, д. 12", "+7 (111) 222-3333", "ЦД", 4, 5),
            new Student("Павел", "Ковалев", "Александрович", new DateTime(2003, 8, 12), "пр. Мира, д. 10", "+7 (555) 555-5555", "ИСИТ", 1, 1),
            new Student("Ольга", "Дмитриева", "Анатольевна", new DateTime(1999, 5, 7), "ул. Лесная, д. 3", "+7 (444) 777-8888", "ПИ", 2, 7),
            new Student("Игорь", "Тимошенко", "Игоревич", new DateTime(2001, 12, 25), "пр. Пушкина, д. 22", "+7 (666) 999-0000", "ЦД", 2, 4),
            new Student("Наталья", "Захарова", "Николаевна", new DateTime(1998, 7, 3), "ул. Космическая, д. 8", "+7 (555) 999-1111", "ИСИТ", 4, 3),
            new Student("Ирина", "Белова", "Станиславовна", new DateTime(2000, 2, 12), "ул. Ленина, д. 20", "+7 (123) 456-7890", "ПИ", 3, 7),
            new Student("Виктор", "Соловьев", "Анатольевич", new DateTime(1999, 4, 22), "пр. Мира, д. 14", "+7 (987) 654-3211", "ЦД", 2, 4),
            new Student("Елизавета", "Кириллова", "Арсеньевна", new DateTime(2001, 11, 30), "ул. Солнечная, д. 9", "+7 (555) 777-8888", "ПИ", 4, 8),
            new Student("Андрей", "Громов", "Николаевич", new DateTime(2002, 8, 15), "пр. Ленина, д. 23", "+7 (444) 888-9999", "ПИ", 1, 7),
            new Student("Татьяна", "Сидорова", "Викторовна", new DateTime(1997, 3, 28), "ул. Победы, д. 17", "+7 (111) 222-4444", "ПИ", 2, 7),
            new Student("Максим", "Яковлев", "Сергеевич", new DateTime(2003, 5, 4), "ул. Лесная, д. 11", "+7 (222) 333-5555", "ПИ", 3, 7),
            new Student("Оксана", "Морозова", "Юрьевна", new DateTime(1998, 9, 19), "пр. Гагарина, д. 6", "+7 (333) 444-6666", "ЦД", 4, 4),
            new Student("Роман", "Никитин", "Денисович", new DateTime(2000, 12, 1), "ул. Центральная, д. 5", "+7 (444) 555-7777", "ЦД", 1, 4),
            new Student("Светлана", "Романова", "Александровна", new DateTime(2002, 10, 10), "ул. Невского, д. 18", "+7 (555) 666-8888", "ИСИТ", 3, 3)
        };

        string specialty = "ИСИТ";
        var studentsInSpecialty = students.Where(s => s.Faculty == specialty).OrderBy(s => s.LastName);
        Console.WriteLine($"список студентов по алфавиту, учащихся на факультете {specialty}:");
        PrintStudents(studentsInSpecialty);

        string faculty = "ПИ";
        int groupNumber = 7;
        var studentsInGroup = students.Where(s => s.Faculty == faculty && s.Group == groupNumber);
        Console.WriteLine($"\nсписок студентов из группы {groupNumber} на факультете {faculty}:");
        PrintStudents(studentsInGroup);

        var youngestStudent = students.OrderBy(s => s.BirthDate).First();
        Console.WriteLine($"\nсамый молодой студент: {youngestStudent.FirstName} {youngestStudent.LastName}");

        int targetGroup = 2;
        var studentsInTargetGroup = students.Where(s => s.Group == targetGroup).OrderBy(s => s.LastName);
        Console.WriteLine($"\nколичество студентов в группе {targetGroup} их фамилии упорядочены:");
        PrintStudents(studentsInTargetGroup);

        string searchName = "Вадим";
        var firstStudent = students.FirstOrDefault(s => s.FirstName == searchName);
        if (firstStudent != null)
        {
            Console.WriteLine($"\nпервый студент с именем {searchName}: {firstStudent.FirstName} {firstStudent.LastName}");
        }
        else
        {
            Console.WriteLine($"\nстудент с именем {searchName} не найден.");
        }


        var customQuery = students
            .Where(student => student.Course <= 2)
            .OrderBy(student => student.Course)
            .Skip(5)
            .Select(student => new { student.FirstName, student.LastName })
            .Count();
        Console.WriteLine($"\nпользовательский запрос: {customQuery}");


        var joinQueryResult = students
            .Where(s => s.LastName.StartsWith("Г"))
            .Join(students,
                  student => student.Id,
                  otherStudent => otherStudent.Id,
                  (student, otherStudent) => new { student.FirstName, student.LastName,otherStudent.Course, otherStudent.Group });

        Console.WriteLine("\nзапрос с Join:");
        foreach (var result in joinQueryResult)
        {
            Console.WriteLine($"{result.FirstName} {result.LastName}, курс: {result.Course}, группа: {result.Group}");
        }
    }

    static void PrintStudents(IEnumerable<Student> students)
    {
        foreach (var student in students)
        {
            Console.WriteLine($"{student.FirstName} {student.LastName} {student.MiddleName}");
        }
    }
}