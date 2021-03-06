/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#include <math.h>            // fabs( ... )
#include "Shipping.h"  // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Shipping
* Description: constructor
********************************************************************/
Shipping::Shipping( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
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
Model &Shipping::externalFunction( const ExternalMessage &msg )
{
   if ( this->state() == passive)
    {
	holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
    pid = msg.value();
    }
	return *this ;

}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Shipping::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Shipping::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, pid );
	return *this;
}

Shipping::~Shipping()
{
	delete dist;
}
