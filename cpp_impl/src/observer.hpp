#pragma once
#include <iostream>
#include <cmath>


struct ActivityData
{
    double xpos;
    double ypos;
};



/**
 * @brief object interface class
 * 
 */
class IObserver
{
private:
    /* data */
public:
    IObserver(/* args */){};
    IObserver(){};

    virtual void Update(const ActivityData& newState);
};


class cObserverA : IObserver
{
private:
    /* data */
public:
    cObserverA(/* args */){};
    ~cObserverA(){};

    void Update(const ActivityData& newState) override
    {
        std::cout << "New Position: x = " << newState.xpos << ", y = " <<newState.ypos << std::endl;

    }

};

class cDistObserver : IObserver
{
private:
    ActivityData oPrevPos;
public:

    cDistObserver(const ActivityData& initPos)
    {
        oPrevPos = initPos;
    }

    void Update(const ActivityData& newState) override
    {
        double distance = sqrt( 
            ( pow( newState.xpos - oPrevPos.xpos, 2) + pow( newState.ypos - oPrevPos.ypos, 2)
            ));

        std::cout << "Distance travelled: " << distance << std::endl;
    }
};