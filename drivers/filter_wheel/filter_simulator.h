/*******************************************************************************
  Copyright(c) 2010 Gerry Rozema. All rights reserved.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Library General Public
 License version 2 as published by the Free Software Foundation.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Library General Public License for more details.

 You should have received a copy of the GNU Library General Public License
 along with this library; see the file COPYING.LIB.  If not, write to
 the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 Boston, MA 02110-1301, USA.
*******************************************************************************/

#pragma once

#include "indifilterwheel.h"

/**
 * @brief The FilterSim class provides a simple simulator to change filters. The filter names are saved to a config file when updated.
 */
class FilterSim : public INDI::FilterWheel
{
    public:
        FilterSim() = default;
        virtual ~FilterSim() = default;

        virtual bool initProperties() override;
        virtual bool updateProperties() override;
        virtual bool ISNewNumber(const char *dev, const char *name, double values[], char *names[], int n) override;
        virtual const char *getDefaultName() override;

        bool Connect() override;
        bool Disconnect() override;
        bool SelectFilter(int) override;
        void TimerHit() override;

    private:
        INDI::PropertyNumber DelayNP {1};
};
