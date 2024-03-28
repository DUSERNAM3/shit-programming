using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PATTERN
{
    internal class Dummy : RPGBuilder
    {
        public override void SetHP()
        {
            this.RPGModel.HP = new HP { value = 200 };
        }
        public override void SetMP()
        {
            this.RPGModel.MP = new MP { value = 100 };
        }
        public override void SetClassName()
        {
            // не используется
        }
        public override void SetName()
        {
            this.RPGModel.Name = new Names { name = "Манекен" };
        }
        public override void SetWeapon()
        {
            this.RPGModel.Weapon = new Sword { power = 1 };
            this.RPGModel.Weapon.name = "Wooden Sword";
            this.RPGModel.SetStrategy(warrior);
        }
    }
}
