#pragma once

#include <string>
#include <iostream>
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include <functional>
#include <tuple>
#include <deque>

using namespace std;
enum Element
{
    Fire,
    Water,
    Air,
    Earth,
    Nature,
    last
};

class Poks
{
public:
    Poks(string name, int hp, int ad, int def, Element _el, const char *path);
    void render(float x, float y);
    string get_name();
    int get_hp();
    void take_damage(int damage);
    void attack(Poks &target, string &out_text);
    void defend(string &out_text);
    void special(Poks &target, string &out_text);
    void reset();
private:
    string _name;
    Texture2D _texture;
    int _base_hp;
    int _base_ad;
    int _base_def;
    int _hp;
    int _ad;
    int _def;

    bool is_special;
    bool used_special;
    Element _element;

};
