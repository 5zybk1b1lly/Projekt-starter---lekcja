#include <Poks.hpp>
#include <iostream> // For debugging

using namespace std;

const int TEXTURE_WIDTH = 350;
const int TEXTURE_HEIGHT = 400;

Poks::Poks(string name, const char *path) : _name(name)
{
    Image img = LoadImage(path);
    if (img.data == nullptr) {
        cerr << "Failed to load image: " << path << endl;
        exit(EXIT_FAILURE);
    }

    ImageResize(&img, TEXTURE_WIDTH, TEXTURE_HEIGHT);
    _texture = LoadTextureFromImage(img);
    if (_texture.id == 0) {
        cerr << "Failed to load texture from image." << endl;
        UnloadImage(img);
        exit(EXIT_FAILURE);
    }

    UnloadImage(img);
}

void Poks::render(float x, float y)
{
    DrawTexture(_texture, x, y, WHITE);
    DrawText(_name.c_str(), x, y + TEXTURE_HEIGHT + 10, 20, BLACK);
}