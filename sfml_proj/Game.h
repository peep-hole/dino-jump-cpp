#ifndef SFML_PROJ_GAME_H
#define SFML_PROJ_GAME_H


#include <string>
#include "GameObject.h"
#define PLATFORMS 20
#define WIDTH 600
#define HEIGHT 900
#define SCROLL_HEIGHT 500
#define COMET_SPEED 10
#define HIT_TIMER 15
#define FLOOR_BUFFER 111
#define IN_PLACE 0
#define FALLING_VELOCITY 0.5
#define MARGIN 50
#define BULLET_START_POS -250
#define FONT_SIZE 24


using namespace sf;


class Game {
private:

    GameObject player;
    GameObject platforms[PLATFORMS];
    GameObject bg;
    GameObject comet;
    GameObject menu;
    GameObject hearths[3];
    RenderWindow app;
    Font font;
    int points =0;
    bool start = true;
    bool is_safe = true;
    void display_game(Sprite bg_sprite, Sprite pl, Sprite plat[PLATFORMS], Sprite bullet, Sprite men, Sprite health[3],
                      int hp, Text t, const Font& font, int hit_timer, bool bullet_on, float total_height);
    void randomize_platforms();
    bool player_fell();
    void check_platforms();
    void scroll_map(bool bullet_on);

public:
    explicit Game(const std::string& graphicPath);
    void start_game();
    void menu_state(bool isStart = true);
};


#endif //SFML_PROJ_GAME_H
