using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec03LibN
{
    public class BonusA : IBonus
    {
        public float cost1Hour { get; set; }
        public BonusA(float cost1Hour)
        {
            this.cost1Hour = cost1Hour;
        }
        public float Calculate(float number_hours)
        {
            return cost1Hour * number_hours;
        }
    }
    public class BonusAL2 : IBonus
    {
        public float cost1Hour { get; set; }
        private float A { get; set; }
        public BonusAL2(float cost1Hour, float A)
        {
            this.cost1Hour = cost1Hour;
            this.A = A;
        }
        public float Calculate(float number_hours)
        {
            return (number_hours + A) * cost1Hour;
        }
    }
    public class BonusAL3 : IBonus
    {
        private float A { get; set; }
        private float B { get; set; }
        public float cost1Hour { get; set; }
        public BonusAL3(float cost1Hour, float A, float B)
        {
            this.cost1Hour = cost1Hour;
            this.A = A;
            this.B = B;
        }
        public float Calculate(float number_hours)
        {
            return (number_hours + A) * (cost1Hour + B);
        }
    }
}