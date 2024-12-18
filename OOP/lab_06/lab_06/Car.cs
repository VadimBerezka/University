using System;

public partial class Car : AbstractVehicle, IDriveable
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

    public Car(string brand, string model, Engine engine, Dimensions dimensions)
        : base(brand, model, engine, dimensions)
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