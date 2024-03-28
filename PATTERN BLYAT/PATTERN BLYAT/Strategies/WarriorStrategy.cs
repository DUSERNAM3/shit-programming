using System.Security.Cryptography.X509Certificates;
using System.Threading.Channels;

namespace PATTERN
{
public class WarriorStrategy : ICharacterStrategy
{
    public void Attack(RPGProduct attacker, RPGProduct defender)
    {
        Console.WriteLine($"{attacker.Name.name} атакует {defender.Name.name} мечом!");

        Random random = new Random();
        double chance = random.NextDouble();

        if (defender.HP.value > 0)
            {
                if (chance < 0.1)
                {
                    Console.WriteLine($"{attacker.Name.name} промахивается!");
                }
                else if (chance < 0.5)
                {
                    defender.Defend(attacker);
                }
                else
                {
                    defender.HP.value -= attacker.Weapon.power;
                    Console.WriteLine($"{attacker.Name.name} нанёс {attacker.Weapon.power} мечом!");

                }
            }
        else Console.WriteLine($"Невозможно атаковать {defender.Name.name}. {defender.Name.name} уже помер");
        }

    public void Defend(RPGProduct attacker, RPGProduct defender)
    {
        Console.WriteLine($"{defender.Name.name} защищается щитом! Заблокировано {attacker.Weapon.power} урона");
    }

    public void Heal(RPGProduct healer, RPGProduct target)
    {
        Console.WriteLine($"{healer.Name.name} не может лечить {target.Name.name}!");
    }
}
}