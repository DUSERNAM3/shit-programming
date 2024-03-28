namespace PATTERN
{
    public class ArcherStrategy : ICharacterStrategy
{
    public void Attack(RPGProduct attacker, RPGProduct defender)
    {
        Console.WriteLine($"{attacker.Name.name} атакует {defender.Name.name} луком!");

        Random random = new Random();
        double chance = random.NextDouble();
        if (defender.HP.value > 0)
            {
                if (chance < 0.2)
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
                    Console.WriteLine($"{attacker.Name.name} нанёс {attacker.Weapon.power} луком!");
                }
            } 
        else Console.WriteLine($"Невозможно атаковать {defender.Name.name}. {defender.Name.name} уже помер");
    }

    public void Defend(RPGProduct attacker, RPGProduct defender)
    {
        Console.WriteLine($"{defender.Name.name} не может защититься!");
        defender.HP.value -= attacker.Weapon.power;
    }

    public void Heal(RPGProduct healer, RPGProduct target)
    {
            if (target.HP.value > 0)
            {
                Random random = new Random();
                double chance = random.NextDouble();
                if (chance > 0.3)
                {
                    Console.WriteLine($"{healer.Name.name} лечит {target.Name.name} подорожником! Восстановлено 10 HP.");
                    target.HP.value += 10;
                }
                else
                {
                    Console.WriteLine($"Исцеление вышло неудачно! {target.Name.name} получил 10 урона");
                    target.HP.value -= 10;
                }
            }
            else Console.WriteLine($"Невозможно исцелить {target.Name.name}. {target.Name.name} уже помер");
    }
}
}