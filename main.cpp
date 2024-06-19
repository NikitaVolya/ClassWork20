
#include <iostream>

namespace Bit
{
	float transform(float Kbytes) { return Kbytes * 8192; }
}
namespace Gram
{
	float transform(float Kilogram) { return Kilogram * 1000; }
}

class Monster
{
private:
	float health;
	float damage;
	unsigned short level;
	int xpToLevel;
protected:
	Monster(float pHealth, float pDamage, unsigned short pLevel) : health(pHealth), damage(pDamage), level(pLevel), xpToLevel(level* level) {}
public:
	Monster() : health(0), damage(0), level(1) {}

	float getHealth() const { return health; }
	void sendDamage(float pValue) { health = (float) fmax(0, health - pValue); }

	float getDamage() const { return damage + damage * level / 10.f; }
	void setDamage(float pValue) { damage = pValue; }

	void upLevel() { level += 1; xpToLevel = level * level; }

	int getLevel() const { return (int)level; }
	void setLevel(int pValue) { if (pValue <= 0) throw std::out_of_range("Level can`t be lower to 0"); level = (unsigned short)pValue; xpToLevel = level * level; }
	void addXp(float xp) {
		while (xp > 0) {
			float tmp = xpToLevel;
			xpToLevel -= fmin(xpToLevel, xp);
			xp -= fmin(tmp, xp);
			if (xpToLevel == 0)
				upLevel();
		} 
	}
};

namespace Monsters
{
	class Ogre : public Monster
	{
	public:
		Ogre() : Monster(10, 15, 1) {};
	};

	class Goblin : public Monster
	{
	public:
		Goblin() : Monster(5, 3, 1) {};
	};

	class Skeleton : public Monster
	{
	public:
		Skeleton() : Monster(6, 12, 1) {};
	};
}


int main()
{
	Monsters::Skeleton testSkeleton;

	std::cout << testSkeleton.getLevel() << std::endl;
	testSkeleton.addXp(658);
	std::cout << testSkeleton.getLevel();

	return 0;
}