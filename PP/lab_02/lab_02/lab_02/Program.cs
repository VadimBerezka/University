using System;

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
    public class Organization : IStaff
    {
        public List<JobVacancy> GetJobVacancies()
        {
            List<JobVacancy> a = new List<JobVacancy>();
            return a;
        }
        public List<Employee> GetEmployees()
        {
            List<Employee> a = new List<Employee>();
            return a;
        }
        public List<JobTitle> GetJobTitles()
        {
            List<JobTitle> a = new List<JobTitle>(); return a;
        }

        public int addJobTitle()
        {
            return 17;
        }
        public string printJobVacancies()
        {
            return "111";
        }
        public bool delJobVacancies()
        {
            return true;
        }
        public void openJobVacancy(JobVacancy a) { }
        public bool closeJobVacancy(int a)
        {
            return true;
        }
        public Employee recruit(JobVacancy a, Person b)
        {
            Employee f = new Employee();
            return f;
        }
        public bool dismiss(int a, Reason b)
        {
            return true;
        }
        public int id { get; private set; }
        public string name { get; protected set; }
        public string shortName { get; protected set; }
        public string address { get; protected set; }
        public DateTime timeStamp { get; protected set; }
        public Organization() { }
        public Organization(Organization a) { }
        public Organization(string name, string shortName, string address)
        {
            this.name = name;
            this.shortName = shortName;
            this.address = address;
        }
        public void printInfo() { }
    }
    public class University : Organization, IStaff
    {
        protected List<Faculty> faculties;
        public University() { }
        public University(University a) { }
        public University(string name, string shortName, string address)
        {
            this.name = name;
            this.shortName = shortName;
            this.address = address;
        }
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
        public int addJobTitle(JobTitle a)
        {
            return 1000;
        }
        public bool delJobTitle(int a)
        {
            return false;
        }

    }
    public class Faculty : Organization, IStaff
    {
        protected List<Department> departments;
        public Faculty() { }
        public Faculty(Faculty a) { }
        public Faculty(string name, string shortName, string address)
        {
            this.name = name;
            this.shortName = shortName;
            this.address = address;
        }
        public int addDepartment(Department a)
        {
            return 11;
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
        public int addJobTitle(JobTitle a)
        {
            return 111;
        }
        public bool delJobTitle(int a)
        {
            return false;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {

        Organization org = new Organization("Яндекс", "YNDX", "ул. Льва Толстого 16");
        Console.WriteLine($"Организация: {org.name}, Краткое название: {org.shortName}, Адрес: {org.address}");

        University university = new University("Белорусский государственный технологический университет", "БГТУ", "ул. Свердлова 13А");
        Console.WriteLine($"Университет: {university.name}, Адрес: {university.address}");

        Faculty faculty = new Faculty("Компьютерные науки", "КС", "Корпус А");
        Console.WriteLine($"Факультет: {faculty.name}, Адрес: {faculty.address}");

        var jobVacancy = new JobVacancy();
        university.openJobVacancy(jobVacancy);
        Console.WriteLine("Вакансия открыта в Университете.");

        var employee = university.recruit(jobVacancy, new Person());
        Console.WriteLine("Сотрудник нанят в Университете.");

        faculty.openJobVacancy(jobVacancy);
        Console.WriteLine("Вакансия открыта на Факультете.");
    }
    }