#include <iostream>
#include "CWaypoint.h"
#include <string>
#include <cmath>
#include <math.h>
using namespace std;


/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CWAYPOINT.CPP
* Author          :	Mohammad Shahid Mobin
* Description     :CWaypoint class is to take the Way points name, latitude and longitude.
*				  :here printing latitude and longitude both in decimal degree format and degree, Minutes and second format.
* 				  :and Calculating distance.
* 				  *
*
*
****************************************************************************/


//System Include Files


//Own Include Files

//Method Implementations
//Constructor called. whenever object is created it accesses the constructor for initializing the value.
CWaypoint::CWaypoint(string objectName,double objectLatitude,double objectLongitude)
{

	set(objectName,objectLatitude,objectLongitude);

}

//getter function for taking name.
string CWaypoint::getName()
{

	return m_name;
}

//getter function for taking Latitude.
double CWaypoint::getLatitude()
{

	return m_latitude;
}

//getter function for taking Longitude.
double CWaypoint::getLongitude()
{

	return m_longitude;
}

/*Using set function for setting the parameters after checking the validity of longitude and latitude.
as latitude varies between (-90 to 90)Degree
as longitude varies between (-180 to 180)Degree */
void CWaypoint::set(string Name,double Latitude,double Longitude){

	m_name = Name;

	if(((Latitude>=-90)&&(Latitude<=90))&&((Longitude>=-180)&&(Longitude<=180)))
		{
		m_latitude=Latitude;
		m_longitude=Longitude;


	}
	else{
		m_latitude=0;
		m_longitude=0;
		cout << "incorrect values"<<endl;

	}
}


//transfromLongitude2degmmss function is use to calculate longitude from decimal to degree min and ss format.
void CWaypoint::transfromLongitude2degmmss(int &deg, int &mm,double &ss)
{

	int intLongitude=m_longitude;
	deg=intLongitude;
	double doubLongitudeMin=(m_longitude-intLongitude)*60;
	int intLongitudeMin=doubLongitudeMin;
	mm=intLongitudeMin;
	double doubLongitudeSS=(doubLongitudeMin-intLongitudeMin)*60;
	ss=doubLongitudeSS;

}

//transfromLatitude2degmmss function is use to calculate latitude from decimal to degree min and ss format.
void CWaypoint::transfromLatitude2degmmss(int &deg, int &mm,double &ss)
{

	int intLatitude=m_latitude;
	deg=intLatitude;
	double doubLatitudeMin=(m_latitude-intLatitude)*60;
	int intLatitudeMin=doubLatitudeMin;
	mm=intLatitudeMin;
	double doubLatitudeSS=(doubLatitudeMin-intLatitudeMin)*60;
	ss=doubLatitudeSS;

}



// getAllDataByReference it is taking data by reference as by this method it is taking data by reference and updating value at the same location of the variable.
//here if define function is used whenever SHOWADDRESS is defined the it will print the value inside the ifdef condition if not defined then it will skip.
void CWaypoint::getAllDataByReference(string &name, double &latitude,double &longitude)
{
	 name = m_name;
	 latitude = m_latitude;
	 longitude = m_longitude;
	 cout<<name<<" at address "<<&name<<" of size "<<sizeof(name)<<endl;
	 cout<<latitude<<" at address "<<&latitude<<" of size "<<sizeof(latitude)<<endl;
	 cout<<longitude<<" at address "<<&longitude<<" of size "<<sizeof(longitude)<<endl;

#ifdef SHOWADDRESS
	 cout<<"SHOWADDRESS is enabled"<<endl;
	cout<<"Object Address "<<this<<endl;
	cout<<m_name<<" at Location "<<&m_name<<endl<<"latitude "<< m_latitude<<" at Location "<<&m_latitude<<" longitude "<<m_longitude<<" at Location "<<&m_longitude<<endl;

#endif

}


/*calculateDistance is calculating distance between two point and input it is taking as constant Waypoint
we are taking it constant so that the value inside it cannot be modified. it will return value after calculating through the given formula.
*/
double CWaypoint::calculateDistance(const CWaypoint &wp)
{
	double latitude_1=(m_latitude);
	double longitude_1=m_longitude;
	double latitude_2=wp.m_latitude;
	double longitude_2=wp.m_longitude;
	double dist= R*acos(sin(latitude_1*PI)*sin(latitude_2*PI)+cos(latitude_1*PI)*cos(latitude_2*PI)*cos((longitude_2*PI)-(longitude_1*PI)));//
	cout<<"Distance between "<< m_name << " and "<<wp.m_name <<" is "<< dist <<"km"<<endl;
	return dist;
}


//print function taking input format which can be either of two form  DEGREE or 1 for printing values in decimal format, and
//MMSS or 2 for printing the value in degree minutes and second format.

void CWaypoint::print(int format)
{
	if(format==1)
	{
		cout<<getName()<<" is on Latitude = "<<getLatitude()<<"deg and "<<getLongitude()<<"deg"<<endl;


	}
	else if(format==2)
	{
		int deg=0,mm=0;
		double ss=0.0;
		cout<<getName()<<" is on ";
		transfromLatitude2degmmss(deg,mm,ss);
		cout<<" Latitude : "<<deg<<"deg "<<mm<<"mm "<<ss<<"ss";
		transfromLongitude2degmmss(deg,mm,ss);
		cout<<"  Longitude :"<<deg<<"deg "<<mm<<"mm "<<ss<<"ss"<<endl;

	}
	else
	{
		cout<<" Invalid Format "<<endl;
	}
}
