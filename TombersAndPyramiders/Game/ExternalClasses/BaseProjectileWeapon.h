/*===================================================================================*//**
	BaseProjectileWeapon
	
	Abstract class for a base projectile weapon.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseWeapon.h"

/*========================================================================================
	BaseProjectileWeapon	
========================================================================================*/
class BaseProjectileWeapon : public BaseWeapon
{
    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit BaseProjectileWeapon() = default;

		virtual ~BaseProjectileWeapon() {};
};
