using System;
using System.Diagnostics;

public enum VehicleType
{
    Car,
    Transformer
}

// для 1
public class ArmyException : Exception
{
    public ArmyException(string message) : base(message) { }
}
public class HumanNotFoundException : ArmyException
{
    public HumanNotFoundException(string message) : base(message) { }
}
public class TransformerNotFoundException : ArmyException
{
    public TransformerNotFoundException(string message) : base(message) { }
}
public class InvalidHorsePowerException : ArmyException
{
    public InvalidHorsePowerException(string message) : base(message) { }
}
//для 2 
public class InvalidDataException : Exception
{
    public InvalidDataException(string message) : base(message) { }
}
public class InvalidYearException : Exception
{
    public InvalidYearException(string message) : base(message) { }
}
public class EmptyTransformerException : Exception
{
    public EmptyTransformerException(string message) : base(message) { }
}
// для 5
public class CustomException : Exception
{
    public CustomException(string message) : base(message) { }
}


public struct Dimensions
{
    public float Length { get; }
    public float Width { get; }
    public float Height { get; }
    public Dimensions(float length, float width, float height)
    {
        Length = length;
        Width = width;
        Height = height;
    }

    public override string ToString()
    {
        return $"Размеры: {Length}м x {Width}м x {Height}м";
    }
}

public interface IDriveable
{
    void Start();
    void Stop();
    bool DoDrive(); // ex4
}

public abstract class AbstractVehicle : IDriveable
{
    private string brand;
    private string model;
    private Engine engine;

    public Dimensions VehicleDimensions { get; }

    public string Brand
    {
        get
        {
            return brand;
        }
        set
        {
            brand = value;
        }
    }

    public string Model
    {
        get
        {
            return model;
        }
        set
        {
            model = value;
        }
    }

    public Engine Engine
    {
        get
        {
            return engine;
        }
        set
        {
            engine = value;
        }
    }

    protected AbstractVehicle(string brand, string model, Engine engine, Dimensions dimensions)
    {
        Brand = brand;
        Model = model;
        Engine = engine;
        VehicleDimensions = dimensions;
    }

    public abstract void Start();
    public abstract void Stop();
    public abstract bool DoDrive(); // ex4

    public override string ToString()
    {
        return $"{GetType().Name}: {Brand} {Model}, {Engine}, {VehicleDimensions}";
    }
}

public class CarControl
{
    public void Accelerate()
    {
        /* Console.WriteLine("ускоряемся"); */
    }

    public void Brake()
    {
        /* Console.WriteLine("сломалась"); */
    }
}

public class Engine
{
    private int horsePower;

    public int HorsePower
    {
        get
        {
            return horsePower;
        }
        set
        {
            horsePower = value;
        }
    }

    public Engine(int horsePower)
    {
        if (horsePower <= 0)
        {
            throw new InvalidHorsePowerException("Мощность должна быть положительной.");
        }
        HorsePower = horsePower;
    }

    public override string ToString()
    {
        return $"{HorsePower} лошадок";
    }
}

public class IntelligentBeing : ICloneable
{
    private string name;

    public string Name
    {
        get
        {
            return name;
        }
        set
        {
            name = value;
        }
    }

    public IntelligentBeing(string name)
    {
        Name = name;
    }

    public virtual void Speak()
    {
        Console.WriteLine($"{Name} говорит");
    }

    public override string ToString()
    {
        return $"человек: {Name}";
    }

    public object Clone()
    {
        return new IntelligentBeing(Name);
    }
}

public class Human : IntelligentBeing, IComparable, ICloneable
{
    public int YearOfBirth { get; set; }
    public Human(string name, int yearOfBirth) : base(name)
    {
        if (string.IsNullOrWhiteSpace(name))
        {
            throw new InvalidDataException("Имя не может быть пустым.");
        }

        if (yearOfBirth <= 0)
        {
            throw new InvalidYearException("Год рождения должен быть положительным.");
        }

        YearOfBirth = yearOfBirth;
    }
    public override void Speak()
    {
        Console.WriteLine($"{Name} передает привет");
    }

    public override string ToString()
    {
        return base.ToString() + $", год рождения: {YearOfBirth}";
    }

    public int CompareTo(object obj)
    {
        if (obj is Human other)
        {
            return YearOfBirth.CompareTo(other.YearOfBirth);
        }
        throw new ArgumentException("ошибка.");
    }

    public object Clone()
    {
        return new Human(Name, YearOfBirth);
    }
}

