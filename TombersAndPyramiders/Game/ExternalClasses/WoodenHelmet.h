/*===================================================================================*//**
	WoodenHelmet
	
	A weak wooden helmet.

    @author Erick Fernandez de Arteaga
	
*//*====================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include "BaseHelmet.h"

/*========================================================================================
	WoodenHelmet	
========================================================================================*/
class WoodenHelmet : public BaseHelmet
{
    /*----------------------------------------------------------------------------------------
		Class Fields
    ----------------------------------------------------------------------------------------*/
    private:
		static const float WOODEN_HELMET_CRITICAL_RESIST_CHANCE;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit WoodenHelmet();

		virtual ~WoodenHelmet() {};
};
