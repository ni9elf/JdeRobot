/*
 *  Copyright (C) 1997-2015 JDE Developers Team
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses/.
 *  Authors :
 *       Francisco Perez Salgado <f.pererz475@gmai.com>
 */

#ifndef BUMPER_H
#define BUMPER_H


#include <jderobot/bumper.h>
#include <roomba/roombasensors.hh>

namespace roomba{
namespace interfaces{

class BumperI : public jderobot::Bumper {
public:
    BumperI (const roomba::RoombaSensors *sensor);
    virtual ~BumperI();

    virtual jderobot::BumperDataPtr getBumperData ( const Ice::Current& );

protected:
    jderobot::BumperDataPtr bumperdata;
    const roomba::RoombaSensors* const sensor;
};

}}//NS
#endif // BUMPER_H
