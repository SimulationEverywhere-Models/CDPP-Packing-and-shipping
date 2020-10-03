/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __Packing_H
#define __Packing_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class Packing: public Atomic
{
public:
	Packing( const string &name = "Packing" ) ;	 // Default constructor

	~Packing();					// Destructor

	virtual string className() const
		{return "Packing";}

protected:
	Model &initFunction()
		{return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &in ;
	Port &out ;
	Distribution *dist ;
    double pid;

	Distribution &distribution()
			{return *dist;}
};	// class Packing


#endif   //__Packing_H

