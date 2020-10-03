
/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*
*********************************************************************/

/** include files **/
#include "RequestHandler.h"           // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator

/*******************************************************************
* Function Name: RequestHandler
* Description: constructor
********************************************************************/
RequestHandler::RequestHandler( const string &name )
: Atomic( name )
, ReqIn( addInputPort( "ReqIn" ) )
, done( addInputPort( "done" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 10, 0 )
{
	finish = 0;
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description:
* Precondition:
********************************************************************/
Model &RequestHandler::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &RequestHandler::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == ReqIn )
	{
		elements.push_back( msg.value() ) ;
		if(( msg.value() == 1 )& (finish == 0))
			holdIn( active, preparationTime );
		if((elements.size() == 1)&(finish = 1))
		    holdIn( active, preparationTime );


	}

	if( msg.port() == done )
	{
		if( !elements.empty() ){
	    elements.pop_front() ;
			holdIn( active, preparationTime );
		}
		else
		    finish = 1;

passivate();
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &RequestHandler::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &RequestHandler::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, elements.front() ) ;

	elements.pop_front() ;
	if (finish == 1) finish = 0;
	return *this ;
}
RequestHandler::~RequestHandler()
{

}
