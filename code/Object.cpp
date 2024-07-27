#include "Object.h"

Object::Object() = default;
Object::Object(std::string newName, std::string newTag): name(newName), tag(newTag) {}

void Object::setName(std::string newName) {
    name = newName;
}

void Object::setTag(std::string newTag) {
    tag = newTag;
}

std::string Object::getName() {
    return name;
}

std::string Object::getTag() {
    return tag;
}