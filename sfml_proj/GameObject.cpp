#include "GameObject.h"

GameObject::GameObject(float x,
                       float y,
                       float dx,
                       float dy,
                       float rx,
                       float ry,
                       const std::string& graphic_path) {

    position.x = x;
    position.y = y;

    pos_diff.x = dx;
    pos_diff.y = dy;

    radius.x = rx;
    radius.y = ry;

    texture.loadFromFile(graphic_path);


}

const Vector &GameObject::getRadius() const {
    return radius;
}


bool GameObject::doesIntersect(const GameObject& other) const {
    float rx1 = radius.x/2.f, rx2 = other.getRadius().x/2.f;
    float x_rad = rx1 + rx2;

    float ry1 = radius.y/2.f, ry2 = other.getRadius().y/2.f;
    float y_rad = ry1 + ry2;

    float dx = std::abs(position.x - other.getPosX());
    float dy = std::abs(position.y - other.getPosY());

    if ((dx < x_rad) && (dy < y_rad)) {

        return true;
    }

    return false;
}

void GameObject::update() {

    position.x += pos_diff.x;
    position.y += pos_diff.y;
}

void GameObject::setPosDiffY(float dy, bool increment) {
    if (increment) {
        pos_diff.y += dy;
    }
    else {
        pos_diff.y = dy;
    }
}

GameObject::GameObject() {
    position.x = 0;
    position.y = 0;
    pos_diff.x = 0;
    pos_diff.y = 0;
    radius.x = 0;
    radius.y = 0;
    texture = sf::Texture();

}

void GameObject::setPosX(float x, bool increment) {
    if (increment) {
        position.x += x;
    }
    else {
        position.x = x;
    }
}

void GameObject::setPosY(float y, bool increment) {
    if (increment) {
        position.y += y;
    }
    else {
        position.y = y;
    }
}

float GameObject::getPosX() const {
    return position.x;
}

float GameObject::getPosY() const {
    return position.y;
}

float GameObject::getPosDiffY() const {
    return pos_diff.y;
}


