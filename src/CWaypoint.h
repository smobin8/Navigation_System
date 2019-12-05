/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CWAYPOINT.H
* Author          :Mohammad Shahid Mobin
* Description     :
*
*
****************************************************************************/

#ifndef CWAYPOINT_H
#define CWAYPOINT_H
#include <iostream>
#include <string>
#include <math.h>
#define SHOWADDRESS  //for printing address
#define R  6378.17
#define PI (3.14159/180)
#define DEGREE 1
#define MMSS 2


//Header file for declaration of all the method used

using namespace std;

class CWaypoint {

protected:

    string m_name;
    double m_latitude;
    double m_longitude;

public:

    CWaypoint(string objectName="",double objectLatitude=0.00,double objectLongitude=0.00);
    void set(string name,double latitude,double longitude);
    string getName();
    double getLatitude();
    double getLongitude();
    void getAllDataByReference(string &name, double &latitude,double &longitude);
    double calculateDistance(const CWaypoint &wp);
    void print(int format);
private:
    void transfromLongitude2degmmss(int &deg, int &mm,double &ss);
	void transfromLatitude2degmmss(int &deg, int &mm,double &ss);





};
/********************
**  CLASS END
*********************/
#endif /* CWAYPOINT_H */
