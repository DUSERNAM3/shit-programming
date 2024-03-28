using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PATTERN
{
    internal abstract class RPGBuilder
    {
        public WarriorStrategy warrior = new WarriorStrategy();
        public ArcherStrategy archer = new ArcherStrategy();
        public HealerStrategy healer = new HealerStrategy();
        // абстрактный класс строителя
        public string readname; //для ввода string-значения
        public int choice; // для ввода int-значения
        public RPGProduct RPGModel { get; private set; }
        public void CreateModel()
        {
            RPGModel = new RPGProduct();
        }
        public abstract void SetHP();
        public abstract void SetMP();
        public abstract void SetClassName();
        public abstract void SetName();
        public abstract void SetWeapon();
        public RPGProduct GetResult()
        {
            return RPGModel;
        }
    }
}
