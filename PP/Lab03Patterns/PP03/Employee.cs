using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lec03LibN;

namespace PP03
{
    public class Employee
    {
        public IBonus bonus { get; private set; }
        public Employee(IBonus bonus)
        {
            this.bonus = bonus;
        }
        public float calcBonus(float number_hours)
        {
            return bonus.Calculate(number_hours);
        }
    }
}