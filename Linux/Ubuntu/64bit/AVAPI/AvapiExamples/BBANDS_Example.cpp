#include <string>
#include <iostream>
#include <sstream>
#include "Avapi/AvapiConnection.hpp"
#include "Avapi/TECHNICAL_INDICATOR/BBANDS.hpp"

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
    
    auto& QueryObject = avapi_connection->GetQueryObject_BBANDS();

    auto Response = QueryObject.Query(   
             "MSFT"
             ,Const_BBANDS_interval::n_60min
             ,"5"
             ,Const_BBANDS_series_type::close
             ,"3"
             ,"3"
             ,Const_BBANDS_matype::n_0);

    cout << endl <<  "******** RAW DATA BBANDS ********"<< endl;
    cout <<  Response.get_RawData() << endl << endl;

    cout << "******** STRUCTURED DATA BBANDS ********"<< endl;

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
        cout << "TimePeriod: " <<  MetaData.get_TimePeriod() << endl;
        cout << "DeviationUpper: " <<  MetaData.get_DeviationUpper() << endl;
        cout << "DeviationLower: " <<  MetaData.get_DeviationLower() << endl;
        cout << "MAType: " <<  MetaData.get_MAType() << endl;
        cout << "SeriesType: " <<  MetaData.get_SeriesType() << endl;
        cout << "TimeZone: " <<  MetaData.get_TimeZone() << endl;
        cout << "========================" << endl;
        cout << "========================" << endl;

        for(auto& element : TechnicalIndicator)
        {
            cout << "RealLowerBand: " << element.get_RealLowerBand() << endl;
            cout << "RealUpperBand: " << element.get_RealUpperBand() << endl;
            cout << "RealMiddleBand: " << element.get_RealMiddleBand() << endl;
            cout << "DateTime: " << element.get_DateTime() << endl;
            cout << "========================" << endl;
        }
    }
    
	return EXIT_SUCCESS;
}
