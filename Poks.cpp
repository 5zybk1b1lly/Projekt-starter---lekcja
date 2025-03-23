#include <Poks.hpp>
#include <iostream> // For debugging

using namespace std;

const int TEXTURE_WIDTH = 350;
const int TEXTURE_HEIGHT = 400;

Poks::Poks(string name, int hp, int ad, int def, Element _el, const char *path) : 
    _base_hp(hp), 
    _base_ad(ad), 
    _base_def(def), 
    _hp(hp), 
    _ad(ad), 
    _def(def), 
    _element(_el), 
    _name(name)
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
int Poks::get_hp() 
{
    return _hp;
}
string Poks::get_name()
{
    return _name;
}
void Poks::take_damage(int damage)
{
    _hp -= damage;
}
void Poks::attack(Poks &target, string &out_text)
{
    target.take_damage(_ad);
    out_text = this-> get_name() + " attacked " + target.get_name() + " for " + to_string(_ad) + " damage.";
}
void Poks::defend(string &out_text)
{
    _def += _base_def / 2;
    out_text = this->get_name() + " defends for " + to_string(_def) + " defense.";
}
void Poks::special(Poks &target, string &out_text)
{
    if (!used_special)
    {
        target.take_damage(_ad * 2);
        out_text = this->get_name() + " used special attack on " + target.get_name() + " for " + to_string(_ad * 2) + " damage.";
        used_special = true;
    }
    else
    {
        out_text = this->get_name() + " has already used special attack.";
    }
}
void Poks::reset()
{   
    this-> _def = this->_base_def;
}