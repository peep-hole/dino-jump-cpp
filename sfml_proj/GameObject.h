#ifndef SFML_PROJ_GAMEOBJECT_H
#define SFML_PROJ_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

struct Vector {
    float x, y;
};


class GameObject {
protected:
    Vector position;
    Vector pos_diff;
    Vector radius;

public:

    sf::Texture texture;

    GameObject();

    GameObject(float x, float y, float dx, float dy, float rx, float ry, const std::string& graphic_path);

    const Vector &getRadius() const;

    bool doesIntersect(const GameObject& other) const;

    void update();

    void setPosDiffY(float dy, bool increment=false);

    void setPosX(float x, bool increment=false);

    void setPosY(float y, bool increment=false);

    float getPosX() const;

    float getPosY() const;

    float getPosDiffY() const;

};


#endif //SFML_PROJ_GAMEOBJECT_H
