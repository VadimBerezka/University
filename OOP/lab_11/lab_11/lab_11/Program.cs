using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;
class C1
{
    public C1() { }
    public void method1()
    {
        Console.WriteLine("1");
    }
    public string prop { get; set; }
}
class Program
{   
    static void Main(string[] args)
    {
    // мои классы
    Reflector.SaveToFile("Student", "Student.txt");
    Reflector.SaveToFile("StringMethods", "StringMethods.txt");
    // стандартные классы
    Reflector.SaveToFile("System.Char", "Char.txt");
    Reflector.SaveToFile("System.Boolean", "Boolean.txt");

    var primer = new C1();
    string filePath = @"C:\University\OOP\lab_11\file.txt";
    Reflector.Invoke(primer, "method1", filePath);

        var ResForCreate = Reflector.Create<Student>("Вадим", "Берёзка", "Сергеевич", new DateTime(2006, 5, 17), "ул. Лупова, д. 9", "+375 29 978 05 71", "ИСИТ", 2, 3);
    Console.WriteLine($"Студент:\nимя: {ResForCreate.FirstName}, фамилия: {ResForCreate.LastName}, отчество: {ResForCreate.MiddleName}, дата рождения: {ResForCreate.BirthDate}, адресс: {ResForCreate.Address}, телефон: {ResForCreate.PhoneNumber}, курс: {ResForCreate.Course}, группа: {ResForCreate.Group}");
    }
}