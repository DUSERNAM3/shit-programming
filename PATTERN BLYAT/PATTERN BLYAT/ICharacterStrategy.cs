namespace PATTERN
{
public interface ICharacterStrategy
{
    public void Attack(RPGProduct attacker, RPGProduct defender);
    public void Defend(RPGProduct attacker,RPGProduct defender);
    public void Heal(RPGProduct healer, RPGProduct target);
}
}