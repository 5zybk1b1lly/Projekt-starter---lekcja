#include <Poks.hpp>

using namespace std;

const int TEXTURE_WIDTH = 350;
const int TEXTURE_HEIGHT = 400;

Poks::Poks(string name, const char *path) : _name(name)
{
    Image img = LoadImage(path);
    ImageResize(&img, TEXTURE_WIDTH, TEXTURE_HEIGHT);
    _texture = LoadTextureFromImage(img);
    UnloadImage(img);
}

void Poks::render(float x, float y)
{
    DrawTexture(_texture, x, y, WHITE);
    DrawText(_name.c_str(), x, y + TEXTURE_HEIGHT + 10, 20, BLACK);
}

