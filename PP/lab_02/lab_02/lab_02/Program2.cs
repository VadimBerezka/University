/*using System;

    public class JobVacancy { }
    public class Person { }
    public class Employee { }
    public class JobTitle { }
    public class Reason { }
    public class Department { }
    interface IStaff
    {
        List<JobVacancy> GetJobVacancies();
        List<Employee> GetEmployees();
        List<JobTitle> GetJobTitles();
        int addJobTitle();
        string printJobVacancies();
        bool delJobVacancies();
        void openJobVacancy(JobVacancy a);
        bool closeJobVacancy(int a);
        Employee recruit(JobVacancy a, Person b);
        bool dismiss(int a, Reason b);

    }
    public class Organization
    {
        public int id { get; private set; }
        public string name { get; protected set; }
        public Type shortName { get; protected set; }
        public string address { get; protected set; }
        public DateTime timeStamp { get; protected set; }
        public Organization() { }
        public Organization(Organization a) { }
        public Organization(string name, string shortName, string address)
        {
            this.name = name;
            this.address = address;
        }
        public void printInfo() { }
    }
    public class University : Organization
    {
        protected List<Faculty> faculties;
        public University() { }
        public University(University a) { }
        public University(string name, string shortName, string address) { }
        public int addFaculty(Faculty a)
        {
            return 11;
        }
        public bool delFaculty(int a)
        {
            return true;
        }
        public bool updFaculty(Faculty a)
        {
            return true;
        }
        private bool verFaculty(int a)
        {
            return true;
        }
        public List<Faculty> GetFaculties()
        {
            List<Faculty> a = new List<Faculty>();
            return a;
        }
        public void printInfo() { }
        public List<JobVacancy> GetJobVacancies()
        {
            List<JobVacancy> a = new List<JobVacancy>();
            return a;
        }
        public int addJobTitle(JobTitle a)
        {
            return 22;
        }
        public bool delJobTitle(int a)
        {
            return false;
        }
        public int openJobVacancy(JobVacancy a)
        {
            return 33;
        }
        public bool closeJobVacancy(int a)
        {
            return true;
        }
        public Employee recruit(JobVacancy a, Person b)
        {
            Employee c = new Employee();
            return c;
        }
        public void dismiss(int a, Reason b) { }
    }
    public class Faculty : Organization
    {
        protected List<Department> departments;
        public Faculty() { }
        public Faculty(Faculty a) { }
        public Faculty(string name, string shortName, string address) { }
        public int addDepartment(Department a)
        {
            return 44;
        }
        public bool delDepartment(int a)
        {
            return true;
        }
        public bool updDepartment(Department a)
        {
            return true;
        }
        private bool verDepartment(int a)
        {
            return true;
        }
        public List<Department> GetFaculties()
        {
            List<Department> a = new List<Department>();
            return a;
        }
        public void printInfo() { }
        public List<JobVacancy> GetJobVacancies()
        {
            List<JobVacancy> a = new List<JobVacancy>();
            return a;
        }
        public int addJobTitle(JobTitle a)
        {
            return 55;
        }
        public bool delJobTitle(int a)
        {
            return false;
        }
        public int openJobVacancy(JobVacancy a)
        {
            return 66;
        }
        public bool closeJobVacancy(int a)
        {
            return true;
        }
        public Employee recruit(JobVacancy a, Person b)
        {
            Employee c = new Employee();
            return c;
        }
        public void dismiss(int a, Reason b) { }

    }

    internal class Program
    {
        static void Main(string[] args)
        {

        University university = new University("Белорусский государственный технологический университет", "БГТУ", "Свердлова 13А");
        university.printInfo();

        Faculty faculty = new Faculty("Инженерный факультет", "ИФ", "456 Инженерный проспект");
        faculty.printInfo();

        university.addFaculty(faculty);

        Department department = new Department();
        faculty.addDepartment(department);

        JobVacancy jobVacancy = new JobVacancy();
        university.openJobVacancy(jobVacancy);

        Person person = new Person();
        Employee newEmployee = university.recruit(jobVacancy, person);
        Console.WriteLine("Новый сотрудник нанят!");

        List<JobVacancy> vacancies = university.GetJobVacancies();
        Console.WriteLine($"Текущие вакансии: {vacancies.Count}");
    }
    }*/