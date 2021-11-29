
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

    virtual void Update(ActivityData& newState);
};
