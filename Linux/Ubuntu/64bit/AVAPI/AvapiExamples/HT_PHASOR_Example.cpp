#include <string>
#include <iostream>
#include <sstream>
#include "Avapi/AvapiConnection.hpp"
#include "Avapi/TECHNICAL_INDICATOR/HT_PHASOR.hpp"

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
    
    auto& QueryObject = avapi_connection->GetQueryObject_HT_PHASOR();

    auto Response = QueryObject.Query(   
             "MSFT"
             ,Const_HT_PHASOR_interval::weekly
             ,Const_HT_PHASOR_series_type::close);

    cout << endl <<  "******** RAW DATA HT_PHASOR ********"<< endl;
    cout <<  Response.get_RawData() << endl << endl;

    cout << "******** STRUCTURED DATA HT_PHASOR ********"<< endl;

    if(Response.get_Data().isError())
    {
        cerr << Response.get_Data().get_ErrorMessage() << endl;
    }
    else
    {
        auto& MetaData  = Response.get_Data().get_MetaData();
        auto& TechnicalIndicator = Response.get_Data().get_TechnicalIndicator();

        cout << "========================" << endl;
        cout << "Symbol: " <<  MetaData.get_Symbol() << endl;
        cout << "Indicator: " <<  MetaData.get_Indicator() << endl;
        cout << "LastRefreshed: " <<  MetaData.get_LastRefreshed() << endl;
        cout << "Interval: " <<  MetaData.get_Interval() << endl;
        cout << "SeriesType: " <<  MetaData.get_SeriesType() << endl;
        cout << "TimeZone: " <<  MetaData.get_TimeZone() << endl;
        cout << "========================" << endl;
        cout << "========================" << endl;

        for(auto& element : TechnicalIndicator)
        {
            cout << "PHASE: " << element.get_PHASE() << endl;
            cout << "QUADRATURE: " << element.get_QUADRATURE() << endl;
            cout << "DateTime: " << element.get_DateTime() << endl;
            cout << "========================" << endl;
        }
    }
    
	return EXIT_SUCCESS;
}
