#include "Game.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;

Game::Game(const std::string& graphicPath) : app(VideoMode(600, 1200), "Jump'n'Dodge!") {

    srand(time(0));

    // init game objects

    player = GameObject(100, 460, 0, 0, 100, 100, graphicPath + "dino.png");

    for (auto & platform : platforms) {
        float x = rand() % (WIDTH - 50) + 20;
        float y = rand() % (HEIGHT);
        platform = GameObject(x, y, 0, 0, 100, 20, graphicPath + "platform.png");
    }

    bg = GameObject(0, 0, 0, 0, 900, 600, graphicPath + "background.png");
    comet = GameObject(0, 0, 0, COMET_SPEED, 30, 30, graphicPath + "comet.png");
    menu = GameObject(0, 900, 0, 0, 0, 0, graphicPath + "Menu.png");

    hearths[0] = GameObject(250, 1000, 0, 0, 0, 0, graphicPath + "hp.png");
    hearths[1] = GameObject(370, 1000, 0, 0, 0, 0, graphicPath + "hp.png");
    hearths[2] = GameObject(490, 1000, 0, 0, 0, 0, graphicPath + "hp.png");

    app.setFramerateLimit(60);

    font.loadFromFile("../arial.ttf"); // load fonts

}

void Game::start_game() {

    int hp = 3;
    bool can_jump = false;
    bool bullet_on = false;
    int hit_timer = 0;
    float total_height = 296;
    points = 0;

    srand(time(0));

    Sprite bg_sprite(bg.texture), pl(player.texture), plat[PLATFORMS], bullet(comet.texture), men(menu.texture), health[3];
    Text t;

    for(int i=0; i<PLATFORMS; ++i) {
        plat[i].setTexture(platforms[i].texture);
    }

    for(int i=0; i<3; ++i) {
        health[i].setTexture(hearths[i].texture);
    }

    randomize_platforms();

    while (app.isOpen()) {
        Event e{};

        while (app.pollEvent(e)) {
            if (e.type == Event::Closed) {
                app.close();
            }
        }

        // checking if player fell down

        if(player_fell()) {
            return; // game over
        }

        // checking keyboard navigation

        if (Keyboard::isKeyPressed(Keyboard::Right)) player.setPosX(5, true);
        if (Keyboard::isKeyPressed(Keyboard::Left)) player.setPosX(-5, true);
        if ((Keyboard::isKeyPressed(Keyboard::Up))&&(can_jump)) {
            player.setPosDiffY(-15);
        }


        // checking if player is on platform

        check_platforms();

        // checking comet collision

        if (player.doesIntersect(comet)) {
            hp -= 1;
            bullet_on = false;
            hit_timer = HIT_TIMER;

            if (hp <= 0) {
               return;
            }
        }

        // setting jump possibility

        if (player.getPosDiffY() == 0) can_jump = true;
        else can_jump = false;

        player.update();

        // bg scrolling

        scroll_map(bullet_on);

        if (!bullet_on) {
            bullet_on = true;
            comet.setPosX(rand()%(WIDTH-MARGIN) + MARGIN);
            comet.setPosY(BULLET_START_POS);
        }

        if (comet.getPosY() >= HEIGHT - MARGIN) {
            bullet_on = false;
        } else {
            comet.update();
        }

        total_height -= player.getPosDiffY();

        // displaying

        display_game(bg_sprite, pl, plat, bullet,men,
                     health,hp,t, font, hit_timer, bullet_on, total_height);

        if (hit_timer > 0) {
            hit_timer -= 1;
        }

    }
}

void Game::menu_state(bool isStart) {

    Sprite s(bg.texture);
    s.setScale(600, 900);
    s.setColor(Color::Black);

    Sprite man(menu.texture);
    man.setPosition(0, 900);

    Sprite h[3];
    h[0].setTexture(hearths[0].texture);
    h[0].setPosition(hearths[0].getPosX(), hearths[0].getPosY());

    h[1].setTexture(hearths[1].texture);
    h[1].setPosition(hearths[1].getPosX(), hearths[1].getPosY());

    h[2].setTexture(hearths[2].texture);
    h[2].setPosition(hearths[2].getPosX(), hearths[2].getPosY());

    Text t1, t2, t3;
    t1.setFont(font);
    t1.setCharacterSize(FONT_SIZE);
    t1.setFillColor(Color::Green);
    t1.setPosition(250, 350);

    t2.setFont(font);
    t2.setCharacterSize(FONT_SIZE);
    t2.setFillColor(Color::Green);
    t2.setString("-- Press ENTER to start --");
    t2.setPosition(150, 400);

    t3.setFont(font);
    t3.setCharacterSize(FONT_SIZE + 10);
    t3.setFillColor(Color::Green);
    t3.setString("GAME OVER");
    t3.setPosition(190, 300);


    while (app.isOpen()) {
        Event e{};

        while (app.pollEvent(e)) {
            if (e.type == Event::Closed) {
                app.close();
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Enter)) {
            start_game();
        }

        app.draw(s);
        app.draw(man);
        app.draw(h[0]);
        app.draw(h[1]);
        app.draw(h[2]);

        app.draw(t2);

        if (!isStart) {
            t1.setString("Points: " + std::to_string(points));
            app.draw(t1);
            app.draw(t3);
        }

        app.display();
    }
}

