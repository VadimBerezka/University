using System;

public enum VehicleType
{
    Car,
    Transformer
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

        return foundTransformers;
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

        controller.AddHuman(new Human("Вадим", 2006));
        controller.AddHuman(new Human("Алексей", 2006));
        controller.AddHuman(new Human("ВладиSLAVE", 2005));
        controller.AddHuman(new Human("SEMEN", 2005));
        controller.AddHuman(new Human("тайская женщина",1999));

        Engine engine1 = new Engine(1000);
        Dimensions carDimensions1 = new Dimensions(17, 5, 20);
        controller.AddTransformer(new Transformer("Nissan", "Skyline", engine1, carDimensions1));

        Engine engine2 = new Engine(800);
        Dimensions carDimensions2 = new Dimensions(13, 15, 6);
        controller.AddTransformer(new Transformer("Bumblebee", "Chevrolet Camaro", engine2, carDimensions2));

        Engine engine3 = new Engine(10000);
        Dimensions carDimensions3 = new Dimensions(5, 5, 5);
        controller.AddTransformer(new Transformer("Optimus", "Prime", engine3, carDimensions3));

        controller.DisplayUnits();
        controller.FindHumansByYear(2005);
        controller.FindHumansByYear(1999);
        controller.GetTransformersByHorsePower(1000);
        controller.GetTransformersByHorsePower(10000);
        controller.CountCombatUnits();
    }
}