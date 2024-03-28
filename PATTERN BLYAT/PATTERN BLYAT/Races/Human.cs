using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PATTERN;

namespace PATTERN
{
    // билдер для класса Человек
    internal class Human : RPGBuilder
    {
        public override void SetHP()
        {
            this.RPGModel.HP = new HP { value = 200 };
        }
        public override void SetMP()
        {
            this.RPGModel.MP = new MP { value = 0 };
        }
        public override void SetClassName()
        {
            this.RPGModel.ClassName = new ClassNames { cname = "Человек" };
        }
        public override void SetName()
        {
            Console.Write("Введите имя для расы Человек: ");
            while (true)
            {
                readname = Console.ReadLine();
                Console.Clear();
                if (readname.Length > 12) Console.Write("Введенное имя превышает максимальную длину.\n\tПопробуйте снова.\n");
                else break;
            }
            this.RPGModel.Name = new Names { name = readname };
        }
        public override void SetWeapon()
        {
            while (true)
            {
                Console.Write("Какое оружие хотите экипировать?\n" +
                "1) Меч\n" +
                "2) Лук\n" +
                "3) Книга исцеления\n");
                switch (Convert.ToInt32(Console.ReadLine()))
                {
                    case 1:
                        this.RPGModel.Weapon = new Sword { power = 50 };
                        this.RPGModel.Weapon.name = "MegaSword";
                        this.RPGModel.SetStrategy(warrior);
                        return;
                    case 2:
                        this.RPGModel.Weapon = new Bow { power = 1000 };
                        this.RPGModel.Weapon.name = "MegaBow";
                        this.RPGModel.SetStrategy(archer);
                        return;
                    case 3:
                        this.RPGModel.MP.value = 100;
                        this.RPGModel.Weapon = new HealBook { power = 0 };
                        this.RPGModel.Weapon.name = "HealBook";
                        this.RPGModel.SetStrategy(healer);
                        return;
                    default:
                        Console.WriteLine("Введена неправильная команда.\n\tПопробуйте снова");
                        break;
                }
            }
        }
    }
}
