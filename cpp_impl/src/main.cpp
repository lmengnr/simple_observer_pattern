#include "subject.hpp"

int main()
{

    ActivityTracker oMovementTracker;

    std::shared_ptr<IObserver> oPosDisplay = std::make_shared<cObserverA>();

    ActivityData oInitPos;
    oInitPos.xpos = 0.0;
    oInitPos.ypos = 0.0;

    std::shared_ptr<IObserver> oDistDisplay = std::make_shared<cDistObserver>(oInitPos);

    oMovementTracker.RegisterObserver(oPosDisplay);
    oMovementTracker.RegisterObserver(oDistDisplay);

    ActivityData newPos;
    newPos.xpos = 3.0;
    newPos.ypos = 4.0;

    oMovementTracker.NotifyObservers(newPos);


    return 0;
}