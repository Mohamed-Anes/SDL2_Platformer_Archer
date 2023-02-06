
#include "Scene.hpp"
#include "Defs.hpp"
#include <iostream>


Scene::Scene() {
}

Scene::~Scene() {
}

void Scene::update(float dt) {
    
    background->update(dt);
    // TODO: consider storing objects.end() into a variable
    for(auto it = objects.begin(); it != objects.end(); it++) {
        (*it)->update(dt);
    }

    resolveCollisions();

    player->update(dt);

}

void Scene::render() {

    background->render();
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
    // TO-DO: use an iterator with .erase() method to not go over the entire list
    delete object;
    objects.remove(object);
}



// TO-DO: search Minkowski difference for collision detection and resolution
void Scene::resolveCollisions(){

    for(auto it = objects.begin(); it != objects.end(); it++) {
        if((*it)->isColliding(player)){
            // resolve
            // float dx_pl_br = (*it)->positionAndSize.x - player->positionAndSize.x + player->positionAndSize.w; // distance x ,player on the left, box on the right
            // float dx_pr_bl = player->positionAndSize.x - (*it)->positionAndSize.x + (*it)->positionAndSize.w; // flip
            
            // float dy_pa_bb = (*it)->positionAndSize.y - player->positionAndSize.y + player->positionAndSize.h; // distance y, player above, box below
            // float dy_pb_ba = player->positionAndSize.y - (*it)->positionAndSize.y + (*it)->positionAndSize.h; // flip

            // if(MIN(ABS(dx_pl_br), ABS(dx_pr_bl)) < MIN(ABS(dy_pa_bb), ABS(dy_pb_ba))){
            //     // case of dx smaller than dy
            //     if()
            // }

            float dx, dy;
            if( (*it)->positionAndSize.x < player->positionAndSize.x ) { 
                dx = player->positionAndSize.x - ((*it)->positionAndSize.x + (*it)->positionAndSize.w); // player on the rigt, box on the left, result negative
            } else { 
                dx = (player->positionAndSize.x + player->positionAndSize.w) - (*it)->positionAndSize.x; // flip, result positive
            }

            if( (*it)->positionAndSize.y < player->positionAndSize.y ) {
                dy = player->positionAndSize.y - ((*it)->positionAndSize.y + (*it)->positionAndSize.h); // player below, box above, result negative
            } else {
                dy = (player->positionAndSize.y + player->positionAndSize.h) - (*it)->positionAndSize.y; //flip, result positive
            }

            if( ABS(dx) < ABS(dy) ) {
                // treat the collision on the x axis
                if( dx > 0 ) {
                    player->vx = -10;
                } else {
                    player->vx = 10;
                }
            } else {// treat the collision on the y axis, flipped compared to the x axis since player update function subtracts vy rather than add
                if( dy > 0 ) {
                    player->vy = 10;
                } else {
                    player->vy = -10;
                }

            }

            std::cout << "\n-- Collision --\n";
        }
    }

}
