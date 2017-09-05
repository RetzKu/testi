#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

enum Type
{
	PlayerType,
	EnemyType,
	ProjectileType,
	PickableItemType,

};


class GameObject
{
public:
	GameObject() { _X = 0; _Y = 0; }
	
	void SetType(Type Type) { _Type = Type; }
	Type GetType() { return _Type; }

	virtual void update(float Deltatime) { Sleep(Deltatime); }

	int GetX() { return _X; }
	int GetY() { return _Y; }

	void SetPosition(int x, int y)
	{
		_X = x;
		_Y = y;
	}

private:
	Type _Type;
	int _X;
	int _Y;
};

class Player : public GameObject
{
public:
	Player() { GameObject::SetType(Type::PlayerType); }

	

private:
};

class Enemy : public GameObject
{
public:
	Enemy() { _Energy = 5; GameObject::SetType(Type::EnemyType);}
	void Takehit() { _Energy -= 1; }
private:
	int _Energy;
};

class Projectile : public GameObject
{
public:
	Projectile(){ GameObject::SetType(Type::ProjectileType); }
private:
};

class PickableItem : public GameObject
{
public:
	PickableItem(){ GameObject::SetType(Type::PickableItemType); }
private:
};

vector <GameObject> GameObjects;

int main()
{
	bool Running = true;
	int Key;

	while (Running == true)
	{
		if (GetAsyncKeyState(0x41) & 0x8000 != 0)
		{
			cout << "A";
		}
		if (GetAsyncKeyState(0x42) & 0x8000 != 0)
		{
			cout << "B";
		}
		if (GetAsyncKeyState(0x31) & 0x8000 != 0)
		{
			Player NewPlayer;
			GameObjects.push_back(NewPlayer);
			cout << "Player Created!\n";
		}
		if (GetAsyncKeyState(0x32) & 0x8000 != 0)
		{
			Enemy NewEnemy;
			GameObjects.push_back(NewEnemy);
			cout << "Enemy Created!\n";
		}
		if (GetAsyncKeyState(0x33) & 0x8000 != 0)
		{
			Projectile NewProjectile;
			GameObjects.push_back(NewProjectile);
			cout << "Projectile Created!\n";
		}
		if (GetAsyncKeyState(0x34) & 0x8000 != 0)
		{
			PickableItem NewPickableItem;
			GameObjects.push_back(NewPickableItem);
			cout << "Pickableitem Created!\n";
		}
		for each (GameObject var in GameObjects)
		{
			if (var.GetType() == Type::EnemyType)
			{

			}
			/*var.update(200);*/
			//cout << "update\n";
		}
	}
	
	return 0;
}


