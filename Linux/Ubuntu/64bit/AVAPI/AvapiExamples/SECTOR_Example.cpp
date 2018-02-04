#include <string>
#include <iostream>
#include <sstream>
#include "Avapi/AvapiConnection.hpp"
#include "Avapi/SECTOR/SECTOR.hpp"

using namespace std;
using namespace Avapi;

int main()
{
    string lastHttpRequest = "";
    AvapiConnection* avapi_connection;
    
    try
    {
        avapi_connection = AvapiConnection::getInstance();
        avapi_connection->set_ApiKey("Your Alpha Vantage API Key !!!!");
    }
    catch(AvapiConnectionError& e)
    {
        cout <<  e.get_error() << endl;
        return EXIT_FAILURE;
    }
    
    auto& QueryObject = avapi_connection->GetQueryObject_SECTOR();

    auto Response = QueryObject.Query();

    cout << endl <<  "******** RAW DATA SECTOR ********"<< endl;
    cout <<  Response.get_RawData() << endl << endl;

    cout << "******** STRUCTURED DATA SECTOR ********"<< endl;

    if(Response.get_Data().isError())
    {
        cerr << Response.get_Data().get_ErrorMessage() << endl;
    }
    else
    {
        auto& MetaData = Response.get_Data().get_MetaData();
        auto& RankA = Response.get_Data().get_RankA();
        auto& RankB = Response.get_Data().get_RankB();
        auto& RankC = Response.get_Data().get_RankC();
        auto& RankD = Response.get_Data().get_RankD();
        auto& RankE = Response.get_Data().get_RankE();
        auto& RankF = Response.get_Data().get_RankF();
        auto& RankG = Response.get_Data().get_RankG();
        auto& RankH = Response.get_Data().get_RankH();
        auto& RankI = Response.get_Data().get_RankI();
        auto& RankJ = Response.get_Data().get_RankJ();

        cout << "========================" << endl;
        cout << "Information: " <<  MetaData.get_Information() << endl;
        cout << "LastRefreshed: " <<  MetaData.get_LastRefreshed() << endl;
        cout << "========================" << endl;
        cout << "========================" << endl;

        //RankA
        cout << "RankName: " << RankA.get_RankName() << endl;
        cout << "Financials : " << RankA.get_Financials() << endl;
        cout << "Utilities : " << RankA.get_Utilities() << endl;
        cout << "HealthCare : " << RankA.get_HealthCare() << endl;
        cout << "Industrials : " << RankA.get_Industrials() << endl;
        cout << "RealEstate : " << RankA.get_RealEstate() << endl;
        cout << "Materials : " << RankA.get_Materials() << endl;
        cout << "TelecommunicationServices : " << RankA.get_TelecommunicationServices() << endl;
        cout << "ConsumerDiscretionary : " << RankA.get_ConsumerDiscretionary() << endl;
        cout << "ConsumerStaples : " << RankA.get_ConsumerStaples() << endl;
        cout << "InformationTechnology : " << RankA.get_InformationTechnology() << endl;
        cout << "Energy : " << RankA.get_Energy() << endl;
        cout << "========================" << endl;

        //RankB
        cout << "RankName: " << RankB.get_RankName() << endl;
        cout << "Financials : " << RankB.get_Financials() << endl;
        cout << "Utilities : " << RankB.get_Utilities() << endl;
        cout << "HealthCare : " << RankB.get_HealthCare() << endl;
        cout << "Industrials : " << RankB.get_Industrials() << endl;
        cout << "RealEstate : " << RankB.get_RealEstate() << endl;
        cout << "Materials : " << RankB.get_Materials() << endl;
        cout << "TelecommunicationServices : " << RankB.get_TelecommunicationServices() << endl;
        cout << "ConsumerDiscretionary : " << RankB.get_ConsumerDiscretionary() << endl;
        cout << "ConsumerStaples : " << RankB.get_ConsumerStaples() << endl;
        cout << "InformationTechnology : " << RankB.get_InformationTechnology() << endl;
        cout << "Energy : " << RankB.get_Energy() << endl;
        cout << "========================" << endl;

        //RankC
        cout << "RankName: " << RankC.get_RankName() << endl;
        cout << "Financials : " << RankC.get_Financials() << endl;
        cout << "Utilities : " << RankC.get_Utilities() << endl;
        cout << "HealthCare : " << RankC.get_HealthCare() << endl;
        cout << "Industrials : " << RankC.get_Industrials() << endl;
        cout << "RealEstate : " << RankC.get_RealEstate() << endl;
        cout << "Materials : " << RankC.get_Materials() << endl;
        cout << "TelecommunicationServices : " << RankC.get_TelecommunicationServices() << endl;
        cout << "ConsumerDiscretionary : " << RankC.get_ConsumerDiscretionary() << endl;
        cout << "ConsumerStaples : " << RankC.get_ConsumerStaples() << endl;
        cout << "InformationTechnology : " << RankC.get_InformationTechnology() << endl;
        cout << "Energy : " << RankC.get_Energy() << endl;
        cout << "========================" << endl;

        //RankD
        cout << "RankName: " << RankD.get_RankName() << endl;
        cout << "Financials : " << RankD.get_Financials() << endl;
        cout << "Utilities : " << RankD.get_Utilities() << endl;
        cout << "HealthCare : " << RankD.get_HealthCare() << endl;
        cout << "Industrials : " << RankD.get_Industrials() << endl;
        cout << "RealEstate : " << RankD.get_RealEstate() << endl;
        cout << "Materials : " << RankD.get_Materials() << endl;
        cout << "TelecommunicationServices : " << RankD.get_TelecommunicationServices() << endl;
        cout << "ConsumerDiscretionary : " << RankD.get_ConsumerDiscretionary() << endl;
        cout << "ConsumerStaples : " << RankD.get_ConsumerStaples() << endl;
        cout << "InformationTechnology : " << RankD.get_InformationTechnology() << endl;
        cout << "Energy : " << RankD.get_Energy() << endl;
        cout << "========================" << endl;

        //RankE
        cout << "RankName: " << RankE.get_RankName() << endl;
        cout << "Financials : " << RankE.get_Financials() << endl;
        cout << "Utilities : " << RankE.get_Utilities() << endl;
        cout << "HealthCare : " << RankE.get_HealthCare() << endl;
        cout << "Industrials : " << RankE.get_Industrials() << endl;
        cout << "RealEstate : " << RankE.get_RealEstate() << endl;
        cout << "Materials : " << RankE.get_Materials() << endl;
        cout << "TelecommunicationServices : " << RankE.get_TelecommunicationServices() << endl;
        cout << "ConsumerDiscretionary : " << RankE.get_ConsumerDiscretionary() << endl;
        cout << "ConsumerStaples : " << RankE.get_ConsumerStaples() << endl;
        cout << "InformationTechnology : " << RankE.get_InformationTechnology() << endl;
        cout << "Energy : " << RankE.get_Energy() << endl;
        cout << "========================" << endl;

        //RankF
        cout << "RankName: " << RankF.get_RankName() << endl;
        cout << "Financials : " << RankF.get_Financials() << endl;
        cout << "Utilities : " << RankF.get_Utilities() << endl;
        cout << "HealthCare : " << RankF.get_HealthCare() << endl;
        cout << "Industrials : " << RankF.get_Industrials() << endl;
        cout << "RealEstate : " << RankF.get_RealEstate() << endl;
        cout << "Materials : " << RankF.get_Materials() << endl;
        cout << "TelecommunicationServices : " << RankF.get_TelecommunicationServices() << endl;
        cout << "ConsumerDiscretionary : " << RankF.get_ConsumerDiscretionary() << endl;
        cout << "ConsumerStaples : " << RankF.get_ConsumerStaples() << endl;
        cout << "InformationTechnology : " << RankF.get_InformationTechnology() << endl;
        cout << "Energy : " << RankF.get_Energy() << endl;
        cout << "========================" << endl;

        //RankG
        cout << "RankName: " << RankG.get_RankName() << endl;
        cout << "Financials : " << RankG.get_Financials() << endl;
        cout << "Utilities : " << RankG.get_Utilities() << endl;
        cout << "HealthCare : " << RankG.get_HealthCare() << endl;
        cout << "Industrials : " << RankG.get_Industrials() << endl;
        cout << "RealEstate : " << RankG.get_RealEstate() << endl;
        cout << "Materials : " << RankG.get_Materials() << endl;
        cout << "TelecommunicationServices : " << RankG.get_TelecommunicationServices() << endl;
        cout << "ConsumerDiscretionary : " << RankG.get_ConsumerDiscretionary() << endl;
        cout << "ConsumerStaples : " << RankG.get_ConsumerStaples() << endl;
        cout << "InformationTechnology : " << RankG.get_InformationTechnology() << endl;
        cout << "Energy : " << RankG.get_Energy() << endl;
        cout << "========================" << endl;

        //RankH
        cout << "RankName: " << RankH.get_RankName() << endl;
        cout << "Financials : " << RankH.get_Financials() << endl;
        cout << "Utilities : " << RankH.get_Utilities() << endl;
        cout << "HealthCare : " << RankH.get_HealthCare() << endl;
        cout << "Industrials : " << RankH.get_Industrials() << endl;
        cout << "Materials : " << RankH.get_Materials() << endl;
        cout << "TelecommunicationServices : " << RankH.get_TelecommunicationServices() << endl;
        cout << "ConsumerDiscretionary : " << RankH.get_ConsumerDiscretionary() << endl;
        cout << "ConsumerStaples : " << RankH.get_ConsumerStaples() << endl;
        cout << "InformationTechnology : " << RankH.get_InformationTechnology() << endl;
        cout << "Energy : " << RankH.get_Energy() << endl;
        cout << "========================" << endl;

        //RankI
        cout << "RankName: " << RankI.get_RankName() << endl;
        cout << "Financials : " << RankI.get_Financials() << endl;
        cout << "Utilities : " << RankI.get_Utilities() << endl;
        cout << "HealthCare : " << RankI.get_HealthCare() << endl;
        cout << "Industrials : " << RankI.get_Industrials() << endl;
        cout << "Materials : " << RankI.get_Materials() << endl;
        cout << "TelecommunicationServices : " << RankI.get_TelecommunicationServices() << endl;
        cout << "ConsumerDiscretionary : " << RankI.get_ConsumerDiscretionary() << endl;
        cout << "ConsumerStaples : " << RankI.get_ConsumerStaples() << endl;
        cout << "InformationTechnology : " << RankI.get_InformationTechnology() << endl;
        cout << "Energy : " << RankI.get_Energy() << endl;
        cout << "========================" << endl;

        //RankJ
        cout << "RankName: " << RankJ.get_RankName() << endl;
        cout << "Financials : " << RankJ.get_Financials() << endl;
        cout << "Utilities : " << RankJ.get_Utilities() << endl;
        cout << "HealthCare : " << RankJ.get_HealthCare() << endl;
        cout << "Industrials : " << RankJ.get_Industrials() << endl;
        cout << "Materials : " << RankJ.get_Materials() << endl;
        cout << "TelecommunicationServices : " << RankJ.get_TelecommunicationServices() << endl;
        cout << "ConsumerDiscretionary : " << RankJ.get_ConsumerDiscretionary() << endl;
        cout << "ConsumerStaples : " << RankJ.get_ConsumerStaples() << endl;
        cout << "InformationTechnology : " << RankJ.get_InformationTechnology() << endl;
        cout << "Energy : " << RankJ.get_Energy() << endl;
        cout << "========================" << endl;
    }
    
	return EXIT_SUCCESS;
}
