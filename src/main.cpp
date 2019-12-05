
#include <iostream>
#include <stdlib.h>
#include <string>
#include "CWaypoint.h"
#include "CGPSSensor.h"
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CRoute.h"
#include "CNavigationSystem.h"
using namespace std;



int main (void)
{

	cout<<"First part : Creating CWayPoint"<<endl;
	cout<<"Constructor"<<endl;

	CWaypoint Amsterdam("Amsterdam",52.3680,4.9036);
	CWaypoint Darmstadt("Darmsdadt",49.8728,8.6512);
	CWaypoint Berlin("Berlin",52.5166,13.40);
	CWaypoint Tokio("Tokio",35.6895,139.6917);
	CWaypoint newWaypoint();
	cout<<"*======================================*"<<endl;
	cout<<"print Method"<<endl;
	cout<<"*======================================*"<<endl;
	Berlin.print(DEGREE);
	Berlin.print(MMSS);
	cout<<"======================================"<<endl;
	string name= "NULL";
	double latitude =0;
	double longitude=0;

	Tokio.getAllDataByReference(name,latitude,longitude);


	cout<<"And the first real method"<<endl;
	cout<<"======================================"<<endl;
	Berlin.calculateDistance(Amsterdam);
	Berlin.calculateDistance(Tokio);
	cout<<"======================================"<<endl;

	cout<<"     Navigation System Project    "<<endl;
	cout<<"======================================"<<endl;
	CNavigationSystem NSObject;
	NSObject.run();

	cout<<"======================================"<<endl;
	cout<<"===================End ==============================";



	return 0;
}


