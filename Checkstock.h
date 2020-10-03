/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __Checkstock_H
#define __Checkstock_H

#include "atomic.h"     // class Atomic

class Distribution ;

class Checkstock : public Atomic
{
public:
	Checkstock( const string &name = "Checkstock" ) ;	 // Default constructor

	~Checkstock();					// Destructor

	virtual string className() const
		{return "Checkstock";}
protected:
	Model &initFunction()
	{return *this; }

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );
private:
	const Port &in;
	Port &out;
	Port &done ;
	Distribution *dist ;
	int pid ;

	Distribution &distribution()
			{return *dist;}

};	// class Checkstock

#endif   //__Checkstock_H
