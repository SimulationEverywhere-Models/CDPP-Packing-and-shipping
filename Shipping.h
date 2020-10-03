/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __Shipping_H
#define __Shipping_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class Shipping: public Atomic
{
public:
	Shipping( const string &name = "Shipping" ) ;	 // Default constructor

	~Shipping();					// Destructor

	virtual string className() const
		{return "Shipping";}

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


#endif   //__Shipping_H
