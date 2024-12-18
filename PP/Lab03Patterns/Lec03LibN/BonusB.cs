using System;

namespace Lec03LibN
{
    public class BonusB : IBonus
    {
        private float x { get; set; }
        public float cost1Hour { get; set; }

        public BonusB(float cost1Hour, float x)
        {
            this.x = x;
            this.cost1Hour = cost1Hour;
        }

        public float Calculate(float number_hours)
        {
            return cost1Hour * number_hours * x;
        }
    }

    public class BonusBL2 : IBonus
    {
        private float x { get; set; }
        public float cost1Hour { get; set; }
        private float A { get; set; }

        public BonusBL2(float cost1Hour, float x, float A)
        {
            this.cost1Hour = cost1Hour;
            this.A = A;
            this.x = x;
        }

        public float Calculate(float number_hours)
        {
            return (number_hours + A) * cost1Hour * x;
        }
    }

    public class BonusBL3 : IBonus
    {
        private float A { get; set; }
        private float B { get; set; }
        private float x { get; set; }
        public float cost1Hour { get; set; }

        public BonusBL3(float cost1Hour, float x, float A, float B)
        {
            this.cost1Hour = cost1Hour;
            this.A = A;
            this.B = B;
            this.x = x;
        }

        public float Calculate(float number_hours)
        {
            return (number_hours + A) * (cost1Hour + B) * x;
        }
    }
}