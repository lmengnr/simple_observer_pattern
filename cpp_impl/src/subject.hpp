#pragma once

#include "observer.hpp"

#include <map>
#include <unordered_map>
#include <list>
#include <memory>


class ISubject
{
private:
    /* data */

protected:
    std::list<std::shared_ptr<IObserver>> m_listObservers;

public:
    ISubject(/* args */)
    {
    }
    ~ISubject()
    {
    }

    virtual void RegisterObserver(std::shared_ptr<IObserver> pObserver) = 0;
    virtual void UnregisterObserver(std::shared_ptr<IObserver> pObserver) = 0;
    virtual void NotifyObservers(const ActivityData& newState) = 0;
    //TODO: Maybe keep notify observers without params and have an update state method?
};

class ActivityTracker : ISubject
{

private:

public:
    ActivityTracker() {}
    ~ActivityTracker() {}

    void RegisterObserver(std::shared_ptr<IObserver> pObserver) override
    {
        m_listObservers.push_back(pObserver);

    }
    void UnregisterObserver(std::shared_ptr<IObserver> pObserver) override
    {
        m_listObservers.remove(pObserver);

    }
    void NotifyObservers(const ActivityData& newState) override
    {
        for (auto observer : m_listObservers)
        {
            observer->Update(newState);
        }

    }

};