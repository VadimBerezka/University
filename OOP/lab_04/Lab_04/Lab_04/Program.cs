using System;

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

    protected AbstractVehicle(string brand, string model, Engine engine)
        {
            Brand = brand;
            Model = model;
            Engine = engine;
        }

        public abstract void Start();
        public abstract void Stop();
        public abstract bool DoDrive(); // ex4

        public override string ToString()
        {
            return $"{GetType().Name}: {Brand} {Model}, {Engine}";
        }
    }

    public sealed class Car : AbstractVehicle, IDriveable
    {
    private CarControl control;

    public CarControl Control
    {
        get
        {
            return control;
        }
        set
        {
            control = value;
        }
    }

    public Car(string brand, string model, Engine engine) : base(brand, model, engine)
        {
            Control = new CarControl();
        }

        public override void Start()
        {
            Console.WriteLine($"{Brand} {Model} стартует");
            Control.Accelerate();
        }

        public override void Stop()
        {
            Control.Brake();
            Console.WriteLine($"{Brand} {Model} стоп");
        }

        public override bool DoDrive() // ex4
        {
            Console.WriteLine($"{Brand} {Model} водим");
            return true;
        }

        void IDriveable.Start()
        {
        Console.WriteLine($"{Brand} {Model} поехал");
        Control.Accelerate();
        }
        void IDriveable.Stop()
        {
            Control.Brake();
            Console.WriteLine($"{Brand} {Model} стоп");
        }

    public override string ToString()
        {
            return base.ToString() + " машинка";
        }
    }

    public class CarControl
    {
        public void Accelerate()
        {
            //Console.WriteLine("ускоряемся");
        }

        public void Brake()
        {
            //Console.WriteLine("сломалась");
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

    public class IntelligentBeing
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
            return $"умный человек: {Name}";
        }
    }

    public class Human : IntelligentBeing
    {
        public Human(string name) : base(name) 
        { 
           
        }

        public override void Speak()
        {
            Console.WriteLine($"{Name} передает привет");
        }

        public override string ToString()
        {
            return base.ToString() + " человек";
        }
    }

    public class Transformer : AbstractVehicle
    {
        public Transformer(string brand, string model, Engine engine) : base(brand, model, engine) 
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

        public override bool DoDrive() // ex4
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
        Engine engine = new Engine(1000);
        AbstractVehicle car = new Car("Nissan", "Skyline", engine);
        AbstractVehicle transformer = new Transformer("Bumblebee", "Chevrolet Camaro", engine);
        IntelligentBeing human = new Human("Брайн");

        Printer printer = new Printer();

        IDriveable[] driveables = new IDriveable[]
        {
            car,
            transformer,
        };

        foreach (var driveable in driveables)
        {
            printer.IAmPrinting(driveable);
        }

        Console.WriteLine(human.ToString());

        car.Start();
        IDriveable test = car;
        test.Start();
    }
}