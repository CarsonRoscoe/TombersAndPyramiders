/*===================================================================================*//**
	BaseChestplate
	
	Abstract class for a base chestplate

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseEquippableItem.h"

/*========================================================================================
	BaseChestplate	
========================================================================================*/
class BaseChestplate
{
    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
	private:
		int m_maxDurability;
		int m_durability;
		float m_absorptionPercent;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        explicit BaseChestplate() = delete;

		explicit BaseChestplate(int durability, float absorptionPercent);

	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		/**
			Returns the actual amount of damage the character should take after absorption 
			by the chestplate.
			
			Destroys the chestplate if it has taken too much damage.
		*/
		int absorbDamage(int damage);

	private:
		/**
			Destroys the chestplate.
		*/
		void destroy();
};