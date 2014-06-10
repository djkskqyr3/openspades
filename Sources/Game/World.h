/*
 Copyright (c) 2013 yvt
 
 This file is part of OpenSpades.
 
 OpenSpades is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 OpenSpades is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with OpenSpades.  If not, see <http://www.gnu.org/licenses/>.
 
 */

#pragma once

#include <Core/RefCountedObject.h>
#include "Constants.h"
#include <Client/GameMap.h>
#include <Core/TMPUtils.h>

namespace spades { namespace game {
	
	/** World-global parameters. */
	struct WorldParameters {
		
		float playerJumpVelocity;
		float fallDamageVelocity;
		float fatalFallDamageVelocity;
		
		WorldParameters();
		
	};
	
	class World: public RefCountedObject
	{
		Timepoint currentTime;
		WorldParameters params;
		Handle<client::GameMap> gameMap;
	public:
		World();
		~World();
		
		Timepoint GetCurrentTime() const { return currentTime; }
		
		void Advance(Duration);
		
		/** Returns global gravity vector.
		 * @return Gravity in units/sec^2. */
		Vector3 GetGravity();
		
		bool IsWaterAt(const Vector3&);
		
		bool IsLocalHostServer();
		stmp::optional<uint32_t> GetLocalPlayerId();
		
		client::GameMap *GetGameMap() { return gameMap; }
		
		const WorldParameters& GetParameters() const
		{ return params; }
		
	};
	
	
} }

