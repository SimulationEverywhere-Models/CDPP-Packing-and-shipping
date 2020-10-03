/*******************************************************************
*
*  Auto Generated File
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  This registration file is used to describe the atomic models that can be used to compose coupled models.
*
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "DeliveryType.h"	// class DeliveryType








#include "Packing.h" //class Packing
#include "Shipping.h" //class Shipping
#include "RequestHandler.h"	// class RequestHandler
#include "Checkstock.h"	// class Checkstock



void MainSimulator::registerNewAtomics()
{


	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Packing>() , "Packing" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Shipping>() , "Shipping" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Checkstock>() , "Checkstock" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<RequestHandler>() , "RequestHandler" ) ;


	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<DeliveryType>() , "DeliveryType" ) ;

}
