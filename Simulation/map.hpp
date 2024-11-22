#pragma once

#include<cmath>


struct Coordinate
{
    float x = 0;
    float y = 0;

    Coordinate operator + (Coordinate other)
    {
        Coordinate new_coordinate;
        new_coordinate.x = this->x + other.x;
        new_coordinate.y =  this->y + other.y;
        return new_coordinate;
    }

    Coordinate operator - (Coordinate other)
    {
        Coordinate new_coordinate;
        new_coordinate.x = this->x - other.x;
        new_coordinate.y =  this->y - other.y;
        return new_coordinate;
    }

    Coordinate operator * (int scalar)
    {
        Coordinate new_coordinate;
        new_coordinate.x = this->x * scalar;
        new_coordinate.y = this->y * scalar;
        return new_coordinate;
    }

    void calculate_magnitude()
    {
        return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
    }

};