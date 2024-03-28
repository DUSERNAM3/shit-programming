using System;

namespace PATTERN
{
    public class HealerStrategy : ICharacterStrategy
{
    public void Attack(RPGProduct attacker, RPGProduct defender)
    {
        Console.WriteLine($"{attacker.Name.name} не может атаковать {defender.Name.name}!");
    }

    public void Defend(RPGProduct attacker, RPGProduct defender)
    {
        Console.WriteLine($"{defender.Name.name} создает магический щит!");
    }

    public void Heal(RPGProduct healer, RPGProduct target)
    {
            if (target.HP.value > 0 && healer.MP.value > 0)
            {
                Random random = new Random();
                double chance = random.NextDouble();
                if (chance > 0.3)
                {
                    Console.WriteLine($"{healer.Name.name} лечит {target.Name.name} магией! Восстановлено 50 HP.");
                    target.HP.value += 50;
                    healer.MP.value -= 20;
                }
                else
                {
                    Console.WriteLine($"Исцеление вышло неудачно! {target.Name.name} получил 10 урона");
                    target.HP.value -= 10;
                    healer.MP.value -= 20;
                }
            }
            else if (healer.MP.value <= 0) Console.WriteLine($"Невозможно исцелить {target.Name.name}. У {healer.Name.name} закончилась мана.");
            else Console.WriteLine($"Невозможно исцелить {target.Name.name}. {target.Name.name} уже помер");
        }
}
}