public class Transformer : AbstractVehicle, IComparable, ICloneable
{
    public Transformer(string brand, string model, Engine engine, Dimensions dimensions)
        : base(brand, model, engine, dimensions)
    {
        if (string.IsNullOrWhiteSpace(brand))
        {
            throw new InvalidDataException("Имя бренда не может быть пустым.");
        }

        // Проверка на пустую модель
        if (string.IsNullOrWhiteSpace(model))
        {
            throw new InvalidDataException("Модель не может быть пустой.");
        }

        // Проверка на недопустимую мощность двигателя
        if (engine.HorsePower <= 0)
        {
            throw new InvalidHorsePowerException("Мощность двигателя должна быть положительной.");
        }
    }
    public override void Start()
    {
        Console.WriteLine($"{Brand} {Model} стартует");
    }

    public override void Stop()
    {
        Console.WriteLine($"{Brand} {Model} стоп");
    }

    public override bool DoDrive()
    {
        Console.WriteLine($"{Brand} {Model} поехали");
        return true;
    }

    public void Transform()
    {
        Console.WriteLine($"{Brand} {Model} трансформируется");
    }

    public override string ToString()
    {
        return base.ToString() + " автобот";
    }

    public int CompareTo(object obj)
    {
        if (obj is Transformer other)
        {
            return Engine.HorsePower.CompareTo(other.Engine.HorsePower);
        }
        throw new ArgumentException("ошибка");
    }

    public object Clone()
    {
        return new Transformer(Brand, Model, new Engine(Engine.HorsePower), VehicleDimensions);
    }
}

public class Army
{
    private List<IntelligentBeing> humans;
    private List<AbstractVehicle> transformers;

    public Army()
    {
        humans = new List<IntelligentBeing>();
        transformers = new List<AbstractVehicle>();
    }

    public void AddHuman(Human human)
    {
        humans.Add(human);
    }

    public void AddTransformer(Transformer transformer)
    {
        transformers.Add(transformer);
    }

    public List<IntelligentBeing> FindHumansByYear(int year)
    {
        List<IntelligentBeing> foundHumans = new List<IntelligentBeing>();

        foreach (var being in humans)
        {
            if (being is Human human && human.YearOfBirth == year)
            {
                foundHumans.Add(human);
            }
        }

        if (foundHumans.Count == 0)
        {
            throw new HumanNotFoundException($"Не найдено людей, рожденных в {year} году.");
        }

        return foundHumans;
    }

    public List<Transformer> GetTransformersByHorsePower(int horsePower)
    {
        List<Transformer> foundTransformers = new List<Transformer>();

        foreach (var vehicle in transformers)
        {
            if (vehicle is Transformer transformer && transformer.Engine.HorsePower == horsePower)
            {
                foundTransformers.Add(transformer);
            }
        }

        if (foundTransformers.Count == 0)
        {
            throw new TransformerNotFoundException($"Не найдено трансформеров с мощностью {horsePower} л.с.");
        }

        return foundTransformers;
    }

    public void ValidateHorsePower(int horsePower)
    {
        if (horsePower < 0)
        {
            throw new InvalidHorsePowerException("Мощность не может быть отрицательной.");
        }
    }

    public int CountCombatUnits()
    {
        return humans.Count + transformers.Count;
    }

    public void DisplayUnits()
    {
        foreach (var human in humans)
        {
            Console.WriteLine(human.ToString());
        }
        foreach (var transformer in transformers)
        {
            Console.WriteLine(transformer.ToString());
        }
    }
}

public class Controller
{
    private Army army;

    public Controller()
    {
        army = new Army();
    }

    public void AddHuman(Human human)
    {
        army.AddHuman(human);
    }

    public void AddTransformer(Transformer transformer)
    {
        army.AddTransformer(transformer);
    }

    public void DisplayUnits()
    {
        army.DisplayUnits();
    }

    public void FindHumansByYear(int year)
    {
        var foundHumans = army.FindHumansByYear(year);
        Console.WriteLine($"\nчелы, рожденные в {year}:");
        foreach (var human in foundHumans)
        {
            Console.WriteLine(human.ToString());
        }
    }

    public void GetTransformersByHorsePower(int horsePower)
    {
        var transformers = army.GetTransformersByHorsePower(horsePower);
        Console.WriteLine($"\nТрансформеры с мощностью {horsePower} л.с.:");
        foreach (var transformer in transformers)
        {
            Console.WriteLine(transformer.ToString());
        }
    }

    public void CountCombatUnits()
    {
        Console.WriteLine($"\nв армии: {army.CountCombatUnits()}");
    }
}

