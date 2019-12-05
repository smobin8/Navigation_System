/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPOIDATABASE.H
* Author          :Mohammad Shahid Mobin
* Description     :CPoiDatabase is inheriting CPOI class. in this defining prototype for addpoi and getpointer is defined
*
*
****************************************************************************/

#ifndef CPOIDATABASE_H
#define CPOIDATABASE_H
#include "CPOI.h"
#include "string"
#include <iostream>
using namespace std;


class CPoiDatabase :public CPOI {
private:
    CPOI m_POI[10];
    int m_noPoi;
public:
    CPoiDatabase();

    void addPoi(t_poi type,string name,string description,double latitude,double longitude);

    CPOI* getPointerToPoi(string name);
    };
/********************
**  CLASS END
*********************/
#endif /* CPOIDATABASE_H */
