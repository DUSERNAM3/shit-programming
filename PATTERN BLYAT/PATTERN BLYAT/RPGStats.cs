using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PATTERN;

namespace PATTERN
{
    public class RPGProduct
    {
        public ICharacterStrategy strategy;
        // ХП
        public HP HP { get; set; }
        // Мана
        public MP MP { get; set; }
        // Имя
        public ClassNames ClassName { get; set; }
        public Names Name { get; set; }
        public Weapons Weapon { get; set; }
        public override string ToString()
        {
            StringBuilder SB = new StringBuilder();
            //Name
            if (Name != null) SB.AppendLine("Имя: " + Name.name);
            else SB.AppendLine("Имя: NONE");
            //Race
            if (ClassName != null) SB.AppendLine("Раса: " + ClassName.cname);
            else SB.AppendLine("Раса: NONE");
            //Class
            if (strategy != null)
            {
                if (strategy is WarriorStrategy) SB.AppendLine("Класс: Воин");
                else if (strategy is ArcherStrategy) SB.AppendLine("Класс: Лучник");
                else SB.AppendLine("Класс: Целитель");
            }
            else SB.AppendLine("Бедолага, без класса");
            //HP
            if (HP.value > 0) SB.AppendLine("HP = " + HP.value);
            else SB.AppendLine("Мертв");
            //MP
            if (MP != null) SB.AppendLine("MP = " + MP.value);
            else SB.AppendLine("Не имеет ману, не обладает магией");
            //возвращаем
            if (Weapon != null) SB.AppendLine("Оружие = " + Weapon.name + "; " + "Сила = " + Weapon.power);
            else SB.AppendLine("Не имеет оружия");
            return SB.ToString();
        }
        public void SetStrategy(ICharacterStrategy strategy)
        {
            this.strategy = strategy;
        }

        public void Attack(RPGProduct defender)
        {
            strategy.Attack(this, defender);
        }

        public void Defend(RPGProduct attacker)
        {
            strategy.Defend(attacker, this);
        }

        public void Heal(RPGProduct target)
        {
            strategy.Heal(this, target);
        }
    }
}
