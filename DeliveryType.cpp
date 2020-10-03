/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "DeliveryType.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: DeliveryType
* Description:
********************************************************************/
DeliveryType::DeliveryType( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, closeOrder( addOutputPort( "closeOrder" ) )
, preparationTime( 0, 00, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &DeliveryType::initFunction()
{
	this-> passivate();
	pid = 0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &DeliveryType::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		pid = static_cast < int > (msg.value());
		holdIn( active, preparationTime );
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &DeliveryType::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &DeliveryType::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), closeOrder, pid) ;
	return *this ;
}
