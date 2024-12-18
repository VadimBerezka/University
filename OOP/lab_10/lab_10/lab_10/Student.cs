using System;

public class Student
{
    private readonly int id;
    private string firstName;
    private string lastName;
    private string middleName;
    private DateTime birthDate;
    private string address;
    private string phoneNumber;
    private string faculty;
    private int course;
    private int group;

    public string FirstName
    {
        get
        {
            return firstName;
        }
        set
        {
            if (!string.IsNullOrWhiteSpace(value))
            {
                firstName = value;
            }
        }
    }
    public string LastName
    {
        get
        {
            return lastName;
        }
        set
        {
            if (!string.IsNullOrWhiteSpace(value))
            {
                lastName = value;
            }
        }
    }
    public string MiddleName
    {
        get
        {
            return middleName;
        }
        set
        {
            middleName = value;
        }
    }
    public DateTime BirthDate
    {
        get
        {
            return birthDate;
        }
        set
        {
            birthDate = value;
        }
    }
    public string Address
    {
        get
        {
            return address;
        }
        set
        {
            address = value;
        }
    }
    public string PhoneNumber
    {
        get
        {
            return phoneNumber;
        }
        set
        {
            phoneNumber = value;
        }
    }
    public string Faculty
    {
        get
        {
            return faculty;
        }
        set
        {
            faculty = value;
        }
    }
    public int Course
    {
        get
        {
            return course;
        }
        set
        {
            course = value;
        }
    }
    public int Group
    {
        get
        {
            return group;
        }
        set
        {
            group = value;
        }
    }
    public int Id
    {
        get
        {
            return id;
        }
    }

    public Student(string firstName, string lastName, string middleName,
                   DateTime birthDate, string address, string phoneNumber,
                   string faculty, int course, int group)
    {
        FirstName = firstName;
        LastName = lastName;
        MiddleName = middleName;
        BirthDate = birthDate;
        Address = address;
        PhoneNumber = phoneNumber;
        Faculty = faculty;
        Course = course;
        Group = group;
        id = GetHashCode();
    }
}