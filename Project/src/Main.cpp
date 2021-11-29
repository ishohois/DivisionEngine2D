#include <SDL2/SDL.h>
#include "Session.h"
#include "Component.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include <string>

// Paths to resource folders. Change to your own path!
std::string resPath = "./resources/";

Session ses;

class Bullet : public Component
{
public:
	static Bullet *getInstance(int x)
	{
		return new Bullet(x);
	}
	Bullet(int x) : Component(x, 500, 40, 40)
	{
		// Change path to your own 'images' folder!
		texture = IMG_LoadTexture(sys.ren, (resPath + "images/dot40x40.bmp").c_str());
	}
	~Bullet()
	{
		SDL_DestroyTexture(texture);
	}
	void draw() const
	{
		const SDL_Rect &rect = getRect();
		//SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
		SDL_RenderCopy(sys.ren, texture, NULL, &rect);
	}
	void tick()
	{
		if (rect.y <= 0)
		{
			ses.remove(this);
		}
		else
		{
			rect.y--;
		}
	}

private:
	SDL_Texture *texture;
};

class Pistol : public Component
{
public:
	Pistol() : Component(0, 0, 0, 0) {}
	void draw() const {}
	void tick() {}
	void mouseDown(int x, int y)
	{
		Bullet *b = Bullet::getInstance(x);
		ses.add(b);
	}
};

int main(int argc, char **argv)
{
	Pistol *pistol = new Pistol();
	ses.add(pistol);
	ses.run();
	return 0;
}