public class Printer
{
    public void IAmPrinting(IDriveable someObj)
    {
        Console.WriteLine(someObj.ToString());
    }
}

class Program
{
    static void Main(string[] args)
    {
        Controller controller = new Controller();

        try
        {
            controller.AddHuman(new Human("Вадим", 2006));
            controller.AddHuman(new Human("Алексей", 2006));
            controller.AddHuman(new Human("ВладиSLAVE", 2005));
            controller.AddHuman(new Human("SEMEN", 2005));
            controller.AddHuman(new Human("тайская женщина", 1999));
        }
        catch (InvalidDataException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (InvalidYearException ex)
        {
            Console.WriteLine(ex.Message);
        }

        try
        {
            Engine engine1 = new Engine(1000);
            Dimensions carDimensions1 = new Dimensions(17, 5, 20);
            controller.AddTransformer(new Transformer("Nissan", "Skyline", engine1, carDimensions1));

            Engine engine2 = new Engine(800);
            Dimensions carDimensions2 = new Dimensions(13, 15, 6);
            controller.AddTransformer(new Transformer("Bumblebee", "Chevrolet Camaro", engine2, carDimensions2));

            Engine engine3 = new Engine(10000);
            Dimensions carDimensions3 = new Dimensions(5, 5, 5);
            controller.AddTransformer(new Transformer("Optimus", "Prime", engine3, carDimensions3));
        }
        catch (InvalidHorsePowerException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (EmptyTransformerException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (InvalidDataException ex)
        {
            Console.WriteLine(ex.Message);
        }

        // ex1
        try
        {
            controller.DisplayUnits();
            controller.FindHumansByYear(2005);
            controller.FindHumansByYear(1998);
            controller.GetTransformersByHorsePower(1000);
            controller.GetTransformersByHorsePower(10000);
            controller.CountCombatUnits();
        }
        catch (HumanNotFoundException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (TransformerNotFoundException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (InvalidHorsePowerException ex)
        {
            Console.WriteLine(ex.Message);
        }
        // универсальный и финальный
        catch (Exception ex)
        {
            Console.WriteLine($"Произошла ошибка: {ex.Message}");
        }
        finally
        {
            Console.WriteLine("Завершение\n");
        }

        // ex2
        try
        {
            // Исключение для человека (имя, год)
            controller.AddHuman(new Human("", -1));
        }
        catch (InvalidDataException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (InvalidYearException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Произошла ошибка: {ex.Message}");
        }
        finally
        {
            Console.WriteLine("Завершение обработки исключений для человеков\n");
        }

        try
        {
            // Исключение для трансформеров (мощность, бренд, модель)
            Engine engine = new Engine(-150);
            Dimensions dimensions = new Dimensions(2.5f, 1.5f, 1.0f);
            Transformer transformer = new Transformer("1", "1", engine, dimensions);
            controller.AddTransformer(transformer);
        }
        catch (EmptyTransformerException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (InvalidHorsePowerException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (InvalidDataException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Произошла ошибка: {ex.Message}");
        }
        finally
        {
            Console.WriteLine("Завершение обработки исключений для трансформеров\n");
        }


        try
        {
            int nVar = 0;
            int result = 17 / nVar;
        }
        catch (DivideByZeroException ex)
        {
            Console.WriteLine($"Ошибка деления на ноль: {ex.Message}\n");
        }

        try
        {
            int[] numbers = { 1, 2 };
            Console.WriteLine(numbers[2]);
        }
        catch (IndexOutOfRangeException ex)
        {
            Console.WriteLine($"Ошибка индекса массива: {ex.Message}\n");
        }
        // ex 7
        try
        {
            TestAssert(1);
            TestAssert(2);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }
        catch
        {
            Console.WriteLine("Ошибка");
        }
        finally
        {
            Console.WriteLine("Завершение");
        }
        // ex5-6
        try
        {
            MethodA();
            MethodB();
        }
        catch (CustomException ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
            Console.WriteLine("Диагностика: произошла ошибка в пользовательском методе");
            throw;
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Необработанная ошибка: {ex.Message}");
            Console.WriteLine("Диагностика: произошла ошибка в системе");
        }
        finally
        {
            Console.WriteLine("Завершение");
        }
        
    }
    static void TestAssert(int value)
    {
        Debug.Assert(value >= 0, "Значение должно быть неотрицательным.");
        Console.WriteLine($"Значение: {value}");
    }
    // ex5-6
    static void MethodA()
    {
        throw new CustomException("Ошибка в MethodA");
    }

    static void MethodB()
    {
        throw new CustomException("Ошибка в MethodB");
    }
}