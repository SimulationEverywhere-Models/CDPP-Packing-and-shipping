/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#include <math.h>        // fabs( ... )

#include "Checkstock.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Checkstock
* Description: constructor
********************************************************************/
Checkstock::Checkstock( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
, done( addOutputPort( "done" ) )
{
	try
	{
		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );

		MASSERT( dist );

		for ( register int i = 0 ; i < dist->varCount() ; i++ )
		{
			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar(i) ) ) ;
			dist->setVar( i, str2float( parameter ) ) ;
		}
	} catch( InvalidDistribution &e )
	{
		e.addText( "The model " + description() + " has distribution problems!" ) ;
		e.print(cerr);
		MTHROW( e ) ;
	} catch( MException &e )
	{
		MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &Checkstock::externalFunction( const ExternalMessage &msg )
{
	pid = static_cast< int >( msg.value() ) ;
	holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;

	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Checkstock::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Checkstock::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, pid );
	sendOutput( msg.time(),done, pid);


	return *this;
}

Checkstock::~Checkstock()
{
	delete dist;
}
