using System;

class C1
{
    private const int A = 17;
    public const int B = 5;
    protected const int C = 2006;
    private bool isPrivateBoolean;
    public bool IsPublicBoolean;
    protected bool IsProtectedBoolean;
    private string PrivateStringProperty { get; set; }
    public string PublicStringProperty { get; set; }
    protected string ProtectedStringProperty { get; set; }

    public C1()
    {
        isPrivateBoolean = true;
        IsPublicBoolean = false;
        PublicStringProperty = "Изначальное значение публичного свойства";
        Console.WriteLine("Конструктор по умолчанию");
    }
    public C1(C1 source)
    {
        isPrivateBoolean = source.isPrivateBoolean;
        IsPublicBoolean = source.IsPublicBoolean;
        PublicStringProperty = source.PublicStringProperty;
        Console.WriteLine("Конструктор копирования");
    }
    public C1(bool isPrivateBoolean)
    {
        this.isPrivateBoolean = isPrivateBoolean;
        IsPublicBoolean = true;
        PublicStringProperty = "Публичное свойство с новым isPrivateBoolean";
        Console.WriteLine("Конструктор с параметром");
    }

    private void MethodPrivate()
    {
        Console.WriteLine("Приватный метод");
    }

    public void MethodPublic()
    {
        Console.WriteLine("Публичный метод");
    }

    protected void MethodProtected()
    {
        Console.WriteLine("Защищенный метод");
    }
}

interface I1
{
    int MyProperty { get; set; }
    void MyMethod();
    event EventHandler MyEvent;
    int this[int index] { get; set; }
}

class C2 : I1
{
    public int MyProperty { get; set; }

    public event EventHandler MyEvent;

    private int[] numbersArray = new int[10];
    public int this[int index]
    {
        get { return numbersArray[index]; }
        set { numbersArray[index] = value; }
    }

    private const int A = 17;
    public const int B = 5;
    protected const int C = 2006;

    private bool isPrivateBoolean;
    public bool IsPublicBoolean;
    protected bool IsProtectedBoolean;

    private string PrivateStringProperty { get; set; }
    public string PublicStringProperty { get; set; }
    protected string ProtectedStringProperty { get; set; }

    public C2()
    {
        isPrivateBoolean = true;
        IsPublicBoolean = false;
        PublicStringProperty = "Изначальное значение для публичного свойства C2";
        Console.WriteLine("Конструктор без параметров C2");
    }

    public C2(bool isPrivateBoolean)
    {
        this.isPrivateBoolean = isPrivateBoolean;
        IsPublicBoolean = true;
        PublicStringProperty = "Публичное свойство с isPrivateBoolean в C2";
        Console.WriteLine("Конструктор с параметром C2");
    }

    public C2(C2 source)
    {
        isPrivateBoolean = source.isPrivateBoolean;
        IsPublicBoolean = source.IsPublicBoolean;
        PublicStringProperty = source.PublicStringProperty;
        Console.WriteLine("Конструктор копирования C2");
    }

    public void MyMethod()
    {
        Console.WriteLine("Реализация MyMethod из интерфейса I1 в C2");
    }

    private void MethodPrivate()
    {
        Console.WriteLine("Скрытый метод C2");
    }

    public void MethodPublic()
    {
        Console.WriteLine("Общий метод C2");
    }

    protected void MethodProtected()
    {
        Console.WriteLine("Защищенный метод C2");
    }
}

class C3
{
    public string PublicField = "Общее поле для C3";
    protected string ProtectedField = "Защищенное поле C3";
    private int PrivateField = 123;

    public string PublicProperty { get; set; } = "Общее свойство C3";
    protected string ProtectedProperty { get; set; } = "Защищенное свойство C3";
    private int PrivateProperty { get; set; } = 456;

    public C3()
    {
        Console.WriteLine("Конструктор C3");
    }

    public void MethodPublic()
    {
        Console.WriteLine("Метод C3");
    }

    protected void MethodProtected()
    {
        Console.WriteLine("Защищенный метод C3");
    }

    private void MethodPrivate()
    {
        Console.WriteLine("Скрытый метод C3");
    }
}

class C4 : C3
{
    public C4()
    {
        Console.WriteLine("Конструктор C4");
    }

    public void SetProtectedField(string value)
    {
        ProtectedField = value;
        Console.WriteLine($"Защищенное поле изменено на: {ProtectedField}");
        MethodProtected();
    }

    public new void MethodPublic()
    {
        Console.WriteLine("Метод C4");
        base.MethodPublic();
    }
}

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("1 задание\n");
        C1 instance1 = new C1();
        instance1.MethodPublic();
        Console.WriteLine($"Публичное свойство: {instance1.PublicStringProperty}");

        C1 instance2 = new C1(true);
        instance2.MethodPublic();
        Console.WriteLine($"Публичное свойство: {instance2.PublicStringProperty}");

        C1 instance3 = new C1(instance2);
        instance3.MethodPublic();
        Console.WriteLine($"Публичное свойство (скопировано): {instance3.PublicStringProperty}");

        instance1.IsPublicBoolean = true;
        Console.WriteLine($"Публичный булевый: {instance1.IsPublicBoolean}");

        Console.WriteLine("\n3 задание\n");
        C2 obj1 = new C2();
        obj1.MethodPublic();
        obj1.PublicStringProperty = "Новое значение для PublicStringProperty в C2";
        Console.WriteLine($"PublicStringProperty: {obj1.PublicStringProperty}");

        obj1[0] = 200;
        Console.WriteLine($"obj1[0]: {obj1[0]}");

        obj1.MyProperty = 84;
        Console.WriteLine($"MyProperty (из I1): {obj1.MyProperty}");
        obj1.MyMethod();

        C2 obj2 = new C2(true);
        obj2.MethodPublic();
        Console.WriteLine($"PublicStringProperty: {obj2.PublicStringProperty}");

        C2 obj3 = new C2(obj1);
        obj3.MethodPublic();
        Console.WriteLine($"PublicStringProperty (скопированное значение): {obj3.PublicStringProperty}");

        Console.WriteLine("\n4 задание\n");
        C4 obj4 = new C4();

        Console.WriteLine($"Публичное поле (унаследованное): {obj4.PublicField}");
        obj4.MethodPublic();

        obj4.PublicProperty = "Новое значение для PublicProperty в C4";
        Console.WriteLine($"PublicProperty (унаследованное): {obj4.PublicProperty}");

        obj4.SetProtectedField("Новое значение для Защищенного поля");

        obj4.MethodPublic();
    }
}