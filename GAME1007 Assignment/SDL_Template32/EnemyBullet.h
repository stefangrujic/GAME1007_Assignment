#pragma once
#include<iostream>
#include<cmath>


class Enemy :
    class Enemy
{
    int type;
    SDL_Texture* texture;

    int helth;

    SDL_Rect pos;
    SDL_Rect col;


    void loop();

    void render(SDL_Renderer* renderer);

    class game : 
    {
        player Player;

        std::vector<Enemy> enemies;
        std::vector<Bullet> bullets;


        void even(SDL_Event* event)
        {
            // Handle events and
            //  Pass on events to underlaying code   
        }

        void render(SDL_Renderer* renderer)
        {
            //Render 
        }

        void loop()
        {
            /*
             Update positions

             Handle collisions
             */
        }
    };