void Game::display_game(Sprite bg_sprite, Sprite pl, Sprite plat[PLATFORMS], Sprite bullet, Sprite men,
                        Sprite health[3], int hp, Text t, const Font& font, int hit_timer, bool bullet_on,
                        float total_height) {

    bg_sprite.setPosition(bg.getPosX(), bg.getPosX());
    app.draw(bg_sprite);

    pl.setPosition(player.getPosX(), player.getPosY());
    if (hit_timer > 0) {
        pl.setColor(sf::Color(Color::Red));
    }
    else {
        pl = Sprite(player.texture);
        pl.setPosition(player.getPosX(), player.getPosY());
    }
    app.draw(pl);

    for (int i = 0; i < PLATFORMS; ++i) {
        plat[i].setPosition(platforms[i].getPosX(), platforms[i].getPosY());
        app.draw(plat[i]);
    }

    if (bullet_on) {
        bullet.setPosition(comet.getPosX(), comet.getPosY());
        app.draw(bullet);
    }

    men.setPosition(menu.getPosX(), menu.getPosY());
    app.draw(men);

    if(hp >= 3) {
        health[2].setPosition(hearths[2].getPosX(), hearths[2].getPosY());
        app.draw(health[2]);
    }
    if(hp >= 2) {
        health[1].setPosition(hearths[1].getPosX(), hearths[1].getPosY());
        app.draw(health[1]);
    }
    if(hp >= 1) {
        health[0].setPosition(hearths[0].getPosX(), hearths[0].getPosY());
        app.draw(health[0]);
    }

    if ((int)total_height > points) {
        points = (int)total_height;
    }

    t.setFont(font);
    t.setString("POINTS: " + std::to_string(points));
    t.setCharacterSize(FONT_SIZE);
    t.setFillColor(Color::Green);

    app.draw(t);

    app.display();
}

void Game::randomize_platforms() {

    srand(time(0));

    for (auto & platform : platforms) {
        float x = rand() % (WIDTH - MARGIN) + MARGIN;
        float y = rand() % (HEIGHT);
        platform.setPosX(x);
        platform.setPosY(y);
    }
}

bool Game::player_fell() {

    player.setPosDiffY(FALLING_VELOCITY, true);
    if (player.getPosY() > HEIGHT - FLOOR_BUFFER) {
        if (!is_safe) {
            return true;   // game over
        }
        else {
            player.setPosDiffY(IN_PLACE);
        }
    }

    return false;
}

void Game::check_platforms() {

    for (const auto & platform : platforms) {
        if ((player.getPosX()+50 > platform.getPosX()) &&
            (player.getPosX()+20 < platform.getPosX() + 68) &&
            (player.getPosY()+100 > platform.getPosY()) &&
            (player.getPosY()+100 < platform.getPosY()+20) &&
            (player.getPosDiffY() > 0)) {

            player.setPosDiffY(0);
        }
    }
}

void Game::scroll_map(bool bullet_on) {
    if (player.getPosY() < SCROLL_HEIGHT) {
        if (start) {
            start = false;
        }
        else if (is_safe) {
            is_safe = false;
        }
        if(bullet_on) {
            comet.setPosY(-player.getPosDiffY(), true);
        }
        for (auto & platform : platforms) {
            player.setPosY(SCROLL_HEIGHT);
            platform.setPosY(-player.getPosDiffY(), true);
            if (platform.getPosY() > HEIGHT) {
                platform.setPosY(IN_PLACE); platform.setPosX(rand()%(WIDTH-MARGIN) + MARGIN);
            }
        }
    }
}

