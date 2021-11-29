#include "observer.hpp"

#include <map>
#include <unordered_map>
#include <memory>


class ISubject
{
private:
    /* data */

protected:
    std::unordered_map<uint16_t, std::shared_ptr<IObserver>> m_mapObservers;

public:
    ISubject(/* args */)
    {
    }
    ~ISubject()
    {
    }

    virtual void RegisterObserver(std::shared_ptr<IObserver> pObserver) = 0;
    virtual void UnregisterObserver(std::shared_ptr<IObserver> pObserver) = 0;
    virtual void NotifyObservers() = 0;
};

class ActivityObserver : ISubject
{

private:

public:
    ActivityObserver() {}
    ~ActivityObserver() {}

    void RegisterObserver(std::shared_ptr<IObserver> pObserver) override
    {

    }
    void UnregisterObserver(std::shared_ptr<IObserver> pObserver) override
    {

    }
    void NotifyObservers() override
    {

    }

};