#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "PolarVector.h"

//Base inheritance class, contains a two vector defining a position (virtual)

class Item
{
public:
    Item();
    Item(PolarVector& position);
    virtual ~Item();

    //Position get and set methods
    PolarVector GetPosition() const;
    void SetPosition(PolarVector position);

protected:
    PolarVector fPosition;

};

#endif // ITEM_H
