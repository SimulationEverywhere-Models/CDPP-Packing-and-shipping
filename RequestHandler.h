/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*
*********************************************************************/

#ifndef __RequestHandler_H
#define __RequestHandler_H

#include <list>
#include "atomic.h"     // class Atomic

class RequestHandler : public Atomic
{
public:
	RequestHandler( const string &name = "RequestHandler" );					//Default constructor
    ~RequestHandler();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &ReqIn;
	const Port &done;
	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;
	int finish;

	Time timeLeft;

};	// class RequestHandler

// ** inline ** //
inline
string RequestHandler::className() const
{
	return "RequestHandler" ;
}

#endif   //__RequestHandler_H

