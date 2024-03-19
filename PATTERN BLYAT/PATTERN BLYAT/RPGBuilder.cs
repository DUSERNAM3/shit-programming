using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PATTERN
{
    internal abstract class RPGBuilder
    {
        // абстрактный класс строителя
        public string readname; //для ввода string-значения
        public int choice; // для ввода int-значения
        public RPGStats RPGModel { get; private set; }
        public void CreateModel()
        {
            RPGModel = new RPGStats();
        }
        public abstract void SetHP();
        public abstract void SetMP();
        public abstract void SetClassName();
        public abstract void SetName();
        public abstract void SetWeapon();
    }
}
