/*
 *  cBirthGlobalHandler.h
 *  Avida
 *
 *  Created by David Bryson on 4/1/09.
 *  Copyright 2009-2010 Michigan State University. All rights reserved.
 *
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; version 2
 *  of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef cBirthGlobalHandler_h
#define cBirthGlobalHandler_h

#ifndef cBirthEntry_h
#include "cBirthEntry.h"
#endif
#ifndef cBirthSelectionHandler_h
#include "cBirthSelectionHandler.h"
#endif

class cBirthChamber;


class cBirthGlobalHandler : public cBirthSelectionHandler
{
private:
  cBirthChamber* m_bc;
  cBirthEntry m_entry;

  
public:
  cBirthGlobalHandler(cBirthChamber* bc) : m_bc(bc) { ; }
  
  cBirthEntry* SelectOffspring(cAvidaContext& ctx, const cMetaGenome& offspring, cOrganism* parent);
};

#endif
