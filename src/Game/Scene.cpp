
#include "Scene.hpp"

#include <iostream>


Scene::Scene() {
}

Scene::~Scene() {
}

void Scene::update(float dt) {
    // TODO: consider storing objects.end() into a variable
    for(auto it = objects.begin(); it != objects.end(); it++) {
        (*it)->update(dt);
    }
    player->update(dt);

    resolveCollisions();
}

void Scene::render() {
    // TODO: consider storing objects.end() into a variable
    for(auto it = objects.begin(); it != objects.end(); it++) {
        (*it)->render();
    }
    player->render();
}

void Scene::addObject(GameObject *object) {
    objects.push_back(object);
}


void Scene::removeObject(GameObject *object) {
    // TODO: use an iterator with .erase() method to not go over the entire list
    delete object;
    objects.remove(object);
}



void Scene::resolveCollisions(){

    for(auto it = objects.begin(); it != objects.end(); it++) {
        if((*it)->isColliding(player)){
            // resolve
            player->vy = 10;
            std::cout << "\n-- Collision --\n";
        }
    }

}
