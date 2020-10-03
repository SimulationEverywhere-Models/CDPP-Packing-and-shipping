/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __DeliveryType_H
#define __DeliveryType_H

//#include <list>
#include "atomic.h"     // class Atomic

class DeliveryType : public Atomic
{
public:
	DeliveryType( const string &name = "DeliveryType" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	Port &closeOrder;
	Time preparationTime;
	int pid;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class DeliverType

// ** inline ** //
inline
string DeliveryType::className() const
{
	return "DeliveryType" ;
}

#endif   //__DeliveryType_H 
