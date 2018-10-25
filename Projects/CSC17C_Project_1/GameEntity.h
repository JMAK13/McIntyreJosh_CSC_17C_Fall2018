/* 
 * File:   GameEntity.h
 * Author: Josh McIntyre
* Created on October 25, 2018, 4:19 PM
 */

#ifndef GAMEENTITY_H
#define GAMEENTITY_H

//GameEntity Abstract Class
class GameEntity {
    protected:
        bool isPl;
    public:
        virtual bool isPlayer()const=0;
};

#endif /* GAMEENTITY_H */

