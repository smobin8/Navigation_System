#include <iostream>
#include "CGPSSensor.h"
#include "CWaypoint.h"

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CGPSSENSOR.CPP
* Author          :Mohammad Shahid Mobin
* Description     :This class is taking Current Location and returning it to CWaypoint
*
*
****************************************************************************/


//System Include Files


//Own Include Files

//Method Implementations

//Constructor of CGPSSensor
CGPSSensor::CGPSSensor()
 {
}

// for taking input of latitude and longitude and returning all the values to the CWaypoint.
CWaypoint CGPSSensor::getCurrentPosition()
{

	string name;
	double latitude;
	double longitude;
	cout<<"please enter Current Latitude "<<endl;
	cin>>latitude;
	cout<<"please enter Current Longitude"<<endl;
	cin>>longitude;
	name="Current_Location";
	CWaypoint CallObj;
	CallObj.set(name,latitude,longitude);
	CallObj.print(1);

	return CallObj;
}

