/* 
 * File:   GameEntity.h
 * Author: Josh McIntyre
 * Created on May 18, 2018, 10:29 AM
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

